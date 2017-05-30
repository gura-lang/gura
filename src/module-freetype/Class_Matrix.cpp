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

bool Object_Matrix::ConvertFrom(Signal &sig, const ArrayT<Double> *pArrayT)
{
	if (pArrayT->GetElemNum() != 4) {
		sig.SetError(ERR_ValueError, "matrix must be larger than or equal to 2x2");
		return false;
	}
	// 16.16 fixed float format
	const Double *pElem = pArrayT->GetPointer();
	_matrix.xx = static_cast<FT_Fixed>(*pElem * (1 << 16)); pElem++;
	_matrix.xy = static_cast<FT_Fixed>(*pElem * (1 << 16)); pElem++;
	_matrix.yx = static_cast<FT_Fixed>(*pElem * (1 << 16)); pElem++;
	_matrix.yy = static_cast<FT_Fixed>(*pElem * (1 << 16));
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
// freetype.Matrix(array:array@double):map {block?}
Gura_DeclareFunction(Matrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "array", VTYPE_array_at_double);
	SetClassToConstruct(Gura_UserClass(Matrix));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Matrix)
{
	Signal &sig = env.GetSignal();
	const ArrayT<Double> *pArray = Object_arrayT<Double>::GetObject(arg, 0)->GetArrayT();
	AutoPtr<Object_Matrix> pObjRtn(new Object_Matrix());
	if (!pObjRtn->ConvertFrom(sig, pArray)) return false;
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
	env.LookupClass(VTYPE_array_at_double)->CastFrom(env, value, flags);
	if (value.Is_array_at_double()) {
		ArrayT<Double> *pArrayT = Object_arrayT<Double>::GetObject(value)->GetArrayT();
		AutoPtr<Object_Matrix> pObjRtn(new Object_Matrix());
		if (!pObjRtn->ConvertFrom(sig, pArrayT)) return false;
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
