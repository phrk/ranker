#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

#include "hiconfig.h"
#include "hiaux/structs/hashtable.h"
#include "hiaux/strings/string_utils.h"
#include <vector>
#include <string>
#include <iostream>
#include "doc.h"

class Tokenizer {
	hiaux::hashtable<std::string, uint64_t> m_tokens;
	void textToIds(const std::string &_text, std::vector<uint32_t> &_words);
	
	void splitByDelims(const std::string &_text, std::vector<std::string> &_words);
public:
	uint64_t getTokenId(const std::string &_token);
	void tokenizeDoc(uint64_t _id, const std::string &_text, Doc &_doc);
	void tokenizeText(const std::string &_str_query, std::vector<uint64_t> &_query);
	void tokenizeTextPrefixes(const std::string &_str_query, std::vector<uint64_t> &_query);
};

#endif
