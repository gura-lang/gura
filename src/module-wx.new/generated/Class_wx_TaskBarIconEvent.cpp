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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_TaskBarIconEvent, wxTaskBarIconEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "evtType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tbIcon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarIconEvent, wxTaskBarIconEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarIconEvent *pThis = Object_wx_TaskBarIconEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int evtType = arg.GetNumber(0)
	//int tbIcon = arg.GetNumber(1)
	//pThis->GetEntity()->wxTaskBarIconEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTaskBarIconEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TaskBarIconEvent)
{
	Gura_AssignMethod(wx_TaskBarIconEvent, wxTaskBarIconEvent);
}

Gura_ImplementDescendantCreator(wx_TaskBarIconEvent)
{
	return new Object_wx_TaskBarIconEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
