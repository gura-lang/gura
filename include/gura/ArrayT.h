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
	class GURA_DLLDECLARE KernelScanner_ExpandVec {
	private:
		const Array *_pArraySrc;
		AutoPtr<Array> &_pArrayRtn;
		T_Elem *_pElemDst;
		T_Elem _padNum;
	public:
		KernelScanner_ExpandVec(const Array *pArraySrc, AutoPtr<Array> &pArrayRtn, T_Elem padNum) :
			_pArraySrc(pArraySrc), _pArrayRtn(pArrayRtn), _pElemDst(nullptr), _padNum(padNum) {}
		void Initialize1d(size_t nKernels, size_t sizeKernel);
		void Initialize2d(size_t nKernelsRow, size_t nKernelsCol, size_t sizeKernelRow, size_t sizeKernelCol);
		void Initialize3d(size_t nKernelsPlane, size_t nKernelsRow, size_t nKernelsCol,
						  size_t sizeKernelPlane, size_t sizeKernelRow, size_t sizeKernelCol);
		inline void BeginKernel(T_Elem *pElem) {} // nothing to do
		inline void EndKernel() {} // nothing to do
		inline void DoPadding(size_t n) { while (n-- > 0) *_pElemDst++ = _padNum; }
		inline void DoElement(T_Elem *pElem) { *_pElemDst++ = *pElem; }
	};
	class GURA_DLLDECLARE KernelScanner_ExpandVec_ChLast {
	private:
		const Array *_pArraySrc;
		AutoPtr<Array> &_pArrayRtn;
		T_Elem *_pElemDst;
		T_Elem _padNum;
		size_t _nChannels;
	public:
		KernelScanner_ExpandVec_ChLast(const Array *pArraySrc, AutoPtr<Array> &pArrayRtn, T_Elem padNum) :
			_pArraySrc(pArraySrc), _pArrayRtn(pArrayRtn), _pElemDst(nullptr), _padNum(padNum), _nChannels(0) {}
		void Initialize1d(size_t nKernels, size_t sizeKernel);
		void Initialize2d(size_t nKernelsRow, size_t nKernelsCol,
						  size_t sizeKernelRow, size_t sizeKernelCol);
		void Initialize3d(size_t nKernelsPlane, size_t nKernelsRow, size_t nKernelsCol,
						  size_t sizeKernelPlane, size_t sizeKernelRow, size_t sizeKernelCol);
		inline void BeginKernel(T_Elem *pElem) {} // nothing to do
		inline void EndKernel() {} // nothing to do
		inline void DoPadding(size_t n) {
			n *= _nChannels;
			while (n-- > 0) *_pElemDst++ = _padNum;
		}
		inline void DoElement(T_Elem *pElem) {
			size_t n = _nChannels;
			while (n-- > 0) *_pElemDst++ = *pElem++;
		}
	};
	class GURA_DLLDECLARE KernelScanner_CalcMaxPool {
	private:
		const Array *_pArraySrc;
		AutoPtr<Array> &_pArrayRtn;
		T_Elem *_pElemDst;
		T_Elem _elemMax;
	public:
		KernelScanner_CalcMaxPool(const Array *pArraySrc, AutoPtr<Array> &pArrayRtn) :
			_pArraySrc(pArraySrc), _pArrayRtn(pArrayRtn), _pElemDst(nullptr), _elemMax(0) {}
		void Initialize1d(size_t nKernels, size_t sizeKernel);
		void Initialize2d(size_t nKernelsRow, size_t nKernelsCol, size_t sizeKernelRow, size_t sizeKernelCol);
		void Initialize3d(size_t nKernelsPlane, size_t nKernelsRow, size_t nKernelsCol,
						  size_t sizeKernelPlane, size_t sizeKernelRow, size_t sizeKernelCol);
		inline void BeginKernel(T_Elem *pElem) { _elemMax = *pElem; }
		inline void EndKernel() { *_pElemDst++ = _elemMax; }
		inline void DoPadding(size_t n) {} // nothing to do
		inline void DoElement(T_Elem *pElem) { if (_elemMax < *pElem) _elemMax = *pElem; }
	};
	class GURA_DLLDECLARE KernelScanner_CalcMaxPool_ChLast {
	private:
		const Array *_pArraySrc;
		AutoPtr<Array> &_pArrayRtn;
		T_Elem *_pElemDst;
		std::unique_ptr<T_Elem []> _elemMaxTbl;
		size_t _nChannels;
	public:
		KernelScanner_CalcMaxPool_ChLast(const Array *pArraySrc, AutoPtr<Array> &pArrayRtn) :
			_pArraySrc(pArraySrc), _pArrayRtn(pArrayRtn), _pElemDst(nullptr), _nChannels(0) {}
		void Initialize1d(size_t nKernels, size_t sizeKernel);
		void Initialize2d(size_t nKernelsRow, size_t nKernelsCol,
						  size_t sizeKernelRow, size_t sizeKernelCol);
		void Initialize3d(size_t nKernelsPlane, size_t nKernelsRow, size_t nKernelsCol,
						  size_t sizeKernelPlane, size_t sizeKernelRow, size_t sizeKernelCol);
		inline void BeginKernel(T_Elem *pElem) {
			for (size_t iChannel = 0; iChannel < _nChannels; iChannel++, pElem++) {
				_elemMaxTbl[iChannel] = *pElem;
			}
		}
		inline void EndKernel() {
			for (size_t iChannel = 0; iChannel < _nChannels; iChannel++) {
				*_pElemDst++ = _elemMaxTbl[iChannel];
			}
		}
		inline void DoPadding(size_t n) {} // nothing to do
		inline void DoElement(T_Elem *pElem) {
			for (size_t iChannel = 0; iChannel < _nChannels; iChannel++, pElem++) {
				T_Elem &elemMax = _elemMaxTbl[iChannel];
				if (elemMax < *pElem) elemMax = *pElem;
			}
		}
	};
	class GURA_DLLDECLARE Iterator_Each : public Iterator {
	private:
		AutoPtr<ArrayT> _pArrayT;
		bool _flatFlag;
		size_t _idx;
	public:
		inline Iterator_Each(ArrayT *pArrayT, bool flatFlag) :
			Iterator(FinitePredictable), _pArrayT(pArrayT), _flatFlag(flatFlag), _idx(0) {}
		virtual size_t GetLength() const;
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
public:
	Gura_DeclareReferenceAccessor(ArrayT);
public:
	static ValueType ValueTypeElem;
	static ElemType ElemTypeThis;
	static size_t ElemBytes;
	static const char *ElemTypeName;
	static const char *ConstructorName;
protected:
	inline ArrayT(const ArrayT &src) : Array(src) {}
	ArrayT();
public:
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
	virtual void Dump(Signal &sig, Stream &stream, bool upperFlag) const {};
	virtual bool DoesContainZero() const;
	virtual bool DoesContainMinus() const;
	virtual bool DoesContainZeroOrMinus() const;
	virtual Double GetScalarNumber() const;
	virtual Complex GetScalarComplex() const;
	virtual void CopyToList(Object_list *pObjList) const;
	virtual void FillRand();
	virtual void FillRandRange(UInt range);
	virtual void FillRandNormal(double mu, double sigma);
	void SetScalar(const T_Elem &num);
	virtual void Fill(Double num);
	virtual void RoundOff(AutoPtr<Array> &pArrayRtn, double threshold) const;
	virtual void Flatten(AutoPtr<Array> &pArrayRtn) const;
	virtual bool Transpose(AutoPtr<Array> &pArrayRtn, const SizeTList &axes) const;
	virtual bool FindMax(Signal &sig, AutoPtr<Array> &pArrayRtn, ssize_t axis) const;
	virtual bool FindMin(Signal &sig, AutoPtr<Array> &pArrayRtn, ssize_t axis) const;
	virtual bool FindMaxIndex(Signal &sig, AutoPtr<Array> &pArrayRtn, ssize_t axis, bool lastFlag) const;
	virtual bool FindMinIndex(Signal &sig, AutoPtr<Array> &pArrayRtn, ssize_t axis, bool lastFlag) const;
	virtual bool CalcSum(Signal &sig, AutoPtr<Array> &pArrayRtn, ssize_t axis, bool meanFlag) const;
	virtual bool CalcVar(Signal &sig, AutoPtr<Array> &pArrayRtn, ssize_t axis, bool populationFlag, bool stdFlag) const;
	template<typename T_KernelScanner>
	static void ScanKernel1d(
		ArrayT *pArrayT, const Dimension &dimCol, size_t sizeKernel, size_t stridesKernel, size_t sizePad,
		T_KernelScanner &kernelScanner);
	template<typename T_KernelScanner>
	static void ScanKernel2d(
		ArrayT *pArrayT, const Dimension &dimRow, const Dimension &dimCol,
		size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelRow, size_t stridesKernelCol, size_t sizePadRow, size_t sizePadCol,
		T_KernelScanner &kernelScanner);
	template<typename T_KernelScanner>
	static void ScanKernel3d(
		ArrayT *pArrayT, const Dimension &dimPlane, const Dimension &dimRow, const Dimension &dimCol,
		size_t sizeKernelPlane, size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelPlane, size_t stridesKernelRow, size_t stridesKernelCol,
		size_t sizePadPlane, size_t sizePadRow, size_t sizePadCol,
		T_KernelScanner &kernelScanner);
	virtual void ExpandKernelVec1d(
		AutoPtr<Array> &pArrayRtn, size_t sizeKernel, size_t stridesKernel, size_t sizePad,
		bool chLastFlag, Double padNum) const;
	virtual void ExpandKernelVec2d(
		AutoPtr<Array> &pArrayRtn, size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelRow, size_t stridesKernelCol, size_t sizePadRow, size_t sizePadCol,
		bool chLastFlag, Double padNum) const;
	virtual void ExpandKernelVec3d(
		AutoPtr<Array> &pArrayRtn, size_t sizeKernelPlane, size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelPlane, size_t stridesKernelRow, size_t stridesKernelCol,
		size_t sizePadPlane, size_t sizePadRow, size_t sizePadCol,
		bool chLastFlag, Double padNum) const;
	virtual void StoreKernelVec1d(
		const Array *pArrayRtn, size_t sizeKernel, size_t stridesKernel, size_t sizePad);
	virtual void StoreKernelVec2d(
		const Array *pArrayRtn, size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelRow, size_t stridesKernelCol, size_t sizePadRow, size_t sizePadCol);
	virtual void StoreKernelVec3d(
		const Array *pArrayRtn, size_t sizeKernelPlane, size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelPlane, size_t stridesKernelRow, size_t stridesKernelCol,
		size_t sizePadPlane, size_t sizePadRow, size_t sizePadCol);
	virtual void CalcMaxPool1d(
		AutoPtr<Array> &pArrayRtn, size_t sizeKernel, size_t stridesKernel,
		size_t sizePad, bool chLastFlag) const;
	virtual void CalcMaxPool2d(
		AutoPtr<Array> &pArrayRtn, size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelRow, size_t stridesKernelCol,
		size_t sizePadRow, size_t sizePadCol, bool chLastFlag) const;
	virtual void CalcMaxPool3d(
		AutoPtr<Array> &pArrayRtn, size_t sizeKernelPlane, size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelPlane, size_t stridesKernelRow, size_t stridesKernelCol,
		size_t sizePadPlane, size_t sizePadRow, size_t sizePadCol, bool chLastFlag) const;
	virtual Iterator *CreateIteratorEach(bool flatFlag) const;
	// functions to create an ArrayT instance
	static ArrayT *Create();
	static ArrayT *Create(const Dimensions &dims);
	static ArrayT *Create1d(size_t size);
	static ArrayT *Create2d(size_t sizeRow, size_t sizeCol);
	static ArrayT *Create3d(size_t sizePlane, size_t sizeRow, size_t sizeCol);
	static ArrayT *CreateScalar(const T_Elem &num);
	static ArrayT *CreateFromValue(Environment &env, const Value &value);
	static ArrayT *CreateFromList(const ValueList &valList);
	static ArrayT *CreateFromList(Environment &env, const ValueList &valList);
	static ArrayT *CreateFromIterator(Environment &env, Iterator *pIterator);
	static ArrayT *CreateFromExpr(Environment &env, const Expr *pExpr);
	// utilities
	static void FillDouble(T_Elem *pElem, size_t nElems, Double num, size_t strides);
	static void FillComplex(T_Elem *pElem, size_t nElems, const Complex &num, size_t strides) {}
	static bool StoreValueAt(Environment &env, T_Elem *pElem, const Value &value);
private:
	inline ~ArrayT() {}
};

}

#endif
