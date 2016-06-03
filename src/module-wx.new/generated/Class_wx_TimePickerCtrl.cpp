//----------------------------------------------------------------------------
// wxTimePickerCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTimePickerCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTimePickerCtrl
//----------------------------------------------------------------------------
Object_wx_TimePickerCtrl::~Object_wx_TimePickerCtrl()
{
}

Object *Object_wx_TimePickerCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_TimePickerCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.TimePickerCtrl:");
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
Gura_DeclareFunctionAlias(__TimePickerCtrl, "TimePickerCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TimePickerCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TimePickerCtrl)
{
	//wxTimePickerCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__TimePickerCtrl_1, "TimePickerCtrl_1")
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
	SetClassToConstruct(Gura_UserClass(wx_TimePickerCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TimePickerCtrl_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxDateTime& dt = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxTimePickerCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TimePickerCtrl, __Create, "Create")
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

Gura_ImplementMethod(wx_TimePickerCtrl, __Create)
{
	Object_wx_TimePickerCtrl *pThis = Object_wx_TimePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxDateTime& dt = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimePickerCtrl, __GetTime, "GetTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimePickerCtrl, __GetTime)
{
	Object_wx_TimePickerCtrl *pThis = Object_wx_TimePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int* hour = arg.GetNumber(0)
	//int* min = arg.GetNumber(1)
	//int* sec = arg.GetNumber(2)
	//pThis->GetEntity()->GetTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimePickerCtrl, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimePickerCtrl, __GetValue)
{
	Object_wx_TimePickerCtrl *pThis = Object_wx_TimePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimePickerCtrl, __SetTime, "SetTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimePickerCtrl, __SetTime)
{
	Object_wx_TimePickerCtrl *pThis = Object_wx_TimePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int hour = arg.GetNumber(0)
	//int min = arg.GetNumber(1)
	//int sec = arg.GetNumber(2)
	//pThis->GetEntity()->SetTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimePickerCtrl, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimePickerCtrl, __SetValue)
{
	Object_wx_TimePickerCtrl *pThis = Object_wx_TimePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDateTime& dt = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTimePickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TimePickerCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__TimePickerCtrl);
	Gura_AssignFunction(__TimePickerCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_TimePickerCtrl, __Create);
	Gura_AssignMethod(wx_TimePickerCtrl, __GetTime);
	Gura_AssignMethod(wx_TimePickerCtrl, __GetValue);
	Gura_AssignMethod(wx_TimePickerCtrl, __SetTime);
	Gura_AssignMethod(wx_TimePickerCtrl, __SetValue);
}

Gura_ImplementDescendantCreator(wx_TimePickerCtrl)
{
	return new Object_wx_TimePickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
