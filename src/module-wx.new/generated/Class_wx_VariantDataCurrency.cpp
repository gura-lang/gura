//----------------------------------------------------------------------------
// wxVariantDataCurrency
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVariantDataCurrency
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVariantDataCurrency
//----------------------------------------------------------------------------
Object_wx_VariantDataCurrency::~Object_wx_VariantDataCurrency()
{
}

Object *Object_wx_VariantDataCurrency::Clone() const
{
	return nullptr;
}

String Object_wx_VariantDataCurrency::ToString(bool exprFlag)
{
	String rtn("<wx.VariantDataCurrency:");
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
Gura_DeclareFunctionAlias(__VariantDataCurrency, "VariantDataCurrency")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_VariantDataCurrency));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__VariantDataCurrency)
{
	//wxVariantDataCurrency();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__VariantDataCurrency_1, "VariantDataCurrency_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_VariantDataCurrency));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__VariantDataCurrency_1)
{
	//CURRENCY value = arg.GetNumber(0)
	//wxVariantDataCurrency(value);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_VariantDataCurrency, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VariantDataCurrency, __GetValue)
{
	Object_wx_VariantDataCurrency *pThis = Object_wx_VariantDataCurrency::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//CURRENCY _rtn = pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantDataCurrency, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataCurrency, __SetValue)
{
	Object_wx_VariantDataCurrency *pThis = Object_wx_VariantDataCurrency::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//CURRENCY value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue(value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantDataCurrency, __Eq, "Eq")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataCurrency, __Eq)
{
	Object_wx_VariantDataCurrency *pThis = Object_wx_VariantDataCurrency::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariantData& data = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Eq(data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantDataCurrency, __Write, "Write")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataCurrency, __Write)
{
	Object_wx_VariantDataCurrency *pThis = Object_wx_VariantDataCurrency::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString& str = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Write(str);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantDataCurrency, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VariantDataCurrency, __Clone)
{
	Object_wx_VariantDataCurrency *pThis = Object_wx_VariantDataCurrency::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariantData* _rtn = pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantDataCurrency, __GetType, "GetType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VariantDataCurrency, __GetType)
{
	Object_wx_VariantDataCurrency *pThis = Object_wx_VariantDataCurrency::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantDataCurrency, __GetAsAny, "GetAsAny")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "any", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataCurrency, __GetAsAny)
{
	Object_wx_VariantDataCurrency *pThis = Object_wx_VariantDataCurrency::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAny* any = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->GetAsAny(any);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVariantDataCurrency
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VariantDataCurrency)
{
	// Constructor assignment
	Gura_AssignFunction(__VariantDataCurrency);
	Gura_AssignFunction(__VariantDataCurrency_1);
	// Method assignment
	Gura_AssignMethod(wx_VariantDataCurrency, __GetValue);
	Gura_AssignMethod(wx_VariantDataCurrency, __SetValue);
	Gura_AssignMethod(wx_VariantDataCurrency, __Eq);
	Gura_AssignMethod(wx_VariantDataCurrency, __Write);
	Gura_AssignMethod(wx_VariantDataCurrency, __Clone);
	Gura_AssignMethod(wx_VariantDataCurrency, __GetType);
	Gura_AssignMethod(wx_VariantDataCurrency, __GetAsAny);
}

Gura_ImplementDescendantCreator(wx_VariantDataCurrency)
{
	return new Object_wx_VariantDataCurrency((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
