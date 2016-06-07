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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__DataViewModel, "DataViewModel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DataViewModel));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DataViewModel)
{
	//wxDataViewModel();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataViewModel, __AddNotifier, "AddNotifier")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "notifier", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __AddNotifier)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataViewModelNotifier* notifier = arg.GetNumber(0)
	//pThis->GetEntity()->AddNotifier(notifier);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __ChangeValue, "ChangeValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __ChangeValue)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxVariant& variant = arg.GetNumber(0)
	//const wxDataViewItem& item = arg.GetNumber(1)
	//unsigned int col = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->ChangeValue(variant, item, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __Cleared, "Cleared")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModel, __Cleared)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Cleared();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __Compare, "Compare")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ascending", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __Compare)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item1 = arg.GetNumber(0)
	//const wxDataViewItem& item2 = arg.GetNumber(1)
	//unsigned int column = arg.GetNumber(2)
	//bool ascending = arg.GetNumber(3)
	//int _rtn = pThis->GetEntity()->Compare(item1, item2, column, ascending);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __GetAttr, "GetAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __GetAttr)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//unsigned int col = arg.GetNumber(1)
	//wxDataViewItemAttr& attr = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->GetAttr(item, col, attr);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __IsEnabled, "IsEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __IsEnabled)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//unsigned int col = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->IsEnabled(item, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __GetChildren, "GetChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "children", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __GetChildren)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//wxDataViewItemArray& children = arg.GetNumber(1)
	//unsigned int _rtn = pThis->GetEntity()->GetChildren(item, children);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __GetColumnCount, "GetColumnCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModel, __GetColumnCount)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int _rtn = pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __GetColumnType, "GetColumnType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __GetColumnType)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int col = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetColumnType(col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __GetParent, "GetParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __GetParent)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//wxDataViewItem _rtn = pThis->GetEntity()->GetParent(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __GetValue)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariant& variant = arg.GetNumber(0)
	//const wxDataViewItem& item = arg.GetNumber(1)
	//unsigned int col = arg.GetNumber(2)
	//pThis->GetEntity()->GetValue(variant, item, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __HasContainerColumns, "HasContainerColumns")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __HasContainerColumns)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->HasContainerColumns(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __HasDefaultCompare, "HasDefaultCompare")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModel, __HasDefaultCompare)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasDefaultCompare();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __HasValue, "HasValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __HasValue)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//unsigned col = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->HasValue(item, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __IsContainer, "IsContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __IsContainer)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsContainer(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __ItemAdded, "ItemAdded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __ItemAdded)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//const wxDataViewItem& item = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->ItemAdded(parent, item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __ItemChanged, "ItemChanged")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __ItemChanged)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->ItemChanged(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __ItemDeleted, "ItemDeleted")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __ItemDeleted)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//const wxDataViewItem& item = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->ItemDeleted(parent, item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __ItemsAdded, "ItemsAdded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __ItemsAdded)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//const wxDataViewItemArray& items = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->ItemsAdded(parent, items);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __ItemsChanged, "ItemsChanged")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __ItemsChanged)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItemArray& items = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->ItemsChanged(items);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __ItemsDeleted, "ItemsDeleted")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __ItemsDeleted)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//const wxDataViewItemArray& items = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->ItemsDeleted(parent, items);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __RemoveNotifier, "RemoveNotifier")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "notifier", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __RemoveNotifier)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataViewModelNotifier* notifier = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveNotifier(notifier);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __Resort, "Resort")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModel, __Resort)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Resort();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __SetValue)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxVariant& variant = arg.GetNumber(0)
	//const wxDataViewItem& item = arg.GetNumber(1)
	//unsigned int col = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->SetValue(variant, item, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __ValueChanged, "ValueChanged")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModel, __ValueChanged)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//unsigned int col = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->ValueChanged(item, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __IsListModel, "IsListModel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModel, __IsListModel)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsListModel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModel, __IsVirtualListModel, "IsVirtualListModel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModel, __IsVirtualListModel)
{
	Object_wx_DataViewModel *pThis = Object_wx_DataViewModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsVirtualListModel();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewModel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewModel)
{
	// Constructor assignment
	Gura_AssignFunction(__DataViewModel);
	// Method assignment
	Gura_AssignMethod(wx_DataViewModel, __AddNotifier);
	Gura_AssignMethod(wx_DataViewModel, __ChangeValue);
	Gura_AssignMethod(wx_DataViewModel, __Cleared);
	Gura_AssignMethod(wx_DataViewModel, __Compare);
	Gura_AssignMethod(wx_DataViewModel, __GetAttr);
	Gura_AssignMethod(wx_DataViewModel, __IsEnabled);
	Gura_AssignMethod(wx_DataViewModel, __GetChildren);
	Gura_AssignMethod(wx_DataViewModel, __GetColumnCount);
	Gura_AssignMethod(wx_DataViewModel, __GetColumnType);
	Gura_AssignMethod(wx_DataViewModel, __GetParent);
	Gura_AssignMethod(wx_DataViewModel, __GetValue);
	Gura_AssignMethod(wx_DataViewModel, __HasContainerColumns);
	Gura_AssignMethod(wx_DataViewModel, __HasDefaultCompare);
	Gura_AssignMethod(wx_DataViewModel, __HasValue);
	Gura_AssignMethod(wx_DataViewModel, __IsContainer);
	Gura_AssignMethod(wx_DataViewModel, __ItemAdded);
	Gura_AssignMethod(wx_DataViewModel, __ItemChanged);
	Gura_AssignMethod(wx_DataViewModel, __ItemDeleted);
	Gura_AssignMethod(wx_DataViewModel, __ItemsAdded);
	Gura_AssignMethod(wx_DataViewModel, __ItemsChanged);
	Gura_AssignMethod(wx_DataViewModel, __ItemsDeleted);
	Gura_AssignMethod(wx_DataViewModel, __RemoveNotifier);
	Gura_AssignMethod(wx_DataViewModel, __Resort);
	Gura_AssignMethod(wx_DataViewModel, __SetValue);
	Gura_AssignMethod(wx_DataViewModel, __ValueChanged);
	Gura_AssignMethod(wx_DataViewModel, __IsListModel);
	Gura_AssignMethod(wx_DataViewModel, __IsVirtualListModel);
}

Gura_ImplementDescendantCreator(wx_DataViewModel)
{
	return new Object_wx_DataViewModel((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
