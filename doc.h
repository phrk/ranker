#ifndef _DOC_H_
#define _DOC_H_

#include "hiconfig.h"
#include <string>

class Doc {
public:
	uint64_t id;
	std::vector<uint64_t> title;
	std::vector<uint64_t> text;
};

#endif
