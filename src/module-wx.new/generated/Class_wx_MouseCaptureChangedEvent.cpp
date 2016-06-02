//----------------------------------------------------------------------------
// wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------
Object_wx_MouseCaptureChangedEvent::~Object_wx_MouseCaptureChangedEvent()
{
}

Object *Object_wx_MouseCaptureChangedEvent::Clone() const
{
	return nullptr;
}

String Object_wx_MouseCaptureChangedEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MouseCaptureChangedEvent:");
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
Gura_DeclareMethod(wx_MouseCaptureChangedEvent, wxMouseCaptureChangedEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "windowId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "gainedCapture", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseCaptureChangedEvent, wxMouseCaptureChangedEvent)
{
	Object_wx_MouseCaptureChangedEvent *pThis = Object_wx_MouseCaptureChangedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int windowId = arg.GetNumber(0)
	//int gainedCapture = arg.GetNumber(1)
	//pThis->GetEntity()->wxMouseCaptureChangedEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseCaptureChangedEvent, GetCapturedWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseCaptureChangedEvent, GetCapturedWindow)
{
	Object_wx_MouseCaptureChangedEvent *pThis = Object_wx_MouseCaptureChangedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCapturedWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseCaptureChangedEvent)
{
	Gura_AssignMethod(wx_MouseCaptureChangedEvent, wxMouseCaptureChangedEvent);
	Gura_AssignMethod(wx_MouseCaptureChangedEvent, GetCapturedWindow);
}

Gura_ImplementDescendantCreator(wx_MouseCaptureChangedEvent)
{
	return new Object_wx_MouseCaptureChangedEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
