//=============================================================================
// MemoryPool
//=============================================================================
#include "stdafx.h"

//-----------------------------------------------------------------------------
// Overload of new/delete operator
//-----------------------------------------------------------------------------
#if 1
void *operator new(size_t size)
{
	//::printf("new: %ld bytes\n", size);
	return Gura::MemoryPool::Allocate(size);
}

void operator delete(void *pv) noexcept
{
	Gura::MemoryPool::Deallocate(pv);
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

void MemoryPool::DoDeallocate(void *p)
{
	char *pHeaderRaw = reinterpret_cast<char *>(p) - sizeof(Header);
	Header *pHeader = reinterpret_cast<Header *>(pHeaderRaw);
	pHeader->u.pChunk->Deallocate(p);
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
	char *pHeaderRaw = nullptr;
	if (_pHeaderVacantHead == nullptr) {
		size_t bytesFrame = sizeof(Header) + _bytesBlock;
		if (_iBlockNext >= _nBlocks) {
			_iBlockNext = 0;
			Pool *pPool = reinterpret_cast<Pool *>(
				::malloc(sizeof(Pool) + bytesFrame * _nBlocks - 1));
			pPool->pPoolPrev = _pPool;
			_pPool = pPool;
		}
		pHeaderRaw = _pPool->buff + bytesFrame * _iBlockNext;
		_iBlockNext++;
	} else {
		pHeaderRaw = reinterpret_cast<char *>(_pHeaderVacantHead);
		_pHeaderVacantHead = _pHeaderVacantHead->u.pHeaderVacantNext;
	}
	Header *pHeader = reinterpret_cast<Header *>(pHeaderRaw);
	pHeader->u.pChunk = this;
	pHeader->ownerName = ownerName;
	return pHeaderRaw + sizeof(Header);
}

void MemoryPool::ChunkFixed::Deallocate(void *p)
{
	char *pHeaderRaw = reinterpret_cast<char *>(p) - sizeof(Header);
	Header *pHeader = reinterpret_cast<Header *>(pHeaderRaw);
	pHeader->u.pHeaderVacantNext = _pHeaderVacantHead;
	pHeader->ownerName = nullptr;
	_pHeaderVacantHead = pHeader;
}

void MemoryPool::ChunkFixed::Print() const
{
	::printf("[ChunkFixed:%ldbytes/block]\n", _bytesBlock);
	size_t bytesFrame = sizeof(Header) + _bytesBlock;
	for (const Pool *pPool = _pPool; pPool != nullptr; pPool = pPool->pPoolPrev) {
		const char *pHeaderRaw = pPool->buff;
		for (size_t iBlock = 0; iBlock < _iBlockNext; iBlock++, pHeaderRaw += bytesFrame) {
			const Header *pHeader = reinterpret_cast<const Header *>(pHeaderRaw);
			::printf("%c", (pHeader->ownerName == nullptr)? '*' : '.');
		}
	}
	::printf("\n");
}

//-----------------------------------------------------------------------------
// MemoryPool::ChunkVariable
//-----------------------------------------------------------------------------
void *MemoryPool::ChunkVariable::Allocate(size_t bytes, const char *ownerName)
{
	size_t bytesFrame = sizeof(Header) + bytes;
	char *pHeaderRaw = reinterpret_cast<char *>(::malloc(bytesFrame));
	if (pHeaderRaw == nullptr) return nullptr;
	Header *pHeader = reinterpret_cast<Header *>(pHeaderRaw);
	pHeader->u.pChunk = this;
	pHeader->ownerName = ownerName;
	return pHeaderRaw + sizeof(Header);
}

void MemoryPool::ChunkVariable::Deallocate(void *p)
{
	char *pHeaderRaw = reinterpret_cast<char *>(p) - sizeof(Header);
	::free(pHeaderRaw);
}

}
