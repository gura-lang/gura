//----------------------------------------------------------------------------
// wxWebViewArchiveHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebViewArchiveHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebViewArchiveHandler
//----------------------------------------------------------------------------
Object_wx_WebViewArchiveHandler::~Object_wx_WebViewArchiveHandler()
{
}

Object *Object_wx_WebViewArchiveHandler::Clone() const
{
	return nullptr;
}

String Object_wx_WebViewArchiveHandler::ToString(bool exprFlag)
{
	String rtn("<wx.WebViewArchiveHandler:");
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
Gura_DeclareMethod(wx_WebViewArchiveHandler, wxWebViewArchiveHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "scheme", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebViewArchiveHandler, wxWebViewArchiveHandler)
{
	Object_wx_WebViewArchiveHandler *pThis = Object_wx_WebViewArchiveHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int scheme = arg.GetNumber(0)
	//pThis->GetEntity()->wxWebViewArchiveHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebViewArchiveHandler, GetFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "uri", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebViewArchiveHandler, GetFile)
{
	Object_wx_WebViewArchiveHandler *pThis = Object_wx_WebViewArchiveHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int uri = arg.GetNumber(0)
	//pThis->GetEntity()->GetFile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWebViewArchiveHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebViewArchiveHandler)
{
	Gura_AssignMethod(wx_WebViewArchiveHandler, wxWebViewArchiveHandler);
	Gura_AssignMethod(wx_WebViewArchiveHandler, GetFile);
}

Gura_ImplementDescendantCreator(wx_WebViewArchiveHandler)
{
	return new Object_wx_WebViewArchiveHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
