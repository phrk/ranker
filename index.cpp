#include "index.h"

/*
void Occurs::leaveOnlyCategory(uint64_t _cat, Occurs &_occ) {
	std::vector<Occur>::iterator it = m_occurs.begin();
	std::vector<Occur>::iterator end = m_occurs.end();
	while (it != end) {
		if (m_docinCategory(it->docid, _cat)) {
			_occ.add(*it);
		}
	//		m_occurs.erase(it);
		it++;
	}
}
*/
void InvertIndex::indexDoc(const Doc &_doc) {
	
	DocPtr doc (new Doc(_doc));
	
	for (int i = 0; i<doc->text.size(); i++) {
		Occur occur(doc->id);
		hiaux::hashtable<uint64_t, Occurs>::iterator it = m_index.find(doc->text[i]);
		if (it == m_index.end()) {
			m_index.insert(std::pair<uint64_t, Occurs> (doc->text[i], 
				Occurs()) );
				it = m_index.find(doc->text[i]);
		}
				
		it->second.add( occur );
	}
	m_docs[doc->id] = doc;
}

bool InvertIndex::docinCategory(uint64_t _docid, uint64_t _catid) {
	return m_docs[_docid]->inCategory(_catid);
}

void InvertIndex::removeOccurance(uint64_t _word, uint64_t _docid) {
	hiaux::hashtable<uint64_t, Occurs>::iterator it = m_index.find(_word);
	if (it != m_index.end())
		it->second.removeOccurance(_docid);
}

void InvertIndex::removeDoc(uint64_t _id) {
	hiaux::hashtable<uint64_t, DocPtr>::iterator it = m_docs.find(_id);
	if (it != m_docs.end()) {
		//for (int i = 0; i<it->second.title.size(); i++)
		//	removeOccurance(it->second.title[i], _id);
		
		for (int i = 0; i<it->second->text.size(); i++)
			removeOccurance(it->second->text[i], _id);
		
		m_docs.erase(it);
	}
}

void InvertIndex::query(const std::vector<uint64_t> &_query, //uint64_t _cat,
						std::vector<uint64_t> &_result) const {
	
	hiaux::hashtable<uint64_t, Occurs>::const_iterator it = m_index.find(_query[0]);
	if (it == m_index.end())
		return;
	
	Occurs res = it->second;
	//res0.leaveOnlyCategory(_cat, res);
	
	for (int i = 1; i<_query.size(); i++) {
		it = m_index.find(_query[i]);
		if (it == m_index.end())
			continue;
		
		res.intersect (res, it->second, res);
	}
	
	res.getDocIds(_result);
	//std::cout << "result size: " << _result.size() << " category: " << _cat << std::endl;
}

void InvertIndex::query(const std::vector<uint64_t> &_query, uint64_t _cat,
	 		std::vector<uint64_t> &_result) const {
	 
	throw "not implemented";
}
