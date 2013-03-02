//
// Object_matrix
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_matrix
//-----------------------------------------------------------------------------
Object_matrix::Object_matrix(Environment &env, size_t nRows, size_t nCols) :
	Object(env.LookupClass(VTYPE_matrix)),
	_pObjList(new Object_list(env)),
	_iRowOff(0), _iColOff(0),
	_nRows(nRows), _nCols(nCols), _nFold(nCols), _indexForColFlag(false)
{
	ValueList &valListMat = _pObjList->GetList();
	valListMat.reserve(_nRows * _nCols);
}

Object_matrix::Object_matrix(Environment &env,
						size_t nRows, size_t nCols, const Value &valueElem) :
	Object(env.LookupClass(VTYPE_matrix)),
	_pObjList(new Object_list(env, nRows * nCols, valueElem)),
	_iRowOff(0), _iColOff(0),
	_nRows(nRows), _nCols(nCols), _nFold(nCols), _indexForColFlag(false)
{
}

Object_matrix::Object_matrix(Environment &env, Object_list *pObjList,
				size_t iRowOff, size_t iColOff, size_t nRows, size_t nCols,
				size_t nFold, bool indexForColFlag) :
	Object(env.LookupClass(VTYPE_matrix)),
	_pObjList(pObjList),
	_iRowOff(iRowOff), _iColOff(iColOff),
	_nRows(nRows), _nCols(nCols), _nFold(nFold), _indexForColFlag(indexForColFlag)
{
}

Object_matrix::Object_matrix(const Object_matrix &obj) :
	Object(obj),
	_pObjList(dynamic_cast<Object_list *>(obj._pObjList->Clone())),
	_iRowOff(obj._iRowOff), _iColOff(obj._iColOff),
	_nRows(obj._nRows), _nCols(obj._nCols),
	_nFold(obj._nFold), _indexForColFlag(obj._indexForColFlag)
{
}

Object_matrix::~Object_matrix()
{
}

Object *Object_matrix::Clone() const
{
	return new Object_matrix(*this);
}

Value Object_matrix::EmptyIndexGet(Environment &env, Signal sig)
{
	if (_indexForColFlag) {
		sig.SetError(ERR_IndexError, "only one empty index should be applied");
		return Value::Null;
	}
	Value result;
	Object_matrix *pObj = new Object_matrix(env,
				Object_list::Reference(_pObjList.get()),
				_iRowOff, _iColOff, _nRows, _nCols, _nFold, true);
	result.InitAsObject(pObj);
	return result;
}

Value Object_matrix::IndexGet(Environment &env, Signal sig, const Value &valueIdx)
{
	if (!valueIdx.IsNumber()) {
		sig.SetError(ERR_IndexError, "index must be a number for list");
		return Value::Null;
	}
	size_t idx = valueIdx.GetSizeT();
	if (_indexForColFlag) {
		if (GetCols() == 1) {
			if (idx >= GetRows()) {
				SetError_IndexOutOfRange(sig);
				return Value::Null;
			}
			return *GetPointer(idx, 0);
		} else {
			if (idx >= GetCols()) {
				SetError_IndexOutOfRange(sig);
				return Value::Null;
			}
			if (GetRows() == 1) {
				return *GetPointer(0, idx);
			} else {
				return GetSub(0, idx, GetRows(), 1);
			}
		}
	} else {
		if (GetRows() == 1) {
			if (idx >= GetCols()) {
				SetError_IndexOutOfRange(sig);
				return Value::Null;
			}
			return *GetPointer(0, idx);
		} else {
			if (idx >= GetRows()) {
				SetError_IndexOutOfRange(sig);
				return Value::Null;
			}
			if (GetCols() == 1) {
				return *GetPointer(idx, 0);
			} else {
				return GetSub(idx, 0, 1, GetCols());
			}
		}
	}
}

void Object_matrix::IndexSet(Environment &env, Signal sig, const Value &valueIdx, const Value &value)
{
	if (!valueIdx.IsNumber()) {
		sig.SetError(ERR_IndexError, "index must be a number for list");
		return;
	}
	size_t idx = valueIdx.GetSizeT();
	if (GetRows() == 1) {
		if (idx >= GetCols()) {
			SetError_IndexOutOfRange(sig);
			return;
		}
		*GetPointer(0, idx) = value;
	} else {
		if (idx >= GetRows()) {
			SetError_IndexOutOfRange(sig);
			return;
		}
		if (GetCols() == 1) {
			*GetPointer(idx, 0) = value;
		} else if (value.IsMatrix()) {
			
			// todo
			
		} else {
			AutoPtr<Iterator> pIterator((value.IsList() || value.IsIterator())?
					value.CreateIterator(sig) : new Iterator_Constant(value));
			if (sig.IsSignalled()) return;
			SetRow(*this, sig, idx, *pIterator);
		}
	}
}

String Object_matrix::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	if (_nRows == 1 && _nCols == 1) {
		ValueList::const_iterator pValueElem = GetPointer(0, 0);
		rtn += pValueElem->ToString(sig, exprFlag);
	} else if (_nCols == 1) {
		rtn += "@@{";
		ValueList::const_iterator pValueElem = GetPointer(0, 0);
		size_t offset = 0;
		for (size_t iRow = 0; iRow < _nRows; iRow++, offset += GetFold()) {
			if (iRow > 0) rtn += ", ";
			rtn += (pValueElem + offset)->ToString(sig, exprFlag);
		}
		rtn += "}";
	} else {
		rtn += "@@{";
		for (size_t iRow = 0; iRow < _nRows; iRow++) {
			if (iRow > 0) rtn += ", ";
			rtn += "{";
			ValueList::const_iterator pValueElem = GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < _nCols; iCol++, pValueElem++) {
				if (iCol > 0) rtn += ", ";
				rtn += pValueElem->ToString(sig, exprFlag);
			}
			rtn += "}";
		}
		rtn += "}";
	}
	return rtn;
}

void Object_matrix::ToList(ValueList &valList, bool transposeFlag, bool flattenFlag)
{
	Environment &env = *this;
	if (_nRows == 1) {
		valList.reserve(_nCols);
		ValueList::const_iterator pValueElem = GetPointer(0, 0);
		for (size_t iCol = 0; iCol < _nCols; iCol++, pValueElem++) {
			valList.push_back(*pValueElem);
		}
	} else if (_nCols == 1) {
		valList.reserve(_nRows);
		ValueList::const_iterator pValueElem = GetPointer(0, 0);
		size_t offset = 0;
		for (size_t iRow = 0; iRow < _nRows; iRow++, offset += GetFold()) {
			valList.push_back(*(pValueElem + offset));
		}
	} else if (transposeFlag) {
		if (flattenFlag) {
			valList.reserve(_nRows * _nCols);
			for (size_t iCol = 0; iCol < _nCols; iCol++) {
				ValueList::const_iterator pValueElem = GetPointer(0, iCol);
				size_t offset = 0;
				for (size_t iRow = 0; iRow < _nRows; iRow++, offset += GetFold()) {
					valList.push_back(*(pValueElem + offset));
				}
			}
		} else {
			valList.reserve(_nCols);
			for (size_t iCol = 0; iCol < _nCols; iCol++) {
				ValueList::const_iterator pValueElem = GetPointer(0, iCol);
				Value valueCol;
				ValueList &valListCol = valueCol.InitAsList(env);
				valList.push_back(valueCol);
				size_t offset = 0;
				for (size_t iRow = 0; iRow < _nRows; iRow++, offset += GetFold()) {
					valListCol.push_back(*(pValueElem + offset));
				}
			}
		}
	} else {
		if (flattenFlag) {
			valList.reserve(_nRows * _nCols);
			for (size_t iRow = 0; iRow < _nRows; iRow++) {
				ValueList::const_iterator pValueElem = GetPointer(iRow, 0);
				for (size_t iCol = 0; iCol < _nCols; iCol++, pValueElem++) {
					valList.push_back(*pValueElem);
				}
			}
		} else {
			valList.reserve(_nRows);
			for (size_t iRow = 0; iRow < _nRows; iRow++) {
				ValueList::const_iterator pValueElem = GetPointer(iRow, 0);
				Value valueRow;
				ValueList &valListRow = valueRow.InitAsList(env);
				valList.push_back(valueRow);
				for (size_t iCol = 0; iCol < _nCols; iCol++, pValueElem++) {
					valListRow.push_back(*pValueElem);
				}
			}
		}
	}
}

Value Object_matrix::GetSub(size_t iRow, size_t iCol, size_t nRows, size_t nCols)
{
	Environment &env = *this;
	Value result;
	Object_matrix *pObj = new Object_matrix(env,
				Object_list::Reference(_pObjList.get()),
				iRow, iCol, nRows, nCols, _nFold, false);
	result.InitAsObject(pObj);
	return result;
}

bool Object_matrix::Set(Environment &env, Signal sig, Iterator &iterator)
{
	for (size_t iRow = 0; iRow < _nRows; iRow++) {
		ValueList::iterator pValueElem = GetPointer(iRow, 0);
		Value value;
		for (size_t iCol = 0; iCol < _nCols && iterator.Next(env, sig, value);
														iCol++, pValueElem++) {
			*pValueElem = value;
		}
		if (sig.IsSignalled()) return false;
	}
	return true;
}

bool Object_matrix::SetRow(Environment &env, Signal sig, size_t iRow, Iterator &iterator)
{
	if (iRow >= _nRows) {
		SetError_IndexOutOfRange(sig);
		return false;
	}
	Value value;
	ValueList::iterator pValueElem = GetPointer(iRow, 0);
	for (size_t iCol = 0; iCol < _nCols && iterator.Next(env, sig, value);
												iCol++, pValueElem++) {
		*pValueElem = value;
	}
	return true;
}

bool Object_matrix::SetCol(Environment &env, Signal sig, size_t iCol, Iterator &iterator)
{
	if (iCol >= _nCols) {
		SetError_IndexOutOfRange(sig);
		return false;
	}
	Value value;
	ValueList::iterator pValueElem = GetPointer(0, iCol);
	size_t offset = 0;
	for (size_t iRow = 0; iRow < _nRows && iterator.Next(env, sig, value);
												iRow++, offset += GetFold()) {
		*(pValueElem + offset) = value;
	}
	return true;
}

Value Object_matrix::GetRow(Environment &env, Signal sig, size_t iRow) const
{
	if (iRow >= _nRows) {
		SetError_IndexOutOfRange(sig);
		return false;
	}
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(GetCols());
	ValueList::const_iterator pValueElem = GetPointer(iRow, 0);
	for (size_t iCol = 0; iCol < GetCols(); iCol++, pValueElem++) {
		valList.push_back(*pValueElem);
	}
	return result;
}

Value Object_matrix::GetCol(Environment &env, Signal sig, size_t iCol) const
{
	if (iCol >= _nCols) {
		SetError_IndexOutOfRange(sig);
		return false;
	}
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(GetRows());
	ValueList::const_iterator pValueElem = GetPointer(0, iCol);
	size_t offset = 0;
	for (size_t iRow = 0; iRow < GetRows(); iRow++, offset += GetFold()) {
		valList.push_back(*(pValueElem + offset));
	}
	return result;
}

Value Object_matrix::RoundOff(Environment &env, Signal sig, Number threshold)
{
	size_t nRows = GetRows(), nCols = GetCols();
	Object_matrix *pObjMatRtn = new Object_matrix(env, nRows, nCols);
	ValueList &valList = pObjMatRtn->GetList();
	foreach_const (ValueList, pValue, GetList()) {
		if (pValue->IsNumber()) {
			Number num = pValue->GetNumber();
			if (num < threshold) num = 0;
			valList.push_back(Value(num));
		} else {
			valList.push_back(*pValue);
		}
	}
	Value result(pObjMatRtn);
	return result;
}

Value Object_matrix::Transpose(Environment &env, Signal sig)
{
	Value result;
	size_t nRows = GetRows(), nCols = GetCols();
	size_t nFold = GetFold();
	Object_matrix *pObjMatRtn = new Object_matrix(env, nCols, nRows);
	result.InitAsObject(pObjMatRtn);
	ValueList &valList = pObjMatRtn->GetList();
	for (size_t iCol = 0; iCol < nCols; iCol++) {
		ValueList::const_iterator pValueElem = GetPointer(0, iCol);
		size_t offset = 0;
		for (size_t iRow = 0; iRow < nRows; iRow++, offset += nFold) {
			valList.push_back(*(pValueElem + offset));
		}
	}
	return result;
}

Value Object_matrix::Invert(Environment &env, Signal sig)
{
	size_t nCols = GetCols(), nRows = GetRows();
	if (nCols != nRows) {
		sig.SetError(ERR_ValueError, "inversion can only be applied to square matrix");
		return Value::Null;
	}
	ValueType valType = CheckValueType();
	if (valType == VTYPE_number) {
		NumberList mat;
		mat.reserve(nCols * 2 * nRows);
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
				mat.push_back(pValueElem->GetNumber());
			}
			for (size_t iCol = 0; iCol < nCols; iCol++) {
				mat.push_back((iCol == iRow)? 1. : 0.);
			}
		}
		Number det;
		if (!InvertMatrix(mat, nCols, det)) {
			sig.SetError(ERR_ValueError, "failed to calculate inverted matrix");
			return Value::Null;
		}
		Value result;
		Object_matrix *pObjMatRtn = new Object_matrix(env, nCols, nRows);
		result.InitAsObject(pObjMatRtn);
		ValueList &valList = pObjMatRtn->GetList();
		size_t offset = nCols;
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			for (size_t iCol = 0; iCol < nCols; iCol++, offset++) {
				valList.push_back(mat[offset]);
			}
			offset += nCols;
		}
		return result;
	} else if (valType == VTYPE_complex) {
		ComplexList mat;
		mat.reserve(nCols * 2 * nRows);
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
				mat.push_back(pValueElem->GetComplex());
			}
			for (size_t iCol = 0; iCol < nCols; iCol++) {
				mat.push_back((iCol == iRow)? 1. : 0.);
			}
		}
		Complex det;
		if (!InvertMatrix(mat, nCols, det)) {
			sig.SetError(ERR_ValueError, "failed to calculate inverted matrix");
			return Value::Null;
		}
		Value result;
		Object_matrix *pObjMatRtn = new Object_matrix(env, nCols, nRows);
		result.InitAsObject(pObjMatRtn);
		ValueList &valList = pObjMatRtn->GetList();
		size_t offset = nCols;
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			for (size_t iCol = 0; iCol < nCols; iCol++, offset++) {
				valList.push_back(mat[offset]);
			}
			offset += nCols;
		}
		return result;
	}
	sig.SetError(ERR_ValueError, "failed to calculate inverted matrix");
	return Value::Null;
}

bool Object_matrix::GetElemIndex(Environment &env, Signal sig,
		const Expr *pExprIdx, size_t nElemsSrc, size_t &iElem, size_t &nElems)
{
	Value valueIdx = pExprIdx->Exec(env, sig);
	if (sig.IsSignalled()) return false;
	if (valueIdx.IsNumber()) {
		iElem = valueIdx.GetSizeT();
	} else if (valueIdx.IsIterator()) {
		Iterator *pIterator = valueIdx.GetIterator();
		if (pIterator->IsSequence()) {
			Iterator_Sequence *pIteratorEx =
							dynamic_cast<Iterator_Sequence *>(pIterator);
			iElem = static_cast<size_t>(pIteratorEx->GetBegin());
			nElems = static_cast<size_t>(
						pIteratorEx->GetEnd() - pIteratorEx->GetBegin()) + 1;
		} else if (pIterator->IsSequenceInf()) {
			Iterator_SequenceInf *pIteratorEx =
							dynamic_cast<Iterator_SequenceInf *>(pIterator);
			iElem = static_cast<size_t>(pIteratorEx->GetBegin());
			nElems = nElemsSrc - iElem;
		} else {
			sig.SetError(ERR_ValueError, "invalid index expression");
			return false;
		}
	} else {
		sig.SetError(ERR_ValueError, "invalid index expression");
		return false;
	}
	if (iElem >= nElemsSrc || iElem + nElems > nElemsSrc) {
		SetError_IndexOutOfRange(sig);
		return false;
	}
	return true;
}

Value Object_matrix::OperatorNeg(Environment &env, Signal sig,
											const Object_matrix *pObjMat)
{
	Value result;
	size_t nRows = pObjMat->GetRows(), nCols = pObjMat->GetCols();
	Object_matrix *pObjMatRtn = new Object_matrix(env, nRows, nCols);
	result.InitAsObject(pObjMatRtn);
	ValueList &valList = pObjMatRtn->GetList();
	const Function *pFunc = env.GetOpFunc(OPTYPE_Neg);
	for (size_t iRow = 0; iRow < nRows; iRow++) {
		ValueList::const_iterator pValueElem = pObjMat->GetPointer(iRow, 0);
		for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
			ValueList valListArg(*pValueElem);
			Args args(valListArg);
			Value resultElem = pFunc->Eval(env, sig, args);
			if (sig.IsSignalled()) return Value::Null;
			valList.push_back(resultElem);
		}
	}
	return result;
}

void SetError_MatrixSizeMismatch(Signal sig)
{
	sig.SetError(ERR_ValueError, "matrix size mismatches");
}

Value Object_matrix::OperatorPlusMinus(Environment &env, Signal sig, const Function *pFunc,
				const Object_matrix *pObjMat1, const Object_matrix *pObjMat2)
{
	Value result;
	size_t nRows = pObjMat1->GetRows(), nCols = pObjMat1->GetCols();
	if (!(nRows == pObjMat2->GetRows() && nCols == pObjMat2->GetCols())) {
		SetError_MatrixSizeMismatch(sig);
		return Value::Null;
	}
	Object_matrix *pObjMatRtn = new Object_matrix(env, nRows, nCols);
	result.InitAsObject(pObjMatRtn);
	ValueList &valList = pObjMatRtn->GetList();
	for (size_t iRow = 0; iRow < nRows; iRow++) {
		ValueList::const_iterator pValueElem1 = pObjMat1->GetPointer(iRow, 0);
		ValueList::const_iterator pValueElem2 = pObjMat2->GetPointer(iRow, 0);
		for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem1++, pValueElem2++) {
			ValueList valListArg(*pValueElem1, *pValueElem2);
			Args args(valListArg);
			Value resultElem = pFunc->Eval(env, sig, args);
			if (sig.IsSignalled()) return Value::Null;
			valList.push_back(resultElem);
		}
	}
	return result;
}

Value Object_matrix::OperatorMultiply(Environment &env, Signal sig,
				const Object_matrix *pObjMat1, const Object_matrix *pObjMat2)
{
	Value result;
	size_t nRows = pObjMat1->GetRows(), nCols = pObjMat2->GetCols();
	size_t nElems = pObjMat1->GetCols();
	size_t nFold = pObjMat2->GetFold();
	if (nElems != pObjMat2->GetRows()) {
		SetError_MatrixSizeMismatch(sig);
		return Value::Null;
	}
	Object_matrix *pObjMatRtn = new Object_matrix(env, nRows, nCols);
	result.InitAsObject(pObjMatRtn);
	ValueList &valList = pObjMatRtn->GetList();
	const Function *pFuncMultiply = env.GetOpFunc(OPTYPE_Multiply);
	const Function *pFuncPlus = env.GetOpFunc(OPTYPE_Plus);
	for (size_t iRow = 0; iRow < nRows; iRow++) {
		for (size_t iCol = 0; iCol < nCols; iCol++) {
			ValueList::const_iterator pValueElem1 = pObjMat1->GetPointer(iRow, 0);
			ValueList::const_iterator pValueElem2 = pObjMat2->GetPointer(0, iCol);
			Value valueAccum(0);
			size_t offset = 0;
			for (size_t iElem = 0; iElem < nElems;
									iElem++, pValueElem1++, offset += nFold) {
				Value valueElem;
				do {
					ValueList valListArg(*pValueElem1, *(pValueElem2 + offset));
					Args args(valListArg);
					valueElem = pFuncMultiply->Eval(env, sig, args);
					if (sig.IsSignalled()) return Value::Null;
				} while (0);
				do {
					ValueList valListArg(valueAccum, valueElem);
					Args args(valListArg);
					valueAccum = pFuncPlus->Eval(env, sig, args);
					if (sig.IsSignalled()) return Value::Null;
				} while (0);
			}
			valList.push_back(valueAccum);
		}
	}
	return result;
}

Value Object_matrix::OperatorMultiply(Environment &env, Signal sig,
							const Object_matrix *pObjMat, const Value &value)
{
	Value result;
	size_t nRows = pObjMat->GetRows(), nCols = pObjMat->GetCols();
	if (value.IsList()) {
		const ValueList &valList = value.GetList();
		if (nCols != valList.size()) {
			SetError_MatrixSizeMismatch(sig);
			return Value::Null;
		}
		const Function *pFuncMultiply = env.GetOpFunc(OPTYPE_Multiply);
		const Function *pFuncPlus = env.GetOpFunc(OPTYPE_Plus);
		ValueList &valListResult = result.InitAsList(env);
		valListResult.reserve(nRows);
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = pObjMat->GetPointer(iRow, 0);
			Value valueAccum(0);
			foreach_const (ValueList, pValue, valList) {
				Value valueElem;
				do {
					ValueList valListArg(*pValueElem, *pValue);
					Args args(valListArg);
					valueElem = pFuncMultiply->Eval(env, sig, args);
					if (sig.IsSignalled()) return Value::Null;
				} while (0);
				do {
					ValueList valListArg(valueAccum, valueElem);
					Args args(valListArg);
					valueAccum = pFuncPlus->Eval(env, sig, args);
					if (sig.IsSignalled()) return Value::Null;
				} while (0);
				pValueElem++;
			}
			valListResult.push_back(valueAccum);
		}
		if (valListResult.size() == 1) return valListResult.front();
	} else {
		Object_matrix *pObjMatRtn = new Object_matrix(env, nRows, nCols);
		result.InitAsObject(pObjMatRtn);
		ValueList &valListResult = pObjMatRtn->GetList();
		const Function *pFunc = env.GetOpFunc(OPTYPE_Multiply);
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = pObjMat->GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
				ValueList valListArg(*pValueElem, value);
				Args args(valListArg);
				Value resultElem = pFunc->Eval(env, sig, args);
				if (sig.IsSignalled()) return Value::Null;
				valListResult.push_back(resultElem);
			}
		}
		if (valListResult.size() == 1) return valListResult.front();
	}
	return result;
}

Value Object_matrix::OperatorMultiply(Environment &env, Signal sig,
							const Value &value, const Object_matrix *pObjMat)
{
	Value result;
	size_t nRows = pObjMat->GetRows(), nCols = pObjMat->GetCols();
	size_t nFold = pObjMat->GetFold();
	if (value.IsList()) {
		const ValueList &valList = value.GetList();
		if (nRows != valList.size()) {
			SetError_MatrixSizeMismatch(sig);
			return Value::Null;
		}
		const Function *pFuncMultiply = env.GetOpFunc(OPTYPE_Multiply);
		const Function *pFuncPlus = env.GetOpFunc(OPTYPE_Plus);
		ValueList &valListResult = result.InitAsList(env);
		valListResult.reserve(nCols);
		for (size_t iCol = 0; iCol < nCols; iCol++) {
			ValueList::const_iterator pValueElem = pObjMat->GetPointer(0, iCol);
			Value valueAccum(0);
			size_t offset = 0;
			foreach_const (ValueList, pValue, valList) {
				Value valueElem;
				do {
					ValueList valListArg(*(pValueElem + offset), *pValue);
					Args args(valListArg);
					valueElem = pFuncMultiply->Eval(env, sig, args);
					if (sig.IsSignalled()) return Value::Null;
				} while (0);
				do {
					ValueList valListArg(valueAccum, valueElem);
					Args args(valListArg);
					valueAccum = pFuncPlus->Eval(env, sig, args);
					if (sig.IsSignalled()) return Value::Null;
				} while (0);
				offset += nFold;
			}
			valListResult.push_back(valueAccum);
		}
		if (valListResult.size() == 1) return valListResult.front();
	} else {
		Object_matrix *pObjMatRtn = new Object_matrix(env, nRows, nCols);
		result.InitAsObject(pObjMatRtn);
		ValueList &valListResult = pObjMatRtn->GetList();
		const Function *pFunc = env.GetOpFunc(OPTYPE_Multiply);
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = pObjMat->GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
				ValueList valListArg(value, *pValueElem);
				Args args(valListArg);
				Value resultElem = pFunc->Eval(env, sig, args);
				if (sig.IsSignalled()) return Value::Null;
				valListResult.push_back(resultElem);
			}
		}
		if (valListResult.size() == 1) return valListResult.front();
	}
	return result;
}

Value Object_matrix::OperatorDivide(Environment &env, Signal sig,
							const Object_matrix *pObjMat, const Value &value)
{
	Value result;
	size_t nRows = pObjMat->GetRows(), nCols = pObjMat->GetCols();
	Object_matrix *pObjMatRtn = new Object_matrix(env, nRows, nCols);
	result.InitAsObject(pObjMatRtn);
	ValueList &valList = pObjMatRtn->GetList();
	const Function *pFunc = env.GetOpFunc(OPTYPE_Divide);
	for (size_t iRow = 0; iRow < nRows; iRow++) {
		ValueList::const_iterator pValueElem = pObjMat->GetPointer(iRow, 0);
		for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
			ValueList valListArg(*pValueElem, value);
			Args args(valListArg);
			Value resultElem = pFunc->Eval(env, sig, args);
			if (sig.IsSignalled()) return Value::Null;
			valList.push_back(resultElem);
		}
	}
	return result;
}

ValueType Object_matrix::CheckValueType() const
{
	ValueType valType = VTYPE_nil;
	size_t nCols = GetCols(), nRows = GetRows();
	for (size_t iRow = 0; iRow < nRows; iRow++) {
		ValueList::const_iterator pValueElem = GetPointer(iRow, 0);
		for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
			if (pValueElem->IsNumber()) {
				if (valType == VTYPE_nil) valType = VTYPE_number;
			} else if (pValueElem->IsComplex()) {
				valType = VTYPE_complex;
			} else {
				return VTYPE_nil;
			}
		}
	}
	return valType;
}

void Object_matrix::SetError_IndexOutOfRange(Signal sig)
{
	sig.SetError(ERR_IndexError, "index is out of range");
}

//-----------------------------------------------------------------------------
// Object_matrix::IteratorEach
//-----------------------------------------------------------------------------
Object_matrix::IteratorEach::~IteratorEach()
{
}

bool Object_matrix::IteratorEach::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_transposeFlag) {
		if (_iCol >= _pObj->GetCols()) return false;
		value = *_pObj->GetPointer(_iRow, _iCol);
		_iRow++;
		if (_iRow >= _pObj->GetRows()) {
			_iRow = 0, _iCol++;
		}
	} else {
		if (_iRow >= _pObj->GetRows()) return false;
		value = *_pObj->GetPointer(_iRow, _iCol);
		_iCol++;
		if (_iCol >= _pObj->GetCols()) {
			_iCol = 0, _iRow++;
		}
	}
	return true;
}

String Object_matrix::IteratorEach::ToString(Signal sig) const
{
	return String("<iterator:matrix#each>");
}

void Object_matrix::IteratorEach::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_matrix::IteratorEachRow
//-----------------------------------------------------------------------------
Object_matrix::IteratorEachRow::~IteratorEachRow()
{
}

bool Object_matrix::IteratorEachRow::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_iRow >= _pObj->GetRows()) return false;
	value = _pObj->GetRow(env, sig, _iRow);
	_iRow++;
	return true;
}

String Object_matrix::IteratorEachRow::ToString(Signal sig) const
{
	return String("<iterator:matrix#eachrow>");
}

void Object_matrix::IteratorEachRow::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_matrix::IteratorEachCol
//-----------------------------------------------------------------------------
Object_matrix::IteratorEachCol::~IteratorEachCol()
{
}

bool Object_matrix::IteratorEachCol::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_iCol >= _pObj->GetCols()) return false;
	value = _pObj->GetCol(env, sig, _iCol);
	_iCol++;
	return true;
}

String Object_matrix::IteratorEachCol::ToString(Signal sig) const
{
	return String("<iterator:matrix#eachcol>");
}

void Object_matrix::IteratorEachCol::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Global functions
//-----------------------------------------------------------------------------
// matrix(nrows:number, ncols:number, value?) {block?}
Gura_DeclareFunction(matrix)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "nrows", VTYPE_number);
	DeclareArg(env, "ncols", VTYPE_number);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_matrix));
}

Gura_ImplementFunction(matrix)
{
	Value result;
	Value valueZero(0.);
	result.InitAsMatrix(env, args.GetInt(0), args.GetInt(1),
					args.IsValid(2)? args.GetValue(2) : valueZero);
	return ReturnValue(env, sig, args, result);
}

// @@ {block}
Gura_DeclareFunction(MatrixInit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementFunction(MatrixInit)
{
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	Environment envLister(&env, ENVTYPE_lister);
	Value valueInit = pExprBlock->GetExprOwner().ExecForList(envLister, sig, false, false);
	if (sig.IsSignalled()) return Value::Null;
	Value result;
	result.InitAsMatrix(env, sig, valueInit.GetList());
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_matrix
//-----------------------------------------------------------------------------
// matrix.identity(n:number) {block?}
Gura_DeclareClassMethod(matrix, identity)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(matrix, identity)
{
	Value result;
	Value valueZero(0.), valueOne(1.);
	int n = args.GetInt(0);
	Object_matrix *pObj = result.InitAsMatrix(env, n, n, valueZero);
	for (int i = 0; i < n; i++) {
		pObj->SetElement(i, i, valueOne);
	}
	return ReturnValue(env, sig, args, result);
}

// matrix#set(value)
Gura_DeclareMethod(matrix, set)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any);
	AddHelp(Gura_Symbol(en), "Sets all the cells of the matrix with a specified value.");
}

Gura_ImplementMethod(matrix, set)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	AutoPtr<Iterator> pIterator((args.IsList(0) || args.IsIterator(0))?
								args.GetValue(0).CreateIterator(sig) :
								new Iterator_Constant(args.GetValue(0)));
	if (sig.IsSignalled()) return Value::Null;
	pThis->Set(env, sig, *pIterator);
	return Value::Null;
}

// matrix#setrow(row:number, value)
Gura_DeclareMethod(matrix, setrow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "row", VTYPE_number);
	DeclareArg(env, "value", VTYPE_any);
	AddHelp(Gura_Symbol(en), "Sets cells in a selected row of the matrix with a specified value.");
}

Gura_ImplementMethod(matrix, setrow)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	AutoPtr<Iterator> pIterator((args.IsList(1) || args.IsIterator(1))?
								args.GetValue(1).CreateIterator(sig) :
								new Iterator_Constant(args.GetValue(1)));
	if (sig.IsSignalled()) return Value::Null;
	pThis->SetRow(env, sig, args.GetSizeT(0), *pIterator);
	return Value::Null;
}

// matrix#setcol(col:number, value)
Gura_DeclareMethod(matrix, setcol)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "col", VTYPE_number);
	DeclareArg(env, "value", VTYPE_any);
	AddHelp(Gura_Symbol(en), "Sets cells in a selected column of the matrix with a specified value.");
}

Gura_ImplementMethod(matrix, setcol)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	AutoPtr<Iterator> pIterator((args.IsList(1) || args.IsIterator(1))?
								args.GetValue(1).CreateIterator(sig) :
								new Iterator_Constant(args.GetValue(1)));
	if (sig.IsSignalled()) return Value::Null;
	pThis->SetCol(env, sig, args.GetSizeT(0), *pIterator);
	return Value::Null;
}

// matrix#rowsize()
Gura_DeclareMethod(matrix, rowsize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), "Returns the matrix row size.");
}

Gura_ImplementMethod(matrix, rowsize)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	return Value(static_cast<unsigned int>(pThis->GetRows()));
}

// matrix#colsize()
Gura_DeclareMethod(matrix, colsize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), "Returns the matrix column size.");
}

Gura_ImplementMethod(matrix, colsize)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	return Value(static_cast<unsigned int>(pThis->GetCols()));
}

// matrix#issquare()
Gura_DeclareMethod(matrix, issquare)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), "Returns true if the matrix is a square one.");
}

Gura_ImplementMethod(matrix, issquare)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	return Value(pThis->GetRows() == pThis->GetCols());
}

// matrix#submat(row:number, col:number, nrows:number, ncols:number):map
Gura_DeclareMethod(matrix, submat)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number);
	DeclareArg(env, "col", VTYPE_number);
	DeclareArg(env, "nrows", VTYPE_number);
	DeclareArg(env, "ncols", VTYPE_number);
	AddHelp(Gura_Symbol(en), 
	"Returns a sub matrix that refers to cells in a specified area of the matrix.\n"
	"Modification on the returned sub matrix will affect on the original one.");
}

Gura_ImplementMethod(matrix, submat)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	return pThis->GetSub(args.GetSizeT(0), args.GetSizeT(1),
						args.GetSizeT(2), args.GetSizeT(3));
}

// matrix#row(row:number):map
Gura_DeclareMethod(matrix, row)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number);
	AddHelp(Gura_Symbol(en), 
	"Returns a list of values copied from a specified row of the matrix.\n"
	"Modification on the returned sub matrix will affect on the original one.");
}

Gura_ImplementMethod(matrix, row)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	return pThis->GetRow(env, sig, args.GetSizeT(0));
}

// matrix#col(col:number):map
Gura_DeclareMethod(matrix, col)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number);
	AddHelp(Gura_Symbol(en), 
	"Returns a list of values copied from a specified column of the matrix.\n"
	"Modification on the returned sub matrix will affect on the original one.");
}

Gura_ImplementMethod(matrix, col)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	return pThis->GetCol(env, sig, args.GetSizeT(0));
}

// matrix#each():[transpose]
Gura_DeclareMethod(matrix, each)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(transpose));
	AddHelp(Gura_Symbol(en), 
	"Returns an iterator that picks up each cell by scanning the matrix.\n"
	"In default, that scan is done in a horizontal direction.\n"
	"When an attribute :transpose is specified, it's done in a vertical direction.");
}

Gura_ImplementMethod(matrix, each)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	Object_matrix *pObj = Object_matrix::Reference(pThis);
	Iterator *pIterator = new Object_matrix::IteratorEach(pObj,
								args.IsSet(Gura_Symbol(transpose)));
	return ReturnIterator(env, sig, args, pIterator);
}

// matrix#eachrow()
Gura_DeclareMethod(matrix, eachrow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), 
	"Returns an iterator that generates lists of values copied from each row\n"
	"of the matrix.\n");
}

Gura_ImplementMethod(matrix, eachrow)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	Object_matrix *pObj = Object_matrix::Reference(pThis);
	return ReturnIterator(env, sig, args,
							new Object_matrix::IteratorEachRow(pObj));
}

// matrix#eachcol()
Gura_DeclareMethod(matrix, eachcol)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), 
	"Returns an iterator that generates lists of values copied from each column\n"
	"of the matrix.\n");
}

Gura_ImplementMethod(matrix, eachcol)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	Object_matrix *pObj = Object_matrix::Reference(pThis);
	return ReturnIterator(env, sig, args,
							new Object_matrix::IteratorEachCol(pObj));
}

// matrix#tolist():[transpose,flat]
Gura_DeclareMethod(matrix, tolist)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(transpose));
	DeclareAttr(Gura_Symbol(flat));
	AddHelp(Gura_Symbol(en), 
	"Converts the matrix into a list containing sub-lists that represents its rows.\n"
	"If :transpose attribute is specified, each sub-list contains values of\n"
	"corresponding column. If :flat attribute is specified, it generates\n"
	"one-dimentional list.\n"
	"Example:\n"
	">>> @@{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}.tolist()\n"
	"[[1, 2, 3], [4, 5, 6], [7, 8, 9]]\n"
	">>> @@{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}.tolist():transpose\n"
	"[[1, 4, 7], [2, 5, 8], [3, 6, 9]]");
}

Gura_ImplementMethod(matrix, tolist)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	Value result;
	ValueList &valList = result.InitAsList(env);
	pThis->ToList(valList,
			args.IsSet(Gura_Symbol(transpose)),
			args.IsSet(Gura_Symbol(flat)));
	return result;
}

// matrix#roundoff(threshold:number => 1e-10)
Gura_DeclareMethod(matrix, roundoff)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once, FLAG_None,
										new Expr_Value(RoundOffThreshold));
	AddHelp(Gura_Symbol(en), "Returns a matrix with values that have been rounded off.");
}

Gura_ImplementMethod(matrix, roundoff)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	if (sig.IsSignalled()) return Value::Null;
	return pThis->RoundOff(env, sig, args.GetNumber(0));
}

// matrix#transpose()
Gura_DeclareMethod(matrix, transpose)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), "Returns a transpose matrix.");
}

Gura_ImplementMethod(matrix, transpose)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	if (sig.IsSignalled()) return Value::Null;
	return pThis->Transpose(env, sig);
}

// matrix#invert()
Gura_DeclareMethod(matrix, invert)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), "Returns an inverted matrix.");
}

Gura_ImplementMethod(matrix, invert)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	if (sig.IsSignalled()) return Value::Null;
	return pThis->Invert(env, sig);
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_matrix::Class_matrix(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_matrix)
{
	Gura_AssignMethod(matrix, identity);
	Gura_AssignMethod(matrix, set);
	Gura_AssignMethod(matrix, setrow);
	Gura_AssignMethod(matrix, setcol);
	Gura_AssignMethod(matrix, rowsize);
	Gura_AssignMethod(matrix, colsize);
	Gura_AssignMethod(matrix, issquare);
	Gura_AssignMethod(matrix, submat);
	Gura_AssignMethod(matrix, row);
	Gura_AssignMethod(matrix, col);
	Gura_AssignMethod(matrix, each);
	Gura_AssignMethod(matrix, eachrow);
	Gura_AssignMethod(matrix, eachcol);
	Gura_AssignMethod(matrix, tolist);
	Gura_AssignMethod(matrix, roundoff);
	Gura_AssignMethod(matrix, transpose);
	Gura_AssignMethod(matrix, invert);
}

bool Class_matrix::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	Object_matrix *pObj = value.GetMatrixObj();
	if (!pObj->GetList().Serialize(env, sig, stream)) return false;
	if (!stream.SerializePackedULong(sig, static_cast<unsigned long>(pObj->GetRowOff()))) return false;
	if (!stream.SerializePackedULong(sig, static_cast<unsigned long>(pObj->GetColOff()))) return false;
	if (!stream.SerializePackedULong(sig, static_cast<unsigned long>(pObj->GetRows()))) return false;
	if (!stream.SerializePackedULong(sig, static_cast<unsigned long>(pObj->GetCols()))) return false;
	if (!stream.SerializePackedULong(sig, static_cast<unsigned long>(pObj->GetFold()))) return false;
	if (!stream.SerializeBoolean(sig, pObj->GetIndexForColFlag())) return false;
	return true;
}

bool Class_matrix::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	Object_list *pObjList = new Object_list(env);
	if (!pObjList->GetList().Deserialize(env, sig, stream)) return false;
	unsigned long iRowOff = 0, iColOff = 0;
	unsigned long nRows = 0, nCols = 0;
	unsigned long nFold = 0;
	bool indexForColFlag = false;
	if (!stream.DeserializePackedULong(sig, iRowOff)) return false;
	if (!stream.DeserializePackedULong(sig, iColOff)) return false;
	if (!stream.DeserializePackedULong(sig, nRows)) return false;
	if (!stream.DeserializePackedULong(sig, nCols)) return false;
	if (!stream.DeserializePackedULong(sig, nFold)) return false;
	if (!stream.DeserializeBoolean(sig, indexForColFlag)) return false;
	unsigned long nElems = static_cast<unsigned long>(pObjList->GetList().size());
	//::printf("%d %d %d %d %d %d\n", nElems, iRowOff, iColOff, nRows, nCols, nFold);
	if (nFold * nRows > nElems || iColOff + nCols > nFold) {
		sig.SetError(ERR_ValueError, "invalid parameter for matrix");
		return false;
	}
	value = Value(new Object_matrix(env, pObjList,
			static_cast<size_t>(iRowOff), static_cast<size_t>(iColOff),
			static_cast<size_t>(nRows), static_cast<size_t>(nCols),
			static_cast<size_t>(nFold), indexForColFlag));
	return true;
}

Object *Class_matrix::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	return NULL;
}

void Class_matrix::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(matrix);
	Gura_AssignFunctionEx(MatrixInit, "@@");
}

}
