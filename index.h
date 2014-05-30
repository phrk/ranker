#ifndef _INVINDEX_H_
#define _INVINDEX_H_

#include "hiconfig.h"
#include "hiaux/structs/hashtable.h"
#include "doc.h"

#include <iostream>
#include <algorithm>

class Occur {
public:
	uint64_t docid;
	uint64_t tf; // term frequency
	bool in_title;
	
	Occur(uint64_t docid);
};

class Occurs {
	std::vector<Occur> m_occurs;
public:
	void add(Occur &_occur);
	void getDocIds(std::vector<uint64_t> &_docids);
	static void intersect(const Occurs &_a, const Occurs &_b, Occurs &_res);
	void removeOccurance(uint64_t _docid);
};

class InvertIndex {
	hiaux::hashtable<uint64_t, Occurs> m_index;
	hiaux::hashtable<uint64_t, Doc> m_docs;
	
	void removeOccurance(uint64_t _word, uint64_t _docid);
public:
	
	void indexDoc(const Doc &_doc);	
	void removeDoc(uint64_t _id);
	void query(const std::vector<uint64_t> &_query, std::vector<uint64_t> &_result);
};

#endif
