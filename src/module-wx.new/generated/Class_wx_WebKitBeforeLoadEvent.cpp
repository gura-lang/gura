//----------------------------------------------------------------------------
// wxWebKitBeforeLoadEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebKitBeforeLoadEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebKitBeforeLoadEvent
//----------------------------------------------------------------------------
Object_wx_WebKitBeforeLoadEvent::~Object_wx_WebKitBeforeLoadEvent()
{
}

Object *Object_wx_WebKitBeforeLoadEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WebKitBeforeLoadEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WebKitBeforeLoadEvent:");
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
Gura_DeclareFunctionAlias(__WebKitBeforeLoadEvent, "WebKitBeforeLoadEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WebKitBeforeLoadEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WebKitBeforeLoadEvent)
{
	//wxWindow* win = arg.GetNumber(0)
	//wxWebKitBeforeLoadEvent(win);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_WebKitBeforeLoadEvent, __IsCancelled, "IsCancelled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitBeforeLoadEvent, __IsCancelled)
{
	Object_wx_WebKitBeforeLoadEvent *pThis = Object_wx_WebKitBeforeLoadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsCancelled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitBeforeLoadEvent, __Cancel, "Cancel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cancel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitBeforeLoadEvent, __Cancel)
{
	Object_wx_WebKitBeforeLoadEvent *pThis = Object_wx_WebKitBeforeLoadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool cancel = arg.GetNumber(0)
	//pThis->GetEntity()->Cancel(cancel);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitBeforeLoadEvent, __GetURL, "GetURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitBeforeLoadEvent, __GetURL)
{
	Object_wx_WebKitBeforeLoadEvent *pThis = Object_wx_WebKitBeforeLoadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitBeforeLoadEvent, __SetURL, "SetURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitBeforeLoadEvent, __SetURL)
{
	Object_wx_WebKitBeforeLoadEvent *pThis = Object_wx_WebKitBeforeLoadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& url = arg.GetNumber(0)
	//pThis->GetEntity()->SetURL(url);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitBeforeLoadEvent, __SetNavigationType, "SetNavigationType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "navType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitBeforeLoadEvent, __SetNavigationType)
{
	Object_wx_WebKitBeforeLoadEvent *pThis = Object_wx_WebKitBeforeLoadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int navType = arg.GetNumber(0)
	//pThis->GetEntity()->SetNavigationType(navType);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitBeforeLoadEvent, __GetNavigationType, "GetNavigationType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitBeforeLoadEvent, __GetNavigationType)
{
	Object_wx_WebKitBeforeLoadEvent *pThis = Object_wx_WebKitBeforeLoadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNavigationType();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWebKitBeforeLoadEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebKitBeforeLoadEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__WebKitBeforeLoadEvent);
	// Method assignment
	Gura_AssignMethod(wx_WebKitBeforeLoadEvent, __IsCancelled);
	Gura_AssignMethod(wx_WebKitBeforeLoadEvent, __Cancel);
	Gura_AssignMethod(wx_WebKitBeforeLoadEvent, __GetURL);
	Gura_AssignMethod(wx_WebKitBeforeLoadEvent, __SetURL);
	Gura_AssignMethod(wx_WebKitBeforeLoadEvent, __SetNavigationType);
	Gura_AssignMethod(wx_WebKitBeforeLoadEvent, __GetNavigationType);
}

Gura_ImplementDescendantCreator(wx_WebKitBeforeLoadEvent)
{
	return new Object_wx_WebKitBeforeLoadEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
