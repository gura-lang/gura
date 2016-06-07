//----------------------------------------------------------------------------
// wxFloatingPointValidator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFloatingPointValidator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFloatingPointValidator
//----------------------------------------------------------------------------
Object_wx_FloatingPointValidator::~Object_wx_FloatingPointValidator()
{
}

Object *Object_wx_FloatingPointValidator::Clone() const
{
	return nullptr;
}

String Object_wx_FloatingPointValidator::ToString(bool exprFlag)
{
	String rtn("<wx.FloatingPointValidator:");
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
Gura_DeclareFunctionAlias(__FloatingPointValidator, "FloatingPointValidator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FloatingPointValidator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FloatingPointValidator)
{
	//ValueType* value = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//wxFloatingPointValidator(value, style);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FloatingPointValidator_1, "FloatingPointValidator_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "precision", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FloatingPointValidator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FloatingPointValidator_1)
{
	//int precision = arg.GetNumber(0)
	//ValueType* value = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//wxFloatingPointValidator(precision, value, style);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FloatingPointValidator, __SetPrecision, "SetPrecision")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "precision", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FloatingPointValidator, __SetPrecision)
{
	Object_wx_FloatingPointValidator *pThis = Object_wx_FloatingPointValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned precision = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrecision(precision);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFloatingPointValidator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FloatingPointValidator)
{
	// Constructor assignment
	Gura_AssignFunction(__FloatingPointValidator);
	Gura_AssignFunction(__FloatingPointValidator_1);
	// Method assignment
	Gura_AssignMethod(wx_FloatingPointValidator, __SetPrecision);
}

Gura_ImplementDescendantCreator(wx_FloatingPointValidator)
{
	return new Object_wx_FloatingPointValidator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
