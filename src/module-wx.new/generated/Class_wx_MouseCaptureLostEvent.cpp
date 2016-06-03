//----------------------------------------------------------------------------
// wxMouseCaptureLostEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMouseCaptureLostEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMouseCaptureLostEvent
//----------------------------------------------------------------------------
Object_wx_MouseCaptureLostEvent::~Object_wx_MouseCaptureLostEvent()
{
}

Object *Object_wx_MouseCaptureLostEvent::Clone() const
{
	return nullptr;
}

String Object_wx_MouseCaptureLostEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MouseCaptureLostEvent:");
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
Gura_DeclareFunctionAlias(__wxMouseCaptureLostEvent, "wxMouseCaptureLostEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "windowId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxMouseCaptureLostEvent)
{
	//int windowId = arg.GetNumber(0)
	//wxMouseCaptureLostEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMouseCaptureLostEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseCaptureLostEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__wxMouseCaptureLostEvent);
}

Gura_ImplementDescendantCreator(wx_MouseCaptureLostEvent)
{
	return new Object_wx_MouseCaptureLostEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
