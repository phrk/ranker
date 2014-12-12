#include "doc.h"

Doc::Doc() {
	
}

Doc::Doc(uint64_t _id, const std::vector<uint64_t> &_title, const std::vector<uint64_t> &_text, const std::set<uint64_t> &_categories) {
	
	id =_id;
	title = _title;
	text = _text;
	categories = _categories;
}

Doc::~Doc() {
	
}

bool Doc::inCategory(uint64_t _cat) {
	return categories.find(_cat) != categories.end();
}
