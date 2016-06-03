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
Gura_DeclareFunctionAlias(__GenericValidator, "GenericValidator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GenericValidator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GenericValidator)
{
	//int validator = arg.GetNumber(0)
	//wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GenericValidator_1, "GenericValidator_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GenericValidator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GenericValidator_1)
{
	//int valPtr = arg.GetNumber(0)
	//wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GenericValidator_2, "GenericValidator_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GenericValidator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GenericValidator_2)
{
	//int valPtr = arg.GetNumber(0)
	//wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GenericValidator_3, "GenericValidator_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GenericValidator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GenericValidator_3)
{
	//int valPtr = arg.GetNumber(0)
	//wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GenericValidator_4, "GenericValidator_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GenericValidator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GenericValidator_4)
{
	//int valPtr = arg.GetNumber(0)
	//wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GenericValidator_5, "GenericValidator_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GenericValidator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GenericValidator_5)
{
	//int valPtr = arg.GetNumber(0)
	//wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GenericValidator_6, "GenericValidator_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GenericValidator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GenericValidator_6)
{
	//int valPtr = arg.GetNumber(0)
	//wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GenericValidator_7, "GenericValidator_7")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GenericValidator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GenericValidator_7)
{
	//int valPtr = arg.GetNumber(0)
	//wxGenericValidator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GenericValidator_8, "GenericValidator_8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GenericValidator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GenericValidator_8)
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
	Gura_AssignFunction(__GenericValidator);
	Gura_AssignFunction(__GenericValidator_1);
	Gura_AssignFunction(__GenericValidator_2);
	Gura_AssignFunction(__GenericValidator_3);
	Gura_AssignFunction(__GenericValidator_4);
	Gura_AssignFunction(__GenericValidator_5);
	Gura_AssignFunction(__GenericValidator_6);
	Gura_AssignFunction(__GenericValidator_7);
	Gura_AssignFunction(__GenericValidator_8);
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
