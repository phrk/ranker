#ifndef _RANKER_H_
#define _RANKER_H_

#include "hiconfig.h"
#include "tokenizer.h"
#include "index.h"
#include <boost/shared_ptr.hpp>

#include <boost/noncopyable.hpp>

class Ranker : public boost::noncopyable {
	
	InvertIndex m_index;
	Tokenizer m_tokenizer;
	
public:
	
	Ranker();
	virtual ~Ranker();
	
	void addDoc(const Doc &_doc);
	void addDoc(uint64_t _id, const std::string &_title, const std::string &_text, const std::set<uint64_t> &_categories);
	void addDoc(uint64_t _id, const std::string &_title, const std::string &_text);

	void removeDoc(uint64_t _id);
	
	void query(const std::string &_query, std::vector<uint64_t> &_result) const;
	void query(const std::string &_query, uint64_t _cat, std::vector<uint64_t> &_result) const;
};

typedef boost::shared_ptr<Ranker> RankerPtr;

#endif
