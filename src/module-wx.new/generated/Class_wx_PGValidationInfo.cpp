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
Gura_DeclareMethodAlias(wx_PGValidationInfo, __GetFailureBehavior, "GetFailureBehavior")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGValidationInfo, __GetFailureBehavior)
{
	Object_wx_PGValidationInfo *pThis = Object_wx_PGValidationInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFailureBehavior();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGValidationInfo, __GetFailureMessage, "GetFailureMessage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGValidationInfo, __GetFailureMessage)
{
	Object_wx_PGValidationInfo *pThis = Object_wx_PGValidationInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFailureMessage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGValidationInfo, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGValidationInfo, __GetValue)
{
	Object_wx_PGValidationInfo *pThis = Object_wx_PGValidationInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGValidationInfo, __SetFailureBehavior, "SetFailureBehavior")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "failureBehavior", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGValidationInfo, __SetFailureBehavior)
{
	Object_wx_PGValidationInfo *pThis = Object_wx_PGValidationInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGVFBFlags failureBehavior = arg.GetNumber(0)
	//pThis->GetEntity()->SetFailureBehavior(failureBehavior);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGValidationInfo, __SetFailureMessage, "SetFailureMessage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGValidationInfo, __SetFailureMessage)
{
	Object_wx_PGValidationInfo *pThis = Object_wx_PGValidationInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& message = arg.GetNumber(0)
	//pThis->GetEntity()->SetFailureMessage(message);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPGValidationInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PGValidationInfo)
{
	// Class assignment
	Gura_AssignValueEx("PGValidationInfo", Reference());
	// Method assignment
	Gura_AssignMethod(wx_PGValidationInfo, __GetFailureBehavior);
	Gura_AssignMethod(wx_PGValidationInfo, __GetFailureMessage);
	Gura_AssignMethod(wx_PGValidationInfo, __GetValue);
	Gura_AssignMethod(wx_PGValidationInfo, __SetFailureBehavior);
	Gura_AssignMethod(wx_PGValidationInfo, __SetFailureMessage);
}

Gura_ImplementDescendantCreator(wx_PGValidationInfo)
{
	return new Object_wx_PGValidationInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
