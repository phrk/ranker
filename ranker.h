#ifndef _RANKER_H_
#define _RANKER_H_

#include "hiconfig.h"
#include "tokenizer.h"
#include "index.h"
#include <boost/shared_ptr.hpp>

class Ranker {
	
	InvertIndex m_index;
	
public:
	
	Tokenizer m_tokenizer;
	
	void addDoc(Doc *_doc);
	//void addDoc(uint64_t _id, const std::string &_title, const std::string &_text,
	//			const std::vector<uint64_t> &_cats);
	
	void removeDoc(uint64_t _id);
	
	void query(const std::string &_query, //uint64_t _cat,
										std::vector<uint64_t> &_result) const;
};

typedef boost::shared_ptr<Ranker> RankerPtr;

#endif
