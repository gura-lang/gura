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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxSpinCtrlDouble, "wxSpinCtrlDouble")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxSpinCtrlDouble)
{
	//wxSpinCtrlDouble();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxSpinCtrlDouble_1, "wxSpinCtrlDouble_1")
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

Gura_ImplementFunction(__wxSpinCtrlDouble_1)
{
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
	//wxSpinCtrlDouble();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SpinCtrlDouble, __Create, "Create")
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

Gura_ImplementMethod(wx_SpinCtrlDouble, __Create)
{
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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

Gura_DeclareMethodAlias(wx_SpinCtrlDouble, __GetDigits, "GetDigits")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, __GetDigits)
{
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDigits();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinCtrlDouble, __GetIncrement, "GetIncrement")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, __GetIncrement)
{
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIncrement();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinCtrlDouble, __GetMax, "GetMax")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, __GetMax)
{
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMax();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinCtrlDouble, __GetMin, "GetMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, __GetMin)
{
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinCtrlDouble, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, __GetValue)
{
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinCtrlDouble, __SetDigits, "SetDigits")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "digits", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, __SetDigits)
{
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int digits = arg.GetNumber(0)
	//pThis->GetEntity()->SetDigits();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinCtrlDouble, __SetIncrement, "SetIncrement")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "inc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, __SetIncrement)
{
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int inc = arg.GetNumber(0)
	//pThis->GetEntity()->SetIncrement();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinCtrlDouble, __SetRange, "SetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minVal", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxVal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, __SetRange)
{
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int minVal = arg.GetNumber(0)
	//int maxVal = arg.GetNumber(1)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinCtrlDouble, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, __SetValue)
{
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinCtrlDouble, __SetValue_1, "SetValue_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrlDouble, __SetValue_1)
{
	Object_wx_SpinCtrlDouble *pThis = Object_wx_SpinCtrlDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSpinCtrlDouble
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SpinCtrlDouble)
{
	// Constructor assignment
	Gura_AssignFunction(__wxSpinCtrlDouble);
	Gura_AssignFunction(__wxSpinCtrlDouble_1);
	// Method assignment
	Gura_AssignMethod(wx_SpinCtrlDouble, __Create);
	Gura_AssignMethod(wx_SpinCtrlDouble, __GetDigits);
	Gura_AssignMethod(wx_SpinCtrlDouble, __GetIncrement);
	Gura_AssignMethod(wx_SpinCtrlDouble, __GetMax);
	Gura_AssignMethod(wx_SpinCtrlDouble, __GetMin);
	Gura_AssignMethod(wx_SpinCtrlDouble, __GetValue);
	Gura_AssignMethod(wx_SpinCtrlDouble, __SetDigits);
	Gura_AssignMethod(wx_SpinCtrlDouble, __SetIncrement);
	Gura_AssignMethod(wx_SpinCtrlDouble, __SetRange);
	Gura_AssignMethod(wx_SpinCtrlDouble, __SetValue);
	Gura_AssignMethod(wx_SpinCtrlDouble, __SetValue_1);
}

Gura_ImplementDescendantCreator(wx_SpinCtrlDouble)
{
	return new Object_wx_SpinCtrlDouble((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
