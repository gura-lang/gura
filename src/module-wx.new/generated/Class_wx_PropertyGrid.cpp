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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__PropertyGrid, "PropertyGrid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PropertyGrid));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PropertyGrid)
{
	//wxPropertyGrid();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__PropertyGrid_1, "PropertyGrid_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PropertyGrid));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PropertyGrid_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxPropertyGrid();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PropertyGrid, __AddActionTrigger, "AddActionTrigger")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "keycode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "modifiers", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __AddActionTrigger)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int action = arg.GetNumber(0)
	//int keycode = arg.GetNumber(1)
	//int modifiers = arg.GetNumber(2)
	//pThis->GetEntity()->AddActionTrigger();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __AddToSelection, "AddToSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __AddToSelection)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->AddToSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __AutoGetTranslation, "AutoGetTranslation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __AutoGetTranslation)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool enable = arg.GetNumber(0)
	//pThis->GetEntity()->AutoGetTranslation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __BeginLabelEdit, "BeginLabelEdit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __BeginLabelEdit)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int colIndex = arg.GetNumber(0)
	//pThis->GetEntity()->BeginLabelEdit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __ChangePropertyValue, "ChangePropertyValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __ChangePropertyValue)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//wxVariant newValue = arg.GetNumber(1)
	//pThis->GetEntity()->ChangePropertyValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __CenterSplitter, "CenterSplitter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enableAutoResizing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __CenterSplitter)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool enableAutoResizing = arg.GetNumber(0)
	//pThis->GetEntity()->CenterSplitter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __Clear)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __ClearActionTriggers, "ClearActionTriggers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __ClearActionTriggers)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int action = arg.GetNumber(0)
	//pThis->GetEntity()->ClearActionTriggers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __CommitChangesFromEditor, "CommitChangesFromEditor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __CommitChangesFromEditor)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint32 flags = arg.GetNumber(0)
	//pThis->GetEntity()->CommitChangesFromEditor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __Create)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __DedicateKey, "DedicateKey")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "keycode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __DedicateKey)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int keycode = arg.GetNumber(0)
	//pThis->GetEntity()->DedicateKey();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __EnableCategories, "EnableCategories")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __EnableCategories)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableCategories();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __EndLabelEdit, "EndLabelEdit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commit", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __EndLabelEdit)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool commit = arg.GetNumber(0)
	//pThis->GetEntity()->EndLabelEdit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __EnsureVisible, "EnsureVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __EnsureVisible)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __FitColumns, "FitColumns")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __FitColumns)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->FitColumns();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetLabelEditor, "GetLabelEditor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetLabelEditor)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLabelEditor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetPanel, "GetPanel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetPanel)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPanel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetCaptionBackgroundColour, "GetCaptionBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetCaptionBackgroundColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaptionBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetCaptionFont, "GetCaptionFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetCaptionFont)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaptionFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetCaptionForegroundColour, "GetCaptionForegroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetCaptionForegroundColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaptionForegroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetCellBackgroundColour, "GetCellBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetCellBackgroundColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCellBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetCellDisabledTextColour, "GetCellDisabledTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetCellDisabledTextColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCellDisabledTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetCellTextColour, "GetCellTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetCellTextColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCellTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetColumnCount, "GetColumnCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetColumnCount)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetEmptySpaceColour, "GetEmptySpaceColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetEmptySpaceColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEmptySpaceColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetFontHeight, "GetFontHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetFontHeight)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFontHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetGrid, "GetGrid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetGrid)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGrid();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetImageRect, "GetImageRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetImageRect)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGProperty* property = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->GetImageRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetImageSize, "GetImageSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetImageSize)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGProperty* property = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->GetImageSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetLastItem, "GetLastItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetLastItem)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->GetLastItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetLineColour, "GetLineColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetLineColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLineColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetMarginColour, "GetMarginColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetMarginColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMarginColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetRoot, "GetRoot")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetRoot)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRoot();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetRowHeight, "GetRowHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetRowHeight)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRowHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetSelectedProperty, "GetSelectedProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetSelectedProperty)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedProperty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetSelection)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetSelectionBackgroundColour, "GetSelectionBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetSelectionBackgroundColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetSelectionForegroundColour, "GetSelectionForegroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetSelectionForegroundColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionForegroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetSortFunction, "GetSortFunction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetSortFunction)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSortFunction();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetSplitterPosition, "GetSplitterPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "splitterIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetSplitterPosition)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int splitterIndex = arg.GetNumber(0)
	//pThis->GetEntity()->GetSplitterPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetEditorTextCtrl, "GetEditorTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetEditorTextCtrl)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEditorTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetUnspecifiedValueAppearance, "GetUnspecifiedValueAppearance")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetUnspecifiedValueAppearance)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUnspecifiedValueAppearance();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetUnspecifiedValueText, "GetUnspecifiedValueText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "argFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetUnspecifiedValueText)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int argFlags = arg.GetNumber(0)
	//pThis->GetEntity()->GetUnspecifiedValueText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetVerticalSpacing, "GetVerticalSpacing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetVerticalSpacing)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVerticalSpacing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __HitTest, "HitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __HitTest)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __IsAnyModified, "IsAnyModified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __IsAnyModified)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAnyModified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __IsEditorFocused, "IsEditorFocused")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __IsEditorFocused)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEditorFocused();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __IsFrozen, "IsFrozen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __IsFrozen)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFrozen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __MakeColumnEditable, "MakeColumnEditable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "editable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __MakeColumnEditable)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int column = arg.GetNumber(0)
	//bool editable = arg.GetNumber(1)
	//pThis->GetEntity()->MakeColumnEditable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __OnTLPChanging, "OnTLPChanging")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newTLP", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __OnTLPChanging)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* newTLP = arg.GetNumber(0)
	//pThis->GetEntity()->OnTLPChanging();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __RefreshEditor, "RefreshEditor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __RefreshEditor)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RefreshEditor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __RefreshProperty, "RefreshProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __RefreshProperty)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGProperty* p = arg.GetNumber(0)
	//pThis->GetEntity()->RefreshProperty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __RegisterEditorClass, "RegisterEditorClass")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noDefCheck", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __RegisterEditorClass)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGEditor* editor = arg.GetNumber(0)
	//bool noDefCheck = arg.GetNumber(1)
	//pThis->GetEntity()->RegisterEditorClass();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __DoRegisterEditorClass, "DoRegisterEditorClass")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noDefCheck", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __DoRegisterEditorClass)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGEditor* editor = arg.GetNumber(0)
	//const wxString& name = arg.GetNumber(1)
	//bool noDefCheck = arg.GetNumber(2)
	//pThis->GetEntity()->DoRegisterEditorClass();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __ResetColours, "ResetColours")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __ResetColours)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ResetColours();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __ResetColumnSizes, "ResetColumnSizes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enableAutoResizing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __ResetColumnSizes)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool enableAutoResizing = arg.GetNumber(0)
	//pThis->GetEntity()->ResetColumnSizes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __RemoveFromSelection, "RemoveFromSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __RemoveFromSelection)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveFromSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SelectProperty, "SelectProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "focus", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SelectProperty)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//bool focus = arg.GetNumber(1)
	//pThis->GetEntity()->SelectProperty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SetCaptionBackgroundColour, "SetCaptionBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SetCaptionBackgroundColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& col = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaptionBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SetCaptionTextColour, "SetCaptionTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SetCaptionTextColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& col = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaptionTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SetCellBackgroundColour, "SetCellBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SetCellBackgroundColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& col = arg.GetNumber(0)
	//pThis->GetEntity()->SetCellBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SetCellDisabledTextColour, "SetCellDisabledTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SetCellDisabledTextColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& col = arg.GetNumber(0)
	//pThis->GetEntity()->SetCellDisabledTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SetCellTextColour, "SetCellTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SetCellTextColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& col = arg.GetNumber(0)
	//pThis->GetEntity()->SetCellTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SetColumnCount, "SetColumnCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SetColumnCount)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colCount = arg.GetNumber(0)
	//pThis->GetEntity()->SetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SetCurrentCategory, "SetCurrentCategory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SetCurrentCategory)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//pThis->GetEntity()->SetCurrentCategory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SetEmptySpaceColour, "SetEmptySpaceColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SetEmptySpaceColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& col = arg.GetNumber(0)
	//pThis->GetEntity()->SetEmptySpaceColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SetLineColour, "SetLineColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SetLineColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& col = arg.GetNumber(0)
	//pThis->GetEntity()->SetLineColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SetMarginColour, "SetMarginColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SetMarginColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& col = arg.GetNumber(0)
	//pThis->GetEntity()->SetMarginColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newSelection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SetSelection)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayPGProperty& newSelection = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SetSelectionBackgroundColour, "SetSelectionBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SetSelectionBackgroundColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& col = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SetSelectionTextColour, "SetSelectionTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SetSelectionTextColour)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& col = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SetSortFunction, "SetSortFunction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sortFunction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SetSortFunction)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGSortCallback sortFunction = arg.GetNumber(0)
	//pThis->GetEntity()->SetSortFunction();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SetSplitterPosition, "SetSplitterPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newxpos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SetSplitterPosition)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int newxpos = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->SetSplitterPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SetSplitterLeft, "SetSplitterLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "privateChildrenToo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SetSplitterLeft)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool privateChildrenToo = arg.GetNumber(0)
	//pThis->GetEntity()->SetSplitterLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SetUnspecifiedValueAppearance, "SetUnspecifiedValueAppearance")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SetUnspecifiedValueAppearance)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPGCell& cell = arg.GetNumber(0)
	//pThis->GetEntity()->SetUnspecifiedValueAppearance();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __SetVerticalSpacing, "SetVerticalSpacing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "vspacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __SetVerticalSpacing)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int vspacing = arg.GetNumber(0)
	//pThis->GetEntity()->SetVerticalSpacing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __DoShowPropertyError, "DoShowPropertyError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __DoShowPropertyError)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGProperty* property = arg.GetNumber(0)
	//const wxString& msg = arg.GetNumber(1)
	//pThis->GetEntity()->DoShowPropertyError();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __DoHidePropertyError, "DoHidePropertyError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __DoHidePropertyError)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGProperty* property = arg.GetNumber(0)
	//pThis->GetEntity()->DoHidePropertyError();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetStatusBar, "GetStatusBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetStatusBar)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStatusBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __EditorsValueWasModified, "EditorsValueWasModified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __EditorsValueWasModified)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EditorsValueWasModified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __EditorsValueWasNotModified, "EditorsValueWasNotModified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __EditorsValueWasNotModified)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EditorsValueWasNotModified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __GetUncommittedPropertyValue, "GetUncommittedPropertyValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __GetUncommittedPropertyValue)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUncommittedPropertyValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __IsEditorsValueModified, "IsEditorsValueModified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __IsEditorsValueModified)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEditorsValueModified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __ShowPropertyError, "ShowPropertyError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGrid, __ShowPropertyError)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//const wxString& msg = arg.GetNumber(1)
	//pThis->GetEntity()->ShowPropertyError();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGrid, __WasValueChangedInEvent, "WasValueChangedInEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGrid, __WasValueChangedInEvent)
{
	Object_wx_PropertyGrid *pThis = Object_wx_PropertyGrid::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WasValueChangedInEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPropertyGrid
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertyGrid)
{
	// Constructor assignment
	Gura_AssignFunction(__PropertyGrid);
	Gura_AssignFunction(__PropertyGrid_1);
	// Method assignment
	Gura_AssignMethod(wx_PropertyGrid, __AddActionTrigger);
	Gura_AssignMethod(wx_PropertyGrid, __AddToSelection);
	Gura_AssignMethod(wx_PropertyGrid, __AutoGetTranslation);
	Gura_AssignMethod(wx_PropertyGrid, __BeginLabelEdit);
	Gura_AssignMethod(wx_PropertyGrid, __ChangePropertyValue);
	Gura_AssignMethod(wx_PropertyGrid, __CenterSplitter);
	Gura_AssignMethod(wx_PropertyGrid, __Clear);
	Gura_AssignMethod(wx_PropertyGrid, __ClearActionTriggers);
	Gura_AssignMethod(wx_PropertyGrid, __CommitChangesFromEditor);
	Gura_AssignMethod(wx_PropertyGrid, __Create);
	Gura_AssignMethod(wx_PropertyGrid, __DedicateKey);
	Gura_AssignMethod(wx_PropertyGrid, __EnableCategories);
	Gura_AssignMethod(wx_PropertyGrid, __EndLabelEdit);
	Gura_AssignMethod(wx_PropertyGrid, __EnsureVisible);
	Gura_AssignMethod(wx_PropertyGrid, __FitColumns);
	Gura_AssignMethod(wx_PropertyGrid, __GetLabelEditor);
	Gura_AssignMethod(wx_PropertyGrid, __GetPanel);
	Gura_AssignMethod(wx_PropertyGrid, __GetCaptionBackgroundColour);
	Gura_AssignMethod(wx_PropertyGrid, __GetCaptionFont);
	Gura_AssignMethod(wx_PropertyGrid, __GetCaptionForegroundColour);
	Gura_AssignMethod(wx_PropertyGrid, __GetCellBackgroundColour);
	Gura_AssignMethod(wx_PropertyGrid, __GetCellDisabledTextColour);
	Gura_AssignMethod(wx_PropertyGrid, __GetCellTextColour);
	Gura_AssignMethod(wx_PropertyGrid, __GetColumnCount);
	Gura_AssignMethod(wx_PropertyGrid, __GetEmptySpaceColour);
	Gura_AssignMethod(wx_PropertyGrid, __GetFontHeight);
	Gura_AssignMethod(wx_PropertyGrid, __GetGrid);
	Gura_AssignMethod(wx_PropertyGrid, __GetImageRect);
	Gura_AssignMethod(wx_PropertyGrid, __GetImageSize);
	Gura_AssignMethod(wx_PropertyGrid, __GetLastItem);
	Gura_AssignMethod(wx_PropertyGrid, __GetLineColour);
	Gura_AssignMethod(wx_PropertyGrid, __GetMarginColour);
	Gura_AssignMethod(wx_PropertyGrid, __GetRoot);
	Gura_AssignMethod(wx_PropertyGrid, __GetRowHeight);
	Gura_AssignMethod(wx_PropertyGrid, __GetSelectedProperty);
	Gura_AssignMethod(wx_PropertyGrid, __GetSelection);
	Gura_AssignMethod(wx_PropertyGrid, __GetSelectionBackgroundColour);
	Gura_AssignMethod(wx_PropertyGrid, __GetSelectionForegroundColour);
	Gura_AssignMethod(wx_PropertyGrid, __GetSortFunction);
	Gura_AssignMethod(wx_PropertyGrid, __GetSplitterPosition);
	Gura_AssignMethod(wx_PropertyGrid, __GetEditorTextCtrl);
	Gura_AssignMethod(wx_PropertyGrid, __GetUnspecifiedValueAppearance);
	Gura_AssignMethod(wx_PropertyGrid, __GetUnspecifiedValueText);
	Gura_AssignMethod(wx_PropertyGrid, __GetVerticalSpacing);
	Gura_AssignMethod(wx_PropertyGrid, __HitTest);
	Gura_AssignMethod(wx_PropertyGrid, __IsAnyModified);
	Gura_AssignMethod(wx_PropertyGrid, __IsEditorFocused);
	Gura_AssignMethod(wx_PropertyGrid, __IsFrozen);
	Gura_AssignMethod(wx_PropertyGrid, __MakeColumnEditable);
	Gura_AssignMethod(wx_PropertyGrid, __OnTLPChanging);
	Gura_AssignMethod(wx_PropertyGrid, __RefreshEditor);
	Gura_AssignMethod(wx_PropertyGrid, __RefreshProperty);
	Gura_AssignMethod(wx_PropertyGrid, __RegisterEditorClass);
	Gura_AssignMethod(wx_PropertyGrid, __DoRegisterEditorClass);
	Gura_AssignMethod(wx_PropertyGrid, __ResetColours);
	Gura_AssignMethod(wx_PropertyGrid, __ResetColumnSizes);
	Gura_AssignMethod(wx_PropertyGrid, __RemoveFromSelection);
	Gura_AssignMethod(wx_PropertyGrid, __SelectProperty);
	Gura_AssignMethod(wx_PropertyGrid, __SetCaptionBackgroundColour);
	Gura_AssignMethod(wx_PropertyGrid, __SetCaptionTextColour);
	Gura_AssignMethod(wx_PropertyGrid, __SetCellBackgroundColour);
	Gura_AssignMethod(wx_PropertyGrid, __SetCellDisabledTextColour);
	Gura_AssignMethod(wx_PropertyGrid, __SetCellTextColour);
	Gura_AssignMethod(wx_PropertyGrid, __SetColumnCount);
	Gura_AssignMethod(wx_PropertyGrid, __SetCurrentCategory);
	Gura_AssignMethod(wx_PropertyGrid, __SetEmptySpaceColour);
	Gura_AssignMethod(wx_PropertyGrid, __SetLineColour);
	Gura_AssignMethod(wx_PropertyGrid, __SetMarginColour);
	Gura_AssignMethod(wx_PropertyGrid, __SetSelection);
	Gura_AssignMethod(wx_PropertyGrid, __SetSelectionBackgroundColour);
	Gura_AssignMethod(wx_PropertyGrid, __SetSelectionTextColour);
	Gura_AssignMethod(wx_PropertyGrid, __SetSortFunction);
	Gura_AssignMethod(wx_PropertyGrid, __SetSplitterPosition);
	Gura_AssignMethod(wx_PropertyGrid, __SetSplitterLeft);
	Gura_AssignMethod(wx_PropertyGrid, __SetUnspecifiedValueAppearance);
	Gura_AssignMethod(wx_PropertyGrid, __SetVerticalSpacing);
	Gura_AssignMethod(wx_PropertyGrid, __DoShowPropertyError);
	Gura_AssignMethod(wx_PropertyGrid, __DoHidePropertyError);
	Gura_AssignMethod(wx_PropertyGrid, __GetStatusBar);
	Gura_AssignMethod(wx_PropertyGrid, __EditorsValueWasModified);
	Gura_AssignMethod(wx_PropertyGrid, __EditorsValueWasNotModified);
	Gura_AssignMethod(wx_PropertyGrid, __GetUncommittedPropertyValue);
	Gura_AssignMethod(wx_PropertyGrid, __IsEditorsValueModified);
	Gura_AssignMethod(wx_PropertyGrid, __ShowPropertyError);
	Gura_AssignMethod(wx_PropertyGrid, __WasValueChangedInEvent);
}

Gura_ImplementDescendantCreator(wx_PropertyGrid)
{
	return new Object_wx_PropertyGrid((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
