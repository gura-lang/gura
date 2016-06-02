//----------------------------------------------------------------------------
// wxDebugContext
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugContext
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDebugContext
//----------------------------------------------------------------------------
Object_wx_DebugContext::~Object_wx_DebugContext()
{
}

Object *Object_wx_DebugContext::Clone() const
{
	return nullptr;
}

String Object_wx_DebugContext::ToString(bool exprFlag)
{
	String rtn("<wx.DebugContext:");
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
Gura_DeclareMethod(wx_DebugContext, Check)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "checkAll", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, Check)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int checkAll = arg.GetNumber(0)
	//pThis->GetEntity()->Check();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugContext, Dump)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DebugContext, Dump)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Dump();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugContext, GetCheckPrevious)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DebugContext, GetCheckPrevious)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCheckPrevious();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugContext, GetDebugMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DebugContext, GetDebugMode)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDebugMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugContext, GetLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DebugContext, GetLevel)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugContext, PrintClasses)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DebugContext, PrintClasses)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PrintClasses();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugContext, PrintStatistics)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "detailed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, PrintStatistics)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int detailed = arg.GetNumber(0)
	//pThis->GetEntity()->PrintStatistics();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugContext, SetCheckPrevious)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "check", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, SetCheckPrevious)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int check = arg.GetNumber(0)
	//pThis->GetEntity()->SetCheckPrevious();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugContext, SetCheckpoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "all", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, SetCheckpoint)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int all = arg.GetNumber(0)
	//pThis->GetEntity()->SetCheckpoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugContext, SetDebugMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "debug", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, SetDebugMode)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int debug = arg.GetNumber(0)
	//pThis->GetEntity()->SetDebugMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugContext, SetLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, SetLevel)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//pThis->GetEntity()->SetLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugContext, SetShutdownNotifyFunction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "func", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, SetShutdownNotifyFunction)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int func = arg.GetNumber(0)
	//pThis->GetEntity()->SetShutdownNotifyFunction();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDebugContext
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugContext)
{
	Gura_AssignMethod(wx_DebugContext, Check);
	Gura_AssignMethod(wx_DebugContext, Dump);
	Gura_AssignMethod(wx_DebugContext, GetCheckPrevious);
	Gura_AssignMethod(wx_DebugContext, GetDebugMode);
	Gura_AssignMethod(wx_DebugContext, GetLevel);
	Gura_AssignMethod(wx_DebugContext, PrintClasses);
	Gura_AssignMethod(wx_DebugContext, PrintStatistics);
	Gura_AssignMethod(wx_DebugContext, SetCheckPrevious);
	Gura_AssignMethod(wx_DebugContext, SetCheckpoint);
	Gura_AssignMethod(wx_DebugContext, SetDebugMode);
	Gura_AssignMethod(wx_DebugContext, SetLevel);
	Gura_AssignMethod(wx_DebugContext, SetShutdownNotifyFunction);
}

Gura_ImplementDescendantCreator(wx_DebugContext)
{
	return new Object_wx_DebugContext((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
