#ifndef _RANKER_H_
#define _RANKER_H_

#include "hiconfig.h"
#include "tokenizer.h"
#include "index.h"
#include <boost/shared_ptr.hpp>

#include <boost/noncopyable.hpp>

#include <type_traits>

template <class CatT, class ObjId, class ObjT>
class Ranker : public boost::noncopyable {
	
	InvertIndex<CatT, ObjId, ObjT> m_index;
	Tokenizer m_tokenizer;

protected:
	
	void addDoc(const Doc<CatT, ObjId, ObjT> &_doc);

	void addDocAsId(ObjId _obj, const std::string &_title, const std::string &_text, const std::set<CatT> &_categories);
	void addDocAsId(ObjId _obj, const std::string &_title, const std::string &_text);

public:
	
	Ranker();
	virtual ~Ranker();
	
	ObjId addDoc(ObjT _obj, const std::string &_title, const std::string &_text, const std::set<CatT> &_categories);
	ObjId addDoc(ObjT _obj, const std::string &_title, const std::string &_text);
	
	void removeDoc(ObjId _id);
	
	void query(const std::string &_query, std::vector<ObjT> &_result) const;
	void query(const std::string &_query, CatT _cat, std::vector<ObjT> &_result) const;
};

#include "ranker.impl"

#endif
