//----------------------------------------------------------------------------
// wxGenericValidator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGenericValidator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGenericValidator
//----------------------------------------------------------------------------
Object_wx_GenericValidator::~Object_wx_GenericValidator()
{
}

Object *Object_wx_GenericValidator::Clone() const
{
	return nullptr;
}

String Object_wx_GenericValidator::ToString(bool exprFlag)
{
	String rtn("<wx.GenericValidator:");
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
Gura_DeclareMethodAlias(wx_GenericValidator, __wxGenericValidator, "wxGenericValidator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericValidator, __wxGenericValidator)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int validator = arg.GetNumber(0)
	//pThis->GetEntity()->wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericValidator, __wxGenericValidator_1, "wxGenericValidator_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericValidator, __wxGenericValidator_1)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int valPtr = arg.GetNumber(0)
	//pThis->GetEntity()->wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericValidator, __wxGenericValidator_2, "wxGenericValidator_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericValidator, __wxGenericValidator_2)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int valPtr = arg.GetNumber(0)
	//pThis->GetEntity()->wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericValidator, __wxGenericValidator_3, "wxGenericValidator_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericValidator, __wxGenericValidator_3)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int valPtr = arg.GetNumber(0)
	//pThis->GetEntity()->wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericValidator, __wxGenericValidator_4, "wxGenericValidator_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericValidator, __wxGenericValidator_4)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int valPtr = arg.GetNumber(0)
	//pThis->GetEntity()->wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericValidator, __wxGenericValidator_5, "wxGenericValidator_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericValidator, __wxGenericValidator_5)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int valPtr = arg.GetNumber(0)
	//pThis->GetEntity()->wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericValidator, __wxGenericValidator_6, "wxGenericValidator_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericValidator, __wxGenericValidator_6)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int valPtr = arg.GetNumber(0)
	//pThis->GetEntity()->wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericValidator, __wxGenericValidator_7, "wxGenericValidator_7")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericValidator, __wxGenericValidator_7)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int valPtr = arg.GetNumber(0)
	//pThis->GetEntity()->wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericValidator, __wxGenericValidator_8, "wxGenericValidator_8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericValidator, __wxGenericValidator_8)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int valPtr = arg.GetNumber(0)
	//pThis->GetEntity()->wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericValidator, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericValidator, __Clone)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericValidator, __TransferFromWindow, "TransferFromWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericValidator, __TransferFromWindow)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TransferFromWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericValidator, __TransferToWindow, "TransferToWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericValidator, __TransferToWindow)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TransferToWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGenericValidator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GenericValidator)
{
	Gura_AssignMethod(wx_GenericValidator, __wxGenericValidator);
	Gura_AssignMethod(wx_GenericValidator, __wxGenericValidator_1);
	Gura_AssignMethod(wx_GenericValidator, __wxGenericValidator_2);
	Gura_AssignMethod(wx_GenericValidator, __wxGenericValidator_3);
	Gura_AssignMethod(wx_GenericValidator, __wxGenericValidator_4);
	Gura_AssignMethod(wx_GenericValidator, __wxGenericValidator_5);
	Gura_AssignMethod(wx_GenericValidator, __wxGenericValidator_6);
	Gura_AssignMethod(wx_GenericValidator, __wxGenericValidator_7);
	Gura_AssignMethod(wx_GenericValidator, __wxGenericValidator_8);
	Gura_AssignMethod(wx_GenericValidator, __Clone);
	Gura_AssignMethod(wx_GenericValidator, __TransferFromWindow);
	Gura_AssignMethod(wx_GenericValidator, __TransferToWindow);
}

Gura_ImplementDescendantCreator(wx_GenericValidator)
{
	return new Object_wx_GenericValidator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
