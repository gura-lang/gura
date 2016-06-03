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
Gura_DeclareFunctionAlias(__SpinCtrlDouble, "SpinCtrlDouble")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SpinCtrlDouble));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SpinCtrlDouble)
{
	//wxSpinCtrlDouble();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__SpinCtrlDouble_1, "SpinCtrlDouble_1")
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
	SetClassToConstruct(Gura_UserClass(wx_SpinCtrlDouble));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SpinCtrlDouble_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& value = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//double min = arg.GetNumber(6)
	//double max = arg.GetNumber(7)
	//double initial = arg.GetNumber(8)
	//double inc = arg.GetNumber(9)
	//const wxString& name = arg.GetNumber(10)
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
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& value = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//double min = arg.GetNumber(6)
	//double max = arg.GetNumber(7)
	//double initial = arg.GetNumber(8)
	//double inc = arg.GetNumber(9)
	//const wxString& name = arg.GetNumber(10)
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
	//unsigned int digits = arg.GetNumber(0)
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
	//double inc = arg.GetNumber(0)
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
	//double minVal = arg.GetNumber(0)
	//double maxVal = arg.GetNumber(1)
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
	//const wxString& text = arg.GetNumber(0)
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
	//double value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSpinCtrlDouble
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SpinCtrlDouble)
{
	// Constructor assignment
	Gura_AssignFunction(__SpinCtrlDouble);
	Gura_AssignFunction(__SpinCtrlDouble_1);
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
