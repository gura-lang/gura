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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RichTextProperties, "RichTextProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextProperties));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextProperties)
{
	//wxRichTextProperties();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextProperties_1, "RichTextProperties_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "props", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextProperties));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextProperties_1)
{
	//const wxRichTextProperties& props = arg.GetNumber(0)
	//wxRichTextProperties(props);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextProperties, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "props", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __Copy)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextProperties& props = arg.GetNumber(0)
	//pThis->GetEntity()->Copy(props);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextProperties, __Clear)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __GetProperties, "GetProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextProperties, __GetProperties)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextVariantArray& _rtn = pThis->GetEntity()->GetProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __GetProperties_1, "GetProperties_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextProperties, __GetProperties_1)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextVariantArray& _rtn = pThis->GetEntity()->GetProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __SetProperties, "SetProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "props", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __SetProperties)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextVariantArray& props = arg.GetNumber(0)
	//pThis->GetEntity()->SetProperties(props);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __GetPropertyNames, "GetPropertyNames")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextProperties, __GetPropertyNames)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArrayString _rtn = pThis->GetEntity()->GetPropertyNames();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextProperties, __GetCount)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __HasProperty, "HasProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __HasProperty)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->HasProperty(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __Find, "Find")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __Find)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->Find(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __Remove, "Remove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __Remove)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Remove(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __GetProperty, "GetProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __GetProperty)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//const wxVariant& _rtn = pThis->GetEntity()->GetProperty(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __FindOrCreateProperty, "FindOrCreateProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __FindOrCreateProperty)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxVariant* _rtn = pThis->GetEntity()->FindOrCreateProperty(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __GetPropertyString, "GetPropertyString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __GetPropertyString)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetPropertyString(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __GetPropertyLong, "GetPropertyLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __GetPropertyLong)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//long _rtn = pThis->GetEntity()->GetPropertyLong(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __GetPropertyBool, "GetPropertyBool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __GetPropertyBool)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->GetPropertyBool(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __GetPropertyDouble, "GetPropertyDouble")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __GetPropertyDouble)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//double _rtn = pThis->GetEntity()->GetPropertyDouble(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __SetProperty, "SetProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __SetProperty)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxVariant& variant = arg.GetNumber(0)
	//pThis->GetEntity()->SetProperty(variant);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __SetProperty_1, "SetProperty_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __SetProperty_1)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//const wxVariant& variant = arg.GetNumber(1)
	//pThis->GetEntity()->SetProperty(name, variant);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __SetProperty_2, "SetProperty_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __SetProperty_2)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//const wxString& value = arg.GetNumber(1)
	//pThis->GetEntity()->SetProperty(name, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __SetProperty_3, "SetProperty_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __SetProperty_3)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//const wxChar* value = arg.GetNumber(1)
	//pThis->GetEntity()->SetProperty(name, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __SetProperty_4, "SetProperty_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __SetProperty_4)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//long value = arg.GetNumber(1)
	//pThis->GetEntity()->SetProperty(name, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __SetProperty_5, "SetProperty_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __SetProperty_5)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//double value = arg.GetNumber(1)
	//pThis->GetEntity()->SetProperty(name, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __SetProperty_6, "SetProperty_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __SetProperty_6)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//bool value = arg.GetNumber(1)
	//pThis->GetEntity()->SetProperty(name, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __RemoveProperties, "RemoveProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "properties", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __RemoveProperties)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextProperties& properties = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveProperties(properties);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextProperties, __MergeProperties, "MergeProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "properties", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextProperties, __MergeProperties)
{
	Object_wx_RichTextProperties *pThis = Object_wx_RichTextProperties::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextProperties& properties = arg.GetNumber(0)
	//pThis->GetEntity()->MergeProperties(properties);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextProperties
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextProperties)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextProperties);
	Gura_AssignFunction(__RichTextProperties_1);
	// Method assignment
	Gura_AssignMethod(wx_RichTextProperties, __Copy);
	Gura_AssignMethod(wx_RichTextProperties, __Clear);
	Gura_AssignMethod(wx_RichTextProperties, __GetProperties);
	Gura_AssignMethod(wx_RichTextProperties, __GetProperties_1);
	Gura_AssignMethod(wx_RichTextProperties, __SetProperties);
	Gura_AssignMethod(wx_RichTextProperties, __GetPropertyNames);
	Gura_AssignMethod(wx_RichTextProperties, __GetCount);
	Gura_AssignMethod(wx_RichTextProperties, __HasProperty);
	Gura_AssignMethod(wx_RichTextProperties, __Find);
	Gura_AssignMethod(wx_RichTextProperties, __Remove);
	Gura_AssignMethod(wx_RichTextProperties, __GetProperty);
	Gura_AssignMethod(wx_RichTextProperties, __FindOrCreateProperty);
	Gura_AssignMethod(wx_RichTextProperties, __GetPropertyString);
	Gura_AssignMethod(wx_RichTextProperties, __GetPropertyLong);
	Gura_AssignMethod(wx_RichTextProperties, __GetPropertyBool);
	Gura_AssignMethod(wx_RichTextProperties, __GetPropertyDouble);
	Gura_AssignMethod(wx_RichTextProperties, __SetProperty);
	Gura_AssignMethod(wx_RichTextProperties, __SetProperty_1);
	Gura_AssignMethod(wx_RichTextProperties, __SetProperty_2);
	Gura_AssignMethod(wx_RichTextProperties, __SetProperty_3);
	Gura_AssignMethod(wx_RichTextProperties, __SetProperty_4);
	Gura_AssignMethod(wx_RichTextProperties, __SetProperty_5);
	Gura_AssignMethod(wx_RichTextProperties, __SetProperty_6);
	Gura_AssignMethod(wx_RichTextProperties, __RemoveProperties);
	Gura_AssignMethod(wx_RichTextProperties, __MergeProperties);
}

Gura_ImplementDescendantCreator(wx_RichTextProperties)
{
	return new Object_wx_RichTextProperties((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
