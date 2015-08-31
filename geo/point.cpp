#include "point.h"

namespace rnk2 {

Point::Point() {
	
}

Point::Point(GeoCoord _x, GeoCoord _y):
x(_x),
y(_y) {
	
}

Point::~Point() {
	
}

void Point::print() const{
	
	std::cout << "Point " << x << " " << y << std::endl;
}

}
