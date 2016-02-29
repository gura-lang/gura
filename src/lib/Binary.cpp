//=============================================================================
// Binary
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Binary::PackerEx
//-----------------------------------------------------------------------------
bool Binary::PackerEx::PackAt(Signal &sig, size_t offset, size_t bytes)
{
	return true;
}

void Binary::PackerEx::PackBuffer(size_t offset, const UChar *buff, size_t bytes)
{
	if (offset < _buff.size()) {
		size_t bytesToCopy = ChooseMin(_buff.size() - offset, bytes);
		std::copy(buff, buff + bytesToCopy, _buff.begin() + offset);
		buff += bytesToCopy;
		bytes -= bytesToCopy;
	} else if (offset > _buff.size()) {
		_buff.append(offset - _buff.size(), '\0');
	}
	_buff.append(buff, buff + bytes);
}

const UChar *Binary::PackerEx::UnpackAt(Signal &sig, size_t offset,
									size_t bytes, bool exceedErrorFlag)
{
	if (offset + bytes <= _buff.size()) {
		return reinterpret_cast<const UChar *>(_buff.data() + offset);
	}
	if (exceedErrorFlag) {
		sig.SetError(ERR_IndexError, "pointer exceeds the range of binary");
	}
	return nullptr;
}

}
