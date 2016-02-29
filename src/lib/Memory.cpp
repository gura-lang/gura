//=============================================================================
// Memory
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Memory
//-----------------------------------------------------------------------------
Memory::~Memory()
{
	// virtual destructor
}

//-----------------------------------------------------------------------------
// Memory::PackerEx
//-----------------------------------------------------------------------------
bool Memory::PackerEx::PackAt(Signal &sig, size_t offset, size_t bytes)
{
	if (offset + bytes <= _memory.GetSize()) return true;
	sig.SetError(ERR_IndexError, "pointer exceeds the range of memory");
	return false;
}

void Memory::PackerEx::PackBuffer(size_t offset, const UChar *buff, size_t bytes)
{
	if (offset >= _memory.GetSize()) return;
	size_t bytesToCopy = ChooseMin(_memory.GetSize() - offset, bytes);
	::memcpy(_memory.GetPointer(offset), buff, bytesToCopy);
}

const UChar *Memory::PackerEx::UnpackAt(Signal &sig, size_t offset,
									size_t bytes, bool exceedErrorFlag)
{
	if (offset + bytes <= _memory.GetSize()) {
		return reinterpret_cast<const UChar *>(_memory.GetPointer(offset));
	}
	if (exceedErrorFlag) {
		sig.SetError(ERR_IndexError, "pointer exceeds the range of memory");
	}
	return nullptr;
}

//-----------------------------------------------------------------------------
// MemoryOwner
//-----------------------------------------------------------------------------
MemoryOwner::~MemoryOwner()
{
	Clear();
}

void MemoryOwner::Clear()
{
	foreach (MemoryOwner, ppMemory, *this) {
		Memory *pMemory = *ppMemory;
		Memory::Delete(pMemory);
	}
	clear();
}

#if defined(GURA_ON_MSWIN)

//-----------------------------------------------------------------------------
// MemoryHeap
//-----------------------------------------------------------------------------
MemoryHeap::MemoryHeap(size_t bytes)
{
	_bytes = bytes;
	_buff = reinterpret_cast<char *>(::LocalAlloc(LMEM_FIXED, _bytes));
}

MemoryHeap::~MemoryHeap()
{
	::LocalFree(_buff);
}

//-----------------------------------------------------------------------------
// MemoryDIB
//-----------------------------------------------------------------------------
MemoryDIB::MemoryDIB() : _hBitmap(nullptr)
{
}

MemoryDIB::~MemoryDIB()
{
	if (_hBitmap != nullptr) ::DeleteObject(_hBitmap);
}

bool MemoryDIB::AllocBuffer(size_t width, size_t height, size_t bitsPerPixel)
{
	BITMAPINFO bmi;
	BITMAPINFOHEADER &hdr = bmi.bmiHeader;
	::memset(&bmi, 0, sizeof(BITMAPINFO));
	hdr.biSize = sizeof(BITMAPINFOHEADER);
	hdr.biWidth = static_cast<int>(width);
	hdr.biHeight = -static_cast<int>(height);
	hdr.biPlanes = 1;
	hdr.biBitCount = static_cast<int>(bitsPerPixel);
	hdr.biCompression = BI_RGB;
	hdr.biSizeImage = 0;
	hdr.biXPelsPerMeter = 0;
	hdr.biYPelsPerMeter = 0;
	hdr.biClrUsed = 0;
	hdr.biClrImportant = 0;
	void *buff = nullptr;
	_hBitmap = ::CreateDIBSection(nullptr, &bmi, DIB_RGB_COLORS, &buff, nullptr, 0);
	_buff = reinterpret_cast<char *>(buff);
	_bytes = ((bitsPerPixel + 7) / 8 * width + 3) / 4 * 4;
	return _hBitmap != nullptr && _buff != nullptr;
}

#else

//-----------------------------------------------------------------------------
// MemoryHeap
//-----------------------------------------------------------------------------
MemoryHeap::MemoryHeap(size_t bytes)
{
	_bytes = bytes;
	_buff = reinterpret_cast<char *>(::malloc(_bytes));
}

MemoryHeap::~MemoryHeap()
{
	::free(_buff);
}

#endif

}
