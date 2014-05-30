#include "ranker.h"

void Ranker::addDoc(uint64_t _id, const std::string &_title, const std::string &_text) {
	std::vector<uint64_t> cats;
	addDoc(_id, _title, _text, cats);
}

void Ranker::addDoc(uint64_t _id, const std::string &_title, const std::string &_text,
			const std::vector<uint64_t> &_cats) {
	Doc doc;
	doc.categories.insert(0); // any category
	for (int i = 0; i<_cats.size(); i++)
		doc.categories.insert(_cats[i]);
	
	m_tokenizer.tokenizeDoc(_id, _title, _text, doc);
	m_index.indexDoc(doc);
}

void Ranker::removeDoc(uint64_t _id) {
	m_index.removeDoc(_id);
}

void Ranker::query(const std::string &_query, uint64_t _cat, std::vector<uint64_t> &_result) {
	std::vector<uint64_t> query;
	m_tokenizer.tokenizeText(_query, query);
	if (query.size() != 0)
		m_index.query(query, _cat, _result);
}
