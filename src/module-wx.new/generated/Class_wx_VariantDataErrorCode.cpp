//----------------------------------------------------------------------------
// wxVariantDataErrorCode
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVariantDataErrorCode
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVariantDataErrorCode
//----------------------------------------------------------------------------
Object_wx_VariantDataErrorCode::~Object_wx_VariantDataErrorCode()
{
}

Object *Object_wx_VariantDataErrorCode::Clone() const
{
	return nullptr;
}

String Object_wx_VariantDataErrorCode::ToString(bool exprFlag)
{
	String rtn("<wx.VariantDataErrorCode:");
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
Gura_DeclareMethod(wx_VariantDataErrorCode, wxVariantDataErrorCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataErrorCode, wxVariantDataErrorCode)
{
	Signal &sig = env.GetSignal();
	Object_wx_VariantDataErrorCode *pThis = Object_wx_VariantDataErrorCode::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->wxVariantDataErrorCode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantDataErrorCode, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantDataErrorCode, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_VariantDataErrorCode *pThis = Object_wx_VariantDataErrorCode::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantDataErrorCode, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataErrorCode, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_VariantDataErrorCode *pThis = Object_wx_VariantDataErrorCode::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantDataErrorCode, Eq)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataErrorCode, Eq)
{
	Signal &sig = env.GetSignal();
	Object_wx_VariantDataErrorCode *pThis = Object_wx_VariantDataErrorCode::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Eq();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantDataErrorCode, Write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataErrorCode, Write)
{
	Signal &sig = env.GetSignal();
	Object_wx_VariantDataErrorCode *pThis = Object_wx_VariantDataErrorCode::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantDataErrorCode, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantDataErrorCode, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_VariantDataErrorCode *pThis = Object_wx_VariantDataErrorCode::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantDataErrorCode, GetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantDataErrorCode, GetType)
{
	Signal &sig = env.GetSignal();
	Object_wx_VariantDataErrorCode *pThis = Object_wx_VariantDataErrorCode::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantDataErrorCode, GetAsAny)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "any", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataErrorCode, GetAsAny)
{
	Signal &sig = env.GetSignal();
	Object_wx_VariantDataErrorCode *pThis = Object_wx_VariantDataErrorCode::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int any = arg.GetNumber(0)
	//pThis->GetEntity()->GetAsAny();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVariantDataErrorCode
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VariantDataErrorCode)
{
	Gura_AssignMethod(wx_VariantDataErrorCode, wxVariantDataErrorCode);
	Gura_AssignMethod(wx_VariantDataErrorCode, GetValue);
	Gura_AssignMethod(wx_VariantDataErrorCode, SetValue);
	Gura_AssignMethod(wx_VariantDataErrorCode, Eq);
	Gura_AssignMethod(wx_VariantDataErrorCode, Write);
	Gura_AssignMethod(wx_VariantDataErrorCode, Clone);
	Gura_AssignMethod(wx_VariantDataErrorCode, GetType);
	Gura_AssignMethod(wx_VariantDataErrorCode, GetAsAny);
}

Gura_ImplementDescendantCreator(wx_VariantDataErrorCode)
{
	return new Object_wx_VariantDataErrorCode((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
