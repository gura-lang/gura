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

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.GlyphSlot#advance
Gura_DeclareProperty_R(GlyphSlot, advance)
{
	SetPropAttr(VTYPE_Vector);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(GlyphSlot, advance)
{
	Object_GlyphSlot *pObjThis = Object_GlyphSlot::GetObject(valueThis);
	FT_GlyphSlot &glyphSlot = pObjThis->GetEntity();
	AutoPtr<Object_Vector> pObj(new Object_Vector(
									Object::Reference(pObjThis), &glyphSlot->advance));
	return Value(pObj.release());
}

// freetype.GlyphSlot#bitmap
Gura_DeclareProperty_R(GlyphSlot, bitmap)
{
	SetPropAttr(VTYPE_Bitmap);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(GlyphSlot, bitmap)
{
	Object_GlyphSlot *pObjThis = Object_GlyphSlot::GetObject(valueThis);
	FT_GlyphSlot &glyphSlot = pObjThis->GetEntity();
	AutoPtr<Object_Bitmap> pObj(new Object_Bitmap(
									Object::Reference(pObjThis), &glyphSlot->bitmap));
	return Value(pObj.release());
}

// freetype.GlyphSlot#bitmap_left
Gura_DeclareProperty_R(GlyphSlot, bitmap_left)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(GlyphSlot, bitmap_left)
{
	FT_GlyphSlot &glyphSlot = Object_GlyphSlot::GetObject(valueThis)->GetEntity();
	return Value(glyphSlot->bitmap_left);
}

// freetype.GlyphSlot#bitmap_top
Gura_DeclareProperty_R(GlyphSlot, bitmap_top)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(GlyphSlot, bitmap_top)
{
	FT_GlyphSlot &glyphSlot = Object_GlyphSlot::GetObject(valueThis)->GetEntity();
	return Value(glyphSlot->bitmap_top);
}

// freetype.GlyphSlot#format
Gura_DeclareProperty_R(GlyphSlot, format)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(GlyphSlot, format)
{
	FT_GlyphSlot &glyphSlot = Object_GlyphSlot::GetObject(valueThis)->GetEntity();
	return Value(glyphSlot->format);
}

// freetype.GlyphSlot#outline
Gura_DeclareProperty_R(GlyphSlot, outline)
{
	SetPropAttr(VTYPE_Outline);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(GlyphSlot, outline)
{
	Object_GlyphSlot *pObjThis = Object_GlyphSlot::GetObject(valueThis);
	FT_GlyphSlot &glyphSlot = pObjThis->GetEntity();
	AutoPtr<Object_Outline> pObj(new Object_Outline(
									 Object::Reference(pObjThis), &glyphSlot->outline));
	return Value(pObj.release());
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
	Gura_AssignProperty(GlyphSlot, advance);
	Gura_AssignProperty(GlyphSlot, bitmap);
	Gura_AssignProperty(GlyphSlot, bitmap_left);
	Gura_AssignProperty(GlyphSlot, bitmap_top);
	Gura_AssignProperty(GlyphSlot, format);
	Gura_AssignProperty(GlyphSlot, outline);
	// Assignment of methods
	Gura_AssignMethod(GlyphSlot, Get_Glyph);
	Gura_AssignMethod(GlyphSlot, Render);
	// Assignment of value
	Gura_AssignValue(GlyphSlot, Value(Reference()));
}

Gura_EndModuleScope(freetype)
