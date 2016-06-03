//----------------------------------------------------------------------------
// wxCmdLineArg
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCmdLineArg
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCmdLineArg
//----------------------------------------------------------------------------
Object_wx_CmdLineArg::~Object_wx_CmdLineArg()
{
}

Object *Object_wx_CmdLineArg::Clone() const
{
	return nullptr;
}

String Object_wx_CmdLineArg::ToString(bool exprFlag)
{
	String rtn("<wx.CmdLineArg:");
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
Gura_DeclareMethodAlias(wx_CmdLineArg, __GetDateVal, "GetDateVal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArg, __GetDateVal)
{
	Object_wx_CmdLineArg *pThis = Object_wx_CmdLineArg::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDateVal();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineArg, __GetDoubleVal, "GetDoubleVal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArg, __GetDoubleVal)
{
	Object_wx_CmdLineArg *pThis = Object_wx_CmdLineArg::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDoubleVal();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineArg, __GetKind, "GetKind")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArg, __GetKind)
{
	Object_wx_CmdLineArg *pThis = Object_wx_CmdLineArg::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetKind();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineArg, __GetLongVal, "GetLongVal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArg, __GetLongVal)
{
	Object_wx_CmdLineArg *pThis = Object_wx_CmdLineArg::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLongVal();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineArg, __GetLongName, "GetLongName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArg, __GetLongName)
{
	Object_wx_CmdLineArg *pThis = Object_wx_CmdLineArg::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLongName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineArg, __GetShortName, "GetShortName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArg, __GetShortName)
{
	Object_wx_CmdLineArg *pThis = Object_wx_CmdLineArg::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetShortName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineArg, __GetStrVal, "GetStrVal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArg, __GetStrVal)
{
	Object_wx_CmdLineArg *pThis = Object_wx_CmdLineArg::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStrVal();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineArg, __GetType, "GetType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArg, __GetType)
{
	Object_wx_CmdLineArg *pThis = Object_wx_CmdLineArg::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineArg, __IsNegated, "IsNegated")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArg, __IsNegated)
{
	Object_wx_CmdLineArg *pThis = Object_wx_CmdLineArg::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsNegated();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCmdLineArg
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CmdLineArg)
{
	// Class assignment
	Gura_AssignValueEx("CmdLineArg", Reference());
	// Method assignment
	Gura_AssignMethod(wx_CmdLineArg, __GetDateVal);
	Gura_AssignMethod(wx_CmdLineArg, __GetDoubleVal);
	Gura_AssignMethod(wx_CmdLineArg, __GetKind);
	Gura_AssignMethod(wx_CmdLineArg, __GetLongVal);
	Gura_AssignMethod(wx_CmdLineArg, __GetLongName);
	Gura_AssignMethod(wx_CmdLineArg, __GetShortName);
	Gura_AssignMethod(wx_CmdLineArg, __GetStrVal);
	Gura_AssignMethod(wx_CmdLineArg, __GetType);
	Gura_AssignMethod(wx_CmdLineArg, __IsNegated);
}

Gura_ImplementDescendantCreator(wx_CmdLineArg)
{
	return new Object_wx_CmdLineArg((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
