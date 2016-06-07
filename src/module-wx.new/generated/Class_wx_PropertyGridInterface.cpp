//----------------------------------------------------------------------------
// wxPropertyGridInterface
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropertyGridInterface
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropertyGridInterface
//----------------------------------------------------------------------------
Object_wx_PropertyGridInterface::~Object_wx_PropertyGridInterface()
{
}

Object *Object_wx_PropertyGridInterface::Clone() const
{
	return nullptr;
}

String Object_wx_PropertyGridInterface::ToString(bool exprFlag)
{
	String rtn("<wx.PropertyGridInterface:");
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
Gura_DeclareMethodAlias(wx_PropertyGridInterface, __Append, "Append")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __Append)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGProperty* property = arg.GetNumber(0)
	//pThis->GetEntity()->Append(property);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __AppendIn, "AppendIn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newProperty", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __AppendIn)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//wxPGProperty* newProperty = arg.GetNumber(1)
	//pThis->GetEntity()->AppendIn(id, newProperty);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __BeginAddChildren, "BeginAddChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __BeginAddChildren)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->BeginAddChildren(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __Clear)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __ClearSelection, "ClearSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "validation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __ClearSelection)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool validation = arg.GetNumber(0)
	//pThis->GetEntity()->ClearSelection(validation);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __ClearModifiedStatus, "ClearModifiedStatus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __ClearModifiedStatus)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearModifiedStatus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __Collapse, "Collapse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __Collapse)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->Collapse(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __CollapseAll, "CollapseAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __CollapseAll)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CollapseAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __ChangePropertyValue, "ChangePropertyValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __ChangePropertyValue)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//wxVariant newValue = arg.GetNumber(1)
	//pThis->GetEntity()->ChangePropertyValue(id, newValue);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __DeleteProperty, "DeleteProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __DeleteProperty)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteProperty(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __DisableProperty, "DisableProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __DisableProperty)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->DisableProperty(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __EditorValidate, "EditorValidate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __EditorValidate)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EditorValidate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __EnableProperty, "EnableProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __EnableProperty)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//bool enable = arg.GetNumber(1)
	//pThis->GetEntity()->EnableProperty(id, enable);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __EndAddChildren, "EndAddChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __EndAddChildren)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->EndAddChildren(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __Expand, "Expand")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __Expand)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->Expand(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __ExpandAll, "ExpandAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "expand", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __ExpandAll)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool expand = arg.GetNumber(0)
	//pThis->GetEntity()->ExpandAll(expand);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetColumnProportion, "GetColumnProportion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetColumnProportion)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int column = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnProportion(column);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetFirstChild, "GetFirstChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetFirstChild)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetFirstChild(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetIterator, "GetIterator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "firstProp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetIterator)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//wxPGProperty* firstProp = arg.GetNumber(1)
	//pThis->GetEntity()->GetIterator(flags, firstProp);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetIterator_1, "GetIterator_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "firstProp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetIterator_1)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//wxPGProperty* firstProp = arg.GetNumber(1)
	//pThis->GetEntity()->GetIterator(flags, firstProp);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetIterator_2, "GetIterator_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetIterator_2)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int startPos = arg.GetNumber(1)
	//pThis->GetEntity()->GetIterator(flags, startPos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetIterator_3, "GetIterator_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetIterator_3)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int startPos = arg.GetNumber(1)
	//pThis->GetEntity()->GetIterator(flags, startPos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetFirst, "GetFirst")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetFirst)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->GetFirst(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetProperty, "GetProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetProperty)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->GetProperty(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertiesWithFlag, "GetPropertiesWithFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "targetArr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inverse", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iterFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertiesWithFlag)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArrayPGProperty* targetArr = arg.GetNumber(0)
	//wxPGProperty::FlagType flags = arg.GetNumber(1)
	//bool inverse = arg.GetNumber(2)
	//int iterFlags = arg.GetNumber(3)
	//pThis->GetEntity()->GetPropertiesWithFlag(targetArr, flags, inverse, iterFlags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyAttribute, "GetPropertyAttribute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attrName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyAttribute)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//const wxString& attrName = arg.GetNumber(1)
	//pThis->GetEntity()->GetPropertyAttribute(id, attrName);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyBackgroundColour, "GetPropertyBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyBackgroundColour)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyBackgroundColour(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyCategory, "GetPropertyCategory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyCategory)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyCategory(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyClientData, "GetPropertyClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyClientData)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyClientData(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyByLabel, "GetPropertyByLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyByLabel)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& label = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyByLabel(label);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyByName, "GetPropertyByName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyByName)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyByName(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyByName_1, "GetPropertyByName_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "subname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyByName_1)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//const wxString& subname = arg.GetNumber(1)
	//pThis->GetEntity()->GetPropertyByName(name, subname);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyEditor, "GetPropertyEditor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyEditor)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyEditor(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyHelpString, "GetPropertyHelpString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyHelpString)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyHelpString(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyImage, "GetPropertyImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyImage)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyImage(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyLabel, "GetPropertyLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyLabel)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyLabel(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyName, "GetPropertyName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyName)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGProperty* property = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyName(property);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyTextColour, "GetPropertyTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyTextColour)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyTextColour(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyValidator, "GetPropertyValidator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyValidator)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValidator(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyValue, "GetPropertyValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyValue)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValue(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyValueAsArrayInt, "GetPropertyValueAsArrayInt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyValueAsArrayInt)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsArrayInt(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyValueAsArrayString, "GetPropertyValueAsArrayString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyValueAsArrayString)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsArrayString(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyValueAsBool, "GetPropertyValueAsBool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyValueAsBool)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsBool(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyValueAsDateTime, "GetPropertyValueAsDateTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyValueAsDateTime)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsDateTime(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyValueAsDouble, "GetPropertyValueAsDouble")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyValueAsDouble)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsDouble(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyValueAsInt, "GetPropertyValueAsInt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyValueAsInt)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsInt(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyValueAsLong, "GetPropertyValueAsLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyValueAsLong)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsLong(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyValueAsLongLong, "GetPropertyValueAsLongLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyValueAsLongLong)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsLongLong(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyValueAsString, "GetPropertyValueAsString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyValueAsString)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsString(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyValueAsULong, "GetPropertyValueAsULong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyValueAsULong)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsULong(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyValueAsULongLong, "GetPropertyValueAsULongLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyValueAsULongLong)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsULongLong(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetPropertyValues, "GetPropertyValues")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "listname", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "baseparent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetPropertyValues)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& listname = arg.GetNumber(0)
	//wxPGProperty* baseparent = arg.GetNumber(1)
	//long flags = arg.GetNumber(2)
	//pThis->GetEntity()->GetPropertyValues(listname, baseparent, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetSelectedProperties, "GetSelectedProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetSelectedProperties)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetSelection)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __GetVIterator, "GetVIterator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __GetVIterator)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->GetVIterator(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __HideProperty, "HideProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hide", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __HideProperty)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//bool hide = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->HideProperty(id, hide, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __InitAllTypeHandlers, "InitAllTypeHandlers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __InitAllTypeHandlers)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->InitAllTypeHandlers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __Insert, "Insert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "priorThis", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newProperty", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __Insert)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg priorThis = arg.GetNumber(0)
	//wxPGProperty* newProperty = arg.GetNumber(1)
	//pThis->GetEntity()->Insert(priorThis, newProperty);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __Insert_1, "Insert_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newProperty", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __Insert_1)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg parent = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//wxPGProperty* newProperty = arg.GetNumber(2)
	//pThis->GetEntity()->Insert(parent, index, newProperty);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __IsPropertyCategory, "IsPropertyCategory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __IsPropertyCategory)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->IsPropertyCategory(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __IsPropertyEnabled, "IsPropertyEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __IsPropertyEnabled)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->IsPropertyEnabled(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __IsPropertyExpanded, "IsPropertyExpanded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __IsPropertyExpanded)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->IsPropertyExpanded(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __IsPropertyModified, "IsPropertyModified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __IsPropertyModified)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->IsPropertyModified(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __IsPropertySelected, "IsPropertySelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __IsPropertySelected)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->IsPropertySelected(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __IsPropertyShown, "IsPropertyShown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __IsPropertyShown)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->IsPropertyShown(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __IsPropertyValueUnspecified, "IsPropertyValueUnspecified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __IsPropertyValueUnspecified)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->IsPropertyValueUnspecified(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __LimitPropertyEditing, "LimitPropertyEditing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "limit", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __LimitPropertyEditing)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//bool limit = arg.GetNumber(1)
	//pThis->GetEntity()->LimitPropertyEditing(id, limit);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __RegisterAdditionalEditors, "RegisterAdditionalEditors")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __RegisterAdditionalEditors)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RegisterAdditionalEditors();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __RemoveProperty, "RemoveProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __RemoveProperty)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveProperty(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridInterface, __ReplaceProperty, "ReplaceProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, __ReplaceProperty)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//wxPGProperty* property = arg.GetNumber(1)
	//pThis->GetEntity()->ReplaceProperty(id, property);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPropertyGridInterface
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertyGridInterface)
{
	// Class assignment
	Gura_AssignValueEx("PropertyGridInterface", Reference());
	// Method assignment
	Gura_AssignMethod(wx_PropertyGridInterface, __Append);
	Gura_AssignMethod(wx_PropertyGridInterface, __AppendIn);
	Gura_AssignMethod(wx_PropertyGridInterface, __BeginAddChildren);
	Gura_AssignMethod(wx_PropertyGridInterface, __Clear);
	Gura_AssignMethod(wx_PropertyGridInterface, __ClearSelection);
	Gura_AssignMethod(wx_PropertyGridInterface, __ClearModifiedStatus);
	Gura_AssignMethod(wx_PropertyGridInterface, __Collapse);
	Gura_AssignMethod(wx_PropertyGridInterface, __CollapseAll);
	Gura_AssignMethod(wx_PropertyGridInterface, __ChangePropertyValue);
	Gura_AssignMethod(wx_PropertyGridInterface, __DeleteProperty);
	Gura_AssignMethod(wx_PropertyGridInterface, __DisableProperty);
	Gura_AssignMethod(wx_PropertyGridInterface, __EditorValidate);
	Gura_AssignMethod(wx_PropertyGridInterface, __EnableProperty);
	Gura_AssignMethod(wx_PropertyGridInterface, __EndAddChildren);
	Gura_AssignMethod(wx_PropertyGridInterface, __Expand);
	Gura_AssignMethod(wx_PropertyGridInterface, __ExpandAll);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetColumnProportion);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetFirstChild);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetIterator);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetIterator_1);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetIterator_2);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetIterator_3);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetFirst);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetProperty);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertiesWithFlag);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyAttribute);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyBackgroundColour);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyCategory);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyClientData);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyByLabel);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyByName);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyByName_1);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyEditor);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyHelpString);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyImage);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyLabel);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyName);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyTextColour);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyValidator);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyValue);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyValueAsArrayInt);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyValueAsArrayString);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyValueAsBool);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyValueAsDateTime);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyValueAsDouble);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyValueAsInt);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyValueAsLong);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyValueAsLongLong);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyValueAsString);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyValueAsULong);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyValueAsULongLong);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetPropertyValues);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetSelectedProperties);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetSelection);
	Gura_AssignMethod(wx_PropertyGridInterface, __GetVIterator);
	Gura_AssignMethod(wx_PropertyGridInterface, __HideProperty);
	Gura_AssignMethod(wx_PropertyGridInterface, __InitAllTypeHandlers);
	Gura_AssignMethod(wx_PropertyGridInterface, __Insert);
	Gura_AssignMethod(wx_PropertyGridInterface, __Insert_1);
	Gura_AssignMethod(wx_PropertyGridInterface, __IsPropertyCategory);
	Gura_AssignMethod(wx_PropertyGridInterface, __IsPropertyEnabled);
	Gura_AssignMethod(wx_PropertyGridInterface, __IsPropertyExpanded);
	Gura_AssignMethod(wx_PropertyGridInterface, __IsPropertyModified);
	Gura_AssignMethod(wx_PropertyGridInterface, __IsPropertySelected);
	Gura_AssignMethod(wx_PropertyGridInterface, __IsPropertyShown);
	Gura_AssignMethod(wx_PropertyGridInterface, __IsPropertyValueUnspecified);
	Gura_AssignMethod(wx_PropertyGridInterface, __LimitPropertyEditing);
	Gura_AssignMethod(wx_PropertyGridInterface, __RegisterAdditionalEditors);
	Gura_AssignMethod(wx_PropertyGridInterface, __RemoveProperty);
	Gura_AssignMethod(wx_PropertyGridInterface, __ReplaceProperty);
}

Gura_ImplementDescendantCreator(wx_PropertyGridInterface)
{
	return new Object_wx_PropertyGridInterface((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
