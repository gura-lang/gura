//----------------------------------------------------------------------------
// wxCheckBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCheckBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCheckBox
//----------------------------------------------------------------------------
Object_wx_CheckBox::~Object_wx_CheckBox()
{
}

Object *Object_wx_CheckBox::Clone() const
{
	return nullptr;
}

String Object_wx_CheckBox::ToString(bool exprFlag)
{
	String rtn("<wx.CheckBox:");
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
Gura_DeclareFunctionAlias(__CheckBox, "CheckBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CheckBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CheckBox)
{
	//wxCheckBox();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CheckBox_1, "CheckBox_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CheckBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CheckBox_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxCheckBox(parent, id, label, pos, size, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CheckBox, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CheckBox, __Create)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, label, pos, size, style, validator, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CheckBox, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CheckBox, __GetValue)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CheckBox, __Get3StateValue, "Get3StateValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CheckBox, __Get3StateValue)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCheckBoxState _rtn = pThis->GetEntity()->Get3StateValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CheckBox, __Is3State, "Is3State")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CheckBox, __Is3State)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Is3State();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CheckBox, __Is3rdStateAllowedForUser, "Is3rdStateAllowedForUser")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CheckBox, __Is3rdStateAllowedForUser)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Is3rdStateAllowedForUser();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CheckBox, __IsChecked, "IsChecked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CheckBox, __IsChecked)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsChecked();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CheckBox, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CheckBox, __SetValue)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool state = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue(state);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CheckBox, __Set3StateValue, "Set3StateValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CheckBox, __Set3StateValue)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCheckBoxState state = arg.GetNumber(0)
	//pThis->GetEntity()->Set3StateValue(state);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCheckBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CheckBox)
{
	// Constructor assignment
	Gura_AssignFunction(__CheckBox);
	Gura_AssignFunction(__CheckBox_1);
	// Method assignment
	Gura_AssignMethod(wx_CheckBox, __Create);
	Gura_AssignMethod(wx_CheckBox, __GetValue);
	Gura_AssignMethod(wx_CheckBox, __Get3StateValue);
	Gura_AssignMethod(wx_CheckBox, __Is3State);
	Gura_AssignMethod(wx_CheckBox, __Is3rdStateAllowedForUser);
	Gura_AssignMethod(wx_CheckBox, __IsChecked);
	Gura_AssignMethod(wx_CheckBox, __SetValue);
	Gura_AssignMethod(wx_CheckBox, __Set3StateValue);
}

Gura_ImplementDescendantCreator(wx_CheckBox)
{
	return new Object_wx_CheckBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
