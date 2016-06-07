//----------------------------------------------------------------------------
// wxCheckListBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCheckListBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCheckListBox
//----------------------------------------------------------------------------
Object_wx_CheckListBox::~Object_wx_CheckListBox()
{
}

Object *Object_wx_CheckListBox::Clone() const
{
	return nullptr;
}

String Object_wx_CheckListBox::ToString(bool exprFlag)
{
	String rtn("<wx.CheckListBox:");
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
Gura_DeclareFunctionAlias(__CheckListBox, "CheckListBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CheckListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CheckListBox)
{
	//wxCheckListBox();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CheckListBox_1, "CheckListBox_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg5", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CheckListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CheckListBox_1)
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
	//wxCheckListBox(parent, id, pos, size, n, _arg5, style, validator, name);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CheckListBox_2, "CheckListBox_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CheckListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CheckListBox_2)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//const wxArrayString& choices = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxCheckListBox(parent, id, pos, size, choices, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CheckListBox, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStrings", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg5", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CheckListBox, __Create)
{
	Object_wx_CheckListBox *pThis = Object_wx_CheckListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//int nStrings = arg.GetNumber(4)
	//const wxString choices[] _arg5 = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, pos, size, nStrings, _arg5, style, validator, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CheckListBox, __Create_1, "Create_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CheckListBox, __Create_1)
{
	Object_wx_CheckListBox *pThis = Object_wx_CheckListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//const wxArrayString& choices = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, pos, size, choices, style, validator, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CheckListBox, __Check, "Check")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "check", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CheckListBox, __Check)
{
	Object_wx_CheckListBox *pThis = Object_wx_CheckListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int item = arg.GetNumber(0)
	//bool check = arg.GetNumber(1)
	//pThis->GetEntity()->Check(item, check);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CheckListBox, __IsChecked, "IsChecked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CheckListBox, __IsChecked)
{
	Object_wx_CheckListBox *pThis = Object_wx_CheckListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int item = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsChecked(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CheckListBox, __GetCheckedItems, "GetCheckedItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "checkedItems", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CheckListBox, __GetCheckedItems)
{
	Object_wx_CheckListBox *pThis = Object_wx_CheckListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArrayInt& checkedItems = arg.GetNumber(0)
	//unsigned int _rtn = pThis->GetEntity()->GetCheckedItems(checkedItems);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCheckListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CheckListBox)
{
	// Constructor assignment
	Gura_AssignFunction(__CheckListBox);
	Gura_AssignFunction(__CheckListBox_1);
	Gura_AssignFunction(__CheckListBox_2);
	// Method assignment
	Gura_AssignMethod(wx_CheckListBox, __Create);
	Gura_AssignMethod(wx_CheckListBox, __Create_1);
	Gura_AssignMethod(wx_CheckListBox, __Check);
	Gura_AssignMethod(wx_CheckListBox, __IsChecked);
	Gura_AssignMethod(wx_CheckListBox, __GetCheckedItems);
}

Gura_ImplementDescendantCreator(wx_CheckListBox)
{
	return new Object_wx_CheckListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
