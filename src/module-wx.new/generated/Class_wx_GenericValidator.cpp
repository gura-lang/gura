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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxGenericValidator, "wxGenericValidator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxGenericValidator)
{
	//int validator = arg.GetNumber(0)
	//wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxGenericValidator_1, "wxGenericValidator_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxGenericValidator_1)
{
	//int valPtr = arg.GetNumber(0)
	//wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxGenericValidator_2, "wxGenericValidator_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxGenericValidator_2)
{
	//int valPtr = arg.GetNumber(0)
	//wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxGenericValidator_3, "wxGenericValidator_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxGenericValidator_3)
{
	//int valPtr = arg.GetNumber(0)
	//wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxGenericValidator_4, "wxGenericValidator_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxGenericValidator_4)
{
	//int valPtr = arg.GetNumber(0)
	//wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxGenericValidator_5, "wxGenericValidator_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxGenericValidator_5)
{
	//int valPtr = arg.GetNumber(0)
	//wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxGenericValidator_6, "wxGenericValidator_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxGenericValidator_6)
{
	//int valPtr = arg.GetNumber(0)
	//wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxGenericValidator_7, "wxGenericValidator_7")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxGenericValidator_7)
{
	//int valPtr = arg.GetNumber(0)
	//wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxGenericValidator_8, "wxGenericValidator_8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxGenericValidator_8)
{
	//int valPtr = arg.GetNumber(0)
	//wxGenericValidator();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
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
	// Constructor assignment
	Gura_AssignFunction(__wxGenericValidator);
	Gura_AssignFunction(__wxGenericValidator_1);
	Gura_AssignFunction(__wxGenericValidator_2);
	Gura_AssignFunction(__wxGenericValidator_3);
	Gura_AssignFunction(__wxGenericValidator_4);
	Gura_AssignFunction(__wxGenericValidator_5);
	Gura_AssignFunction(__wxGenericValidator_6);
	Gura_AssignFunction(__wxGenericValidator_7);
	Gura_AssignFunction(__wxGenericValidator_8);
	// Method assignment
	Gura_AssignMethod(wx_GenericValidator, __Clone);
	Gura_AssignMethod(wx_GenericValidator, __TransferFromWindow);
	Gura_AssignMethod(wx_GenericValidator, __TransferToWindow);
}

Gura_ImplementDescendantCreator(wx_GenericValidator)
{
	return new Object_wx_GenericValidator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
