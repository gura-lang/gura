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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_TreeListCtrl, wxTreeListCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, wxTreeListCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxTreeListCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, wxTreeListCtrl_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, wxTreeListCtrl_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxTreeListCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_TreeListCtrl, AssignImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, AssignImageList)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int imageList = arg.GetNumber(0)
	//pThis->GetEntity()->AssignImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, SetImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, SetImageList)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int imageList = arg.GetNumber(0)
	//pThis->GetEntity()->SetImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, AppendColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, AppendColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int align = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->AppendColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, GetColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, GetColumnCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, DeleteColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, DeleteColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, ClearColumns)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, ClearColumns)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ClearColumns();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, SetColumnWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, SetColumnWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//pThis->GetEntity()->SetColumnWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, GetColumnWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, GetColumnWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, WidthFor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, WidthFor)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->WidthFor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, AppendItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageClosed", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageOpened", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, AppendItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int imageClosed = arg.GetNumber(2)
	//int imageOpened = arg.GetNumber(3)
	//int data = arg.GetNumber(4)
	//pThis->GetEntity()->AppendItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, InsertItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "previous", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageClosed", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageOpened", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, InsertItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int previous = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int imageClosed = arg.GetNumber(3)
	//int imageOpened = arg.GetNumber(4)
	//int data = arg.GetNumber(5)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, PrependItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageClosed", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageOpened", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, PrependItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int imageClosed = arg.GetNumber(2)
	//int imageOpened = arg.GetNumber(3)
	//int data = arg.GetNumber(4)
	//pThis->GetEntity()->PrependItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, DeleteItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, DeleteItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, DeleteAllItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, DeleteAllItems)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DeleteAllItems();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, GetRootItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, GetRootItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRootItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, GetItemParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, GetItemParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, GetFirstChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, GetFirstChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetFirstChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, GetNextSibling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, GetNextSibling)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetNextSibling();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, GetFirstItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, GetFirstItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFirstItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, GetNextItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, GetNextItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetNextItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, GetItemText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, GetItemText)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetItemText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, SetItemText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, SetItemText)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//pThis->GetEntity()->SetItemText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, SetItemText_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, SetItemText_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, SetItemImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "closed", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "opened", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, SetItemImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int closed = arg.GetNumber(1)
	//int opened = arg.GetNumber(2)
	//pThis->GetEntity()->SetItemImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, GetItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, GetItemData)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, SetItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, SetItemData)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, Expand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, Expand)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Expand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, Collapse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, Collapse)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Collapse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, IsExpanded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, IsExpanded)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsExpanded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, GetSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selections", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, GetSelections)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int selections = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelections();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, Select)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, Select)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Select();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, Unselect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, Unselect)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Unselect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, IsSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, IsSelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsSelected();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, SelectAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, SelectAll)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, UnselectAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, UnselectAll)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UnselectAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, EnsureVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, EnsureVisible)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, CheckItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, CheckItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int state = arg.GetNumber(1)
	//pThis->GetEntity()->CheckItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, CheckItemRecursively)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, CheckItemRecursively)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int state = arg.GetNumber(1)
	//pThis->GetEntity()->CheckItemRecursively();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, UncheckItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, UncheckItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->UncheckItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, UpdateItemParentStateRecursively)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, UpdateItemParentStateRecursively)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->UpdateItemParentStateRecursively();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, GetCheckedState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, GetCheckedState)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetCheckedState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, AreAllChildrenInState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, AreAllChildrenInState)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int state = arg.GetNumber(1)
	//pThis->GetEntity()->AreAllChildrenInState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, SetSortColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ascendingOrder", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, SetSortColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int ascendingOrder = arg.GetNumber(1)
	//pThis->GetEntity()->SetSortColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, GetSortColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ascendingOrder", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, GetSortColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int ascendingOrder = arg.GetNumber(1)
	//pThis->GetEntity()->GetSortColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, SetItemComparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "comparator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListCtrl, SetItemComparator)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int comparator = arg.GetNumber(0)
	//pThis->GetEntity()->SetItemComparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, GetView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, GetView)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListCtrl, GetDataView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListCtrl, GetDataView)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListCtrl *pThis = Object_wx_TreeListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDataView();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTreeListCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeListCtrl)
{
	Gura_AssignMethod(wx_TreeListCtrl, wxTreeListCtrl);
	Gura_AssignMethod(wx_TreeListCtrl, wxTreeListCtrl_1);
	Gura_AssignMethod(wx_TreeListCtrl, Create);
	Gura_AssignMethod(wx_TreeListCtrl, AssignImageList);
	Gura_AssignMethod(wx_TreeListCtrl, SetImageList);
	Gura_AssignMethod(wx_TreeListCtrl, AppendColumn);
	Gura_AssignMethod(wx_TreeListCtrl, GetColumnCount);
	Gura_AssignMethod(wx_TreeListCtrl, DeleteColumn);
	Gura_AssignMethod(wx_TreeListCtrl, ClearColumns);
	Gura_AssignMethod(wx_TreeListCtrl, SetColumnWidth);
	Gura_AssignMethod(wx_TreeListCtrl, GetColumnWidth);
	Gura_AssignMethod(wx_TreeListCtrl, WidthFor);
	Gura_AssignMethod(wx_TreeListCtrl, AppendItem);
	Gura_AssignMethod(wx_TreeListCtrl, InsertItem);
	Gura_AssignMethod(wx_TreeListCtrl, PrependItem);
	Gura_AssignMethod(wx_TreeListCtrl, DeleteItem);
	Gura_AssignMethod(wx_TreeListCtrl, DeleteAllItems);
	Gura_AssignMethod(wx_TreeListCtrl, GetRootItem);
	Gura_AssignMethod(wx_TreeListCtrl, GetItemParent);
	Gura_AssignMethod(wx_TreeListCtrl, GetFirstChild);
	Gura_AssignMethod(wx_TreeListCtrl, GetNextSibling);
	Gura_AssignMethod(wx_TreeListCtrl, GetFirstItem);
	Gura_AssignMethod(wx_TreeListCtrl, GetNextItem);
	Gura_AssignMethod(wx_TreeListCtrl, GetItemText);
	Gura_AssignMethod(wx_TreeListCtrl, SetItemText);
	Gura_AssignMethod(wx_TreeListCtrl, SetItemText_1);
	Gura_AssignMethod(wx_TreeListCtrl, SetItemImage);
	Gura_AssignMethod(wx_TreeListCtrl, GetItemData);
	Gura_AssignMethod(wx_TreeListCtrl, SetItemData);
	Gura_AssignMethod(wx_TreeListCtrl, Expand);
	Gura_AssignMethod(wx_TreeListCtrl, Collapse);
	Gura_AssignMethod(wx_TreeListCtrl, IsExpanded);
	Gura_AssignMethod(wx_TreeListCtrl, GetSelection);
	Gura_AssignMethod(wx_TreeListCtrl, GetSelections);
	Gura_AssignMethod(wx_TreeListCtrl, Select);
	Gura_AssignMethod(wx_TreeListCtrl, Unselect);
	Gura_AssignMethod(wx_TreeListCtrl, IsSelected);
	Gura_AssignMethod(wx_TreeListCtrl, SelectAll);
	Gura_AssignMethod(wx_TreeListCtrl, UnselectAll);
	Gura_AssignMethod(wx_TreeListCtrl, EnsureVisible);
	Gura_AssignMethod(wx_TreeListCtrl, CheckItem);
	Gura_AssignMethod(wx_TreeListCtrl, CheckItemRecursively);
	Gura_AssignMethod(wx_TreeListCtrl, UncheckItem);
	Gura_AssignMethod(wx_TreeListCtrl, UpdateItemParentStateRecursively);
	Gura_AssignMethod(wx_TreeListCtrl, GetCheckedState);
	Gura_AssignMethod(wx_TreeListCtrl, AreAllChildrenInState);
	Gura_AssignMethod(wx_TreeListCtrl, SetSortColumn);
	Gura_AssignMethod(wx_TreeListCtrl, GetSortColumn);
	Gura_AssignMethod(wx_TreeListCtrl, SetItemComparator);
	Gura_AssignMethod(wx_TreeListCtrl, GetView);
	Gura_AssignMethod(wx_TreeListCtrl, GetDataView);
}

Gura_ImplementDescendantCreator(wx_TreeListCtrl)
{
	return new Object_wx_TreeListCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
