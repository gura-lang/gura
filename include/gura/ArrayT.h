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
	void Fill(const T_Elem &num) {
		T_Elem *p = GetPointer();
		for (size_t i = 0; i < GetCountTotal(); i++, p++) {
			*p = num;
		}
	}
	void FillZero() {
		::memset(GetPointer(), 0x00, sizeof(T_Elem) * GetCountTotal());
	}
	bool Paste(Signal &sig, size_t offset, const ArrayT *pArrayTSrc) {
		if (GetCountTotal() < offset + pArrayTSrc->GetCountTotal()) {
			sig.SetError(ERR_OutOfRangeError, "out of range");
			return false;
		}
		::memcpy(GetPointer() + offset, pArrayTSrc->GetPointer(),
				 sizeof(T_Elem) * pArrayTSrc->GetCountTotal());
		return true;
	}
	void Dump(Signal &sig, Stream &stream, bool upperFlag) const {
	}
	void CopyToList(ValueList &valList) const {
		if (valList.empty()) valList.reserve(GetCountTotal());
		const T_Elem *p = GetPointer();
		for (size_t cnt = GetCountTotal(); cnt > 0; cnt--, p++) {
			valList.push_back(Value(*p));
		}
	}
	T_Elem Sum() const {
		T_Elem rtn = 0;
		const T_Elem *p = GetPointer();
		for (size_t i = 0; i < GetCountTotal(); i++, p++) {
			rtn += *p;
		}
		return rtn;
	}
	T_Elem Average() const {
		if (GetCountTotal() == 0) return 0;
		return Sum() / GetCountTotal();
	}
	// functions to create an ArrayT instance
	static ArrayT *CreateLike(const Array::Dimensions &dims) {
		AutoPtr<ArrayT> pArrayT(new ArrayT());
		pArrayT->SetSize(dims);
		pArrayT->AllocMemory();
		return pArrayT.release();
	}
	static ArrayT *CreateFromList(const ValueList &valList) {
		AutoPtr<ArrayT> pArrayT(new ArrayT(valList.size()));
		T_Elem *p = pArrayT->GetPointer();
		foreach_const (ValueList, pValue, valList) {
			*p++ = static_cast<T_Elem>(pValue->GetNumber());
		}
		return pArrayT.release();
	}
	static ArrayT *CreateFromList(Signal &sig, const ValueList &valList) {
		AutoPtr<ArrayT> pArrayT(new ArrayT(valList.size()));
		T_Elem *p = pArrayT->GetPointer();
		foreach_const (ValueList, pValue, valList) {
			if (!pValue->Is_number() && !pValue->Is_boolean()) {
				sig.SetError(ERR_ValueError, "element must be a number or a boolean");
				return nullptr;
			}
			*p++ = static_cast<T_Elem>(pValue->GetNumber());
		}
		return pArrayT.release();
	}
	static ArrayT *CreateFromIterator(Environment &env, Iterator *pIterator) {
		size_t len = pIterator->GetLengthEx(env);
		if (env.IsSignalled()) return nullptr;
		AutoPtr<ArrayT> pArrayT(new ArrayT(len));
		AutoPtr<Iterator> pIteratorWork(pIterator->Clone());
		T_Elem *p = pArrayT->GetPointer();
		Value value;
		while (pIteratorWork->Next(env, value)) {
			if (!value.Is_number() && !value.Is_boolean()) {
				env.SetError(ERR_ValueError, "element must be a number or a boolean");
				return nullptr;
			}
			*p++ = static_cast<T_Elem>(value.GetNumber());
		}
		return pArrayT.release();
	}
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
	virtual size_t GetLength() const {
		return _pArrayT->GetCountTotal();
	}
	virtual Iterator *GetSource() { return nullptr; }
	virtual bool DoNext(Environment &env, Value &value) {
		if (_idx >= _pArrayT->GetCountTotal()) return false;
		value = Value(*(_pArrayT->GetPointer() + _idx));
		_idx++;
		return true;
	}
	virtual String ToString() const {
		String rtn;
		rtn = "array";
		return rtn;
	}
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet) {
	}
};

}

#endif
