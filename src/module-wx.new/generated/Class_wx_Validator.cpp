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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Validator, wxValidator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Validator, wxValidator)
{
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Validator, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Validator, Clone)
{
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Validator, GetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Validator, GetWindow)
{
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Validator, SuppressBellOnError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "suppress", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Validator, SuppressBellOnError)
{
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int suppress = arg.GetNumber(0)
	//pThis->GetEntity()->SuppressBellOnError();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Validator, IsSilent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Validator, IsSilent)
{
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSilent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Validator, SetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Validator, SetWindow)
{
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Validator, TransferFromWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Validator, TransferFromWindow)
{
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TransferFromWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Validator, TransferToWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Validator, TransferToWindow)
{
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TransferToWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Validator, Validate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Validator, Validate)
{
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->Validate();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxValidator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Validator)
{
	Gura_AssignMethod(wx_Validator, wxValidator);
	Gura_AssignMethod(wx_Validator, Clone);
	Gura_AssignMethod(wx_Validator, GetWindow);
	Gura_AssignMethod(wx_Validator, SuppressBellOnError);
	Gura_AssignMethod(wx_Validator, IsSilent);
	Gura_AssignMethod(wx_Validator, SetWindow);
	Gura_AssignMethod(wx_Validator, TransferFromWindow);
	Gura_AssignMethod(wx_Validator, TransferToWindow);
	Gura_AssignMethod(wx_Validator, Validate);
}

Gura_ImplementDescendantCreator(wx_Validator)
{
	return new Object_wx_Validator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
