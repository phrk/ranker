#include "occurs.h"

Occur::Occur(ObjId _docid):
	docid (_docid) {
	
}

Occurs::~Occurs() {
	
}

bool cmpOccur (const Occur &_a, const Occur &_b) {
	return _a.docid < _b.docid;
}

Occurs::Occurs()
	//:m_docinCategory(_docinCategory)
{
}

void Occurs::add(Occur &_occur) {
	m_occurs.push_back(_occur);
	std::sort(m_occurs.begin(), m_occurs.end(), cmpOccur);
	
	/*
	std::list<Occur>::iterator it = m_occurs.begin();
	std::list<Occur>::iterator end = m_occurs.end();
	
	while ( _occur.docid > it->docid &&
			it != end) {
		it++;		
	}
	
	if (it != end)
		m_occurs.insert(it, _occur);
	else
		m_occurs.push_back(_occur);*/
}

void Occurs::getDocIds(std::vector<ObjId> &_docids) {

	for (int i = 0; i<m_occurs.size(); i++)
		_docids.push_back( m_occurs[i].docid );
/*	
	std::list<Occur>::iterator it = m_occurs.begin();
	std::list<Occur>::iterator end = m_occurs.end();

	while (it != end) {
		_docids.push_back( it->docid );
		it++;
	}*/
}

void Occurs::intersect(const Occurs &_a, const Occurs &_b, Occurs &_res) {
//	std::cout << "Occurs::intersect " << _a.m_occurs.size()
//		 << " " <<  _b.m_occurs.size() << std::endl;
	
	int a_pos = 0;
	int b_pos = 0;
	Occurs res;
/*	
	std::list<Occur>::const_iterator it_a = _a.m_occurs.begin();
	std::list<Occur>::const_iterator end_a = _a.m_occurs.end();
	
	std::list<Occur>::const_iterator it_b = _b.m_occurs.begin();
	std::list<Occur>::const_iterator end_b = _b.m_occurs.end();
	*/
	while (1) {
		
		/*
		while (! m_docinCategory(_a.m_occurs[a_pos].docid, _cat) && a_pos < _a.m_occurs.size())
			a_pos++;
		*/
		/*
		if (it_a == end_a)
			break;
		
		if (it_b == end_b)
			break;
		*/
		/*
		while (! m_docinCategory(_a.m_occurs[b_pos].docid, _cat) && b_pos < _b.m_occurs.size())
			b_pos++;
		*/
		
		if (a_pos >= _a.m_occurs.size())
			break;
		
		if (b_pos >= _b.m_occurs.size())
			break;
		
		
		//if (it_a->docid == it_b->docid) {
		if ( _a.m_occurs[a_pos].docid == _b.m_occurs[b_pos].docid ) {
			
			res.m_occurs.push_back(  _a.m_occurs[a_pos] );
			//res.m_occurs.push_back(*it_a);
			a_pos++;
			b_pos++;
			//it_a++;
			//it_b++;
		}
		//else if (it_a->docid < it_b->docid)
		else if ( _a.m_occurs[a_pos].docid < _b.m_occurs[b_pos].docid)
			//it_a++;
			a_pos++;
		else // _a.m_occurs[a_pos].docid > _b.m_occurs[b_pos].docid
			//it_b++;
			b_pos++;
		
	}
	_res = res;
}

void Occurs::removeOccurance(ObjId _docid) {
	
	
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
