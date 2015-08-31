#include "RankerTests.h"

using namespace rnk2;

void RankerTests::testAABB() {
	
	float box_half_size = 10.0f;
	
	AABB b(Point(0, 0), box_half_size);
	
	TS_ASSERT( b.isInside(Point(0, 0)) );
	TS_ASSERT( !b.isInside(Point(0, 20)) );
	
	
	AABB b2(Point(0, 0), box_half_size/2.0f);
	TS_ASSERT( b.isInside(b2) );
	
	AABB b3(Point(0, 0), box_half_size*2.0f);
	TS_ASSERT( !b.isInside(b3) );
	
	TS_ASSERT( b.isIntersects(b2) );
	TS_ASSERT( b.isIntersects(b3) );
	
	AABB b4(Point(15, 15), box_half_size);
	TS_ASSERT( b.isIntersects(b4) );
	
	TS_ASSERT( !b.isIntersects(AABB(Point(35, 35), box_half_size)) );
}

void RankerTests::testAABBgetCorners() {
	
	
	float box_half_size = 10.0f;
	AABB b(Point(0, 0), box_half_size);
	
	std::vector<Point> corners;
	
	b.getCorners(corners);
}
