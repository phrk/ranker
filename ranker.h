#ifndef _RANKER_H_
#define _RANKER_H_

#include "hiconfig.h"
#include "tokenizer.h"

class Ranker {
	Tokenizer m_tokenizer;
	InvertIndex m_index;
	
public:
	
	void addDoc(uint64_t _id, const std::string &_title, const std::string &_text);
	void removeDoc(uint64_t _id);
	
	void query(const std::string &_query, std::vector<uint64_t> &_result);
};

#endif
