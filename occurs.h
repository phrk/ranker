#ifndef _RANKER2_OCCURS_H_
#define _RANKER2_OCCURS_H_

#include "hiconfig.h"

#include <vector>
#include <math.h>
#include <algorithm>

#include "doc.h"

namespace rnk2 {

typedef int PosInDoc;
typedef int DocFieldId;

template <class ObjId>
class Occur {
public:
	ObjId docid;
	PosInDoc pos;
	DocFieldId field;
	
	Occur(ObjId docid);
};

template <class ObjId>
class Occurs {
	
	typedef std::vector<Occur<ObjId> >  OccursVec;
	OccursVec m_occurs;
	
public:
	
	Occurs();
	virtual ~Occurs();
	
	int size() const;
	void add(Occur<ObjId> &_occur);
	void getDocIds(std::vector<ObjId> &_docids);
	
	void intersect(const Occurs<ObjId> &_a, const Occurs<ObjId> &_b, Occurs<ObjId> &_res);
	void removeOccurance(ObjId _docid);
};

#include "occurs.impl"

}

#endif
