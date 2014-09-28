#include "ranker.h"

//void Ranker::addDoc(uint64_t _id, const std::string &_title, const std::string &_text) {
//	std::vector<uint64_t> cats;
//	addDoc(_id, _title, _text, cats);
//}

void Ranker::addDoc(Doc *_doc) {
	//Doc doc;
	//doc.categories.insert(0); // any category
	//for (int i = 0; i<_cats.size(); i++)
	//	doc.categories.insert(_cats[i]);
	
	//m_tokenizer.tokenizeText(_id, _text);
	m_index.indexDoc(_doc);
}

void Ranker::removeDoc(uint64_t _id) {
	m_index.removeDoc(_id);
}

void Ranker::query(const std::string &_query, //uint64_t _cat, 
						std::vector<uint64_t> &_result) const {
	std::vector<uint64_t> query;
	m_tokenizer.tokenizeTextConst(_query, query);
	if (query.size() != 0)
		m_index.query(query, _result);
}
