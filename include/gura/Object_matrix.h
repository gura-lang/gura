#ifndef __GURA_OBJECT_MATRIX_H__
#define __GURA_OBJECT_MATRIX_H__

#include "Object_list.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_matrix
//-----------------------------------------------------------------------------
class DLLDECLARE Class_matrix : public Class {
public:
	Class_matrix(Environment *pEnvOuter);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void OnModuleEntry(Environment &env, Signal sig);
};

//-----------------------------------------------------------------------------
// Object_matrix
//-----------------------------------------------------------------------------
class DLLDECLARE Object_matrix : public Object {
public:
	class IteratorEach : public Iterator {
	private:
		AutoPtr<Object_matrix> _pObj;
		size_t _iRow, _iCol;
		bool _transposeFlag;
	public:
		inline IteratorEach(Object_matrix *pObj, bool transposeFlag) :
							Iterator(false), _pObj(pObj),
							_iRow(0), _iCol(0), _transposeFlag(transposeFlag) {}
		virtual ~IteratorEach();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorEachRow : public Iterator {
	private:
		AutoPtr<Object_matrix> _pObj;
		size_t _iRow;
	public:
		inline IteratorEachRow(Object_matrix *pObj) :
							Iterator(false), _pObj(pObj), _iRow(0) {}
		virtual ~IteratorEachRow();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorEachCol : public Iterator {
	private:
		AutoPtr<Object_matrix> _pObj;
		size_t _iCol;
	public:
		inline IteratorEachCol(Object_matrix *pObj) :
							Iterator(false), _pObj(pObj), _iCol(0) {}
		virtual ~IteratorEachCol();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
private:
	AutoPtr<Object_list> _pObjList;
	size_t _iRowOff, _iColOff;
	size_t _nRows, _nCols;
	size_t _nFold;
	bool _indexForColFlag;
public:
	Gura_DeclareObjectAccessor(matrix)
public:
	Object_matrix(Environment &env, size_t nRows, size_t nCols);
	Object_matrix(Environment &env, size_t nRows, size_t nCols, const Value &valueElem);
	Object_matrix(Environment &env, Object_list *pObjList,
				size_t iRowOff, size_t iColOff, size_t nRows, size_t nCols,
				size_t nFold, bool indexForColFlag);
	Object_matrix(const Object_matrix &obj);
	virtual ~Object_matrix();
	//virtual bool IsMatrix() const;
	virtual Object *Clone() const;
	virtual Value EmptyIndexGet(Environment &env, Signal sig);
	virtual Value IndexGet(Environment &env, Signal sig, const Value &valueIdx);
	virtual void IndexSet(Environment &env, Signal sig, const Value &valueIdx, const Value &value);
	virtual String ToString(Signal sig, bool exprFlag);
	void ToList(ValueList &valList, bool transposeFlag, bool flattenFlag);
	inline size_t RowSize() const { return _nRows; }
	inline size_t ColSize() const { return _nCols; }
	inline size_t FoldSize() const { return _nFold; }
	inline ValueList &GetList() { return _pObjList->GetList(); }
	inline const ValueList &GetList() const { return _pObjList->GetList(); }
	inline ValueList::iterator GetPointer(size_t iRow, size_t iCol) {
		return GetList().begin() + _iColOff + iCol + (_iRowOff + iRow) * _nFold;
	}
	inline ValueList::const_iterator GetPointer(size_t iRow, size_t iCol) const {
		return GetList().begin() + _iColOff + iCol + (_iRowOff + iRow) * _nFold;
	}
	inline const Value &GetElement(size_t iRow, size_t iCol) {
		return *GetPointer(iRow, iCol);
	}
	inline void SetElement(size_t iRow, size_t iCol, const Value &value) {
		*GetPointer(iRow, iCol) = value;
	}
	Value GetSub(size_t iRow, size_t iCol, size_t nRows, size_t nCols);
	bool Set(Environment &env, Signal sig, Iterator &iterator);
	bool SetRow(Environment &env, Signal sig, size_t iRow, Iterator &iterator);
	bool SetCol(Environment &env, Signal sig, size_t iCol, Iterator &iterator);
	Value GetRow(Environment &env, Signal sig, size_t iRow) const;
	Value GetCol(Environment &env, Signal sig, size_t iCol) const;
	Value RoundOff(Environment &env, Signal sig, Number threshold);
	Value Transpose(Environment &env, Signal sig);
	Value Inverse(Environment &env, Signal sig);
	static Value OperatorNeg(Environment &env, Signal sig,
										const Object_matrix *pObjMat);
	static Value OperatorPlusMinus(Environment &env, Signal sig, const Function *pFunc,
				const Object_matrix *pObjMat1, const Object_matrix *pObjMat2);
	static Value OperatorMultiply(Environment &env, Signal sig,
				const Object_matrix *pObjMat1, const Object_matrix *pObjMat2);
	static Value OperatorMultiply(Environment &env, Signal sig,
				const Object_matrix *pObjMat, const Value &value);
	static Value OperatorMultiply(Environment &env, Signal sig,
				const Value &value, const Object_matrix *pObjMat);
	static Value OperatorDivide(Environment &env, Signal sig,
				const Object_matrix *pObjMat, const Value &value);
	static void SetError_IndexOutOfRange(Signal sig);
private:
	ValueType CheckValueType() const;
	static bool GetElemIndex(Environment &env, Signal sig,
		const Expr *pExprIdx, size_t nElemsSrc, size_t &iElem, size_t &nElems);
};

}

#endif
