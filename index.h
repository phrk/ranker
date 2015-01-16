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

template <class CatT, class ObjId, class ObjT>
class InvertIndex : public boost::noncopyable {
	
	typedef boost::shared_ptr<Doc <CatT, ObjId, ObjT> > DocPtr;
	typedef hiaux::hashtable<uint64_t, DocPtr> DocsHash;
	typedef hiaux::hashtable<uint64_t, Occurs<ObjId> > OccursHash;
	
	OccursHash m_index;
	DocsHash m_docs;
	
	void removeOccurance(uint64_t _word, ObjId _docid);
public:
	
	virtual ~InvertIndex();
	
	int getDocsCount();
	bool docinCategory(ObjId _docid, CatT _catid);
	void indexDoc(const Doc<CatT, ObjId, ObjT> &_doc);	
	void removeDoc(ObjId _id);
	void query(const TextRepr &_query, std::vector<ObjT> &_result) const;
	
	void query(const TextRepr &_query, CatT _cat, std::vector<ObjT> &_result) const;			
};

#include "index.impl"

#endif
