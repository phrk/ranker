#include "ranker.h"

void Ranker::addDoc(uint64_t _id, const std::string &_title, const std::string &_text) {
	Doc doc;
	m_tokenizer.tokenizeDoc(_id, _title, _text, doc);
	m_index.indexDoc(doc);
}

void Ranker::removeDoc(uint64_t _id) {
	
}

void Ranker::query(const std::string &_query, std::vector<uint64_t> &_result) {
	
}
