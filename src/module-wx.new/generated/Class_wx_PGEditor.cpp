//----------------------------------------------------------------------------
// wxPGEditor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPGEditor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPGEditor
//----------------------------------------------------------------------------
Object_wx_PGEditor::~Object_wx_PGEditor()
{
}

Object *Object_wx_PGEditor::Clone() const
{
	return nullptr;
}

String Object_wx_PGEditor::ToString(bool exprFlag)
{
	String rtn("<wx.PGEditor:");
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
Gura_DeclareFunctionAlias(__wxPGEditor, "wxPGEditor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PGEditor));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxPGEditor)
{
	//wxPGEditor();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PGEditor, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGEditor, __GetName)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGEditor, __CreateControls, "CreateControls")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "propgrid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, __CreateControls)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int propgrid = arg.GetNumber(0)
	//int property = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//pThis->GetEntity()->CreateControls();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGEditor, __UpdateControl, "UpdateControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, __UpdateControl)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//int ctrl = arg.GetNumber(1)
	//pThis->GetEntity()->UpdateControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGEditor, __DrawValue, "DrawValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, __DrawValue)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//int property = arg.GetNumber(2)
	//int text = arg.GetNumber(3)
	//pThis->GetEntity()->DrawValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGEditor, __OnEvent, "OnEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "propgrid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd_primary", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, __OnEvent)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int propgrid = arg.GetNumber(0)
	//int property = arg.GetNumber(1)
	//int wnd_primary = arg.GetNumber(2)
	//int event = arg.GetNumber(3)
	//pThis->GetEntity()->OnEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGEditor, __GetValueFromControl, "GetValueFromControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, __GetValueFromControl)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int variant = arg.GetNumber(0)
	//int property = arg.GetNumber(1)
	//int ctrl = arg.GetNumber(2)
	//pThis->GetEntity()->GetValueFromControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGEditor, __SetValueToUnspecified, "SetValueToUnspecified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, __SetValueToUnspecified)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//int ctrl = arg.GetNumber(1)
	//pThis->GetEntity()->SetValueToUnspecified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGEditor, __SetControlAppearance, "SetControlAppearance")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "appearance", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "oldAppearance", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "unspecified", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, __SetControlAppearance)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pg = arg.GetNumber(0)
	//int property = arg.GetNumber(1)
	//int ctrl = arg.GetNumber(2)
	//int appearance = arg.GetNumber(3)
	//int oldAppearance = arg.GetNumber(4)
	//int unspecified = arg.GetNumber(5)
	//pThis->GetEntity()->SetControlAppearance();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGEditor, __SetControlStringValue, "SetControlStringValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "txt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, __SetControlStringValue)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//int ctrl = arg.GetNumber(1)
	//int txt = arg.GetNumber(2)
	//pThis->GetEntity()->SetControlStringValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGEditor, __SetControlIntValue, "SetControlIntValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, __SetControlIntValue)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//int ctrl = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->SetControlIntValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGEditor, __InsertItem, "InsertItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, __InsertItem)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ctrl = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int index = arg.GetNumber(2)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGEditor, __DeleteItem, "DeleteItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, __DeleteItem)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ctrl = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGEditor, __OnFocus, "OnFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, __OnFocus)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//pThis->GetEntity()->OnFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGEditor, __CanContainCustomImage, "CanContainCustomImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGEditor, __CanContainCustomImage)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanContainCustomImage();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPGEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PGEditor)
{
	// Constructor assignment
	Gura_AssignFunction(__wxPGEditor);
	// Method assignment
	Gura_AssignMethod(wx_PGEditor, __GetName);
	Gura_AssignMethod(wx_PGEditor, __CreateControls);
	Gura_AssignMethod(wx_PGEditor, __UpdateControl);
	Gura_AssignMethod(wx_PGEditor, __DrawValue);
	Gura_AssignMethod(wx_PGEditor, __OnEvent);
	Gura_AssignMethod(wx_PGEditor, __GetValueFromControl);
	Gura_AssignMethod(wx_PGEditor, __SetValueToUnspecified);
	Gura_AssignMethod(wx_PGEditor, __SetControlAppearance);
	Gura_AssignMethod(wx_PGEditor, __SetControlStringValue);
	Gura_AssignMethod(wx_PGEditor, __SetControlIntValue);
	Gura_AssignMethod(wx_PGEditor, __InsertItem);
	Gura_AssignMethod(wx_PGEditor, __DeleteItem);
	Gura_AssignMethod(wx_PGEditor, __OnFocus);
	Gura_AssignMethod(wx_PGEditor, __CanContainCustomImage);
}

Gura_ImplementDescendantCreator(wx_PGEditor)
{
	return new Object_wx_PGEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
