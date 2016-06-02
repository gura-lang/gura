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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_HeaderCtrl, wxHeaderCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrl, wxHeaderCtrl)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxHeaderCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, wxHeaderCtrl_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, wxHeaderCtrl_1)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxHeaderCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, Create)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, SetColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, SetColumnCount)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int count = arg.GetNumber(0)
	//pThis->GetEntity()->SetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, GetColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrl, GetColumnCount)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrl, IsEmpty)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, UpdateColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, UpdateColumn)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->UpdateColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, SetColumnsOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "order", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, SetColumnsOrder)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int order = arg.GetNumber(0)
	//pThis->GetEntity()->SetColumnsOrder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, GetColumnsOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrl, GetColumnsOrder)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumnsOrder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, GetColumnAt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, GetColumnAt)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnAt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, GetColumnPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, GetColumnPos)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, ResetColumnsOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrl, ResetColumnsOrder)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ResetColumnsOrder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, MoveColumnInOrderArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "order", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, MoveColumnInOrderArray)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int order = arg.GetNumber(0)
	//int idx = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//pThis->GetEntity()->MoveColumnInOrderArray();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, ShowColumnsMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, ShowColumnsMenu)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int title = arg.GetNumber(1)
	//pThis->GetEntity()->ShowColumnsMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, AddColumnsItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "idColumnsBase", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, AddColumnsItems)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//int idColumnsBase = arg.GetNumber(1)
	//pThis->GetEntity()->AddColumnsItems();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, ShowCustomizeDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrl, ShowCustomizeDialog)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShowCustomizeDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, GetColumnTitleWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, GetColumnTitleWidth)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnTitleWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, GetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, GetColumn)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, UpdateColumnVisibility)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, UpdateColumnVisibility)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//int show = arg.GetNumber(1)
	//pThis->GetEntity()->UpdateColumnVisibility();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, UpdateColumnsOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "order", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, UpdateColumnsOrder)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int order = arg.GetNumber(0)
	//pThis->GetEntity()->UpdateColumnsOrder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, UpdateColumnWidthToFit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "widthTitle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, UpdateColumnWidthToFit)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//int widthTitle = arg.GetNumber(1)
	//pThis->GetEntity()->UpdateColumnWidthToFit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrl, OnColumnCountChanging)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrl, OnColumnCountChanging)
{
	Object_wx_HeaderCtrl *pThis = Object_wx_HeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int count = arg.GetNumber(0)
	//pThis->GetEntity()->OnColumnCountChanging();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHeaderCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HeaderCtrl)
{
	Gura_AssignMethod(wx_HeaderCtrl, wxHeaderCtrl);
	Gura_AssignMethod(wx_HeaderCtrl, wxHeaderCtrl_1);
	Gura_AssignMethod(wx_HeaderCtrl, Create);
	Gura_AssignMethod(wx_HeaderCtrl, SetColumnCount);
	Gura_AssignMethod(wx_HeaderCtrl, GetColumnCount);
	Gura_AssignMethod(wx_HeaderCtrl, IsEmpty);
	Gura_AssignMethod(wx_HeaderCtrl, UpdateColumn);
	Gura_AssignMethod(wx_HeaderCtrl, SetColumnsOrder);
	Gura_AssignMethod(wx_HeaderCtrl, GetColumnsOrder);
	Gura_AssignMethod(wx_HeaderCtrl, GetColumnAt);
	Gura_AssignMethod(wx_HeaderCtrl, GetColumnPos);
	Gura_AssignMethod(wx_HeaderCtrl, ResetColumnsOrder);
	Gura_AssignMethod(wx_HeaderCtrl, MoveColumnInOrderArray);
	Gura_AssignMethod(wx_HeaderCtrl, ShowColumnsMenu);
	Gura_AssignMethod(wx_HeaderCtrl, AddColumnsItems);
	Gura_AssignMethod(wx_HeaderCtrl, ShowCustomizeDialog);
	Gura_AssignMethod(wx_HeaderCtrl, GetColumnTitleWidth);
	Gura_AssignMethod(wx_HeaderCtrl, GetColumn);
	Gura_AssignMethod(wx_HeaderCtrl, UpdateColumnVisibility);
	Gura_AssignMethod(wx_HeaderCtrl, UpdateColumnsOrder);
	Gura_AssignMethod(wx_HeaderCtrl, UpdateColumnWidthToFit);
	Gura_AssignMethod(wx_HeaderCtrl, OnColumnCountChanging);
}

Gura_ImplementDescendantCreator(wx_HeaderCtrl)
{
	return new Object_wx_HeaderCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
