//----------------------------------------------------------------------------
// wxSystemOptions
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSystemOptions
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSystemOptions
//----------------------------------------------------------------------------
Object_wx_SystemOptions::~Object_wx_SystemOptions()
{
}

Object *Object_wx_SystemOptions::Clone() const
{
	return nullptr;
}

String Object_wx_SystemOptions::ToString(bool exprFlag)
{
	String rtn("<wx.SystemOptions:");
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
Gura_DeclareMethod(wx_SystemOptions, wxSystemOptions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SystemOptions, wxSystemOptions)
{
	Signal &sig = env.GetSignal();
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxSystemOptions();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SystemOptions, GetOption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemOptions, GetOption)
{
	Signal &sig = env.GetSignal();
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetOption();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SystemOptions, GetOptionInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemOptions, GetOptionInt)
{
	Signal &sig = env.GetSignal();
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetOptionInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SystemOptions, HasOption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemOptions, HasOption)
{
	Signal &sig = env.GetSignal();
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->HasOption();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SystemOptions, IsFalse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemOptions, IsFalse)
{
	Signal &sig = env.GetSignal();
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->IsFalse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SystemOptions, SetOption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemOptions, SetOption)
{
	Signal &sig = env.GetSignal();
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->SetOption();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SystemOptions, SetOption_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemOptions, SetOption_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->SetOption();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSystemOptions
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SystemOptions)
{
	Gura_AssignMethod(wx_SystemOptions, wxSystemOptions);
	Gura_AssignMethod(wx_SystemOptions, GetOption);
	Gura_AssignMethod(wx_SystemOptions, GetOptionInt);
	Gura_AssignMethod(wx_SystemOptions, HasOption);
	Gura_AssignMethod(wx_SystemOptions, IsFalse);
	Gura_AssignMethod(wx_SystemOptions, SetOption);
	Gura_AssignMethod(wx_SystemOptions, SetOption_1);
}

Gura_ImplementDescendantCreator(wx_SystemOptions)
{
	return new Object_wx_SystemOptions((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
