#ifndef _RANKER2_GEO_H_
#define _RANKER2_GEO_H_

#include "ranker_defs.h"

#include "qtree.h"

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/geometries/box.hpp>

#include <boost/geometry/index/rtree.hpp>

namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;

namespace rnk2 {

template<class ObjId>
class GeoIndex {
public:
	
	void addDoc(ObjId _id, Point _p);
	virtual ~GeoIndex();
};

};

#endif
