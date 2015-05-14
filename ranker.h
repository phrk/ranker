#ifndef _RANKER2_H_
#define _RANKER2_H_

#include "hiconfig.h"
#include "tokenizer.h"
#include "index.h"
#include <boost/shared_ptr.hpp>

#include <boost/noncopyable.hpp>

#include <type_traits>

#include "ranker_defs.h"

namespace rnk2 {

template <class CatT, class ObjId>
class Ranker : public boost::noncopyable {
	
	InvertIndex<CatT, ObjId> m_index;
	Tokenizer<TokenIdT> m_tokenizer;

protected:
	
	void addDoc(const Doc<CatT, ObjId> &_doc);

public:
	
	Ranker(bool _by_pref);
	virtual ~Ranker();
	
	ObjId addDoc(ObjId _id, const std::string &_title, const std::string &_text, const std::set<CatT> &_categories);
	ObjId addDoc(ObjId _id, const std::string &_title, const std::string &_text);
	
	void removeDoc(ObjId _id);
	
	void query(const std::string &_query, std::vector<ObjId> &_result) const;
	void query(const std::string &_query, CatT _cat, std::vector<ObjId> &_result) const;
};

#include "ranker.impl"

}

#endif
