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

void AABB::splitToFour(AABB &_tl, AABB &_tr, AABB &_bl, AABB &_br) const {
	 
	float line = 0.0f;
	_tl = AABB(Point(center.x-halfDimension/2.0f, center.y+halfDimension/2.0f), halfDimension/2.0f+line);
	_tr = AABB(Point(center.x+halfDimension/2.0f, center.y+halfDimension/2.0f), halfDimension/2.0f+line);
	_bl = AABB(Point(center.x-halfDimension/2.0f, center.y-halfDimension/2.0f), halfDimension/2.0f+line);
	_br = AABB(Point(center.x+halfDimension/2.0f, center.y-halfDimension/2.0f), halfDimension/2.0f+line);
}

bool AABB::isInside(const Point &_p) const {
	
	if (center.x-halfDimension <= _p.x &&
		_p.x <= center.x+halfDimension &&
		center.y-halfDimension <= _p.y &&
		_p.y <= center.y+halfDimension)
			return true;
	return false;
}

void AABB::getCorners(std::vector<Point> &_corners) const {
	
	_corners.push_back(Point(center.x-halfDimension, center.y+halfDimension));
	_corners.push_back(Point(center.x+halfDimension, center.y+halfDimension));
	_corners.push_back(Point(center.x-halfDimension, center.y-halfDimension));
	_corners.push_back(Point(center.x+halfDimension, center.y+halfDimension));
}

bool AABB::isInside(const AABB &_b) const {
	
	std::vector<Point> corners;
	_b.getCorners(corners);
	
	for (auto it : corners)
		if (!isInside( it ))
			return false;
	return true;
}

bool AABB::isIntersects(const AABB &_b) const {
	
	std::vector<Point> a_corners;
	getCorners(a_corners);
	
	for (auto it : a_corners)
		if (_b.isInside(it))
			return true;
	
	
	std::vector<Point> b_corners;
	_b.getCorners(b_corners);
	
	for (auto it : b_corners)
		if (isInside(it))
			return true;
	
	return false;
}

void AABB::print() const {
	
	std::cout << "AABB " << center.x << " " << center.y << " " << halfDimension << std::endl;
}

}
