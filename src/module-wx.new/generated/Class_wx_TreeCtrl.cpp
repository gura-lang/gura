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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxTreeCtrl(parent, id, pos, size, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TreeCtrl, __AddRoot, "AddRoot")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxTreeItemId _rtn = pThis->GetEntity()->AddRoot(text, image, selImage, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __AppendItem, "AppendItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxTreeItemId _rtn = pThis->GetEntity()->AppendItem(parent, text, image, selImage, data);
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
	//pThis->GetEntity()->AssignButtonsImageList(imageList);
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
	//pThis->GetEntity()->AssignImageList(imageList);
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
	//pThis->GetEntity()->AssignStateImageList(imageList);
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
	//pThis->GetEntity()->Collapse(item);
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
	//pThis->GetEntity()->CollapseAllChildren(item);
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
	//pThis->GetEntity()->CollapseAndReset(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//bool _rtn = pThis->GetEntity()->Create(parent, id, pos, size, style, validator, name);
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
	//pThis->GetEntity()->Delete(item);
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
	//pThis->GetEntity()->DeleteChildren(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __EditLabel, "EditLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textCtrlClass", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __EditLabel)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxClassInfo* textCtrlClass = arg.GetNumber(1)
	//wxTextCtrl* _rtn = pThis->GetEntity()->EditLabel(item, textCtrlClass);
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
	//pThis->GetEntity()->EnableBellOnNoMatch(on);
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
	//pThis->GetEntity()->EndEditLabel(item, discardChanges);
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
	//pThis->GetEntity()->EnsureVisible(item);
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
	//pThis->GetEntity()->Expand(item);
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
	//pThis->GetEntity()->ExpandAllChildren(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetBoundingRect, "GetBoundingRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//bool _rtn = pThis->GetEntity()->GetBoundingRect(item, rect, textOnly);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetButtonsImageList, "GetButtonsImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetButtonsImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxImageList* _rtn = pThis->GetEntity()->GetButtonsImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetChildrenCount, "GetChildrenCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursively", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetChildrenCount)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//bool recursively = arg.GetNumber(1)
	//size_t _rtn = pThis->GetEntity()->GetChildrenCount(item, recursively);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetCount)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int _rtn = pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetEditControl, "GetEditControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetEditControl)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTextCtrl* _rtn = pThis->GetEntity()->GetEditControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetFirstChild, "GetFirstChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetFirstChild)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxTreeItemIdValue& cookie = arg.GetNumber(1)
	//wxTreeItemId _rtn = pThis->GetEntity()->GetFirstChild(item, cookie);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetFirstVisibleItem, "GetFirstVisibleItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetFirstVisibleItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeItemId _rtn = pThis->GetEntity()->GetFirstVisibleItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetFocusedItem, "GetFocusedItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetFocusedItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeItemId _rtn = pThis->GetEntity()->GetFocusedItem();
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
	//pThis->GetEntity()->SetFocusedItem(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetImageList, "GetImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxImageList* _rtn = pThis->GetEntity()->GetImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetIndent, "GetIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetIndent)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int _rtn = pThis->GetEntity()->GetIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetItemBackgroundColour, "GetItemBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetItemBackgroundColour)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxColour _rtn = pThis->GetEntity()->GetItemBackgroundColour(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetItemData, "GetItemData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetItemData)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxTreeItemData* _rtn = pThis->GetEntity()->GetItemData(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetItemFont, "GetItemFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetItemFont)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxFont _rtn = pThis->GetEntity()->GetItemFont(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetItemImage, "GetItemImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetItemImage)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxTreeItemIcon which = arg.GetNumber(1)
	//int _rtn = pThis->GetEntity()->GetItemImage(item, which);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetItemParent, "GetItemParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetItemParent)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxTreeItemId _rtn = pThis->GetEntity()->GetItemParent(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetItemState, "GetItemState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetItemState)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetItemState(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetItemText, "GetItemText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetItemText)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetItemText(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetItemTextColour, "GetItemTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetItemTextColour)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxColour _rtn = pThis->GetEntity()->GetItemTextColour(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetLastChild, "GetLastChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetLastChild)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxTreeItemId _rtn = pThis->GetEntity()->GetLastChild(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetNextChild, "GetNextChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetNextChild)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxTreeItemIdValue& cookie = arg.GetNumber(1)
	//wxTreeItemId _rtn = pThis->GetEntity()->GetNextChild(item, cookie);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetNextSibling, "GetNextSibling")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetNextSibling)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxTreeItemId _rtn = pThis->GetEntity()->GetNextSibling(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetNextVisible, "GetNextVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetNextVisible)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxTreeItemId _rtn = pThis->GetEntity()->GetNextVisible(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetPrevSibling, "GetPrevSibling")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetPrevSibling)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxTreeItemId _rtn = pThis->GetEntity()->GetPrevSibling(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetPrevVisible, "GetPrevVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetPrevVisible)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//wxTreeItemId _rtn = pThis->GetEntity()->GetPrevVisible(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetQuickBestSize, "GetQuickBestSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetQuickBestSize)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetQuickBestSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetRootItem, "GetRootItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetRootItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeItemId _rtn = pThis->GetEntity()->GetRootItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetSelection)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTreeItemId _rtn = pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetSelections, "GetSelections")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetSelections)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArrayTreeItemIds& selection = arg.GetNumber(0)
	//size_t _rtn = pThis->GetEntity()->GetSelections(selection);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __GetStateImageList, "GetStateImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __GetStateImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxImageList* _rtn = pThis->GetEntity()->GetStateImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __HitTest, "HitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __HitTest)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& point = arg.GetNumber(0)
	//int& flags = arg.GetNumber(1)
	//wxTreeItemId _rtn = pThis->GetEntity()->HitTest(point, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __InsertItem, "InsertItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxTreeItemId _rtn = pThis->GetEntity()->InsertItem(parent, previous, text, image, selImage, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __InsertItem_1, "InsertItem_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxTreeItemId _rtn = pThis->GetEntity()->InsertItem(parent, pos, text, image, selImage, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __IsBold, "IsBold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __IsBold)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsBold(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, __IsEmpty)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __IsExpanded, "IsExpanded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __IsExpanded)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsExpanded(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __IsSelected, "IsSelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __IsSelected)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsSelected(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __IsVisible, "IsVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __IsVisible)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsVisible(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __ItemHasChildren, "ItemHasChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __ItemHasChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->ItemHasChildren(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __OnCompareItems, "OnCompareItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, __OnCompareItems)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTreeItemId& item1 = arg.GetNumber(0)
	//const wxTreeItemId& item2 = arg.GetNumber(1)
	//int _rtn = pThis->GetEntity()->OnCompareItems(item1, item2);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeCtrl, __PrependItem, "PrependItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxTreeItemId _rtn = pThis->GetEntity()->PrependItem(parent, text, image, selImage, data);
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
	//pThis->GetEntity()->ScrollTo(item);
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
	//pThis->GetEntity()->SelectItem(item, select);
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
	//pThis->GetEntity()->SetButtonsImageList(imageList);
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
	//pThis->GetEntity()->SetImageList(imageList);
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
	//pThis->GetEntity()->SetIndent(indent);
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
	//pThis->GetEntity()->SetItemBackgroundColour(item, col);
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
	//pThis->GetEntity()->SetItemBold(item, bold);
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
	//pThis->GetEntity()->SetItemData(item, data);
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
	//pThis->GetEntity()->SetItemDropHighlight(item, highlight);
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
	//pThis->GetEntity()->SetItemFont(item, font);
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
	//pThis->GetEntity()->SetItemHasChildren(item, hasChildren);
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
	//pThis->GetEntity()->SetItemImage(item, image, which);
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
	//pThis->GetEntity()->SetItemState(item, state);
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
	//pThis->GetEntity()->SetItemText(item, text);
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
	//pThis->GetEntity()->SetItemTextColour(item, col);
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
	//pThis->GetEntity()->SetQuickBestSize(quickBestSize);
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
	//pThis->GetEntity()->SetStateImageList(imageList);
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
	//pThis->GetEntity()->SetWindowStyle(styles);
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
	//pThis->GetEntity()->SortChildren(item);
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
	//pThis->GetEntity()->Toggle(item);
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
	//pThis->GetEntity()->ToggleItemSelection(item);
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
	//pThis->GetEntity()->UnselectItem(item);
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
	//pThis->GetEntity()->SelectChildren(parent);
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
