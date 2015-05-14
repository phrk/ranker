#ifndef _RANKER2_QUERY_H_
#define _RANKER2_QUERY_H_

#include "ranker_defs.h"

namespace rnk2 {

class Query {
public:
	TextRepr text;
	std::vector<RnkReal> idfs;
	
	virtual ~Query();
	int size() const;
};

}

#endif
