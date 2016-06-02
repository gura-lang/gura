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
Gura_DeclareMethod(wx_CmdLineArg, GetDateVal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArg, GetDateVal)
{
	Object_wx_CmdLineArg *pThis = Object_wx_CmdLineArg::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDateVal();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineArg, GetDoubleVal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArg, GetDoubleVal)
{
	Object_wx_CmdLineArg *pThis = Object_wx_CmdLineArg::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDoubleVal();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineArg, GetKind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArg, GetKind)
{
	Object_wx_CmdLineArg *pThis = Object_wx_CmdLineArg::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetKind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineArg, GetLongVal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArg, GetLongVal)
{
	Object_wx_CmdLineArg *pThis = Object_wx_CmdLineArg::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLongVal();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineArg, GetLongName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArg, GetLongName)
{
	Object_wx_CmdLineArg *pThis = Object_wx_CmdLineArg::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLongName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineArg, GetShortName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArg, GetShortName)
{
	Object_wx_CmdLineArg *pThis = Object_wx_CmdLineArg::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetShortName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineArg, GetStrVal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArg, GetStrVal)
{
	Object_wx_CmdLineArg *pThis = Object_wx_CmdLineArg::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStrVal();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineArg, GetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArg, GetType)
{
	Object_wx_CmdLineArg *pThis = Object_wx_CmdLineArg::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineArg, IsNegated)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArg, IsNegated)
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
	Gura_AssignMethod(wx_CmdLineArg, GetDateVal);
	Gura_AssignMethod(wx_CmdLineArg, GetDoubleVal);
	Gura_AssignMethod(wx_CmdLineArg, GetKind);
	Gura_AssignMethod(wx_CmdLineArg, GetLongVal);
	Gura_AssignMethod(wx_CmdLineArg, GetLongName);
	Gura_AssignMethod(wx_CmdLineArg, GetShortName);
	Gura_AssignMethod(wx_CmdLineArg, GetStrVal);
	Gura_AssignMethod(wx_CmdLineArg, GetType);
	Gura_AssignMethod(wx_CmdLineArg, IsNegated);
}

Gura_ImplementDescendantCreator(wx_CmdLineArg)
{
	return new Object_wx_CmdLineArg((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
