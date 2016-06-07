//----------------------------------------------------------------------------
// wxPen
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPen
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPen
//----------------------------------------------------------------------------
Object_wx_Pen::~Object_wx_Pen()
{
}

Object *Object_wx_Pen::Clone() const
{
	return nullptr;
}

String Object_wx_Pen::ToString(bool exprFlag)
{
	String rtn("<wx.Pen:");
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
Gura_DeclareFunctionAlias(__Pen, "Pen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Pen));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Pen)
{
	//wxPen();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Pen_1, "Pen_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Pen));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Pen_1)
{
	//const wxColour& colour = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//wxPenStyle style = arg.GetNumber(2)
	//wxPen(colour, width, style);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Pen_2, "Pen_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "stipple", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Pen));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Pen_2)
{
	//const wxBitmap& stipple = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//wxPen(stipple, width);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Pen_3, "Pen_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pen", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Pen));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Pen_3)
{
	//const wxPen& pen = arg.GetNumber(0)
	//wxPen(pen);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Pen, __GetCap, "GetCap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, __GetCap)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPenCap _rtn = pThis->GetEntity()->GetCap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __GetColour, "GetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, __GetColour)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxColour _rtn = pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __GetDashes, "GetDashes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dashes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, __GetDashes)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDash** dashes = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetDashes(dashes);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __GetJoin, "GetJoin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, __GetJoin)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPenJoin _rtn = pThis->GetEntity()->GetJoin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __GetStipple, "GetStipple")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, __GetStipple)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxBitmap* _rtn = pThis->GetEntity()->GetStipple();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, __GetStyle)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPenStyle _rtn = pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __GetWidth, "GetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, __GetWidth)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, __IsOk)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __IsNonTransparent, "IsNonTransparent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, __IsNonTransparent)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsNonTransparent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __IsTransparent, "IsTransparent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, __IsTransparent)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsTransparent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __SetCap, "SetCap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "capStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, __SetCap)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPenCap capStyle = arg.GetNumber(0)
	//pThis->GetEntity()->SetCap(capStyle);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __SetColour, "SetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, __SetColour)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxColour& colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour(colour);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __SetColour_1, "SetColour_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, __SetColour_1)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned char red = arg.GetNumber(0)
	//unsigned char green = arg.GetNumber(1)
	//unsigned char blue = arg.GetNumber(2)
	//pThis->GetEntity()->SetColour(red, green, blue);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __SetDashes, "SetDashes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dash", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, __SetDashes)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//const wxDash* dash = arg.GetNumber(1)
	//pThis->GetEntity()->SetDashes(n, dash);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __SetJoin, "SetJoin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "join_style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, __SetJoin)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPenJoin join_style = arg.GetNumber(0)
	//pThis->GetEntity()->SetJoin(join_style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __SetStipple, "SetStipple")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stipple", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, __SetStipple)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& stipple = arg.GetNumber(0)
	//pThis->GetEntity()->SetStipple(stipple);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __SetStyle, "SetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, __SetStyle)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPenStyle style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle(style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __SetWidth, "SetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, __SetWidth)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth(width);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPen
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Pen)
{
	// Constructor assignment
	Gura_AssignFunction(__Pen);
	Gura_AssignFunction(__Pen_1);
	Gura_AssignFunction(__Pen_2);
	Gura_AssignFunction(__Pen_3);
	// Method assignment
	Gura_AssignMethod(wx_Pen, __GetCap);
	Gura_AssignMethod(wx_Pen, __GetColour);
	Gura_AssignMethod(wx_Pen, __GetDashes);
	Gura_AssignMethod(wx_Pen, __GetJoin);
	Gura_AssignMethod(wx_Pen, __GetStipple);
	Gura_AssignMethod(wx_Pen, __GetStyle);
	Gura_AssignMethod(wx_Pen, __GetWidth);
	Gura_AssignMethod(wx_Pen, __IsOk);
	Gura_AssignMethod(wx_Pen, __IsNonTransparent);
	Gura_AssignMethod(wx_Pen, __IsTransparent);
	Gura_AssignMethod(wx_Pen, __SetCap);
	Gura_AssignMethod(wx_Pen, __SetColour);
	Gura_AssignMethod(wx_Pen, __SetColour_1);
	Gura_AssignMethod(wx_Pen, __SetDashes);
	Gura_AssignMethod(wx_Pen, __SetJoin);
	Gura_AssignMethod(wx_Pen, __SetStipple);
	Gura_AssignMethod(wx_Pen, __SetStyle);
	Gura_AssignMethod(wx_Pen, __SetWidth);
}

Gura_ImplementDescendantCreator(wx_Pen)
{
	return new Object_wx_Pen((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
