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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_CheckBox, wxCheckBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CheckBox, wxCheckBox)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxCheckBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CheckBox, wxCheckBox_1)
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

Gura_ImplementMethod(wx_CheckBox, wxCheckBox_1)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->wxCheckBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CheckBox, Create)
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

Gura_ImplementMethod(wx_CheckBox, Create)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CheckBox, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CheckBox, GetValue)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CheckBox, Get3StateValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CheckBox, Get3StateValue)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Get3StateValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CheckBox, Is3State)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CheckBox, Is3State)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Is3State();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CheckBox, Is3rdStateAllowedForUser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CheckBox, Is3rdStateAllowedForUser)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Is3rdStateAllowedForUser();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CheckBox, IsChecked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CheckBox, IsChecked)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsChecked();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CheckBox, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CheckBox, SetValue)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int state = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CheckBox, Set3StateValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CheckBox, Set3StateValue)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int state = arg.GetNumber(0)
	//pThis->GetEntity()->Set3StateValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCheckBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CheckBox)
{
	Gura_AssignMethod(wx_CheckBox, wxCheckBox);
	Gura_AssignMethod(wx_CheckBox, wxCheckBox_1);
	Gura_AssignMethod(wx_CheckBox, Create);
	Gura_AssignMethod(wx_CheckBox, GetValue);
	Gura_AssignMethod(wx_CheckBox, Get3StateValue);
	Gura_AssignMethod(wx_CheckBox, Is3State);
	Gura_AssignMethod(wx_CheckBox, Is3rdStateAllowedForUser);
	Gura_AssignMethod(wx_CheckBox, IsChecked);
	Gura_AssignMethod(wx_CheckBox, SetValue);
	Gura_AssignMethod(wx_CheckBox, Set3StateValue);
}

Gura_ImplementDescendantCreator(wx_CheckBox)
{
	return new Object_wx_CheckBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
