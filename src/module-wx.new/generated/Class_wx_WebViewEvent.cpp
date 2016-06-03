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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_WebViewEvent, __wxWebViewEvent, "wxWebViewEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebViewEvent, __wxWebViewEvent)
{
	Object_wx_WebViewEvent *pThis = Object_wx_WebViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxWebViewEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebViewEvent, __wxWebViewEvent_1, "wxWebViewEvent_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "href", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "target", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebViewEvent, __wxWebViewEvent_1)
{
	Object_wx_WebViewEvent *pThis = Object_wx_WebViewEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int href = arg.GetNumber(2)
	//int target = arg.GetNumber(3)
	//pThis->GetEntity()->wxWebViewEvent();
	return Value::Nil;
}

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
	Gura_AssignMethod(wx_WebViewEvent, __wxWebViewEvent);
	Gura_AssignMethod(wx_WebViewEvent, __wxWebViewEvent_1);
	Gura_AssignMethod(wx_WebViewEvent, __GetTarget);
	Gura_AssignMethod(wx_WebViewEvent, __GetURL);
}

Gura_ImplementDescendantCreator(wx_WebViewEvent)
{
	return new Object_wx_WebViewEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
