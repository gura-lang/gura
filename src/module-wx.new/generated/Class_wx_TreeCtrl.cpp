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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__TreeCtrl, "TreeCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TreeCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TreeCtrl)
{
	//wxTreeCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__TreeCtrl_1, "TreeCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TreeCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TreeCtrl_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxValidator& validator = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//wxTreeCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TreeCtrl, __AddRoot, "AddRoot")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selImage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __AddRoot)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//int image = arg.GetNumber(1)
	//int selImage = arg.GetNumber(2)
	//wxTreeItemData* data = arg.GetNumber(3)
	//pThis->GetEntity()->AddRoot();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __AppendItem, "AppendItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selImage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __AppendItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& parent = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//int image = arg.GetNumber(2)
	//int selImage = arg.GetNumber(3)
	//wxTreeItemData* data = arg.GetNumber(4)
	//pThis->GetEntity()->AppendItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __AssignButtonsImageList, "AssignButtonsImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __AssignButtonsImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxImageList* imageList = arg.GetNumber(0)
	//pThis->GetEntity()->AssignButtonsImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __AssignImageList, "AssignImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __AssignImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxImageList* imageList = arg.GetNumber(0)
	//pThis->GetEntity()->AssignImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __AssignStateImageList, "AssignStateImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __AssignStateImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxImageList* imageList = arg.GetNumber(0)
	//pThis->GetEntity()->AssignStateImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __Collapse, "Collapse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __Collapse)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->Collapse();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __CollapseAll, "CollapseAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __CollapseAll)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CollapseAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __CollapseAllChildren, "CollapseAllChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __CollapseAllChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->CollapseAllChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __CollapseAndReset, "CollapseAndReset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __CollapseAndReset)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->CollapseAndReset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __Create, "Create")
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

Gura_ImplementMethod(wx_TreeCtrl, __Create)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxValidator& validator = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __Delete, "Delete")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __Delete)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->Delete();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __DeleteAllItems, "DeleteAllItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __DeleteAllItems)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteAllItems();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __DeleteChildren, "DeleteChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __DeleteChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __EditLabel, "EditLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textCtrlClass", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __EditLabel)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxClassInfo* textCtrlClass = arg.GetNumber(1)
	//pThis->GetEntity()->EditLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __EnableBellOnNoMatch, "EnableBellOnNoMatch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "on", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __EnableBellOnNoMatch)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool on = arg.GetNumber(0)
	//pThis->GetEntity()->EnableBellOnNoMatch();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __EndEditLabel, "EndEditLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "discardChanges", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __EndEditLabel)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//bool discardChanges = arg.GetNumber(1)
	//pThis->GetEntity()->EndEditLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __EnsureVisible, "EnsureVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __EnsureVisible)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __Expand, "Expand")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __Expand)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->Expand();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __ExpandAll, "ExpandAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __ExpandAll)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ExpandAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __ExpandAllChildren, "ExpandAllChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __ExpandAllChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->ExpandAllChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetBoundingRect, "GetBoundingRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textOnly", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetBoundingRect)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxRect& rect = arg.GetNumber(1)
	//bool textOnly = arg.GetNumber(2)
	//pThis->GetEntity()->GetBoundingRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetButtonsImageList, "GetButtonsImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetButtonsImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetButtonsImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetChildrenCount, "GetChildrenCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursively", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetChildrenCount)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//bool recursively = arg.GetNumber(1)
	//pThis->GetEntity()->GetChildrenCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetCount)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetEditControl, "GetEditControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetEditControl)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEditControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetFirstChild, "GetFirstChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetFirstChild)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxTreeItemIdValue& cookie = arg.GetNumber(1)
	//pThis->GetEntity()->GetFirstChild();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetFirstVisibleItem, "GetFirstVisibleItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetFirstVisibleItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFirstVisibleItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetFocusedItem, "GetFocusedItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetFocusedItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFocusedItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __ClearFocusedItem, "ClearFocusedItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __ClearFocusedItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearFocusedItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SetFocusedItem, "SetFocusedItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SetFocusedItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->SetFocusedItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetImageList, "GetImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetIndent, "GetIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetIndent)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetItemBackgroundColour, "GetItemBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetItemBackgroundColour)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetItemData, "GetItemData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetItemData)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetItemFont, "GetItemFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetItemFont)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetItemImage, "GetItemImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetItemImage)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxTreeItemIcon which = arg.GetNumber(1)
	//pThis->GetEntity()->GetItemImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetItemParent, "GetItemParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetItemParent)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetItemState, "GetItemState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetItemState)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetItemText, "GetItemText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetItemText)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetItemTextColour, "GetItemTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetItemTextColour)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetLastChild, "GetLastChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetLastChild)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->GetLastChild();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetNextChild, "GetNextChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetNextChild)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxTreeItemIdValue& cookie = arg.GetNumber(1)
	//pThis->GetEntity()->GetNextChild();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetNextSibling, "GetNextSibling")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetNextSibling)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->GetNextSibling();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetNextVisible, "GetNextVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetNextVisible)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->GetNextVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetPrevSibling, "GetPrevSibling")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetPrevSibling)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->GetPrevSibling();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetPrevVisible, "GetPrevVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetPrevVisible)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->GetPrevVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetQuickBestSize, "GetQuickBestSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetQuickBestSize)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetQuickBestSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetRootItem, "GetRootItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetRootItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRootItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetSelection)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetSelections, "GetSelections")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetSelections)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArrayTreeItemIds& selection = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelections();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetStateImageList, "GetStateImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetStateImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStateImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __HitTest, "HitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __HitTest)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& point = arg.GetNumber(0)
	//int& flags = arg.GetNumber(1)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __InsertItem, "InsertItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "previous", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selImage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __InsertItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& parent = arg.GetNumber(0)
	//const wxTreeItemId& previous = arg.GetNumber(1)
	//const wxString& text = arg.GetNumber(2)
	//int image = arg.GetNumber(3)
	//int selImage = arg.GetNumber(4)
	//wxTreeItemData* data = arg.GetNumber(5)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __InsertItem_1, "InsertItem_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selImage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __InsertItem_1)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& parent = arg.GetNumber(0)
	//size_t pos = arg.GetNumber(1)
	//const wxString& text = arg.GetNumber(2)
	//int image = arg.GetNumber(3)
	//int selImage = arg.GetNumber(4)
	//wxTreeItemData* data = arg.GetNumber(5)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __IsBold, "IsBold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __IsBold)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->IsBold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __IsEmpty)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __IsExpanded, "IsExpanded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __IsExpanded)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->IsExpanded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __IsSelected, "IsSelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __IsSelected)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->IsSelected();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __IsVisible, "IsVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __IsVisible)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->IsVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __ItemHasChildren, "ItemHasChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __ItemHasChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->ItemHasChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __OnCompareItems, "OnCompareItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __OnCompareItems)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item1 = arg.GetNumber(0)
	//const wxTreeItemId& item2 = arg.GetNumber(1)
	//pThis->GetEntity()->OnCompareItems();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __PrependItem, "PrependItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selImage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __PrependItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& parent = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//int image = arg.GetNumber(2)
	//int selImage = arg.GetNumber(3)
	//wxTreeItemData* data = arg.GetNumber(4)
	//pThis->GetEntity()->PrependItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __ScrollTo, "ScrollTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __ScrollTo)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollTo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SelectItem, "SelectItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SelectItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//bool select = arg.GetNumber(1)
	//pThis->GetEntity()->SelectItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SetButtonsImageList, "SetButtonsImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SetButtonsImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxImageList* imageList = arg.GetNumber(0)
	//pThis->GetEntity()->SetButtonsImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SetImageList, "SetImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SetImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxImageList* imageList = arg.GetNumber(0)
	//pThis->GetEntity()->SetImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SetIndent, "SetIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SetIndent)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int indent = arg.GetNumber(0)
	//pThis->GetEntity()->SetIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SetItemBackgroundColour, "SetItemBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SetItemBackgroundColour)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//const wxColour& col = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SetItemBold, "SetItemBold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bold", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SetItemBold)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//bool bold = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemBold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SetItemData, "SetItemData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SetItemData)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxTreeItemData* data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SetItemDropHighlight, "SetItemDropHighlight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "highlight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SetItemDropHighlight)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//bool highlight = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemDropHighlight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SetItemFont, "SetItemFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SetItemFont)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//const wxFont& font = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SetItemHasChildren, "SetItemHasChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hasChildren", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SetItemHasChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//bool hasChildren = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemHasChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SetItemImage, "SetItemImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SetItemImage)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//int image = arg.GetNumber(1)
	//wxTreeItemIcon which = arg.GetNumber(2)
	//pThis->GetEntity()->SetItemImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SetItemState, "SetItemState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SetItemState)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//int state = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SetItemText, "SetItemText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SetItemText)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SetItemTextColour, "SetItemTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SetItemTextColour)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//const wxColour& col = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SetQuickBestSize, "SetQuickBestSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "quickBestSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SetQuickBestSize)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool quickBestSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetQuickBestSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SetStateImageList, "SetStateImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SetStateImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxImageList* imageList = arg.GetNumber(0)
	//pThis->GetEntity()->SetStateImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SetWindowStyle, "SetWindowStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styles", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SetWindowStyle)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long styles = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindowStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SortChildren, "SortChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SortChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->SortChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __Toggle, "Toggle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __Toggle)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->Toggle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __ToggleItemSelection, "ToggleItemSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __ToggleItemSelection)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->ToggleItemSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __Unselect, "Unselect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __Unselect)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Unselect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __UnselectAll, "UnselectAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __UnselectAll)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UnselectAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __UnselectItem, "UnselectItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __UnselectItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//pThis->GetEntity()->UnselectItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __SelectChildren, "SelectChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __SelectChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& parent = arg.GetNumber(0)
	//pThis->GetEntity()->SelectChildren();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTreeCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__TreeCtrl);
	Gura_AssignFunction(__TreeCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_TreeCtrl, __AddRoot);
	Gura_AssignMethod(wx_TreeCtrl, __AppendItem);
	Gura_AssignMethod(wx_TreeCtrl, __AssignButtonsImageList);
	Gura_AssignMethod(wx_TreeCtrl, __AssignImageList);
	Gura_AssignMethod(wx_TreeCtrl, __AssignStateImageList);
	Gura_AssignMethod(wx_TreeCtrl, __Collapse);
	Gura_AssignMethod(wx_TreeCtrl, __CollapseAll);
	Gura_AssignMethod(wx_TreeCtrl, __CollapseAllChildren);
	Gura_AssignMethod(wx_TreeCtrl, __CollapseAndReset);
	Gura_AssignMethod(wx_TreeCtrl, __Create);
	Gura_AssignMethod(wx_TreeCtrl, __Delete);
	Gura_AssignMethod(wx_TreeCtrl, __DeleteAllItems);
	Gura_AssignMethod(wx_TreeCtrl, __DeleteChildren);
	Gura_AssignMethod(wx_TreeCtrl, __EditLabel);
	Gura_AssignMethod(wx_TreeCtrl, __EnableBellOnNoMatch);
	Gura_AssignMethod(wx_TreeCtrl, __EndEditLabel);
	Gura_AssignMethod(wx_TreeCtrl, __EnsureVisible);
	Gura_AssignMethod(wx_TreeCtrl, __Expand);
	Gura_AssignMethod(wx_TreeCtrl, __ExpandAll);
	Gura_AssignMethod(wx_TreeCtrl, __ExpandAllChildren);
	Gura_AssignMethod(wx_TreeCtrl, __GetBoundingRect);
	Gura_AssignMethod(wx_TreeCtrl, __GetButtonsImageList);
	Gura_AssignMethod(wx_TreeCtrl, __GetChildrenCount);
	Gura_AssignMethod(wx_TreeCtrl, __GetCount);
	Gura_AssignMethod(wx_TreeCtrl, __GetEditControl);
	Gura_AssignMethod(wx_TreeCtrl, __GetFirstChild);
	Gura_AssignMethod(wx_TreeCtrl, __GetFirstVisibleItem);
	Gura_AssignMethod(wx_TreeCtrl, __GetFocusedItem);
	Gura_AssignMethod(wx_TreeCtrl, __ClearFocusedItem);
	Gura_AssignMethod(wx_TreeCtrl, __SetFocusedItem);
	Gura_AssignMethod(wx_TreeCtrl, __GetImageList);
	Gura_AssignMethod(wx_TreeCtrl, __GetIndent);
	Gura_AssignMethod(wx_TreeCtrl, __GetItemBackgroundColour);
	Gura_AssignMethod(wx_TreeCtrl, __GetItemData);
	Gura_AssignMethod(wx_TreeCtrl, __GetItemFont);
	Gura_AssignMethod(wx_TreeCtrl, __GetItemImage);
	Gura_AssignMethod(wx_TreeCtrl, __GetItemParent);
	Gura_AssignMethod(wx_TreeCtrl, __GetItemState);
	Gura_AssignMethod(wx_TreeCtrl, __GetItemText);
	Gura_AssignMethod(wx_TreeCtrl, __GetItemTextColour);
	Gura_AssignMethod(wx_TreeCtrl, __GetLastChild);
	Gura_AssignMethod(wx_TreeCtrl, __GetNextChild);
	Gura_AssignMethod(wx_TreeCtrl, __GetNextSibling);
	Gura_AssignMethod(wx_TreeCtrl, __GetNextVisible);
	Gura_AssignMethod(wx_TreeCtrl, __GetPrevSibling);
	Gura_AssignMethod(wx_TreeCtrl, __GetPrevVisible);
	Gura_AssignMethod(wx_TreeCtrl, __GetQuickBestSize);
	Gura_AssignMethod(wx_TreeCtrl, __GetRootItem);
	Gura_AssignMethod(wx_TreeCtrl, __GetSelection);
	Gura_AssignMethod(wx_TreeCtrl, __GetSelections);
	Gura_AssignMethod(wx_TreeCtrl, __GetStateImageList);
	Gura_AssignMethod(wx_TreeCtrl, __HitTest);
	Gura_AssignMethod(wx_TreeCtrl, __InsertItem);
	Gura_AssignMethod(wx_TreeCtrl, __InsertItem_1);
	Gura_AssignMethod(wx_TreeCtrl, __IsBold);
	Gura_AssignMethod(wx_TreeCtrl, __IsEmpty);
	Gura_AssignMethod(wx_TreeCtrl, __IsExpanded);
	Gura_AssignMethod(wx_TreeCtrl, __IsSelected);
	Gura_AssignMethod(wx_TreeCtrl, __IsVisible);
	Gura_AssignMethod(wx_TreeCtrl, __ItemHasChildren);
	Gura_AssignMethod(wx_TreeCtrl, __OnCompareItems);
	Gura_AssignMethod(wx_TreeCtrl, __PrependItem);
	Gura_AssignMethod(wx_TreeCtrl, __ScrollTo);
	Gura_AssignMethod(wx_TreeCtrl, __SelectItem);
	Gura_AssignMethod(wx_TreeCtrl, __SetButtonsImageList);
	Gura_AssignMethod(wx_TreeCtrl, __SetImageList);
	Gura_AssignMethod(wx_TreeCtrl, __SetIndent);
	Gura_AssignMethod(wx_TreeCtrl, __SetItemBackgroundColour);
	Gura_AssignMethod(wx_TreeCtrl, __SetItemBold);
	Gura_AssignMethod(wx_TreeCtrl, __SetItemData);
	Gura_AssignMethod(wx_TreeCtrl, __SetItemDropHighlight);
	Gura_AssignMethod(wx_TreeCtrl, __SetItemFont);
	Gura_AssignMethod(wx_TreeCtrl, __SetItemHasChildren);
	Gura_AssignMethod(wx_TreeCtrl, __SetItemImage);
	Gura_AssignMethod(wx_TreeCtrl, __SetItemState);
	Gura_AssignMethod(wx_TreeCtrl, __SetItemText);
	Gura_AssignMethod(wx_TreeCtrl, __SetItemTextColour);
	Gura_AssignMethod(wx_TreeCtrl, __SetQuickBestSize);
	Gura_AssignMethod(wx_TreeCtrl, __SetStateImageList);
	Gura_AssignMethod(wx_TreeCtrl, __SetWindowStyle);
	Gura_AssignMethod(wx_TreeCtrl, __SortChildren);
	Gura_AssignMethod(wx_TreeCtrl, __Toggle);
	Gura_AssignMethod(wx_TreeCtrl, __ToggleItemSelection);
	Gura_AssignMethod(wx_TreeCtrl, __Unselect);
	Gura_AssignMethod(wx_TreeCtrl, __UnselectAll);
	Gura_AssignMethod(wx_TreeCtrl, __UnselectItem);
	Gura_AssignMethod(wx_TreeCtrl, __SelectChildren);
}

Gura_ImplementDescendantCreator(wx_TreeCtrl)
{
	return new Object_wx_TreeCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
