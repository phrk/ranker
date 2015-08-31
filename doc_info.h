#ifndef _RANKER_DOCINFO_H_
#define _RANKER_DOCINFO_H_

#include "ranker_defs.h"

namespace rnk2 {

template <class CatT, class ObjId>
class DocInfo {
public:
	ObjId id;
	std::string title;
	std::string text;
	std::set<CatT> categories;
	Point geo;
	
	DocInfo(ObjId id, const std::string &_title, const std::string &_text);
	virtual ~DocInfo();
	
	void addCategory(CatT _cat);
	void setGeo(const Point &_point);
};

#include "doc_info.impl"

};

#endif
