//----------------------------------------------------------------------------
// wxTreeListCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeListCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreeListCtrl
//----------------------------------------------------------------------------
Object_wx_TreeListCtrl::~Object_wx_TreeListCtrl()
{
}

Object *Object_wx_TreeListCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_TreeListCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.TreeListCtrl:");
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
Gura_DeclareFunctionAlias(__TreeListCtrl, "TreeListCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TreeListCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TreeListCtrl)
{
	//wxTreeListCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__TreeListCtrl_1, "TreeListCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TreeListCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TreeListCtrl_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxTreeListCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TreeListCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __Create)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_TreeListCtrl, __AssignImageList, "AssignImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __AssignImageList)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxImageList* imageList = arg.GetNumber(0)
	//pThis->GetEntity()->AssignImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __SetImageList, "SetImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __SetImageList)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxImageList* imageList = arg.GetNumber(0)
	//pThis->GetEntity()->SetImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __AppendColumn, "AppendColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __AppendColumn)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& title = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//wxAlignment align = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->AppendColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __GetColumnCount, "GetColumnCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, __GetColumnCount)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __DeleteColumn, "DeleteColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __DeleteColumn)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned col = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __ClearColumns, "ClearColumns")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, __ClearColumns)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearColumns();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __SetColumnWidth, "SetColumnWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __SetColumnWidth)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned col = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//pThis->GetEntity()->SetColumnWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __GetColumnWidth, "GetColumnWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __GetColumnWidth)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned col = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __WidthFor, "WidthFor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __WidthFor)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->WidthFor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __AppendItem, "AppendItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageClosed", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageOpened", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __AppendItem)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem parent = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//int imageClosed = arg.GetNumber(2)
	//int imageOpened = arg.GetNumber(3)
	//wxClientData* data = arg.GetNumber(4)
	//pThis->GetEntity()->AppendItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __InsertItem, "InsertItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "previous", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageClosed", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageOpened", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __InsertItem)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem parent = arg.GetNumber(0)
	//wxTreeListItem previous = arg.GetNumber(1)
	//const wxString& text = arg.GetNumber(2)
	//int imageClosed = arg.GetNumber(3)
	//int imageOpened = arg.GetNumber(4)
	//wxClientData* data = arg.GetNumber(5)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __PrependItem, "PrependItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageClosed", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageOpened", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __PrependItem)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem parent = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//int imageClosed = arg.GetNumber(2)
	//int imageOpened = arg.GetNumber(3)
	//wxClientData* data = arg.GetNumber(4)
	//pThis->GetEntity()->PrependItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __DeleteItem, "DeleteItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __DeleteItem)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __DeleteAllItems, "DeleteAllItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, __DeleteAllItems)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteAllItems();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __GetRootItem, "GetRootItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, __GetRootItem)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRootItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __GetItemParent, "GetItemParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __GetItemParent)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __GetFirstChild, "GetFirstChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __GetFirstChild)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//pThis->GetEntity()->GetFirstChild();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __GetNextSibling, "GetNextSibling")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __GetNextSibling)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//pThis->GetEntity()->GetNextSibling();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __GetFirstItem, "GetFirstItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, __GetFirstItem)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFirstItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __GetNextItem, "GetNextItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __GetNextItem)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//pThis->GetEntity()->GetNextItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __GetItemText, "GetItemText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __GetItemText)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//unsigned col = arg.GetNumber(1)
	//pThis->GetEntity()->GetItemText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __SetItemText, "SetItemText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __SetItemText)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//unsigned col = arg.GetNumber(1)
	//const wxString& text = arg.GetNumber(2)
	//pThis->GetEntity()->SetItemText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __SetItemText_1, "SetItemText_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __SetItemText_1)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __SetItemImage, "SetItemImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "closed", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "opened", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __SetItemImage)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//int closed = arg.GetNumber(1)
	//int opened = arg.GetNumber(2)
	//pThis->GetEntity()->SetItemImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __GetItemData, "GetItemData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __GetItemData)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __SetItemData, "SetItemData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __SetItemData)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//wxClientData* data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __Expand, "Expand")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __Expand)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//pThis->GetEntity()->Expand();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __Collapse, "Collapse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __Collapse)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//pThis->GetEntity()->Collapse();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __IsExpanded, "IsExpanded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __IsExpanded)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//pThis->GetEntity()->IsExpanded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, __GetSelection)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __GetSelections, "GetSelections")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selections", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __GetSelections)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItems& selections = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelections();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __Select, "Select")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __Select)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//pThis->GetEntity()->Select();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __Unselect, "Unselect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __Unselect)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//pThis->GetEntity()->Unselect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __IsSelected, "IsSelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __IsSelected)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//pThis->GetEntity()->IsSelected();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __SelectAll, "SelectAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, __SelectAll)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __UnselectAll, "UnselectAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, __UnselectAll)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UnselectAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __EnsureVisible, "EnsureVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __EnsureVisible)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __CheckItem, "CheckItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __CheckItem)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//wxCheckBoxState state = arg.GetNumber(1)
	//pThis->GetEntity()->CheckItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __CheckItemRecursively, "CheckItemRecursively")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __CheckItemRecursively)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//wxCheckBoxState state = arg.GetNumber(1)
	//pThis->GetEntity()->CheckItemRecursively();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __UncheckItem, "UncheckItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __UncheckItem)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//pThis->GetEntity()->UncheckItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __UpdateItemParentStateRecursively, "UpdateItemParentStateRecursively")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __UpdateItemParentStateRecursively)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//pThis->GetEntity()->UpdateItemParentStateRecursively();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __GetCheckedState, "GetCheckedState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __GetCheckedState)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//pThis->GetEntity()->GetCheckedState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __AreAllChildrenInState, "AreAllChildrenInState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __AreAllChildrenInState)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItem item = arg.GetNumber(0)
	//wxCheckBoxState state = arg.GetNumber(1)
	//pThis->GetEntity()->AreAllChildrenInState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __SetSortColumn, "SetSortColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ascendingOrder", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __SetSortColumn)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned col = arg.GetNumber(0)
	//bool ascendingOrder = arg.GetNumber(1)
	//pThis->GetEntity()->SetSortColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __GetSortColumn, "GetSortColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ascendingOrder", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __GetSortColumn)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned* col = arg.GetNumber(0)
	//bool* ascendingOrder = arg.GetNumber(1)
	//pThis->GetEntity()->GetSortColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __SetItemComparator, "SetItemComparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "comparator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, __SetItemComparator)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeListItemComparator* comparator = arg.GetNumber(0)
	//pThis->GetEntity()->SetItemComparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __GetView, "GetView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, __GetView)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetView();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListCtrl, __GetDataView, "GetDataView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, __GetDataView)
{
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDataView();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTreeListCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeListCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__TreeListCtrl);
	Gura_AssignFunction(__TreeListCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_TreeListCtrl, __Create);
	Gura_AssignMethod(wx_TreeListCtrl, __AssignImageList);
	Gura_AssignMethod(wx_TreeListCtrl, __SetImageList);
	Gura_AssignMethod(wx_TreeListCtrl, __AppendColumn);
	Gura_AssignMethod(wx_TreeListCtrl, __GetColumnCount);
	Gura_AssignMethod(wx_TreeListCtrl, __DeleteColumn);
	Gura_AssignMethod(wx_TreeListCtrl, __ClearColumns);
	Gura_AssignMethod(wx_TreeListCtrl, __SetColumnWidth);
	Gura_AssignMethod(wx_TreeListCtrl, __GetColumnWidth);
	Gura_AssignMethod(wx_TreeListCtrl, __WidthFor);
	Gura_AssignMethod(wx_TreeListCtrl, __AppendItem);
	Gura_AssignMethod(wx_TreeListCtrl, __InsertItem);
	Gura_AssignMethod(wx_TreeListCtrl, __PrependItem);
	Gura_AssignMethod(wx_TreeListCtrl, __DeleteItem);
	Gura_AssignMethod(wx_TreeListCtrl, __DeleteAllItems);
	Gura_AssignMethod(wx_TreeListCtrl, __GetRootItem);
	Gura_AssignMethod(wx_TreeListCtrl, __GetItemParent);
	Gura_AssignMethod(wx_TreeListCtrl, __GetFirstChild);
	Gura_AssignMethod(wx_TreeListCtrl, __GetNextSibling);
	Gura_AssignMethod(wx_TreeListCtrl, __GetFirstItem);
	Gura_AssignMethod(wx_TreeListCtrl, __GetNextItem);
	Gura_AssignMethod(wx_TreeListCtrl, __GetItemText);
	Gura_AssignMethod(wx_TreeListCtrl, __SetItemText);
	Gura_AssignMethod(wx_TreeListCtrl, __SetItemText_1);
	Gura_AssignMethod(wx_TreeListCtrl, __SetItemImage);
	Gura_AssignMethod(wx_TreeListCtrl, __GetItemData);
	Gura_AssignMethod(wx_TreeListCtrl, __SetItemData);
	Gura_AssignMethod(wx_TreeListCtrl, __Expand);
	Gura_AssignMethod(wx_TreeListCtrl, __Collapse);
	Gura_AssignMethod(wx_TreeListCtrl, __IsExpanded);
	Gura_AssignMethod(wx_TreeListCtrl, __GetSelection);
	Gura_AssignMethod(wx_TreeListCtrl, __GetSelections);
	Gura_AssignMethod(wx_TreeListCtrl, __Select);
	Gura_AssignMethod(wx_TreeListCtrl, __Unselect);
	Gura_AssignMethod(wx_TreeListCtrl, __IsSelected);
	Gura_AssignMethod(wx_TreeListCtrl, __SelectAll);
	Gura_AssignMethod(wx_TreeListCtrl, __UnselectAll);
	Gura_AssignMethod(wx_TreeListCtrl, __EnsureVisible);
	Gura_AssignMethod(wx_TreeListCtrl, __CheckItem);
	Gura_AssignMethod(wx_TreeListCtrl, __CheckItemRecursively);
	Gura_AssignMethod(wx_TreeListCtrl, __UncheckItem);
	Gura_AssignMethod(wx_TreeListCtrl, __UpdateItemParentStateRecursively);
	Gura_AssignMethod(wx_TreeListCtrl, __GetCheckedState);
	Gura_AssignMethod(wx_TreeListCtrl, __AreAllChildrenInState);
	Gura_AssignMethod(wx_TreeListCtrl, __SetSortColumn);
	Gura_AssignMethod(wx_TreeListCtrl, __GetSortColumn);
	Gura_AssignMethod(wx_TreeListCtrl, __SetItemComparator);
	Gura_AssignMethod(wx_TreeListCtrl, __GetView);
	Gura_AssignMethod(wx_TreeListCtrl, __GetDataView);
}

Gura_ImplementDescendantCreator(wx_TreeListCtrl)
{
	return new Object_wx_TreeListCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
