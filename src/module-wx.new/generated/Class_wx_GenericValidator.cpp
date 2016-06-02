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
Gura_DeclareMethod(wx_GenericValidator, wxGenericValidator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericValidator, wxGenericValidator)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int validator = arg.GetNumber(0)
	//pThis->GetEntity()->wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericValidator, wxGenericValidator_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericValidator, wxGenericValidator_1)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int valPtr = arg.GetNumber(0)
	//pThis->GetEntity()->wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericValidator, wxGenericValidator_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericValidator, wxGenericValidator_2)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int valPtr = arg.GetNumber(0)
	//pThis->GetEntity()->wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericValidator, wxGenericValidator_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericValidator, wxGenericValidator_3)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int valPtr = arg.GetNumber(0)
	//pThis->GetEntity()->wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericValidator, wxGenericValidator_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericValidator, wxGenericValidator_4)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int valPtr = arg.GetNumber(0)
	//pThis->GetEntity()->wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericValidator, wxGenericValidator_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericValidator, wxGenericValidator_5)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int valPtr = arg.GetNumber(0)
	//pThis->GetEntity()->wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericValidator, wxGenericValidator_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericValidator, wxGenericValidator_6)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int valPtr = arg.GetNumber(0)
	//pThis->GetEntity()->wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericValidator, wxGenericValidator_7)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericValidator, wxGenericValidator_7)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int valPtr = arg.GetNumber(0)
	//pThis->GetEntity()->wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericValidator, wxGenericValidator_8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericValidator, wxGenericValidator_8)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int valPtr = arg.GetNumber(0)
	//pThis->GetEntity()->wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericValidator, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericValidator, Clone)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericValidator, TransferFromWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericValidator, TransferFromWindow)
{
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TransferFromWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericValidator, TransferToWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericValidator, TransferToWindow)
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
	Gura_AssignMethod(wx_GenericValidator, wxGenericValidator);
	Gura_AssignMethod(wx_GenericValidator, wxGenericValidator_1);
	Gura_AssignMethod(wx_GenericValidator, wxGenericValidator_2);
	Gura_AssignMethod(wx_GenericValidator, wxGenericValidator_3);
	Gura_AssignMethod(wx_GenericValidator, wxGenericValidator_4);
	Gura_AssignMethod(wx_GenericValidator, wxGenericValidator_5);
	Gura_AssignMethod(wx_GenericValidator, wxGenericValidator_6);
	Gura_AssignMethod(wx_GenericValidator, wxGenericValidator_7);
	Gura_AssignMethod(wx_GenericValidator, wxGenericValidator_8);
	Gura_AssignMethod(wx_GenericValidator, Clone);
	Gura_AssignMethod(wx_GenericValidator, TransferFromWindow);
	Gura_AssignMethod(wx_GenericValidator, TransferToWindow);
}

Gura_ImplementDescendantCreator(wx_GenericValidator)
{
	return new Object_wx_GenericValidator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
