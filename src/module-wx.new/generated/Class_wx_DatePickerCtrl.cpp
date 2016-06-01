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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DatePickerCtrl, wxDatePickerCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DatePickerCtrl, wxDatePickerCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_DatePickerCtrl *pThis = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxDatePickerCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DatePickerCtrl, wxDatePickerCtrl_1)
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

Gura_ImplementMethod(wx_DatePickerCtrl, wxDatePickerCtrl_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DatePickerCtrl *pThis = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int dt = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->wxDatePickerCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DatePickerCtrl, Create)
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

Gura_ImplementMethod(wx_DatePickerCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_DatePickerCtrl *pThis = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_DatePickerCtrl, GetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dt1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DatePickerCtrl, GetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_DatePickerCtrl *pThis = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dt1 = arg.GetNumber(0)
	//int dt2 = arg.GetNumber(1)
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DatePickerCtrl, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DatePickerCtrl, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_DatePickerCtrl *pThis = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DatePickerCtrl, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dt1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DatePickerCtrl, SetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_DatePickerCtrl *pThis = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dt1 = arg.GetNumber(0)
	//int dt2 = arg.GetNumber(1)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DatePickerCtrl, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DatePickerCtrl, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_DatePickerCtrl *pThis = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dt = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDatePickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DatePickerCtrl)
{
	Gura_AssignMethod(wx_DatePickerCtrl, wxDatePickerCtrl);
	Gura_AssignMethod(wx_DatePickerCtrl, wxDatePickerCtrl_1);
	Gura_AssignMethod(wx_DatePickerCtrl, Create);
	Gura_AssignMethod(wx_DatePickerCtrl, GetRange);
	Gura_AssignMethod(wx_DatePickerCtrl, GetValue);
	Gura_AssignMethod(wx_DatePickerCtrl, SetRange);
	Gura_AssignMethod(wx_DatePickerCtrl, SetValue);
}

Gura_ImplementDescendantCreator(wx_DatePickerCtrl)
{
	return new Object_wx_DatePickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
