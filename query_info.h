#ifndef _RANKER_QUERY_INFO_H_
#define _RANKER_QUERY_INFO_H_

#include "ranker_defs.h"

#include <boost/any.hpp>

namespace rnk2 {

typedef int AttributeId;

class Attribute {
public:
	
	enum Type {
		SEARCH_TEXT,
		STRING,
		GEO,
		INT,
		FLOAT
	};
		
	AttributeId id;
	boost::any value;
};

class Scheme {
public:
	
	std::vector< Attribute::Type > fields;
};

class SearchQuery {
};


class QueryInfo {

public:
	
	//std::vector<> fields;
};

#include "query_info.impl"

};

#endif
