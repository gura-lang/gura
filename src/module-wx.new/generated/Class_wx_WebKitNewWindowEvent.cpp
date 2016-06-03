//----------------------------------------------------------------------------
// wxWebKitNewWindowEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebKitNewWindowEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebKitNewWindowEvent
//----------------------------------------------------------------------------
Object_wx_WebKitNewWindowEvent::~Object_wx_WebKitNewWindowEvent()
{
}

Object *Object_wx_WebKitNewWindowEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WebKitNewWindowEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WebKitNewWindowEvent:");
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
Gura_DeclareFunctionAlias(__WebKitNewWindowEvent, "WebKitNewWindowEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WebKitNewWindowEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WebKitNewWindowEvent)
{
	//wxWindow* win = arg.GetNumber(0)
	//wxWebKitNewWindowEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_WebKitNewWindowEvent, __GetURL, "GetURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitNewWindowEvent, __GetURL)
{
	Object_wx_WebKitNewWindowEvent *pThis = Object_wx_WebKitNewWindowEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitNewWindowEvent, __SetURL, "SetURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitNewWindowEvent, __SetURL)
{
	Object_wx_WebKitNewWindowEvent *pThis = Object_wx_WebKitNewWindowEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& url = arg.GetNumber(0)
	//pThis->GetEntity()->SetURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitNewWindowEvent, __GetTargetName, "GetTargetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitNewWindowEvent, __GetTargetName)
{
	Object_wx_WebKitNewWindowEvent *pThis = Object_wx_WebKitNewWindowEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTargetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitNewWindowEvent, __SetTargetName, "SetTargetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitNewWindowEvent, __SetTargetName)
{
	Object_wx_WebKitNewWindowEvent *pThis = Object_wx_WebKitNewWindowEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetTargetName();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWebKitNewWindowEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebKitNewWindowEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__WebKitNewWindowEvent);
	// Method assignment
	Gura_AssignMethod(wx_WebKitNewWindowEvent, __GetURL);
	Gura_AssignMethod(wx_WebKitNewWindowEvent, __SetURL);
	Gura_AssignMethod(wx_WebKitNewWindowEvent, __GetTargetName);
	Gura_AssignMethod(wx_WebKitNewWindowEvent, __SetTargetName);
}

Gura_ImplementDescendantCreator(wx_WebKitNewWindowEvent)
{
	return new Object_wx_WebKitNewWindowEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
