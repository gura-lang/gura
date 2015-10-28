//=============================================================================
// Allocator
//=============================================================================
#ifndef __GURA_ALLOCATOR_H__
#define __GURA_ALLOCATOR_H__
#include "Common.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Allocator
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Allocator {
public:
	class Chunk {
	public:
		virtual void Free(void *p) = 0;
	};
	struct Frame {
		union {
			Chunk *pChunk;
			Frame *pFrameNext;
		} u;
		char buff[1];
	};
	class ChunkFixed : public Chunk {
	private:
		size_t _bytesBlock;
		size_t _nBlocks;
		size_t _iBlockNext;
		char *_buff;
		Frame *_pFrameFreed;
	public:
		inline ChunkFixed(size_t bytesBlock, size_t nBlocks) :
			_bytesBlock(bytesBlock), _nBlocks(nBlocks), _iBlockNext(nBlocks),
			_buff(nullptr), _pFrameFreed(nullptr) {}
		inline size_t GetBytesBlock() const { return _bytesBlock; }
		void *Allocate();
		virtual void Free(void *p);
	};
	class ChunkVariable : public Chunk {
	public:
		inline ChunkVariable() {}
		void *Allocate(size_t bytes);
		virtual void Free(void *p);
	};
private:
	static Allocator _inst;
private:
	ChunkFixed _chunkFixed1;
	ChunkFixed _chunkFixed2;
	ChunkVariable _chunkVariable;
public:
	Allocator();
	inline static void *Allocate(size_t bytes) { return _inst.DoAllocate(bytes); }
	inline static void Free(void *p) { _inst.DoFree(p); }
private:
	void *DoAllocate(size_t bytes);
	void DoFree(void *p);
};

}

#endif
