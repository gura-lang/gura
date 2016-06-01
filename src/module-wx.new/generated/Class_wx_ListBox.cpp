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
Gura_DeclareMethod(wx_ListBox, wxListBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListBox, wxListBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxListBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, wxListBox_1)
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

Gura_ImplementMethod(wx_ListBox, wxListBox_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_ListBox, wxListBox_2)
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

Gura_ImplementMethod(wx_ListBox, wxListBox_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_ListBox, ~wxListBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListBox, ~wxListBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxListBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, Create)
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

Gura_ImplementMethod(wx_ListBox, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_ListBox, Create_1)
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

Gura_ImplementMethod(wx_ListBox, Create_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_ListBox, Deselect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, Deselect)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->Deselect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListBox, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, SetStringSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, SetStringSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//int select = arg.GetNumber(1)
	//pThis->GetEntity()->SetStringSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, SetStringSelection_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, SetStringSelection_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->SetStringSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, GetSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selections", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, GetSelections)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int selections = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelections();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, HitTest)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int point = arg.GetNumber(0)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, HitTest_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, HitTest_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, InsertItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nItems", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, InsertItems)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int nItems = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//pThis->GetEntity()->InsertItems();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, InsertItems_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, InsertItems_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int items = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->InsertItems();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, IsSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, IsSelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->IsSelected();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, SetFirstItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, SetFirstItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetFirstItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, SetFirstItem_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, SetFirstItem_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//pThis->GetEntity()->SetFirstItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, EnsureVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, EnsureVisible)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, IsSorted)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListBox, IsSorted)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsSorted();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, GetCountPerPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListBox, GetCountPerPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCountPerPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, GetTopItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListBox, GetTopItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTopItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListBox, GetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, GetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, SetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, SetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int s = arg.GetNumber(1)
	//pThis->GetEntity()->SetString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListBox, FindString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bCase", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListBox, FindString)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListBox *pThis = Object_wx_ListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_ListBox, wxListBox);
	Gura_AssignMethod(wx_ListBox, wxListBox_1);
	Gura_AssignMethod(wx_ListBox, wxListBox_2);
	Gura_AssignMethod(wx_ListBox, ~wxListBox);
	Gura_AssignMethod(wx_ListBox, Create);
	Gura_AssignMethod(wx_ListBox, Create_1);
	Gura_AssignMethod(wx_ListBox, Deselect);
	Gura_AssignMethod(wx_ListBox, SetSelection);
	Gura_AssignMethod(wx_ListBox, GetSelection);
	Gura_AssignMethod(wx_ListBox, SetStringSelection);
	Gura_AssignMethod(wx_ListBox, SetStringSelection_1);
	Gura_AssignMethod(wx_ListBox, GetSelections);
	Gura_AssignMethod(wx_ListBox, HitTest);
	Gura_AssignMethod(wx_ListBox, HitTest_1);
	Gura_AssignMethod(wx_ListBox, InsertItems);
	Gura_AssignMethod(wx_ListBox, InsertItems_1);
	Gura_AssignMethod(wx_ListBox, IsSelected);
	Gura_AssignMethod(wx_ListBox, SetFirstItem);
	Gura_AssignMethod(wx_ListBox, SetFirstItem_1);
	Gura_AssignMethod(wx_ListBox, EnsureVisible);
	Gura_AssignMethod(wx_ListBox, IsSorted);
	Gura_AssignMethod(wx_ListBox, GetCountPerPage);
	Gura_AssignMethod(wx_ListBox, GetTopItem);
	Gura_AssignMethod(wx_ListBox, GetCount);
	Gura_AssignMethod(wx_ListBox, GetString);
	Gura_AssignMethod(wx_ListBox, SetString);
	Gura_AssignMethod(wx_ListBox, FindString);
}

Gura_ImplementDescendantCreator(wx_ListBox)
{
	return new Object_wx_ListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
