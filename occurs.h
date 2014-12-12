#ifndef _RANKER_OCCURS_H_
#define _RANKER_OCCURS_H_

#include "hiconfig.h"

#include <vector>

class Occur {
public:
	uint64_t docid;
	uint64_t tf; // term frequency
	bool in_title;
	
	Occur(uint64_t docid);
};

class Occurs {
	std::vector<Occur> m_occurs;
	//std::list<Occur> m_occurs;
	//boost::function<bool(uint64_t, uint64_t)> m_docinCategory;
	
public:
	
	Occurs();
	//Occurs();
	
	void add(Occur &_occur);
	void getDocIds(std::vector<uint64_t> &_docids);
	void intersect(const Occurs &_a, const Occurs &_b, Occurs &_res);
	void removeOccurance(uint64_t _docid);
//	void leaveOnlyCategory(uint64_t _cat, Occurs &_occ);
};

#endif
