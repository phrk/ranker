#ifndef _DOC_H_
#define _DOC_H_

#include "hiconfig.h"
#include <string>
#include <vector>
#include <set>

#include <boost/shared_ptr.hpp>

class Doc {
public:
	uint64_t id;
	std::vector<uint64_t> title;
	std::vector<uint64_t> text;
	std::set<uint64_t> categories;
	
	
	Doc();
	Doc(uint64_t _id, const std::vector<uint64_t> &_title, const std::vector<uint64_t> &_text, const std::set<uint64_t> &_categories);
	virtual ~Doc();
	
	bool inCategory(uint64_t _cat);
};

typedef boost::shared_ptr<Doc> DocPtr;

#endif
