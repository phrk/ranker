#include "rnk_ex.h"

namespace rnk2 {

RnkEx::RnkEx(const std::string &_mess):
m_mess(_mess) {
}

RnkEx::RnkEx() {
}

RnkEx::~RnkEx() throw() {
	
}

const char* RnkEx::what() {
	
	return m_mess.c_str();
}

}
