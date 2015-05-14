#ifndef _RANKER2_EXCEPTION_
#define _RANKER2_EXCEPTION_

#include <exception>
#include <string>

namespace rnk2 {

class RnkEx : std::exception {
	std::string m_mess;
public:
	
	RnkEx(const std::string &_mess);
	RnkEx();
	virtual ~RnkEx() throw ();
	virtual const char* what();
};

}

#endif
