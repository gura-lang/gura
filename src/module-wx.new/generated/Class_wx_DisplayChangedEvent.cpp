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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__DisplayChangedEvent, "DisplayChangedEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DisplayChangedEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DisplayChangedEvent)
{
	//wxDisplayChangedEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDisplayChangedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DisplayChangedEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__DisplayChangedEvent);
}

Gura_ImplementDescendantCreator(wx_DisplayChangedEvent)
{
	return new Object_wx_DisplayChangedEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
