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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__URI, "URI")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_URI));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__URI)
{
	//wxURI();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__URI_1, "URI_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "uri", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_URI));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__URI_1)
{
	//const wxString& uri = arg.GetNumber(0)
	//wxURI(uri);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__URI_2, "URI_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "uri", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_URI));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__URI_2)
{
	//const wxURI& uri = arg.GetNumber(0)
	//wxURI(uri);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_URI, __BuildURI, "BuildURI")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __BuildURI)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->BuildURI();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __BuildUnescapedURI, "BuildUnescapedURI")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __BuildUnescapedURI)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->BuildUnescapedURI();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "uri", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_URI, __Create)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& uri = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Create(uri);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __GetFragment, "GetFragment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __GetFragment)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetFragment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __GetHostType, "GetHostType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __GetHostType)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxURIHostType _rtn = pThis->GetEntity()->GetHostType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __GetPassword, "GetPassword")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __GetPassword)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetPassword();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __GetPath, "GetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __GetPath)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __GetPort, "GetPort")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __GetPort)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetPort();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __GetQuery, "GetQuery")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __GetQuery)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetQuery();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __GetScheme, "GetScheme")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __GetScheme)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetScheme();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __GetServer, "GetServer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __GetServer)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetServer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __GetUser, "GetUser")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __GetUser)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetUser();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __GetUserInfo, "GetUserInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __GetUserInfo)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetUserInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __HasFragment, "HasFragment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __HasFragment)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasFragment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __HasPath, "HasPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __HasPath)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __HasPort, "HasPort")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __HasPort)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasPort();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __HasQuery, "HasQuery")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __HasQuery)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasQuery();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __HasScheme, "HasScheme")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __HasScheme)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasScheme();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __HasServer, "HasServer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __HasServer)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasServer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __HasUserInfo, "HasUserInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __HasUserInfo)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasUserInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __IsReference, "IsReference")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_URI, __IsReference)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsReference();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __Resolve, "Resolve")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_URI, __Resolve)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxURI& base = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Resolve(base, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URI, __Unescape, "Unescape")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "uri", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_URI, __Unescape)
{
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& uri = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->Unescape(uri);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxURI
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_URI)
{
	// Constructor assignment
	Gura_AssignFunction(__URI);
	Gura_AssignFunction(__URI_1);
	Gura_AssignFunction(__URI_2);
	// Method assignment
	Gura_AssignMethod(wx_URI, __BuildURI);
	Gura_AssignMethod(wx_URI, __BuildUnescapedURI);
	Gura_AssignMethod(wx_URI, __Create);
	Gura_AssignMethod(wx_URI, __GetFragment);
	Gura_AssignMethod(wx_URI, __GetHostType);
	Gura_AssignMethod(wx_URI, __GetPassword);
	Gura_AssignMethod(wx_URI, __GetPath);
	Gura_AssignMethod(wx_URI, __GetPort);
	Gura_AssignMethod(wx_URI, __GetQuery);
	Gura_AssignMethod(wx_URI, __GetScheme);
	Gura_AssignMethod(wx_URI, __GetServer);
	Gura_AssignMethod(wx_URI, __GetUser);
	Gura_AssignMethod(wx_URI, __GetUserInfo);
	Gura_AssignMethod(wx_URI, __HasFragment);
	Gura_AssignMethod(wx_URI, __HasPath);
	Gura_AssignMethod(wx_URI, __HasPort);
	Gura_AssignMethod(wx_URI, __HasQuery);
	Gura_AssignMethod(wx_URI, __HasScheme);
	Gura_AssignMethod(wx_URI, __HasServer);
	Gura_AssignMethod(wx_URI, __HasUserInfo);
	Gura_AssignMethod(wx_URI, __IsReference);
	Gura_AssignMethod(wx_URI, __Resolve);
	Gura_AssignMethod(wx_URI, __Unescape);
}

Gura_ImplementDescendantCreator(wx_URI)
{
	return new Object_wx_URI((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
