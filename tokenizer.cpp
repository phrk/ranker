#include "tokenizer.h"

uint64_t Tokenizer::getTokenId(const std::string &_token) {
	hiaux::hashtable<std::string, uint64_t>::iterator it = m_tokens.find(_token);
	if (it != m_tokens.end())
		return it->second;
	
	uint64_t newid = m_tokens.size();
	m_tokens[_token] = newid;
	return newid;
}

void Tokenizer::tokenizeDoc(uint64_t _id, const std::string &_title, const std::string &_text, Doc &_doc) {
	
}

void Tokenizer::tokenizeQuery(const std::string &_str_query, std::vector<uint64_t> _query) {
	
}
