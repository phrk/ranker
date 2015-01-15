#ifndef _RANKER_OCCURS_H_
#define _RANKER_OCCURS_H_

#include "hiconfig.h"

#include <vector>
#include <math.h>
#include <algorithm>

#include "doc.h"

class Occur {
public:
	ObjId docid;
	uint64_t tf; // term frequency
	bool in_title;
	
	Occur(ObjId docid);
};

class Occurs {
	std::vector<Occur> m_occurs;
	//std::list<Occur> m_occurs;
	//boost::function<bool(uint64_t, uint64_t)> m_docinCategory;
	
public:
	
	Occurs();
	virtual ~Occurs();
	//Occurs();
	
	void add(Occur &_occur);
	void getDocIds(std::vector<ObjId> &_docids);
	
	void intersect(const Occurs &_a, const Occurs &_b, Occurs &_res);
	void removeOccurance(ObjId _docid);
//	void leaveOnlyCategory(uint64_t _cat, Occurs &_occ);
};

#endif
