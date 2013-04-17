// Matrix

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Matrix
//-----------------------------------------------------------------------------
Matrix::Matrix(const Matrix &matrix) :
	_cntRef(1), _pElements(new Elements(*matrix._pElements)),
	_iRowOff(matrix._iRowOff), _iColOff(matrix._iColOff),
	_nRows(matrix._nRows), _nCols(matrix._nCols),
	_nFold(matrix._nFold), _indexForColFlag(matrix._indexForColFlag)
{

}

Matrix::Matrix(size_t nRows, size_t nCols) :
	_cntRef(1), _pElements(new Elements()),
	_iRowOff(0), _iColOff(0),
	_nRows(nRows), _nCols(nCols), _nFold(nCols), _indexForColFlag(false)
{
	size_t nElems = _nRows * _nCols;
	GetList().reserve(nElems);
}

Matrix::Matrix(size_t nRows, size_t nCols, const Value &valueElem) :
	_cntRef(1), _pElements(new Elements()),
	_iRowOff(0), _iColOff(0),
	_nRows(nRows), _nCols(nCols), _nFold(nCols), _indexForColFlag(false)
{
	size_t nElems = _nRows * _nCols;
	GetList().reserve(nElems);
	for (size_t i = 0; i < nElems; i++) GetList().push_back(valueElem);
}

Matrix::Matrix(Elements *pElements,
			size_t iRowOff, size_t iColOff, size_t nRows, size_t nCols,
			size_t nFold, bool indexForColFlag) :
	_cntRef(1), _pElements(pElements),
	_iRowOff(iRowOff), _iColOff(iColOff),
	_nRows(nRows), _nCols(nCols), _nFold(nFold), _indexForColFlag(indexForColFlag)
{
}

Matrix *Matrix::CreateIdentity(int n)
{
	AutoPtr<Matrix> pMat(new Matrix(n, n, Value::Zero));
	for (int i = 0; i < n; i++) {
		pMat->SetElement(i, i, Value::One);
	}
	return pMat.release();
}

Matrix *Matrix::CreateRotation(double rad)
{
	Number numCos = ::cos(rad), numSin = ::sin(rad);
	AutoPtr<Matrix> pMat(new Matrix(2, 2));
	ValueList &valList = pMat->GetList();
	valList.push_back(Value(numCos));
	valList.push_back(Value(-numSin));
	valList.push_back(Value(numSin));
	valList.push_back(Value(numCos));
	return pMat.release();
}

Matrix *Matrix::CreateRotationX(double rad)
{
	Number numCos = ::cos(rad), numSin = ::sin(rad);
	AutoPtr<Matrix> pMat(new Matrix(3, 3));
	ValueList &valList = pMat->GetList();
	valList.push_back(Value::One);
	valList.push_back(Value::Zero);
	valList.push_back(Value::Zero);
	valList.push_back(Value::Zero);
	valList.push_back(Value(numCos));
	valList.push_back(Value(-numSin));
	valList.push_back(Value::Zero);
	valList.push_back(Value(numSin));
	valList.push_back(Value(numCos));
	return pMat.release();
}

Matrix *Matrix::CreateRotationY(double rad)
{
	Number numCos = ::cos(rad), numSin = ::sin(rad);
	AutoPtr<Matrix> pMat(new Matrix(3, 3));
	ValueList &valList = pMat->GetList();
	valList.push_back(Value(numCos));
	valList.push_back(Value::Zero);
	valList.push_back(Value(numSin));
	valList.push_back(Value::Zero);
	valList.push_back(Value::One);
	valList.push_back(Value::Zero);
	valList.push_back(Value(-numSin));
	valList.push_back(Value::Zero);
	valList.push_back(Value(numCos));
	
	return pMat.release();
}

Matrix *Matrix::CreateRotationZ(double rad)
{
	Number numCos = ::cos(rad), numSin = ::sin(rad);
	AutoPtr<Matrix> pMat(new Matrix(3, 3));
	ValueList &valList = pMat->GetList();
	valList.push_back(Value(numCos));
	valList.push_back(Value(-numSin));
	valList.push_back(Value::Zero);
	valList.push_back(Value(numSin));
	valList.push_back(Value(numCos));
	valList.push_back(Value::Zero);
	valList.push_back(Value::Zero);
	valList.push_back(Value::Zero);
	valList.push_back(Value::One);
	return pMat.release();
}

void Matrix::ToList(Environment &env, ValueList &valList, bool transposeFlag, bool flattenFlag)
{
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

Value Matrix::GetSub(Environment &env, size_t iRow, size_t iCol, size_t nRows, size_t nCols)
{
	AutoPtr<Matrix> pMat(new Matrix(Elements::Reference(GetElements()),
								iRow, iCol, nRows, nCols, _nFold, false));
	return Value(new Object_matrix(env, pMat.release()));
}

bool Matrix::Set(Environment &env, Signal sig, Iterator &iterator)
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

bool Matrix::SetRow(Environment &env, Signal sig, size_t iRow, Iterator &iterator)
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

bool Matrix::SetCol(Environment &env, Signal sig, size_t iCol, Iterator &iterator)
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

Value Matrix::GetRow(Environment &env, Signal sig, size_t iRow) const
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

Value Matrix::GetCol(Environment &env, Signal sig, size_t iCol) const
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

Value Matrix::RoundOff(Environment &env, Signal sig, Number threshold)
{
	size_t nRows = GetRows(), nCols = GetCols();
	AutoPtr<Matrix> pMatRtn(new Matrix(nRows, nCols));
	ValueList &valList = pMatRtn->GetList();
	foreach_const (ValueList, pValue, GetList()) {
		if (pValue->IsNumber()) {
			Number num = pValue->GetNumber();
			if (num < threshold) num = 0;
			valList.push_back(Value(num));
		} else {
			valList.push_back(*pValue);
		}
	}
	return Value(new Object_matrix(env, pMatRtn.release()));
}

Value Matrix::Transpose(Environment &env, Signal sig)
{
	size_t nRows = GetRows(), nCols = GetCols();
	size_t nFold = GetFold();
	AutoPtr<Matrix> pMatRtn(new Matrix(nCols, nRows));
	ValueList &valList = pMatRtn->GetList();
	for (size_t iCol = 0; iCol < nCols; iCol++) {
		ValueList::const_iterator pValueElem = GetPointer(0, iCol);
		size_t offset = 0;
		for (size_t iRow = 0; iRow < nRows; iRow++, offset += nFold) {
			valList.push_back(*(pValueElem + offset));
		}
	}
	return Value(new Object_matrix(env, pMatRtn.release()));
}

Value Matrix::Invert(Environment &env, Signal sig)
{
	size_t nCols = GetCols(), nRows = GetRows();
	if (nCols != nRows) {
		sig.SetError(ERR_ValueError, "inversion can only be applied to square matrix");
		return Value::Null;
	}
	ValueType valType = CheckValueType(*this);
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
		AutoPtr<Matrix> pMatRtn(new Matrix(nCols, nRows));
		ValueList &valList = pMatRtn->GetList();
		size_t offset = nCols;
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			for (size_t iCol = 0; iCol < nCols; iCol++, offset++) {
				valList.push_back(mat[offset]);
			}
			offset += nCols;
		}
		return Value(new Object_matrix(env, pMatRtn.release()));
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
		AutoPtr<Matrix> pMatRtn(new Matrix(nCols, nRows));
		ValueList &valList = pMatRtn->GetList();
		size_t offset = nCols;
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			for (size_t iCol = 0; iCol < nCols; iCol++, offset++) {
				valList.push_back(mat[offset]);
			}
			offset += nCols;
		}
		return Value(new Object_matrix(env, pMatRtn.release()));
	} else {
		sig.SetError(ERR_ValueError, "failed to calculate inverted matrix");
		return Value::Null;
	}
}

bool Matrix::GetElemIndex(Environment &env, Signal sig,
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

Value Matrix::OperatorNeg(Environment &env, Signal sig, const Matrix *pMat)
{
	size_t nRows = pMat->GetRows(), nCols = pMat->GetCols();
	AutoPtr<Matrix> pMatRtn(new Matrix(nRows, nCols));
	ValueList &valList = pMatRtn->GetList();
	ValueType valType = CheckValueType(*pMat);
	if (valType == VTYPE_number) {
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = pMat->GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
				valList.push_back(Value(-pValueElem->GetNumber()));
			}
		}
	} else if (valType == VTYPE_complex) {
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = pMat->GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
				valList.push_back(Value(-pValueElem->GetComplex()));
			}
		}
	} else {
		const Function *pFunc = env.GetOpFunc(OPTYPE_Neg);
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = pMat->GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
				ValueList valListArg(*pValueElem);
				Args args(valListArg);
				valList.push_back(pFunc->Eval(env, sig, args));
				if (sig.IsSignalled()) return Value::Null;
			}
		}
	}
	return Value(new Object_matrix(env, pMatRtn.release()));
}

Value Matrix::OperatorPlusMinus(Environment &env, Signal sig, OpType opType,
				const Matrix *pMat1, const Matrix *pMat2)
{
	size_t nRows = pMat1->GetRows(), nCols = pMat1->GetCols();
	if (!(nRows == pMat2->GetRows() && nCols == pMat2->GetCols())) {
		SetError_MatrixSizeMismatch(sig);
		return Value::Null;
	}
	AutoPtr<Matrix> pMatRtn(new Matrix(nRows, nCols));
	ValueList &valList = pMatRtn->GetList();
	ValueType valType1 = CheckValueType(*pMat1);
	ValueType valType2 = CheckValueType(*pMat2);
	if (valType1 == VTYPE_number && valType2 == VTYPE_number) {
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem1 = pMat1->GetPointer(iRow, 0);
			ValueList::const_iterator pValueElem2 = pMat2->GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem1++, pValueElem2++) {
				Number num = (opType == OPTYPE_Plus)?
						pValueElem1->GetNumber() + pValueElem2->GetNumber() :
						pValueElem1->GetNumber() - pValueElem2->GetNumber();
				valList.push_back(Value(num));
			}
		}
	} else if ((valType1 == VTYPE_complex || valType1 == VTYPE_number) &&
				(valType2 == VTYPE_complex || valType2 == VTYPE_number)) {
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem1 = pMat1->GetPointer(iRow, 0);
			ValueList::const_iterator pValueElem2 = pMat2->GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem1++, pValueElem2++) {
				Complex num = (opType == OPTYPE_Plus)?
						pValueElem1->GetComplex() + pValueElem2->GetComplex() :
						pValueElem1->GetComplex() - pValueElem2->GetComplex();
				valList.push_back(Value(num));
			}
		}
	} else {
		const Function *pFunc = env.GetOpFunc(opType);
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem1 = pMat1->GetPointer(iRow, 0);
			ValueList::const_iterator pValueElem2 = pMat2->GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem1++, pValueElem2++) {
				ValueList valListArg(*pValueElem1, *pValueElem2);
				Args args(valListArg);
				valList.push_back(pFunc->Eval(env, sig, args));
				if (sig.IsSignalled()) return Value::Null;
			}
		}
	}
	return Value(new Object_matrix(env, pMatRtn.release()));
}

Value Matrix::OperatorMultiply(Environment &env, Signal sig,
				const Matrix *pMat1, const Matrix *pMat2)
{
	size_t nRows = pMat1->GetRows(), nCols = pMat2->GetCols();
	size_t nElems = pMat1->GetCols();
	size_t nFold = pMat2->GetFold();
	if (nElems != pMat2->GetRows()) {
		SetError_MatrixSizeMismatch(sig);
		return Value::Null;
	}
	AutoPtr<Matrix> pMatRtn(new Matrix(nRows, nCols));
	ValueList &valList = pMatRtn->GetList();
	ValueType valType1 = CheckValueType(*pMat1);
	ValueType valType2 = CheckValueType(*pMat2);
	if (valType1 == VTYPE_number && valType2 == VTYPE_number) {
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			for (size_t iCol = 0; iCol < nCols; iCol++) {
				ValueList::const_iterator pValueElem1 = pMat1->GetPointer(iRow, 0);
				ValueList::const_iterator pValueElem2 = pMat2->GetPointer(0, iCol);
				Number numAccum = 0;
				size_t offset = 0;
				for (size_t iElem = 0; iElem < nElems;
										iElem++, pValueElem1++, offset += nFold) {
					numAccum += pValueElem1->GetNumber() *
										(pValueElem2 + offset)->GetNumber();
				}
				valList.push_back(Value(numAccum));
			}
		}
	} else if ((valType1 == VTYPE_complex || valType1 == VTYPE_number) &&
				(valType2 == VTYPE_complex || valType2 == VTYPE_number)) {
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			for (size_t iCol = 0; iCol < nCols; iCol++) {
				ValueList::const_iterator pValueElem1 = pMat1->GetPointer(iRow, 0);
				ValueList::const_iterator pValueElem2 = pMat2->GetPointer(0, iCol);
				Complex numAccum = 0;
				size_t offset = 0;
				for (size_t iElem = 0; iElem < nElems;
										iElem++, pValueElem1++, offset += nFold) {
					numAccum += pValueElem1->GetComplex() *
										(pValueElem2 + offset)->GetComplex();
				}
				valList.push_back(Value(numAccum));
			}
		}
	} else {
		const Function *pFuncMultiply = env.GetOpFunc(OPTYPE_Multiply);
		const Function *pFuncPlus = env.GetOpFunc(OPTYPE_Plus);
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			for (size_t iCol = 0; iCol < nCols; iCol++) {
				ValueList::const_iterator pValueElem1 = pMat1->GetPointer(iRow, 0);
				ValueList::const_iterator pValueElem2 = pMat2->GetPointer(0, iCol);
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
	}
	return Value(new Object_matrix(env, pMatRtn.release()));
}

Value Matrix::OperatorMultiply(Environment &env, Signal sig,
							const Matrix *pMat, const ValueList &valList)
{
	size_t nRows = pMat->GetRows(), nCols = pMat->GetCols();
	if (nCols != valList.size()) {
		SetError_MatrixSizeMismatch(sig);
		return Value::Null;
	}
	Value result;
	ValueList &valListResult = result.InitAsList(env);
	valListResult.reserve(nRows);
	ValueType valType1 = CheckValueType(*pMat);
	ValueType valType2 = CheckValueType(valList);
	if (valType1 == VTYPE_number && valType2 == VTYPE_number) {
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = pMat->GetPointer(iRow, 0);
			Number numAccum = 0;
			foreach_const (ValueList, pValue, valList) {
				numAccum += pValueElem->GetNumber() * pValue->GetNumber();
				pValueElem++;
			}
			valListResult.push_back(Value(numAccum));
		}
	} else if ((valType1 == VTYPE_complex || valType1 == VTYPE_number) &&
				(valType2 == VTYPE_complex || valType2 == VTYPE_number)) {
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = pMat->GetPointer(iRow, 0);
			Complex numAccum = 0;
			foreach_const (ValueList, pValue, valList) {
				numAccum += pValueElem->GetComplex() * pValue->GetComplex();
				pValueElem++;
			}
			valListResult.push_back(Value(numAccum));
		}
	} else {
		const Function *pFuncMultiply = env.GetOpFunc(OPTYPE_Multiply);
		const Function *pFuncPlus = env.GetOpFunc(OPTYPE_Plus);
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = pMat->GetPointer(iRow, 0);
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
	}
	if (valListResult.size() == 1) return valListResult.front();
	return result;
}

Value Matrix::OperatorMultiply(Environment &env, Signal sig,
							const Matrix *pMat, const Value &value)
{
	size_t nRows = pMat->GetRows(), nCols = pMat->GetCols();
	AutoPtr<Matrix> pMatRtn(new Matrix(nRows, nCols));
	ValueList &valListResult = pMatRtn->GetList();
	ValueType valType1 = CheckValueType(*pMat);
	ValueType valType2 = value.GetType();
	if (valType1 == VTYPE_number && valType2 == VTYPE_number) {
		Number num = value.GetNumber();
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = pMat->GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
				valListResult.push_back(Value(pValueElem->GetNumber() * num));
			}
		}
	} else if ((valType1 == VTYPE_complex || valType1 == VTYPE_number) &&
				(valType2 == VTYPE_complex || valType2 == VTYPE_number)) {
		Complex num = value.GetComplex();
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = pMat->GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
				valListResult.push_back(Value(pValueElem->GetComplex() * num));
			}
		}
	} else {
		const Function *pFunc = env.GetOpFunc(OPTYPE_Multiply);
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = pMat->GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
				ValueList valListArg(*pValueElem, value);
				Args args(valListArg);
				Value resultElem = pFunc->Eval(env, sig, args);
				if (sig.IsSignalled()) return Value::Null;
				valListResult.push_back(resultElem);
			}
		}
	}
	if (valListResult.size() == 1) return valListResult.front();
	return Value(new Object_matrix(env, pMatRtn.release()));
}

Value Matrix::OperatorMultiply(Environment &env, Signal sig,
							const ValueList &valList, const Matrix *pMat)
{
	size_t nRows = pMat->GetRows(), nCols = pMat->GetCols();
	size_t nFold = pMat->GetFold();
	if (nRows != valList.size()) {
		SetError_MatrixSizeMismatch(sig);
		return Value::Null;
	}
	Value result;
	ValueList &valListResult = result.InitAsList(env);
	valListResult.reserve(nCols);
	ValueType valType1 = CheckValueType(valList);
	ValueType valType2 = CheckValueType(*pMat);
	if (valType1 == VTYPE_number && valType2 == VTYPE_number) {
		for (size_t iCol = 0; iCol < nCols; iCol++) {
			ValueList::const_iterator pValueElem = pMat->GetPointer(0, iCol);
			Number numAccum = 0;
			size_t offset = 0;
			foreach_const (ValueList, pValue, valList) {
				numAccum += (pValueElem + offset)->GetNumber() * pValue->GetNumber();
				offset += nFold;
			}
			valListResult.push_back(Value(numAccum));
		}
	} else if ((valType1 == VTYPE_complex || valType1 == VTYPE_number) &&
				(valType2 == VTYPE_complex || valType2 == VTYPE_number)) {
		for (size_t iCol = 0; iCol < nCols; iCol++) {
			ValueList::const_iterator pValueElem = pMat->GetPointer(0, iCol);
			Complex numAccum = 0;
			size_t offset = 0;
			foreach_const (ValueList, pValue, valList) {
				numAccum += (pValueElem + offset)->GetComplex() * pValue->GetComplex();
				offset += nFold;
			}
			valListResult.push_back(Value(numAccum));
		}
	} else {
		const Function *pFuncMultiply = env.GetOpFunc(OPTYPE_Multiply);
		const Function *pFuncPlus = env.GetOpFunc(OPTYPE_Plus);
		for (size_t iCol = 0; iCol < nCols; iCol++) {
			ValueList::const_iterator pValueElem = pMat->GetPointer(0, iCol);
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
	}
	if (valListResult.size() == 1) return valListResult.front();
	return result;
}

Value Matrix::OperatorMultiply(Environment &env, Signal sig,
							const Value &value, const Matrix *pMat)
{
	size_t nRows = pMat->GetRows(), nCols = pMat->GetCols();
	size_t nFold = pMat->GetFold();
	AutoPtr<Matrix> pMatRtn(new Matrix(nRows, nCols));
	ValueList &valListResult = pMatRtn->GetList();
	ValueType valType1 = value.GetType();
	ValueType valType2 = CheckValueType(*pMat);
	if (valType1 == VTYPE_number && valType2 == VTYPE_number) {
		Number num = value.GetNumber();
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = pMat->GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
				valListResult.push_back(Value(num * pValueElem->GetNumber()));
			}
		}
	} else if ((valType1 == VTYPE_complex || valType1 == VTYPE_number) &&
				(valType2 == VTYPE_complex || valType2 == VTYPE_number)) {
		Complex num = value.GetComplex();
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = pMat->GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
				valListResult.push_back(Value(num * pValueElem->GetComplex()));
			}
		}
	} else {
		const Function *pFunc = env.GetOpFunc(OPTYPE_Multiply);
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = pMat->GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
				ValueList valListArg(value, *pValueElem);
				Args args(valListArg);
				Value resultElem = pFunc->Eval(env, sig, args);
				if (sig.IsSignalled()) return Value::Null;
				valListResult.push_back(resultElem);
			}
		}
	}
	if (valListResult.size() == 1) return valListResult.front();
	return Value(new Object_matrix(env, pMatRtn.release()));
}

Value Matrix::OperatorDivide(Environment &env, Signal sig,
							const Matrix *pMat, const Value &value)
{
	size_t nRows = pMat->GetRows(), nCols = pMat->GetCols();
	AutoPtr<Matrix> pMatRtn(new Matrix(nRows, nCols));
	ValueList &valList = pMatRtn->GetList();
	ValueType valType1 = CheckValueType(*pMat);
	ValueType valType2 = value.GetType();
	if (valType1 == VTYPE_number && valType2 == VTYPE_number) {
		Number num = value.GetNumber();
		if (num == 0) {
			sig.SetError(ERR_ZeroDivisionError, "divide by zero");
			return Value::Null;
		}
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = pMat->GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
				valList.push_back(Value(pValueElem->GetNumber() / num));
			}
		}
	} else if ((valType1 == VTYPE_complex || valType1 == VTYPE_number) &&
				(valType2 == VTYPE_complex || valType2 == VTYPE_number)) {
		Complex num = value.GetComplex();
		if (num.IsZero()) {
			sig.SetError(ERR_ZeroDivisionError, "divide by zero");
			return Value::Null;
		}
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = pMat->GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
				valList.push_back(Value(pValueElem->GetComplex() / num));
			}
		}
	} else {
		const Function *pFunc = env.GetOpFunc(OPTYPE_Divide);
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			ValueList::const_iterator pValueElem = pMat->GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < nCols; iCol++, pValueElem++) {
				ValueList valListArg(*pValueElem, value);
				Args args(valListArg);
				valList.push_back(pFunc->Eval(env, sig, args));
				if (sig.IsSignalled()) return Value::Null;
			}
		}
	}
	return Value(new Object_matrix(env, pMatRtn.release()));
}

ValueType Matrix::CheckValueType(const ValueList &valList)
{
	ValueType valType = VTYPE_nil;
	foreach_const (ValueList, pValueElem, valList) {
		if (pValueElem->IsNumber()) {
			if (valType == VTYPE_nil) valType = VTYPE_number;
		} else if (pValueElem->IsComplex()) {
			valType = VTYPE_complex;
		} else {
			return VTYPE_nil;
		}
	}
	return valType;
}

ValueType Matrix::CheckValueType(const Matrix &mat)
{
	return CheckValueType(mat.GetElements()->GetList());
}

void Matrix::SetError_MatrixSizeMismatch(Signal sig)
{
	sig.SetError(ERR_ValueError, "matrix size mismatches");
}

void Matrix::SetError_IndexOutOfRange(Signal sig)
{
	sig.SetError(ERR_IndexError, "index is out of range");
}

//-----------------------------------------------------------------------------
// Matrix::IteratorEach
//-----------------------------------------------------------------------------
Matrix::IteratorEach::~IteratorEach()
{
}

Iterator *Matrix::IteratorEach::GetSource()
{
	return NULL;
}

bool Matrix::IteratorEach::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_transposeFlag) {
		if (_iCol >= _pMat->GetCols()) return false;
		value = *_pMat->GetPointer(_iRow, _iCol);
		_iRow++;
		if (_iRow >= _pMat->GetRows()) {
			_iRow = 0, _iCol++;
		}
	} else {
		if (_iRow >= _pMat->GetRows()) return false;
		value = *_pMat->GetPointer(_iRow, _iCol);
		_iCol++;
		if (_iCol >= _pMat->GetCols()) {
			_iCol = 0, _iRow++;
		}
	}
	return true;
}

String Matrix::IteratorEach::ToString(Signal sig) const
{
	return String("<iterator:matrix#each>");
}

void Matrix::IteratorEach::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Matrix::IteratorEachRow
//-----------------------------------------------------------------------------
Matrix::IteratorEachRow::~IteratorEachRow()
{
}

Iterator *Matrix::IteratorEachRow::GetSource()
{
	return NULL;
}

bool Matrix::IteratorEachRow::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_iRow >= _pMat->GetRows()) return false;
	value = _pMat->GetRow(env, sig, _iRow);
	_iRow++;
	return true;
}

String Matrix::IteratorEachRow::ToString(Signal sig) const
{
	return String("<iterator:matrix#eachrow>");
}

void Matrix::IteratorEachRow::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Matrix::IteratorEachCol
//-----------------------------------------------------------------------------
Matrix::IteratorEachCol::~IteratorEachCol()
{
}

Iterator *Matrix::IteratorEachCol::GetSource()
{
	return NULL;
}

bool Matrix::IteratorEachCol::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_iCol >= _pMat->GetCols()) return false;
	value = _pMat->GetCol(env, sig, _iCol);
	_iCol++;
	return true;
}

String Matrix::IteratorEachCol::ToString(Signal sig) const
{
	return String("<iterator:matrix#eachcol>");
}

void Matrix::IteratorEachCol::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

}
