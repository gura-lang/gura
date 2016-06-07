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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RadioBox, "RadioBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RadioBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RadioBox)
{
	//wxRadioBox();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RadioBox_1, "RadioBox_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg6", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "majorDimension", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RadioBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RadioBox_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//int n = arg.GetNumber(5)
	//const wxString choices[] _arg6 = arg.GetNumber(6)
	//int majorDimension = arg.GetNumber(7)
	//long style = arg.GetNumber(8)
	//const wxValidator& validator = arg.GetNumber(9)
	//const wxString& name = arg.GetNumber(10)
	//wxRadioBox(parent, id, label, pos, size, n, _arg6, majorDimension, style, validator, name);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RadioBox_2, "RadioBox_2")
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
	SetClassToConstruct(Gura_UserClass(wx_RadioBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RadioBox_2)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//const wxArrayString& choices = arg.GetNumber(5)
	//int majorDimension = arg.GetNumber(6)
	//long style = arg.GetNumber(7)
	//const wxValidator& validator = arg.GetNumber(8)
	//const wxString& name = arg.GetNumber(9)
	//wxRadioBox(parent, id, label, pos, size, choices, majorDimension, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RadioBox, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg6", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "majorDimension", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, __Create)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//int n = arg.GetNumber(5)
	//const wxString choices[] _arg6 = arg.GetNumber(6)
	//int majorDimension = arg.GetNumber(7)
	//long style = arg.GetNumber(8)
	//const wxValidator& validator = arg.GetNumber(9)
	//const wxString& name = arg.GetNumber(10)
	//pThis->GetEntity()->Create(parent, id, label, pos, size, n, _arg6, majorDimension, style, validator, name);
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
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//const wxArrayString& choices = arg.GetNumber(5)
	//int majorDimension = arg.GetNumber(6)
	//long style = arg.GetNumber(7)
	//const wxValidator& validator = arg.GetNumber(8)
	//const wxString& name = arg.GetNumber(9)
	//pThis->GetEntity()->Create(parent, id, label, pos, size, choices, majorDimension, style, validator, name);
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
	//unsigned int n = arg.GetNumber(0)
	//bool enable = arg.GetNumber(1)
	//pThis->GetEntity()->Enable(n, enable);
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
	//const wxString& string = arg.GetNumber(0)
	//bool bCase = arg.GetNumber(1)
	//pThis->GetEntity()->FindString(string, bCase);
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
	//const wxPoint& pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemFromPoint(pt);
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
	//unsigned int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemHelpText(item);
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
	//unsigned int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemToolTip(item);
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
	//unsigned int n = arg.GetNumber(0)
	//pThis->GetEntity()->IsItemEnabled(n);
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
	//unsigned int n = arg.GetNumber(0)
	//pThis->GetEntity()->IsItemShown(n);
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
	//unsigned int item = arg.GetNumber(0)
	//const wxString& helptext = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemHelpText(item, helptext);
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
	//unsigned int item = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemToolTip(item, text);
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
	//pThis->GetEntity()->SetSelection(n);
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
	//unsigned int item = arg.GetNumber(0)
	//bool show = arg.GetNumber(1)
	//pThis->GetEntity()->Show(item, show);
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
	//unsigned int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetString(n);
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
	//unsigned int n = arg.GetNumber(0)
	//const wxString& string = arg.GetNumber(1)
	//pThis->GetEntity()->SetString(n, string);
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
	// Constructor assignment
	Gura_AssignFunction(__RadioBox);
	Gura_AssignFunction(__RadioBox_1);
	Gura_AssignFunction(__RadioBox_2);
	// Method assignment
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
