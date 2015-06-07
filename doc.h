#ifndef _DOC2_H_
#define _DOC2_H_

#include "hiconfig.h"
#include <string>
#include <vector>
#include <set>

#include <boost/shared_ptr.hpp>

#include "ranker_defs.h"

namespace rnk2 {

template <class CatT, class ObjId>
class Doc {
public:
	ObjId id;
	TextRepr title;
	TextRepr text;
	std::set<CatT> categories;
	
	hashtable<TokenIdT, RnkReal> m_tfs;
	
	Doc(ObjId _id, const TextRepr &_title, const TextRepr &_text, const std::set<CatT> &_categories);
	virtual ~Doc();
	
	bool inCategory(CatT _cat) const;
	RnkReal getTf(TokenIdT _token) const;
	int size() const;
};

#include "doc.impl"

}

#endif
