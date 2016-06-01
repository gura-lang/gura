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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_FloatingPointValidator, wxFloatingPointValidator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FloatingPointValidator, wxFloatingPointValidator)
{
	Signal &sig = env.GetSignal();
	Object_wx_FloatingPointValidator *pThis = Object_wx_FloatingPointValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->wxFloatingPointValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FloatingPointValidator, wxFloatingPointValidator_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "precision", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FloatingPointValidator, wxFloatingPointValidator_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FloatingPointValidator *pThis = Object_wx_FloatingPointValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int precision = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->wxFloatingPointValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FloatingPointValidator, SetPrecision)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "precision", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FloatingPointValidator, SetPrecision)
{
	Signal &sig = env.GetSignal();
	Object_wx_FloatingPointValidator *pThis = Object_wx_FloatingPointValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int precision = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrecision();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFloatingPointValidator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FloatingPointValidator)
{
	Gura_AssignMethod(wx_FloatingPointValidator, wxFloatingPointValidator);
	Gura_AssignMethod(wx_FloatingPointValidator, wxFloatingPointValidator_1);
	Gura_AssignMethod(wx_FloatingPointValidator, SetPrecision);
}

Gura_ImplementDescendantCreator(wx_FloatingPointValidator)
{
	return new Object_wx_FloatingPointValidator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
