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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_TimePickerCtrl, wxTimePickerCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimePickerCtrl, wxTimePickerCtrl)
{
	Object_wx_TimePickerCtrl *pThis = Object_wx_TimePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxTimePickerCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimePickerCtrl, wxTimePickerCtrl_1)
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

Gura_ImplementMethod(wx_TimePickerCtrl, wxTimePickerCtrl_1)
{
	Object_wx_TimePickerCtrl *pThis = Object_wx_TimePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int dt = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->wxTimePickerCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimePickerCtrl, Create)
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

Gura_ImplementMethod(wx_TimePickerCtrl, Create)
{
	Object_wx_TimePickerCtrl *pThis = Object_wx_TimePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int dt = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimePickerCtrl, GetTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimePickerCtrl, GetTime)
{
	Object_wx_TimePickerCtrl *pThis = Object_wx_TimePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int hour = arg.GetNumber(0)
	//int min = arg.GetNumber(1)
	//int sec = arg.GetNumber(2)
	//pThis->GetEntity()->GetTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimePickerCtrl, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimePickerCtrl, GetValue)
{
	Object_wx_TimePickerCtrl *pThis = Object_wx_TimePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimePickerCtrl, SetTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimePickerCtrl, SetTime)
{
	Object_wx_TimePickerCtrl *pThis = Object_wx_TimePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int hour = arg.GetNumber(0)
	//int min = arg.GetNumber(1)
	//int sec = arg.GetNumber(2)
	//pThis->GetEntity()->SetTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimePickerCtrl, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimePickerCtrl, SetValue)
{
	Object_wx_TimePickerCtrl *pThis = Object_wx_TimePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dt = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTimePickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TimePickerCtrl)
{
	Gura_AssignMethod(wx_TimePickerCtrl, wxTimePickerCtrl);
	Gura_AssignMethod(wx_TimePickerCtrl, wxTimePickerCtrl_1);
	Gura_AssignMethod(wx_TimePickerCtrl, Create);
	Gura_AssignMethod(wx_TimePickerCtrl, GetTime);
	Gura_AssignMethod(wx_TimePickerCtrl, GetValue);
	Gura_AssignMethod(wx_TimePickerCtrl, SetTime);
	Gura_AssignMethod(wx_TimePickerCtrl, SetValue);
}

Gura_ImplementDescendantCreator(wx_TimePickerCtrl)
{
	return new Object_wx_TimePickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
