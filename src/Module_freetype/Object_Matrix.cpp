#include "stdafx.h"

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_Matrix implementation
//-----------------------------------------------------------------------------
Object *Object_Matrix::Clone() const
{
	return NULL;
}

String Object_Matrix::ToString(Signal sig, bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.Matrix:xx=%d,xy=%d,yx=%d,yy=%d>",
					_matrix.xx, _matrix.xy, _matrix.yx, _matrix.yy);
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
		return Value(_matrix.xx);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(xy))) {
		return Value(_matrix.xy);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yx))) {
		return Value(_matrix.yx);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yy))) {
		return Value(_matrix.yy);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Matrix::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(xx))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_matrix.xx = static_cast<FT_Pos>(value.GetLong());
		return Value(_matrix.xx);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(xy))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_matrix.xy = static_cast<FT_Pos>(value.GetLong());
		return Value(_matrix.xy);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yx))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_matrix.yx = static_cast<FT_Pos>(value.GetLong());
		return Value(_matrix.yx);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yy))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_matrix.yy = static_cast<FT_Pos>(value.GetLong());
		return Value(_matrix.yy);
	}
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.Matrix
//-----------------------------------------------------------------------------
// freetype.Matrix#Multiply(matrix:matrix):reduce
Gura_DeclareMethod(Matrix, Multiply)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "matrix", VTYPE_Matrix);
}

Gura_ImplementMethod(Matrix, Multiply)
{
	FT_Matrix *matrixThis = Object_Matrix::GetThisObj(args)->GetEntity();
	FT_Matrix *matrix = Object_Matrix::GetObject(args, 0)->GetEntity();
	::FT_Matrix_Multiply(matrix, matrixThis);	// void function
	return args.GetThis();
}

Gura_ImplementUserClassWithCast(Matrix)
{
}

Gura_ImplementCastFrom(Matrix)
{
	if (value.IsMatrix()) {
		Gura::Matrix *pMat = Gura::Object_matrix::GetObject(value)->GetMatrix();
		if (pMat->GetRows() < 2 || pMat->GetCols() < 2) {
			sig.SetError(ERR_ValueError, "matrix must be larger than or equal to 2x2");
			return false;
		}
		if (Gura::Matrix::CheckValueType(*pMat) != VTYPE_number) {
			sig.SetError(ERR_ValueError, "matrix must compose of number elements");
			return false;
		}
		
		FT_Matrix matrix;
		// 16.16 fixed float format
		matrix.xx = static_cast<FT_Fixed>(pMat->GetElement(0, 0).GetDouble() * (1 << 16));
		matrix.xy = static_cast<FT_Fixed>(pMat->GetElement(0, 1).GetDouble() * (1 << 16));
		matrix.yx = static_cast<FT_Fixed>(pMat->GetElement(1, 0).GetDouble() * (1 << 16));
		matrix.yy = static_cast<FT_Fixed>(pMat->GetElement(1, 1).GetDouble() * (1 << 16));
		AutoPtr<Object_Matrix> pObjRtn(new Object_Matrix(matrix));
		value = Value(pObjRtn.release());
		return true;
	}
	return false;
}

Gura_ImplementCastTo(Matrix)
{
	return false;
}

}}
