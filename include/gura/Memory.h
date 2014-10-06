//=============================================================================
// Memory
//=============================================================================
#ifndef __GURA_MEMORY_H__
#define __GURA_MEMORY_H__
#include "Common.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Memory
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Memory {
protected:
	int _cntRef;
	size_t _bytes;
	char *_buff;
public:
	Gura_DeclareReferenceAccessor(Memory);
public:
	inline Memory() : _cntRef(1), _bytes(0), _buff(NULL) {}
protected:
	virtual ~Memory();
public:
	inline size_t GetSize() const { return _bytes; }
	inline char *GetPointer(size_t offset = 0) { return _buff + offset; }
	inline const char *GetPointer(size_t offset = 0) const { return _buff + offset; }
	inline operator Int *()		{ return reinterpret_cast<Int *>(_buff);	}
	inline operator UInt *()	{ return reinterpret_cast<UInt *>(_buff);	}
	inline operator Char *()	{ return reinterpret_cast<Char *>(_buff);	}
	inline operator UChar *()	{ return reinterpret_cast<UChar *>(_buff);	}
	inline operator Short *()	{ return reinterpret_cast<Short *>(_buff);	}
	inline operator UShort *()	{ return reinterpret_cast<UShort *>(_buff);	}
	inline operator Long *()	{ return reinterpret_cast<Long *>(_buff);	}
	inline operator ULong *()	{ return reinterpret_cast<ULong *>(_buff);	}
	inline operator Int64 *()	{ return reinterpret_cast<Int64 *>(_buff);	}
	inline operator UInt64 *()	{ return reinterpret_cast<UInt64 *>(_buff);	}
private:
	inline Memory(const Memory &memory) {}
};

//-----------------------------------------------------------------------------
// MemoryList
//-----------------------------------------------------------------------------
class MemoryList : public std::vector<Memory *> {
};

//-----------------------------------------------------------------------------
// MemoryOwner
//-----------------------------------------------------------------------------
class MemoryOwner : public MemoryList {
public:
	~MemoryOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// MemoryHeap
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE MemoryHeap : public Memory {
public:
	MemoryHeap(size_t bytes);
protected:
	virtual ~MemoryHeap();
};

#if defined(GURA_ON_MSWIN)
//-----------------------------------------------------------------------------
// MemoryDIB
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE MemoryDIB : public Memory {
private:
	HBITMAP _hBitmap;
public:
	MemoryDIB();
protected:
	virtual ~MemoryDIB();
public:
	inline HBITMAP GetHBITMAP() { return _hBitmap; }
	bool AllocBuffer(size_t width, size_t height, size_t bitsPerPixel);
};
#endif

}

#endif
