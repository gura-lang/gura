//----------------------------------------------------------------------------
// wxRadioBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRadioBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRadioBox
//----------------------------------------------------------------------------
Object_wx_RadioBox::~Object_wx_RadioBox()
{
}

Object *Object_wx_RadioBox::Clone() const
{
	return nullptr;
}

String Object_wx_RadioBox::ToString(bool exprFlag)
{
	String rtn("<wx.RadioBox:");
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
Gura_DeclareMethod(wx_RadioBox, wxRadioBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RadioBox, wxRadioBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRadioBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, wxRadioBox_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "majorDimension", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, wxRadioBox_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int n = arg.GetNumber(5)
	//int choices = arg.GetNumber(6)
	//int majorDimension = arg.GetNumber(7)
	//int style = arg.GetNumber(8)
	//int validator = arg.GetNumber(9)
	//int name = arg.GetNumber(10)
	//pThis->GetEntity()->wxRadioBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, wxRadioBox_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "majorDimension", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, wxRadioBox_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int choices = arg.GetNumber(5)
	//int majorDimension = arg.GetNumber(6)
	//int style = arg.GetNumber(7)
	//int validator = arg.GetNumber(8)
	//int name = arg.GetNumber(9)
	//pThis->GetEntity()->wxRadioBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, ~wxRadioBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RadioBox, ~wxRadioBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxRadioBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "majorDimension", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int n = arg.GetNumber(5)
	//int choices = arg.GetNumber(6)
	//int majorDimension = arg.GetNumber(7)
	//int style = arg.GetNumber(8)
	//int validator = arg.GetNumber(9)
	//int name = arg.GetNumber(10)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, Create_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "majorDimension", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, Create_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int choices = arg.GetNumber(5)
	//int majorDimension = arg.GetNumber(6)
	//int style = arg.GetNumber(7)
	//int validator = arg.GetNumber(8)
	//int name = arg.GetNumber(9)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, Enable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, Enable)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int enable = arg.GetNumber(1)
	//pThis->GetEntity()->Enable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, FindString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bCase", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, FindString)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//int bCase = arg.GetNumber(1)
	//pThis->GetEntity()->FindString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, GetColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RadioBox, GetColumnCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, GetItemFromPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, GetItemFromPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemFromPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, GetItemHelpText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, GetItemHelpText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemHelpText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, GetItemToolTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, GetItemToolTip)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemToolTip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, GetRowCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RadioBox, GetRowCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRowCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, IsItemEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, IsItemEnabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->IsItemEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, IsItemShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, IsItemShown)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->IsItemShown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, SetItemHelpText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helptext", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, SetItemHelpText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int helptext = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemHelpText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, SetItemToolTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, SetItemToolTip)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemToolTip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int show = arg.GetNumber(1)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RadioBox, GetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, GetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, SetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, SetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int string = arg.GetNumber(1)
	//pThis->GetEntity()->SetString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RadioBox, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRadioBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RadioBox)
{
	Gura_AssignMethod(wx_RadioBox, wxRadioBox);
	Gura_AssignMethod(wx_RadioBox, wxRadioBox_1);
	Gura_AssignMethod(wx_RadioBox, wxRadioBox_2);
	Gura_AssignMethod(wx_RadioBox, ~wxRadioBox);
	Gura_AssignMethod(wx_RadioBox, Create);
	Gura_AssignMethod(wx_RadioBox, Create_1);
	Gura_AssignMethod(wx_RadioBox, Enable);
	Gura_AssignMethod(wx_RadioBox, FindString);
	Gura_AssignMethod(wx_RadioBox, GetColumnCount);
	Gura_AssignMethod(wx_RadioBox, GetItemFromPoint);
	Gura_AssignMethod(wx_RadioBox, GetItemHelpText);
	Gura_AssignMethod(wx_RadioBox, GetItemToolTip);
	Gura_AssignMethod(wx_RadioBox, GetRowCount);
	Gura_AssignMethod(wx_RadioBox, IsItemEnabled);
	Gura_AssignMethod(wx_RadioBox, IsItemShown);
	Gura_AssignMethod(wx_RadioBox, SetItemHelpText);
	Gura_AssignMethod(wx_RadioBox, SetItemToolTip);
	Gura_AssignMethod(wx_RadioBox, SetSelection);
	Gura_AssignMethod(wx_RadioBox, Show);
	Gura_AssignMethod(wx_RadioBox, GetCount);
	Gura_AssignMethod(wx_RadioBox, GetString);
	Gura_AssignMethod(wx_RadioBox, SetString);
	Gura_AssignMethod(wx_RadioBox, GetSelection);
}

Gura_ImplementDescendantCreator(wx_RadioBox)
{
	return new Object_wx_RadioBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
