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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__WebViewHandler, "WebViewHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "scheme", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WebViewHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WebViewHandler)
{
	//const wxString& scheme = arg.GetNumber(0)
	//wxWebViewHandler(scheme);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_WebViewHandler, __GetFile, "GetFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "uri", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebViewHandler, __GetFile)
{
	Object_wx_WebViewHandler *pThis = Object_wx_WebViewHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& uri = arg.GetNumber(0)
	//pThis->GetEntity()->GetFile(uri);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebViewHandler, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebViewHandler, __GetName)
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
	// Constructor assignment
	Gura_AssignFunction(__WebViewHandler);
	// Method assignment
	Gura_AssignMethod(wx_WebViewHandler, __GetFile);
	Gura_AssignMethod(wx_WebViewHandler, __GetName);
}

Gura_ImplementDescendantCreator(wx_WebViewHandler)
{
	return new Object_wx_WebViewHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
