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
Gura_DeclareFunctionAlias(__ListCtrl, "ListCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ListCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ListCtrl)
{
	//wxListCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__ListCtrl_1, "ListCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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

Gura_ImplementFunction(__ListCtrl_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxValidator& validator = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//wxListCtrl(parent, id, pos, size, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ListCtrl, __AppendColumn, "AppendColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "heading", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __AppendColumn)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& heading = arg.GetNumber(0)
	//wxListColumnFormat format = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//long _rtn = pThis->GetEntity()->AppendColumn(heading, format, width);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __Arrange, "Arrange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __Arrange)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Arrange(flag);
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
	//wxImageList* imageList = arg.GetNumber(0)
	//int which = arg.GetNumber(1)
	//pThis->GetEntity()->AssignImageList(imageList, which);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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

Gura_DeclareMethodAlias(wx_ListCtrl, __DeleteAllItems, "DeleteAllItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __DeleteAllItems)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->DeleteAllItems();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __DeleteColumn, "DeleteColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __DeleteColumn)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->DeleteColumn(col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __DeleteItem, "DeleteItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __DeleteItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->DeleteItem(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __EditLabel, "EditLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textControlClass", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __EditLabel)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//wxClassInfo* textControlClass = arg.GetNumber(1)
	//wxTextCtrl* _rtn = pThis->GetEntity()->EditLabel(item, textControlClass);
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
	//bool enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableAlternateRowColours(enable);
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
	//bool on = arg.GetNumber(0)
	//pThis->GetEntity()->EnableBellOnNoMatch(on);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __EndEditLabel, "EndEditLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "cancel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __EndEditLabel)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool cancel = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->EndEditLabel(cancel);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __EnsureVisible, "EnsureVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __EnsureVisible)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->EnsureVisible(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __FindItem, "FindItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "partial", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __FindItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long start = arg.GetNumber(0)
	//const wxString& str = arg.GetNumber(1)
	//bool partial = arg.GetNumber(2)
	//long _rtn = pThis->GetEntity()->FindItem(start, str, partial);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __FindItem_1, "FindItem_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __FindItem_1)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long start = arg.GetNumber(0)
	//wxUIntPtr data = arg.GetNumber(1)
	//long _rtn = pThis->GetEntity()->FindItem(start, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __FindItem_2, "FindItem_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __FindItem_2)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long start = arg.GetNumber(0)
	//const wxPoint& pt = arg.GetNumber(1)
	//int direction = arg.GetNumber(2)
	//long _rtn = pThis->GetEntity()->FindItem(start, pt, direction);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetColumn, "GetColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetColumn)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//wxListItem& item = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->GetColumn(col, item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetColumnCount, "GetColumnCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetColumnCount)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetColumnIndexFromOrder, "GetColumnIndexFromOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetColumnIndexFromOrder)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetColumnIndexFromOrder(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetColumnOrder, "GetColumnOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetColumnOrder)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetColumnOrder(col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetColumnWidth, "GetColumnWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetColumnWidth)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetColumnWidth(col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetColumnsOrder, "GetColumnsOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetColumnsOrder)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArrayInt _rtn = pThis->GetEntity()->GetColumnsOrder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetCountPerPage, "GetCountPerPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetCountPerPage)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetCountPerPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetEditControl, "GetEditControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetEditControl)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTextCtrl* _rtn = pThis->GetEntity()->GetEditControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetImageList, "GetImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetImageList)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int which = arg.GetNumber(0)
	//wxImageList* _rtn = pThis->GetEntity()->GetImageList(which);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItem, "GetItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxListItem& info = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->GetItem(info);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemBackgroundColour, "GetItemBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemBackgroundColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//wxColour _rtn = pThis->GetEntity()->GetItemBackgroundColour(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemCount, "GetItemCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemCount)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetItemCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemData, "GetItemData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemData)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//wxUIntPtr _rtn = pThis->GetEntity()->GetItemData(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemFont, "GetItemFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemFont)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//wxFont _rtn = pThis->GetEntity()->GetItemFont(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemPosition, "GetItemPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemPosition)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//wxPoint& pos = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->GetItemPosition(item, pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemRect, "GetItemRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "code", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemRect)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//wxRect& rect = arg.GetNumber(1)
	//int code = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->GetItemRect(item, rect, code);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemSpacing, "GetItemSpacing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemSpacing)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSize _rtn = pThis->GetEntity()->GetItemSpacing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemState, "GetItemState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stateMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemState)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//long stateMask = arg.GetNumber(1)
	//int _rtn = pThis->GetEntity()->GetItemState(item, stateMask);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemText, "GetItemText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemText)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//wxString _rtn = pThis->GetEntity()->GetItemText(item, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetItemTextColour, "GetItemTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetItemTextColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//wxColour _rtn = pThis->GetEntity()->GetItemTextColour(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetNextItem, "GetNextItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "geometry", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetNextItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//int geometry = arg.GetNumber(1)
	//int state = arg.GetNumber(2)
	//long _rtn = pThis->GetEntity()->GetNextItem(item, geometry, state);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetSelectedItemCount, "GetSelectedItemCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetSelectedItemCount)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetSelectedItemCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetSubItemRect, "GetSubItemRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "subItem", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "code", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __GetSubItemRect)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//long subItem = arg.GetNumber(1)
	//wxRect& rect = arg.GetNumber(2)
	//int code = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->GetSubItemRect(item, subItem, rect, code);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetTextColour, "GetTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetTextColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxColour _rtn = pThis->GetEntity()->GetTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetTopItem, "GetTopItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetTopItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long _rtn = pThis->GetEntity()->GetTopItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetViewRect, "GetViewRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetViewRect)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRect _rtn = pThis->GetEntity()->GetViewRect();
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
	//const wxColour& colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlternateRowColour(colour);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __GetAlternateRowColour, "GetAlternateRowColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __GetAlternateRowColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxColour _rtn = pThis->GetEntity()->GetAlternateRowColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __HitTest, "HitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ptrSubItem", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __HitTest)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& point = arg.GetNumber(0)
	//int& flags = arg.GetNumber(1)
	//long* ptrSubItem = arg.GetNumber(2)
	//long _rtn = pThis->GetEntity()->HitTest(point, flags, ptrSubItem);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __InReportView, "InReportView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __InReportView)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->InReportView();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __InsertColumn, "InsertColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __InsertColumn)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long col = arg.GetNumber(0)
	//const wxListItem& info = arg.GetNumber(1)
	//long _rtn = pThis->GetEntity()->InsertColumn(col, info);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __InsertColumn_1, "InsertColumn_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "heading", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __InsertColumn_1)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long col = arg.GetNumber(0)
	//const wxString& heading = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//long _rtn = pThis->GetEntity()->InsertColumn(col, heading, format, width);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __InsertItem, "InsertItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __InsertItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxListItem& info = arg.GetNumber(0)
	//long _rtn = pThis->GetEntity()->InsertItem(info);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __InsertItem_1, "InsertItem_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __InsertItem_1)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long index = arg.GetNumber(0)
	//const wxString& label = arg.GetNumber(1)
	//long _rtn = pThis->GetEntity()->InsertItem(index, label);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __InsertItem_2, "InsertItem_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __InsertItem_2)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long index = arg.GetNumber(0)
	//int imageIndex = arg.GetNumber(1)
	//long _rtn = pThis->GetEntity()->InsertItem(index, imageIndex);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __InsertItem_3, "InsertItem_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __InsertItem_3)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long index = arg.GetNumber(0)
	//const wxString& label = arg.GetNumber(1)
	//int imageIndex = arg.GetNumber(2)
	//long _rtn = pThis->GetEntity()->InsertItem(index, label, imageIndex);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __IsVirtual, "IsVirtual")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __IsVirtual)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsVirtual();
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
	//long item = arg.GetNumber(0)
	//pThis->GetEntity()->RefreshItem(item);
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
	//long itemFrom = arg.GetNumber(0)
	//long itemTo = arg.GetNumber(1)
	//pThis->GetEntity()->RefreshItems(itemFrom, itemTo);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __ScrollList, "ScrollList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __ScrollList)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->ScrollList(dx, dy);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetBackgroundColour, "SetBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetBackgroundColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& col = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->SetBackgroundColour(col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetColumn, "SetColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetColumn)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//wxListItem& item = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SetColumn(col, item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetColumnWidth, "SetColumnWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetColumnWidth)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SetColumnWidth(col, width);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetColumnsOrder, "SetColumnsOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "orders", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetColumnsOrder)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayInt& orders = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->SetColumnsOrder(orders);
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
	//wxImageList* imageList = arg.GetNumber(0)
	//int which = arg.GetNumber(1)
	//pThis->GetEntity()->SetImageList(imageList, which);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItem, "SetItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxListItem& info = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->SetItem(info);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItem_1, "SetItem_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItem_1)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long index = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//int imageId = arg.GetNumber(3)
	//long _rtn = pThis->GetEntity()->SetItem(index, column, label, imageId);
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
	//long item = arg.GetNumber(0)
	//const wxColour& col = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemBackgroundColour(item, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItemColumnImage, "SetItemColumnImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItemColumnImage)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//long column = arg.GetNumber(1)
	//int image = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->SetItemColumnImage(item, column, image);
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
	//long count = arg.GetNumber(0)
	//pThis->GetEntity()->SetItemCount(count);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItemData, "SetItemData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItemData)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//long data = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SetItemData(item, data);
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
	//long item = arg.GetNumber(0)
	//const wxFont& font = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemFont(item, font);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItemImage, "SetItemImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selImage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItemImage)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//int image = arg.GetNumber(1)
	//int selImage = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->SetItemImage(item, image, selImage);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItemPosition, "SetItemPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItemPosition)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//const wxPoint& pos = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SetItemPosition(item, pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItemPtrData, "SetItemPtrData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItemPtrData)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//wxUIntPtr data = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SetItemPtrData(item, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SetItemState, "SetItemState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stateMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SetItemState)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//long state = arg.GetNumber(1)
	//long stateMask = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->SetItemState(item, state, stateMask);
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
	//long item = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemText(item, text);
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
	//long item = arg.GetNumber(0)
	//const wxColour& col = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemTextColour(item, col);
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
	//long style = arg.GetNumber(0)
	//bool add = arg.GetNumber(1)
	//pThis->GetEntity()->SetSingleStyle(style, add);
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
	//const wxColour& col = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextColour(col);
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
	//long style = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindowStyleFlag(style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __SortItems, "SortItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "fnSortCallBack", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __SortItems)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxListCtrlCompare fnSortCallBack = arg.GetNumber(0)
	//wxIntPtr data = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SortItems(fnSortCallBack, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __HasCheckboxes, "HasCheckboxes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, __HasCheckboxes)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasCheckboxes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __EnableCheckboxes, "EnableCheckboxes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __EnableCheckboxes)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool enable = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->EnableCheckboxes(enable);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __IsItemChecked, "IsItemChecked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __IsItemChecked)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsItemChecked(item);
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
	//long item = arg.GetNumber(0)
	//bool check = arg.GetNumber(1)
	//pThis->GetEntity()->CheckItem(item, check);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __OnGetItemAttr, "OnGetItemAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __OnGetItemAttr)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//wxListItemAttr* _rtn = pThis->GetEntity()->OnGetItemAttr(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __OnGetItemColumnAttr, "OnGetItemColumnAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __OnGetItemColumnAttr)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//long column = arg.GetNumber(1)
	//wxListItemAttr* _rtn = pThis->GetEntity()->OnGetItemColumnAttr(item, column);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __OnGetItemColumnImage, "OnGetItemColumnImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __OnGetItemColumnImage)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//long column = arg.GetNumber(1)
	//int _rtn = pThis->GetEntity()->OnGetItemColumnImage(item, column);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __OnGetItemImage, "OnGetItemImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __OnGetItemImage)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->OnGetItemImage(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListCtrl, __OnGetItemText, "OnGetItemText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, __OnGetItemText)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//long column = arg.GetNumber(1)
	//wxString _rtn = pThis->GetEntity()->OnGetItemText(item, column);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxListCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__ListCtrl);
	Gura_AssignFunction(__ListCtrl_1);
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
