//----------------------------------------------------------------------------
// wxItemContainerImmutable
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxItemContainerImmutable
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxItemContainerImmutable
//----------------------------------------------------------------------------
Object_wx_ItemContainerImmutable::~Object_wx_ItemContainerImmutable()
{
}

Object *Object_wx_ItemContainerImmutable::Clone() const
{
	return nullptr;
}

String Object_wx_ItemContainerImmutable::ToString(bool exprFlag)
{
	String rtn("<wx.ItemContainerImmutable:");
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
Gura_DeclareMethod(wx_ItemContainerImmutable, wxItemContainerImmutable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, wxItemContainerImmutable)
{
	Signal &sig = env.GetSignal();
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxItemContainerImmutable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainerImmutable, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, GetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainerImmutable, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, IsEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainerImmutable, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, GetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainerImmutable, GetStrings)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, GetStrings)
{
	Signal &sig = env.GetSignal();
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStrings();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainerImmutable, SetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, SetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int string = arg.GetNumber(1)
	//pThis->GetEntity()->SetString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainerImmutable, FindString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caseSensitive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, FindString)
{
	Signal &sig = env.GetSignal();
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//int caseSensitive = arg.GetNumber(1)
	//pThis->GetEntity()->FindString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainerImmutable, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainerImmutable, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainerImmutable, SetStringSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, SetStringSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//pThis->GetEntity()->SetStringSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainerImmutable, GetStringSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, GetStringSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStringSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainerImmutable, Select)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, Select)
{
	Signal &sig = env.GetSignal();
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->Select();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxItemContainerImmutable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ItemContainerImmutable)
{
	Gura_AssignMethod(wx_ItemContainerImmutable, wxItemContainerImmutable);
	Gura_AssignMethod(wx_ItemContainerImmutable, GetCount);
	Gura_AssignMethod(wx_ItemContainerImmutable, IsEmpty);
	Gura_AssignMethod(wx_ItemContainerImmutable, GetString);
	Gura_AssignMethod(wx_ItemContainerImmutable, GetStrings);
	Gura_AssignMethod(wx_ItemContainerImmutable, SetString);
	Gura_AssignMethod(wx_ItemContainerImmutable, FindString);
	Gura_AssignMethod(wx_ItemContainerImmutable, SetSelection);
	Gura_AssignMethod(wx_ItemContainerImmutable, GetSelection);
	Gura_AssignMethod(wx_ItemContainerImmutable, SetStringSelection);
	Gura_AssignMethod(wx_ItemContainerImmutable, GetStringSelection);
	Gura_AssignMethod(wx_ItemContainerImmutable, Select);
}

Gura_ImplementDescendantCreator(wx_ItemContainerImmutable)
{
	return new Object_wx_ItemContainerImmutable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
