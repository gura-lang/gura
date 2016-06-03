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
Gura_DeclareFunctionAlias(__wxPen, "wxPen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxPen)
{
	//wxPen();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxPen_1, "wxPen_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxPen_1)
{
	//int colour = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//wxPen();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxPen_2, "wxPen_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stipple", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxPen_2)
{
	//int stipple = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//wxPen();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxPen_3, "wxPen_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxPen_3)
{
	//int pen = arg.GetNumber(0)
	//wxPen();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Pen, __GetCap, "GetCap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, __GetCap)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __GetColour, "GetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, __GetColour)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __GetDashes, "GetDashes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dashes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, __GetDashes)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dashes = arg.GetNumber(0)
	//pThis->GetEntity()->GetDashes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __GetJoin, "GetJoin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, __GetJoin)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetJoin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __GetStipple, "GetStipple")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, __GetStipple)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStipple();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, __GetStyle)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __GetWidth, "GetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, __GetWidth)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, __IsOk)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __IsNonTransparent, "IsNonTransparent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, __IsNonTransparent)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsNonTransparent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Pen, __IsTransparent, "IsTransparent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, __IsTransparent)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsTransparent();
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
	//int capStyle = arg.GetNumber(0)
	//pThis->GetEntity()->SetCap();
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
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
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
	//int red = arg.GetNumber(0)
	//int green = arg.GetNumber(1)
	//int blue = arg.GetNumber(2)
	//pThis->GetEntity()->SetColour();
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
	//int dash = arg.GetNumber(1)
	//pThis->GetEntity()->SetDashes();
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
	//int join_style = arg.GetNumber(0)
	//pThis->GetEntity()->SetJoin();
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
	//int stipple = arg.GetNumber(0)
	//pThis->GetEntity()->SetStipple();
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
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
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
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPen
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Pen)
{
	// Constructor assignment
	Gura_AssignFunction(__wxPen);
	Gura_AssignFunction(__wxPen_1);
	Gura_AssignFunction(__wxPen_2);
	Gura_AssignFunction(__wxPen_3);
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
