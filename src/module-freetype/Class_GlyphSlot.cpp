#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_GlyphSlot implementation
//-----------------------------------------------------------------------------
Object *Object_GlyphSlot::Clone() const
{
	return nullptr;
}

String Object_GlyphSlot::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.GlyphSlot>");
	return String(buff);
}

bool Object_GlyphSlot::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(advance));
	symbols.insert(Gura_UserSymbol(format));
	symbols.insert(Gura_UserSymbol(bitmap));
	symbols.insert(Gura_UserSymbol(bitmap_left));
	symbols.insert(Gura_UserSymbol(bitmap_top));
	symbols.insert(Gura_UserSymbol(outline));
	return true;
}

Value Object_GlyphSlot::DoGetProp(Environment &env, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(advance))) {
		AutoPtr<Object_Vector> pObj(new Object_Vector(
								Object::Reference(this), &_glyphSlot->advance));
		return Value(pObj.release());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(format))) {
		return Value(_glyphSlot->format);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(bitmap))) {
		AutoPtr<Object_Bitmap> pObj(new Object_Bitmap(
								Object::Reference(this), &_glyphSlot->bitmap));
		return Value(pObj.release());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(bitmap_left))) {
		return Value(_glyphSlot->bitmap_left);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(bitmap_top))) {
		return Value(_glyphSlot->bitmap_top);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(outline))) {
		AutoPtr<Object_Outline> pObj(new Object_Outline(
								Object::Reference(this), &_glyphSlot->outline));
		return Value(pObj.release());
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_GlyphSlot::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	evaluatedFlag = true;
#if 0
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		_vector.x = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		_vector.y = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.y);
	}
#endif
	evaluatedFlag = false;
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.GlyphSlot#advance
Gura_DeclareProperty_R(GlyphSlot, advance)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(GlyphSlot, advance)
{
	return Value::Nil;
}

// freetype.GlyphSlot#bitmap
Gura_DeclareProperty_R(GlyphSlot, bitmap)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(GlyphSlot, bitmap)
{
	return Value::Nil;
}

// freetype.GlyphSlot#bitmap_left
Gura_DeclareProperty_R(GlyphSlot, bitmap_left)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(GlyphSlot, bitmap_left)
{
	return Value::Nil;
}

// freetype.GlyphSlot#bitmap_top
Gura_DeclareProperty_R(GlyphSlot, bitmap_top)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(GlyphSlot, bitmap_top)
{
	return Value::Nil;
}

// freetype.GlyphSlot#format
Gura_DeclareProperty_R(GlyphSlot, format)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(GlyphSlot, format)
{
	return Value::Nil;
}

// freetype.GlyphSlot#outline
Gura_DeclareProperty_R(GlyphSlot, outline)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(GlyphSlot, outline)
{
	return Value::Nil;
}

// freetype.GlyphSlot#x
Gura_DeclareProperty_RW(GlyphSlot, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(GlyphSlot, x)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(GlyphSlot, x)
{
	return Value::Nil;
}

// freetype.GlyphSlot#y
Gura_DeclareProperty_RW(GlyphSlot, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(GlyphSlot, y)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(GlyphSlot, y)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Gura interfaces for freetype.GlyphSlot
//-----------------------------------------------------------------------------
// freetype.GlyphSlot#Get_Glyph()
Gura_DeclareMethod(GlyphSlot, Get_Glyph)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(GlyphSlot, Get_Glyph)
{
	Signal &sig = env.GetSignal();
	FT_GlyphSlot glyphSlot = Object_GlyphSlot::GetObjectThis(arg)->GetEntity();
	std::unique_ptr<FT_Glyph> pGlyph(new FT_Glyph);
	FT_Error err = ::FT_Get_Glyph(glyphSlot, pGlyph.get());
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return Value(new Object_Glyph(nullptr, pGlyph.release()));
}

// freetype.GlyphSlot#Render(render_mode:number):reduce
Gura_DeclareMethod(GlyphSlot, Render)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "render_mode", VTYPE_number);
}

Gura_ImplementMethod(GlyphSlot, Render)
{
	Signal &sig = env.GetSignal();
	FT_GlyphSlot glyphSlot = Object_GlyphSlot::GetObjectThis(arg)->GetEntity();
	FT_Render_Mode render_mode = static_cast<FT_Render_Mode>(arg.GetInt(0));
	FT_Error err = ::FT_Render_Glyph(glyphSlot, render_mode);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return arg.GetValueThis();
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.GlyphSlot
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(GlyphSlot)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(GlyphSlot, advance);
	Gura_AssignProperty(GlyphSlot, bitmap);
	Gura_AssignProperty(GlyphSlot, bitmap_left);
	Gura_AssignProperty(GlyphSlot, bitmap_top);
	Gura_AssignProperty(GlyphSlot, format);
	Gura_AssignProperty(GlyphSlot, outline);
	Gura_AssignProperty(GlyphSlot, x);
	Gura_AssignProperty(GlyphSlot, y);
#endif
	Gura_AssignValue(GlyphSlot, Value(Reference()));
	Gura_AssignMethod(GlyphSlot, Get_Glyph);
	Gura_AssignMethod(GlyphSlot, Render);
}

Gura_EndModuleScope(freetype)
