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
Gura_DeclareMethodAlias(wx_TextValidator, __wxTextValidator, "wxTextValidator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, __wxTextValidator)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int validator = arg.GetNumber(0)
	//pThis->GetEntity()->wxTextValidator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __wxTextValidator_1, "wxTextValidator_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, __wxTextValidator_1)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int valPtr = arg.GetNumber(1)
	//pThis->GetEntity()->wxTextValidator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextValidator, __Clone)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __GetExcludes, "GetExcludes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextValidator, __GetExcludes)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExcludes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __GetIncludes, "GetIncludes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextValidator, __GetIncludes)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIncludes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextValidator, __GetStyle)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __HasFlag, "HasFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, __HasFlag)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->HasFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __OnChar, "OnChar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, __OnChar)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __SetExcludes, "SetExcludes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stringList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, __SetExcludes)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stringList = arg.GetNumber(0)
	//pThis->GetEntity()->SetExcludes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __SetCharExcludes, "SetCharExcludes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "chars", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, __SetCharExcludes)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int chars = arg.GetNumber(0)
	//pThis->GetEntity()->SetCharExcludes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __SetIncludes, "SetIncludes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stringList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, __SetIncludes)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stringList = arg.GetNumber(0)
	//pThis->GetEntity()->SetIncludes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __SetCharIncludes, "SetCharIncludes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "chars", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, __SetCharIncludes)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int chars = arg.GetNumber(0)
	//pThis->GetEntity()->SetCharIncludes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __SetStyle, "SetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, __SetStyle)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __TransferFromWindow, "TransferFromWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextValidator, __TransferFromWindow)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TransferFromWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __TransferToWindow, "TransferToWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextValidator, __TransferToWindow)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TransferToWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __Validate, "Validate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, __Validate)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->Validate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __ContainsOnlyIncludedCharacters, "ContainsOnlyIncludedCharacters")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, __ContainsOnlyIncludedCharacters)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->ContainsOnlyIncludedCharacters();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __ContainsExcludedCharacters, "ContainsExcludedCharacters")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, __ContainsExcludedCharacters)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->ContainsExcludedCharacters();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __IsValid, "IsValid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, __IsValid)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->IsValid();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextValidator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextValidator)
{
	Gura_AssignMethod(wx_TextValidator, __wxTextValidator);
	Gura_AssignMethod(wx_TextValidator, __wxTextValidator_1);
	Gura_AssignMethod(wx_TextValidator, __Clone);
	Gura_AssignMethod(wx_TextValidator, __GetExcludes);
	Gura_AssignMethod(wx_TextValidator, __GetIncludes);
	Gura_AssignMethod(wx_TextValidator, __GetStyle);
	Gura_AssignMethod(wx_TextValidator, __HasFlag);
	Gura_AssignMethod(wx_TextValidator, __OnChar);
	Gura_AssignMethod(wx_TextValidator, __SetExcludes);
	Gura_AssignMethod(wx_TextValidator, __SetCharExcludes);
	Gura_AssignMethod(wx_TextValidator, __SetIncludes);
	Gura_AssignMethod(wx_TextValidator, __SetCharIncludes);
	Gura_AssignMethod(wx_TextValidator, __SetStyle);
	Gura_AssignMethod(wx_TextValidator, __TransferFromWindow);
	Gura_AssignMethod(wx_TextValidator, __TransferToWindow);
	Gura_AssignMethod(wx_TextValidator, __Validate);
	Gura_AssignMethod(wx_TextValidator, __ContainsOnlyIncludedCharacters);
	Gura_AssignMethod(wx_TextValidator, __ContainsExcludedCharacters);
	Gura_AssignMethod(wx_TextValidator, __IsValid);
}

Gura_ImplementDescendantCreator(wx_TextValidator)
{
	return new Object_wx_TextValidator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
