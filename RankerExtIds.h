#ifndef _RANKER_EXT_IDS_H_
#define _RANKER_EXT_IDS_H_

#include "ranker.h"

template <class CatT, class ObjId>
class RankerExtIds : protected Ranker<CatT, ObjId, ObjId> {

public:
	
	RankerExtIds();
	virtual ~RankerExtIds();
	
	void addDoc(ObjId _obj, const std::string &_title, const std::string &_text, const std::set<CatT> &_categories);
	void addDoc(ObjId _obj, const std::string &_title, const std::string &_text);
	
	void removeDoc(ObjId _id);
	
	void query(const std::string &_query, std::vector<ObjId> &_result) const;
	void query(const std::string &_query, CatT _cat, std::vector<ObjId> &_result) const;
};

#include "RankerExtIds.impl"

#endif
