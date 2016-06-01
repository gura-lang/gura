//----------------------------------------------------------------------------
// wxTextAttrBorders
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttrBorders
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextAttrBorders
//----------------------------------------------------------------------------
Object_wx_TextAttrBorders::~Object_wx_TextAttrBorders()
{
}

Object *Object_wx_TextAttrBorders::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttrBorders::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttrBorders:");
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
Gura_DeclareMethod(wx_TextAttrBorders, wxTextAttrBorders)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, wxTextAttrBorders)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxTextAttrBorders();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorders, SetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorders, SetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, SetColour_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorders, SetColour_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorders, SetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, SetWidth_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorders, SetWidth_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int units = arg.GetNumber(1)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, Reset)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, EqPartial)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "borders", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weakTest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorders, EqPartial)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int borders = arg.GetNumber(0)
	//int weakTest = arg.GetNumber(1)
	//pThis->GetEntity()->EqPartial();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, Apply)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "borders", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "compareWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorders, Apply)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int borders = arg.GetNumber(0)
	//int compareWith = arg.GetNumber(1)
	//pThis->GetEntity()->Apply();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, RemoveStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorders, RemoveStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, CollectCommonAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clashingAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "absentAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorders, CollectCommonAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int clashingAttr = arg.GetNumber(1)
	//int absentAttr = arg.GetNumber(2)
	//pThis->GetEntity()->CollectCommonAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, IsValid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, IsValid)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsValid();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, GetLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, GetLeft)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, GetLeft_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, GetLeft_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, GetRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, GetRight)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, GetRight_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, GetRight_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, GetTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, GetTop)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, GetTop_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, GetTop_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, GetBottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, GetBottom)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorders, GetBottom_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorders, GetBottom_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrBorders *pThis = Object_wx_TextAttrBorders::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBottom();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextAttrBorders
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttrBorders)
{
	Gura_AssignMethod(wx_TextAttrBorders, wxTextAttrBorders);
	Gura_AssignMethod(wx_TextAttrBorders, SetStyle);
	Gura_AssignMethod(wx_TextAttrBorders, SetColour);
	Gura_AssignMethod(wx_TextAttrBorders, SetColour_1);
	Gura_AssignMethod(wx_TextAttrBorders, SetWidth);
	Gura_AssignMethod(wx_TextAttrBorders, SetWidth_1);
	Gura_AssignMethod(wx_TextAttrBorders, Reset);
	Gura_AssignMethod(wx_TextAttrBorders, EqPartial);
	Gura_AssignMethod(wx_TextAttrBorders, Apply);
	Gura_AssignMethod(wx_TextAttrBorders, RemoveStyle);
	Gura_AssignMethod(wx_TextAttrBorders, CollectCommonAttributes);
	Gura_AssignMethod(wx_TextAttrBorders, IsValid);
	Gura_AssignMethod(wx_TextAttrBorders, GetLeft);
	Gura_AssignMethod(wx_TextAttrBorders, GetLeft_1);
	Gura_AssignMethod(wx_TextAttrBorders, GetRight);
	Gura_AssignMethod(wx_TextAttrBorders, GetRight_1);
	Gura_AssignMethod(wx_TextAttrBorders, GetTop);
	Gura_AssignMethod(wx_TextAttrBorders, GetTop_1);
	Gura_AssignMethod(wx_TextAttrBorders, GetBottom);
	Gura_AssignMethod(wx_TextAttrBorders, GetBottom_1);
}

Gura_ImplementDescendantCreator(wx_TextAttrBorders)
{
	return new Object_wx_TextAttrBorders((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
