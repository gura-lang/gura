//----------------------------------------------------------------------------
// wxBrush
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBrush
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBrush
//----------------------------------------------------------------------------
Object_wx_Brush::~Object_wx_Brush()
{
}

Object *Object_wx_Brush::Clone() const
{
	return nullptr;
}

String Object_wx_Brush::ToString(bool exprFlag)
{
	String rtn("<wx.Brush:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Brush, "Brush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Brush));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Brush)
{
	//wxBrush();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Brush_1, "Brush_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Brush));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Brush_1)
{
	//const wxColour& colour = arg.GetNumber(0)
	//wxBrushStyle style = arg.GetNumber(1)
	//wxBrush(colour, style);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Brush_2, "Brush_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "stippleBitmap", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Brush));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Brush_2)
{
	//const wxBitmap& stippleBitmap = arg.GetNumber(0)
	//wxBrush(stippleBitmap);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Brush_3, "Brush_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "brush", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Brush));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Brush_3)
{
	//const wxBrush& brush = arg.GetNumber(0)
	//wxBrush(brush);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Brush, __GetColour, "GetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Brush, __GetColour)
{
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxColour _rtn = pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Brush, __GetStipple, "GetStipple")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Brush, __GetStipple)
{
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxBitmap* _rtn = pThis->GetEntity()->GetStipple();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Brush, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Brush, __GetStyle)
{
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxBrushStyle _rtn = pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Brush, __IsHatch, "IsHatch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Brush, __IsHatch)
{
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsHatch();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Brush, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Brush, __IsOk)
{
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Brush, __IsNonTransparent, "IsNonTransparent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Brush, __IsNonTransparent)
{
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsNonTransparent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Brush, __IsTransparent, "IsTransparent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Brush, __IsTransparent)
{
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsTransparent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Brush, __SetColour, "SetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, __SetColour)
{
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour(colour);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Brush, __SetColour_1, "SetColour_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, __SetColour_1)
{
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned char red = arg.GetNumber(0)
	//unsigned char green = arg.GetNumber(1)
	//unsigned char blue = arg.GetNumber(2)
	//pThis->GetEntity()->SetColour(red, green, blue);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Brush, __SetStipple, "SetStipple")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, __SetStipple)
{
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetStipple(bitmap);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Brush, __SetStyle, "SetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, __SetStyle)
{
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxBrushStyle style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle(style);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBrush
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Brush)
{
	// Constructor assignment
	Gura_AssignFunction(__Brush);
	Gura_AssignFunction(__Brush_1);
	Gura_AssignFunction(__Brush_2);
	Gura_AssignFunction(__Brush_3);
	// Method assignment
	Gura_AssignMethod(wx_Brush, __GetColour);
	Gura_AssignMethod(wx_Brush, __GetStipple);
	Gura_AssignMethod(wx_Brush, __GetStyle);
	Gura_AssignMethod(wx_Brush, __IsHatch);
	Gura_AssignMethod(wx_Brush, __IsOk);
	Gura_AssignMethod(wx_Brush, __IsNonTransparent);
	Gura_AssignMethod(wx_Brush, __IsTransparent);
	Gura_AssignMethod(wx_Brush, __SetColour);
	Gura_AssignMethod(wx_Brush, __SetColour_1);
	Gura_AssignMethod(wx_Brush, __SetStipple);
	Gura_AssignMethod(wx_Brush, __SetStyle);
}

Gura_ImplementDescendantCreator(wx_Brush)
{
	return new Object_wx_Brush((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
