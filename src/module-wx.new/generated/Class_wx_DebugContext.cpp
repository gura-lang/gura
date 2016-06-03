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
Gura_DeclareMethodAlias(wx_DebugContext, __Check, "Check")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "checkAll", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, __Check)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int checkAll = arg.GetNumber(0)
	//pThis->GetEntity()->Check();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DebugContext, __Dump, "Dump")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DebugContext, __Dump)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Dump();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DebugContext, __GetCheckPrevious, "GetCheckPrevious")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DebugContext, __GetCheckPrevious)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCheckPrevious();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DebugContext, __GetDebugMode, "GetDebugMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DebugContext, __GetDebugMode)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDebugMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DebugContext, __GetLevel, "GetLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DebugContext, __GetLevel)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DebugContext, __PrintClasses, "PrintClasses")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DebugContext, __PrintClasses)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PrintClasses();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DebugContext, __PrintStatistics, "PrintStatistics")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "detailed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, __PrintStatistics)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int detailed = arg.GetNumber(0)
	//pThis->GetEntity()->PrintStatistics();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DebugContext, __SetCheckPrevious, "SetCheckPrevious")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "check", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, __SetCheckPrevious)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int check = arg.GetNumber(0)
	//pThis->GetEntity()->SetCheckPrevious();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DebugContext, __SetCheckpoint, "SetCheckpoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "all", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, __SetCheckpoint)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int all = arg.GetNumber(0)
	//pThis->GetEntity()->SetCheckpoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DebugContext, __SetDebugMode, "SetDebugMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "debug", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, __SetDebugMode)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int debug = arg.GetNumber(0)
	//pThis->GetEntity()->SetDebugMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DebugContext, __SetLevel, "SetLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, __SetLevel)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//pThis->GetEntity()->SetLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DebugContext, __SetShutdownNotifyFunction, "SetShutdownNotifyFunction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "func", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, __SetShutdownNotifyFunction)
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
	// Method assignment
	Gura_AssignMethod(wx_DebugContext, __Check);
	Gura_AssignMethod(wx_DebugContext, __Dump);
	Gura_AssignMethod(wx_DebugContext, __GetCheckPrevious);
	Gura_AssignMethod(wx_DebugContext, __GetDebugMode);
	Gura_AssignMethod(wx_DebugContext, __GetLevel);
	Gura_AssignMethod(wx_DebugContext, __PrintClasses);
	Gura_AssignMethod(wx_DebugContext, __PrintStatistics);
	Gura_AssignMethod(wx_DebugContext, __SetCheckPrevious);
	Gura_AssignMethod(wx_DebugContext, __SetCheckpoint);
	Gura_AssignMethod(wx_DebugContext, __SetDebugMode);
	Gura_AssignMethod(wx_DebugContext, __SetLevel);
	Gura_AssignMethod(wx_DebugContext, __SetShutdownNotifyFunction);
}

Gura_ImplementDescendantCreator(wx_DebugContext)
{
	return new Object_wx_DebugContext((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
