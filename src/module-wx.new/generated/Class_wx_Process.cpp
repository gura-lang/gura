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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Process, "Process")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Process));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Process)
{
	//wxEvtHandler* parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//wxProcess();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Process_1, "Process_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Process));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Process_1)
{
	//int flags = arg.GetNumber(0)
	//wxProcess();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Process, __Activate, "Activate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, __Activate)
{
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Activate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Process, __CloseOutput, "CloseOutput")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, __CloseOutput)
{
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CloseOutput();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Process, __Detach, "Detach")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, __Detach)
{
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Process, __Exists, "Exists")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Process, __Exists)
{
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pid = arg.GetNumber(0)
	//pThis->GetEntity()->Exists();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Process, __GetErrorStream, "GetErrorStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, __GetErrorStream)
{
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetErrorStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Process, __GetInputStream, "GetInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, __GetInputStream)
{
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Process, __GetOutputStream, "GetOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, __GetOutputStream)
{
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOutputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Process, __GetPid, "GetPid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, __GetPid)
{
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPid();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Process, __IsErrorAvailable, "IsErrorAvailable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, __IsErrorAvailable)
{
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsErrorAvailable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Process, __IsInputAvailable, "IsInputAvailable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, __IsInputAvailable)
{
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsInputAvailable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Process, __IsInputOpened, "IsInputOpened")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, __IsInputOpened)
{
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsInputOpened();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Process, __Kill, "Kill")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sig", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Process, __Kill)
{
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pid = arg.GetNumber(0)
	//wxSignal sig = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->Kill();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Process, __OnTerminate, "OnTerminate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "status", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Process, __OnTerminate)
{
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pid = arg.GetNumber(0)
	//int status = arg.GetNumber(1)
	//pThis->GetEntity()->OnTerminate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Process, __Open, "Open")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cmd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Process, __Open)
{
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& cmd = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Open();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Process, __Redirect, "Redirect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, __Redirect)
{
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Redirect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Process, __SetPriority, "SetPriority")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "priority", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Process, __SetPriority)
{
	Object_wx_Process *pThis = Object_wx_Process::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned priority = arg.GetNumber(0)
	//pThis->GetEntity()->SetPriority();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxProcess
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Process)
{
	// Constructor assignment
	Gura_AssignFunction(__Process);
	Gura_AssignFunction(__Process_1);
	// Method assignment
	Gura_AssignMethod(wx_Process, __Activate);
	Gura_AssignMethod(wx_Process, __CloseOutput);
	Gura_AssignMethod(wx_Process, __Detach);
	Gura_AssignMethod(wx_Process, __Exists);
	Gura_AssignMethod(wx_Process, __GetErrorStream);
	Gura_AssignMethod(wx_Process, __GetInputStream);
	Gura_AssignMethod(wx_Process, __GetOutputStream);
	Gura_AssignMethod(wx_Process, __GetPid);
	Gura_AssignMethod(wx_Process, __IsErrorAvailable);
	Gura_AssignMethod(wx_Process, __IsInputAvailable);
	Gura_AssignMethod(wx_Process, __IsInputOpened);
	Gura_AssignMethod(wx_Process, __Kill);
	Gura_AssignMethod(wx_Process, __OnTerminate);
	Gura_AssignMethod(wx_Process, __Open);
	Gura_AssignMethod(wx_Process, __Redirect);
	Gura_AssignMethod(wx_Process, __SetPriority);
}

Gura_ImplementDescendantCreator(wx_Process)
{
	return new Object_wx_Process((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
