#ifndef _RANKER2_DEFS_H_
#define _RANKER2_DEFS_H_

#include <vector>
#include <string>

#include "hiaux/structs/hashtable.h"

namespace rnk2 {

typedef int TokenIdT;
typedef std::vector<TokenIdT> TextRepr;

typedef float RnkReal;

typedef float GeoCoord;

template <class K, class V>
class hashtable : public hiaux::hashtable<K,V> {
public:
	virtual ~hashtable() { };
};

}

#endif
