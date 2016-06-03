//----------------------------------------------------------------------------
// wxGridCellEditor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellEditor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellEditor
//----------------------------------------------------------------------------
Object_wx_GridCellEditor::~Object_wx_GridCellEditor()
{
}

Object *Object_wx_GridCellEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellEditor:");
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
Gura_DeclareMethodAlias(wx_GridCellEditor, __wxGridCellEditor, "wxGridCellEditor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, __wxGridCellEditor)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxGridCellEditor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellEditor, __BeginEdit, "BeginEdit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, __BeginEdit)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int grid = arg.GetNumber(2)
	//pThis->GetEntity()->BeginEdit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellEditor, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, __Clone)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellEditor, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "evtHandler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, __Create)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int evtHandler = arg.GetNumber(2)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellEditor, __Destroy, "Destroy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, __Destroy)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Destroy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellEditor, __EndEdit, "EndEdit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "oldval", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newval", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, __EndEdit)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int grid = arg.GetNumber(2)
	//int oldval = arg.GetNumber(3)
	//int newval = arg.GetNumber(4)
	//pThis->GetEntity()->EndEdit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellEditor, __ApplyEdit, "ApplyEdit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, __ApplyEdit)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int grid = arg.GetNumber(2)
	//pThis->GetEntity()->ApplyEdit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellEditor, __HandleReturn, "HandleReturn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, __HandleReturn)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->HandleReturn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellEditor, __IsCreated, "IsCreated")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, __IsCreated)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsCreated();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellEditor, __PaintBackground, "PaintBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rectCell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, __PaintBackground)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int rectCell = arg.GetNumber(1)
	//int attr = arg.GetNumber(2)
	//pThis->GetEntity()->PaintBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellEditor, __Reset, "Reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, __Reset)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellEditor, __SetSize, "SetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, __SetSize)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellEditor, __Show, "Show")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, __Show)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//int attr = arg.GetNumber(1)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellEditor, __StartingClick, "StartingClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, __StartingClick)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StartingClick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellEditor, __StartingKey, "StartingKey")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, __StartingKey)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->StartingKey();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellEditor, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, __GetValue)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellEditor, __GetControl, "GetControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, __GetControl)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellEditor, __SetControl, "SetControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "control", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, __SetControl)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int control = arg.GetNumber(0)
	//pThis->GetEntity()->SetControl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellEditor)
{
	Gura_AssignMethod(wx_GridCellEditor, __wxGridCellEditor);
	Gura_AssignMethod(wx_GridCellEditor, __BeginEdit);
	Gura_AssignMethod(wx_GridCellEditor, __Clone);
	Gura_AssignMethod(wx_GridCellEditor, __Create);
	Gura_AssignMethod(wx_GridCellEditor, __Destroy);
	Gura_AssignMethod(wx_GridCellEditor, __EndEdit);
	Gura_AssignMethod(wx_GridCellEditor, __ApplyEdit);
	Gura_AssignMethod(wx_GridCellEditor, __HandleReturn);
	Gura_AssignMethod(wx_GridCellEditor, __IsCreated);
	Gura_AssignMethod(wx_GridCellEditor, __PaintBackground);
	Gura_AssignMethod(wx_GridCellEditor, __Reset);
	Gura_AssignMethod(wx_GridCellEditor, __SetSize);
	Gura_AssignMethod(wx_GridCellEditor, __Show);
	Gura_AssignMethod(wx_GridCellEditor, __StartingClick);
	Gura_AssignMethod(wx_GridCellEditor, __StartingKey);
	Gura_AssignMethod(wx_GridCellEditor, __GetValue);
	Gura_AssignMethod(wx_GridCellEditor, __GetControl);
	Gura_AssignMethod(wx_GridCellEditor, __SetControl);
}

Gura_ImplementDescendantCreator(wx_GridCellEditor)
{
	return new Object_wx_GridCellEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
