#ifndef _INVINDEX_H_
#define _INVINDEX_H_

#include "hiconfig.h"
#include "hiaux/structs/hashtable.h"
#include "doc.h"

#include <iostream>
#include <algorithm>

#include <boost/function.hpp>
#include <boost/bind.hpp>

class Occur {
public:
	uint64_t docid;
	uint64_t tf; // term frequency
	bool in_title;
	
	Occur(uint64_t docid);
};

class Occurs {
	std::vector<Occur> m_occurs;
	
	boost::function<bool(uint64_t, uint64_t)> m_docinCategory;
	
public:
	
	//Occurs();
	Occurs(boost::function<bool(uint64_t, uint64_t)> _docinCategory);
	
	void add(Occur &_occur);
	void getDocIds(std::vector<uint64_t> &_docids);
	void intersect(const Occurs &_a, const Occurs &_b, Occurs &_res, uint64_t _cat);
	void removeOccurance(uint64_t _docid);
	void leaveOnlyCategory(uint64_t _cat, Occurs &_occ);
};

class InvertIndex {
	hiaux::hashtable<uint64_t, Occurs> m_index;
	hiaux::hashtable<uint64_t, Doc> m_docs;
	
	void removeOccurance(uint64_t _word, uint64_t _docid);
public:
	
	bool docinCategory(uint64_t _docid, uint64_t _catid);
	void indexDoc(const Doc &_doc);	
	void removeDoc(uint64_t _id);
	void query(const std::vector<uint64_t> &_query, uint64_t _cat, std::vector<uint64_t> &_result);
};

#endif
