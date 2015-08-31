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

template<int v>
struct Int2Type {
	enum { value = v };
};

template <class T>
struct Type2Type {
	typedef T OriginalType;
};

struct ByPrefixes {
};

struct ByWords {
};

//template<class TokenIdT>
class TokenizerIfs {
public:
	
	virtual ~TokenizerIfs() { }
	virtual void tokenizeText(const std::string &_str_query, TextRepr &_text) = 0;
	virtual void tokenizeTextConst(const std::string &_str_query, TextRepr &_text) const = 0;
};

typedef boost::shared_ptr<TokenizerIfs> TokenizerIfsPtr;

template<class TokenIdT, class ModeT = ByWords>
class Tokenizer : public TokenizerIfs {
	
	hashtable<std::string, TokenIdT> m_tokens;
	void textToIds_(const std::string &_text, std::vector<TokenIdT> &_words);
	
	void splitByDelims_(const std::string &_text, std::vector<std::string> &_words) const;
		
	void tokenizeText_(const std::string &_text, TextRepr &_words, Type2Type<ByPrefixes>);
	void tokenizeText_(const std::string &_text, TextRepr &_words, Type2Type<ByWords>);
	
	TokenIdT getTokenId_(const std::string &_token);
	TokenIdT getTokenIdConst_(const std::string &_token) const;
	
	void tokenizeTextPrefixes_(const std::string &_str_query, TextRepr &_text);
	
public:
	
	Tokenizer();
	
	virtual void tokenizeText(const std::string &_str_query, TextRepr &_text);
	virtual void tokenizeTextConst(const std::string &_str_query, TextRepr &_text) const;
	
	virtual ~Tokenizer();
};

#include "tokenizer.impl"

}

#endif
