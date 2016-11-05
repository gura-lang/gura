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
	void AllocMemory() {
		_pMemory.reset(new MemoryHeap(sizeof(T_Elem) * GetCountTotal()));
	}
	void AllocMemory1D(size_t cnt) {
		SetSize1D(cnt);
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
	static ArrayT *CreateFromList(const ValueList &valList) {
		AutoPtr<ArrayT> pArrayT(new ArrayT());
		pArrayT->AllocMemory1D(valList.size());
		T_Elem *p = pArrayT->GetPointer();
		foreach_const (ValueList, pValue, valList) {
			*p++ = static_cast<T_Elem>(pValue->GetNumber());
		}
		return pArrayT.release();
	}
	static ArrayT *CreateFromList(Signal &sig, const ValueList &valList) {
		AutoPtr<ArrayT> pArrayT(new ArrayT());
		pArrayT->AllocMemory1D(valList.size());
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
		AutoPtr<ArrayT> pArrayT(new ArrayT());
		pArrayT->AllocMemory1D(len);
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

template<typename T_ElemResult, typename T_Elem>
bool Neg(Signal &sig, ArrayT<T_ElemResult> &result, const ArrayT<T_Elem> &array)
{
	T_ElemResult *pResult = result.GetPointer();
	const T_Elem *pElem = array.GetPointer();
	size_t cnt = array.GetCountTotal();
	for (size_t i = 0; i < cnt; i++, pResult++, pElem++) {
		*pResult = -*pElem;
	}
	return true;
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
bool Add(Signal &sig, ArrayT<T_ElemResult> &result,
		 const ArrayT<T_ElemL> &arrayL, const ArrayT<T_ElemR> &arrayR)
{
	T_ElemResult *pResult = result.GetPointer();
	const T_ElemL *pElemL = arrayL.GetPointer();
	const T_ElemR *pElemR = arrayR.GetPointer();
	size_t cntL = arrayL.GetCountTotal();
	size_t cntR = arrayR.GetCountTotal();
	if (cntL == cntR) {
		for (size_t i = 0; i < cntL; i++, pResult++, pElemL++, pElemR++) {
			*pResult = static_cast<T_ElemResult>(*pElemL + *pElemR);
		}
	} else if (cntL < cntR) {
		size_t j = 0;
		const T_ElemL *pElemLOrg = pElemL;
		for (size_t i = 0; i < cntR; i++, pResult++, pElemL++, pElemR++) {
			*pResult = static_cast<T_ElemResult>(*pElemL + *pElemR);
			if (++j >= cntL) {
				pElemL = pElemLOrg;
				j = 0;
			}
		}
	} else { // cntL > cntR
		size_t j = 0;
		const T_ElemR *pElemROrg = pElemR;
		for (size_t i = 0; i < cntL; i++, pResult++, pElemL++, pElemR++) {
			*pResult = static_cast<T_ElemResult>(*pElemL + *pElemR);
			if (++j >= cntR) {
				pElemR = pElemROrg;
				j = 0;
			}
		}
	}
	return true;
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
bool Sub(Signal &sig, ArrayT<T_ElemResult> &result,
		 const ArrayT<T_ElemL> &arrayL, const ArrayT<T_ElemR> &arrayR)
{
	T_ElemResult *pResult = result.GetPointer();
	const T_ElemL *pElemL = arrayL.GetPointer();
	const T_ElemR *pElemR = arrayR.GetPointer();
	size_t cnt = arrayL.GetCountTotal();
	for (size_t i = 0; i < cnt; i++, pResult++, pElemL++, pElemR++) {
		*pResult = static_cast<T_ElemResult>(*pElemL - *pElemR);
	}
	return true;
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
bool Mul(Signal &sig, ArrayT<T_ElemResult> &result,
		 const ArrayT<T_ElemL> &arrayL, const ArrayT<T_ElemR> &arrayR)
{
	T_ElemResult *pResult = result.GetPointer();
	const T_ElemL *pElemL = arrayL.GetPointer();
	const T_ElemR *pElemR = arrayR.GetPointer();
	size_t cnt = arrayL.GetCountTotal();
	for (size_t i = 0; i < cnt; i++, pResult++, pElemL++, pElemR++) {
		*pResult = static_cast<T_ElemResult>(*pElemL * *pElemR);
	}
	return true;
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
bool Div(Signal &sig, ArrayT<T_ElemResult> &result,
		 const ArrayT<T_ElemL> &arrayL, const ArrayT<T_ElemR> &arrayR)
{
	T_ElemResult *pResult = result.GetPointer();
	const T_ElemL *pElemL = arrayL.GetPointer();
	const T_ElemR *pElemR = arrayR.GetPointer();
	size_t cnt = arrayL.GetCountTotal();
	for (size_t i = 0; i < cnt; i++, pResult++, pElemL++, pElemR++) {
		if (*pElemR == 0) {
			sig.SetError(ERR_ZeroDivisionError, "divided by zero");
			return false;
		}
		*pResult = static_cast<T_ElemResult>(*pElemL / *pElemR);
	}
	return true;
}

template<> GURA_DLLDECLARE void ArrayT<Char>::Dump(Signal &sig, Stream &stream, bool upperFlag) const;
template<> GURA_DLLDECLARE void ArrayT<UChar>::Dump(Signal &sig, Stream &stream, bool upperFlag) const;
template<> GURA_DLLDECLARE void ArrayT<Short>::Dump(Signal &sig, Stream &stream, bool upperFlag) const;
template<> GURA_DLLDECLARE void ArrayT<UShort>::Dump(Signal &sig, Stream &stream, bool upperFlag) const;
template<> GURA_DLLDECLARE void ArrayT<Int32>::Dump(Signal &sig, Stream &stream, bool upperFlag) const;
template<> GURA_DLLDECLARE void ArrayT<UInt32>::Dump(Signal &sig, Stream &stream, bool upperFlag) const;
template<> GURA_DLLDECLARE void ArrayT<Int64>::Dump(Signal &sig, Stream &stream, bool upperFlag) const;
template<> GURA_DLLDECLARE void ArrayT<UInt64>::Dump(Signal &sig, Stream &stream, bool upperFlag) const;
template<> GURA_DLLDECLARE void ArrayT<float>::Dump(Signal &sig, Stream &stream, bool upperFlag) const;
template<> GURA_DLLDECLARE void ArrayT<double>::Dump(Signal &sig, Stream &stream, bool upperFlag) const;

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
