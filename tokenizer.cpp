#include "tokenizer.h"

uint64_t Tokenizer::getTokenId(const std::string &_token) {
	hiaux::hashtable<std::string, uint64_t>::iterator it = m_tokens.find(_token);
	if (it != m_tokens.end())
		return it->second;
	
	uint64_t newid = m_tokens.size();
	m_tokens[_token] = newid;
//	std::cout << "new token: " << _token << newid << std::endl;
	return newid;
}

void Tokenizer::tokenizeText(const std::string &_text, std::vector<uint64_t> &_words) {
	
	std::string text (_text);
	toLowerUtf8(text);
	fix_utf8_string(text);
	
//	std::cout << "tokenize text: " << _text << std::endl << "splited: ";
	
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
	
	std::vector<std::string> words;
	splitUtf8(text, delims, words);
	for (int i = 0; i<words.size(); i++)
		if (words[i].size() != 0) {
				_words.push_back(getTokenId(words[i]));
				//std::cout << words[i] << " ";
		}
//	std::cout << std::endl;
}

void Tokenizer::tokenizeDoc(uint64_t _id, const std::string &_title, const std::string &_text, Doc &_doc) {
	
	std::string title(_title);
	std::string text(_text);
		
	tokenizeText(text, _doc.text);
	//tokenizeText(title, _doc.title);
	_doc.id = _id;
}
