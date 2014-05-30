#include "index.h"

Occur::Occur(uint64_t _docid):
	docid (_docid) {
	
}

bool cmpOccur (Occur &_a, Occur &_b) {
	return _a.docid < _b.docid;
}

void Occurs::add(Occur &_occur) {
	m_occurs.push_back(_occur);
	std::sort(m_occurs.begin(), m_occurs.end(), cmpOccur);
}

void Occurs::getDocIds(std::vector<uint64_t> &_docids) {
	for (int i = 0; i<m_occurs.size(); i++)
		_docids.push_back(m_occurs[i].docid);
}

void Occurs::intersect(const Occurs &_a, const Occurs &_b, Occurs &_res) {
//	std::cout << "Occurs::intersect " << _a.m_occurs.size()
//		 << " " <<  _b.m_occurs.size() << std::endl;
	
	int a_pos = 0;
	int b_pos = 0;
	Occurs res;
	while (1) {
		
		if (a_pos >= _a.m_occurs.size())
			break;
		if (b_pos >= _b.m_occurs.size())
			break;
		
		if ( _a.m_occurs[a_pos].docid == _b.m_occurs[b_pos].docid ) {
			res.m_occurs.push_back(  _a.m_occurs[a_pos] );
			a_pos++;
			b_pos++;
		}
		else if ( _a.m_occurs[a_pos].docid < _b.m_occurs[b_pos].docid)
			a_pos++;
		else
			b_pos++;
		
	}
	_res = res;
}

void InvertIndex::indexDoc(const Doc &_doc) {
	for (int i = 0; i<_doc.text.size(); i++) {
		Occur occur(_doc.id);
		m_index[ _doc.text[i] ].add( occur );
	}
	m_docs[_doc.id] = _doc; 
}

void Occurs::removeOccurance(uint64_t _docid) {
	
	std::vector<Occur>::iterator it = m_occurs.begin();
	std::vector<Occur>::iterator end = m_occurs.end();
	
	while (it != end) {
		if (it->docid == _docid) {
			m_occurs.erase(it);
			break;
		}
		it++;
	}	
}

void InvertIndex::removeOccurance(uint64_t _word, uint64_t _docid) {
	hiaux::hashtable<uint64_t, Occurs>::iterator it = m_index.find(_word);
	if (it != m_index.end())
		it->second.removeOccurance(_docid);
}

void InvertIndex::removeDoc(uint64_t _id) {
	hiaux::hashtable<uint64_t, Doc>::iterator it = m_docs.find(_id);
	if (it != m_docs.end()) {
		for (int i = 0; i<it->second.title.size(); i++)
			removeOccurance(it->second.title[i], _id);
		
		for (int i = 0; i<it->second.text.size(); i++)
			removeOccurance(it->second.text[i], _id);
	}
}

void InvertIndex::query(const std::vector<uint64_t> &_query, std::vector<uint64_t> &_result) {
	
	Occurs res = m_index[ _query[0] ];
	for (int i = 1; i<_query.size(); i++) {
		Occurs::intersect (res, m_index[ _query[i] ], res);
	}
	res.getDocIds(_result);
}
