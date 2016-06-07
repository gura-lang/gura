//----------------------------------------------------------------------------
// wxHeaderCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHeaderCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHeaderCtrl
//----------------------------------------------------------------------------
Object_wx_HeaderCtrl::~Object_wx_HeaderCtrl()
{
}

Object *Object_wx_HeaderCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_HeaderCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.HeaderCtrl:");
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
Gura_DeclareFunctionAlias(__HeaderCtrl, "HeaderCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HeaderCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HeaderCtrl)
{
	//wxHeaderCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__HeaderCtrl_1, "HeaderCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HeaderCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HeaderCtrl_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID winid = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxHeaderCtrl(parent, winid, pos, size, style, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HeaderCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, __Create)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID winid = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//pThis->GetEntity()->Create(parent, winid, pos, size, style, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __SetColumnCount, "SetColumnCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, __SetColumnCount)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int count = arg.GetNumber(0)
	//pThis->GetEntity()->SetColumnCount(count);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __GetColumnCount, "GetColumnCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrl, __GetColumnCount)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrl, __IsEmpty)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __UpdateColumn, "UpdateColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, __UpdateColumn)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int idx = arg.GetNumber(0)
	//pThis->GetEntity()->UpdateColumn(idx);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __SetColumnsOrder, "SetColumnsOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "order", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, __SetColumnsOrder)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayInt& order = arg.GetNumber(0)
	//pThis->GetEntity()->SetColumnsOrder(order);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __GetColumnsOrder, "GetColumnsOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrl, __GetColumnsOrder)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumnsOrder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __GetColumnAt, "GetColumnAt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, __GetColumnAt)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnAt(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __GetColumnPos, "GetColumnPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, __GetColumnPos)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int idx = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnPos(idx);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __ResetColumnsOrder, "ResetColumnsOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrl, __ResetColumnsOrder)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ResetColumnsOrder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __MoveColumnInOrderArray, "MoveColumnInOrderArray")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "order", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, __MoveColumnInOrderArray)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArrayInt& order = arg.GetNumber(0)
	//unsigned int idx = arg.GetNumber(1)
	//unsigned int pos = arg.GetNumber(2)
	//pThis->GetEntity()->MoveColumnInOrderArray(order, idx, pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __ShowColumnsMenu, "ShowColumnsMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, __ShowColumnsMenu)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//const wxString& title = arg.GetNumber(1)
	//pThis->GetEntity()->ShowColumnsMenu(pt, title);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __AddColumnsItems, "AddColumnsItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "idColumnsBase", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, __AddColumnsItems)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMenu& menu = arg.GetNumber(0)
	//int idColumnsBase = arg.GetNumber(1)
	//pThis->GetEntity()->AddColumnsItems(menu, idColumnsBase);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __ShowCustomizeDialog, "ShowCustomizeDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrl, __ShowCustomizeDialog)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShowCustomizeDialog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __GetColumnTitleWidth, "GetColumnTitleWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, __GetColumnTitleWidth)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxHeaderColumn& col = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnTitleWidth(col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __GetColumn, "GetColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, __GetColumn)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int idx = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumn(idx);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __UpdateColumnVisibility, "UpdateColumnVisibility")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, __UpdateColumnVisibility)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int idx = arg.GetNumber(0)
	//bool show = arg.GetNumber(1)
	//pThis->GetEntity()->UpdateColumnVisibility(idx, show);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __UpdateColumnsOrder, "UpdateColumnsOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "order", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, __UpdateColumnsOrder)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayInt& order = arg.GetNumber(0)
	//pThis->GetEntity()->UpdateColumnsOrder(order);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __UpdateColumnWidthToFit, "UpdateColumnWidthToFit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "widthTitle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, __UpdateColumnWidthToFit)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int idx = arg.GetNumber(0)
	//int widthTitle = arg.GetNumber(1)
	//pThis->GetEntity()->UpdateColumnWidthToFit(idx, widthTitle);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrl, __OnColumnCountChanging, "OnColumnCountChanging")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, __OnColumnCountChanging)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int count = arg.GetNumber(0)
	//pThis->GetEntity()->OnColumnCountChanging(count);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHeaderCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HeaderCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__HeaderCtrl);
	Gura_AssignFunction(__HeaderCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_HeaderCtrl, __Create);
	Gura_AssignMethod(wx_HeaderCtrl, __SetColumnCount);
	Gura_AssignMethod(wx_HeaderCtrl, __GetColumnCount);
	Gura_AssignMethod(wx_HeaderCtrl, __IsEmpty);
	Gura_AssignMethod(wx_HeaderCtrl, __UpdateColumn);
	Gura_AssignMethod(wx_HeaderCtrl, __SetColumnsOrder);
	Gura_AssignMethod(wx_HeaderCtrl, __GetColumnsOrder);
	Gura_AssignMethod(wx_HeaderCtrl, __GetColumnAt);
	Gura_AssignMethod(wx_HeaderCtrl, __GetColumnPos);
	Gura_AssignMethod(wx_HeaderCtrl, __ResetColumnsOrder);
	Gura_AssignMethod(wx_HeaderCtrl, __MoveColumnInOrderArray);
	Gura_AssignMethod(wx_HeaderCtrl, __ShowColumnsMenu);
	Gura_AssignMethod(wx_HeaderCtrl, __AddColumnsItems);
	Gura_AssignMethod(wx_HeaderCtrl, __ShowCustomizeDialog);
	Gura_AssignMethod(wx_HeaderCtrl, __GetColumnTitleWidth);
	Gura_AssignMethod(wx_HeaderCtrl, __GetColumn);
	Gura_AssignMethod(wx_HeaderCtrl, __UpdateColumnVisibility);
	Gura_AssignMethod(wx_HeaderCtrl, __UpdateColumnsOrder);
	Gura_AssignMethod(wx_HeaderCtrl, __UpdateColumnWidthToFit);
	Gura_AssignMethod(wx_HeaderCtrl, __OnColumnCountChanging);
}

Gura_ImplementDescendantCreator(wx_HeaderCtrl)
{
	return new Object_wx_HeaderCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
