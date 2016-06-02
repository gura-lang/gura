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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_PGEditor, wxPGEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGEditor, wxPGEditor)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxPGEditor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGEditor, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGEditor, GetName)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGEditor, CreateControls)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "propgrid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, CreateControls)
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

Gura_DeclareMethod(wx_PGEditor, UpdateControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, UpdateControl)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//int ctrl = arg.GetNumber(1)
	//pThis->GetEntity()->UpdateControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGEditor, DrawValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, DrawValue)
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

Gura_DeclareMethod(wx_PGEditor, OnEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "propgrid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd_primary", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, OnEvent)
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

Gura_DeclareMethod(wx_PGEditor, GetValueFromControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, GetValueFromControl)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int variant = arg.GetNumber(0)
	//int property = arg.GetNumber(1)
	//int ctrl = arg.GetNumber(2)
	//pThis->GetEntity()->GetValueFromControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGEditor, SetValueToUnspecified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, SetValueToUnspecified)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//int ctrl = arg.GetNumber(1)
	//pThis->GetEntity()->SetValueToUnspecified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGEditor, SetControlAppearance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "appearance", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "oldAppearance", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "unspecified", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, SetControlAppearance)
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

Gura_DeclareMethod(wx_PGEditor, SetControlStringValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "txt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, SetControlStringValue)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//int ctrl = arg.GetNumber(1)
	//int txt = arg.GetNumber(2)
	//pThis->GetEntity()->SetControlStringValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGEditor, SetControlIntValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, SetControlIntValue)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//int ctrl = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->SetControlIntValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGEditor, InsertItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, InsertItem)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ctrl = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int index = arg.GetNumber(2)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGEditor, DeleteItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, DeleteItem)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ctrl = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGEditor, OnFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGEditor, OnFocus)
{
	Object_wx_PGEditor *pThis = Object_wx_PGEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//pThis->GetEntity()->OnFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGEditor, CanContainCustomImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGEditor, CanContainCustomImage)
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
	Gura_AssignMethod(wx_PGEditor, wxPGEditor);
	Gura_AssignMethod(wx_PGEditor, GetName);
	Gura_AssignMethod(wx_PGEditor, CreateControls);
	Gura_AssignMethod(wx_PGEditor, UpdateControl);
	Gura_AssignMethod(wx_PGEditor, DrawValue);
	Gura_AssignMethod(wx_PGEditor, OnEvent);
	Gura_AssignMethod(wx_PGEditor, GetValueFromControl);
	Gura_AssignMethod(wx_PGEditor, SetValueToUnspecified);
	Gura_AssignMethod(wx_PGEditor, SetControlAppearance);
	Gura_AssignMethod(wx_PGEditor, SetControlStringValue);
	Gura_AssignMethod(wx_PGEditor, SetControlIntValue);
	Gura_AssignMethod(wx_PGEditor, InsertItem);
	Gura_AssignMethod(wx_PGEditor, DeleteItem);
	Gura_AssignMethod(wx_PGEditor, OnFocus);
	Gura_AssignMethod(wx_PGEditor, CanContainCustomImage);
}

Gura_ImplementDescendantCreator(wx_PGEditor)
{
	return new Object_wx_PGEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
