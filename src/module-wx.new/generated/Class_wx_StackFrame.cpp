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
Gura_DeclareMethodAlias(wx_StackFrame, __GetAddress, "GetAddress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, __GetAddress)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAddress();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StackFrame, __GetFileName, "GetFileName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, __GetFileName)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFileName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StackFrame, __GetLevel, "GetLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, __GetLevel)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StackFrame, __GetLine, "GetLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, __GetLine)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StackFrame, __GetModule, "GetModule")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, __GetModule)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetModule();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StackFrame, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, __GetName)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StackFrame, __GetOffset, "GetOffset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, __GetOffset)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOffset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StackFrame, __GetParam, "GetParam")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StackFrame, __GetParam)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//wxString* type = arg.GetNumber(1)
	//wxString* name = arg.GetNumber(2)
	//wxString* value = arg.GetNumber(3)
	//pThis->GetEntity()->GetParam();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StackFrame, __GetParamCount, "GetParamCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, __GetParamCount)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParamCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StackFrame, __HasSourceLocation, "HasSourceLocation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, __HasSourceLocation)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasSourceLocation();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStackFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StackFrame)
{
	// Class assignment
	Gura_AssignValueEx("StackFrame", Reference());
	// Method assignment
	Gura_AssignMethod(wx_StackFrame, __GetAddress);
	Gura_AssignMethod(wx_StackFrame, __GetFileName);
	Gura_AssignMethod(wx_StackFrame, __GetLevel);
	Gura_AssignMethod(wx_StackFrame, __GetLine);
	Gura_AssignMethod(wx_StackFrame, __GetModule);
	Gura_AssignMethod(wx_StackFrame, __GetName);
	Gura_AssignMethod(wx_StackFrame, __GetOffset);
	Gura_AssignMethod(wx_StackFrame, __GetParam);
	Gura_AssignMethod(wx_StackFrame, __GetParamCount);
	Gura_AssignMethod(wx_StackFrame, __HasSourceLocation);
}

Gura_ImplementDescendantCreator(wx_StackFrame)
{
	return new Object_wx_StackFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
