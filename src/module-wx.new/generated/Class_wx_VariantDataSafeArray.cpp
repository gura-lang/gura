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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__VariantDataSafeArray, "VariantDataSafeArray")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_VariantDataSafeArray));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__VariantDataSafeArray)
{
	//SAFEARRAY* value = arg.GetNumber(0)
	//explicit _rtn = wxVariantDataSafeArray(value);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_VariantDataSafeArray, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VariantDataSafeArray, __GetValue)
{
	Object_wx_VariantDataSafeArray *pThis = Object_wx_VariantDataSafeArray::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//SAFEARRAY* _rtn = pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantDataSafeArray, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataSafeArray, __SetValue)
{
	Object_wx_VariantDataSafeArray *pThis = Object_wx_VariantDataSafeArray::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//SAFEARRAY* value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue(value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantDataSafeArray, __Eq, "Eq")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataSafeArray, __Eq)
{
	Object_wx_VariantDataSafeArray *pThis = Object_wx_VariantDataSafeArray::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariantData& data = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Eq(data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantDataSafeArray, __Write, "Write")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataSafeArray, __Write)
{
	Object_wx_VariantDataSafeArray *pThis = Object_wx_VariantDataSafeArray::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString& str = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Write(str);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantDataSafeArray, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VariantDataSafeArray, __Clone)
{
	Object_wx_VariantDataSafeArray *pThis = Object_wx_VariantDataSafeArray::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariantData* _rtn = pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantDataSafeArray, __GetType, "GetType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VariantDataSafeArray, __GetType)
{
	Object_wx_VariantDataSafeArray *pThis = Object_wx_VariantDataSafeArray::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantDataSafeArray, __GetAsAny, "GetAsAny")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "any", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataSafeArray, __GetAsAny)
{
	Object_wx_VariantDataSafeArray *pThis = Object_wx_VariantDataSafeArray::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAny* any = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->GetAsAny(any);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVariantDataSafeArray
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VariantDataSafeArray)
{
	// Constructor assignment
	Gura_AssignFunction(__VariantDataSafeArray);
	// Method assignment
	Gura_AssignMethod(wx_VariantDataSafeArray, __GetValue);
	Gura_AssignMethod(wx_VariantDataSafeArray, __SetValue);
	Gura_AssignMethod(wx_VariantDataSafeArray, __Eq);
	Gura_AssignMethod(wx_VariantDataSafeArray, __Write);
	Gura_AssignMethod(wx_VariantDataSafeArray, __Clone);
	Gura_AssignMethod(wx_VariantDataSafeArray, __GetType);
	Gura_AssignMethod(wx_VariantDataSafeArray, __GetAsAny);
}

Gura_ImplementDescendantCreator(wx_VariantDataSafeArray)
{
	return new Object_wx_VariantDataSafeArray((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
