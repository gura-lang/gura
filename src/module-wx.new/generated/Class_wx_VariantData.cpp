//----------------------------------------------------------------------------
// wxVariantData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVariantData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVariantData
//----------------------------------------------------------------------------
Object_wx_VariantData::~Object_wx_VariantData()
{
}

Object *Object_wx_VariantData::Clone() const
{
	return nullptr;
}

String Object_wx_VariantData::ToString(bool exprFlag)
{
	String rtn("<wx.VariantData:");
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
Gura_DeclareFunctionAlias(__VariantData, "VariantData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_VariantData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__VariantData)
{
	//wxVariantData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_VariantData, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantData, __Clone)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantData, __DecRef, "DecRef")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantData, __DecRef)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DecRef();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantData, __Eq, "Eq")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantData, __Eq)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariantData& data = arg.GetNumber(0)
	//pThis->GetEntity()->Eq(data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantData, __GetAny, "GetAny")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "any", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantData, __GetAny)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAny* any = arg.GetNumber(0)
	//pThis->GetEntity()->GetAny(any);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantData, __GetType, "GetType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantData, __GetType)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantData, __GetValueClassInfo, "GetValueClassInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantData, __GetValueClassInfo)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValueClassInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantData, __IncRef, "IncRef")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantData, __IncRef)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IncRef();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantData, __Read, "Read")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantData, __Read)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//istream& stream = arg.GetNumber(0)
	//pThis->GetEntity()->Read(stream);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantData, __Read_1, "Read_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantData, __Read_1)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString& string = arg.GetNumber(0)
	//pThis->GetEntity()->Read(string);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantData, __Write, "Write")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantData, __Write)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//ostream& stream = arg.GetNumber(0)
	//pThis->GetEntity()->Write(stream);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VariantData, __Write_1, "Write_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantData, __Write_1)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString& string = arg.GetNumber(0)
	//pThis->GetEntity()->Write(string);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVariantData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VariantData)
{
	// Constructor assignment
	Gura_AssignFunction(__VariantData);
	// Method assignment
	Gura_AssignMethod(wx_VariantData, __Clone);
	Gura_AssignMethod(wx_VariantData, __DecRef);
	Gura_AssignMethod(wx_VariantData, __Eq);
	Gura_AssignMethod(wx_VariantData, __GetAny);
	Gura_AssignMethod(wx_VariantData, __GetType);
	Gura_AssignMethod(wx_VariantData, __GetValueClassInfo);
	Gura_AssignMethod(wx_VariantData, __IncRef);
	Gura_AssignMethod(wx_VariantData, __Read);
	Gura_AssignMethod(wx_VariantData, __Read_1);
	Gura_AssignMethod(wx_VariantData, __Write);
	Gura_AssignMethod(wx_VariantData, __Write_1);
}

Gura_ImplementDescendantCreator(wx_VariantData)
{
	return new Object_wx_VariantData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
