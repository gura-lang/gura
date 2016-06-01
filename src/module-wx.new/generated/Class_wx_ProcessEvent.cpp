//----------------------------------------------------------------------------
// wxProcessEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxProcessEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxProcessEvent
//----------------------------------------------------------------------------
Object_wx_ProcessEvent::~Object_wx_ProcessEvent()
{
}

Object *Object_wx_ProcessEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ProcessEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ProcessEvent:");
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
Gura_DeclareMethod(wx_ProcessEvent, wxProcessEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "exitcode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ProcessEvent, wxProcessEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_ProcessEvent *pThis = Object_wx_ProcessEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int pid = arg.GetNumber(1)
	//int exitcode = arg.GetNumber(2)
	//pThis->GetEntity()->wxProcessEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ProcessEvent, GetExitCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ProcessEvent, GetExitCode)
{
	Signal &sig = env.GetSignal();
	Object_wx_ProcessEvent *pThis = Object_wx_ProcessEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetExitCode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ProcessEvent, GetPid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ProcessEvent, GetPid)
{
	Signal &sig = env.GetSignal();
	Object_wx_ProcessEvent *pThis = Object_wx_ProcessEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPid();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxProcessEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ProcessEvent)
{
	Gura_AssignMethod(wx_ProcessEvent, wxProcessEvent);
	Gura_AssignMethod(wx_ProcessEvent, GetExitCode);
	Gura_AssignMethod(wx_ProcessEvent, GetPid);
}

Gura_ImplementDescendantCreator(wx_ProcessEvent)
{
	return new Object_wx_ProcessEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
