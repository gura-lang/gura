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
Gura_DeclareMethod(wx_GridCellEditor, wxGridCellEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, wxGridCellEditor)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxGridCellEditor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, BeginEdit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, BeginEdit)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int grid = arg.GetNumber(2)
	//pThis->GetEntity()->BeginEdit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "evtHandler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int evtHandler = arg.GetNumber(2)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, Destroy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, Destroy)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Destroy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, EndEdit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "oldval", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newval", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, EndEdit)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int grid = arg.GetNumber(2)
	//int oldval = arg.GetNumber(3)
	//int newval = arg.GetNumber(4)
	//pThis->GetEntity()->EndEdit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, ApplyEdit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, ApplyEdit)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int grid = arg.GetNumber(2)
	//pThis->GetEntity()->ApplyEdit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, HandleReturn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, HandleReturn)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->HandleReturn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, IsCreated)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, IsCreated)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsCreated();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, PaintBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rectCell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, PaintBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int rectCell = arg.GetNumber(1)
	//int attr = arg.GetNumber(2)
	//pThis->GetEntity()->PaintBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, Reset)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, SetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//int attr = arg.GetNumber(1)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, StartingClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, StartingClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->StartingClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, StartingKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, StartingKey)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->StartingKey();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, GetControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, GetControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, SetControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "control", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, SetControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int control = arg.GetNumber(0)
	//pThis->GetEntity()->SetControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, ~wxGridCellEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, ~wxGridCellEditor)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxGridCellEditor();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellEditor)
{
	Gura_AssignMethod(wx_GridCellEditor, wxGridCellEditor);
	Gura_AssignMethod(wx_GridCellEditor, BeginEdit);
	Gura_AssignMethod(wx_GridCellEditor, Clone);
	Gura_AssignMethod(wx_GridCellEditor, Create);
	Gura_AssignMethod(wx_GridCellEditor, Destroy);
	Gura_AssignMethod(wx_GridCellEditor, EndEdit);
	Gura_AssignMethod(wx_GridCellEditor, ApplyEdit);
	Gura_AssignMethod(wx_GridCellEditor, HandleReturn);
	Gura_AssignMethod(wx_GridCellEditor, IsCreated);
	Gura_AssignMethod(wx_GridCellEditor, PaintBackground);
	Gura_AssignMethod(wx_GridCellEditor, Reset);
	Gura_AssignMethod(wx_GridCellEditor, SetSize);
	Gura_AssignMethod(wx_GridCellEditor, Show);
	Gura_AssignMethod(wx_GridCellEditor, StartingClick);
	Gura_AssignMethod(wx_GridCellEditor, StartingKey);
	Gura_AssignMethod(wx_GridCellEditor, GetValue);
	Gura_AssignMethod(wx_GridCellEditor, GetControl);
	Gura_AssignMethod(wx_GridCellEditor, SetControl);
	Gura_AssignMethod(wx_GridCellEditor, ~wxGridCellEditor);
}

Gura_ImplementDescendantCreator(wx_GridCellEditor)
{
	return new Object_wx_GridCellEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
