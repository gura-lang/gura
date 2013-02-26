#include "stdafx.h"

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_BBox implementation
//-----------------------------------------------------------------------------
Object *Object_BBox::Clone() const
{
	return NULL;
}

String Object_BBox::ToString(Signal sig, bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<sdl.BBox:xMin=%d,yMin=%d,xMax=%d,yMax=%d>",
						_bbox.xMin, _bbox.yMin, _bbox.xMax, _bbox.yMax);
	return String(buff);
}

bool Object_BBox::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(xMin));
	symbols.insert(Gura_UserSymbol(yMin));
	symbols.insert(Gura_UserSymbol(xMax));
	symbols.insert(Gura_UserSymbol(yMax));
	return true;
}

Value Object_BBox::DoGetProp(Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(xMin))) {
		return Value(_bbox.xMin);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yMin))) {
		return Value(_bbox.yMin);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(xMax))) {
		return Value(_bbox.xMax);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yMax))) {
		return Value(_bbox.yMax);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_BBox::DoSetProp(Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(xMin))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_bbox.xMin = static_cast<FT_Pos>(value.GetLong());
		return Value(_bbox.xMin);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yMin))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_bbox.yMin = static_cast<FT_Pos>(value.GetLong());
		return Value(_bbox.yMin);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(xMax))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_bbox.xMax = static_cast<FT_Pos>(value.GetLong());
		return Value(_bbox.xMax);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yMax))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_bbox.yMax = static_cast<FT_Pos>(value.GetLong());
		return Value(_bbox.yMax);
	}
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.BBox
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(BBox)
{
}

}}
