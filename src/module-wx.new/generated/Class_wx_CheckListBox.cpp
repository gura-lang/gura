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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_CheckListBox, wxCheckListBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CheckListBox, wxCheckListBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_CheckListBox *pThis = Object_wx_CheckListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxCheckListBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CheckListBox, wxCheckListBox_1)
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

Gura_ImplementMethod(wx_CheckListBox, wxCheckListBox_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_CheckListBox *pThis = Object_wx_CheckListBox::GetObjectThis(arg);
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
	//pThis->GetEntity()->wxCheckListBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CheckListBox, wxCheckListBox_2)
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

Gura_ImplementMethod(wx_CheckListBox, wxCheckListBox_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_CheckListBox *pThis = Object_wx_CheckListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int choices = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->wxCheckListBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CheckListBox, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStrings", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CheckListBox, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_CheckListBox *pThis = Object_wx_CheckListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int nStrings = arg.GetNumber(4)
	//int choices = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CheckListBox, Create_1)
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

Gura_ImplementMethod(wx_CheckListBox, Create_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_CheckListBox *pThis = Object_wx_CheckListBox::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_CheckListBox, ~wxCheckListBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CheckListBox, ~wxCheckListBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_CheckListBox *pThis = Object_wx_CheckListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxCheckListBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CheckListBox, Check)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "check", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CheckListBox, Check)
{
	Signal &sig = env.GetSignal();
	Object_wx_CheckListBox *pThis = Object_wx_CheckListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int check = arg.GetNumber(1)
	//pThis->GetEntity()->Check();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CheckListBox, IsChecked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CheckListBox, IsChecked)
{
	Signal &sig = env.GetSignal();
	Object_wx_CheckListBox *pThis = Object_wx_CheckListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsChecked();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CheckListBox, GetCheckedItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "checkedItems", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CheckListBox, GetCheckedItems)
{
	Signal &sig = env.GetSignal();
	Object_wx_CheckListBox *pThis = Object_wx_CheckListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int checkedItems = arg.GetNumber(0)
	//pThis->GetEntity()->GetCheckedItems();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCheckListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CheckListBox)
{
	Gura_AssignMethod(wx_CheckListBox, wxCheckListBox);
	Gura_AssignMethod(wx_CheckListBox, wxCheckListBox_1);
	Gura_AssignMethod(wx_CheckListBox, wxCheckListBox_2);
	Gura_AssignMethod(wx_CheckListBox, Create);
	Gura_AssignMethod(wx_CheckListBox, Create_1);
	Gura_AssignMethod(wx_CheckListBox, ~wxCheckListBox);
	Gura_AssignMethod(wx_CheckListBox, Check);
	Gura_AssignMethod(wx_CheckListBox, IsChecked);
	Gura_AssignMethod(wx_CheckListBox, GetCheckedItems);
}

Gura_ImplementDescendantCreator(wx_CheckListBox)
{
	return new Object_wx_CheckListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
