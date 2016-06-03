//----------------------------------------------------------------------------
// wxListBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxListBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxListBox
//----------------------------------------------------------------------------
Object_wx_ListBox::~Object_wx_ListBox()
{
}

Object *Object_wx_ListBox::Clone() const
{
	return nullptr;
}

String Object_wx_ListBox::ToString(bool exprFlag)
{
	String rtn("<wx.ListBox:");
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
Gura_DeclareMethodAlias(wx_ListBox, __wxListBox, "wxListBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListBox, __wxListBox)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxListBox();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __wxListBox_1, "wxListBox_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __wxListBox_1)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int n = arg.GetNumber(4)
	//int choices = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->wxListBox();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __wxListBox_2, "wxListBox_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __wxListBox_2)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int choices = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->wxListBox();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __Create)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int n = arg.GetNumber(4)
	//int choices = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __Create_1, "Create_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __Create_1)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int choices = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __Deselect, "Deselect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __Deselect)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->Deselect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __SetSelection)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListBox, __GetSelection)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __SetStringSelection, "SetStringSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __SetStringSelection)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//int select = arg.GetNumber(1)
	//pThis->GetEntity()->SetStringSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __SetStringSelection_1, "SetStringSelection_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __SetStringSelection_1)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->SetStringSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __GetSelections, "GetSelections")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selections", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __GetSelections)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selections = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelections();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __HitTest, "HitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __HitTest)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int point = arg.GetNumber(0)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __HitTest_1, "HitTest_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __HitTest_1)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __InsertItems, "InsertItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nItems", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __InsertItems)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nItems = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//pThis->GetEntity()->InsertItems();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __InsertItems_1, "InsertItems_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __InsertItems_1)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int items = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->InsertItems();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __IsSelected, "IsSelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __IsSelected)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->IsSelected();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __SetFirstItem, "SetFirstItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __SetFirstItem)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetFirstItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __SetFirstItem_1, "SetFirstItem_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __SetFirstItem_1)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//pThis->GetEntity()->SetFirstItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __EnsureVisible, "EnsureVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __EnsureVisible)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __IsSorted, "IsSorted")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListBox, __IsSorted)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSorted();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __GetCountPerPage, "GetCountPerPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListBox, __GetCountPerPage)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCountPerPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __GetTopItem, "GetTopItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListBox, __GetTopItem)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListBox, __GetCount)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __GetString, "GetString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __GetString)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __SetString, "SetString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __SetString)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int s = arg.GetNumber(1)
	//pThis->GetEntity()->SetString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListBox, __FindString, "FindString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bCase", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __FindString)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//int bCase = arg.GetNumber(1)
	//pThis->GetEntity()->FindString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListBox)
{
	Gura_AssignMethod(wx_ListBox, __wxListBox);
	Gura_AssignMethod(wx_ListBox, __wxListBox_1);
	Gura_AssignMethod(wx_ListBox, __wxListBox_2);
	Gura_AssignMethod(wx_ListBox, __Create);
	Gura_AssignMethod(wx_ListBox, __Create_1);
	Gura_AssignMethod(wx_ListBox, __Deselect);
	Gura_AssignMethod(wx_ListBox, __SetSelection);
	Gura_AssignMethod(wx_ListBox, __GetSelection);
	Gura_AssignMethod(wx_ListBox, __SetStringSelection);
	Gura_AssignMethod(wx_ListBox, __SetStringSelection_1);
	Gura_AssignMethod(wx_ListBox, __GetSelections);
	Gura_AssignMethod(wx_ListBox, __HitTest);
	Gura_AssignMethod(wx_ListBox, __HitTest_1);
	Gura_AssignMethod(wx_ListBox, __InsertItems);
	Gura_AssignMethod(wx_ListBox, __InsertItems_1);
	Gura_AssignMethod(wx_ListBox, __IsSelected);
	Gura_AssignMethod(wx_ListBox, __SetFirstItem);
	Gura_AssignMethod(wx_ListBox, __SetFirstItem_1);
	Gura_AssignMethod(wx_ListBox, __EnsureVisible);
	Gura_AssignMethod(wx_ListBox, __IsSorted);
	Gura_AssignMethod(wx_ListBox, __GetCountPerPage);
	Gura_AssignMethod(wx_ListBox, __GetTopItem);
	Gura_AssignMethod(wx_ListBox, __GetCount);
	Gura_AssignMethod(wx_ListBox, __GetString);
	Gura_AssignMethod(wx_ListBox, __SetString);
	Gura_AssignMethod(wx_ListBox, __FindString);
}

Gura_ImplementDescendantCreator(wx_ListBox)
{
	return new Object_wx_ListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
