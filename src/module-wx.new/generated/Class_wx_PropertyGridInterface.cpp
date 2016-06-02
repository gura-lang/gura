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
Gura_DeclareMethod(wx_PropertyGridInterface, Append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, Append)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, AppendIn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newProperty", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, AppendIn)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int newProperty = arg.GetNumber(1)
	//pThis->GetEntity()->AppendIn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, BeginAddChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, BeginAddChildren)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->BeginAddChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridInterface, Clear)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, ClearSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "validation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, ClearSelection)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int validation = arg.GetNumber(0)
	//pThis->GetEntity()->ClearSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, ClearModifiedStatus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridInterface, ClearModifiedStatus)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearModifiedStatus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, Collapse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, Collapse)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->Collapse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, CollapseAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridInterface, CollapseAll)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CollapseAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, ChangePropertyValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, ChangePropertyValue)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int newValue = arg.GetNumber(1)
	//pThis->GetEntity()->ChangePropertyValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, DeleteProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, DeleteProperty)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, DisableProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, DisableProperty)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->DisableProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, EditorValidate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridInterface, EditorValidate)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EditorValidate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, EnableProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, EnableProperty)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int enable = arg.GetNumber(1)
	//pThis->GetEntity()->EnableProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, EndAddChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, EndAddChildren)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->EndAddChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, Expand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, Expand)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->Expand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, ExpandAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "expand", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, ExpandAll)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int expand = arg.GetNumber(0)
	//pThis->GetEntity()->ExpandAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetColumnProportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetColumnProportion)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnProportion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetFirstChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetFirstChild)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetFirstChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetIterator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "firstProp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetIterator)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int firstProp = arg.GetNumber(1)
	//pThis->GetEntity()->GetIterator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetIterator_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "firstProp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetIterator_1)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int firstProp = arg.GetNumber(1)
	//pThis->GetEntity()->GetIterator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetIterator_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetIterator_2)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int startPos = arg.GetNumber(1)
	//pThis->GetEntity()->GetIterator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetIterator_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetIterator_3)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int startPos = arg.GetNumber(1)
	//pThis->GetEntity()->GetIterator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetFirst)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->GetFirst();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetProperty)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertiesWithFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "targetArr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inverse", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iterFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertiesWithFlag)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int targetArr = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//int inverse = arg.GetNumber(2)
	//int iterFlags = arg.GetNumber(3)
	//pThis->GetEntity()->GetPropertiesWithFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyAttribute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attrName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyAttribute)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int attrName = arg.GetNumber(1)
	//pThis->GetEntity()->GetPropertyAttribute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyBackgroundColour)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyCategory)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyCategory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyClientData)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyByLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyByLabel)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyByLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyByName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyByName)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyByName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyByName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "subname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyByName_1)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int subname = arg.GetNumber(1)
	//pThis->GetEntity()->GetPropertyByName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyEditor)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyEditor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyHelpString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyHelpString)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyHelpString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyImage)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyLabel)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyName)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyTextColour)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyValidator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyValidator)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyValue)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyValueAsArrayInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyValueAsArrayInt)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsArrayInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyValueAsArrayString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyValueAsArrayString)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsArrayString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyValueAsBool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyValueAsBool)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsBool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyValueAsDateTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyValueAsDateTime)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsDateTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyValueAsDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyValueAsDouble)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyValueAsInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyValueAsInt)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyValueAsLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyValueAsLong)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyValueAsLongLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyValueAsLongLong)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsLongLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyValueAsString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyValueAsString)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyValueAsULong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyValueAsULong)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsULong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyValueAsULongLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyValueAsULongLong)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyValueAsULongLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetPropertyValues)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "listname", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "baseparent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetPropertyValues)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int listname = arg.GetNumber(0)
	//int baseparent = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->GetPropertyValues();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetSelectedProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetSelectedProperties)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetSelection)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, GetVIterator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, GetVIterator)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->GetVIterator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, HideProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hide", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, HideProperty)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int hide = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->HideProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, InitAllTypeHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridInterface, InitAllTypeHandlers)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->InitAllTypeHandlers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "priorThis", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newProperty", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, Insert)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int priorThis = arg.GetNumber(0)
	//int newProperty = arg.GetNumber(1)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, Insert_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newProperty", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, Insert_1)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//int newProperty = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, IsPropertyCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, IsPropertyCategory)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsPropertyCategory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, IsPropertyEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, IsPropertyEnabled)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsPropertyEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, IsPropertyExpanded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, IsPropertyExpanded)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsPropertyExpanded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, IsPropertyModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, IsPropertyModified)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsPropertyModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, IsPropertySelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, IsPropertySelected)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsPropertySelected();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, IsPropertyShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, IsPropertyShown)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsPropertyShown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, IsPropertyValueUnspecified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, IsPropertyValueUnspecified)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsPropertyValueUnspecified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, LimitPropertyEditing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "limit", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, LimitPropertyEditing)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int limit = arg.GetNumber(1)
	//pThis->GetEntity()->LimitPropertyEditing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, RegisterAdditionalEditors)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridInterface, RegisterAdditionalEditors)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RegisterAdditionalEditors();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, RemoveProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, RemoveProperty)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridInterface, ReplaceProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridInterface, ReplaceProperty)
{
	Object_wx_PropertyGridInterface *pThis = Object_wx_PropertyGridInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int property = arg.GetNumber(1)
	//pThis->GetEntity()->ReplaceProperty();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPropertyGridInterface
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertyGridInterface)
{
	Gura_AssignMethod(wx_PropertyGridInterface, Append);
	Gura_AssignMethod(wx_PropertyGridInterface, AppendIn);
	Gura_AssignMethod(wx_PropertyGridInterface, BeginAddChildren);
	Gura_AssignMethod(wx_PropertyGridInterface, Clear);
	Gura_AssignMethod(wx_PropertyGridInterface, ClearSelection);
	Gura_AssignMethod(wx_PropertyGridInterface, ClearModifiedStatus);
	Gura_AssignMethod(wx_PropertyGridInterface, Collapse);
	Gura_AssignMethod(wx_PropertyGridInterface, CollapseAll);
	Gura_AssignMethod(wx_PropertyGridInterface, ChangePropertyValue);
	Gura_AssignMethod(wx_PropertyGridInterface, DeleteProperty);
	Gura_AssignMethod(wx_PropertyGridInterface, DisableProperty);
	Gura_AssignMethod(wx_PropertyGridInterface, EditorValidate);
	Gura_AssignMethod(wx_PropertyGridInterface, EnableProperty);
	Gura_AssignMethod(wx_PropertyGridInterface, EndAddChildren);
	Gura_AssignMethod(wx_PropertyGridInterface, Expand);
	Gura_AssignMethod(wx_PropertyGridInterface, ExpandAll);
	Gura_AssignMethod(wx_PropertyGridInterface, GetColumnProportion);
	Gura_AssignMethod(wx_PropertyGridInterface, GetFirstChild);
	Gura_AssignMethod(wx_PropertyGridInterface, GetIterator);
	Gura_AssignMethod(wx_PropertyGridInterface, GetIterator_1);
	Gura_AssignMethod(wx_PropertyGridInterface, GetIterator_2);
	Gura_AssignMethod(wx_PropertyGridInterface, GetIterator_3);
	Gura_AssignMethod(wx_PropertyGridInterface, GetFirst);
	Gura_AssignMethod(wx_PropertyGridInterface, GetProperty);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertiesWithFlag);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyAttribute);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyBackgroundColour);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyCategory);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyClientData);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyByLabel);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyByName);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyByName_1);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyEditor);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyHelpString);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyImage);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyLabel);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyName);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyTextColour);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyValidator);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyValue);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyValueAsArrayInt);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyValueAsArrayString);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyValueAsBool);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyValueAsDateTime);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyValueAsDouble);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyValueAsInt);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyValueAsLong);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyValueAsLongLong);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyValueAsString);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyValueAsULong);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyValueAsULongLong);
	Gura_AssignMethod(wx_PropertyGridInterface, GetPropertyValues);
	Gura_AssignMethod(wx_PropertyGridInterface, GetSelectedProperties);
	Gura_AssignMethod(wx_PropertyGridInterface, GetSelection);
	Gura_AssignMethod(wx_PropertyGridInterface, GetVIterator);
	Gura_AssignMethod(wx_PropertyGridInterface, HideProperty);
	Gura_AssignMethod(wx_PropertyGridInterface, InitAllTypeHandlers);
	Gura_AssignMethod(wx_PropertyGridInterface, Insert);
	Gura_AssignMethod(wx_PropertyGridInterface, Insert_1);
	Gura_AssignMethod(wx_PropertyGridInterface, IsPropertyCategory);
	Gura_AssignMethod(wx_PropertyGridInterface, IsPropertyEnabled);
	Gura_AssignMethod(wx_PropertyGridInterface, IsPropertyExpanded);
	Gura_AssignMethod(wx_PropertyGridInterface, IsPropertyModified);
	Gura_AssignMethod(wx_PropertyGridInterface, IsPropertySelected);
	Gura_AssignMethod(wx_PropertyGridInterface, IsPropertyShown);
	Gura_AssignMethod(wx_PropertyGridInterface, IsPropertyValueUnspecified);
	Gura_AssignMethod(wx_PropertyGridInterface, LimitPropertyEditing);
	Gura_AssignMethod(wx_PropertyGridInterface, RegisterAdditionalEditors);
	Gura_AssignMethod(wx_PropertyGridInterface, RemoveProperty);
	Gura_AssignMethod(wx_PropertyGridInterface, ReplaceProperty);
}

Gura_ImplementDescendantCreator(wx_PropertyGridInterface)
{
	return new Object_wx_PropertyGridInterface((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
