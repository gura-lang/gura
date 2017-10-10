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
class GURA_DLLDECLARE ArrayT : public Array {
public:
	Gura_DeclareReferenceAccessor(ArrayT);
public:
	static ValueType ValueTypeElem;
	static ElemType ElemTypeThis;
	static size_t ElemBytes;
	static const char *ElemTypeName;
	static const char *ConstructorName;
public:
	inline ArrayT(const ArrayT &src) : Array(src) {}
	ArrayT(bool colMajorFlag);
	ArrayT(bool colMajorFlag, Memory *pMemory, size_t offsetBase);
	inline void AllocMemory() {
		_pMemory.reset(new MemoryHeap(sizeof(T_Elem) * GetElemNum()));
	}
	inline T_Elem *GetPointerOrigin() {
		return reinterpret_cast<T_Elem *>(_pMemory->GetPointer());
	}
	inline const T_Elem *GetPointerOrigin() const {
		return reinterpret_cast<T_Elem *>(_pMemory->GetPointer());
	}
	inline T_Elem *GetPointer() { return GetPointerOrigin() + GetOffsetBase(); }
	inline const T_Elem *GetPointer() const { return GetPointerOrigin() + GetOffsetBase(); }
	inline operator T_Elem *() { return GetPointer(); }
	inline operator const T_Elem *() const { return GetPointer(); }
	virtual Array *Clone() const;
	virtual String ToString(bool exprFlag) const;
	virtual bool DoesContainZero() const;
	virtual bool DoesContainMinus() const;
	virtual bool DoesContainZeroOrMinus() const;
	virtual Double GetScalarNumber() const;
	virtual Complex GetScalarComplex() const;
	void SetScalar(const T_Elem &num);
	void Fill(const T_Elem &num);
	void FillRand();
	void FillRandRange(UInt range);
	void FillRandNormal(double mu, double sigma);
	bool Paste(Signal &sig, size_t offset, const ArrayT *pArrayTSrc);
	void CopyToList(Object_list *pObjList) const;
	ArrayT *Flatten() const;
	ArrayT *Reshape(Signal &sig, const ValueList &valList) const;
	ArrayT *Transpose(Signal &sig, const ValueList &valList, Array *pArrayRtn) const;
	ArrayT *Transpose(const SizeTList &axes, Array *pArrayRtn) const;
	ArrayT *Head(Signal &sig, size_t n) const;
	ArrayT *Tail(Signal &sig, size_t n) const;
	ArrayT *Offset(Signal &sig, size_t n) const;
	ArrayT *RoundOff(double threshold) const;
	ArrayT *Im2col(size_t htKernel, size_t wdKernel, size_t strides, size_t padding) const;
	ArrayT *Col2im(size_t htKernel, size_t wdKernel, size_t strides, size_t padding) const;
	// functions to create an ArrayT instance
	static ArrayT *Create(bool colMajorFlag, const Dimensions &dims);
	static ArrayT *Create(bool colMajorFlag, Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd);
	static ArrayT *Create(bool colMajorFlag, size_t size,
						  Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd);
	static ArrayT *Create(bool colMajorFlag, Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd,
						  size_t size);
	static ArrayT *Create(bool colMajorFlag, Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd,
						  size_t sizeRow, size_t sizeCol);
	static ArrayT *Create(bool colMajorFlag, Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd,
						  size_t sizePlane, size_t sizeRow, size_t sizeCol);
	static ArrayT *Create(bool colMajorFlag, Dimensions::const_iterator pDim1, Dimensions::const_iterator pDim1End,
						  Dimensions::const_iterator pDim2, Dimensions::const_iterator pDim2End);
	static ArrayT *Create1d(bool colMajorFlag, size_t size);
	static ArrayT *Create2d(bool colMajorFlag, size_t sizeRow, size_t sizeCol);
	static ArrayT *Create3d(bool colMajorFlag, size_t sizePlane, size_t sizeRow, size_t sizeCol);
	static ArrayT *CreateScalar(const T_Elem &num);
	static ArrayT *CreateFromValue(Environment &env, bool colMajorFlag, const Value &value);
	static ArrayT *CreateFromList(bool colMajorFlag, const ValueList &valList);
	static ArrayT *CreateFromList(Environment &env, bool colMajorFlag, const ValueList &valList);
	static ArrayT *CreateFromIterator(Environment &env, bool colMajorFlag, Iterator *pIterator);
	static ArrayT *CreateFromExpr(Environment &env, bool colMajorFlag, const Expr *pExpr);
private:
	inline ~ArrayT() {}
};

template<typename T_Elem>
void FillDouble(T_Elem *pElem, size_t nElems, Double num, size_t strides)
{
	T_Elem numCasted = static_cast<T_Elem>(num);
	for (size_t i = 0; i < nElems; i++, pElem += strides) *pElem = numCasted;
}

template<typename T_Elem>
void FillComplex(T_Elem *pElem, size_t nElems, const Complex &num, size_t strides) {}

template<>
void FillComplex(Complex *pElem, size_t nElems, const Complex &num, size_t strides);

template<typename T_Elem>
inline bool StoreValueAt(Environment &env, T_Elem *pElem, const Value &value)
{
	if (value.Is_number() || value.Is_boolean()) {
		*pElem = static_cast<T_Elem>(value.GetDouble());
	} else {
		Array::SetError_UnacceptableValueAsElement(env, value);
		return false;
	}
	return true;
}

template<>
inline bool StoreValueAt(Environment &env, Complex *pElem, const Value &value)
{
	if (value.Is_number() || value.Is_boolean()) {
		*pElem = static_cast<Complex>(value.GetDouble());
	} else if (value.Is_complex()) {
		*pElem = value.GetComplex();
	} else {
		Array::SetError_UnacceptableValueAsElement(env, value);
		return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Iterator_ArrayT_Each
//-----------------------------------------------------------------------------
template<typename T_Elem>
class GURA_DLLDECLARE Iterator_ArrayT_Each : public Iterator {
private:
	AutoPtr<ArrayT<T_Elem> > _pArrayT;
	bool _flatFlag;
	size_t _idx;
public:
	inline Iterator_ArrayT_Each(ArrayT<T_Elem> *pArrayT, bool flatFlag) :
		Iterator(FinitePredictable), _pArrayT(pArrayT), _flatFlag(flatFlag), _idx(0) {}
	virtual size_t GetLength() const;
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

}

#endif
