//----------------------------------------------------------------------------
// wxVariantDataSafeArray
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVariantDataSafeArray
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVariantDataSafeArray
//----------------------------------------------------------------------------
Object_wx_VariantDataSafeArray::~Object_wx_VariantDataSafeArray()
{
}

Object *Object_wx_VariantDataSafeArray::Clone() const
{
	return nullptr;
}

String Object_wx_VariantDataSafeArray::ToString(bool exprFlag)
{
	String rtn("<wx.VariantDataSafeArray:");
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
Gura_DeclareMethod(wx_VariantDataSafeArray, wxVariantDataSafeArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataSafeArray, wxVariantDataSafeArray)
{
	Signal &sig = env.GetSignal();
	Object_wx_VariantDataSafeArray *pThis = Object_wx_VariantDataSafeArray::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->wxVariantDataSafeArray();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantDataSafeArray, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantDataSafeArray, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_VariantDataSafeArray *pThis = Object_wx_VariantDataSafeArray::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantDataSafeArray, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataSafeArray, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_VariantDataSafeArray *pThis = Object_wx_VariantDataSafeArray::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantDataSafeArray, Eq)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataSafeArray, Eq)
{
	Signal &sig = env.GetSignal();
	Object_wx_VariantDataSafeArray *pThis = Object_wx_VariantDataSafeArray::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Eq();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantDataSafeArray, Write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataSafeArray, Write)
{
	Signal &sig = env.GetSignal();
	Object_wx_VariantDataSafeArray *pThis = Object_wx_VariantDataSafeArray::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantDataSafeArray, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantDataSafeArray, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_VariantDataSafeArray *pThis = Object_wx_VariantDataSafeArray::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantDataSafeArray, GetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantDataSafeArray, GetType)
{
	Signal &sig = env.GetSignal();
	Object_wx_VariantDataSafeArray *pThis = Object_wx_VariantDataSafeArray::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantDataSafeArray, GetAsAny)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "any", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataSafeArray, GetAsAny)
{
	Signal &sig = env.GetSignal();
	Object_wx_VariantDataSafeArray *pThis = Object_wx_VariantDataSafeArray::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int any = arg.GetNumber(0)
	//pThis->GetEntity()->GetAsAny();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVariantDataSafeArray
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VariantDataSafeArray)
{
	Gura_AssignMethod(wx_VariantDataSafeArray, wxVariantDataSafeArray);
	Gura_AssignMethod(wx_VariantDataSafeArray, GetValue);
	Gura_AssignMethod(wx_VariantDataSafeArray, SetValue);
	Gura_AssignMethod(wx_VariantDataSafeArray, Eq);
	Gura_AssignMethod(wx_VariantDataSafeArray, Write);
	Gura_AssignMethod(wx_VariantDataSafeArray, Clone);
	Gura_AssignMethod(wx_VariantDataSafeArray, GetType);
	Gura_AssignMethod(wx_VariantDataSafeArray, GetAsAny);
}

Gura_ImplementDescendantCreator(wx_VariantDataSafeArray)
{
	return new Object_wx_VariantDataSafeArray((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
