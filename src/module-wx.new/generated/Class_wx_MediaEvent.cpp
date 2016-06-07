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
Gura_DeclareFunctionAlias(__MediaEvent, "MediaEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_MediaEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MediaEvent)
{
	//wxEventType commandType = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//wxMediaEvent(commandType, winid);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMediaEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MediaEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__MediaEvent);
}

Gura_ImplementDescendantCreator(wx_MediaEvent)
{
	return new Object_wx_MediaEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
