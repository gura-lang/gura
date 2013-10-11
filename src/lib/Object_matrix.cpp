//
// Object_matrix
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_matrix
//-----------------------------------------------------------------------------
Object_matrix::Object_matrix(Environment &env, Matrix *pMat) :
						Object(env.LookupClass(VTYPE_matrix)), _pMat(pMat)
{
}

Object_matrix::Object_matrix(const Object_matrix &obj) :
						Object(obj), _pMat(new Matrix(*obj._pMat))
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
	if (_pMat->GetIndexForColFlag()) {
		sig.SetError(ERR_IndexError, "only one empty index should be applied");
		return Value::Null;
	}
	AutoPtr<Matrix> pMat(new Matrix(
				Matrix::Elements::Reference(_pMat->GetElements()),
				_pMat->GetRowOff(), _pMat->GetColOff(),
				_pMat->GetRows(), _pMat->GetCols(), _pMat->GetFold(), true));
	return Value(new Object_matrix(env, pMat.release()));
}

Value Object_matrix::IndexGet(Environment &env, Signal sig, const Value &valueIdx)
{
	if (!valueIdx.IsNumber()) {
		sig.SetError(ERR_IndexError, "index must be a number for list");
		return Value::Null;
	}
	size_t idx = valueIdx.GetSizeT();
	if (_pMat->GetIndexForColFlag()) {
		if (_pMat->GetCols() == 1) {
			if (idx >= _pMat->GetRows()) {
				Matrix::SetError_IndexOutOfRange(sig);
				return Value::Null;
			}
			return *_pMat->GetPointer(idx, 0);
		} else {
			if (idx >= _pMat->GetCols()) {
				Matrix::SetError_IndexOutOfRange(sig);
				return Value::Null;
			}
			if (_pMat->GetRows() == 1) {
				return *_pMat->GetPointer(0, idx);
			} else {
				return _pMat->GetSub(env, 0, idx, _pMat->GetRows(), 1);
			}
		}
	} else {
		if (_pMat->GetRows() == 1) {
			if (idx >= _pMat->GetCols()) {
				Matrix::SetError_IndexOutOfRange(sig);
				return Value::Null;
			}
			return *_pMat->GetPointer(0, idx);
		} else {
			if (idx >= _pMat->GetRows()) {
				Matrix::SetError_IndexOutOfRange(sig);
				return Value::Null;
			}
			if (_pMat->GetCols() == 1) {
				return *_pMat->GetPointer(idx, 0);
			} else {
				return _pMat->GetSub(env, idx, 0, 1, _pMat->GetCols());
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
	if (_pMat->GetRows() == 1) {
		if (idx >= _pMat->GetCols()) {
			Matrix::SetError_IndexOutOfRange(sig);
			return;
		}
		*_pMat->GetPointer(0, idx) = value;
	} else {
		if (idx >= _pMat->GetRows()) {
			Matrix::SetError_IndexOutOfRange(sig);
			return;
		}
		if (_pMat->GetCols() == 1) {
			*_pMat->GetPointer(idx, 0) = value;
		} else if (value.IsMatrix()) {
			
			// todo
			
		} else {
			AutoPtr<Iterator> pIterator((value.IsList() || value.IsIterator())?
					value.CreateIterator(sig) : new Iterator_Constant(value));
			if (sig.IsSignalled()) return;
			_pMat->SetRow(env, sig, idx, *pIterator);
		}
	}
}

String Object_matrix::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	if (_pMat->GetRows() == 1 && _pMat->GetCols() == 1) {
		ValueList::const_iterator pValueElem = _pMat->GetPointer(0, 0);
		rtn += pValueElem->ToString(sig, exprFlag);
	} else if (_pMat->GetCols() == 1) {
		rtn += "@@{";
		ValueList::const_iterator pValueElem = _pMat->GetPointer(0, 0);
		size_t offset = 0;
		for (size_t iRow = 0; iRow < _pMat->GetRows(); iRow++, offset += _pMat->GetFold()) {
			if (iRow > 0) rtn += ", ";
			rtn += (pValueElem + offset)->ToString(sig, exprFlag);
		}
		rtn += "}";
	} else {
		rtn += "@@{";
		for (size_t iRow = 0; iRow < _pMat->GetRows(); iRow++) {
			if (iRow > 0) rtn += ", ";
			rtn += "{";
			ValueList::const_iterator pValueElem = _pMat->GetPointer(iRow, 0);
			for (size_t iCol = 0; iCol < _pMat->GetCols(); iCol++, pValueElem++) {
				if (iCol > 0) rtn += ", ";
				rtn += pValueElem->ToString(sig, exprFlag);
			}
			rtn += "}";
		}
		rtn += "}";
	}
	return rtn;
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
	AutoPtr<Matrix> pMat(new Matrix(args.GetInt(0), args.GetInt(1),
							args.IsValid(2)? args.GetValue(2) : Value::Zero));
	return Value(new Object_matrix(env, pMat.release()));
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
	AutoPtr<Environment> pEnvLister(new Environment(&env, ENVTYPE_lister));
	//Value valueInit = pExprBlock->GetExprOwner().Exec2ForList(*pEnvLister, sig, false);
	//if (sig.IsSignalled()) return Value::Null;
	ValueList valList;
	foreach_const (ExprOwner, ppExpr, pExprBlock->GetExprOwner()) {
		Value value = (*ppExpr)->Exec2(*pEnvLister, sig);
		if (sig.IsSignalled()) {
			sig.AddExprCause(*ppExpr);
			return Value::Null;
		}
		valList.push_back(value);
	}
	size_t nRows = 0, nCols = 0;
	//ValueList &valList = valueInit.GetList();
	if (!valList.CheckMatrix(&nRows, &nCols)) {
		sig.SetError(ERR_ValueError, "invalid matrix initialization");
		return Value::Null;
	}
	AutoPtr<Matrix> pMat(new Matrix(nRows, nCols));
	ValueList &valListDst = pMat->GetList();
	foreach_const (ValueList, pValue, valList) {
		if (pValue->IsList()) {
			foreach_const (ValueList, pValueElem, pValue->GetList()) {
				valListDst.push_back(*pValueElem);
			}
		} else {
			valListDst.push_back(*pValue);
		}
	}
	return Value(new Object_matrix(env, pMat.release()));
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_matrix
//-----------------------------------------------------------------------------
// matrix.identity(n:number):static:map {block?}
Gura_DeclareClassMethod(matrix, identity)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(matrix, identity)
{
	AutoPtr<Matrix> pMat(Matrix::CreateIdentity(args.GetInt(0)));
	return ReturnValue(env, sig, args, Value(new Object_matrix(env, pMat.release())));
}

// matrix.rotation(angle:number, tx?:number, ty?:number):static:map:[deg] {block?}
Gura_DeclareClassMethod(matrix, rotation)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number);
	DeclareArg(env, "tx", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ty", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
}


Gura_ImplementClassMethod(matrix, rotation)
{
	double angle = args.GetDouble(0);
	bool transFlag = false;
	double xTrans = 0;
	double yTrans = 0;
	if (args.IsNumber(1)) {
		transFlag = true;
		xTrans = args.GetDouble(1);
	}
	if (args.IsNumber(2)) {
		transFlag = true;
		yTrans = args.GetDouble(2);
	}
	if (args.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<Matrix> pMat(Matrix::CreateRotation(angle, transFlag, xTrans, yTrans));
	return ReturnValue(env, sig, args, Value(new Object_matrix(env, pMat.release())));
}

// matrix.rotation_x(angle:number, tx?:number, ty?:number, tz?:number):static:map:[deg] {block?}
Gura_DeclareClassMethod(matrix, rotation_x)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number);
	DeclareArg(env, "tx", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ty", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "tz", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(matrix, rotation_x)
{
	double angle = args.GetDouble(0);
	bool transFlag = false;
	double xTrans = 0;
	double yTrans = 0;
	double zTrans = 0;
	if (args.IsNumber(1)) {
		transFlag = true;
		xTrans = args.GetDouble(1);
	}
	if (args.IsNumber(2)) {
		transFlag = true;
		yTrans = args.GetDouble(2);
	}
	if (args.IsNumber(3)) {
		transFlag = true;
		zTrans = args.GetDouble(3);
	}
	if (args.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<Matrix> pMat(Matrix::CreateRotationX(angle, transFlag, xTrans, yTrans, zTrans));
	return ReturnValue(env, sig, args, Value(new Object_matrix(env, pMat.release())));
}

// matrix.rotation_y(angle:number, tx?:number, ty?:number, tz?:number):static:map:[deg] {block?}
Gura_DeclareClassMethod(matrix, rotation_y)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number);
	DeclareArg(env, "tx", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ty", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "tz", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(matrix, rotation_y)
{
	double angle = args.GetDouble(0);
	bool transFlag = false;
	double xTrans = 0;
	double yTrans = 0;
	double zTrans = 0;
	if (args.IsNumber(1)) {
		transFlag = true;
		xTrans = args.GetDouble(1);
	}
	if (args.IsNumber(2)) {
		transFlag = true;
		yTrans = args.GetDouble(2);
	}
	if (args.IsNumber(3)) {
		transFlag = true;
		zTrans = args.GetDouble(3);
	}
	if (args.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<Matrix> pMat(Matrix::CreateRotationY(angle, transFlag, xTrans, yTrans, zTrans));
	return ReturnValue(env, sig, args, Value(new Object_matrix(env, pMat.release())));
}

// matrix.rotation_z(angle:number, tx?:number, ty?:number, tz?:number):static:map:[deg] {block?}
Gura_DeclareClassMethod(matrix, rotation_z)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number);
	DeclareArg(env, "tx", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ty", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "tz", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(matrix, rotation_z)
{
	double angle = args.GetDouble(0);
	bool transFlag = false;
	double xTrans = 0;
	double yTrans = 0;
	double zTrans = 0;
	if (args.IsNumber(1)) {
		transFlag = true;
		xTrans = args.GetDouble(1);
	}
	if (args.IsNumber(2)) {
		transFlag = true;
		yTrans = args.GetDouble(2);
	}
	if (args.IsNumber(3)) {
		transFlag = true;
		zTrans = args.GetDouble(3);
	}
	if (args.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<Matrix> pMat(Matrix::CreateRotationZ(angle, transFlag, xTrans, yTrans, zTrans));
	return ReturnValue(env, sig, args, Value(new Object_matrix(env, pMat.release())));
}

// matrix#set(value)
Gura_DeclareMethod(matrix, set)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Sets all the cells of the matrix with a specified value.");
}

Gura_ImplementMethod(matrix, set)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	AutoPtr<Iterator> pIterator((args.IsList(0) || args.IsIterator(0))?
								args.GetValue(0).CreateIterator(sig) :
								new Iterator_Constant(args.GetValue(0)));
	if (sig.IsSignalled()) return Value::Null;
	pThis->GetMatrix()->Set(env, sig, *pIterator);
	return Value::Null;
}

// matrix#setrow(row:number, value)
Gura_DeclareMethod(matrix, setrow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "row", VTYPE_number);
	DeclareArg(env, "value", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Sets cells in a selected row of the matrix with a specified value.");
}

Gura_ImplementMethod(matrix, setrow)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	AutoPtr<Iterator> pIterator((args.IsList(1) || args.IsIterator(1))?
								args.GetValue(1).CreateIterator(sig) :
								new Iterator_Constant(args.GetValue(1)));
	if (sig.IsSignalled()) return Value::Null;
	pThis->GetMatrix()->SetRow(env, sig, args.GetSizeT(0), *pIterator);
	return Value::Null;
}

// matrix#setcol(col:number, value)
Gura_DeclareMethod(matrix, setcol)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "col", VTYPE_number);
	DeclareArg(env, "value", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Sets cells in a selected column of the matrix with a specified value.");
}

Gura_ImplementMethod(matrix, setcol)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	AutoPtr<Iterator> pIterator((args.IsList(1) || args.IsIterator(1))?
								args.GetValue(1).CreateIterator(sig) :
								new Iterator_Constant(args.GetValue(1)));
	if (sig.IsSignalled()) return Value::Null;
	pThis->GetMatrix()->SetCol(env, sig, args.GetSizeT(0), *pIterator);
	return Value::Null;
}

// matrix#rowsize()
Gura_DeclareMethod(matrix, rowsize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns the matrix row size.");
}

Gura_ImplementMethod(matrix, rowsize)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	return Value(static_cast<UInt>(pThis->GetMatrix()->GetRows()));
}

// matrix#colsize()
Gura_DeclareMethod(matrix, colsize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns the matrix column size.");
}

Gura_ImplementMethod(matrix, colsize)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	return Value(static_cast<UInt>(pThis->GetMatrix()->GetCols()));
}

// matrix#issquare()
Gura_DeclareMethod(matrix, issquare)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns true if the matrix is a square one.");
}

Gura_ImplementMethod(matrix, issquare)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	return Value(pThis->GetMatrix()->GetRows() == pThis->GetMatrix()->GetCols());
}

// matrix#submat(row:number, col:number, nrows:number, ncols:number):map
Gura_DeclareMethod(matrix, submat)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number);
	DeclareArg(env, "col", VTYPE_number);
	DeclareArg(env, "nrows", VTYPE_number);
	DeclareArg(env, "ncols", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a sub matrix that refers to cells in a specified area of the matrix.\n"
	"Modification on the returned sub matrix will affect on the original one.");
}

Gura_ImplementMethod(matrix, submat)
{
	//Object_matrix *pThis = Object_matrix::GetThisObj(args);
	//return pThis->GetMatrix()->GetSub(args.GetSizeT(0), args.GetSizeT(1),
	//					args.GetSizeT(2), args.GetSizeT(3));
	return Value::Null;
}

// matrix#row(row:number):map
Gura_DeclareMethod(matrix, row)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a list of values copied from a specified row of the matrix.\n"
	"Modification on the returned sub matrix will affect on the original one.");
}

Gura_ImplementMethod(matrix, row)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	return pThis->GetMatrix()->GetRow(env, sig, args.GetSizeT(0));
}

// matrix#col(col:number):map
Gura_DeclareMethod(matrix, col)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a list of values copied from a specified column of the matrix.\n"
	"Modification on the returned sub matrix will affect on the original one.");
}

Gura_ImplementMethod(matrix, col)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	return pThis->GetMatrix()->GetCol(env, sig, args.GetSizeT(0));
}

// matrix#each():[transpose]
Gura_DeclareMethod(matrix, each)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(transpose));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns an iterator that picks up each cell by scanning the matrix.\n"
	"In default, that scan is done in a horizontal direction.\n"
	"When an attribute :transpose is specified, it's done in a vertical direction.");
}

Gura_ImplementMethod(matrix, each)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	Iterator *pIterator = new Matrix::IteratorEach(Matrix::Reference(pThis->GetMatrix()),
								args.IsSet(Gura_Symbol(transpose)));
	return ReturnIterator(env, sig, args, pIterator);
}

// matrix#eachrow()
Gura_DeclareMethod(matrix, eachrow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns an iterator that generates lists of values copied from each row\n"
	"of the matrix.\n");
}

Gura_ImplementMethod(matrix, eachrow)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	return ReturnIterator(env, sig, args,
		new Matrix::IteratorEachRow(Matrix::Reference(pThis->GetMatrix())));
}

// matrix#eachcol()
Gura_DeclareMethod(matrix, eachcol)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns an iterator that generates lists of values copied from each column\n"
	"of the matrix.\n");
}

Gura_ImplementMethod(matrix, eachcol)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	return ReturnIterator(env, sig, args,
		new Matrix::IteratorEachCol(Matrix::Reference(pThis->GetMatrix())));
}

// matrix#tolist():[transpose,flat]
Gura_DeclareMethod(matrix, tolist)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(transpose));
	DeclareAttr(Gura_Symbol(flat));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
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
	pThis->GetMatrix()->ToList(env, valList,
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a matrix with values that have been rounded off.");
}

Gura_ImplementMethod(matrix, roundoff)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	if (sig.IsSignalled()) return Value::Null;
	return pThis->GetMatrix()->RoundOff(env, sig, args.GetNumber(0));
}

// matrix#transpose()
Gura_DeclareMethod(matrix, transpose)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a transpose matrix.");
}

Gura_ImplementMethod(matrix, transpose)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	if (sig.IsSignalled()) return Value::Null;
	return pThis->GetMatrix()->Transpose(env, sig);
}

// matrix#invert()
Gura_DeclareMethod(matrix, invert)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns an inverted matrix.");
}

Gura_ImplementMethod(matrix, invert)
{
	Object_matrix *pThis = Object_matrix::GetThisObj(args);
	if (sig.IsSignalled()) return Value::Null;
	return pThis->GetMatrix()->Invert(env, sig);
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_matrix::Class_matrix(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_matrix)
{
}

void Class_matrix::Prepare(Environment &env)
{
	Gura_AssignFunction(matrix);
	Gura_AssignFunctionEx(MatrixInit, "@@");
	Gura_AssignMethod(matrix, identity);
	Gura_AssignMethod(matrix, rotation);
	Gura_AssignMethod(matrix, rotation_x);
	Gura_AssignMethod(matrix, rotation_y);
	Gura_AssignMethod(matrix, rotation_z);
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
	Object_matrix *pObj = Object_matrix::GetObject(value);
	Matrix *pMat = pObj->GetMatrix();
	if (!pMat->GetList().Serialize(env, sig, stream)) return false;
	if (!stream.SerializePackedULong(sig, static_cast<ULong>(pMat->GetRowOff()))) return false;
	if (!stream.SerializePackedULong(sig, static_cast<ULong>(pMat->GetColOff()))) return false;
	if (!stream.SerializePackedULong(sig, static_cast<ULong>(pMat->GetRows()))) return false;
	if (!stream.SerializePackedULong(sig, static_cast<ULong>(pMat->GetCols()))) return false;
	if (!stream.SerializePackedULong(sig, static_cast<ULong>(pMat->GetFold()))) return false;
	if (!stream.SerializeBoolean(sig, pMat->GetIndexForColFlag())) return false;
	return true;
}

bool Class_matrix::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	AutoPtr<Matrix::Elements> pElements(new Matrix::Elements());
	if (!pElements->GetList().Deserialize(env, sig, stream)) return false;
	ULong iRowOff = 0, iColOff = 0;
	ULong nRows = 0, nCols = 0;
	ULong nFold = 0;
	bool indexForColFlag = false;
	if (!stream.DeserializePackedULong(sig, iRowOff)) return false;
	if (!stream.DeserializePackedULong(sig, iColOff)) return false;
	if (!stream.DeserializePackedULong(sig, nRows)) return false;
	if (!stream.DeserializePackedULong(sig, nCols)) return false;
	if (!stream.DeserializePackedULong(sig, nFold)) return false;
	if (!stream.DeserializeBoolean(sig, indexForColFlag)) return false;
	ULong nElems = static_cast<ULong>(pElements->GetList().size());
	//::printf("%d %d %d %d %d %d\n", nElems, iRowOff, iColOff, nRows, nCols, nFold);
	if (nFold * nRows > nElems || iColOff + nCols > nFold) {
		sig.SetError(ERR_ValueError, "invalid parameter for matrix");
		return false;
	}
	AutoPtr<Matrix> pMat(new Matrix(pElements.release(),
			static_cast<size_t>(iRowOff), static_cast<size_t>(iColOff),
			static_cast<size_t>(nRows), static_cast<size_t>(nCols),
			static_cast<size_t>(nFold), indexForColFlag));
	return true;
}

Object *Class_matrix::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	return NULL;
}

}
