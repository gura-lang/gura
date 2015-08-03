//=============================================================================
// Matrix
//=============================================================================
#ifndef __GURA_MATRIX_H__
#define __GURA_MATRIX_H__

#include "Common.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Matrix
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Matrix {
public:
	class Elements {
	private:
		int _cntRef;
		ValueList _valList;
	public:
		Gura_DeclareReferenceAccessor(Elements);
	public:
		inline Elements() : _cntRef(1) {}
		inline Elements(const Elements &elements) :
							_cntRef(1), _valList(elements._valList) {}
	private:
		inline ~Elements() {}
	public:
		inline ValueList &GetList() { return _valList; }
		inline const ValueList &GetList() const { return _valList; }
	};
	class IteratorEach : public Iterator {
	private:
		AutoPtr<Matrix> _pMat;
		size_t _iRow, _iCol;
		bool _transposeFlag;
	public:
		inline IteratorEach(Matrix *pMat, bool transposeFlag) :
							Iterator(false), _pMat(pMat),
							_iRow(0), _iCol(0), _transposeFlag(transposeFlag) {}
		virtual ~IteratorEach();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorEachRow : public Iterator {
	private:
		AutoPtr<Matrix> _pMat;
		size_t _iRow;
	public:
		inline IteratorEachRow(Matrix *pMat) :
							Iterator(false), _pMat(pMat), _iRow(0) {}
		virtual ~IteratorEachRow();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorEachCol : public Iterator {
	private:
		AutoPtr<Matrix> _pMat;
		size_t _iCol;
	public:
		inline IteratorEachCol(Matrix *pMat) :
							Iterator(false), _pMat(pMat), _iCol(0) {}
		virtual ~IteratorEachCol();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
private:
	int _cntRef;
	AutoPtr<Elements> _pElements;
	size_t _iRowOff, _iColOff;
	size_t _nRows, _nCols;
	size_t _nFold;
	bool _indexForColFlag;
public:
	Gura_DeclareReferenceAccessor(Matrix);
public:
	Matrix(const Matrix &matrix);
	Matrix(size_t nRows, size_t nCols);
	Matrix(size_t nRows, size_t nCols, const Value &valueElem);
	Matrix(Elements *pElements,
			size_t iRowOff, size_t iColOff, size_t nRows, size_t nCols,
			size_t nFold, bool indexForColFlag);
	static Matrix *CreateIdentity(int n);
	static Matrix *CreateRotation(double rad,
				bool transFlag, double xTrans, double yTrans);
	static Matrix *CreateRotationX(double rad,
				bool transFlag, double xTrans, double yTrans, double zTrans);
	static Matrix *CreateRotationY(double rad,
				bool transFlag, double xTrans, double yTrans, double zTrans);
	static Matrix *CreateRotationZ(double rad,
				bool transFlag, double xTrans, double yTrans, double zTrans);
	void ToList(Environment &env, ValueList &valList, bool transposeFlag, bool flattenFlag);
	inline void SetRowOff(size_t iRowOff) { _iRowOff = iRowOff; }
	inline void SetColOff(size_t iColOff) { _iColOff = iColOff; }
	inline void SetRows(size_t nRows) { _nRows = nRows; }
	inline void SetCols(size_t nCols) { _nCols = nCols; }
	inline void SetFold(size_t nFold) { _nFold = nFold; }
	inline void SetIndexForColFlag(bool indexForColFlag) { _indexForColFlag = indexForColFlag; }
	inline size_t GetRowOff() const { return _iRowOff; }
	inline size_t GetColOff() const { return _iColOff; }
	inline size_t GetRows() const { return _nRows; }
	inline size_t GetCols() const { return _nCols; }
	inline size_t GetFold() const { return _nFold; }
	inline bool GetIndexForColFlag() const { return _indexForColFlag; }
	inline Elements *GetElements() { return _pElements.get(); }
	inline const Elements *GetElements() const { return _pElements.get(); }
	inline ValueList &GetList() { return _pElements->GetList(); }
	inline const ValueList &GetList() const { return _pElements->GetList(); }
	inline ValueList::iterator GetPointer(size_t iRow, size_t iCol) {
		return GetList().begin() + _iColOff + iCol + (_iRowOff + iRow) * _nFold;
	}
	inline ValueList::const_iterator GetPointer(size_t iRow, size_t iCol) const {
		return GetList().begin() + _iColOff + iCol + (_iRowOff + iRow) * _nFold;
	}
	inline const Value &GetElement(size_t iRow, size_t iCol) const {
		return *GetPointer(iRow, iCol);
	}
	inline void SetElement(size_t iRow, size_t iCol, const Value &value) {
		*GetPointer(iRow, iCol) = value;
	}
	Value GetSub(Environment &env, size_t iRow, size_t iCol, size_t nRows, size_t nCols);
	bool Set(Environment &env, Iterator &iterator);
	bool SetRow(Environment &env, size_t iRow, Iterator &iterator);
	bool SetCol(Environment &env, size_t iCol, Iterator &iterator);
	Value GetRow(Environment &env, size_t iRow) const;
	Value GetCol(Environment &env, size_t iCol) const;
	Value RoundOff(Environment &env, Number threshold);
	Value Transpose(Environment &env);
	Value Invert(Environment &env);
	static Value Neg(Environment &env, const Matrix *pMat);
	static Value AddSub(Environment &env, OpType opType, const Matrix *pMat1, const Matrix *pMat2);
	static Value Mul(Environment &env, const Matrix *pMat1, const Matrix *pMat2);
	static Value Mul(Environment &env, const Matrix *pMat, const ValueList &valList);
	static Value Mul(Environment &env, const Matrix *pMat, const Value &value);
	static Value Mul(Environment &env, const ValueList &valList, const Matrix *pMat);
	static Value Mul(Environment &env, const Value &value, const Matrix *pMat);
	static Value Div(Environment &env, const Matrix *pMat, const Value &value);
	static void SetError_MatrixSizeMismatch(Signal &sig);
	static void SetError_IndexOutOfRange(Signal &sig);
public:
	static ValueType CheckValueType(const ValueList &valList);
	static ValueType CheckValueType(const Matrix &mat);
	static bool GetElemIndex(Environment &env,
		const Expr *pExprIdx, size_t nElemsSrc, size_t &iElem, size_t &nElems);
};

}

#endif
