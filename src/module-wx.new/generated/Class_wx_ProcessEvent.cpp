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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxProcessEvent, "wxProcessEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "exitcode", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ProcessEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxProcessEvent)
{
	//int id = arg.GetNumber(0)
	//int pid = arg.GetNumber(1)
	//int exitcode = arg.GetNumber(2)
	//wxProcessEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ProcessEvent, __GetExitCode, "GetExitCode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ProcessEvent, __GetExitCode)
{
	Object_wx_ProcessEvent *pThis = Object_wx_ProcessEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExitCode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ProcessEvent, __GetPid, "GetPid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ProcessEvent, __GetPid)
{
	Object_wx_ProcessEvent *pThis = Object_wx_ProcessEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPid();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxProcessEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ProcessEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__wxProcessEvent);
	// Method assignment
	Gura_AssignMethod(wx_ProcessEvent, __GetExitCode);
	Gura_AssignMethod(wx_ProcessEvent, __GetPid);
}

Gura_ImplementDescendantCreator(wx_ProcessEvent)
{
	return new Object_wx_ProcessEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
