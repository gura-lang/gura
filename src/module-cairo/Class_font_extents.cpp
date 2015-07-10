#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_font_extents implementation
//-----------------------------------------------------------------------------
Object_font_extents::~Object_font_extents()
{
}

Object *Object_font_extents::Clone() const
{
	return nullptr;
}

bool Object_font_extents::DoDirProp(Environment &env, Signal &sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(ascent));
	symbols.insert(Gura_UserSymbol(descent));
	symbols.insert(Gura_UserSymbol(height));
	symbols.insert(Gura_UserSymbol(max_x_advance));
	symbols.insert(Gura_UserSymbol(max_y_advance));
	return true;
}

Value Object_font_extents::DoGetProp(Environment &env, Signal &sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(ascent))) {
		return Value(_font_extents.ascent);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(descent))) {
		return Value(_font_extents.descent);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(height))) {
		return Value(_font_extents.height);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(max_x_advance))) {
		return Value(_font_extents.max_x_advance);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(max_y_advance))) {
		return Value(_font_extents.max_y_advance);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_font_extents::ToString(bool exprFlag)
{
	return String("<cairo.font_extents>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for font_extents
//-----------------------------------------------------------------------------
// implementation of class font_extents
Gura_ImplementUserClass(font_extents)
{
}

Gura_EndModuleScope(cairo)
