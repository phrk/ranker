#include "aabb.h"

namespace rnk2 {

AABB::AABB() {
	
}

AABB::AABB(const Point &_center, RnkReal _halfDimension):
center(_center),
halfDimension(_halfDimension) {
	
}

AABB::~AABB() {
	
}

void AABB::splitToFour(AABB &_tl, AABB &_tr, AABB &_bl, AABB &_br) {
	 
	_tl = AABB(Point(center.x-halfDimension/2.0f, center.y+halfDimension/2.0f), halfDimension/2.0f);
	_tr = AABB(Point(center.x+halfDimension/2.0f, center.y+halfDimension/2.0f), halfDimension/2.0f);
	_bl = AABB(Point(center.x-halfDimension/2.0f, center.y-halfDimension/2.0f), halfDimension/2.0f);
	_br = AABB(Point(center.x+halfDimension/2.0f, center.y-halfDimension/2.0f), halfDimension/2.0f);
}

bool AABB::isInside(const Point &_p) {
	
	if (center.x-halfDimension <= _p.x &&
		_p.x <= center.x+halfDimension &&
		center.y-halfDimension <= _p.y &&
		_p.y <= center.y+halfDimension)
			return true;
	return false;
}

}
