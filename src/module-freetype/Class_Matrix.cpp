#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Matrix implementation
//-----------------------------------------------------------------------------
Object *Object_Matrix::Clone() const
{
	return nullptr;
}

String Object_Matrix::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.Matrix:xx=%f,xy=%f,yx=%f,yy=%f>",
					static_cast<double>(_matrix.xx) / (1 << 16),
					static_cast<double>(_matrix.xy) / (1 << 16),
					static_cast<double>(_matrix.yx) / (1 << 16),
					static_cast<double>(_matrix.yy) / (1 << 16));
	return String(buff);
}

bool Object_Matrix::ConvertFrom(Signal &sig, const Gura::Matrix *pMat)
{
	if (pMat->GetRows() < 2 || pMat->GetCols() < 2) {
		sig.SetError(ERR_ValueError, "matrix must be larger than or equal to 2x2");
		return false;
	}
	if (Gura::Matrix::CheckValueType(*pMat) != VTYPE_number) {
		sig.SetError(ERR_ValueError, "matrix must compose of number elements");
		return false;
	}
	// 16.16 fixed float format
	_matrix.xx = static_cast<FT_Fixed>(pMat->GetElement(0, 0).GetDouble() * (1 << 16));
	_matrix.xy = static_cast<FT_Fixed>(pMat->GetElement(0, 1).GetDouble() * (1 << 16));
	_matrix.yx = static_cast<FT_Fixed>(pMat->GetElement(1, 0).GetDouble() * (1 << 16));
	_matrix.yy = static_cast<FT_Fixed>(pMat->GetElement(1, 1).GetDouble() * (1 << 16));
	return true;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.Matrix#xx
Gura_DeclareProperty_RW(Matrix, xx)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Matrix, xx)
{
	FT_Matrix &matrix = *Object_Matrix::GetObject(valueThis)->GetEntity();
	return Value(static_cast<double>(matrix.xx) / (1 << 16));
}

Gura_ImplementPropertySetter(Matrix, xx)
{
	FT_Matrix &matrix = *Object_Matrix::GetObject(valueThis)->GetEntity();
	matrix.xx = static_cast<FT_Pos>(value.GetDouble() * (1 << 16));
	return Value(static_cast<double>(matrix.xx) / (1 << 16));
}

// freetype.Matrix#xy
Gura_DeclareProperty_RW(Matrix, xy)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Matrix, xy)
{
	FT_Matrix &matrix = *Object_Matrix::GetObject(valueThis)->GetEntity();
	return Value(static_cast<double>(matrix.xy) / (1 << 16));
}

Gura_ImplementPropertySetter(Matrix, xy)
{
	FT_Matrix &matrix = *Object_Matrix::GetObject(valueThis)->GetEntity();
	matrix.xy = static_cast<FT_Pos>(value.GetDouble() * (1 << 16));
	return Value(static_cast<double>(matrix.xy) / (1 << 16));
}

// freetype.Matrix#yx
Gura_DeclareProperty_RW(Matrix, yx)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Matrix, yx)
{
	FT_Matrix &matrix = *Object_Matrix::GetObject(valueThis)->GetEntity();
	return Value(static_cast<double>(matrix.yx) / (1 << 16));
}

Gura_ImplementPropertySetter(Matrix, yx)
{
	FT_Matrix &matrix = *Object_Matrix::GetObject(valueThis)->GetEntity();
	matrix.yx = static_cast<FT_Pos>(value.GetDouble() * (1 << 16));
	return Value(static_cast<double>(matrix.yx) / (1 << 16));
}

// freetype.Matrix#yy
Gura_DeclareProperty_RW(Matrix, yy)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Matrix, yy)
{
	FT_Matrix &matrix = *Object_Matrix::GetObject(valueThis)->GetEntity();
	return Value(static_cast<double>(matrix.yy) / (1 << 16));
}

Gura_ImplementPropertySetter(Matrix, yy)
{
	FT_Matrix &matrix = *Object_Matrix::GetObject(valueThis)->GetEntity();
	matrix.yy = static_cast<FT_Pos>(value.GetDouble() * (1 << 16));
	return Value(static_cast<double>(matrix.yy) / (1 << 16));
}

//-----------------------------------------------------------------------------
// Gura interfaces for freetype.Matrix
//-----------------------------------------------------------------------------
// freetype.Matrix(matrix:matrix):map {block?}
Gura_DeclareFunction(Matrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "matrix", VTYPE_matrix);
	SetClassToConstruct(Gura_UserClass(Matrix));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Matrix)
{
	Signal &sig = env.GetSignal();
	const Gura::Matrix *pMat = Object_matrix::GetObject(arg, 0)->GetMatrix();
	AutoPtr<Object_Matrix> pObjRtn(new Object_Matrix());
	if (!pObjRtn->ConvertFrom(sig, pMat)) return false;
	return ReturnValue(env, arg, Value(pObjRtn.release()));
}

// freetype.Matrix#Multiply(matrix:freetype.Matrix):reduce
Gura_DeclareMethod(Matrix, Multiply)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "matrix", VTYPE_Matrix);
}

Gura_ImplementMethod(Matrix, Multiply)
{
	FT_Matrix *matrixThis = Object_Matrix::GetObjectThis(arg)->GetEntity();
	FT_Matrix *matrix = Object_Matrix::GetObject(arg, 0)->GetEntity();
	::FT_Matrix_Multiply(matrix, matrixThis);	// void function
	return arg.GetValueThis();
}

// freetype.Matrix#Invert():reduce
Gura_DeclareMethod(Matrix, Invert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(Matrix, Invert)
{
	Signal &sig = env.GetSignal();
	FT_Matrix *matrixThis = Object_Matrix::GetObjectThis(arg)->GetEntity();
	FT_Error err = ::FT_Matrix_Invert(matrixThis);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return arg.GetValueThis();
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.Matrix
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(Matrix)
{
	// Assignment of properties
	Gura_AssignProperty(Matrix, xx);
	Gura_AssignProperty(Matrix, xy);
	Gura_AssignProperty(Matrix, yx);
	Gura_AssignProperty(Matrix, yy);
	// Assignment of function
	Gura_AssignFunction(Matrix);
	// Assignment of methods
	Gura_AssignMethod(Matrix, Multiply);
	Gura_AssignMethod(Matrix, Invert);
}

Gura_ImplementCastFrom(Matrix)
{
	Signal &sig = GetSignal();
	if (value.Is_matrix()) {
		Gura::Matrix *pMat = Gura::Object_matrix::GetObject(value)->GetMatrix();
		AutoPtr<Object_Matrix> pObjRtn(new Object_Matrix());
		if (!pObjRtn->ConvertFrom(sig, pMat)) return false;
		value = Value(pObjRtn.release());
		return true;
	}
	return false;
}

Gura_ImplementCastTo(Matrix)
{
	return false;
}

Gura_EndModuleScope(freetype)
