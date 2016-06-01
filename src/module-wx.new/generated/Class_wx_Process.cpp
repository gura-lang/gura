//----------------------------------------------------------------------------
// wxProcess
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxProcess
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxProcess
//----------------------------------------------------------------------------
Object_wx_Process::~Object_wx_Process()
{
}

Object *Object_wx_Process::Clone() const
{
	return nullptr;
}

String Object_wx_Process::ToString(bool exprFlag)
{
	String rtn("<wx.Process:");
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
Gura_DeclareMethod(wx_Process, wxProcess)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Process, wxProcess)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->wxProcess();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Process, wxProcess_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Process, wxProcess_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->wxProcess();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Process, ~wxProcess)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, ~wxProcess)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxProcess();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Process, Activate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, Activate)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Activate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Process, CloseOutput)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, CloseOutput)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CloseOutput();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Process, Detach)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, Detach)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Process, Exists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Process, Exists)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pid = arg.GetNumber(0)
	//pThis->GetEntity()->Exists();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Process, GetErrorStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, GetErrorStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetErrorStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Process, GetInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, GetInputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Process, GetOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, GetOutputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Process, GetPid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, GetPid)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPid();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Process, IsErrorAvailable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, IsErrorAvailable)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsErrorAvailable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Process, IsInputAvailable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, IsInputAvailable)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsInputAvailable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Process, IsInputOpened)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, IsInputOpened)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsInputOpened();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Process, Kill)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sig", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Process, Kill)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pid = arg.GetNumber(0)
	//int sig = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->Kill();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Process, OnTerminate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "status", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Process, OnTerminate)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pid = arg.GetNumber(0)
	//int status = arg.GetNumber(1)
	//pThis->GetEntity()->OnTerminate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Process, Open)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cmd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Process, Open)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cmd = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Open();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Process, Redirect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, Redirect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Redirect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Process, SetPriority)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "priority", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Process, SetPriority)
{
	Signal &sig = env.GetSignal();
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int priority = arg.GetNumber(0)
	//pThis->GetEntity()->SetPriority();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxProcess
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Process)
{
	Gura_AssignMethod(wx_Process, wxProcess);
	Gura_AssignMethod(wx_Process, wxProcess_1);
	Gura_AssignMethod(wx_Process, ~wxProcess);
	Gura_AssignMethod(wx_Process, Activate);
	Gura_AssignMethod(wx_Process, CloseOutput);
	Gura_AssignMethod(wx_Process, Detach);
	Gura_AssignMethod(wx_Process, Exists);
	Gura_AssignMethod(wx_Process, GetErrorStream);
	Gura_AssignMethod(wx_Process, GetInputStream);
	Gura_AssignMethod(wx_Process, GetOutputStream);
	Gura_AssignMethod(wx_Process, GetPid);
	Gura_AssignMethod(wx_Process, IsErrorAvailable);
	Gura_AssignMethod(wx_Process, IsInputAvailable);
	Gura_AssignMethod(wx_Process, IsInputOpened);
	Gura_AssignMethod(wx_Process, Kill);
	Gura_AssignMethod(wx_Process, OnTerminate);
	Gura_AssignMethod(wx_Process, Open);
	Gura_AssignMethod(wx_Process, Redirect);
	Gura_AssignMethod(wx_Process, SetPriority);
}

Gura_ImplementDescendantCreator(wx_Process)
{
	return new Object_wx_Process((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
