#include "doc.h"

bool Doc::inCategory(uint64_t _cat) {
	return categories.find(_cat) != categories.end();
}