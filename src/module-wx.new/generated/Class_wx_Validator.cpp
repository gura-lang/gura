//----------------------------------------------------------------------------
// wxValidator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxValidator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxValidator
//----------------------------------------------------------------------------
Object_wx_Validator::~Object_wx_Validator()
{
}

Object *Object_wx_Validator::Clone() const
{
	return nullptr;
}

String Object_wx_Validator::ToString(bool exprFlag)
{
	String rtn("<wx.Validator:");
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
Gura_DeclareFunctionAlias(__Validator, "Validator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Validator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Validator)
{
	//wxValidator();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Validator, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Validator, __Clone)
{
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxObject* _rtn = pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Validator, __GetWindow, "GetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Validator, __GetWindow)
{
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* _rtn = pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Validator, __SuppressBellOnError, "SuppressBellOnError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "suppress", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Validator, __SuppressBellOnError)
{
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool suppress = arg.GetNumber(0)
	//pThis->GetEntity()->SuppressBellOnError(suppress);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Validator, __IsSilent, "IsSilent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Validator, __IsSilent)
{
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsSilent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Validator, __SetWindow, "SetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Validator, __SetWindow)
{
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindow(window);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Validator, __TransferFromWindow, "TransferFromWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Validator, __TransferFromWindow)
{
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->TransferFromWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Validator, __TransferToWindow, "TransferToWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Validator, __TransferToWindow)
{
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->TransferToWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Validator, __Validate, "Validate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Validator, __Validate)
{
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Validate(parent);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxValidator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Validator)
{
	// Constructor assignment
	Gura_AssignFunction(__Validator);
	// Method assignment
	Gura_AssignMethod(wx_Validator, __Clone);
	Gura_AssignMethod(wx_Validator, __GetWindow);
	Gura_AssignMethod(wx_Validator, __SuppressBellOnError);
	Gura_AssignMethod(wx_Validator, __IsSilent);
	Gura_AssignMethod(wx_Validator, __SetWindow);
	Gura_AssignMethod(wx_Validator, __TransferFromWindow);
	Gura_AssignMethod(wx_Validator, __TransferToWindow);
	Gura_AssignMethod(wx_Validator, __Validate);
}

Gura_ImplementDescendantCreator(wx_Validator)
{
	return new Object_wx_Validator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
