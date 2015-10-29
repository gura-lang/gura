//=============================================================================
// MemoryPool
//=============================================================================
#include "stdafx.h"

//-----------------------------------------------------------------------------
// Overload of new/delete operator
//-----------------------------------------------------------------------------
#if 0
void *operator new(size_t size)
{
	//::printf("new: %ld bytes\n", size);
	return Gura::MemoryPool::Allocate(size);
}

void operator delete(void *pv) noexcept
{
	Gura::MemoryPool::Free(pv);
}
#endif

namespace Gura {

//-----------------------------------------------------------------------------
// MemoryPool
//-----------------------------------------------------------------------------
MemoryPool MemoryPool::_inst;

MemoryPool::MemoryPool() :
	_chunkFixed1(128, 10000), _chunkFixed2(256, 10000), _chunkVariable()
{
}

void *MemoryPool::DoAllocate(size_t bytes, const char *ownerName)
{
#if 1
	if (bytes <= _chunkFixed1.GetBytesBlock()) {
		return _chunkFixed1.Allocate(ownerName);
	} else if (bytes <= _chunkFixed2.GetBytesBlock()) {
		return _chunkFixed2.Allocate(ownerName);
	} else {
		return _chunkVariable.Allocate(bytes, ownerName);
	}
#else
	return _chunkVariable.Allocate(bytes, ownerName);
#endif
}

void MemoryPool::DoFree(void *p)
{
	char *pRaw = reinterpret_cast<char *>(p) - sizeof(Header);
	Chunk *pChunk = *reinterpret_cast<Chunk **>(pRaw);
	pChunk->Free(p);
}

void MemoryPool::DoPrint() const
{
	_chunkFixed1.Print();
	_chunkFixed2.Print();
}

//-----------------------------------------------------------------------------
// MemoryPool::ChunkFixed
//-----------------------------------------------------------------------------
void *MemoryPool::ChunkFixed::Allocate(const char *ownerName)
{
	char *pRaw = nullptr;
	if (_pHeaderFreed == nullptr) {
		size_t bytesFrame = sizeof(Header) + _bytesBlock;
		if (_iBlockNext >= _nBlocks) {
			_iBlockNext = 0;
			_buff = reinterpret_cast<char *>(::malloc(bytesFrame * _nBlocks));
		}
		pRaw = _buff + bytesFrame * _iBlockNext;
		_iBlockNext++;
	} else {
		pRaw = reinterpret_cast<char *>(_pHeaderFreed);
		_pHeaderFreed = _pHeaderFreed->u.pHeaderNext;
	}
	Header *pHeader = reinterpret_cast<Header *>(pRaw);
	pHeader->u.pChunk = this;
	pHeader->ownerName = ownerName;
	return pRaw + sizeof(Header);
}

void MemoryPool::ChunkFixed::Free(void *p)
{
	char *pRaw = reinterpret_cast<char *>(p) - sizeof(Header);
	Header *pHeader = reinterpret_cast<Header *>(pRaw);
	pHeader->u.pHeaderNext = _pHeaderFreed;
	pHeader->ownerName = nullptr;
	_pHeaderFreed = pHeader;
}

void MemoryPool::ChunkFixed::Print() const
{
	::printf("[ChunkFixed:%ldbytes/block]\n", _bytesBlock);
	if (_buff == nullptr) return;
	size_t bytesFrame = sizeof(Header) + _bytesBlock;
	const char *pRaw = _buff;
	for (size_t iBlock = 0; iBlock < _iBlockNext; iBlock++, pRaw += bytesFrame) {
		const Header *pHeader = reinterpret_cast<const Header *>(pRaw);
		::printf("%c", (pHeader->ownerName == nullptr)? '*' : '.');
	}
	::printf("\n");
}

//-----------------------------------------------------------------------------
// MemoryPool::ChunkVariable
//-----------------------------------------------------------------------------
void *MemoryPool::ChunkVariable::Allocate(size_t bytes, const char *ownerName)
{
	size_t bytesFrame = sizeof(Header) + bytes;
	char *pRaw = reinterpret_cast<char *>(::malloc(bytesFrame));
	if (pRaw == nullptr) return nullptr;
	Header *pHeader = reinterpret_cast<Header *>(pRaw);
	pHeader->u.pChunk = this;
	pHeader->ownerName = ownerName;
	return pRaw + sizeof(Header);
}

void MemoryPool::ChunkVariable::Free(void *p)
{
	char *pRaw = reinterpret_cast<char *>(p) - sizeof(Header);
	::free(pRaw);
}

}
