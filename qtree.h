#ifndef _RANKER_QTREE_H_
#define _RANKER_QTREE_H_

#include "ranker_defs.h"
#include "aabb.h"
#include <boost/shared_ptr.hpp>


namespace rnk2 {
	
	template<class V>
	class QTree {
		
		const int m_node_limit;
		typedef boost::shared_ptr<QTree> QTreePtr;
		
		AABB m_bound;
		
		bool m_isleaf;
		QTreePtr m_tl;
		QTreePtr m_tr;
		QTreePtr m_bl;
		QTreePtr m_br;
		
		int m_size;
		std::vector< std::pair<Point, V> > m_points;
		
		void subdivide();
		
		void brutePoints(const AABB &_bound, std::vector<std::pair<Point, V> > &_res) const;
		
	public:
		
		QTree(int _node_limit, const AABB &_bound);
		virtual ~QTree();
		void insert(const std::pair<Point, V> &_p);
		
		void getAll(std::vector<std::pair<Point, V> > &_res) const;
		void findInArea(const AABB &_bound, std::vector<std::pair<Point, V> > &_res) const;
		bool isInside(const Point &_p) const;
		bool isIntersects(const AABB &_b) const;
	};

#include "qtree.impl"
	
};

#endif
