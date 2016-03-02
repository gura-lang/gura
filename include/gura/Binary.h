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
	class GURA_DLLDECLARE PackerEx : public Packer {
	private:
		Binary &_buff;
	public:
		inline PackerEx(Binary &buff) : _buff(buff) {}
		virtual bool PackPrepare(Signal &sig, size_t offset, size_t bytes);
		virtual void PackBuffer(size_t offset, const UChar *buff, size_t bytes);
		virtual const UChar *UnpackPrepare(Signal &sig, size_t offset,
									  size_t bytes, bool exceedErrorFlag);
	};
public:
	inline Binary() {}
	inline Binary(const Binary &binary) : String(binary) {}
	inline Binary(const String &str) : String(str) {}
	inline Binary(const char *str) : String(str) {}
	inline Binary(const char *buff, size_t size) : String(buff, size) {}
	inline Binary &operator=(const Binary &binary) {
		String::operator=(binary);
		return *this;
	}
};

}

#endif
