#include "tokenizer.h"

Tokenizer::~Tokenizer() {
	
}

uint64_t Tokenizer::getTokenId(const std::string &_token) {
	hiaux::hashtable<std::string, uint64_t>::iterator it = m_tokens.find(_token);
	if (it != m_tokens.end())
		return it->second;
	
	uint64_t newid = m_tokens.size();
	m_tokens[_token] = newid;

	return newid;
}

uint64_t Tokenizer::getTokenIdConst(const std::string &_token) const {
	
	hiaux::hashtable<std::string, uint64_t>::const_iterator it = m_tokens.find(_token);
	if (it != m_tokens.end())
		return it->second;
	return 0;
}

void Tokenizer::splitByDelims(const std::string &_text, std::vector<std::string> &_words) const {
	
	std::set<uint32_t> delims;
	delims.insert(0xE2); // '.'
	delims.insert(0x2E); // '.'
	delims.insert(0x20); // ' '
	delims.insert(0x2C); // ','
	delims.insert(0x3B); // ';'
	delims.insert(0x3A); // ':'
	delims.insert(0x2D); // '-'
	delims.insert(0x28); // '('
	delims.insert(0x29); // ')'
	delims.insert(0x7B); // '{'
	delims.insert(0x7D); // '}'
	delims.insert(0x22); // '"'
	delims.insert(0x27); // '''
	delims.insert(0x3C); // '<'
	delims.insert(0x3E); // '>'
	delims.insert(0x85); // '\n'
	
	splitUtf8(_text, delims, _words);
}

void Tokenizer::tokenizeText(const std::string &_text, TextRepr &_words) {
	
	std::string text (_text);
	toLowerUtf8(text);
	fix_utf8_string(text);
	
	
	std::vector<std::string> words;
	splitByDelims(text, words);
	
	for (int i = 0; i<words.size(); i++)
		if (words[i].size() != 0) {
				_words.push_back(getTokenId(words[i]));
		}
}

void Tokenizer::tokenizeTextConst(const std::string &_text, TextRepr &_words) const {
	
	
	std::string text (_text);
	toLowerUtf8(text);
	fix_utf8_string(text);
	
	std::vector<std::string> words;
	splitByDelims(text, words);
	
	for (int i = 0; i<words.size(); i++)
		if (words[i].size() != 0) {
			uint64_t id = getTokenIdConst(words[i]);
			if (id != 0)
				_words.push_back(id);
		}
	
}

void Tokenizer::tokenizeTextPrefixes(const std::string &_str_query, TextRepr &_text) {
	
	std::string text (_str_query);
	toLowerUtf8(text);
	fix_utf8_string(text);
	
	std::vector<std::string> words;
	splitByDelims(text, words);
	
	for (int i = 0; i<words.size(); i++)
		if (words[i].size() != 0) {
			
			std::vector<std::string> prefixes;
			getPrefixesUtf8(words[i], prefixes);
			
			for (int j = 0; j<prefixes.size(); j++)
				_text.push_back(getTokenId(prefixes[j]));
		}
}
/*
void Tokenizer::tokenizeDoc(uint64_t _id, const std::string &_text, Doc &_doc) {
	
	//std::string title(_title);
	std::string text(_text);
		
	tokenizeText(text, _doc.text);
	//tokenizeText(title, _doc.title);
	_doc.id = _id;
}*/
