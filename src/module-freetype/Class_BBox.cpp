#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_BBox implementation
//-----------------------------------------------------------------------------
Object *Object_BBox::Clone() const
{
	return nullptr;
}

String Object_BBox::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.BBox:xMin=%ld,yMin=%ld,xMax=%ld,yMax=%ld>",
						_bbox.xMin, _bbox.yMin, _bbox.xMax, _bbox.yMax);
	return String(buff);
}

bool Object_BBox::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(xMin));
	symbols.insert(Gura_UserSymbol(yMin));
	symbols.insert(Gura_UserSymbol(xMax));
	symbols.insert(Gura_UserSymbol(yMax));
	return true;
}

Value Object_BBox::DoGetProp(Environment &env, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(xMin))) {
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yMin))) {
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(xMax))) {
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yMax))) {
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_BBox::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(xMin))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yMin))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(xMax))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(yMax))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
	}
	evaluatedFlag = false;
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.BBox#xMax
Gura_DeclareProperty_RW(BBox, xMax)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(BBox, xMax)
{
	const FT_BBox &bbox = Object_BBox::GetObject(valueThis)->GetEntity();
	return Value(bbox.xMax);
}

Gura_ImplementPropertySetter(BBox, xMax)
{
	FT_BBox &bbox = Object_BBox::GetObject(valueThis)->GetEntity();
	bbox.xMax = static_cast<FT_Pos>(value.GetLong());
	return Value(bbox.xMax);
}

// freetype.BBox#xMin
Gura_DeclareProperty_RW(BBox, xMin)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(BBox, xMin)
{
	const FT_BBox &bbox = Object_BBox::GetObject(valueThis)->GetEntity();
	return Value(bbox.xMin);
}

Gura_ImplementPropertySetter(BBox, xMin)
{
	FT_BBox &bbox = Object_BBox::GetObject(valueThis)->GetEntity();
	bbox.xMin = static_cast<FT_Pos>(value.GetLong());
	return Value(bbox.xMin);
}

// freetype.BBox#yMax
Gura_DeclareProperty_RW(BBox, yMax)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(BBox, yMax)
{
	const FT_BBox &bbox = Object_BBox::GetObject(valueThis)->GetEntity();
	return Value(bbox.yMax);
}

Gura_ImplementPropertySetter(BBox, yMax)
{
	FT_BBox &bbox = Object_BBox::GetObject(valueThis)->GetEntity();
	bbox.yMax = static_cast<FT_Pos>(value.GetLong());
	return Value(bbox.yMax);
}

// freetype.BBox#yMin
Gura_DeclareProperty_RW(BBox, yMin)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(BBox, yMin)
{
	const FT_BBox &bbox = Object_BBox::GetObject(valueThis)->GetEntity();
	return Value(bbox.yMin);
}

Gura_ImplementPropertySetter(BBox, yMin)
{
	FT_BBox &bbox = Object_BBox::GetObject(valueThis)->GetEntity();
	bbox.yMin = static_cast<FT_Pos>(value.GetLong());
	return Value(bbox.yMin);
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.BBox
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(BBox)
{
	// Assignment of properties
	Gura_AssignProperty(BBox, xMax);
	Gura_AssignProperty(BBox, xMin);
	Gura_AssignProperty(BBox, yMax);
	Gura_AssignProperty(BBox, yMin);
	// Assignment of value
	Gura_AssignValue(BBox, Value(Reference()));
}

Gura_EndModuleScope(freetype)
