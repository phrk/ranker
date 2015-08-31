#ifndef _RANKER2_GEO_H_
#define _RANKER2_GEO_H_

#include "../ranker_defs.h"

#include "qtree.h"

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/geometries/box.hpp>

#include <boost/geometry/index/rtree.hpp>

#include <vector>

#include <iostream>
#include <boost/foreach.hpp>

namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;

namespace rnk2 {

template<class ObjId>
class GeoIndex {
public:

	typedef bg::model::point<float, 2, bg::cs::geographic<bg::degree> > point;
	//typedef bg::model::box<point> box;
	typedef std::pair<point, uint64_t> value;
	
	GeoIndex() {
		bgi::rtree< value, bgi::rstar<16> > rtree;
		for (int i = 0; i<10; ++i) {
			rtree.insert(std::make_pair(point(0, 2*i), i));
		}
		
		std::vector<value> result_s;
		rtree.query(bgi::nearest(point(0, 0), 5), std::back_inserter(result_s));
	}
	
	void addDoc(ObjId _id, Point _p);
	virtual ~GeoIndex();
};

};

#endif
