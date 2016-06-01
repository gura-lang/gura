//----------------------------------------------------------------------------
// wxPGValidationInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPGValidationInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPGValidationInfo
//----------------------------------------------------------------------------
Object_wx_PGValidationInfo::~Object_wx_PGValidationInfo()
{
}

Object *Object_wx_PGValidationInfo::Clone() const
{
	return nullptr;
}

String Object_wx_PGValidationInfo::ToString(bool exprFlag)
{
	String rtn("<wx.PGValidationInfo:");
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
Gura_DeclareMethod(wx_PGValidationInfo, GetFailureBehavior)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGValidationInfo, GetFailureBehavior)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGValidationInfo *pThis = Object_wx_PGValidationInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFailureBehavior();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGValidationInfo, GetFailureMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGValidationInfo, GetFailureMessage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGValidationInfo *pThis = Object_wx_PGValidationInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFailureMessage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGValidationInfo, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGValidationInfo, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGValidationInfo *pThis = Object_wx_PGValidationInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGValidationInfo, SetFailureBehavior)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "failureBehavior", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGValidationInfo, SetFailureBehavior)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGValidationInfo *pThis = Object_wx_PGValidationInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int failureBehavior = arg.GetNumber(0)
	//pThis->GetEntity()->SetFailureBehavior();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGValidationInfo, SetFailureMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGValidationInfo, SetFailureMessage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGValidationInfo *pThis = Object_wx_PGValidationInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int message = arg.GetNumber(0)
	//pThis->GetEntity()->SetFailureMessage();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPGValidationInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PGValidationInfo)
{
	Gura_AssignMethod(wx_PGValidationInfo, GetFailureBehavior);
	Gura_AssignMethod(wx_PGValidationInfo, GetFailureMessage);
	Gura_AssignMethod(wx_PGValidationInfo, GetValue);
	Gura_AssignMethod(wx_PGValidationInfo, SetFailureBehavior);
	Gura_AssignMethod(wx_PGValidationInfo, SetFailureMessage);
}

Gura_ImplementDescendantCreator(wx_PGValidationInfo)
{
	return new Object_wx_PGValidationInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
