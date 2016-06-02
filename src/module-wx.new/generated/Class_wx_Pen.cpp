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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Pen, wxPen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, wxPen)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxPen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, wxPen_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, wxPen_1)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->wxPen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, wxPen_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stipple", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, wxPen_2)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stipple = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//pThis->GetEntity()->wxPen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, wxPen_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, wxPen_3)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pen = arg.GetNumber(0)
	//pThis->GetEntity()->wxPen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, GetCap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, GetCap)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, GetColour)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, GetDashes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dashes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, GetDashes)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dashes = arg.GetNumber(0)
	//pThis->GetEntity()->GetDashes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, GetJoin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, GetJoin)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetJoin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, GetStipple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, GetStipple)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStipple();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, GetStyle)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, GetWidth)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, IsOk)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, IsNonTransparent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, IsNonTransparent)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsNonTransparent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, IsTransparent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Pen, IsTransparent)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsTransparent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, SetCap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "capStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetCap)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int capStyle = arg.GetNumber(0)
	//pThis->GetEntity()->SetCap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetColour)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, SetColour_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetColour_1)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int red = arg.GetNumber(0)
	//int green = arg.GetNumber(1)
	//int blue = arg.GetNumber(2)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, SetDashes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dash", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetDashes)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int dash = arg.GetNumber(1)
	//pThis->GetEntity()->SetDashes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, SetJoin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "join_style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetJoin)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int join_style = arg.GetNumber(0)
	//pThis->GetEntity()->SetJoin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, SetStipple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stipple", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetStipple)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stipple = arg.GetNumber(0)
	//pThis->GetEntity()->SetStipple();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetStyle)
{
	Object_wx_Pen *pThis = Object_wx_Pen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Pen, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetWidth)
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
	Gura_AssignMethod(wx_Pen, wxPen);
	Gura_AssignMethod(wx_Pen, wxPen_1);
	Gura_AssignMethod(wx_Pen, wxPen_2);
	Gura_AssignMethod(wx_Pen, wxPen_3);
	Gura_AssignMethod(wx_Pen, GetCap);
	Gura_AssignMethod(wx_Pen, GetColour);
	Gura_AssignMethod(wx_Pen, GetDashes);
	Gura_AssignMethod(wx_Pen, GetJoin);
	Gura_AssignMethod(wx_Pen, GetStipple);
	Gura_AssignMethod(wx_Pen, GetStyle);
	Gura_AssignMethod(wx_Pen, GetWidth);
	Gura_AssignMethod(wx_Pen, IsOk);
	Gura_AssignMethod(wx_Pen, IsNonTransparent);
	Gura_AssignMethod(wx_Pen, IsTransparent);
	Gura_AssignMethod(wx_Pen, SetCap);
	Gura_AssignMethod(wx_Pen, SetColour);
	Gura_AssignMethod(wx_Pen, SetColour_1);
	Gura_AssignMethod(wx_Pen, SetDashes);
	Gura_AssignMethod(wx_Pen, SetJoin);
	Gura_AssignMethod(wx_Pen, SetStipple);
	Gura_AssignMethod(wx_Pen, SetStyle);
	Gura_AssignMethod(wx_Pen, SetWidth);
}

Gura_ImplementDescendantCreator(wx_Pen)
{
	return new Object_wx_Pen((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
