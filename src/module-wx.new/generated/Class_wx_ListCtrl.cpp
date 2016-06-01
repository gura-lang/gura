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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ListCtrl, wxListCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, wxListCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxListCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, wxListCtrl_1)
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

Gura_ImplementMethod(wx_ListCtrl, wxListCtrl_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxListCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, ~wxListCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, ~wxListCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxListCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, AppendColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "heading", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, AppendColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int heading = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//pThis->GetEntity()->AppendColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, Arrange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, Arrange)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->Arrange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, AssignImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, AssignImageList)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int imageList = arg.GetNumber(0)
	//int which = arg.GetNumber(1)
	//pThis->GetEntity()->AssignImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, ClearAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, ClearAll)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ClearAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, Create)
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

Gura_ImplementMethod(wx_ListCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_ListCtrl, DeleteAllItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, DeleteAllItems)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DeleteAllItems();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, DeleteColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, DeleteColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, DeleteItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, DeleteItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, EditLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textControlClass", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, EditLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int textControlClass = arg.GetNumber(1)
	//pThis->GetEntity()->EditLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, EnableAlternateRowColours)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, EnableAlternateRowColours)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableAlternateRowColours();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, EnableBellOnNoMatch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "on", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, EnableBellOnNoMatch)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int on = arg.GetNumber(0)
	//pThis->GetEntity()->EnableBellOnNoMatch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, EndEditLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cancel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, EndEditLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cancel = arg.GetNumber(0)
	//pThis->GetEntity()->EndEditLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, EnsureVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, EnsureVisible)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, FindItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "partial", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, FindItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int str = arg.GetNumber(1)
	//int partial = arg.GetNumber(2)
	//pThis->GetEntity()->FindItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, FindItem_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, FindItem_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->FindItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, FindItem_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, FindItem_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int pt = arg.GetNumber(1)
	//int direction = arg.GetNumber(2)
	//pThis->GetEntity()->FindItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, GetColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, GetColumnCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetColumnIndexFromOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, GetColumnIndexFromOrder)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnIndexFromOrder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetColumnOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, GetColumnOrder)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnOrder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetColumnWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, GetColumnWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetColumnsOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, GetColumnsOrder)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetColumnsOrder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetCountPerPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, GetCountPerPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCountPerPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetEditControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, GetEditControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEditControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, GetImageList)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int which = arg.GetNumber(0)
	//pThis->GetEntity()->GetImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, GetItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int info = arg.GetNumber(0)
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetItemBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetItemCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetItemCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemData)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetItemFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetItemPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->GetItemPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetItemRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "code", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//int code = arg.GetNumber(2)
	//pThis->GetEntity()->GetItemRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetItemSpacing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemSpacing)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetItemSpacing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetItemState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stateMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemState)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int stateMask = arg.GetNumber(1)
	//pThis->GetEntity()->GetItemState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetItemText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemText)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetItemText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetItemTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetNextItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "geometry", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, GetNextItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int geometry = arg.GetNumber(1)
	//int state = arg.GetNumber(2)
	//pThis->GetEntity()->GetNextItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetSelectedItemCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, GetSelectedItemCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedItemCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetSubItemRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "subItem", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "code", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, GetSubItemRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int subItem = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int code = arg.GetNumber(3)
	//pThis->GetEntity()->GetSubItemRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, GetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetTopItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, GetTopItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTopItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetViewRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, GetViewRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetViewRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetAlternateRowColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetAlternateRowColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlternateRowColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, GetAlternateRowColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, GetAlternateRowColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAlternateRowColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ptrSubItem", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, HitTest)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int point = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//int ptrSubItem = arg.GetNumber(2)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, InReportView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, InReportView)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->InReportView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, InsertColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, InsertColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int info = arg.GetNumber(1)
	//pThis->GetEntity()->InsertColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, InsertColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "heading", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, InsertColumn_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int heading = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//int width = arg.GetNumber(3)
	//pThis->GetEntity()->InsertColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, InsertItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, InsertItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int info = arg.GetNumber(0)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, InsertItem_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, InsertItem_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, InsertItem_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, InsertItem_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int imageIndex = arg.GetNumber(1)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, InsertItem_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, InsertItem_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int imageIndex = arg.GetNumber(2)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, IsVirtual)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, IsVirtual)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsVirtual();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, RefreshItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, RefreshItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->RefreshItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, RefreshItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "itemFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "itemTo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, RefreshItems)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int itemFrom = arg.GetNumber(0)
	//int itemTo = arg.GetNumber(1)
	//pThis->GetEntity()->RefreshItems();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, ScrollList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, ScrollList)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->ScrollList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->SetColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetColumnWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetColumnWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//pThis->GetEntity()->SetColumnWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetColumnsOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orders", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetColumnsOrder)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int orders = arg.GetNumber(0)
	//pThis->GetEntity()->SetColumnsOrder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageList", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetImageList)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int imageList = arg.GetNumber(0)
	//int which = arg.GetNumber(1)
	//pThis->GetEntity()->SetImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int info = arg.GetNumber(0)
	//pThis->GetEntity()->SetItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItem_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItem_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int imageId = arg.GetNumber(3)
	//pThis->GetEntity()->SetItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemColumnImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemColumnImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//int image = arg.GetNumber(2)
	//pThis->GetEntity()->SetItemColumnImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int count = arg.GetNumber(0)
	//pThis->GetEntity()->SetItemCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemData)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int font = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selImage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int image = arg.GetNumber(1)
	//int selImage = arg.GetNumber(2)
	//pThis->GetEntity()->SetItemImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemPtrData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemPtrData)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemPtrData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stateMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemState)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int state = arg.GetNumber(1)
	//int stateMask = arg.GetNumber(2)
	//pThis->GetEntity()->SetItemState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemText)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetSingleStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "add", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetSingleStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int add = arg.GetNumber(1)
	//pThis->GetEntity()->SetSingleStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetWindowStyleFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetWindowStyleFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindowStyleFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SortItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fnSortCallBack", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SortItems)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fnSortCallBack = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SortItems();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, HasCheckboxes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, HasCheckboxes)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasCheckboxes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, EnableCheckboxes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, EnableCheckboxes)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableCheckboxes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, IsItemChecked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, IsItemChecked)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsItemChecked();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, CheckItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "check", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, CheckItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int check = arg.GetNumber(1)
	//pThis->GetEntity()->CheckItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, OnGetItemAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, OnGetItemAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->OnGetItemAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, OnGetItemColumnAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, OnGetItemColumnAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//pThis->GetEntity()->OnGetItemColumnAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, OnGetItemColumnImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, OnGetItemColumnImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//pThis->GetEntity()->OnGetItemColumnImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, OnGetItemImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, OnGetItemImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->OnGetItemImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, OnGetItemText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, OnGetItemText)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_ListCtrl, wxListCtrl);
	Gura_AssignMethod(wx_ListCtrl, wxListCtrl_1);
	Gura_AssignMethod(wx_ListCtrl, ~wxListCtrl);
	Gura_AssignMethod(wx_ListCtrl, AppendColumn);
	Gura_AssignMethod(wx_ListCtrl, Arrange);
	Gura_AssignMethod(wx_ListCtrl, AssignImageList);
	Gura_AssignMethod(wx_ListCtrl, ClearAll);
	Gura_AssignMethod(wx_ListCtrl, Create);
	Gura_AssignMethod(wx_ListCtrl, DeleteAllItems);
	Gura_AssignMethod(wx_ListCtrl, DeleteColumn);
	Gura_AssignMethod(wx_ListCtrl, DeleteItem);
	Gura_AssignMethod(wx_ListCtrl, EditLabel);
	Gura_AssignMethod(wx_ListCtrl, EnableAlternateRowColours);
	Gura_AssignMethod(wx_ListCtrl, EnableBellOnNoMatch);
	Gura_AssignMethod(wx_ListCtrl, EndEditLabel);
	Gura_AssignMethod(wx_ListCtrl, EnsureVisible);
	Gura_AssignMethod(wx_ListCtrl, FindItem);
	Gura_AssignMethod(wx_ListCtrl, FindItem_1);
	Gura_AssignMethod(wx_ListCtrl, FindItem_2);
	Gura_AssignMethod(wx_ListCtrl, GetColumn);
	Gura_AssignMethod(wx_ListCtrl, GetColumnCount);
	Gura_AssignMethod(wx_ListCtrl, GetColumnIndexFromOrder);
	Gura_AssignMethod(wx_ListCtrl, GetColumnOrder);
	Gura_AssignMethod(wx_ListCtrl, GetColumnWidth);
	Gura_AssignMethod(wx_ListCtrl, GetColumnsOrder);
	Gura_AssignMethod(wx_ListCtrl, GetCountPerPage);
	Gura_AssignMethod(wx_ListCtrl, GetEditControl);
	Gura_AssignMethod(wx_ListCtrl, GetImageList);
	Gura_AssignMethod(wx_ListCtrl, GetItem);
	Gura_AssignMethod(wx_ListCtrl, GetItemBackgroundColour);
	Gura_AssignMethod(wx_ListCtrl, GetItemCount);
	Gura_AssignMethod(wx_ListCtrl, GetItemData);
	Gura_AssignMethod(wx_ListCtrl, GetItemFont);
	Gura_AssignMethod(wx_ListCtrl, GetItemPosition);
	Gura_AssignMethod(wx_ListCtrl, GetItemRect);
	Gura_AssignMethod(wx_ListCtrl, GetItemSpacing);
	Gura_AssignMethod(wx_ListCtrl, GetItemState);
	Gura_AssignMethod(wx_ListCtrl, GetItemText);
	Gura_AssignMethod(wx_ListCtrl, GetItemTextColour);
	Gura_AssignMethod(wx_ListCtrl, GetNextItem);
	Gura_AssignMethod(wx_ListCtrl, GetSelectedItemCount);
	Gura_AssignMethod(wx_ListCtrl, GetSubItemRect);
	Gura_AssignMethod(wx_ListCtrl, GetTextColour);
	Gura_AssignMethod(wx_ListCtrl, GetTopItem);
	Gura_AssignMethod(wx_ListCtrl, GetViewRect);
	Gura_AssignMethod(wx_ListCtrl, SetAlternateRowColour);
	Gura_AssignMethod(wx_ListCtrl, GetAlternateRowColour);
	Gura_AssignMethod(wx_ListCtrl, HitTest);
	Gura_AssignMethod(wx_ListCtrl, InReportView);
	Gura_AssignMethod(wx_ListCtrl, InsertColumn);
	Gura_AssignMethod(wx_ListCtrl, InsertColumn_1);
	Gura_AssignMethod(wx_ListCtrl, InsertItem);
	Gura_AssignMethod(wx_ListCtrl, InsertItem_1);
	Gura_AssignMethod(wx_ListCtrl, InsertItem_2);
	Gura_AssignMethod(wx_ListCtrl, InsertItem_3);
	Gura_AssignMethod(wx_ListCtrl, IsVirtual);
	Gura_AssignMethod(wx_ListCtrl, RefreshItem);
	Gura_AssignMethod(wx_ListCtrl, RefreshItems);
	Gura_AssignMethod(wx_ListCtrl, ScrollList);
	Gura_AssignMethod(wx_ListCtrl, SetBackgroundColour);
	Gura_AssignMethod(wx_ListCtrl, SetColumn);
	Gura_AssignMethod(wx_ListCtrl, SetColumnWidth);
	Gura_AssignMethod(wx_ListCtrl, SetColumnsOrder);
	Gura_AssignMethod(wx_ListCtrl, SetImageList);
	Gura_AssignMethod(wx_ListCtrl, SetItem);
	Gura_AssignMethod(wx_ListCtrl, SetItem_1);
	Gura_AssignMethod(wx_ListCtrl, SetItemBackgroundColour);
	Gura_AssignMethod(wx_ListCtrl, SetItemColumnImage);
	Gura_AssignMethod(wx_ListCtrl, SetItemCount);
	Gura_AssignMethod(wx_ListCtrl, SetItemData);
	Gura_AssignMethod(wx_ListCtrl, SetItemFont);
	Gura_AssignMethod(wx_ListCtrl, SetItemImage);
	Gura_AssignMethod(wx_ListCtrl, SetItemPosition);
	Gura_AssignMethod(wx_ListCtrl, SetItemPtrData);
	Gura_AssignMethod(wx_ListCtrl, SetItemState);
	Gura_AssignMethod(wx_ListCtrl, SetItemText);
	Gura_AssignMethod(wx_ListCtrl, SetItemTextColour);
	Gura_AssignMethod(wx_ListCtrl, SetSingleStyle);
	Gura_AssignMethod(wx_ListCtrl, SetTextColour);
	Gura_AssignMethod(wx_ListCtrl, SetWindowStyleFlag);
	Gura_AssignMethod(wx_ListCtrl, SortItems);
	Gura_AssignMethod(wx_ListCtrl, HasCheckboxes);
	Gura_AssignMethod(wx_ListCtrl, EnableCheckboxes);
	Gura_AssignMethod(wx_ListCtrl, IsItemChecked);
	Gura_AssignMethod(wx_ListCtrl, CheckItem);
	Gura_AssignMethod(wx_ListCtrl, OnGetItemAttr);
	Gura_AssignMethod(wx_ListCtrl, OnGetItemColumnAttr);
	Gura_AssignMethod(wx_ListCtrl, OnGetItemColumnImage);
	Gura_AssignMethod(wx_ListCtrl, OnGetItemImage);
	Gura_AssignMethod(wx_ListCtrl, OnGetItemText);
}

Gura_ImplementDescendantCreator(wx_ListCtrl)
{
	return new Object_wx_ListCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
