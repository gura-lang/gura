//----------------------------------------------------------------------------
// wxRichTextProperties
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextProperties
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextProperties
//----------------------------------------------------------------------------
Object_wx_RichTextProperties::~Object_wx_RichTextProperties()
{
}

Object *Object_wx_RichTextProperties::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextProperties::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextProperties:");
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
Gura_DeclareMethod(wx_RichTextProperties, wxRichTextProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextProperties, wxRichTextProperties)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, wxRichTextProperties_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextProperties, wxRichTextProperties_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, operator=)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "props", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, operator=)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int props = arg.GetNumber(0)
	//pThis->GetEntity()->operator=();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "props", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, Copy)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int props = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextProperties, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, GetProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextProperties, GetProperties)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, GetProperties_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextProperties, GetProperties_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, SetProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "props", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, SetProperties)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int props = arg.GetNumber(0)
	//pThis->GetEntity()->SetProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, GetPropertyNames)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextProperties, GetPropertyNames)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPropertyNames();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextProperties, GetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, HasProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, HasProperty)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->HasProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, Find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, Find)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->Find();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, Remove)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, GetProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, GetProperty)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, FindOrCreateProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, FindOrCreateProperty)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->FindOrCreateProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, GetPropertyString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, GetPropertyString)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, GetPropertyLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, GetPropertyLong)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, GetPropertyBool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, GetPropertyBool)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyBool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, GetPropertyDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, GetPropertyDouble)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, SetProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, SetProperty)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int variant = arg.GetNumber(0)
	//pThis->GetEntity()->SetProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, SetProperty_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, SetProperty_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int variant = arg.GetNumber(1)
	//pThis->GetEntity()->SetProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, SetProperty_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, SetProperty_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->SetProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, SetProperty_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, SetProperty_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->SetProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, SetProperty_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, SetProperty_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->SetProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, SetProperty_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, SetProperty_5)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->SetProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, SetProperty_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, SetProperty_6)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->SetProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, RemoveProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "properties", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, RemoveProperties)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int properties = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextProperties, MergeProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "properties", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, MergeProperties)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int properties = arg.GetNumber(0)
	//pThis->GetEntity()->MergeProperties();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextProperties
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextProperties)
{
	Gura_AssignMethod(wx_RichTextProperties, wxRichTextProperties);
	Gura_AssignMethod(wx_RichTextProperties, wxRichTextProperties_1);
	Gura_AssignMethod(wx_RichTextProperties, operator=);
	Gura_AssignMethod(wx_RichTextProperties, Copy);
	Gura_AssignMethod(wx_RichTextProperties, Clear);
	Gura_AssignMethod(wx_RichTextProperties, GetProperties);
	Gura_AssignMethod(wx_RichTextProperties, GetProperties_1);
	Gura_AssignMethod(wx_RichTextProperties, SetProperties);
	Gura_AssignMethod(wx_RichTextProperties, GetPropertyNames);
	Gura_AssignMethod(wx_RichTextProperties, GetCount);
	Gura_AssignMethod(wx_RichTextProperties, HasProperty);
	Gura_AssignMethod(wx_RichTextProperties, Find);
	Gura_AssignMethod(wx_RichTextProperties, Remove);
	Gura_AssignMethod(wx_RichTextProperties, GetProperty);
	Gura_AssignMethod(wx_RichTextProperties, FindOrCreateProperty);
	Gura_AssignMethod(wx_RichTextProperties, GetPropertyString);
	Gura_AssignMethod(wx_RichTextProperties, GetPropertyLong);
	Gura_AssignMethod(wx_RichTextProperties, GetPropertyBool);
	Gura_AssignMethod(wx_RichTextProperties, GetPropertyDouble);
	Gura_AssignMethod(wx_RichTextProperties, SetProperty);
	Gura_AssignMethod(wx_RichTextProperties, SetProperty_1);
	Gura_AssignMethod(wx_RichTextProperties, SetProperty_2);
	Gura_AssignMethod(wx_RichTextProperties, SetProperty_3);
	Gura_AssignMethod(wx_RichTextProperties, SetProperty_4);
	Gura_AssignMethod(wx_RichTextProperties, SetProperty_5);
	Gura_AssignMethod(wx_RichTextProperties, SetProperty_6);
	Gura_AssignMethod(wx_RichTextProperties, RemoveProperties);
	Gura_AssignMethod(wx_RichTextProperties, MergeProperties);
}

Gura_ImplementDescendantCreator(wx_RichTextProperties)
{
	return new Object_wx_RichTextProperties((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
