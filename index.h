#ifndef _INVINDEX_H_
#define _INVINDEX_H_

#include "hiconfig.h"
#include "hiaux/structs/hashtable.h"
#include "doc.h"

#include <list>

#include <iostream>
#include <algorithm>

#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/noncopyable.hpp>

#include "occurs.h"

class InvertIndex : public boost::noncopyable {
	
	hiaux::hashtable<uint64_t, Occurs> m_index;
	hiaux::hashtable<uint64_t, DocPtr> m_docs;
	
	void removeOccurance(uint64_t _word, uint64_t _docid);
public:
	
	bool docinCategory(uint64_t _docid, uint64_t _catid);
	void indexDoc(const Doc &_doc);	
	void removeDoc(uint64_t _id);
	void query(const std::vector<uint64_t> &_query, //uint64_t _cat,
		 		std::vector<uint64_t> &_result) const;
	
	void query(const std::vector<uint64_t> &_query, uint64_t _cat,
		 		std::vector<uint64_t> &_result) const;			
};

#endif
