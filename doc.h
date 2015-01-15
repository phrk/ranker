#ifndef _DOC_H_
#define _DOC_H_

#include "hiconfig.h"
#include <string>
#include <vector>
#include <set>

#include <boost/shared_ptr.hpp>

typedef uint64_t ObjId;
typedef std::vector<uint64_t> TextRepr;

template <class CatT, class ObjT>
class Doc {
public:
	ObjId id;
	ObjT obj;
	TextRepr title;
	TextRepr text;
	std::set<CatT> categories;
	
	//Doc();
	Doc(ObjId _id, ObjT _obj, const TextRepr &_title, const TextRepr &_text, const std::set<CatT> &_categories);
	virtual ~Doc();
	
	bool inCategory(CatT _cat);
};

#include "doc.impl"

//template <class CatT, class ObjT>
//typedef boost::shared_ptr< Doc<CatT,ObjT> > DocPtr<CatT,ObjT>;

#endif
