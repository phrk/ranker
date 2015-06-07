#ifndef _INVINDEX2_H_
#define _INVINDEX2_H_

#include "hiconfig.h"

#include "rnk_ex.h"
#include "doc.h"

#include <list>

#include <iostream>
#include <algorithm>

#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/noncopyable.hpp>

#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/stats.hpp>

#include <math.h>

#include "occurs.h"
#include "query.h"

namespace rnk2 {

template <class CatT, class ObjId>
class InvertIndex : public boost::noncopyable {

	typedef boost::shared_ptr<Doc <CatT, ObjId> > DocPtr;
	typedef hashtable<TokenIdT, DocPtr> DocsHash;
	typedef hashtable<TokenIdT, Occurs<ObjId> > OccursHash;
	typedef std::vector< std::pair<ObjId, RnkReal> > DocsWeights;

	OccursHash m_index;
	DocsHash m_docs;
	boost::accumulators::accumulator_set<double, boost::accumulators::stats<boost::accumulators::tag::mean> > m_avg_docl_acc;

	void removeOccurance(TokenIdT _word, ObjId _docid);

	RnkReal calcBM25(DocPtr _doc, const Query &_query) const;
	void buildQuery(const TextRepr &_query_tokens, Query &_query) const;
	void query(const TextRepr &_query_tokens, std::vector<ObjId> &_result, bool _category_set, CatT _cat) const;

public:

	virtual ~InvertIndex();

	int getDocsCount() const;
	bool docinCategory(ObjId _docid, CatT _catid) const;
	void indexDoc(const Doc<CatT, ObjId> &_doc);
	void removeDoc(ObjId _id);
	void query(const TextRepr &_query_tokens, std::vector<ObjId> &_result) const;
	void query(const TextRepr &_query_tokens, CatT _cat, std::vector<ObjId> &_result) const;			
};

#include "index.impl"

}

#endif
