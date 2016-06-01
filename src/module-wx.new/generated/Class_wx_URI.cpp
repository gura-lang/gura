//----------------------------------------------------------------------------
// wxURI
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxURI
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxURI
//----------------------------------------------------------------------------
Object_wx_URI::~Object_wx_URI()
{
}

Object *Object_wx_URI::Clone() const
{
	return nullptr;
}

String Object_wx_URI::ToString(bool exprFlag)
{
	String rtn("<wx.URI:");
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
Gura_DeclareMethod(wx_URI, wxURI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, wxURI)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxURI();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, wxURI_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "uri", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_URI, wxURI_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int uri = arg.GetNumber(0)
	//pThis->GetEntity()->wxURI();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, wxURI_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "uri", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_URI, wxURI_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int uri = arg.GetNumber(0)
	//pThis->GetEntity()->wxURI();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, BuildURI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, BuildURI)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->BuildURI();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, BuildUnescapedURI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, BuildUnescapedURI)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->BuildUnescapedURI();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "uri", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_URI, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int uri = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, GetFragment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, GetFragment)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFragment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, GetHostType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, GetHostType)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHostType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, GetPassword)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, GetPassword)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPassword();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, GetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, GetPort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, GetPort)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPort();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, GetQuery)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, GetQuery)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetQuery();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, GetScheme)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, GetScheme)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetScheme();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, GetServer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, GetServer)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetServer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, GetUser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, GetUser)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetUser();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, GetUserInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, GetUserInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetUserInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, HasFragment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, HasFragment)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasFragment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, HasPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, HasPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, HasPort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, HasPort)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasPort();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, HasQuery)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, HasQuery)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasQuery();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, HasScheme)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, HasScheme)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasScheme();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, HasServer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, HasServer)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasServer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, HasUserInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, HasUserInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasUserInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, IsReference)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URI, IsReference)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsReference();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, Resolve)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_URI, Resolve)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Resolve();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, Unescape)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "uri", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_URI, Unescape)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int uri = arg.GetNumber(0)
	//pThis->GetEntity()->Unescape();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxURI
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_URI)
{
	Gura_AssignMethod(wx_URI, wxURI);
	Gura_AssignMethod(wx_URI, wxURI_1);
	Gura_AssignMethod(wx_URI, wxURI_2);
	Gura_AssignMethod(wx_URI, BuildURI);
	Gura_AssignMethod(wx_URI, BuildUnescapedURI);
	Gura_AssignMethod(wx_URI, Create);
	Gura_AssignMethod(wx_URI, GetFragment);
	Gura_AssignMethod(wx_URI, GetHostType);
	Gura_AssignMethod(wx_URI, GetPassword);
	Gura_AssignMethod(wx_URI, GetPath);
	Gura_AssignMethod(wx_URI, GetPort);
	Gura_AssignMethod(wx_URI, GetQuery);
	Gura_AssignMethod(wx_URI, GetScheme);
	Gura_AssignMethod(wx_URI, GetServer);
	Gura_AssignMethod(wx_URI, GetUser);
	Gura_AssignMethod(wx_URI, GetUserInfo);
	Gura_AssignMethod(wx_URI, HasFragment);
	Gura_AssignMethod(wx_URI, HasPath);
	Gura_AssignMethod(wx_URI, HasPort);
	Gura_AssignMethod(wx_URI, HasQuery);
	Gura_AssignMethod(wx_URI, HasScheme);
	Gura_AssignMethod(wx_URI, HasServer);
	Gura_AssignMethod(wx_URI, HasUserInfo);
	Gura_AssignMethod(wx_URI, IsReference);
	Gura_AssignMethod(wx_URI, Resolve);
	Gura_AssignMethod(wx_URI, Unescape);
}

Gura_ImplementDescendantCreator(wx_URI)
{
	return new Object_wx_URI((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
