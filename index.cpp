#include "index.h"

Occur::Occur(uint64_t _docid):
	docid (_docid) {
	
}

bool cmpOccur (Occur &_a, Occur &_b) {
	return _a.docid < _b.docid;
}

Occurs::Occurs(boost::function<bool(uint64_t, uint64_t)> _docinCategory):
	m_docinCategory(_docinCategory)
{
}

void Occurs::add(Occur &_occur) {
	m_occurs.push_back(_occur);
	std::sort(m_occurs.begin(), m_occurs.end(), cmpOccur);
}

void Occurs::getDocIds(std::vector<uint64_t> &_docids) {
	for (int i = 0; i<m_occurs.size(); i++)
		_docids.push_back(m_occurs[i].docid);
}

void Occurs::intersect(const Occurs &_a, const Occurs &_b, Occurs &_res, uint64_t _cat) {
//	std::cout << "Occurs::intersect " << _a.m_occurs.size()
//		 << " " <<  _b.m_occurs.size() << std::endl;
	
	int a_pos = 0;
	int b_pos = 0;
	Occurs res(m_docinCategory);
	while (1) {
		
		if (a_pos >= _a.m_occurs.size())
			break;
		if (b_pos >= _b.m_occurs.size())
			break;
		
		if (! m_docinCategory(_a.m_occurs[a_pos].docid, _cat) ) {
			a_pos++;
			continue;
		}
		
		if (! m_docinCategory(_a.m_occurs[b_pos].docid, _cat) ) {
			b_pos++;
			continue;
		}
		
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

void Occurs::leaveOnlyCategory(uint64_t _cat, Occurs &_occ) {
	std::vector<Occur>::iterator it = m_occurs.begin();
	std::vector<Occur>::iterator end = m_occurs.end();
	while (it != end) {
		if ( m_docinCategory(it->docid, _cat) ) {
			_occ.add(*it);
		}
	//		m_occurs.erase(it);
		it++;
	}
}

void InvertIndex::indexDoc(const Doc &_doc) {
	for (int i = 0; i<_doc.text.size(); i++) {
		Occur occur(_doc.id);
		hiaux::hashtable<uint64_t, Occurs>::iterator it = m_index.find(_doc.text[i]);
		if (it == m_index.end()) {
			m_index.insert(std::pair<uint64_t, Occurs> (_doc.text[i], 
				Occurs(boost::bind(&InvertIndex::docinCategory, this, _1, _2))) );
				it = m_index.find(_doc.text[i]);
		}
				
		
		it->second.add( occur );
	}
	m_docs[_doc.id] = _doc; 
}

bool InvertIndex::docinCategory(uint64_t _docid, uint64_t _catid) {
	return m_docs[_docid].inCategory(_catid);
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

void InvertIndex::query(const std::vector<uint64_t> &_query, uint64_t _cat, std::vector<uint64_t> &_result) {
	
	hiaux::hashtable<uint64_t, Occurs>::iterator it = m_index.find(_query[0]);
	if (it == m_index.end())
		return;
	
	Occurs res0 = it->second;
	Occurs res(boost::bind(&InvertIndex::docinCategory, this, _1, _2));
	res0.leaveOnlyCategory(_cat, res);
	
	for (int i = 1; i<_query.size(); i++) {
		it = m_index.find(_query[i]);
		if (it == m_index.end())
			continue;
		
		res.intersect (res, it->second, res, _cat);
	}
	
	res.getDocIds(_result);
	std::cout << "result size: " << _result.size() << std::endl;
}
