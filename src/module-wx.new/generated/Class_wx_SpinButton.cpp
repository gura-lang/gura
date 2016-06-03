//----------------------------------------------------------------------------
// wxSpinButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSpinButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSpinButton
//----------------------------------------------------------------------------
Object_wx_SpinButton::~Object_wx_SpinButton()
{
}

Object *Object_wx_SpinButton::Clone() const
{
	return nullptr;
}

String Object_wx_SpinButton::ToString(bool exprFlag)
{
	String rtn("<wx.SpinButton:");
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
Gura_DeclareMethodAlias(wx_SpinButton, __wxSpinButton, "wxSpinButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinButton, __wxSpinButton)
{
	Object_wx_SpinButton *pThis = Object_wx_SpinButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxSpinButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinButton, __wxSpinButton_1, "wxSpinButton_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinButton, __wxSpinButton_1)
{
	Object_wx_SpinButton *pThis = Object_wx_SpinButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxSpinButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinButton, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinButton, __Create)
{
	Object_wx_SpinButton *pThis = Object_wx_SpinButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinButton, __GetMax, "GetMax")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinButton, __GetMax)
{
	Object_wx_SpinButton *pThis = Object_wx_SpinButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMax();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinButton, __GetMin, "GetMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinButton, __GetMin)
{
	Object_wx_SpinButton *pThis = Object_wx_SpinButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinButton, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinButton, __GetValue)
{
	Object_wx_SpinButton *pThis = Object_wx_SpinButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinButton, __SetRange, "SetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinButton, __SetRange)
{
	Object_wx_SpinButton *pThis = Object_wx_SpinButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int min = arg.GetNumber(0)
	//int max = arg.GetNumber(1)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinButton, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinButton, __SetValue)
{
	Object_wx_SpinButton *pThis = Object_wx_SpinButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSpinButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SpinButton)
{
	Gura_AssignMethod(wx_SpinButton, __wxSpinButton);
	Gura_AssignMethod(wx_SpinButton, __wxSpinButton_1);
	Gura_AssignMethod(wx_SpinButton, __Create);
	Gura_AssignMethod(wx_SpinButton, __GetMax);
	Gura_AssignMethod(wx_SpinButton, __GetMin);
	Gura_AssignMethod(wx_SpinButton, __GetValue);
	Gura_AssignMethod(wx_SpinButton, __SetRange);
	Gura_AssignMethod(wx_SpinButton, __SetValue);
}

Gura_ImplementDescendantCreator(wx_SpinButton)
{
	return new Object_wx_SpinButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
