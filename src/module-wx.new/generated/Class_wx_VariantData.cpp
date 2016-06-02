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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_VariantData, wxVariantData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantData, wxVariantData)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxVariantData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantData, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantData, Clone)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantData, DecRef)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantData, DecRef)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DecRef();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantData, Eq)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantData, Eq)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Eq();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantData, GetAny)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "any", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantData, GetAny)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int any = arg.GetNumber(0)
	//pThis->GetEntity()->GetAny();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantData, GetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantData, GetType)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantData, GetValueClassInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantData, GetValueClassInfo)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValueClassInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantData, IncRef)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantData, IncRef)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IncRef();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantData, Read)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantData, Read)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->Read();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantData, Read_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantData, Read_1)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//pThis->GetEntity()->Read();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantData, Write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantData, Write)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VariantData, Write_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VariantData, Write_1)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVariantData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VariantData)
{
	Gura_AssignMethod(wx_VariantData, wxVariantData);
	Gura_AssignMethod(wx_VariantData, Clone);
	Gura_AssignMethod(wx_VariantData, DecRef);
	Gura_AssignMethod(wx_VariantData, Eq);
	Gura_AssignMethod(wx_VariantData, GetAny);
	Gura_AssignMethod(wx_VariantData, GetType);
	Gura_AssignMethod(wx_VariantData, GetValueClassInfo);
	Gura_AssignMethod(wx_VariantData, IncRef);
	Gura_AssignMethod(wx_VariantData, Read);
	Gura_AssignMethod(wx_VariantData, Read_1);
	Gura_AssignMethod(wx_VariantData, Write);
	Gura_AssignMethod(wx_VariantData, Write_1);
}

Gura_ImplementDescendantCreator(wx_VariantData)
{
	return new Object_wx_VariantData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
