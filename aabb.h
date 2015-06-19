#ifndef _RANKER_AABB_H_
#define _RANKER_AABB_H_

#include "ranker_defs.h"
#include "point.h"

#include <iostream>

namespace rnk2 {

class AABB {
public:
	Point center;
	RnkReal halfDimension;
	
	AABB();
	AABB(const Point &_center, RnkReal halfDimension);
	virtual ~AABB();
	void splitToFour(AABB &_tl, AABB &_tr, AABB &_bl, AABB &_br) const;
	void getCorners(std::vector<Point> &_corners) const;
	bool isInside(const Point &_p) const;
	bool isInside(const AABB &_b) const;
	bool isIntersects(const AABB &_b) const;
	
	void print() const;
};

};

#endif
