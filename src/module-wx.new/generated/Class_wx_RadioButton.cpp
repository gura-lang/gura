//----------------------------------------------------------------------------
// wxRadioButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRadioButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRadioButton
//----------------------------------------------------------------------------
Object_wx_RadioButton::~Object_wx_RadioButton()
{
}

Object *Object_wx_RadioButton::Clone() const
{
	return nullptr;
}

String Object_wx_RadioButton::ToString(bool exprFlag)
{
	String rtn("<wx.RadioButton:");
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
Gura_DeclareFunctionAlias(__RadioButton, "RadioButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RadioButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RadioButton)
{
	//wxRadioButton();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RadioButton_1, "RadioButton_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RadioButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RadioButton_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxRadioButton();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RadioButton, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioButton, __Create)
{
	Object_wx_RadioButton *pThis = Object_wx_RadioButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioButton, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RadioButton, __GetValue)
{
	Object_wx_RadioButton *pThis = Object_wx_RadioButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RadioButton, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioButton, __SetValue)
{
	Object_wx_RadioButton *pThis = Object_wx_RadioButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRadioButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RadioButton)
{
	// Constructor assignment
	Gura_AssignFunction(__RadioButton);
	Gura_AssignFunction(__RadioButton_1);
	// Method assignment
	Gura_AssignMethod(wx_RadioButton, __Create);
	Gura_AssignMethod(wx_RadioButton, __GetValue);
	Gura_AssignMethod(wx_RadioButton, __SetValue);
}

Gura_ImplementDescendantCreator(wx_RadioButton)
{
	return new Object_wx_RadioButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
