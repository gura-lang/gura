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
	::sprintf(buff, "<sdl.Matrix:xx=%d,xy=%d,yx=%d,yy=%d>",
					_matrix.xx, _matrix.xy, _matrix.yx, _matrix.yy);
	return String(buff);
}

bool Object_Matrix::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(xx));
	symbols.insert(Gura_UserSymbol(xy));
	symbols.insert(Gura_UserSymbol(yx));
	symbols.insert(Gura_UserSymbol(yy));
	return true;
}

Value Object_Matrix::DoGetProp(Signal sig, const Symbol *pSymbol,
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

Value Object_Matrix::DoSetProp(Signal sig, const Symbol *pSymbol, const Value &value,
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
Gura_ImplementUserClass(Matrix)
{
}

}}
