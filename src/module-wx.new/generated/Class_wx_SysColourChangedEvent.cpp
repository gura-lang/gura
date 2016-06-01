//----------------------------------------------------------------------------
// wxSysColourChangedEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSysColourChangedEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSysColourChangedEvent
//----------------------------------------------------------------------------
Object_wx_SysColourChangedEvent::~Object_wx_SysColourChangedEvent()
{
}

Object *Object_wx_SysColourChangedEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SysColourChangedEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SysColourChangedEvent:");
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
Gura_DeclareMethod(wx_SysColourChangedEvent, wxSysColourChangedEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SysColourChangedEvent, wxSysColourChangedEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_SysColourChangedEvent *pThis = Object_wx_SysColourChangedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxSysColourChangedEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSysColourChangedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SysColourChangedEvent)
{
	Gura_AssignMethod(wx_SysColourChangedEvent, wxSysColourChangedEvent);
}

Gura_ImplementDescendantCreator(wx_SysColourChangedEvent)
{
	return new Object_wx_SysColourChangedEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
