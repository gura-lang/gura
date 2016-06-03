//----------------------------------------------------------------------------
// wxListCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxListCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxListCtrl
//----------------------------------------------------------------------------
Object_wx_ListCtrl::~Object_wx_ListCtrl()
{
}

Object *Object_wx_ListCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_ListCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.ListCtrl:");
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
Gura_DeclareFunctionAlias(__wxListCtrl, "wxListCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ListCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxListCtrl)
{
	//wxListCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxListCtrl_1, "wxListCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ListCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxListCtrl_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//wxListCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ListCtrl, __AppendColumn, "AppendColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "heading", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __AppendColumn)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int heading = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//pThis->GetEntity()->AppendColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __Arrange, "Arrange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __Arrange)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->Arrange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __AssignImageList, "AssignImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __AssignImageList)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imageList = arg.GetNumber(0)
	//int which = arg.GetNumber(1)
	//pThis->GetEntity()->AssignImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __ClearAll, "ClearAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __ClearAll)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __Create, "Create")
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

Gura_ImplementMethod(wx_ListCtrl, __Create)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_ListCtrl, __DeleteAllItems, "DeleteAllItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __DeleteAllItems)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteAllItems();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __DeleteColumn, "DeleteColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __DeleteColumn)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __DeleteItem, "DeleteItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __DeleteItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __EditLabel, "EditLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textControlClass", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __EditLabel)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int textControlClass = arg.GetNumber(1)
	//pThis->GetEntity()->EditLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __EnableAlternateRowColours, "EnableAlternateRowColours")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __EnableAlternateRowColours)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableAlternateRowColours();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __EnableBellOnNoMatch, "EnableBellOnNoMatch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "on", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __EnableBellOnNoMatch)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int on = arg.GetNumber(0)
	//pThis->GetEntity()->EnableBellOnNoMatch();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __EndEditLabel, "EndEditLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cancel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __EndEditLabel)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cancel = arg.GetNumber(0)
	//pThis->GetEntity()->EndEditLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __EnsureVisible, "EnsureVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __EnsureVisible)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __FindItem, "FindItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "partial", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __FindItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int str = arg.GetNumber(1)
	//int partial = arg.GetNumber(2)
	//pThis->GetEntity()->FindItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __FindItem_1, "FindItem_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __FindItem_1)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->FindItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __FindItem_2, "FindItem_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __FindItem_2)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int pt = arg.GetNumber(1)
	//int direction = arg.GetNumber(2)
	//pThis->GetEntity()->FindItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetColumn, "GetColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetColumn)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetColumnCount, "GetColumnCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetColumnCount)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetColumnIndexFromOrder, "GetColumnIndexFromOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetColumnIndexFromOrder)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnIndexFromOrder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetColumnOrder, "GetColumnOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetColumnOrder)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnOrder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetColumnWidth, "GetColumnWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetColumnWidth)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetColumnsOrder, "GetColumnsOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetColumnsOrder)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumnsOrder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetCountPerPage, "GetCountPerPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetCountPerPage)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCountPerPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetEditControl, "GetEditControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetEditControl)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEditControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetImageList, "GetImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetImageList)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int which = arg.GetNumber(0)
	//pThis->GetEntity()->GetImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItem, "GetItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int info = arg.GetNumber(0)
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemBackgroundColour, "GetItemBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemBackgroundColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemCount, "GetItemCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemCount)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetItemCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemData, "GetItemData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemData)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemFont, "GetItemFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemFont)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemPosition, "GetItemPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemPosition)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->GetItemPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemRect, "GetItemRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "code", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemRect)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//int code = arg.GetNumber(2)
	//pThis->GetEntity()->GetItemRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemSpacing, "GetItemSpacing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemSpacing)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetItemSpacing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemState, "GetItemState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stateMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemState)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int stateMask = arg.GetNumber(1)
	//pThis->GetEntity()->GetItemState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemText, "GetItemText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemText)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetItemText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemTextColour, "GetItemTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemTextColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetNextItem, "GetNextItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "geometry", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetNextItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int geometry = arg.GetNumber(1)
	//int state = arg.GetNumber(2)
	//pThis->GetEntity()->GetNextItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetSelectedItemCount, "GetSelectedItemCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetSelectedItemCount)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedItemCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetSubItemRect, "GetSubItemRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "subItem", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "code", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetSubItemRect)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int subItem = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int code = arg.GetNumber(3)
	//pThis->GetEntity()->GetSubItemRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetTextColour, "GetTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetTextColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetTopItem, "GetTopItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetTopItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetViewRect, "GetViewRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetViewRect)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetViewRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetAlternateRowColour, "SetAlternateRowColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetAlternateRowColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlternateRowColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetAlternateRowColour, "GetAlternateRowColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetAlternateRowColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAlternateRowColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __HitTest, "HitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ptrSubItem", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __HitTest)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int point = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//int ptrSubItem = arg.GetNumber(2)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __InReportView, "InReportView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __InReportView)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->InReportView();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __InsertColumn, "InsertColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __InsertColumn)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int info = arg.GetNumber(1)
	//pThis->GetEntity()->InsertColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __InsertColumn_1, "InsertColumn_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "heading", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __InsertColumn_1)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int heading = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//pThis->GetEntity()->InsertColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __InsertItem, "InsertItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __InsertItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int info = arg.GetNumber(0)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __InsertItem_1, "InsertItem_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __InsertItem_1)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __InsertItem_2, "InsertItem_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __InsertItem_2)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int imageIndex = arg.GetNumber(1)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __InsertItem_3, "InsertItem_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __InsertItem_3)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int imageIndex = arg.GetNumber(2)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __IsVirtual, "IsVirtual")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __IsVirtual)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsVirtual();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __RefreshItem, "RefreshItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __RefreshItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->RefreshItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __RefreshItems, "RefreshItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "itemFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "itemTo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __RefreshItems)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int itemFrom = arg.GetNumber(0)
	//int itemTo = arg.GetNumber(1)
	//pThis->GetEntity()->RefreshItems();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __ScrollList, "ScrollList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __ScrollList)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->ScrollList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetBackgroundColour, "SetBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetBackgroundColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetColumn, "SetColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetColumn)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->SetColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetColumnWidth, "SetColumnWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetColumnWidth)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//pThis->GetEntity()->SetColumnWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetColumnsOrder, "SetColumnsOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orders", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetColumnsOrder)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orders = arg.GetNumber(0)
	//pThis->GetEntity()->SetColumnsOrder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetImageList, "SetImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetImageList)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imageList = arg.GetNumber(0)
	//int which = arg.GetNumber(1)
	//pThis->GetEntity()->SetImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItem, "SetItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int info = arg.GetNumber(0)
	//pThis->GetEntity()->SetItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItem_1, "SetItem_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItem_1)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int imageId = arg.GetNumber(3)
	//pThis->GetEntity()->SetItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItemBackgroundColour, "SetItemBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItemBackgroundColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItemColumnImage, "SetItemColumnImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItemColumnImage)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//int image = arg.GetNumber(2)
	//pThis->GetEntity()->SetItemColumnImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItemCount, "SetItemCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItemCount)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int count = arg.GetNumber(0)
	//pThis->GetEntity()->SetItemCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItemData, "SetItemData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItemData)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItemFont, "SetItemFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItemFont)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int font = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItemImage, "SetItemImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selImage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItemImage)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int image = arg.GetNumber(1)
	//int selImage = arg.GetNumber(2)
	//pThis->GetEntity()->SetItemImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItemPosition, "SetItemPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItemPosition)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItemPtrData, "SetItemPtrData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItemPtrData)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemPtrData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItemState, "SetItemState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stateMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItemState)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int state = arg.GetNumber(1)
	//int stateMask = arg.GetNumber(2)
	//pThis->GetEntity()->SetItemState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItemText, "SetItemText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItemText)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItemTextColour, "SetItemTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItemTextColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetSingleStyle, "SetSingleStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "add", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetSingleStyle)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int add = arg.GetNumber(1)
	//pThis->GetEntity()->SetSingleStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetTextColour, "SetTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetTextColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetWindowStyleFlag, "SetWindowStyleFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetWindowStyleFlag)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindowStyleFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SortItems, "SortItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fnSortCallBack", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SortItems)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fnSortCallBack = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SortItems();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __HasCheckboxes, "HasCheckboxes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __HasCheckboxes)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasCheckboxes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __EnableCheckboxes, "EnableCheckboxes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __EnableCheckboxes)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableCheckboxes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __IsItemChecked, "IsItemChecked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __IsItemChecked)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsItemChecked();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __CheckItem, "CheckItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "check", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __CheckItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int check = arg.GetNumber(1)
	//pThis->GetEntity()->CheckItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __OnGetItemAttr, "OnGetItemAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __OnGetItemAttr)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->OnGetItemAttr();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __OnGetItemColumnAttr, "OnGetItemColumnAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __OnGetItemColumnAttr)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//pThis->GetEntity()->OnGetItemColumnAttr();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __OnGetItemColumnImage, "OnGetItemColumnImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __OnGetItemColumnImage)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//pThis->GetEntity()->OnGetItemColumnImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __OnGetItemImage, "OnGetItemImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __OnGetItemImage)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->OnGetItemImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __OnGetItemText, "OnGetItemText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __OnGetItemText)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//pThis->GetEntity()->OnGetItemText();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxListCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__wxListCtrl);
	Gura_AssignFunction(__wxListCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_ListCtrl, __AppendColumn);
	Gura_AssignMethod(wx_ListCtrl, __Arrange);
	Gura_AssignMethod(wx_ListCtrl, __AssignImageList);
	Gura_AssignMethod(wx_ListCtrl, __ClearAll);
	Gura_AssignMethod(wx_ListCtrl, __Create);
	Gura_AssignMethod(wx_ListCtrl, __DeleteAllItems);
	Gura_AssignMethod(wx_ListCtrl, __DeleteColumn);
	Gura_AssignMethod(wx_ListCtrl, __DeleteItem);
	Gura_AssignMethod(wx_ListCtrl, __EditLabel);
	Gura_AssignMethod(wx_ListCtrl, __EnableAlternateRowColours);
	Gura_AssignMethod(wx_ListCtrl, __EnableBellOnNoMatch);
	Gura_AssignMethod(wx_ListCtrl, __EndEditLabel);
	Gura_AssignMethod(wx_ListCtrl, __EnsureVisible);
	Gura_AssignMethod(wx_ListCtrl, __FindItem);
	Gura_AssignMethod(wx_ListCtrl, __FindItem_1);
	Gura_AssignMethod(wx_ListCtrl, __FindItem_2);
	Gura_AssignMethod(wx_ListCtrl, __GetColumn);
	Gura_AssignMethod(wx_ListCtrl, __GetColumnCount);
	Gura_AssignMethod(wx_ListCtrl, __GetColumnIndexFromOrder);
	Gura_AssignMethod(wx_ListCtrl, __GetColumnOrder);
	Gura_AssignMethod(wx_ListCtrl, __GetColumnWidth);
	Gura_AssignMethod(wx_ListCtrl, __GetColumnsOrder);
	Gura_AssignMethod(wx_ListCtrl, __GetCountPerPage);
	Gura_AssignMethod(wx_ListCtrl, __GetEditControl);
	Gura_AssignMethod(wx_ListCtrl, __GetImageList);
	Gura_AssignMethod(wx_ListCtrl, __GetItem);
	Gura_AssignMethod(wx_ListCtrl, __GetItemBackgroundColour);
	Gura_AssignMethod(wx_ListCtrl, __GetItemCount);
	Gura_AssignMethod(wx_ListCtrl, __GetItemData);
	Gura_AssignMethod(wx_ListCtrl, __GetItemFont);
	Gura_AssignMethod(wx_ListCtrl, __GetItemPosition);
	Gura_AssignMethod(wx_ListCtrl, __GetItemRect);
	Gura_AssignMethod(wx_ListCtrl, __GetItemSpacing);
	Gura_AssignMethod(wx_ListCtrl, __GetItemState);
	Gura_AssignMethod(wx_ListCtrl, __GetItemText);
	Gura_AssignMethod(wx_ListCtrl, __GetItemTextColour);
	Gura_AssignMethod(wx_ListCtrl, __GetNextItem);
	Gura_AssignMethod(wx_ListCtrl, __GetSelectedItemCount);
	Gura_AssignMethod(wx_ListCtrl, __GetSubItemRect);
	Gura_AssignMethod(wx_ListCtrl, __GetTextColour);
	Gura_AssignMethod(wx_ListCtrl, __GetTopItem);
	Gura_AssignMethod(wx_ListCtrl, __GetViewRect);
	Gura_AssignMethod(wx_ListCtrl, __SetAlternateRowColour);
	Gura_AssignMethod(wx_ListCtrl, __GetAlternateRowColour);
	Gura_AssignMethod(wx_ListCtrl, __HitTest);
	Gura_AssignMethod(wx_ListCtrl, __InReportView);
	Gura_AssignMethod(wx_ListCtrl, __InsertColumn);
	Gura_AssignMethod(wx_ListCtrl, __InsertColumn_1);
	Gura_AssignMethod(wx_ListCtrl, __InsertItem);
	Gura_AssignMethod(wx_ListCtrl, __InsertItem_1);
	Gura_AssignMethod(wx_ListCtrl, __InsertItem_2);
	Gura_AssignMethod(wx_ListCtrl, __InsertItem_3);
	Gura_AssignMethod(wx_ListCtrl, __IsVirtual);
	Gura_AssignMethod(wx_ListCtrl, __RefreshItem);
	Gura_AssignMethod(wx_ListCtrl, __RefreshItems);
	Gura_AssignMethod(wx_ListCtrl, __ScrollList);
	Gura_AssignMethod(wx_ListCtrl, __SetBackgroundColour);
	Gura_AssignMethod(wx_ListCtrl, __SetColumn);
	Gura_AssignMethod(wx_ListCtrl, __SetColumnWidth);
	Gura_AssignMethod(wx_ListCtrl, __SetColumnsOrder);
	Gura_AssignMethod(wx_ListCtrl, __SetImageList);
	Gura_AssignMethod(wx_ListCtrl, __SetItem);
	Gura_AssignMethod(wx_ListCtrl, __SetItem_1);
	Gura_AssignMethod(wx_ListCtrl, __SetItemBackgroundColour);
	Gura_AssignMethod(wx_ListCtrl, __SetItemColumnImage);
	Gura_AssignMethod(wx_ListCtrl, __SetItemCount);
	Gura_AssignMethod(wx_ListCtrl, __SetItemData);
	Gura_AssignMethod(wx_ListCtrl, __SetItemFont);
	Gura_AssignMethod(wx_ListCtrl, __SetItemImage);
	Gura_AssignMethod(wx_ListCtrl, __SetItemPosition);
	Gura_AssignMethod(wx_ListCtrl, __SetItemPtrData);
	Gura_AssignMethod(wx_ListCtrl, __SetItemState);
	Gura_AssignMethod(wx_ListCtrl, __SetItemText);
	Gura_AssignMethod(wx_ListCtrl, __SetItemTextColour);
	Gura_AssignMethod(wx_ListCtrl, __SetSingleStyle);
	Gura_AssignMethod(wx_ListCtrl, __SetTextColour);
	Gura_AssignMethod(wx_ListCtrl, __SetWindowStyleFlag);
	Gura_AssignMethod(wx_ListCtrl, __SortItems);
	Gura_AssignMethod(wx_ListCtrl, __HasCheckboxes);
	Gura_AssignMethod(wx_ListCtrl, __EnableCheckboxes);
	Gura_AssignMethod(wx_ListCtrl, __IsItemChecked);
	Gura_AssignMethod(wx_ListCtrl, __CheckItem);
	Gura_AssignMethod(wx_ListCtrl, __OnGetItemAttr);
	Gura_AssignMethod(wx_ListCtrl, __OnGetItemColumnAttr);
	Gura_AssignMethod(wx_ListCtrl, __OnGetItemColumnImage);
	Gura_AssignMethod(wx_ListCtrl, __OnGetItemImage);
	Gura_AssignMethod(wx_ListCtrl, __OnGetItemText);
}

Gura_ImplementDescendantCreator(wx_ListCtrl)
{
	return new Object_wx_ListCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
