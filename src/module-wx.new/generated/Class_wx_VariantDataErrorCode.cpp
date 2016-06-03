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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__VariantDataErrorCode, "VariantDataErrorCode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_VariantDataErrorCode));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__VariantDataErrorCode)
{
	//SCODE value = arg.GetNumber(0)
	//wxVariantDataErrorCode();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_VariantDataErrorCode, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantDataErrorCode, __GetValue)
{
	Object_wx_VariantDataErrorCode *pThis = Object_wx_VariantDataErrorCode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantDataErrorCode, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataErrorCode, __SetValue)
{
	Object_wx_VariantDataErrorCode *pThis = Object_wx_VariantDataErrorCode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//SCODE value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantDataErrorCode, __Eq, "Eq")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataErrorCode, __Eq)
{
	Object_wx_VariantDataErrorCode *pThis = Object_wx_VariantDataErrorCode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariantData& data = arg.GetNumber(0)
	//pThis->GetEntity()->Eq();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantDataErrorCode, __Write, "Write")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataErrorCode, __Write)
{
	Object_wx_VariantDataErrorCode *pThis = Object_wx_VariantDataErrorCode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString& str = arg.GetNumber(0)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantDataErrorCode, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantDataErrorCode, __Clone)
{
	Object_wx_VariantDataErrorCode *pThis = Object_wx_VariantDataErrorCode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantDataErrorCode, __GetType, "GetType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantDataErrorCode, __GetType)
{
	Object_wx_VariantDataErrorCode *pThis = Object_wx_VariantDataErrorCode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantDataErrorCode, __GetAsAny, "GetAsAny")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "any", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantDataErrorCode, __GetAsAny)
{
	Object_wx_VariantDataErrorCode *pThis = Object_wx_VariantDataErrorCode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAny* any = arg.GetNumber(0)
	//pThis->GetEntity()->GetAsAny();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVariantDataErrorCode
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VariantDataErrorCode)
{
	// Constructor assignment
	Gura_AssignFunction(__VariantDataErrorCode);
	// Method assignment
	Gura_AssignMethod(wx_VariantDataErrorCode, __GetValue);
	Gura_AssignMethod(wx_VariantDataErrorCode, __SetValue);
	Gura_AssignMethod(wx_VariantDataErrorCode, __Eq);
	Gura_AssignMethod(wx_VariantDataErrorCode, __Write);
	Gura_AssignMethod(wx_VariantDataErrorCode, __Clone);
	Gura_AssignMethod(wx_VariantDataErrorCode, __GetType);
	Gura_AssignMethod(wx_VariantDataErrorCode, __GetAsAny);
}

Gura_ImplementDescendantCreator(wx_VariantDataErrorCode)
{
	return new Object_wx_VariantDataErrorCode((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
