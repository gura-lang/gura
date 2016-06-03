//----------------------------------------------------------------------------
// wxURL
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxURL
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxURL
//----------------------------------------------------------------------------
Object_wx_URL::~Object_wx_URL()
{
}

Object *Object_wx_URL::Clone() const
{
	return nullptr;
}

String Object_wx_URL::ToString(bool exprFlag)
{
	String rtn("<wx.URL:");
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
Gura_DeclareFunctionAlias(__URL, "URL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_URL));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__URL)
{
	//const wxString& url = arg.GetNumber(0)
	//wxURL();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_URL, __GetError, "GetError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URL, __GetError)
{
	Object_wx_URL *pThis = Object_wx_URL::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetError();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URL, __GetInputStream, "GetInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URL, __GetInputStream)
{
	Object_wx_URL *pThis = Object_wx_URL::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URL, __GetProtocol, "GetProtocol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URL, __GetProtocol)
{
	Object_wx_URL *pThis = Object_wx_URL::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetProtocol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URL, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URL, __IsOk)
{
	Object_wx_URL *pThis = Object_wx_URL::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URL, __SetDefaultProxy, "SetDefaultProxy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url_proxy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_URL, __SetDefaultProxy)
{
	Object_wx_URL *pThis = Object_wx_URL::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& url_proxy = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultProxy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URL, __SetProxy, "SetProxy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url_proxy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_URL, __SetProxy)
{
	Object_wx_URL *pThis = Object_wx_URL::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& url_proxy = arg.GetNumber(0)
	//pThis->GetEntity()->SetProxy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URL, __SetURL, "SetURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_URL, __SetURL)
{
	Object_wx_URL *pThis = Object_wx_URL::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& url = arg.GetNumber(0)
	//pThis->GetEntity()->SetURL();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxURL
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_URL)
{
	// Constructor assignment
	Gura_AssignFunction(__URL);
	// Method assignment
	Gura_AssignMethod(wx_URL, __GetError);
	Gura_AssignMethod(wx_URL, __GetInputStream);
	Gura_AssignMethod(wx_URL, __GetProtocol);
	Gura_AssignMethod(wx_URL, __IsOk);
	Gura_AssignMethod(wx_URL, __SetDefaultProxy);
	Gura_AssignMethod(wx_URL, __SetProxy);
	Gura_AssignMethod(wx_URL, __SetURL);
}

Gura_ImplementDescendantCreator(wx_URL)
{
	return new Object_wx_URL((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
