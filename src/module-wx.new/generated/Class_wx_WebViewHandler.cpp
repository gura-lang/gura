//----------------------------------------------------------------------------
// wxWebViewHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebViewHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebViewHandler
//----------------------------------------------------------------------------
Object_wx_WebViewHandler::~Object_wx_WebViewHandler()
{
}

Object *Object_wx_WebViewHandler::Clone() const
{
	return nullptr;
}

String Object_wx_WebViewHandler::ToString(bool exprFlag)
{
	String rtn("<wx.WebViewHandler:");
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
Gura_DeclareMethod(wx_WebViewHandler, wxWebViewHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "scheme", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebViewHandler, wxWebViewHandler)
{
	Object_wx_WebViewHandler *pThis = Object_wx_WebViewHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int scheme = arg.GetNumber(0)
	//pThis->GetEntity()->wxWebViewHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebViewHandler, GetFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "uri", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebViewHandler, GetFile)
{
	Object_wx_WebViewHandler *pThis = Object_wx_WebViewHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int uri = arg.GetNumber(0)
	//pThis->GetEntity()->GetFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebViewHandler, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebViewHandler, GetName)
{
	Object_wx_WebViewHandler *pThis = Object_wx_WebViewHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWebViewHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebViewHandler)
{
	Gura_AssignMethod(wx_WebViewHandler, wxWebViewHandler);
	Gura_AssignMethod(wx_WebViewHandler, GetFile);
	Gura_AssignMethod(wx_WebViewHandler, GetName);
}

Gura_ImplementDescendantCreator(wx_WebViewHandler)
{
	return new Object_wx_WebViewHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
