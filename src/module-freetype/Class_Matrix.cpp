#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Matrix implementation
//-----------------------------------------------------------------------------
Object *Object_Matrix::Clone() const
{
	return NULL;
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

bool Object_Matrix::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(xx));
	symbols.insert(Gura_UserSymbol(xy));
	symbols.insert(Gura_UserSymbol(yx));
	symbols.insert(Gura_UserSymbol(yy));
	return true;
}

Value Object_Matrix::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(xx))) {
		return Value(static_cast<double>(_matrix.xx) / (1 << 16));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(xy))) {
		return Value(static_cast<double>(_matrix.xy) / (1 << 16));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yx))) {
		return Value(static_cast<double>(_matrix.yx) / (1 << 16));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yy))) {
		return Value(static_cast<double>(_matrix.yy) / (1 << 16));
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Matrix::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(xx))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_matrix.xx = static_cast<FT_Pos>(value.GetDouble() * (1 << 16));
		return Value(static_cast<double>(_matrix.xx) / (1 << 16));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(xy))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_matrix.xy = static_cast<FT_Pos>(value.GetDouble() * (1 << 16));
		return Value(static_cast<double>(_matrix.xy) / (1 << 16));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yx))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_matrix.yx = static_cast<FT_Pos>(value.GetDouble() * (1 << 16));
		return Value(static_cast<double>(_matrix.yx) / (1 << 16));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yy))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_matrix.yy = static_cast<FT_Pos>(value.GetDouble() * (1 << 16));
		return Value(static_cast<double>(_matrix.yy) / (1 << 16));
	}
	evaluatedFlag = false;
	return Value::Null;
}

bool Object_Matrix::ConvertFrom(Signal sig, const Gura::Matrix *pMat)
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
// Gura interfaces for freetype.Matrix
//-----------------------------------------------------------------------------
// freetype.Matrix(matrix:matrix):map {block?}
Gura_DeclareFunction(Matrix)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "matrix", VTYPE_matrix);
	SetClassToConstruct(Gura_UserClass(Matrix));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Matrix)
{
	const Gura::Matrix *pMat = Object_matrix::GetObject(args, 0)->GetMatrix();
	AutoPtr<Object_Matrix> pObjRtn(new Object_Matrix());
	if (!pObjRtn->ConvertFrom(sig, pMat)) return false;
	return ReturnValue(env, sig, args, Value(pObjRtn.release()));
}

// freetype.Matrix#Multiply(matrix:freetype.Matrix):reduce
Gura_DeclareMethod(Matrix, Multiply)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "matrix", VTYPE_Matrix);
}

Gura_ImplementMethod(Matrix, Multiply)
{
	FT_Matrix *matrixThis = Object_Matrix::GetThisObj(args)->GetEntity();
	FT_Matrix *matrix = Object_Matrix::GetObject(args, 0)->GetEntity();
	::FT_Matrix_Multiply(matrix, matrixThis);	// void function
	return args.GetThis();
}

// freetype.Matrix#Invert():reduce
Gura_DeclareMethod(Matrix, Invert)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(Matrix, Invert)
{
	FT_Matrix *matrixThis = Object_Matrix::GetThisObj(args)->GetEntity();
	FT_Error err = ::FT_Matrix_Invert(matrixThis);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Null;
	}
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.Matrix
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(Matrix)
{
	Gura_AssignFunction(Matrix);
	Gura_AssignMethod(Matrix, Multiply);
	Gura_AssignMethod(Matrix, Invert);
}

Gura_ImplementCastFrom(Matrix)
{
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
