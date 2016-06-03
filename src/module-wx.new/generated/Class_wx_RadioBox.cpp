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
Gura_DeclareMethodAlias(wx_RadioBox, __wxRadioBox, "wxRadioBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RadioBox, __wxRadioBox)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRadioBox();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioBox, __wxRadioBox_1, "wxRadioBox_1")
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

Gura_ImplementMethod(wx_RadioBox, __wxRadioBox_1)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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

Gura_DeclareMethodAlias(wx_RadioBox, __wxRadioBox_2, "wxRadioBox_2")
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

Gura_ImplementMethod(wx_RadioBox, __wxRadioBox_2)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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

Gura_DeclareMethodAlias(wx_RadioBox, __Create, "Create")
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

Gura_ImplementMethod(wx_RadioBox, __Create)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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

Gura_DeclareMethodAlias(wx_RadioBox, __Create_1, "Create_1")
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

Gura_ImplementMethod(wx_RadioBox, __Create_1)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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

Gura_DeclareMethodAlias(wx_RadioBox, __Enable, "Enable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, __Enable)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int enable = arg.GetNumber(1)
	//pThis->GetEntity()->Enable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioBox, __FindString, "FindString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bCase", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, __FindString)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//int bCase = arg.GetNumber(1)
	//pThis->GetEntity()->FindString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioBox, __GetColumnCount, "GetColumnCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RadioBox, __GetColumnCount)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioBox, __GetItemFromPoint, "GetItemFromPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, __GetItemFromPoint)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemFromPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioBox, __GetItemHelpText, "GetItemHelpText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, __GetItemHelpText)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemHelpText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioBox, __GetItemToolTip, "GetItemToolTip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, __GetItemToolTip)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemToolTip();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioBox, __GetRowCount, "GetRowCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RadioBox, __GetRowCount)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRowCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioBox, __IsItemEnabled, "IsItemEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, __IsItemEnabled)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->IsItemEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioBox, __IsItemShown, "IsItemShown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, __IsItemShown)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->IsItemShown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioBox, __SetItemHelpText, "SetItemHelpText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helptext", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, __SetItemHelpText)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int helptext = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemHelpText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioBox, __SetItemToolTip, "SetItemToolTip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, __SetItemToolTip)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemToolTip();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioBox, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, __SetSelection)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioBox, __Show, "Show")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, __Show)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int show = arg.GetNumber(1)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioBox, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RadioBox, __GetCount)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioBox, __GetString, "GetString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, __GetString)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioBox, __SetString, "SetString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, __SetString)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int string = arg.GetNumber(1)
	//pThis->GetEntity()->SetString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioBox, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RadioBox, __GetSelection)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRadioBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RadioBox)
{
	Gura_AssignMethod(wx_RadioBox, __wxRadioBox);
	Gura_AssignMethod(wx_RadioBox, __wxRadioBox_1);
	Gura_AssignMethod(wx_RadioBox, __wxRadioBox_2);
	Gura_AssignMethod(wx_RadioBox, __Create);
	Gura_AssignMethod(wx_RadioBox, __Create_1);
	Gura_AssignMethod(wx_RadioBox, __Enable);
	Gura_AssignMethod(wx_RadioBox, __FindString);
	Gura_AssignMethod(wx_RadioBox, __GetColumnCount);
	Gura_AssignMethod(wx_RadioBox, __GetItemFromPoint);
	Gura_AssignMethod(wx_RadioBox, __GetItemHelpText);
	Gura_AssignMethod(wx_RadioBox, __GetItemToolTip);
	Gura_AssignMethod(wx_RadioBox, __GetRowCount);
	Gura_AssignMethod(wx_RadioBox, __IsItemEnabled);
	Gura_AssignMethod(wx_RadioBox, __IsItemShown);
	Gura_AssignMethod(wx_RadioBox, __SetItemHelpText);
	Gura_AssignMethod(wx_RadioBox, __SetItemToolTip);
	Gura_AssignMethod(wx_RadioBox, __SetSelection);
	Gura_AssignMethod(wx_RadioBox, __Show);
	Gura_AssignMethod(wx_RadioBox, __GetCount);
	Gura_AssignMethod(wx_RadioBox, __GetString);
	Gura_AssignMethod(wx_RadioBox, __SetString);
	Gura_AssignMethod(wx_RadioBox, __GetSelection);
}

Gura_ImplementDescendantCreator(wx_RadioBox)
{
	return new Object_wx_RadioBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
