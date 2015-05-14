#ifndef _TOKENIZER2_H_
#define _TOKENIZER2_H_

#include "hiconfig.h"
#include "hiaux/structs/hashtable.h"
#include "hiaux/strings/string_utils.h"
#include <boost/algorithm/string.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "doc.h"

namespace rnk2 {

template<class TokenIdT>
class Tokenizer {
	hashtable<std::string, TokenIdT> m_tokens;
	void textToIds(const std::string &_text, std::vector<TokenIdT> &_words);
	
	void splitByDelims(const std::string &_text, std::vector<std::string> &_words) const;
	
	bool m_by_pref;
public:
	
	Tokenizer(bool _by_pref);
	
	TokenIdT getTokenId(const std::string &_token);
	TokenIdT getTokenIdConst(const std::string &_token) const;

	void tokenizeText(const std::string &_str_query, TextRepr &_text);
	void tokenizeTextConst(const std::string &_str_query, TextRepr &_text) const;
	
	void tokenizeTextPrefixes(const std::string &_str_query, TextRepr &_text);
	
	virtual ~Tokenizer();
};

#include "tokenizer.impl"

}

#endif
