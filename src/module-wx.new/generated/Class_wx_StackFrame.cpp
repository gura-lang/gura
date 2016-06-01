//----------------------------------------------------------------------------
// wxStackFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStackFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStackFrame
//----------------------------------------------------------------------------
Object_wx_StackFrame::~Object_wx_StackFrame()
{
}

Object *Object_wx_StackFrame::Clone() const
{
	return nullptr;
}

String Object_wx_StackFrame::ToString(bool exprFlag)
{
	String rtn("<wx.StackFrame:");
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
Gura_DeclareMethod(wx_StackFrame, GetAddress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, GetAddress)
{
	Signal &sig = env.GetSignal();
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAddress();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StackFrame, GetFileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, GetFileName)
{
	Signal &sig = env.GetSignal();
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StackFrame, GetLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, GetLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StackFrame, GetLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, GetLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StackFrame, GetModule)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, GetModule)
{
	Signal &sig = env.GetSignal();
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetModule();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StackFrame, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StackFrame, GetOffset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, GetOffset)
{
	Signal &sig = env.GetSignal();
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOffset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StackFrame, GetParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StackFrame, GetParam)
{
	Signal &sig = env.GetSignal();
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//int value = arg.GetNumber(3)
	//pThis->GetEntity()->GetParam();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StackFrame, GetParamCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, GetParamCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetParamCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StackFrame, HasSourceLocation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, HasSourceLocation)
{
	Signal &sig = env.GetSignal();
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasSourceLocation();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStackFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StackFrame)
{
	Gura_AssignMethod(wx_StackFrame, GetAddress);
	Gura_AssignMethod(wx_StackFrame, GetFileName);
	Gura_AssignMethod(wx_StackFrame, GetLevel);
	Gura_AssignMethod(wx_StackFrame, GetLine);
	Gura_AssignMethod(wx_StackFrame, GetModule);
	Gura_AssignMethod(wx_StackFrame, GetName);
	Gura_AssignMethod(wx_StackFrame, GetOffset);
	Gura_AssignMethod(wx_StackFrame, GetParam);
	Gura_AssignMethod(wx_StackFrame, GetParamCount);
	Gura_AssignMethod(wx_StackFrame, HasSourceLocation);
}

Gura_ImplementDescendantCreator(wx_StackFrame)
{
	return new Object_wx_StackFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
