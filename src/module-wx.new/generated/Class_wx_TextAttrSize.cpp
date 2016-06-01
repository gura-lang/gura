//----------------------------------------------------------------------------
// wxTextAttrSize
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttrSize
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextAttrSize
//----------------------------------------------------------------------------
Object_wx_TextAttrSize::~Object_wx_TextAttrSize()
{
}

Object *Object_wx_TextAttrSize::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttrSize::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttrSize:");
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
Gura_DeclareMethod(wx_TextAttrSize, wxTextAttrSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrSize, wxTextAttrSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxTextAttrSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrSize, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrSize, Reset)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrSize, EqPartial)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weakTest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, EqPartial)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//int weakTest = arg.GetNumber(1)
	//pThis->GetEntity()->EqPartial();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrSize, Apply)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dims", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "compareWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, Apply)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dims = arg.GetNumber(0)
	//int compareWith = arg.GetNumber(1)
	//pThis->GetEntity()->Apply();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrSize, CollectCommonAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clashingAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "absentAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, CollectCommonAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int clashingAttr = arg.GetNumber(1)
	//int absentAttr = arg.GetNumber(2)
	//pThis->GetEntity()->CollectCommonAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrSize, RemoveStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, RemoveStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrSize, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrSize, GetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrSize, GetWidth_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrSize, GetWidth_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrSize, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, SetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrSize, SetWidth_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, SetWidth_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int units = arg.GetNumber(1)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrSize, SetWidth_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dim", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, SetWidth_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dim = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrSize, GetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrSize, GetHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrSize, GetHeight_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrSize, GetHeight_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrSize, SetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, SetHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->SetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrSize, SetHeight_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, SetHeight_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int units = arg.GetNumber(1)
	//pThis->GetEntity()->SetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrSize, SetHeight_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dim", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, SetHeight_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dim = arg.GetNumber(0)
	//pThis->GetEntity()->SetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrSize, IsValid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrSize, IsValid)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsValid();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextAttrSize
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttrSize)
{
	Gura_AssignMethod(wx_TextAttrSize, wxTextAttrSize);
	Gura_AssignMethod(wx_TextAttrSize, Reset);
	Gura_AssignMethod(wx_TextAttrSize, EqPartial);
	Gura_AssignMethod(wx_TextAttrSize, Apply);
	Gura_AssignMethod(wx_TextAttrSize, CollectCommonAttributes);
	Gura_AssignMethod(wx_TextAttrSize, RemoveStyle);
	Gura_AssignMethod(wx_TextAttrSize, GetWidth);
	Gura_AssignMethod(wx_TextAttrSize, GetWidth_1);
	Gura_AssignMethod(wx_TextAttrSize, SetWidth);
	Gura_AssignMethod(wx_TextAttrSize, SetWidth_1);
	Gura_AssignMethod(wx_TextAttrSize, SetWidth_2);
	Gura_AssignMethod(wx_TextAttrSize, GetHeight);
	Gura_AssignMethod(wx_TextAttrSize, GetHeight_1);
	Gura_AssignMethod(wx_TextAttrSize, SetHeight);
	Gura_AssignMethod(wx_TextAttrSize, SetHeight_1);
	Gura_AssignMethod(wx_TextAttrSize, SetHeight_2);
	Gura_AssignMethod(wx_TextAttrSize, IsValid);
}

Gura_ImplementDescendantCreator(wx_TextAttrSize)
{
	return new Object_wx_TextAttrSize((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
