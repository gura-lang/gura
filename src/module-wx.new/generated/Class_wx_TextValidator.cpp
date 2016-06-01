//----------------------------------------------------------------------------
// wxTextValidator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextValidator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextValidator
//----------------------------------------------------------------------------
Object_wx_TextValidator::~Object_wx_TextValidator()
{
}

Object *Object_wx_TextValidator::Clone() const
{
	return nullptr;
}

String Object_wx_TextValidator::ToString(bool exprFlag)
{
	String rtn("<wx.TextValidator:");
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
Gura_DeclareMethod(wx_TextValidator, wxTextValidator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, wxTextValidator)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int validator = arg.GetNumber(0)
	//pThis->GetEntity()->wxTextValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, wxTextValidator_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, wxTextValidator_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int valPtr = arg.GetNumber(1)
	//pThis->GetEntity()->wxTextValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextValidator, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, GetExcludes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextValidator, GetExcludes)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetExcludes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, GetIncludes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextValidator, GetIncludes)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetIncludes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextValidator, GetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, HasFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, HasFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->HasFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, OnChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, OnChar)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, SetExcludes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stringList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, SetExcludes)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stringList = arg.GetNumber(0)
	//pThis->GetEntity()->SetExcludes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, SetCharExcludes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "chars", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, SetCharExcludes)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int chars = arg.GetNumber(0)
	//pThis->GetEntity()->SetCharExcludes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, SetIncludes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stringList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, SetIncludes)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stringList = arg.GetNumber(0)
	//pThis->GetEntity()->SetIncludes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, SetCharIncludes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "chars", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, SetCharIncludes)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int chars = arg.GetNumber(0)
	//pThis->GetEntity()->SetCharIncludes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, SetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, TransferFromWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextValidator, TransferFromWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->TransferFromWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, TransferToWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextValidator, TransferToWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->TransferToWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, Validate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, Validate)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->Validate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, ContainsOnlyIncludedCharacters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, ContainsOnlyIncludedCharacters)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->ContainsOnlyIncludedCharacters();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, ContainsExcludedCharacters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, ContainsExcludedCharacters)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->ContainsExcludedCharacters();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, IsValid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, IsValid)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->IsValid();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextValidator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextValidator)
{
	Gura_AssignMethod(wx_TextValidator, wxTextValidator);
	Gura_AssignMethod(wx_TextValidator, wxTextValidator_1);
	Gura_AssignMethod(wx_TextValidator, Clone);
	Gura_AssignMethod(wx_TextValidator, GetExcludes);
	Gura_AssignMethod(wx_TextValidator, GetIncludes);
	Gura_AssignMethod(wx_TextValidator, GetStyle);
	Gura_AssignMethod(wx_TextValidator, HasFlag);
	Gura_AssignMethod(wx_TextValidator, OnChar);
	Gura_AssignMethod(wx_TextValidator, SetExcludes);
	Gura_AssignMethod(wx_TextValidator, SetCharExcludes);
	Gura_AssignMethod(wx_TextValidator, SetIncludes);
	Gura_AssignMethod(wx_TextValidator, SetCharIncludes);
	Gura_AssignMethod(wx_TextValidator, SetStyle);
	Gura_AssignMethod(wx_TextValidator, TransferFromWindow);
	Gura_AssignMethod(wx_TextValidator, TransferToWindow);
	Gura_AssignMethod(wx_TextValidator, Validate);
	Gura_AssignMethod(wx_TextValidator, ContainsOnlyIncludedCharacters);
	Gura_AssignMethod(wx_TextValidator, ContainsExcludedCharacters);
	Gura_AssignMethod(wx_TextValidator, IsValid);
}

Gura_ImplementDescendantCreator(wx_TextValidator)
{
	return new Object_wx_TextValidator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
