#ifndef _DOC_H_
#define _DOC_H_

#include "hiconfig.h"
#include <string>
#include <vector>
#include <set>

class Doc {
public:
	uint64_t id;
	std::vector<uint64_t> title;
	std::vector<uint64_t> text;
	std::set<uint64_t> categories;
};

#endif
