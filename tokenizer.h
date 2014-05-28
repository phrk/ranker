#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

#include "hiconfig.h"
#include "hiaux/structs/hashtable.h"
#include "hiaux/strings/string_utils.h"
#include <vector>
#include <string>

class Tokenizer {
	hiaux::hashtable<std::string, uint64_t> m_tokens;
public:
	uint64_t getTokenId(const std::string &_token);
	void tokenizeDoc(uint64_t _id, const std::string &_title, const std::string &_text, Doc &_doc);
	void tokenizeQuery(const std::string &_str_query, std::vector<uint64_t> _query);
};

#endif
