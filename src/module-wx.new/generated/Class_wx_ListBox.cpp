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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__ListBox, "ListBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ListBox)
{
	//wxListBox();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__ListBox_1, "ListBox_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg5", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ListBox_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//int n = arg.GetNumber(4)
	//const wxString choices[] _arg5 = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//wxListBox(parent, id, pos, size, n, _arg5, style, validator, name);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__ListBox_2, "ListBox_2")
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
	SetClassToConstruct(Gura_UserClass(wx_ListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ListBox_2)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//const wxArrayString& choices = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxListBox(parent, id, pos, size, choices, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ListBox, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg5", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, __Create)
{
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//int n = arg.GetNumber(4)
	//const wxString choices[] _arg5 = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//pThis->GetEntity()->Create(parent, id, pos, size, n, _arg5, style, validator, name);
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
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//const wxArrayString& choices = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//pThis->GetEntity()->Create(parent, id, pos, size, choices, style, validator, name);
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
	//pThis->GetEntity()->Deselect(n);
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
	//pThis->GetEntity()->SetSelection(n);
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
	//const wxString& s = arg.GetNumber(0)
	//bool select = arg.GetNumber(1)
	//pThis->GetEntity()->SetStringSelection(s, select);
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
	//const wxString& s = arg.GetNumber(0)
	//pThis->GetEntity()->SetStringSelection(s);
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
	//wxArrayInt& selections = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelections(selections);
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
	//const wxPoint& point = arg.GetNumber(0)
	//pThis->GetEntity()->HitTest(point);
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
	//pThis->GetEntity()->HitTest(x, y);
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
	//unsigned int nItems = arg.GetNumber(0)
	//const wxString* items = arg.GetNumber(1)
	//unsigned int pos = arg.GetNumber(2)
	//pThis->GetEntity()->InsertItems(nItems, items, pos);
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
	//const wxArrayString& items = arg.GetNumber(0)
	//unsigned int pos = arg.GetNumber(1)
	//pThis->GetEntity()->InsertItems(items, pos);
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
	//pThis->GetEntity()->IsSelected(n);
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
	//pThis->GetEntity()->SetFirstItem(n);
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
	//const wxString& string = arg.GetNumber(0)
	//pThis->GetEntity()->SetFirstItem(string);
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
	//pThis->GetEntity()->EnsureVisible(n);
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
	//unsigned int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetString(n);
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
	//unsigned int n = arg.GetNumber(0)
	//const wxString& s = arg.GetNumber(1)
	//pThis->GetEntity()->SetString(n, s);
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
	//const wxString& s = arg.GetNumber(0)
	//bool bCase = arg.GetNumber(1)
	//pThis->GetEntity()->FindString(s, bCase);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListBox)
{
	// Constructor assignment
	Gura_AssignFunction(__ListBox);
	Gura_AssignFunction(__ListBox_1);
	Gura_AssignFunction(__ListBox_2);
	// Method assignment
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
