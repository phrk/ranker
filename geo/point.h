#ifndef _RANKER_POINT_H_
#define _RANKER_POINT_H_

#include "../ranker_defs.h"

#include <iostream>

namespace rnk2 {

class Point {
public:
	GeoCoord x;
	GeoCoord y;
	
	Point();
	Point(GeoCoord _x, GeoCoord _y);
	virtual ~Point();
	
	void print() const;
}; 

}

#endif
