//=============================================================================
// Gura class: matrix
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

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

Value Object_matrix::EmptyIndexGet(Environment &env)
{
	Signal &sig = GetSignal();
	if (_pMat->GetIndexForColFlag()) {
		sig.SetError(ERR_IndexError, "only one empty index should be applied");
		return Value::Nil;
	}
	AutoPtr<Matrix> pMat(new Matrix(
				 _pMat->GetElements().Reference(),
				_pMat->GetRowOff(), _pMat->GetColOff(),
				_pMat->GetRows(), _pMat->GetCols(), _pMat->GetFold(), true));
	return Value(new Object_matrix(env, pMat.release()));
}

Value Object_matrix::IndexGet(Environment &env, const Value &valueIdx)
{
	Signal &sig = GetSignal();
	if (!valueIdx.Is_number()) {
		sig.SetError(ERR_IndexError, "index must be a number for list");
		return Value::Nil;
	}
	size_t idx = valueIdx.GetSizeT();
	if (_pMat->GetIndexForColFlag()) {
		if (_pMat->GetCols() == 1) {
			if (idx >= _pMat->GetRows()) {
				Matrix::SetError_IndexOutOfRange(sig);
				return Value::Nil;
			}
			return *_pMat->GetPointer(idx, 0);
		} else {
			if (idx >= _pMat->GetCols()) {
				Matrix::SetError_IndexOutOfRange(sig);
				return Value::Nil;
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
				return Value::Nil;
			}
			return *_pMat->GetPointer(0, idx);
		} else {
			if (idx >= _pMat->GetRows()) {
				Matrix::SetError_IndexOutOfRange(sig);
				return Value::Nil;
			}
			if (_pMat->GetCols() == 1) {
				return *_pMat->GetPointer(idx, 0);
			} else {
				return _pMat->GetSub(env, idx, 0, 1, _pMat->GetCols());
			}
		}
	}
}

void Object_matrix::IndexSet(Environment &env, const Value &valueIdx, const Value &value)
{
	Signal &sig = GetSignal();
	if (!valueIdx.Is_number()) {
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
		} else if (value.Is_matrix()) {
			
			// todo
			
		} else {
			AutoPtr<Iterator> pIterator((value.Is_list() || value.Is_iterator())?
					value.CreateIterator(sig) : new Iterator_Constant(value));
			if (sig.IsSignalled()) return;
			_pMat->SetRow(env, idx, *pIterator);
		}
	}
}

String Object_matrix::ToString(bool exprFlag)
{
	String rtn;
	if (_pMat->GetRows() == 1 && _pMat->GetCols() == 1) {
		ValueList::const_iterator pValueElem = _pMat->GetPointer(0, 0);
		rtn += pValueElem->ToString(exprFlag);
	} else if (_pMat->GetCols() == 1) {
		rtn += "@@{";
		ValueList::const_iterator pValueElem = _pMat->GetPointer(0, 0);
		size_t offset = 0;
		for (size_t iRow = 0; iRow < _pMat->GetRows(); iRow++, offset += _pMat->GetFold()) {
			if (iRow > 0) rtn += ", ";
			rtn += (pValueElem + offset)->ToString(exprFlag);
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
				rtn += pValueElem->ToString(exprFlag);
			}
			rtn += "}";
		}
		rtn += "}";
	}
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// matrix(nrows:number, ncols:number, value?) {block?}
Gura_DeclareFunction(matrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "nrows", VTYPE_number);
	DeclareArg(env, "ncols", VTYPE_number);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_matrix));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `matrix` instance that has specified rows and columns.\n"
		"\n"
		"The content of the content will be initialized with `value`.\n"
		"If omitted, it will be initialized with zero value.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("mat", "matrix"));
}

Gura_ImplementFunction(matrix)
{
	AutoPtr<Matrix> pMat(new Matrix(arg.GetInt(0), arg.GetInt(1),
							arg.IsValid(2)? arg.GetValue(2) : Value::Zero));
	return Value(new Object_matrix(env, pMat.release()));
}

// @@ {block}
Gura_DeclareFunction(MatrixInit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en),
		"Creates a `matrix` instance and initializes its content with values listed in `block`.\n"
		"\n"
		"The `block` must contain a one- or two-dimentional list.\n"
		"\n"
		"Below is an example to create a matrix with 3 rows and 4 columns.\n"
		"\n"
		"    @@{{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}}\n"
		"\n"
		"Below is an example to create a matrix with 4 rows and 1 column.\n"
		"\n"
		"    @@{1, 2, 3, 4}\n");
}

Gura_ImplementFunction(MatrixInit)
{
	Signal &sig = env.GetSignal();
	const Expr_Block *pExprBlock = arg.GetBlockCooked(env);
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<Environment> pEnvLister(env.Derive(ENVTYPE_lister));
	ValueList valList;
	foreach_const (ExprOwner, ppExpr, pExprBlock->GetExprOwner()) {
		Value value = (*ppExpr)->Exec(*pEnvLister);
		if (sig.IsSignalled()) {
			sig.AddExprCause(*ppExpr);
			return Value::Nil;
		}
		valList.push_back(value);
	}
	size_t nRows = 0, nCols = 0;
	if (!valList.CheckMatrix(&nRows, &nCols)) {
		sig.SetError(ERR_ValueError, "invalid matrix initialization");
		return Value::Nil;
	}
	AutoPtr<Matrix> pMat(new Matrix(nRows, nCols));
	Matrix::Elements &elementsDst = pMat->GetElements();
	foreach_const (ValueList, pValue, valList) {
		if (pValue->Is_list()) {
			foreach_const (ValueList, pValueElem, pValue->GetList()) {
				elementsDst.push_back(*pValueElem);
			}
		} else {
			elementsDst.push_back(*pValue);
		}
	}
	return Value(new Object_matrix(env, pMat.release()));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// matrix#col(col:number):map
Gura_DeclareMethod(matrix, col)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), 
		"Returns a list of values copied from a specified column of the matrix.\n"
		"Modification on the returned sub matrix will affect on the original one.");
}

Gura_ImplementMethod(matrix, col)
{
	Object_matrix *pThis = Object_matrix::GetObjectThis(arg);
	return pThis->GetMatrix()->GetCol(env, arg.GetSizeT(0));
}

// matrix#colsize()
Gura_DeclareMethod(matrix, colsize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns the matrix column size.");
}

Gura_ImplementMethod(matrix, colsize)
{
	Object_matrix *pThis = Object_matrix::GetObjectThis(arg);
	return Value(static_cast<UInt>(pThis->GetMatrix()->GetCols()));
}

// matrix.dot(a, b):static {block?}
Gura_DeclareClassMethod(matrix, dot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "a", VTYPE_any);
	DeclareArg(env, "b", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementClassMethod(matrix, dot)
{
	if (arg.Is_matrix(0) && arg.Is_matrix(1)) {
		return Matrix::InnerProduct(
			env,
			Object_matrix::GetObject(arg, 0)->GetMatrix(),
			Object_matrix::GetObject(arg, 1)->GetMatrix());
	} else if (arg.Is_matrix(0) && arg.Is_list(1)) {
		return Matrix::InnerProduct(
			env,
			Object_matrix::GetObject(arg, 0)->GetMatrix(),
			arg.GetList(1));
	} else if (arg.Is_list(0) && arg.Is_matrix(1)) {
		return Matrix::InnerProduct(
			env,
			arg.GetList(0),
			Object_matrix::GetObject(arg, 1)->GetMatrix());
	}
	Declaration::SetError_InvalidArgument(env);
	return Value::Nil;
}

// matrix#each():[transpose]
Gura_DeclareMethod(matrix, each)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(transpose));
	AddHelp(
		Gura_Symbol(en), 
		"Returns an iterator that picks up each cell by scanning the matrix.\n"
		"In default, that scan is done in a horizontal direction.\n"
		"When an attribute :transpose is specified, it's done in a vertical direction.");
}

Gura_ImplementMethod(matrix, each)
{
	Object_matrix *pThis = Object_matrix::GetObjectThis(arg);
	Iterator *pIterator = new Matrix::IteratorEach(Matrix::Reference(pThis->GetMatrix()),
								arg.IsSet(Gura_Symbol(transpose)));
	return ReturnIterator(env, arg, pIterator);
}

// matrix#eachcol()
Gura_DeclareMethod(matrix, eachcol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), 
		"Returns an iterator that generates lists of values copied from each column\n"
		"of the matrix.\n");
}

Gura_ImplementMethod(matrix, eachcol)
{
	Object_matrix *pThis = Object_matrix::GetObjectThis(arg);
	return ReturnIterator(env, arg,
		new Matrix::IteratorEachCol(Matrix::Reference(pThis->GetMatrix())));
}

// matrix#eachrow()
Gura_DeclareMethod(matrix, eachrow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), 
		"Returns an iterator that generates lists of values copied from each row\n"
		"of the matrix.\n");
}

Gura_ImplementMethod(matrix, eachrow)
{
	Object_matrix *pThis = Object_matrix::GetObjectThis(arg);
	return ReturnIterator(env, arg,
		new Matrix::IteratorEachRow(Matrix::Reference(pThis->GetMatrix())));
}

// matrix.identity(n:number):static:map {block?}
Gura_DeclareClassMethod(matrix, identity)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementClassMethod(matrix, identity)
{
	AutoPtr<Matrix> pMat(Matrix::CreateIdentity(arg.GetInt(0)));
	return ReturnValue(env, arg, Value(new Object_matrix(env, pMat.release())));
}

// matrix#invert()
Gura_DeclareMethod(matrix, invert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns an inverted matrix.");
}

Gura_ImplementMethod(matrix, invert)
{
	Signal &sig = env.GetSignal();
	Object_matrix *pThis = Object_matrix::GetObjectThis(arg);
	if (sig.IsSignalled()) return Value::Nil;
	return pThis->GetMatrix()->Invert(env);
}

// matrix#issquare()
Gura_DeclareMethod(matrix, issquare)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns true if the matrix is a square one.");
}

Gura_ImplementMethod(matrix, issquare)
{
	Object_matrix *pThis = Object_matrix::GetObjectThis(arg);
	return Value(pThis->GetMatrix()->GetRows() == pThis->GetMatrix()->GetCols());
}

// matrix.rotation(angle:number, tx?:number, ty?:number):static:map:[deg] {block?}
Gura_DeclareClassMethod(matrix, rotation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number);
	DeclareArg(env, "tx", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ty", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a matrix that rotates a two-dimensional coordinate\n"
		"by the specified angle in radian unit.\n"
		"\n"
		"In addition to rotation, you can add translation factors by the arguments `tx` and `ty`\n"
		"that specify translation amount of x and y respectively.\n"
		"\n"
		"You can specify the angle in degree unit by appending `:deg` attribute.\n"
		"\n"
		"Below is an example to create a matrix that rotates 30 degrees.\n"
		"\n"
		"    mat = matrix.rotation(30):deg"
		"\n"
		GURA_HELPTEXT_BLOCK_en("mat", "matrix"));
}


Gura_ImplementClassMethod(matrix, rotation)
{
	double angle = arg.GetDouble(0);
	bool transFlag = false;
	double xTrans = 0;
	double yTrans = 0;
	if (arg.Is_number(1)) {
		transFlag = true;
		xTrans = arg.GetDouble(1);
	}
	if (arg.Is_number(2)) {
		transFlag = true;
		yTrans = arg.GetDouble(2);
	}
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<Matrix> pMat(Matrix::CreateRotation(angle, transFlag, xTrans, yTrans));
	return ReturnValue(env, arg, Value(new Object_matrix(env, pMat.release())));
}

// matrix.rotation@x(angle:number, tx?:number, ty?:number, tz?:number):static:map:[deg] {block?}
Gura_DeclareClassMethodAlias(matrix, rotation_x, "rotation@x")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number);
	DeclareArg(env, "tx", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ty", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "tz", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a matrix that rotates a three-dimensional coordinate around x-axis\n"
		"by the specified angle in radian unit.\n"
		"\n"
		"In addition to rotation, you can add translation factors by the arguments `tx`, `ty` and `tz`\n"
		"that specify translation amount of x, y and z respectively.\n"
		"\n"
		"You can specify the angle in degree unit by appending `:deg` attribute.\n"
		"\n"
		"Below is an example to create a matrix that rotates 30 degrees around x-axis.\n"
		"\n"
		"    mat = matrix.rotation@x(30):deg"
		"\n"
		GURA_HELPTEXT_BLOCK_en("mat", "matrix"));
}

Gura_ImplementClassMethod(matrix, rotation_x)
{
	double angle = arg.GetDouble(0);
	bool transFlag = false;
	double xTrans = 0;
	double yTrans = 0;
	double zTrans = 0;
	if (arg.Is_number(1)) {
		transFlag = true;
		xTrans = arg.GetDouble(1);
	}
	if (arg.Is_number(2)) {
		transFlag = true;
		yTrans = arg.GetDouble(2);
	}
	if (arg.Is_number(3)) {
		transFlag = true;
		zTrans = arg.GetDouble(3);
	}
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<Matrix> pMat(Matrix::CreateRotationX(angle, transFlag, xTrans, yTrans, zTrans));
	return ReturnValue(env, arg, Value(new Object_matrix(env, pMat.release())));
}

// matrix.rotation@y(angle:number, tx?:number, ty?:number, tz?:number):static:map:[deg] {block?}
Gura_DeclareClassMethodAlias(matrix, rotation_y, "rotation@y")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number);
	DeclareArg(env, "tx", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ty", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "tz", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a matrix that rotates a three-dimensional coordinate around y-axis\n"
		"by the specified angle in radian unit.\n"
		"\n"
		"In addition to rotation, you can add translation factors by the arguments `tx`, `ty` and `tz`\n"
		"that specify translation amount of x, y and z respectively.\n"
		"\n"
		"You can specify the angle in degree unit by appending `:deg` attribute.\n"
		"\n"
		"Below is an example to create a matrix that rotates 30 degrees around y-axis.\n"
		"\n"
		"    mat = matrix.rotation@y(30):deg"
		"\n"
		GURA_HELPTEXT_BLOCK_en("mat", "matrix"));
}

Gura_ImplementClassMethod(matrix, rotation_y)
{
	double angle = arg.GetDouble(0);
	bool transFlag = false;
	double xTrans = 0;
	double yTrans = 0;
	double zTrans = 0;
	if (arg.Is_number(1)) {
		transFlag = true;
		xTrans = arg.GetDouble(1);
	}
	if (arg.Is_number(2)) {
		transFlag = true;
		yTrans = arg.GetDouble(2);
	}
	if (arg.Is_number(3)) {
		transFlag = true;
		zTrans = arg.GetDouble(3);
	}
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<Matrix> pMat(Matrix::CreateRotationY(angle, transFlag, xTrans, yTrans, zTrans));
	return ReturnValue(env, arg, Value(new Object_matrix(env, pMat.release())));
}

// matrix.rotation@z(angle:number, tx?:number, ty?:number, tz?:number):static:map:[deg] {block?}
Gura_DeclareClassMethodAlias(matrix, rotation_z, "rotation@z")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number);
	DeclareArg(env, "tx", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ty", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "tz", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a matrix that rotates a three-dimensional coordinate around z-axis\n"
		"by the specified angle in radian unit.\n"
		"\n"
		"In addition to rotation, you can add translation factors by the arguments `tx`, `ty` and `tz`\n"
		"that specify translation amount of x, y and z respectively.\n"
		"\n"
		"You can specify the angle in degree unit by appending `:deg` attribute.\n"
		"\n"
		"Below is an example to create a matrix that rotates 30 degrees around z-axis.\n"
		"\n"
		"    mat = matrix.rotation@z(30):deg"
		"\n"
		GURA_HELPTEXT_BLOCK_en("mat", "matrix"));
}

Gura_ImplementClassMethod(matrix, rotation_z)
{
	double angle = arg.GetDouble(0);
	bool transFlag = false;
	double xTrans = 0;
	double yTrans = 0;
	double zTrans = 0;
	if (arg.Is_number(1)) {
		transFlag = true;
		xTrans = arg.GetDouble(1);
	}
	if (arg.Is_number(2)) {
		transFlag = true;
		yTrans = arg.GetDouble(2);
	}
	if (arg.Is_number(3)) {
		transFlag = true;
		zTrans = arg.GetDouble(3);
	}
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<Matrix> pMat(Matrix::CreateRotationZ(angle, transFlag, xTrans, yTrans, zTrans));
	return ReturnValue(env, arg, Value(new Object_matrix(env, pMat.release())));
}

// matrix#roundoff(threshold:number => 1e-10) {block?}
Gura_DeclareMethod(matrix, roundoff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once, FLAG_None, 0,
										new Expr_Value(RoundOffThreshold));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns a matrix with element values being rounded off.\n"
		"\n"
		"The argument `threshold` specifies the threshold value for the round-off.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("mat", "matrix"));
}

Gura_ImplementMethod(matrix, roundoff)
{
	Signal &sig = env.GetSignal();
	Object_matrix *pThis = Object_matrix::GetObjectThis(arg);
	Value value = pThis->GetMatrix()->RoundOff(env, arg.GetNumber(0));
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, value);
}

// matrix#row(row:number):map
Gura_DeclareMethod(matrix, row)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), 
		"Returns a list of values copied from a specified row of the matrix.\n"
		"Modification on the returned sub matrix will affect on the original one.");
}

Gura_ImplementMethod(matrix, row)
{
	Object_matrix *pThis = Object_matrix::GetObjectThis(arg);
	return pThis->GetMatrix()->GetRow(env, arg.GetSizeT(0));
}

// matrix#rowsize()
Gura_DeclareMethod(matrix, rowsize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns the matrix row size.");
}

Gura_ImplementMethod(matrix, rowsize)
{
	Object_matrix *pThis = Object_matrix::GetObjectThis(arg);
	return Value(static_cast<UInt>(pThis->GetMatrix()->GetRows()));
}

// matrix.scale(sx:number, sy:number, sz?:number):static:map {block?}
Gura_DeclareClassMethod(matrix, scale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sx", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "sy", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "sz", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a matrix that scales a two- or three-dimensional coordinate.\n"
		"\n"
		"Below is an example to create a matrix that scales a coordinate by 3, -2 and 5\n"
		"for x, y and z element.\n"
		"\n"
		"    mat = matrix.scale(3, -2, 5)"
		"\n"
		GURA_HELPTEXT_BLOCK_en("mat", "matrix"));
}

Gura_ImplementClassMethod(matrix, scale)
{
	double xScale = arg.GetDouble(0);
	double yScale = arg.GetDouble(1);
	AutoPtr<Matrix> pMat;
	if (arg.Is_number(2)) {
		double zScale = arg.GetDouble(2);
		pMat.reset(Matrix::CreateScale3D(xScale, yScale, zScale));
	} else {
		pMat.reset(Matrix::CreateScale2D(xScale, yScale));
	}
	return ReturnValue(env, arg, Value(new Object_matrix(env, pMat.release())));
}

// matrix#set(value)
Gura_DeclareMethod(matrix, set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Sets all the cells of the matrix with a specified value.");
}

Gura_ImplementMethod(matrix, set)
{
	Signal &sig = env.GetSignal();
	Object_matrix *pThis = Object_matrix::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator((arg.Is_list(0) || arg.Is_iterator(0))?
								arg.GetValue(0).CreateIterator(sig) :
								new Iterator_Constant(arg.GetValue(0)));
	if (sig.IsSignalled()) return Value::Nil;
	pThis->GetMatrix()->Set(env, *pIterator);
	return Value::Nil;
}

// matrix#setcol(col:number, value)
Gura_DeclareMethod(matrix, setcol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "col", VTYPE_number);
	DeclareArg(env, "value", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Sets cells in a selected column of the matrix with a specified value.");
}

Gura_ImplementMethod(matrix, setcol)
{
	Signal &sig = env.GetSignal();
	Object_matrix *pThis = Object_matrix::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator((arg.Is_list(1) || arg.Is_iterator(1))?
								arg.GetValue(1).CreateIterator(sig) :
								new Iterator_Constant(arg.GetValue(1)));
	if (sig.IsSignalled()) return Value::Nil;
	pThis->GetMatrix()->SetCol(env, arg.GetSizeT(0), *pIterator);
	return Value::Nil;
}

// matrix#setrow(row:number, value)
Gura_DeclareMethod(matrix, setrow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "row", VTYPE_number);
	DeclareArg(env, "value", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Sets cells in a selected row of the matrix with a specified value.");
}

Gura_ImplementMethod(matrix, setrow)
{
	Signal &sig = env.GetSignal();
	Object_matrix *pThis = Object_matrix::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator((arg.Is_list(1) || arg.Is_iterator(1))?
								arg.GetValue(1).CreateIterator(sig) :
								new Iterator_Constant(arg.GetValue(1)));
	if (sig.IsSignalled()) return Value::Nil;
	pThis->GetMatrix()->SetRow(env, arg.GetSizeT(0), *pIterator);
	return Value::Nil;
}

// matrix#submat(row:number, col:number, nrows:number, ncols:number):map
Gura_DeclareMethod(matrix, submat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number);
	DeclareArg(env, "col", VTYPE_number);
	DeclareArg(env, "nrows", VTYPE_number);
	DeclareArg(env, "ncols", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), 
		"Returns a sub matrix that refers to cells in a specified area of the matrix.\n"
		"Modification on the returned sub matrix will affect on the original one.");
}

Gura_ImplementMethod(matrix, submat)
{
	//Object_matrix *pThis = Object_matrix::GetObjectThis(arg);
	//return pThis->GetMatrix()->GetSub(arg.GetSizeT(0), arg.GetSizeT(1),
	//					arg.GetSizeT(2), arg.GetSizeT(3));
	return Value::Nil;
}

// matrix#list():[transpose]
Gura_DeclareMethod(matrix, list)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(transpose));
	AddHelp(
		Gura_Symbol(en), 
		"Converts the matrix into a list containing sub-lists that represents its rows.\n"
		"\n"
		"If `:transpose` attribute is specified, each sub-list contains values of\n"
		"corresponding column.\n"
		"\n"
		"If `:flat` attribute is specified, it generates one-dimentional list.\n"
		"\n"
		"Below is an example:\n"
		"\n"
		"    @@{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}.list()\n"
		"    [[1, 2, 3], [4, 5, 6], [7, 8, 9]]\n"
		"\n"
		"Below is an example with `:transpose` attribute:\n"
		"\n"
		"    @@{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}.list():transpose\n"
		"    [[1, 4, 7], [2, 5, 8], [3, 6, 9]]\n");
}

Gura_ImplementMethod(matrix, list)
{
	Object_matrix *pThis = Object_matrix::GetObjectThis(arg);
	Value result;
	Object_list *pObjList = result.InitAsList(env);
	pThis->GetMatrix()->ToList(env, pObjList->GetListForModify(),
		arg.IsSet(Gura_Symbol(transpose)), arg.GetFlag(FLAG_Flat));
	pObjList->DetermineValueType();
	return result;
}

// matrix.translate(tx:number, ty:number, tz?:number):static:map {block?}
Gura_DeclareClassMethod(matrix, translate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "tx", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "ty", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "tz", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a matrix that translates a two- or three-dimensional coordinate.\n"
		"\n"
		"Below is an example to create a matrix that translates a coordinate by 3, -2 and 5\n"
		"for x, y and z element.\n"
		"\n"
		"    mat = matrix.translate(3, -2, 5)"
		"\n"
		GURA_HELPTEXT_BLOCK_en("mat", "matrix"));
}

Gura_ImplementClassMethod(matrix, translate)
{
	double xTrans = arg.GetDouble(0);
	double yTrans = arg.GetDouble(1);
	AutoPtr<Matrix> pMat;
	if (arg.Is_number(2)) {
		double zTrans = arg.GetDouble(2);
		pMat.reset(Matrix::CreateTranslate3D(xTrans, yTrans, zTrans));
	} else {
		pMat.reset(Matrix::CreateTranslate2D(xTrans, yTrans));
	}
	return ReturnValue(env, arg, Value(new Object_matrix(env, pMat.release())));
}

// matrix#transpose()
Gura_DeclareMethod(matrix, transpose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns a transposed matrix.");
}

Gura_ImplementMethod(matrix, transpose)
{
	Signal &sig = env.GetSignal();
	Object_matrix *pThis = Object_matrix::GetObjectThis(arg);
	if (sig.IsSignalled()) return Value::Nil;
	return pThis->GetMatrix()->Transpose(env);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_matrix::Class_matrix(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_matrix)
{
}

void Class_matrix::DoPrepare(Environment &env)
{
	// Assignment of functions
	Gura_AssignFunction(matrix);
	Gura_AssignFunctionEx(MatrixInit, "@@");
	// Assignment of methods
	Gura_AssignMethod(matrix, col);
	Gura_AssignMethod(matrix, colsize);
	Gura_AssignMethod(matrix, dot);
	Gura_AssignMethod(matrix, each);
	Gura_AssignMethod(matrix, eachcol);
	Gura_AssignMethod(matrix, eachrow);
	Gura_AssignMethod(matrix, identity);
	Gura_AssignMethod(matrix, invert);
	Gura_AssignMethod(matrix, issquare);
	Gura_AssignMethod(matrix, rotation);
	Gura_AssignMethod(matrix, rotation_x);
	Gura_AssignMethod(matrix, rotation_y);
	Gura_AssignMethod(matrix, rotation_z);
	Gura_AssignMethod(matrix, roundoff);
	Gura_AssignMethod(matrix, row);
	Gura_AssignMethod(matrix, rowsize);
	Gura_AssignMethod(matrix, scale);
	Gura_AssignMethod(matrix, set);
	Gura_AssignMethod(matrix, setcol);
	Gura_AssignMethod(matrix, setrow);
	Gura_AssignMethod(matrix, submat);
	Gura_AssignMethod(matrix, list);
	Gura_AssignMethod(matrix, translate);
	Gura_AssignMethod(matrix, transpose);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_matrix::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	Signal &sig = GetSignal();
	Object_matrix *pObj = Object_matrix::GetObject(value);
	Matrix *pMat = pObj->GetMatrix();
	if (!pMat->GetElements().Serialize(env, stream)) return false;
	if (!stream.SerializePackedULong(sig, static_cast<ULong>(pMat->GetRowOff()))) return false;
	if (!stream.SerializePackedULong(sig, static_cast<ULong>(pMat->GetColOff()))) return false;
	if (!stream.SerializePackedULong(sig, static_cast<ULong>(pMat->GetRows()))) return false;
	if (!stream.SerializePackedULong(sig, static_cast<ULong>(pMat->GetCols()))) return false;
	if (!stream.SerializePackedULong(sig, static_cast<ULong>(pMat->GetFold()))) return false;
	if (!stream.SerializeBoolean(sig, pMat->GetIndexForColFlag())) return false;
	return true;
}

bool Class_matrix::Deserialize(Environment &env, Stream &stream, Value &value) const
{
	Signal &sig = GetSignal();
	AutoPtr<Matrix::Elements> pElements(new Matrix::Elements());
	if (!pElements->Deserialize(env, stream)) return false;
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
	ULong nElems = static_cast<ULong>(pElements->size());
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

Object *Class_matrix::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
