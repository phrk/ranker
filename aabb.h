#ifndef _RANKER_AABB_H_
#define _RANKER_AABB_H_

#include "ranker_defs.h"
#include "point.h"

namespace rnk2 {

class AABB {
public:
	Point center;
	RnkReal halfDimension;
	
	AABB();
	AABB(const Point &_center, RnkReal halfDimension);
	virtual ~AABB();
	void splitToFour(AABB &_tl, AABB &_tr, AABB &_bl, AABB &_br);
	bool isInside(const Point &_p);
};

};

#endif
