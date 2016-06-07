//----------------------------------------------------------------------------
// wxPGProperty
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPGProperty
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPGProperty
//----------------------------------------------------------------------------
Object_wx_PGProperty::~Object_wx_PGProperty()
{
}

Object *Object_wx_PGProperty::Clone() const
{
	return nullptr;
}

String Object_wx_PGProperty::ToString(bool exprFlag)
{
	String rtn("<wx.PGProperty:");
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
Gura_DeclareFunctionAlias(__PGProperty, "PGProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PGProperty));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PGProperty)
{
	//wxPGProperty();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__PGProperty_1, "PGProperty_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PGProperty));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PGProperty_1)
{
	//const wxString& label = arg.GetNumber(0)
	//const wxString& name = arg.GetNumber(1)
	//wxPGProperty(label, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PGProperty, __OnSetValue, "OnSetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __OnSetValue)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnSetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __DoGetValue, "DoGetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __DoGetValue)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoGetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __ValidateValue, "ValidateValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validationInfo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __ValidateValue)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariant& value = arg.GetNumber(0)
	//wxPGValidationInfo& validationInfo = arg.GetNumber(1)
	//pThis->GetEntity()->ValidateValue(value, validationInfo);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __StringToValue, "StringToValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __StringToValue)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariant& variant = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//int argFlags = arg.GetNumber(2)
	//pThis->GetEntity()->StringToValue(variant, text, argFlags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __IntToValue, "IntToValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __IntToValue)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariant& variant = arg.GetNumber(0)
	//int number = arg.GetNumber(1)
	//int argFlags = arg.GetNumber(2)
	//pThis->GetEntity()->IntToValue(variant, number, argFlags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __ValueToString, "ValueToString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __ValueToString)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariant& value = arg.GetNumber(0)
	//int argFlags = arg.GetNumber(1)
	//pThis->GetEntity()->ValueToString(value, argFlags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetValueFromString, "SetValueFromString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetValueFromString)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->SetValueFromString(text, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetValueFromInt, "SetValueFromInt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetValueFromInt)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long value = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->SetValueFromInt(value, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __OnMeasureImage, "OnMeasureImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __OnMeasureImage)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->OnMeasureImage(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __OnEvent, "OnEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "propgrid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd_primary", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __OnEvent)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPropertyGrid* propgrid = arg.GetNumber(0)
	//wxWindow* wnd_primary = arg.GetNumber(1)
	//wxEvent& event = arg.GetNumber(2)
	//pThis->GetEntity()->OnEvent(propgrid, wnd_primary, event);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __ChildChanged, "ChildChanged")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "thisValue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "childIndex", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "childValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __ChildChanged)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariant& thisValue = arg.GetNumber(0)
	//int childIndex = arg.GetNumber(1)
	//wxVariant& childValue = arg.GetNumber(2)
	//pThis->GetEntity()->ChildChanged(thisValue, childIndex, childValue);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __DoGetEditorClass, "DoGetEditorClass")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __DoGetEditorClass)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoGetEditorClass();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __DoGetValidator, "DoGetValidator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __DoGetValidator)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoGetValidator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __OnCustomPaint, "OnCustomPaint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paintdata", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __OnCustomPaint)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//const wxRect& rect = arg.GetNumber(1)
	//wxPGPaintData& paintdata = arg.GetNumber(2)
	//pThis->GetEntity()->OnCustomPaint(dc, rect, paintdata);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetCellRenderer, "GetCellRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __GetCellRenderer)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->GetCellRenderer(column);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetChoiceSelection, "GetChoiceSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetChoiceSelection)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChoiceSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __RefreshChildren, "RefreshChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __RefreshChildren)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RefreshChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __DoSetAttribute, "DoSetAttribute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __DoSetAttribute)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxVariant& value = arg.GetNumber(1)
	//pThis->GetEntity()->DoSetAttribute(name, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __DoGetAttribute, "DoGetAttribute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __DoGetAttribute)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->DoGetAttribute(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetEditorDialog, "GetEditorDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetEditorDialog)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEditorDialog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __OnValidationFailure, "OnValidationFailure")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pendingValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __OnValidationFailure)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariant& pendingValue = arg.GetNumber(0)
	//pThis->GetEntity()->OnValidationFailure(pendingValue);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __AddChoice, "AddChoice")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __AddChoice)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& label = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->AddChoice(label, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __AddPrivateChild, "AddPrivateChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __AddPrivateChild)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGProperty* prop = arg.GetNumber(0)
	//pThis->GetEntity()->AddPrivateChild(prop);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __AdaptListToValue, "AdaptListToValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "list", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __AdaptListToValue)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariant& list = arg.GetNumber(0)
	//wxVariant* value = arg.GetNumber(1)
	//pThis->GetEntity()->AdaptListToValue(list, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __AppendChild, "AppendChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childProperty", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __AppendChild)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGProperty* childProperty = arg.GetNumber(0)
	//pThis->GetEntity()->AppendChild(childProperty);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __AreAllChildrenSpecified, "AreAllChildrenSpecified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pendingList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __AreAllChildrenSpecified)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariant* pendingList = arg.GetNumber(0)
	//pThis->GetEntity()->AreAllChildrenSpecified(pendingList);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __AreChildrenComponents, "AreChildrenComponents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __AreChildrenComponents)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AreChildrenComponents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __ChangeFlag, "ChangeFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "set", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __ChangeFlag)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropertyFlags flag = arg.GetNumber(0)
	//bool set = arg.GetNumber(1)
	//pThis->GetEntity()->ChangeFlag(flag, set);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __DeleteChildren, "DeleteChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __DeleteChildren)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __DeleteChoice, "DeleteChoice")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __DeleteChoice)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteChoice(index);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __Enable, "Enable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __Enable)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool enable = arg.GetNumber(0)
	//pThis->GetEntity()->Enable(enable);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GenerateComposedValue, "GenerateComposedValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GenerateComposedValue)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GenerateComposedValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetAttribute, "GetAttribute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __GetAttribute)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->GetAttribute(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetAttribute_1, "GetAttribute_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defVal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __GetAttribute_1)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//const wxString& defVal = arg.GetNumber(1)
	//pThis->GetEntity()->GetAttribute(name, defVal);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetAttributeAsLong, "GetAttributeAsLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defVal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __GetAttributeAsLong)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//long defVal = arg.GetNumber(1)
	//pThis->GetEntity()->GetAttributeAsLong(name, defVal);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetAttributeAsDouble, "GetAttributeAsDouble")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defVal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __GetAttributeAsDouble)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//double defVal = arg.GetNumber(1)
	//pThis->GetEntity()->GetAttributeAsDouble(name, defVal);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetAttributesAsList, "GetAttributesAsList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetAttributesAsList)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAttributesAsList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetColumnEditor, "GetColumnEditor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __GetColumnEditor)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnEditor(column);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetBaseName, "GetBaseName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetBaseName)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBaseName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetCell, "GetCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __GetCell)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int column = arg.GetNumber(0)
	//pThis->GetEntity()->GetCell(column);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetCell_1, "GetCell_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __GetCell_1)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int column = arg.GetNumber(0)
	//pThis->GetEntity()->GetCell(column);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetOrCreateCell, "GetOrCreateCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __GetOrCreateCell)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int column = arg.GetNumber(0)
	//pThis->GetEntity()->GetOrCreateCell(column);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetChildCount, "GetChildCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetChildCount)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChildCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetChildrenHeight, "GetChildrenHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lh", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iMax", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __GetChildrenHeight)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lh = arg.GetNumber(0)
	//int iMax = arg.GetNumber(1)
	//pThis->GetEntity()->GetChildrenHeight(lh, iMax);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetChoices, "GetChoices")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetChoices)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChoices();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetClientData, "GetClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetClientData)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClientData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetClientObject, "GetClientObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetClientObject)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClientObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetDefaultValue, "GetDefaultValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetDefaultValue)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetDisplayedString, "GetDisplayedString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetDisplayedString)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDisplayedString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetEditorClass, "GetEditorClass")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetEditorClass)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEditorClass();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetFlags)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetGrid, "GetGrid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetGrid)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGrid();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetGridIfDisplayed, "GetGridIfDisplayed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetGridIfDisplayed)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGridIfDisplayed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetHelpString, "GetHelpString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetHelpString)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHelpString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetIndexInParent, "GetIndexInParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetIndexInParent)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndexInParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetLabel, "GetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetLabel)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetLastVisibleSubItem, "GetLastVisibleSubItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetLastVisibleSubItem)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLastVisibleSubItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetMainParent, "GetMainParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetMainParent)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMainParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetMaxLength, "GetMaxLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetMaxLength)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaxLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetName)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetParent, "GetParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetParent)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetPropertyByName, "GetPropertyByName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __GetPropertyByName)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyByName(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetValidator, "GetValidator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetValidator)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValidator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetValue)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetValueImage, "GetValueImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetValueImage)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValueImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetValueAsString, "GetValueAsString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "argFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __GetValueAsString)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int argFlags = arg.GetNumber(0)
	//pThis->GetEntity()->GetValueAsString(argFlags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __wxDEPRECATED, "wxDEPRECATED")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "argFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __wxDEPRECATED)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString GetValueString( int argFlags = arg.GetNumber(0)
	//pThis->GetEntity()->wxDEPRECATED(argFlags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetValueType, "GetValueType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetValueType)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValueType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __GetY, "GetY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __GetY)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __HasFlag, "HasFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __HasFlag)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropertyFlags flag = arg.GetNumber(0)
	//pThis->GetEntity()->HasFlag(flag);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __HasVisibleChildren, "HasVisibleChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __HasVisibleChildren)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasVisibleChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __Hide, "Hide")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hide", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __Hide)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool hide = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Hide(hide, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __Index, "Index")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __Index)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPGProperty* p = arg.GetNumber(0)
	//pThis->GetEntity()->Index(p);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __InsertChild, "InsertChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "childProperty", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __InsertChild)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//wxPGProperty* childProperty = arg.GetNumber(1)
	//pThis->GetEntity()->InsertChild(index, childProperty);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __InsertChoice, "InsertChoice")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __InsertChoice)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& label = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->InsertChoice(label, index, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __IsCategory, "IsCategory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __IsCategory)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsCategory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __IsEnabled, "IsEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __IsEnabled)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __IsExpanded, "IsExpanded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __IsExpanded)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsExpanded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __IsRoot, "IsRoot")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __IsRoot)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsRoot();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __IsSomeParent, "IsSomeParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "candidateParent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __IsSomeParent)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGProperty* candidateParent = arg.GetNumber(0)
	//pThis->GetEntity()->IsSomeParent(candidateParent);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __IsTextEditable, "IsTextEditable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __IsTextEditable)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsTextEditable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __IsValueUnspecified, "IsValueUnspecified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __IsValueUnspecified)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsValueUnspecified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __IsVisible, "IsVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __IsVisible)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __Item, "Item")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __Item)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int i = arg.GetNumber(0)
	//pThis->GetEntity()->Item(i);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __RefreshEditor, "RefreshEditor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __RefreshEditor)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RefreshEditor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetAttribute, "SetAttribute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetAttribute)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxVariant value = arg.GetNumber(1)
	//pThis->GetEntity()->SetAttribute(name, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetAutoUnspecified, "SetAutoUnspecified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetAutoUnspecified)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool enable = arg.GetNumber(0)
	//pThis->GetEntity()->SetAutoUnspecified(enable);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetBackgroundColour, "SetBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetBackgroundColour)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colour = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->SetBackgroundColour(colour, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetEditor, "SetEditor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetEditor)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPGEditor* editor = arg.GetNumber(0)
	//pThis->GetEntity()->SetEditor(editor);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetEditor_1, "SetEditor_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editorName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetEditor_1)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& editorName = arg.GetNumber(0)
	//pThis->GetEntity()->SetEditor(editorName);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetCell, "SetCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetCell)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//const wxPGCell& cell = arg.GetNumber(1)
	//pThis->GetEntity()->SetCell(column, cell);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetChoices, "SetChoices")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetChoices)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGChoices& choices = arg.GetNumber(0)
	//pThis->GetEntity()->SetChoices(choices);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetClientData, "SetClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetClientData)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* clientData = arg.GetNumber(0)
	//pThis->GetEntity()->SetClientData(clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetClientObject, "SetClientObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clientObject", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetClientObject)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxClientData* clientObject = arg.GetNumber(0)
	//pThis->GetEntity()->SetClientObject(clientObject);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetChoiceSelection, "SetChoiceSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetChoiceSelection)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int newValue = arg.GetNumber(0)
	//pThis->GetEntity()->SetChoiceSelection(newValue);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetDefaultValue, "SetDefaultValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetDefaultValue)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariant& value = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultValue(value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetFlagRecursively, "SetFlagRecursively")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "set", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetFlagRecursively)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropertyFlags flag = arg.GetNumber(0)
	//bool set = arg.GetNumber(1)
	//pThis->GetEntity()->SetFlagRecursively(flag, set);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetHelpString, "SetHelpString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetHelpString)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& helpString = arg.GetNumber(0)
	//pThis->GetEntity()->SetHelpString(helpString);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetLabel, "SetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetLabel)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& label = arg.GetNumber(0)
	//pThis->GetEntity()->SetLabel(label);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetMaxLength, "SetMaxLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "maxLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetMaxLength)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int maxLen = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxLength(maxLen);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetModifiedStatus, "SetModifiedStatus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "modified", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetModifiedStatus)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool modified = arg.GetNumber(0)
	//pThis->GetEntity()->SetModifiedStatus(modified);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetName, "SetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetName)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& newName = arg.GetNumber(0)
	//pThis->GetEntity()->SetName(newName);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetParentalType, "SetParentalType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetParentalType)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetParentalType(flag);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetTextColour, "SetTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetTextColour)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colour = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->SetTextColour(colour, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetValidator, "SetValidator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetValidator)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxValidator& validator = arg.GetNumber(0)
	//pThis->GetEntity()->SetValidator(validator);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pList", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetValue)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariant value = arg.GetNumber(0)
	//wxVariant* pList = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->SetValue(value, pList, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetValueImage, "SetValueImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetValueImage)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxBitmap& bmp = arg.GetNumber(0)
	//pThis->GetEntity()->SetValueImage(bmp);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetValueInEvent, "SetValueInEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetValueInEvent)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariant value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValueInEvent(value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetValueToUnspecified, "SetValueToUnspecified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __SetValueToUnspecified)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetValueToUnspecified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __SetWasModified, "SetWasModified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "set", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, __SetWasModified)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool set = arg.GetNumber(0)
	//pThis->GetEntity()->SetWasModified(set);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __UpdateParentValues, "UpdateParentValues")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __UpdateParentValues)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UpdateParentValues();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __UsesAutoUnspecified, "UsesAutoUnspecified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __UsesAutoUnspecified)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UsesAutoUnspecified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGProperty, __Empty, "Empty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, __Empty)
{
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Empty();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPGProperty
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PGProperty)
{
	// Constructor assignment
	Gura_AssignFunction(__PGProperty);
	Gura_AssignFunction(__PGProperty_1);
	// Method assignment
	Gura_AssignMethod(wx_PGProperty, __OnSetValue);
	Gura_AssignMethod(wx_PGProperty, __DoGetValue);
	Gura_AssignMethod(wx_PGProperty, __ValidateValue);
	Gura_AssignMethod(wx_PGProperty, __StringToValue);
	Gura_AssignMethod(wx_PGProperty, __IntToValue);
	Gura_AssignMethod(wx_PGProperty, __ValueToString);
	Gura_AssignMethod(wx_PGProperty, __SetValueFromString);
	Gura_AssignMethod(wx_PGProperty, __SetValueFromInt);
	Gura_AssignMethod(wx_PGProperty, __OnMeasureImage);
	Gura_AssignMethod(wx_PGProperty, __OnEvent);
	Gura_AssignMethod(wx_PGProperty, __ChildChanged);
	Gura_AssignMethod(wx_PGProperty, __DoGetEditorClass);
	Gura_AssignMethod(wx_PGProperty, __DoGetValidator);
	Gura_AssignMethod(wx_PGProperty, __OnCustomPaint);
	Gura_AssignMethod(wx_PGProperty, __GetCellRenderer);
	Gura_AssignMethod(wx_PGProperty, __GetChoiceSelection);
	Gura_AssignMethod(wx_PGProperty, __RefreshChildren);
	Gura_AssignMethod(wx_PGProperty, __DoSetAttribute);
	Gura_AssignMethod(wx_PGProperty, __DoGetAttribute);
	Gura_AssignMethod(wx_PGProperty, __GetEditorDialog);
	Gura_AssignMethod(wx_PGProperty, __OnValidationFailure);
	Gura_AssignMethod(wx_PGProperty, __AddChoice);
	Gura_AssignMethod(wx_PGProperty, __AddPrivateChild);
	Gura_AssignMethod(wx_PGProperty, __AdaptListToValue);
	Gura_AssignMethod(wx_PGProperty, __AppendChild);
	Gura_AssignMethod(wx_PGProperty, __AreAllChildrenSpecified);
	Gura_AssignMethod(wx_PGProperty, __AreChildrenComponents);
	Gura_AssignMethod(wx_PGProperty, __ChangeFlag);
	Gura_AssignMethod(wx_PGProperty, __DeleteChildren);
	Gura_AssignMethod(wx_PGProperty, __DeleteChoice);
	Gura_AssignMethod(wx_PGProperty, __Enable);
	Gura_AssignMethod(wx_PGProperty, __GenerateComposedValue);
	Gura_AssignMethod(wx_PGProperty, __GetAttribute);
	Gura_AssignMethod(wx_PGProperty, __GetAttribute_1);
	Gura_AssignMethod(wx_PGProperty, __GetAttributeAsLong);
	Gura_AssignMethod(wx_PGProperty, __GetAttributeAsDouble);
	Gura_AssignMethod(wx_PGProperty, __GetAttributesAsList);
	Gura_AssignMethod(wx_PGProperty, __GetColumnEditor);
	Gura_AssignMethod(wx_PGProperty, __GetBaseName);
	Gura_AssignMethod(wx_PGProperty, __GetCell);
	Gura_AssignMethod(wx_PGProperty, __GetCell_1);
	Gura_AssignMethod(wx_PGProperty, __GetOrCreateCell);
	Gura_AssignMethod(wx_PGProperty, __GetChildCount);
	Gura_AssignMethod(wx_PGProperty, __GetChildrenHeight);
	Gura_AssignMethod(wx_PGProperty, __GetChoices);
	Gura_AssignMethod(wx_PGProperty, __GetClientData);
	Gura_AssignMethod(wx_PGProperty, __GetClientObject);
	Gura_AssignMethod(wx_PGProperty, __GetDefaultValue);
	Gura_AssignMethod(wx_PGProperty, __GetDisplayedString);
	Gura_AssignMethod(wx_PGProperty, __GetEditorClass);
	Gura_AssignMethod(wx_PGProperty, __GetFlags);
	Gura_AssignMethod(wx_PGProperty, __GetGrid);
	Gura_AssignMethod(wx_PGProperty, __GetGridIfDisplayed);
	Gura_AssignMethod(wx_PGProperty, __GetHelpString);
	Gura_AssignMethod(wx_PGProperty, __GetIndexInParent);
	Gura_AssignMethod(wx_PGProperty, __GetLabel);
	Gura_AssignMethod(wx_PGProperty, __GetLastVisibleSubItem);
	Gura_AssignMethod(wx_PGProperty, __GetMainParent);
	Gura_AssignMethod(wx_PGProperty, __GetMaxLength);
	Gura_AssignMethod(wx_PGProperty, __GetName);
	Gura_AssignMethod(wx_PGProperty, __GetParent);
	Gura_AssignMethod(wx_PGProperty, __GetPropertyByName);
	Gura_AssignMethod(wx_PGProperty, __GetValidator);
	Gura_AssignMethod(wx_PGProperty, __GetValue);
	Gura_AssignMethod(wx_PGProperty, __GetValueImage);
	Gura_AssignMethod(wx_PGProperty, __GetValueAsString);
	Gura_AssignMethod(wx_PGProperty, __wxDEPRECATED);
	Gura_AssignMethod(wx_PGProperty, __GetValueType);
	Gura_AssignMethod(wx_PGProperty, __GetY);
	Gura_AssignMethod(wx_PGProperty, __HasFlag);
	Gura_AssignMethod(wx_PGProperty, __HasVisibleChildren);
	Gura_AssignMethod(wx_PGProperty, __Hide);
	Gura_AssignMethod(wx_PGProperty, __Index);
	Gura_AssignMethod(wx_PGProperty, __InsertChild);
	Gura_AssignMethod(wx_PGProperty, __InsertChoice);
	Gura_AssignMethod(wx_PGProperty, __IsCategory);
	Gura_AssignMethod(wx_PGProperty, __IsEnabled);
	Gura_AssignMethod(wx_PGProperty, __IsExpanded);
	Gura_AssignMethod(wx_PGProperty, __IsRoot);
	Gura_AssignMethod(wx_PGProperty, __IsSomeParent);
	Gura_AssignMethod(wx_PGProperty, __IsTextEditable);
	Gura_AssignMethod(wx_PGProperty, __IsValueUnspecified);
	Gura_AssignMethod(wx_PGProperty, __IsVisible);
	Gura_AssignMethod(wx_PGProperty, __Item);
	Gura_AssignMethod(wx_PGProperty, __RefreshEditor);
	Gura_AssignMethod(wx_PGProperty, __SetAttribute);
	Gura_AssignMethod(wx_PGProperty, __SetAutoUnspecified);
	Gura_AssignMethod(wx_PGProperty, __SetBackgroundColour);
	Gura_AssignMethod(wx_PGProperty, __SetEditor);
	Gura_AssignMethod(wx_PGProperty, __SetEditor_1);
	Gura_AssignMethod(wx_PGProperty, __SetCell);
	Gura_AssignMethod(wx_PGProperty, __SetChoices);
	Gura_AssignMethod(wx_PGProperty, __SetClientData);
	Gura_AssignMethod(wx_PGProperty, __SetClientObject);
	Gura_AssignMethod(wx_PGProperty, __SetChoiceSelection);
	Gura_AssignMethod(wx_PGProperty, __SetDefaultValue);
	Gura_AssignMethod(wx_PGProperty, __SetFlagRecursively);
	Gura_AssignMethod(wx_PGProperty, __SetHelpString);
	Gura_AssignMethod(wx_PGProperty, __SetLabel);
	Gura_AssignMethod(wx_PGProperty, __SetMaxLength);
	Gura_AssignMethod(wx_PGProperty, __SetModifiedStatus);
	Gura_AssignMethod(wx_PGProperty, __SetName);
	Gura_AssignMethod(wx_PGProperty, __SetParentalType);
	Gura_AssignMethod(wx_PGProperty, __SetTextColour);
	Gura_AssignMethod(wx_PGProperty, __SetValidator);
	Gura_AssignMethod(wx_PGProperty, __SetValue);
	Gura_AssignMethod(wx_PGProperty, __SetValueImage);
	Gura_AssignMethod(wx_PGProperty, __SetValueInEvent);
	Gura_AssignMethod(wx_PGProperty, __SetValueToUnspecified);
	Gura_AssignMethod(wx_PGProperty, __SetWasModified);
	Gura_AssignMethod(wx_PGProperty, __UpdateParentValues);
	Gura_AssignMethod(wx_PGProperty, __UsesAutoUnspecified);
	Gura_AssignMethod(wx_PGProperty, __Empty);
}

Gura_ImplementDescendantCreator(wx_PGProperty)
{
	return new Object_wx_PGProperty((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
