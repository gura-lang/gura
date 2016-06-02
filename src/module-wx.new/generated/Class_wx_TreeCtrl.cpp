//----------------------------------------------------------------------------
// wxTreeCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreeCtrl
//----------------------------------------------------------------------------
Object_wx_TreeCtrl::~Object_wx_TreeCtrl()
{
}

Object *Object_wx_TreeCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_TreeCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.TreeCtrl:");
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
Gura_DeclareMethod(wx_TreeCtrl, wxTreeCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, wxTreeCtrl)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxTreeCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, wxTreeCtrl_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, wxTreeCtrl_1)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxTreeCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, AddRoot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selImage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, AddRoot)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int image = arg.GetNumber(1)
	//int selImage = arg.GetNumber(2)
	//int data = arg.GetNumber(3)
	//pThis->GetEntity()->AddRoot();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, AppendItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selImage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, AppendItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int image = arg.GetNumber(2)
	//int selImage = arg.GetNumber(3)
	//int data = arg.GetNumber(4)
	//pThis->GetEntity()->AppendItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, AssignButtonsImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, AssignButtonsImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imageList = arg.GetNumber(0)
	//pThis->GetEntity()->AssignButtonsImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, AssignImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, AssignImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imageList = arg.GetNumber(0)
	//pThis->GetEntity()->AssignImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, AssignStateImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, AssignStateImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imageList = arg.GetNumber(0)
	//pThis->GetEntity()->AssignStateImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, Collapse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, Collapse)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Collapse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, CollapseAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, CollapseAll)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CollapseAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, CollapseAllChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, CollapseAllChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->CollapseAllChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, CollapseAndReset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, CollapseAndReset)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->CollapseAndReset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, Create)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, Delete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, Delete)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Delete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, DeleteAllItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, DeleteAllItems)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteAllItems();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, DeleteChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, DeleteChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, EditLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textCtrlClass", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, EditLabel)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int textCtrlClass = arg.GetNumber(1)
	//pThis->GetEntity()->EditLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, EnableBellOnNoMatch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "on", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, EnableBellOnNoMatch)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int on = arg.GetNumber(0)
	//pThis->GetEntity()->EnableBellOnNoMatch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, EndEditLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "discardChanges", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, EndEditLabel)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int discardChanges = arg.GetNumber(1)
	//pThis->GetEntity()->EndEditLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, EnsureVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, EnsureVisible)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, Expand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, Expand)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Expand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, ExpandAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, ExpandAll)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ExpandAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, ExpandAllChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, ExpandAllChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->ExpandAllChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetBoundingRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textOnly", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, GetBoundingRect)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//int textOnly = arg.GetNumber(2)
	//pThis->GetEntity()->GetBoundingRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetButtonsImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, GetButtonsImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetButtonsImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetChildrenCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursively", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, GetChildrenCount)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int recursively = arg.GetNumber(1)
	//pThis->GetEntity()->GetChildrenCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, GetCount)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetEditControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, GetEditControl)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEditControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetFirstChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, GetFirstChild)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int cookie = arg.GetNumber(1)
	//pThis->GetEntity()->GetFirstChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetFirstVisibleItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, GetFirstVisibleItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFirstVisibleItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetFocusedItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, GetFocusedItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFocusedItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, ClearFocusedItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, ClearFocusedItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearFocusedItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SetFocusedItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetFocusedItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->SetFocusedItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, GetImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, GetIndent)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetItemBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, GetItemBackgroundColour)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, GetItemData)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetItemFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, GetItemFont)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetItemImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, GetItemImage)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int which = arg.GetNumber(1)
	//pThis->GetEntity()->GetItemImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetItemParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, GetItemParent)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetItemState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, GetItemState)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetItemText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, GetItemText)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetItemTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, GetItemTextColour)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetLastChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, GetLastChild)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetLastChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetNextChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, GetNextChild)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int cookie = arg.GetNumber(1)
	//pThis->GetEntity()->GetNextChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetNextSibling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, GetNextSibling)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetNextSibling();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetNextVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, GetNextVisible)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetNextVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetPrevSibling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, GetPrevSibling)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetPrevSibling();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetPrevVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, GetPrevVisible)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetPrevVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetQuickBestSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, GetQuickBestSize)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetQuickBestSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetRootItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, GetRootItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRootItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, GetSelection)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, GetSelections)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelections();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, GetStateImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, GetStateImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStateImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, HitTest)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int point = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, InsertItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "previous", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selImage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, InsertItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int previous = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int image = arg.GetNumber(3)
	//int selImage = arg.GetNumber(4)
	//int data = arg.GetNumber(5)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, InsertItem_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selImage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, InsertItem_1)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int image = arg.GetNumber(3)
	//int selImage = arg.GetNumber(4)
	//int data = arg.GetNumber(5)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, IsBold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, IsBold)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsBold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, IsEmpty)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, IsExpanded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, IsExpanded)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsExpanded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, IsSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, IsSelected)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsSelected();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, IsVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, IsVisible)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, ItemHasChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, ItemHasChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->ItemHasChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, OnCompareItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, OnCompareItems)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item1 = arg.GetNumber(0)
	//int item2 = arg.GetNumber(1)
	//pThis->GetEntity()->OnCompareItems();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, PrependItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selImage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, PrependItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int image = arg.GetNumber(2)
	//int selImage = arg.GetNumber(3)
	//int data = arg.GetNumber(4)
	//pThis->GetEntity()->PrependItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, ScrollTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, ScrollTo)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SelectItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SelectItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int select = arg.GetNumber(1)
	//pThis->GetEntity()->SelectItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SetButtonsImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetButtonsImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imageList = arg.GetNumber(0)
	//pThis->GetEntity()->SetButtonsImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SetImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imageList = arg.GetNumber(0)
	//pThis->GetEntity()->SetImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SetIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetIndent)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indent = arg.GetNumber(0)
	//pThis->GetEntity()->SetIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemBackgroundColour)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemBold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bold", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemBold)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int bold = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemBold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemData)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemDropHighlight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "highlight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemDropHighlight)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int highlight = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemDropHighlight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemFont)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int font = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemHasChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hasChildren", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemHasChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int hasChildren = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemHasChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemImage)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int image = arg.GetNumber(1)
	//int which = arg.GetNumber(2)
	//pThis->GetEntity()->SetItemImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemState)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int state = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemText)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemTextColour)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SetQuickBestSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "quickBestSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetQuickBestSize)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int quickBestSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetQuickBestSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SetStateImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetStateImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imageList = arg.GetNumber(0)
	//pThis->GetEntity()->SetStateImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SetWindowStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styles", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetWindowStyle)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styles = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindowStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SortChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SortChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->SortChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, Toggle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, Toggle)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Toggle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, ToggleItemSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, ToggleItemSelection)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->ToggleItemSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, Unselect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, Unselect)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Unselect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, UnselectAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, UnselectAll)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UnselectAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, UnselectItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, UnselectItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->UnselectItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeCtrl, SelectChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SelectChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->SelectChildren();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTreeCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeCtrl)
{
	Gura_AssignMethod(wx_TreeCtrl, wxTreeCtrl);
	Gura_AssignMethod(wx_TreeCtrl, wxTreeCtrl_1);
	Gura_AssignMethod(wx_TreeCtrl, AddRoot);
	Gura_AssignMethod(wx_TreeCtrl, AppendItem);
	Gura_AssignMethod(wx_TreeCtrl, AssignButtonsImageList);
	Gura_AssignMethod(wx_TreeCtrl, AssignImageList);
	Gura_AssignMethod(wx_TreeCtrl, AssignStateImageList);
	Gura_AssignMethod(wx_TreeCtrl, Collapse);
	Gura_AssignMethod(wx_TreeCtrl, CollapseAll);
	Gura_AssignMethod(wx_TreeCtrl, CollapseAllChildren);
	Gura_AssignMethod(wx_TreeCtrl, CollapseAndReset);
	Gura_AssignMethod(wx_TreeCtrl, Create);
	Gura_AssignMethod(wx_TreeCtrl, Delete);
	Gura_AssignMethod(wx_TreeCtrl, DeleteAllItems);
	Gura_AssignMethod(wx_TreeCtrl, DeleteChildren);
	Gura_AssignMethod(wx_TreeCtrl, EditLabel);
	Gura_AssignMethod(wx_TreeCtrl, EnableBellOnNoMatch);
	Gura_AssignMethod(wx_TreeCtrl, EndEditLabel);
	Gura_AssignMethod(wx_TreeCtrl, EnsureVisible);
	Gura_AssignMethod(wx_TreeCtrl, Expand);
	Gura_AssignMethod(wx_TreeCtrl, ExpandAll);
	Gura_AssignMethod(wx_TreeCtrl, ExpandAllChildren);
	Gura_AssignMethod(wx_TreeCtrl, GetBoundingRect);
	Gura_AssignMethod(wx_TreeCtrl, GetButtonsImageList);
	Gura_AssignMethod(wx_TreeCtrl, GetChildrenCount);
	Gura_AssignMethod(wx_TreeCtrl, GetCount);
	Gura_AssignMethod(wx_TreeCtrl, GetEditControl);
	Gura_AssignMethod(wx_TreeCtrl, GetFirstChild);
	Gura_AssignMethod(wx_TreeCtrl, GetFirstVisibleItem);
	Gura_AssignMethod(wx_TreeCtrl, GetFocusedItem);
	Gura_AssignMethod(wx_TreeCtrl, ClearFocusedItem);
	Gura_AssignMethod(wx_TreeCtrl, SetFocusedItem);
	Gura_AssignMethod(wx_TreeCtrl, GetImageList);
	Gura_AssignMethod(wx_TreeCtrl, GetIndent);
	Gura_AssignMethod(wx_TreeCtrl, GetItemBackgroundColour);
	Gura_AssignMethod(wx_TreeCtrl, GetItemData);
	Gura_AssignMethod(wx_TreeCtrl, GetItemFont);
	Gura_AssignMethod(wx_TreeCtrl, GetItemImage);
	Gura_AssignMethod(wx_TreeCtrl, GetItemParent);
	Gura_AssignMethod(wx_TreeCtrl, GetItemState);
	Gura_AssignMethod(wx_TreeCtrl, GetItemText);
	Gura_AssignMethod(wx_TreeCtrl, GetItemTextColour);
	Gura_AssignMethod(wx_TreeCtrl, GetLastChild);
	Gura_AssignMethod(wx_TreeCtrl, GetNextChild);
	Gura_AssignMethod(wx_TreeCtrl, GetNextSibling);
	Gura_AssignMethod(wx_TreeCtrl, GetNextVisible);
	Gura_AssignMethod(wx_TreeCtrl, GetPrevSibling);
	Gura_AssignMethod(wx_TreeCtrl, GetPrevVisible);
	Gura_AssignMethod(wx_TreeCtrl, GetQuickBestSize);
	Gura_AssignMethod(wx_TreeCtrl, GetRootItem);
	Gura_AssignMethod(wx_TreeCtrl, GetSelection);
	Gura_AssignMethod(wx_TreeCtrl, GetSelections);
	Gura_AssignMethod(wx_TreeCtrl, GetStateImageList);
	Gura_AssignMethod(wx_TreeCtrl, HitTest);
	Gura_AssignMethod(wx_TreeCtrl, InsertItem);
	Gura_AssignMethod(wx_TreeCtrl, InsertItem_1);
	Gura_AssignMethod(wx_TreeCtrl, IsBold);
	Gura_AssignMethod(wx_TreeCtrl, IsEmpty);
	Gura_AssignMethod(wx_TreeCtrl, IsExpanded);
	Gura_AssignMethod(wx_TreeCtrl, IsSelected);
	Gura_AssignMethod(wx_TreeCtrl, IsVisible);
	Gura_AssignMethod(wx_TreeCtrl, ItemHasChildren);
	Gura_AssignMethod(wx_TreeCtrl, OnCompareItems);
	Gura_AssignMethod(wx_TreeCtrl, PrependItem);
	Gura_AssignMethod(wx_TreeCtrl, ScrollTo);
	Gura_AssignMethod(wx_TreeCtrl, SelectItem);
	Gura_AssignMethod(wx_TreeCtrl, SetButtonsImageList);
	Gura_AssignMethod(wx_TreeCtrl, SetImageList);
	Gura_AssignMethod(wx_TreeCtrl, SetIndent);
	Gura_AssignMethod(wx_TreeCtrl, SetItemBackgroundColour);
	Gura_AssignMethod(wx_TreeCtrl, SetItemBold);
	Gura_AssignMethod(wx_TreeCtrl, SetItemData);
	Gura_AssignMethod(wx_TreeCtrl, SetItemDropHighlight);
	Gura_AssignMethod(wx_TreeCtrl, SetItemFont);
	Gura_AssignMethod(wx_TreeCtrl, SetItemHasChildren);
	Gura_AssignMethod(wx_TreeCtrl, SetItemImage);
	Gura_AssignMethod(wx_TreeCtrl, SetItemState);
	Gura_AssignMethod(wx_TreeCtrl, SetItemText);
	Gura_AssignMethod(wx_TreeCtrl, SetItemTextColour);
	Gura_AssignMethod(wx_TreeCtrl, SetQuickBestSize);
	Gura_AssignMethod(wx_TreeCtrl, SetStateImageList);
	Gura_AssignMethod(wx_TreeCtrl, SetWindowStyle);
	Gura_AssignMethod(wx_TreeCtrl, SortChildren);
	Gura_AssignMethod(wx_TreeCtrl, Toggle);
	Gura_AssignMethod(wx_TreeCtrl, ToggleItemSelection);
	Gura_AssignMethod(wx_TreeCtrl, Unselect);
	Gura_AssignMethod(wx_TreeCtrl, UnselectAll);
	Gura_AssignMethod(wx_TreeCtrl, UnselectItem);
	Gura_AssignMethod(wx_TreeCtrl, SelectChildren);
}

Gura_ImplementDescendantCreator(wx_TreeCtrl)
{
	return new Object_wx_TreeCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
