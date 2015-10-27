//=============================================================================
// MemoryPool
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// MemoryPool
//-----------------------------------------------------------------------------
class MemoryPool {
public:
	class Chunk {
	private:
		size_t _bytesBlock;
		size_t _nBlocks;
		size_t _iBlockNext;
		char *_buff;
		char *_pFreed;
	public:
		inline Chunk(size_t bytesBlock, size_t nBlocks) :
			_bytesBlock(bytesBlock), _nBlocks(nBlocks), _iBlockNext(nBlocks),
			_buff(nullptr), _pFreed(nullptr) {}
		bool Initialize(size_t nBlocks);
		void *Allocate();
		void Free(void *p);
	};
private:
	Chunk *_pChunk;
	static MemoryPool _inst;
public:
	inline MemoryPool() : _pChunk(nullptr) {}
	inline void *Allocate(size_t bytes) { return _inst.DoAllocate(bytes); }
	inline void Free(void *p) { _inst.DoFree(p); }
private:
	void *DoAllocate(size_t bytes);
	void DoFree(void *p);
};

//-----------------------------------------------------------------------------
// MemoryPool
//-----------------------------------------------------------------------------
MemoryPool MemoryPool::_inst;

void *MemoryPool::DoAllocate(size_t bytes)
{
	return nullptr;
}

void MemoryPool::DoFree(void *p)
{
	char *pRaw = reinterpret_cast<char *>(p) - sizeof(Chunk *);
	Chunk *pChunk = *reinterpret_cast<Chunk **>(pRaw);
	pChunk->Free(p);
}

//-----------------------------------------------------------------------------
// MemoryPool::Chunk
//-----------------------------------------------------------------------------
void *MemoryPool::Chunk::Allocate()
{
	char *pRaw = nullptr;
	if (_pFreed == nullptr) {
		size_t bytesFrame = sizeof(Chunk *) + _bytesBlock;
		if (_iBlockNext >= _nBlocks) {
			_iBlockNext = 0;
			_buff = reinterpret_cast<char *>(::malloc(bytesFrame * _nBlocks));
		}
		pRaw = _buff + bytesFrame * _iBlockNext;
		_iBlockNext++;
	} else {
		pRaw = _pFreed;
		_pFreed = *reinterpret_cast<char **>(pRaw);
	}
	*reinterpret_cast<Chunk **>(pRaw) = this;
	return pRaw + sizeof(Chunk *);
}

void MemoryPool::Chunk::Free(void *p)
{
	char *pRaw = reinterpret_cast<char *>(p) - sizeof(Chunk *);
	*reinterpret_cast<char **>(pRaw) = _pFreed;
	_pFreed = pRaw;
}

}
