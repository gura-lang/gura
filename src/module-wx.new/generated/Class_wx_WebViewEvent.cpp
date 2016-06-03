//----------------------------------------------------------------------------
// wxWebViewEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebViewEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebViewEvent
//----------------------------------------------------------------------------
Object_wx_WebViewEvent::~Object_wx_WebViewEvent()
{
}

Object *Object_wx_WebViewEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WebViewEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WebViewEvent:");
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
Gura_DeclareFunctionAlias(__WebViewEvent, "WebViewEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_WebViewEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WebViewEvent)
{
	//wxWebViewEvent();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__WebViewEvent_1, "WebViewEvent_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "href", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "target", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WebViewEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WebViewEvent_1)
{
	//int type = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int href = arg.GetNumber(2)
	//int target = arg.GetNumber(3)
	//wxWebViewEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_WebViewEvent, __GetTarget, "GetTarget")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebViewEvent, __GetTarget)
{
	Object_wx_WebViewEvent *pThis = Object_wx_WebViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTarget();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebViewEvent, __GetURL, "GetURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebViewEvent, __GetURL)
{
	Object_wx_WebViewEvent *pThis = Object_wx_WebViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetURL();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWebViewEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebViewEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__WebViewEvent);
	Gura_AssignFunction(__WebViewEvent_1);
	// Method assignment
	Gura_AssignMethod(wx_WebViewEvent, __GetTarget);
	Gura_AssignMethod(wx_WebViewEvent, __GetURL);
}

Gura_ImplementDescendantCreator(wx_WebViewEvent)
{
	return new Object_wx_WebViewEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
