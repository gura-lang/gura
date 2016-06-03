//----------------------------------------------------------------------------
// wxWebViewFSHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebViewFSHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebViewFSHandler
//----------------------------------------------------------------------------
Object_wx_WebViewFSHandler::~Object_wx_WebViewFSHandler()
{
}

Object *Object_wx_WebViewFSHandler::Clone() const
{
	return nullptr;
}

String Object_wx_WebViewFSHandler::ToString(bool exprFlag)
{
	String rtn("<wx.WebViewFSHandler:");
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
Gura_DeclareFunctionAlias(__wxWebViewFSHandler, "wxWebViewFSHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "scheme", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WebViewFSHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxWebViewFSHandler)
{
	//int scheme = arg.GetNumber(0)
	//wxWebViewFSHandler();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_WebViewFSHandler, __GetFile, "GetFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "uri", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebViewFSHandler, __GetFile)
{
	Object_wx_WebViewFSHandler *pThis = Object_wx_WebViewFSHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int uri = arg.GetNumber(0)
	//pThis->GetEntity()->GetFile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWebViewFSHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebViewFSHandler)
{
	// Constructor assignment
	Gura_AssignFunction(__wxWebViewFSHandler);
	// Method assignment
	Gura_AssignMethod(wx_WebViewFSHandler, __GetFile);
}

Gura_ImplementDescendantCreator(wx_WebViewFSHandler)
{
	return new Object_wx_WebViewFSHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
