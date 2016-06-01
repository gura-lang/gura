//----------------------------------------------------------------------------
// wxPropertyGrid
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropertyGrid
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropertyGrid
//----------------------------------------------------------------------------
Object_wx_PropertyGrid::~Object_wx_PropertyGrid()
{
}

Object *Object_wx_PropertyGrid::Clone() const
{
	return nullptr;
}

String Object_wx_PropertyGrid::ToString(bool exprFlag)
{
	String rtn("<wx.PropertyGrid:");
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
Gura_DeclareMethod(wx_PropertyGrid, wxPropertyGrid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, wxPropertyGrid)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxPropertyGrid();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, wxPropertyGrid_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, wxPropertyGrid_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxPropertyGrid();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, ~wxPropertyGrid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, ~wxPropertyGrid)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxPropertyGrid();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, AddActionTrigger)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "keycode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "modifiers", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, AddActionTrigger)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int action = arg.GetNumber(0)
	//int keycode = arg.GetNumber(1)
	//int modifiers = arg.GetNumber(2)
	//pThis->GetEntity()->AddActionTrigger();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, AddToSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, AddToSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->AddToSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, AutoGetTranslation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, AutoGetTranslation)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->AutoGetTranslation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, BeginLabelEdit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, BeginLabelEdit)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colIndex = arg.GetNumber(0)
	//pThis->GetEntity()->BeginLabelEdit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, ChangePropertyValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, ChangePropertyValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int newValue = arg.GetNumber(1)
	//pThis->GetEntity()->ChangePropertyValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, CenterSplitter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enableAutoResizing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, CenterSplitter)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enableAutoResizing = arg.GetNumber(0)
	//pThis->GetEntity()->CenterSplitter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, ClearActionTriggers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, ClearActionTriggers)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int action = arg.GetNumber(0)
	//pThis->GetEntity()->ClearActionTriggers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, CommitChangesFromEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, CommitChangesFromEditor)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->CommitChangesFromEditor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, DedicateKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "keycode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, DedicateKey)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int keycode = arg.GetNumber(0)
	//pThis->GetEntity()->DedicateKey();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, EnableCategories)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, EnableCategories)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableCategories();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, EndLabelEdit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commit", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, EndLabelEdit)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int commit = arg.GetNumber(0)
	//pThis->GetEntity()->EndLabelEdit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, EnsureVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, EnsureVisible)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, FitColumns)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, FitColumns)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->FitColumns();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetLabelEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetLabelEditor)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLabelEditor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetPanel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetPanel)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPanel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetCaptionBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetCaptionBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCaptionBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetCaptionFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetCaptionFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCaptionFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetCaptionForegroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetCaptionForegroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCaptionForegroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetCellBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetCellBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCellBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetCellDisabledTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetCellDisabledTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCellDisabledTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetCellTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetCellTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCellTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetColumnCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetEmptySpaceColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetEmptySpaceColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEmptySpaceColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetFontHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetFontHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetGrid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetGrid)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetGrid();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetImageRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, GetImageRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->GetImageRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetImageSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, GetImageSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->GetImageSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetLastItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, GetLastItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->GetLastItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetLineColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetLineColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLineColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetMarginColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetMarginColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMarginColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetRoot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetRoot)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRoot();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetRowHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetRowHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRowHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetSelectedProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetSelectedProperty)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetSelectionBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetSelectionBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetSelectionForegroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetSelectionForegroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionForegroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetSortFunction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetSortFunction)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSortFunction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetSplitterPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "splitterIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, GetSplitterPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int splitterIndex = arg.GetNumber(0)
	//pThis->GetEntity()->GetSplitterPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetEditorTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetEditorTextCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEditorTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetUnspecifiedValueAppearance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetUnspecifiedValueAppearance)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetUnspecifiedValueAppearance();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetUnspecifiedValueText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "argFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, GetUnspecifiedValueText)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int argFlags = arg.GetNumber(0)
	//pThis->GetEntity()->GetUnspecifiedValueText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetVerticalSpacing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetVerticalSpacing)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVerticalSpacing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, HitTest)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, IsAnyModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, IsAnyModified)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsAnyModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, IsEditorFocused)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, IsEditorFocused)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEditorFocused();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, IsFrozen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, IsFrozen)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsFrozen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, MakeColumnEditable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "editable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, MakeColumnEditable)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//int editable = arg.GetNumber(1)
	//pThis->GetEntity()->MakeColumnEditable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, OnTLPChanging)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newTLP", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, OnTLPChanging)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int newTLP = arg.GetNumber(0)
	//pThis->GetEntity()->OnTLPChanging();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, RefreshEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, RefreshEditor)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RefreshEditor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, RefreshProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, RefreshProperty)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->RefreshProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, RegisterEditorClass)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noDefCheck", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, RegisterEditorClass)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int editor = arg.GetNumber(0)
	//int noDefCheck = arg.GetNumber(1)
	//pThis->GetEntity()->RegisterEditorClass();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, DoRegisterEditorClass)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noDefCheck", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, DoRegisterEditorClass)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int editor = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//int noDefCheck = arg.GetNumber(2)
	//pThis->GetEntity()->DoRegisterEditorClass();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, ResetColours)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, ResetColours)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ResetColours();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, ResetColumnSizes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enableAutoResizing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, ResetColumnSizes)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enableAutoResizing = arg.GetNumber(0)
	//pThis->GetEntity()->ResetColumnSizes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, RemoveFromSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, RemoveFromSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveFromSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SelectProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "focus", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SelectProperty)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int focus = arg.GetNumber(1)
	//pThis->GetEntity()->SelectProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SetCaptionBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SetCaptionBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaptionBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SetCaptionTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SetCaptionTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaptionTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SetCellBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SetCellBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetCellBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SetCellDisabledTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SetCellDisabledTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetCellDisabledTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SetCellTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SetCellTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetCellTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SetColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SetColumnCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colCount = arg.GetNumber(0)
	//pThis->GetEntity()->SetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SetCurrentCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SetCurrentCategory)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetCurrentCategory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SetEmptySpaceColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SetEmptySpaceColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetEmptySpaceColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SetLineColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SetLineColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetLineColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SetMarginColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SetMarginColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetMarginColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newSelection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int newSelection = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SetSelectionBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SetSelectionBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SetSelectionTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SetSelectionTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SetSortFunction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sortFunction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SetSortFunction)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sortFunction = arg.GetNumber(0)
	//pThis->GetEntity()->SetSortFunction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SetSplitterPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newxpos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SetSplitterPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int newxpos = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->SetSplitterPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SetSplitterLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "privateChildrenToo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SetSplitterLeft)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int privateChildrenToo = arg.GetNumber(0)
	//pThis->GetEntity()->SetSplitterLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SetUnspecifiedValueAppearance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SetUnspecifiedValueAppearance)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cell = arg.GetNumber(0)
	//pThis->GetEntity()->SetUnspecifiedValueAppearance();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, SetVerticalSpacing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "vspacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, SetVerticalSpacing)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int vspacing = arg.GetNumber(0)
	//pThis->GetEntity()->SetVerticalSpacing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, DoShowPropertyError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, DoShowPropertyError)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//int msg = arg.GetNumber(1)
	//pThis->GetEntity()->DoShowPropertyError();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, DoHidePropertyError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, DoHidePropertyError)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//pThis->GetEntity()->DoHidePropertyError();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetStatusBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetStatusBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStatusBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, EditorsValueWasModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, EditorsValueWasModified)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EditorsValueWasModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, EditorsValueWasNotModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, EditorsValueWasNotModified)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EditorsValueWasNotModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, GetUncommittedPropertyValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, GetUncommittedPropertyValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetUncommittedPropertyValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, IsEditorsValueModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, IsEditorsValueModified)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEditorsValueModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, ShowPropertyError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, ShowPropertyError)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int msg = arg.GetNumber(1)
	//pThis->GetEntity()->ShowPropertyError();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGrid, WasValueChangedInEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, WasValueChangedInEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->WasValueChangedInEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPropertyGrid
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertyGrid)
{
	Gura_AssignMethod(wx_PropertyGrid, wxPropertyGrid);
	Gura_AssignMethod(wx_PropertyGrid, wxPropertyGrid_1);
	Gura_AssignMethod(wx_PropertyGrid, ~wxPropertyGrid);
	Gura_AssignMethod(wx_PropertyGrid, AddActionTrigger);
	Gura_AssignMethod(wx_PropertyGrid, AddToSelection);
	Gura_AssignMethod(wx_PropertyGrid, AutoGetTranslation);
	Gura_AssignMethod(wx_PropertyGrid, BeginLabelEdit);
	Gura_AssignMethod(wx_PropertyGrid, ChangePropertyValue);
	Gura_AssignMethod(wx_PropertyGrid, CenterSplitter);
	Gura_AssignMethod(wx_PropertyGrid, Clear);
	Gura_AssignMethod(wx_PropertyGrid, ClearActionTriggers);
	Gura_AssignMethod(wx_PropertyGrid, CommitChangesFromEditor);
	Gura_AssignMethod(wx_PropertyGrid, Create);
	Gura_AssignMethod(wx_PropertyGrid, DedicateKey);
	Gura_AssignMethod(wx_PropertyGrid, EnableCategories);
	Gura_AssignMethod(wx_PropertyGrid, EndLabelEdit);
	Gura_AssignMethod(wx_PropertyGrid, EnsureVisible);
	Gura_AssignMethod(wx_PropertyGrid, FitColumns);
	Gura_AssignMethod(wx_PropertyGrid, GetLabelEditor);
	Gura_AssignMethod(wx_PropertyGrid, GetPanel);
	Gura_AssignMethod(wx_PropertyGrid, GetCaptionBackgroundColour);
	Gura_AssignMethod(wx_PropertyGrid, GetCaptionFont);
	Gura_AssignMethod(wx_PropertyGrid, GetCaptionForegroundColour);
	Gura_AssignMethod(wx_PropertyGrid, GetCellBackgroundColour);
	Gura_AssignMethod(wx_PropertyGrid, GetCellDisabledTextColour);
	Gura_AssignMethod(wx_PropertyGrid, GetCellTextColour);
	Gura_AssignMethod(wx_PropertyGrid, GetColumnCount);
	Gura_AssignMethod(wx_PropertyGrid, GetEmptySpaceColour);
	Gura_AssignMethod(wx_PropertyGrid, GetFontHeight);
	Gura_AssignMethod(wx_PropertyGrid, GetGrid);
	Gura_AssignMethod(wx_PropertyGrid, GetImageRect);
	Gura_AssignMethod(wx_PropertyGrid, GetImageSize);
	Gura_AssignMethod(wx_PropertyGrid, GetLastItem);
	Gura_AssignMethod(wx_PropertyGrid, GetLineColour);
	Gura_AssignMethod(wx_PropertyGrid, GetMarginColour);
	Gura_AssignMethod(wx_PropertyGrid, GetRoot);
	Gura_AssignMethod(wx_PropertyGrid, GetRowHeight);
	Gura_AssignMethod(wx_PropertyGrid, GetSelectedProperty);
	Gura_AssignMethod(wx_PropertyGrid, GetSelection);
	Gura_AssignMethod(wx_PropertyGrid, GetSelectionBackgroundColour);
	Gura_AssignMethod(wx_PropertyGrid, GetSelectionForegroundColour);
	Gura_AssignMethod(wx_PropertyGrid, GetSortFunction);
	Gura_AssignMethod(wx_PropertyGrid, GetSplitterPosition);
	Gura_AssignMethod(wx_PropertyGrid, GetEditorTextCtrl);
	Gura_AssignMethod(wx_PropertyGrid, GetUnspecifiedValueAppearance);
	Gura_AssignMethod(wx_PropertyGrid, GetUnspecifiedValueText);
	Gura_AssignMethod(wx_PropertyGrid, GetVerticalSpacing);
	Gura_AssignMethod(wx_PropertyGrid, HitTest);
	Gura_AssignMethod(wx_PropertyGrid, IsAnyModified);
	Gura_AssignMethod(wx_PropertyGrid, IsEditorFocused);
	Gura_AssignMethod(wx_PropertyGrid, IsFrozen);
	Gura_AssignMethod(wx_PropertyGrid, MakeColumnEditable);
	Gura_AssignMethod(wx_PropertyGrid, OnTLPChanging);
	Gura_AssignMethod(wx_PropertyGrid, RefreshEditor);
	Gura_AssignMethod(wx_PropertyGrid, RefreshProperty);
	Gura_AssignMethod(wx_PropertyGrid, RegisterEditorClass);
	Gura_AssignMethod(wx_PropertyGrid, DoRegisterEditorClass);
	Gura_AssignMethod(wx_PropertyGrid, ResetColours);
	Gura_AssignMethod(wx_PropertyGrid, ResetColumnSizes);
	Gura_AssignMethod(wx_PropertyGrid, RemoveFromSelection);
	Gura_AssignMethod(wx_PropertyGrid, SelectProperty);
	Gura_AssignMethod(wx_PropertyGrid, SetCaptionBackgroundColour);
	Gura_AssignMethod(wx_PropertyGrid, SetCaptionTextColour);
	Gura_AssignMethod(wx_PropertyGrid, SetCellBackgroundColour);
	Gura_AssignMethod(wx_PropertyGrid, SetCellDisabledTextColour);
	Gura_AssignMethod(wx_PropertyGrid, SetCellTextColour);
	Gura_AssignMethod(wx_PropertyGrid, SetColumnCount);
	Gura_AssignMethod(wx_PropertyGrid, SetCurrentCategory);
	Gura_AssignMethod(wx_PropertyGrid, SetEmptySpaceColour);
	Gura_AssignMethod(wx_PropertyGrid, SetLineColour);
	Gura_AssignMethod(wx_PropertyGrid, SetMarginColour);
	Gura_AssignMethod(wx_PropertyGrid, SetSelection);
	Gura_AssignMethod(wx_PropertyGrid, SetSelectionBackgroundColour);
	Gura_AssignMethod(wx_PropertyGrid, SetSelectionTextColour);
	Gura_AssignMethod(wx_PropertyGrid, SetSortFunction);
	Gura_AssignMethod(wx_PropertyGrid, SetSplitterPosition);
	Gura_AssignMethod(wx_PropertyGrid, SetSplitterLeft);
	Gura_AssignMethod(wx_PropertyGrid, SetUnspecifiedValueAppearance);
	Gura_AssignMethod(wx_PropertyGrid, SetVerticalSpacing);
	Gura_AssignMethod(wx_PropertyGrid, DoShowPropertyError);
	Gura_AssignMethod(wx_PropertyGrid, DoHidePropertyError);
	Gura_AssignMethod(wx_PropertyGrid, GetStatusBar);
	Gura_AssignMethod(wx_PropertyGrid, EditorsValueWasModified);
	Gura_AssignMethod(wx_PropertyGrid, EditorsValueWasNotModified);
	Gura_AssignMethod(wx_PropertyGrid, GetUncommittedPropertyValue);
	Gura_AssignMethod(wx_PropertyGrid, IsEditorsValueModified);
	Gura_AssignMethod(wx_PropertyGrid, ShowPropertyError);
	Gura_AssignMethod(wx_PropertyGrid, WasValueChangedInEvent);
}

Gura_ImplementDescendantCreator(wx_PropertyGrid)
{
	return new Object_wx_PropertyGrid((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
