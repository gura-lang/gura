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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__SysColourChangedEvent, "SysColourChangedEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SysColourChangedEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SysColourChangedEvent)
{
	//wxSysColourChangedEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSysColourChangedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SysColourChangedEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__SysColourChangedEvent);
}

Gura_ImplementDescendantCreator(wx_SysColourChangedEvent)
{
	return new Object_wx_SysColourChangedEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
