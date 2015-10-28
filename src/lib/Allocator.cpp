//=============================================================================
// Allocator
//=============================================================================
#include "stdafx.h"

//-----------------------------------------------------------------------------
// Overload of new/delete operator
//-----------------------------------------------------------------------------
#if 0
void *operator new(size_t size)
{
	//::printf("new: %ld bytes\n", size);
	return Gura::Allocator::Allocate(size);
}

void operator delete(void *pv) noexcept
{
	Gura::Allocator::Free(pv);
}
#endif

namespace Gura {

//-----------------------------------------------------------------------------
// Allocator
//-----------------------------------------------------------------------------
Allocator Allocator::_inst;

Allocator::Allocator() :
	_chunkFixed1(128, 10000), _chunkFixed2(256, 10000), _chunkVariable()
{
}

void *Allocator::DoAllocate(size_t bytes)
{
#if 1
	if (bytes <= _chunkFixed1.GetBytesBlock()) {
		return _chunkFixed1.Allocate();
	} else if (bytes <= _chunkFixed2.GetBytesBlock()) {
		return _chunkFixed2.Allocate();
	} else {
		return _chunkVariable.Allocate(bytes);
	}
#else
	return _chunkVariable.Allocate(bytes);
#endif
}

void Allocator::DoFree(void *p)
{
	char *pRaw = reinterpret_cast<char *>(p) - sizeof(Chunk *);
	Chunk *pChunk = *reinterpret_cast<Chunk **>(pRaw);
	pChunk->Free(p);
}

//-----------------------------------------------------------------------------
// Allocator::ChunkFixed
//-----------------------------------------------------------------------------
void *Allocator::ChunkFixed::Allocate()
{
	Frame *pFrame = nullptr;
	if (_pFrameFreed == nullptr) {
		size_t bytesFrame = sizeof(Frame) + _bytesBlock - 1;
		if (_iBlockNext >= _nBlocks) {
			_iBlockNext = 0;
			_buff = reinterpret_cast<char *>(::malloc(bytesFrame * _nBlocks));
		}
		pFrame = reinterpret_cast<Frame *>(_buff + bytesFrame * _iBlockNext);
		_iBlockNext++;
	} else {
		pFrame = _pFrameFreed;
		_pFrameFreed = pFrame->u.pFrameNext;
	}
	pFrame->u.pChunk = this;
	return pFrame->buff;
}

void Allocator::ChunkFixed::Free(void *p)
{
	char *pRaw = reinterpret_cast<char *>(p) - sizeof(Chunk *);
	Frame *pFrame = reinterpret_cast<Frame *>(pRaw);
	pFrame->u.pFrameNext = _pFrameFreed;
	_pFrameFreed = pFrame;
}

//-----------------------------------------------------------------------------
// Allocator::ChunkVariable
//-----------------------------------------------------------------------------
void *Allocator::ChunkVariable::Allocate(size_t bytes)
{
	size_t bytesFrame = sizeof(Frame) + bytes - 1;
	Frame *pFrame = reinterpret_cast<Frame *>(::malloc(bytesFrame));
	if (pFrame == nullptr) return nullptr;
	pFrame->u.pChunk = this;
	return pFrame->buff;
}

void Allocator::ChunkVariable::Free(void *p)
{
	char *pRaw = reinterpret_cast<char *>(p) - sizeof(Chunk *);
	::free(pRaw);
}

}
