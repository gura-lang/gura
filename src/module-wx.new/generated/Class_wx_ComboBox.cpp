//----------------------------------------------------------------------------
// wxComboBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxComboBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxComboBox
//----------------------------------------------------------------------------
Object_wx_ComboBox::~Object_wx_ComboBox()
{
}

Object *Object_wx_ComboBox::Clone() const
{
	return nullptr;
}

String Object_wx_ComboBox::ToString(bool exprFlag)
{
	String rtn("<wx.ComboBox:");
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
Gura_DeclareMethod(wx_ComboBox, wxComboBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, wxComboBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxComboBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, wxComboBox_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, wxComboBox_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int n = arg.GetNumber(5)
	//int choices = arg.GetNumber(6)
	//int style = arg.GetNumber(7)
	//int validator = arg.GetNumber(8)
	//int name = arg.GetNumber(9)
	//pThis->GetEntity()->wxComboBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, wxComboBox_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, wxComboBox_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int choices = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->wxComboBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, ~wxComboBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, ~wxComboBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxComboBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int n = arg.GetNumber(5)
	//int choices = arg.GetNumber(6)
	//int style = arg.GetNumber(7)
	//int validator = arg.GetNumber(8)
	//int name = arg.GetNumber(9)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, Create_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, Create_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int choices = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, GetCurrentSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, GetCurrentSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, GetInsertionPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, GetInsertionPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, IsEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, IsListEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, IsListEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsListEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, IsTextEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, IsTextEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsTextEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, Popup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, Popup)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Popup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, Dismiss)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, Dismiss)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Dismiss();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, GetSelection_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, GetSelection_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, SetSelection_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, SetSelection_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, FindString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bCase", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, FindString)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//int bCase = arg.GetNumber(1)
	//pThis->GetEntity()->FindString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, GetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, GetStringSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, GetStringSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStringSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, SetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, SetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->SetString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, GetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxComboBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ComboBox)
{
	Gura_AssignMethod(wx_ComboBox, wxComboBox);
	Gura_AssignMethod(wx_ComboBox, wxComboBox_1);
	Gura_AssignMethod(wx_ComboBox, wxComboBox_2);
	Gura_AssignMethod(wx_ComboBox, ~wxComboBox);
	Gura_AssignMethod(wx_ComboBox, Create);
	Gura_AssignMethod(wx_ComboBox, Create_1);
	Gura_AssignMethod(wx_ComboBox, GetCurrentSelection);
	Gura_AssignMethod(wx_ComboBox, GetInsertionPoint);
	Gura_AssignMethod(wx_ComboBox, IsEmpty);
	Gura_AssignMethod(wx_ComboBox, IsListEmpty);
	Gura_AssignMethod(wx_ComboBox, IsTextEmpty);
	Gura_AssignMethod(wx_ComboBox, SetSelection);
	Gura_AssignMethod(wx_ComboBox, SetValue);
	Gura_AssignMethod(wx_ComboBox, Popup);
	Gura_AssignMethod(wx_ComboBox, Dismiss);
	Gura_AssignMethod(wx_ComboBox, GetSelection);
	Gura_AssignMethod(wx_ComboBox, GetSelection_1);
	Gura_AssignMethod(wx_ComboBox, SetSelection_1);
	Gura_AssignMethod(wx_ComboBox, FindString);
	Gura_AssignMethod(wx_ComboBox, GetString);
	Gura_AssignMethod(wx_ComboBox, GetStringSelection);
	Gura_AssignMethod(wx_ComboBox, SetString);
	Gura_AssignMethod(wx_ComboBox, GetCount);
}

Gura_ImplementDescendantCreator(wx_ComboBox)
{
	return new Object_wx_ComboBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
