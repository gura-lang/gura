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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__TextValidator, "TextValidator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TextValidator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TextValidator)
{
	//const wxTextValidator& validator = arg.GetNumber(0)
	//wxTextValidator(validator);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__TextValidator_1, "TextValidator_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TextValidator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TextValidator_1)
{
	//long style = arg.GetNumber(0)
	//wxString* valPtr = arg.GetNumber(1)
	//wxTextValidator(style, valPtr);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TextValidator, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextValidator, __Clone)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxObject* _rtn = pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __GetExcludes, "GetExcludes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextValidator, __GetExcludes)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArrayString& _rtn = pThis->GetEntity()->GetExcludes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __GetIncludes, "GetIncludes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextValidator, __GetIncludes)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArrayString& _rtn = pThis->GetEntity()->GetIncludes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextValidator, __GetStyle)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long _rtn = pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __HasFlag, "HasFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, __HasFlag)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTextValidatorStyle style = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->HasFlag(style);
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
	//wxKeyEvent& event = arg.GetNumber(0)
	//pThis->GetEntity()->OnChar(event);
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
	//const wxArrayString& stringList = arg.GetNumber(0)
	//pThis->GetEntity()->SetExcludes(stringList);
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
	//const wxString& chars = arg.GetNumber(0)
	//pThis->GetEntity()->SetCharExcludes(chars);
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
	//const wxArrayString& stringList = arg.GetNumber(0)
	//pThis->GetEntity()->SetIncludes(stringList);
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
	//const wxString& chars = arg.GetNumber(0)
	//pThis->GetEntity()->SetCharIncludes(chars);
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
	//long style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle(style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __TransferFromWindow, "TransferFromWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextValidator, __TransferFromWindow)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->TransferFromWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __TransferToWindow, "TransferToWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextValidator, __TransferToWindow)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->TransferToWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __Validate, "Validate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, __Validate)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Validate(parent);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __ContainsOnlyIncludedCharacters, "ContainsOnlyIncludedCharacters")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, __ContainsOnlyIncludedCharacters)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& val = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->ContainsOnlyIncludedCharacters(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __ContainsExcludedCharacters, "ContainsExcludedCharacters")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, __ContainsExcludedCharacters)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& val = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->ContainsExcludedCharacters(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextValidator, __IsValid, "IsValid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, __IsValid)
{
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& val = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->IsValid(val);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextValidator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextValidator)
{
	// Constructor assignment
	Gura_AssignFunction(__TextValidator);
	Gura_AssignFunction(__TextValidator_1);
	// Method assignment
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
