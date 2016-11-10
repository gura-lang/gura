//=============================================================================
// ArrayT
//=============================================================================
#ifndef __GURA_ARRAYT_H__
#define __GURA_ARRAYT_H__

#include "Array.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ArrayT
//-----------------------------------------------------------------------------
template<typename T_Elem>
class ArrayT : public Array {
public:
	Gura_DeclareReferenceAccessor(ArrayT);
public:
	inline ArrayT() {}
	inline ArrayT(const ArrayT &src) : Array(src) {}
	inline ArrayT(Memory *pMemory) : Array(pMemory) {}
	inline ArrayT(size_t cnt) {
		SetSize1D(cnt);
		AllocMemory();
	}
	inline void AllocMemory() {
		_pMemory.reset(new MemoryHeap(sizeof(T_Elem) * GetCountTotal()));
	}
	inline T_Elem *GetPointer() {
		return reinterpret_cast<T_Elem *>(_pMemory->GetPointer()) + GetOffsetBase();
	}
	inline const T_Elem *GetPointer() const {
		return reinterpret_cast<T_Elem *>(_pMemory->GetPointer()) + GetOffsetBase();
	}
	inline operator T_Elem *() { return GetPointer(); }
	inline operator const T_Elem *() const { return GetPointer(); }
	void Fill(const T_Elem &num);
	void FillZero();
	bool Paste(Signal &sig, size_t offset, const ArrayT *pArrayTSrc);
	void Dump(Signal &sig, Stream &stream, bool upperFlag) const;
	void CopyToList(ValueList &valList) const;
	T_Elem Sum() const;
	T_Elem Average() const;
	// functions to create an ArrayT instance
	static ArrayT *CreateLike(const Array::Dimensions &dims);
	static ArrayT *CreateFromList(const ValueList &valList);
	static ArrayT *CreateFromList(Signal &sig, const ValueList &valList);
	static ArrayT *CreateFromIterator(Environment &env, Iterator *pIterator);
private:
	inline ~ArrayT() {}
};

//-----------------------------------------------------------------------------
// Iterator_ArrayT_Each
//-----------------------------------------------------------------------------
template<typename T_Elem>
class Iterator_ArrayT_Each : public Iterator {
private:
	AutoPtr<ArrayT<T_Elem> > _pArrayT;
	size_t _idx;
public:
	inline Iterator_ArrayT_Each(ArrayT<T_Elem> *pArrayT) :
		Iterator(FinitePredictable), _pArrayT(pArrayT), _idx(0) {}
	virtual size_t GetLength() const;
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

}

#endif
