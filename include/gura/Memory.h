//=============================================================================
// Memory
//=============================================================================
#ifndef __GURA_MEMORY_H__
#define __GURA_MEMORY_H__
#include "Common.h"
#include "Packer.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Memory
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Memory {
public:
	class GURA_DLLDECLARE PackerEx : public Packer {
	private:
		Memory &_memory;
	public:
		inline PackerEx(Memory &memory) : _memory(memory) {}
		virtual bool PackAt(Signal &sig, size_t offset, size_t bytes);
		virtual void PackBuffer(size_t offset, const UChar *buff, size_t bytes);
		virtual const UChar *UnpackAt(Signal &sig, size_t offset,
									  size_t bytes, bool exceedErrorFlag);
	};
protected:
	int _cntRef;
	size_t _bytes;
	char *_buff;
public:
	Gura_DeclareReferenceAccessor(Memory);
public:
	inline Memory() : _cntRef(1), _bytes(0), _buff(nullptr) {}
	inline Memory(size_t bytes, void *buff) : _cntRef(1),
		_bytes(bytes), _buff(reinterpret_cast<char *>(buff)) {}
protected:
	virtual ~Memory();
public:
	inline size_t GetSize() const { return _bytes; }
	inline char *GetPointer() { return _buff; }
	inline char *GetPointer(size_t offset) { return _buff + offset; }
	inline const char *GetPointer() const { return _buff; }
	inline const char *GetPointer(size_t offset) const { return _buff + offset; }
public:
	inline bool Pack(Environment &env, size_t &offset,
					 const char *format, const ValueList &valListArg) {
		return PackerEx(*this).Pack(env, offset, format, valListArg);
	}
	inline Value Unpack(Environment &env, size_t &offset, const char *format,
						const ValueList &valListArg, bool exceedErrorFlag) {
		return PackerEx(*this).Unpack(env, offset, format, valListArg, exceedErrorFlag);
	}
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
