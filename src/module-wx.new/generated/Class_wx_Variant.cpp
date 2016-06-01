//----------------------------------------------------------------------------
// wxVariant
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVariant
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVariant
//----------------------------------------------------------------------------
Object_wx_Variant::~Object_wx_Variant()
{
}

Object *Object_wx_Variant::Clone() const
{
	return nullptr;
}

String Object_wx_Variant::ToString(bool exprFlag)
{
	String rtn("<wx.Variant:");
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
Gura_DeclareMethod(wx_Variant, wxVariant)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, wxVariant)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxVariant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxVariant_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, wxVariant_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->wxVariant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxVariant_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, wxVariant_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int variant = arg.GetNumber(0)
	//pThis->GetEntity()->wxVariant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxVariant_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "any", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, wxVariant_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int any = arg.GetNumber(0)
	//pThis->GetEntity()->wxVariant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxVariant_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, wxVariant_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->wxVariant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxVariant_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, wxVariant_5)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->wxVariant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxVariant_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, wxVariant_6)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->wxVariant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxVariant_7)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, wxVariant_7)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->wxVariant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxVariant_8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, wxVariant_8)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->wxVariant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxVariant_9)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, wxVariant_9)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->wxVariant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxVariant_10)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, wxVariant_10)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->wxVariant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxVariant_11)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, wxVariant_11)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->wxVariant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxVariant_12)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, wxVariant_12)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->wxVariant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxVariant_13)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, wxVariant_13)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->wxVariant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxVariant_14)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, wxVariant_14)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->wxVariant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxVariant_15)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, wxVariant_15)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->wxVariant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxVariant_16)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, wxVariant_16)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->wxVariant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, ~wxVariant)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, ~wxVariant)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxVariant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, Append)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, ClearList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, ClearList)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ClearList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Delete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, Delete)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Delete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, GetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, GetList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, GetList)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, Insert)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, NullList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, NullList)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->NullList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Convert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, Convert)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->Convert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Convert_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, Convert_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->Convert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Convert_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, Convert_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->Convert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Convert_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, Convert_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->Convert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Convert_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, Convert_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->Convert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Convert_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, Convert_5)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->Convert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Convert_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, Convert_6)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->Convert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Convert_7)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, Convert_7)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->Convert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, GetAny)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, GetAny)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAny();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, GetArrayString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, GetArrayString)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetArrayString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, GetBool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, GetBool)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, GetChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, GetChar)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, GetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, GetDateTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, GetDateTime)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDateTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, GetDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, GetDouble)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, GetLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, GetLong)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, GetLongLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, GetLongLong)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLongLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, GetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, GetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, GetType)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, GetULongLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, GetULongLong)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetULongLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, GetVoidPtr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, GetVoidPtr)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVoidPtr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, GetWxObjectPtr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, GetWxObjectPtr)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWxObjectPtr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, IsNull)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, IsNull)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsNull();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, IsType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, IsType)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->IsType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, IsValueKindOf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, IsValueKindOf)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->IsValueKindOf();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, MakeNull)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, MakeNull)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MakeNull();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, MakeString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, MakeString)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MakeString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Member)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, Member)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->Member();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, SetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Unshare)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, Unshare)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Unshare();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, double)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, double)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->double();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, long)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, long)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->long();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxLongLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, wxLongLong)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxLongLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxULongLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, wxULongLong)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxULongLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, wxChar)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxDateTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, wxDateTime)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxDateTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, wxString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, wxString)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVariant
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Variant)
{
	Gura_AssignMethod(wx_Variant, wxVariant);
	Gura_AssignMethod(wx_Variant, wxVariant_1);
	Gura_AssignMethod(wx_Variant, wxVariant_2);
	Gura_AssignMethod(wx_Variant, wxVariant_3);
	Gura_AssignMethod(wx_Variant, wxVariant_4);
	Gura_AssignMethod(wx_Variant, wxVariant_5);
	Gura_AssignMethod(wx_Variant, wxVariant_6);
	Gura_AssignMethod(wx_Variant, wxVariant_7);
	Gura_AssignMethod(wx_Variant, wxVariant_8);
	Gura_AssignMethod(wx_Variant, wxVariant_9);
	Gura_AssignMethod(wx_Variant, wxVariant_10);
	Gura_AssignMethod(wx_Variant, wxVariant_11);
	Gura_AssignMethod(wx_Variant, wxVariant_12);
	Gura_AssignMethod(wx_Variant, wxVariant_13);
	Gura_AssignMethod(wx_Variant, wxVariant_14);
	Gura_AssignMethod(wx_Variant, wxVariant_15);
	Gura_AssignMethod(wx_Variant, wxVariant_16);
	Gura_AssignMethod(wx_Variant, ~wxVariant);
	Gura_AssignMethod(wx_Variant, Append);
	Gura_AssignMethod(wx_Variant, Clear);
	Gura_AssignMethod(wx_Variant, ClearList);
	Gura_AssignMethod(wx_Variant, Delete);
	Gura_AssignMethod(wx_Variant, GetCount);
	Gura_AssignMethod(wx_Variant, GetList);
	Gura_AssignMethod(wx_Variant, Insert);
	Gura_AssignMethod(wx_Variant, NullList);
	Gura_AssignMethod(wx_Variant, Convert);
	Gura_AssignMethod(wx_Variant, Convert_1);
	Gura_AssignMethod(wx_Variant, Convert_2);
	Gura_AssignMethod(wx_Variant, Convert_3);
	Gura_AssignMethod(wx_Variant, Convert_4);
	Gura_AssignMethod(wx_Variant, Convert_5);
	Gura_AssignMethod(wx_Variant, Convert_6);
	Gura_AssignMethod(wx_Variant, Convert_7);
	Gura_AssignMethod(wx_Variant, GetAny);
	Gura_AssignMethod(wx_Variant, GetArrayString);
	Gura_AssignMethod(wx_Variant, GetBool);
	Gura_AssignMethod(wx_Variant, GetChar);
	Gura_AssignMethod(wx_Variant, GetData);
	Gura_AssignMethod(wx_Variant, GetDateTime);
	Gura_AssignMethod(wx_Variant, GetDouble);
	Gura_AssignMethod(wx_Variant, GetLong);
	Gura_AssignMethod(wx_Variant, GetLongLong);
	Gura_AssignMethod(wx_Variant, GetName);
	Gura_AssignMethod(wx_Variant, GetString);
	Gura_AssignMethod(wx_Variant, GetType);
	Gura_AssignMethod(wx_Variant, GetULongLong);
	Gura_AssignMethod(wx_Variant, GetVoidPtr);
	Gura_AssignMethod(wx_Variant, GetWxObjectPtr);
	Gura_AssignMethod(wx_Variant, IsNull);
	Gura_AssignMethod(wx_Variant, IsType);
	Gura_AssignMethod(wx_Variant, IsValueKindOf);
	Gura_AssignMethod(wx_Variant, MakeNull);
	Gura_AssignMethod(wx_Variant, MakeString);
	Gura_AssignMethod(wx_Variant, Member);
	Gura_AssignMethod(wx_Variant, SetData);
	Gura_AssignMethod(wx_Variant, Unshare);
	Gura_AssignMethod(wx_Variant, double);
	Gura_AssignMethod(wx_Variant, long);
	Gura_AssignMethod(wx_Variant, wxLongLong);
	Gura_AssignMethod(wx_Variant, wxULongLong);
	Gura_AssignMethod(wx_Variant, wxChar);
	Gura_AssignMethod(wx_Variant, wxDateTime);
	Gura_AssignMethod(wx_Variant, wxString);
}

Gura_ImplementDescendantCreator(wx_Variant)
{
	return new Object_wx_Variant((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
