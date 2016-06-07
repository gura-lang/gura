//----------------------------------------------------------------------------
// wxDatePickerCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDatePickerCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDatePickerCtrl
//----------------------------------------------------------------------------
Object_wx_DatePickerCtrl::~Object_wx_DatePickerCtrl()
{
}

Object *Object_wx_DatePickerCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_DatePickerCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.DatePickerCtrl:");
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
Gura_DeclareFunctionAlias(__DatePickerCtrl, "DatePickerCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DatePickerCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DatePickerCtrl)
{
	//wxDatePickerCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DatePickerCtrl_1, "DatePickerCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DatePickerCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DatePickerCtrl_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxDateTime& dt = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxDatePickerCtrl(parent, id, dt, pos, size, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DatePickerCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DatePickerCtrl, __Create)
{
	Object_wx_DatePickerCtrl *pThis = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxDateTime& dt = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//pThis->GetEntity()->Create(parent, id, dt, pos, size, style, validator, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DatePickerCtrl, __GetRange, "GetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dt1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DatePickerCtrl, __GetRange)
{
	Object_wx_DatePickerCtrl *pThis = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDateTime* dt1 = arg.GetNumber(0)
	//wxDateTime* dt2 = arg.GetNumber(1)
	//pThis->GetEntity()->GetRange(dt1, dt2);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DatePickerCtrl, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DatePickerCtrl, __GetValue)
{
	Object_wx_DatePickerCtrl *pThis = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DatePickerCtrl, __SetRange, "SetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dt1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DatePickerCtrl, __SetRange)
{
	Object_wx_DatePickerCtrl *pThis = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDateTime& dt1 = arg.GetNumber(0)
	//const wxDateTime& dt2 = arg.GetNumber(1)
	//pThis->GetEntity()->SetRange(dt1, dt2);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DatePickerCtrl, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DatePickerCtrl, __SetValue)
{
	Object_wx_DatePickerCtrl *pThis = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDateTime& dt = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue(dt);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDatePickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DatePickerCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__DatePickerCtrl);
	Gura_AssignFunction(__DatePickerCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_DatePickerCtrl, __Create);
	Gura_AssignMethod(wx_DatePickerCtrl, __GetRange);
	Gura_AssignMethod(wx_DatePickerCtrl, __GetValue);
	Gura_AssignMethod(wx_DatePickerCtrl, __SetRange);
	Gura_AssignMethod(wx_DatePickerCtrl, __SetValue);
}

Gura_ImplementDescendantCreator(wx_DatePickerCtrl)
{
	return new Object_wx_DatePickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
