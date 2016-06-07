//----------------------------------------------------------------------------
// wxTaskBarIconEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTaskBarIconEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTaskBarIconEvent
//----------------------------------------------------------------------------
Object_wx_TaskBarIconEvent::~Object_wx_TaskBarIconEvent()
{
}

Object *Object_wx_TaskBarIconEvent::Clone() const
{
	return nullptr;
}

String Object_wx_TaskBarIconEvent::ToString(bool exprFlag)
{
	String rtn("<wx.TaskBarIconEvent:");
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
Gura_DeclareFunctionAlias(__TaskBarIconEvent, "TaskBarIconEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "evtType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tbIcon", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TaskBarIconEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TaskBarIconEvent)
{
	//wxEventType evtType = arg.GetNumber(0)
	//wxTaskBarIcon* tbIcon = arg.GetNumber(1)
	//wxTaskBarIconEvent(evtType, tbIcon);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTaskBarIconEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TaskBarIconEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__TaskBarIconEvent);
}

Gura_ImplementDescendantCreator(wx_TaskBarIconEvent)
{
	return new Object_wx_TaskBarIconEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
