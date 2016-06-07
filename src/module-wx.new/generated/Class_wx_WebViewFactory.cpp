//----------------------------------------------------------------------------
// wxWebViewFactory
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebViewFactory
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebViewFactory
//----------------------------------------------------------------------------
Object_wx_WebViewFactory::~Object_wx_WebViewFactory()
{
}

Object *Object_wx_WebViewFactory::Clone() const
{
	return nullptr;
}

String Object_wx_WebViewFactory::ToString(bool exprFlag)
{
	String rtn("<wx.WebViewFactory:");
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
Gura_DeclareMethodAlias(wx_WebViewFactory, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebViewFactory, __Create)
{
	Object_wx_WebViewFactory *pThis = Object_wx_WebViewFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebViewFactory, __Create_1, "Create_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebViewFactory, __Create_1)
{
	Object_wx_WebViewFactory *pThis = Object_wx_WebViewFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& url = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//pThis->GetEntity()->Create(parent, id, url, pos, size, style, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWebViewFactory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebViewFactory)
{
	// Class assignment
	Gura_AssignValueEx("WebViewFactory", Reference());
	// Method assignment
	Gura_AssignMethod(wx_WebViewFactory, __Create);
	Gura_AssignMethod(wx_WebViewFactory, __Create_1);
}

Gura_ImplementDescendantCreator(wx_WebViewFactory)
{
	return new Object_wx_WebViewFactory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
