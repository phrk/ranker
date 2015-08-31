#include "RankerTests.h"

using namespace rnk2;

void RankerTests::testTreeFindInRegion() {
/*	
	std::cout << std::fixed << std::setw( 11 ) << std::setprecision( 6 );
	
	float box_half_size = 10.0f;
	
	QTree<int> tree(4, AABB(Point(0, 0), box_half_size));
	
	std::vector< std::pair<Point, int> > points;
	
	auto genCoord = [&]() {
		float rnd = (float(std::rand()) / RAND_MAX);
		return 2*box_half_size*rnd - box_half_size;
		
	};
	
	for (int i = 0; i<10000; i++) {
		
		Point p = Point(genCoord(), genCoord());
		points.push_back(std::make_pair(p, i));
		
		//p.print();
		//std::cout << p.x << "," << p.y << std::endl;
		
		tree.insert(std::make_pair(p, i));
	}
	
	std::vector< std::pair<Point, int> > got_points;
	
	std::map<int, bool> matched_ids;
	
	AABB search_region(Point(0, 0), box_half_size/2.0f);
	
	tree.findInArea(search_region, got_points);
	//tree.getAll(got_points);
	
//	std::cout << "points: " << points.size() << std::endl;
//	std::cout << "got points: " << got_points.size() << std::endl;
	
	for (auto it : got_points)
		matched_ids[it.second] = true;
	
	for (auto it : points) {
		
		if ( search_region.isInside( it.first ) ) {
			if (matched_ids.find(it.second) == matched_ids.end())
				TS_ASSERT(false);
		}
	}
	
	for (auto it : got_points) {
		
		if (! search_region.isInside( it.first ) )
				TS_ASSERT(false);
	}
	*/
}