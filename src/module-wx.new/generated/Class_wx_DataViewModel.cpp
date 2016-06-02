//----------------------------------------------------------------------------
// wxDataViewModel
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewModel
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewModel
//----------------------------------------------------------------------------
Object_wx_DataViewModel::~Object_wx_DataViewModel()
{
}

Object *Object_wx_DataViewModel::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewModel::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewModel:");
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
Gura_DeclareMethod(wx_DataViewModel, wxDataViewModel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModel, wxDataViewModel)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxDataViewModel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, AddNotifier)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "notifier", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, AddNotifier)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int notifier = arg.GetNumber(0)
	//pThis->GetEntity()->AddNotifier();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, ChangeValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, ChangeValue)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int variant = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->ChangeValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, Cleared)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModel, Cleared)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Cleared();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, Compare)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ascending", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, Compare)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item1 = arg.GetNumber(0)
	//int item2 = arg.GetNumber(1)
	//int column = arg.GetNumber(2)
	//int ascending = arg.GetNumber(3)
	//pThis->GetEntity()->Compare();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, GetAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, GetAttr)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int attr = arg.GetNumber(2)
	//pThis->GetEntity()->GetAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, IsEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, IsEnabled)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->IsEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, GetChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "children", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, GetChildren)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int children = arg.GetNumber(1)
	//pThis->GetEntity()->GetChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, GetColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModel, GetColumnCount)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, GetColumnType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, GetColumnType)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, GetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, GetParent)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, GetValue)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int variant = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, HasContainerColumns)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, HasContainerColumns)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->HasContainerColumns();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, HasDefaultCompare)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModel, HasDefaultCompare)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasDefaultCompare();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, HasValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, HasValue)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->HasValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, IsContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, IsContainer)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, ItemAdded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, ItemAdded)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->ItemAdded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, ItemChanged)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, ItemChanged)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->ItemChanged();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, ItemDeleted)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, ItemDeleted)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->ItemDeleted();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, ItemsAdded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, ItemsAdded)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//pThis->GetEntity()->ItemsAdded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, ItemsChanged)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, ItemsChanged)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int items = arg.GetNumber(0)
	//pThis->GetEntity()->ItemsChanged();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, ItemsDeleted)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, ItemsDeleted)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//pThis->GetEntity()->ItemsDeleted();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, RemoveNotifier)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "notifier", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, RemoveNotifier)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int notifier = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveNotifier();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, Resort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModel, Resort)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Resort();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, SetValue)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int variant = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, ValueChanged)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, ValueChanged)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->ValueChanged();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, IsListModel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModel, IsListModel)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsListModel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModel, IsVirtualListModel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModel, IsVirtualListModel)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsVirtualListModel();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewModel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewModel)
{
	Gura_AssignMethod(wx_DataViewModel, wxDataViewModel);
	Gura_AssignMethod(wx_DataViewModel, AddNotifier);
	Gura_AssignMethod(wx_DataViewModel, ChangeValue);
	Gura_AssignMethod(wx_DataViewModel, Cleared);
	Gura_AssignMethod(wx_DataViewModel, Compare);
	Gura_AssignMethod(wx_DataViewModel, GetAttr);
	Gura_AssignMethod(wx_DataViewModel, IsEnabled);
	Gura_AssignMethod(wx_DataViewModel, GetChildren);
	Gura_AssignMethod(wx_DataViewModel, GetColumnCount);
	Gura_AssignMethod(wx_DataViewModel, GetColumnType);
	Gura_AssignMethod(wx_DataViewModel, GetParent);
	Gura_AssignMethod(wx_DataViewModel, GetValue);
	Gura_AssignMethod(wx_DataViewModel, HasContainerColumns);
	Gura_AssignMethod(wx_DataViewModel, HasDefaultCompare);
	Gura_AssignMethod(wx_DataViewModel, HasValue);
	Gura_AssignMethod(wx_DataViewModel, IsContainer);
	Gura_AssignMethod(wx_DataViewModel, ItemAdded);
	Gura_AssignMethod(wx_DataViewModel, ItemChanged);
	Gura_AssignMethod(wx_DataViewModel, ItemDeleted);
	Gura_AssignMethod(wx_DataViewModel, ItemsAdded);
	Gura_AssignMethod(wx_DataViewModel, ItemsChanged);
	Gura_AssignMethod(wx_DataViewModel, ItemsDeleted);
	Gura_AssignMethod(wx_DataViewModel, RemoveNotifier);
	Gura_AssignMethod(wx_DataViewModel, Resort);
	Gura_AssignMethod(wx_DataViewModel, SetValue);
	Gura_AssignMethod(wx_DataViewModel, ValueChanged);
	Gura_AssignMethod(wx_DataViewModel, IsListModel);
	Gura_AssignMethod(wx_DataViewModel, IsVirtualListModel);
}

Gura_ImplementDescendantCreator(wx_DataViewModel)
{
	return new Object_wx_DataViewModel((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
