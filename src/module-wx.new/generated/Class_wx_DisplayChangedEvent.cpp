//----------------------------------------------------------------------------
// wxDisplayChangedEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDisplayChangedEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDisplayChangedEvent
//----------------------------------------------------------------------------
Object_wx_DisplayChangedEvent::~Object_wx_DisplayChangedEvent()
{
}

Object *Object_wx_DisplayChangedEvent::Clone() const
{
	return nullptr;
}

String Object_wx_DisplayChangedEvent::ToString(bool exprFlag)
{
	String rtn("<wx.DisplayChangedEvent:");
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
Gura_DeclareMethod(wx_DisplayChangedEvent, wxDisplayChangedEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DisplayChangedEvent, wxDisplayChangedEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_DisplayChangedEvent *pThis = Object_wx_DisplayChangedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxDisplayChangedEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDisplayChangedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DisplayChangedEvent)
{
	Gura_AssignMethod(wx_DisplayChangedEvent, wxDisplayChangedEvent);
}

Gura_ImplementDescendantCreator(wx_DisplayChangedEvent)
{
	return new Object_wx_DisplayChangedEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
