//=============================================================================
// ArrayT
//=============================================================================
#ifndef __GURA_ARRAYT_H__
#define __GURA_ARRAYT_H__

#include "Memory.h"
#include "Iterator.h"
#include "Stream.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ArrayT
//-----------------------------------------------------------------------------
template<typename T_Elem>
class ArrayT {
private:
	int _cntRef;
	AutoPtr<Memory> _pMemory;
	size_t _cnt;
	size_t _offsetBase;
public:
	Gura_DeclareReferenceAccessor(ArrayT);
public:
	inline ArrayT(const ArrayT &src) : _cntRef(1),
		_pMemory(src._pMemory->Reference()), _cnt(src._cnt), _offsetBase(src._offsetBase) {}
	inline ArrayT(size_t cnt, size_t offsetBase = 0) : _cntRef(1),
		_pMemory(new MemoryHeap(sizeof(T_Elem) * cnt)), _cnt(cnt), _offsetBase(offsetBase) {}
	inline ArrayT(Memory *pMemory, size_t cnt, size_t offsetBase = 0) : _cntRef(1),
		_pMemory(pMemory), _cnt(cnt), _offsetBase(offsetBase) {}
	inline Memory &GetMemory() { return *_pMemory; }
	inline const Memory &GetMemory() const { return *_pMemory; }
	inline T_Elem *GetPointer() {
		return reinterpret_cast<T_Elem *>(_pMemory->GetPointer()) + _offsetBase;
	}
	inline const T_Elem *GetPointer() const {
		return reinterpret_cast<T_Elem *>(_pMemory->GetPointer()) + _offsetBase;
	}
	inline size_t GetSize() const { return _cnt; }
	inline size_t GetOffsetBase() const { return _offsetBase; }
	inline operator T_Elem *() { return GetPointer(); }
	inline operator const T_Elem *() const { return GetPointer(); }
	void Fill(const T_Elem &num) {
		T_Elem *p = GetPointer();
		for (size_t i = 0; i < _cnt; i++, p++) {
			*p = num;
		}
	}
	void FillZero() {
		::memset(GetPointer(), 0x00, sizeof(T_Elem) * GetSize());
	}
	bool Paste(Signal &sig, size_t offset, const ArrayT *pArrayTSrc) {
		if (GetSize() < offset + pArrayTSrc->GetSize()) {
			sig.SetError(ERR_OutOfRangeError, "out of range");
			return false;
		}
		::memcpy(GetPointer() + offset, pArrayTSrc->GetPointer(),
				 sizeof(T_Elem) * pArrayTSrc->GetSize());
		return true;
	}
	void Dump(Signal &sig, Stream &stream, bool upperFlag) const {
	}
	void CopyToList(ValueList &valList) const {
		if (valList.empty()) valList.reserve(_cnt);
		const T_Elem *p = GetPointer();
		for (size_t cnt = _cnt; cnt > 0; cnt--, p++) {
			valList.push_back(Value(*p));
		}
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
		Signal &sig = env.GetSignal();
		ValueList valList;
		Value value;
		while (pIterator->Next(env, value)) valList.push_back(value);
		if (sig.IsSignalled()) return nullptr;
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
private:
	inline ~ArrayT() {}
};

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
// Iterator_ArrayT
//-----------------------------------------------------------------------------
template<typename T_Elem>
class Iterator_ArrayT : public Iterator {
private:
	AutoPtr<ArrayT<T_Elem> > _pArrayT;
	size_t _idx;
public:
	inline Iterator_ArrayT(ArrayT<T_Elem> *pArrayT) :
		Iterator(Finite), _pArrayT(pArrayT), _idx(0) {} // must be revised later
	virtual Iterator *GetSource() { return nullptr; }
	virtual bool DoNext(Environment &env, Value &value) {
		if (_idx >= _pArrayT->GetSize()) return false;
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
