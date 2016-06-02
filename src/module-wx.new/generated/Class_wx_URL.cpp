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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_URL, wxURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_URL, wxURL)
{
	Object_wx_URL *pThis = Object_wx_URL::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//pThis->GetEntity()->wxURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URL, GetError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URL, GetError)
{
	Object_wx_URL *pThis = Object_wx_URL::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetError();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URL, GetInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URL, GetInputStream)
{
	Object_wx_URL *pThis = Object_wx_URL::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URL, GetProtocol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URL, GetProtocol)
{
	Object_wx_URL *pThis = Object_wx_URL::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetProtocol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URL, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URL, IsOk)
{
	Object_wx_URL *pThis = Object_wx_URL::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URL, SetDefaultProxy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url_proxy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_URL, SetDefaultProxy)
{
	Object_wx_URL *pThis = Object_wx_URL::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int url_proxy = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultProxy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URL, SetProxy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url_proxy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_URL, SetProxy)
{
	Object_wx_URL *pThis = Object_wx_URL::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int url_proxy = arg.GetNumber(0)
	//pThis->GetEntity()->SetProxy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URL, SetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_URL, SetURL)
{
	Object_wx_URL *pThis = Object_wx_URL::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//pThis->GetEntity()->SetURL();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxURL
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_URL)
{
	Gura_AssignMethod(wx_URL, wxURL);
	Gura_AssignMethod(wx_URL, GetError);
	Gura_AssignMethod(wx_URL, GetInputStream);
	Gura_AssignMethod(wx_URL, GetProtocol);
	Gura_AssignMethod(wx_URL, IsOk);
	Gura_AssignMethod(wx_URL, SetDefaultProxy);
	Gura_AssignMethod(wx_URL, SetProxy);
	Gura_AssignMethod(wx_URL, SetURL);
}

Gura_ImplementDescendantCreator(wx_URL)
{
	return new Object_wx_URL((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
