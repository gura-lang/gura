//=============================================================================
// Binary
//=============================================================================
#ifndef __GURA_BINARY_H__
#define __GURA_BINARY_H__

#include "Common.h"
#include "Signal.h"
#include "Value.h"
#include "Packer.h"

namespace Gura {

class GURA_DLLDECLARE Binary : public String {
public:
	inline Binary() {}
	inline Binary(const Binary &binary) : String(binary) {}
	inline Binary(const String &str) : String(str) {}
	inline Binary(const char *str) : String(str) {}
	inline Binary(const char *buff, size_t size) : String(buff, size) {}
	inline Binary(size_t bytes) : String(bytes, '\0') {}
	inline Binary &operator=(const Binary &binary) {
		String::operator=(binary);
		return *this;
	}
};

}

#endif
