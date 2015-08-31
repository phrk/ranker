
#ifndef _RANKER_TESTS_H_
#define _RANKER_TESTS_H_

#include <cxxtest/TestSuite.h>
#include "ranker/ranker.h"

#include <iomanip>

#include <map>

class RankerTests : public CxxTest::TestSuite
{
public:

	void testAABB();
	void testAABBgetCorners();
	
	void testTreeFindInRegion();
	
};

#endif
