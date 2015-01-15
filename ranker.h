#ifndef _RANKER_H_
#define _RANKER_H_

#include "hiconfig.h"
#include "tokenizer.h"
#include "index.h"
#include <boost/shared_ptr.hpp>

#include <boost/noncopyable.hpp>

template <class CatT = uint64_t, class ObjT = uint64_t>
class Ranker : public boost::noncopyable {
	
	InvertIndex<CatT, ObjT> m_index;
	Tokenizer m_tokenizer;
	
	void addDoc(const Doc<CatT,ObjT> &_doc);
	
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

//typedef boost::shared_ptr<Ranker> RankerPtr;

#endif
