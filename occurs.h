#ifndef _RANKER_OCCURS_H_
#define _RANKER_OCCURS_H_

#include "hiconfig.h"

#include <vector>
#include <math.h>
#include <algorithm>

#include "doc.h"

typedef int PosInDoc;
typedef int DocFieldId;

template <class ObjId>
class Occur {
public:
	ObjId docid;
	PosInDoc pos;
	DocFieldId field;
	//bool in_title;
	
	Occur(ObjId docid);
};

template <class ObjId>
class Occurs {
	
	typedef std::vector<Occur<ObjId> >  OccursVec;
	OccursVec m_occurs;
	//std::list<Occur> m_occurs;
	//boost::function<bool(uint64_t, uint64_t)> m_docinCategory;
	
public:
	
	Occurs();
	virtual ~Occurs();
	//Occurs();
	
	void add(Occur<ObjId> &_occur);
	void getDocIds(std::vector<ObjId> &_docids);
	
	void intersect(const Occurs<ObjId> &_a, const Occurs<ObjId> &_b, Occurs<ObjId> &_res);
	void removeOccurance(ObjId _docid);
//	void leaveOnlyCategory(uint64_t _cat, Occurs &_occ);
};

#include "occurs.impl"

#endif
