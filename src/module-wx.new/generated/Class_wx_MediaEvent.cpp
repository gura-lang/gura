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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_MediaEvent, wxMediaEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaEvent, wxMediaEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_MediaEvent *pThis = Object_wx_MediaEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int commandType = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//pThis->GetEntity()->wxMediaEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMediaEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MediaEvent)
{
	Gura_AssignMethod(wx_MediaEvent, wxMediaEvent);
}

Gura_ImplementDescendantCreator(wx_MediaEvent)
{
	return new Object_wx_MediaEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
