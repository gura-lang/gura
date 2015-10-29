//=============================================================================
// MemoryPool
//=============================================================================
#ifndef __GURA_MEMORYPOOL_H__
#define __GURA_MEMORYPOOL_H__
#include "Common.h"

namespace Gura {

//-----------------------------------------------------------------------------
// MemoryPool
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE MemoryPool {
public:
	class Chunk {
	public:
		virtual void Free(void *p) = 0;
	};
	struct Header {
		union {
			Chunk *pChunk;
			Header *pHeaderNext;
		} u;
		const char *ownerName;
	};
	class ChunkFixed : public Chunk {
	private:
		size_t _bytesBlock;
		size_t _nBlocks;
		size_t _iBlockNext;
		char *_buff;
		Header *_pHeaderFreed;
	public:
		inline ChunkFixed(size_t bytesBlock, size_t nBlocks) :
			_bytesBlock(bytesBlock), _nBlocks(nBlocks), _iBlockNext(nBlocks),
			_buff(nullptr), _pHeaderFreed(nullptr) {}
		inline size_t GetBytesBlock() const { return _bytesBlock; }
		void Print() const;
		void *Allocate(const char *ownerName);
		virtual void Free(void *p);
	};
	class ChunkVariable : public Chunk {
	public:
		inline ChunkVariable() {}
		void *Allocate(size_t bytes, const char *ownerName);
		virtual void Free(void *p);
	};
private:
	static MemoryPool _inst;
private:
	ChunkFixed _chunkFixed1;
	ChunkFixed _chunkFixed2;
	ChunkVariable _chunkVariable;
public:
	MemoryPool();
	inline static void *Allocate(size_t bytes, const char *ownerName = "") {
		return _inst.DoAllocate(bytes, ownerName);
	}
	inline static void Free(void *p) { _inst.DoFree(p); }
	inline static void Print() { _inst.DoPrint(); }
private:
	void *DoAllocate(size_t bytes, const char *ownerName);
	void DoFree(void *p);
	void DoPrint() const;
};

}

#endif
