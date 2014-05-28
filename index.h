#ifndef _INVINDEX_H_
#define _INVINDEX_H_

#include "hiconfig.h"
#include "doc.h"

class Occur {
public:
	uint64_t docid;
	uint64_t tf; // term frequency
	bool in_title;
};

class Occurs {
	std::vector<uint64_t> m_occurs;
public:
	
	void intersect(const Occurs &_a);
};

class InvertIndex {
	hiaux::hashtable<uint64_t, Occurs> m_index;
public:
	
	void indexDoc(const Doc &_doc);	
	void removeDoc(uint64_t _id);
};

#endif
