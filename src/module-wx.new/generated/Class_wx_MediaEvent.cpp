//----------------------------------------------------------------------------
// wxMediaEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMediaEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMediaEvent
//----------------------------------------------------------------------------
Object_wx_MediaEvent::~Object_wx_MediaEvent()
{
}

Object *Object_wx_MediaEvent::Clone() const
{
	return nullptr;
}

String Object_wx_MediaEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MediaEvent:");
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
Gura_DeclareFunctionAlias(__wxMediaEvent, "wxMediaEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxMediaEvent)
{
	//int commandType = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//wxMediaEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMediaEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MediaEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__wxMediaEvent);
}

Gura_ImplementDescendantCreator(wx_MediaEvent)
{
	return new Object_wx_MediaEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
