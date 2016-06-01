//----------------------------------------------------------------------------
// wxSpinCtrlDouble
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSpinCtrlDouble
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSpinCtrlDouble
//----------------------------------------------------------------------------
Object_wx_SpinCtrlDouble::~Object_wx_SpinCtrlDouble()
{
}

Object *Object_wx_SpinCtrlDouble::Clone() const
{
	return nullptr;
}

String Object_wx_SpinCtrlDouble::ToString(bool exprFlag)
{
	String rtn("<wx.SpinCtrlDouble:");
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
Gura_DeclareMethod(wx_SpinCtrlDouble, wxSpinCtrlDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, wxSpinCtrlDouble)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxSpinCtrlDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrlDouble, wxSpinCtrlDouble_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "initial", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, wxSpinCtrlDouble_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int min = arg.GetNumber(6)
	//int max = arg.GetNumber(7)
	//int initial = arg.GetNumber(8)
	//int inc = arg.GetNumber(9)
	//int name = arg.GetNumber(10)
	//pThis->GetEntity()->wxSpinCtrlDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrlDouble, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "initial", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int min = arg.GetNumber(6)
	//int max = arg.GetNumber(7)
	//int initial = arg.GetNumber(8)
	//int inc = arg.GetNumber(9)
	//int name = arg.GetNumber(10)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrlDouble, GetDigits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, GetDigits)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDigits();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrlDouble, GetIncrement)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, GetIncrement)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetIncrement();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrlDouble, GetMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, GetMax)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMax();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrlDouble, GetMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, GetMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrlDouble, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrlDouble, SetDigits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "digits", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, SetDigits)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int digits = arg.GetNumber(0)
	//pThis->GetEntity()->SetDigits();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrlDouble, SetIncrement)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "inc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, SetIncrement)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int inc = arg.GetNumber(0)
	//pThis->GetEntity()->SetIncrement();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrlDouble, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minVal", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxVal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, SetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int minVal = arg.GetNumber(0)
	//int maxVal = arg.GetNumber(1)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrlDouble, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrlDouble, SetValue_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, SetValue_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSpinCtrlDouble
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SpinCtrlDouble)
{
	Gura_AssignMethod(wx_SpinCtrlDouble, wxSpinCtrlDouble);
	Gura_AssignMethod(wx_SpinCtrlDouble, wxSpinCtrlDouble_1);
	Gura_AssignMethod(wx_SpinCtrlDouble, Create);
	Gura_AssignMethod(wx_SpinCtrlDouble, GetDigits);
	Gura_AssignMethod(wx_SpinCtrlDouble, GetIncrement);
	Gura_AssignMethod(wx_SpinCtrlDouble, GetMax);
	Gura_AssignMethod(wx_SpinCtrlDouble, GetMin);
	Gura_AssignMethod(wx_SpinCtrlDouble, GetValue);
	Gura_AssignMethod(wx_SpinCtrlDouble, SetDigits);
	Gura_AssignMethod(wx_SpinCtrlDouble, SetIncrement);
	Gura_AssignMethod(wx_SpinCtrlDouble, SetRange);
	Gura_AssignMethod(wx_SpinCtrlDouble, SetValue);
	Gura_AssignMethod(wx_SpinCtrlDouble, SetValue_1);
}

Gura_ImplementDescendantCreator(wx_SpinCtrlDouble)
{
	return new Object_wx_SpinCtrlDouble((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
