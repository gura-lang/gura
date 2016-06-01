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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Brush, wxBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Brush, wxBrush)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxBrush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, wxBrush_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, wxBrush_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->wxBrush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, wxBrush_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stippleBitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, wxBrush_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stippleBitmap = arg.GetNumber(0)
	//pThis->GetEntity()->wxBrush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, wxBrush_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "brush", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, wxBrush_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int brush = arg.GetNumber(0)
	//pThis->GetEntity()->wxBrush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, ~wxBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Brush, ~wxBrush)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxBrush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Brush, GetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, GetStipple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Brush, GetStipple)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStipple();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Brush, GetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, IsHatch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Brush, IsHatch)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsHatch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Brush, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, IsNonTransparent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Brush, IsNonTransparent)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsNonTransparent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, IsTransparent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Brush, IsTransparent)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsTransparent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, SetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, SetColour_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, SetColour_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int red = arg.GetNumber(0)
	//int green = arg.GetNumber(1)
	//int blue = arg.GetNumber(2)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, SetStipple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, SetStipple)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetStipple();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, SetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBrush
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Brush)
{
	Gura_AssignMethod(wx_Brush, wxBrush);
	Gura_AssignMethod(wx_Brush, wxBrush_1);
	Gura_AssignMethod(wx_Brush, wxBrush_2);
	Gura_AssignMethod(wx_Brush, wxBrush_3);
	Gura_AssignMethod(wx_Brush, ~wxBrush);
	Gura_AssignMethod(wx_Brush, GetColour);
	Gura_AssignMethod(wx_Brush, GetStipple);
	Gura_AssignMethod(wx_Brush, GetStyle);
	Gura_AssignMethod(wx_Brush, IsHatch);
	Gura_AssignMethod(wx_Brush, IsOk);
	Gura_AssignMethod(wx_Brush, IsNonTransparent);
	Gura_AssignMethod(wx_Brush, IsTransparent);
	Gura_AssignMethod(wx_Brush, SetColour);
	Gura_AssignMethod(wx_Brush, SetColour_1);
	Gura_AssignMethod(wx_Brush, SetStipple);
	Gura_AssignMethod(wx_Brush, SetStyle);
}

Gura_ImplementDescendantCreator(wx_Brush)
{
	return new Object_wx_Brush((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
