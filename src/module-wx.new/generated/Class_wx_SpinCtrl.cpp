//----------------------------------------------------------------------------
// wxSpinCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSpinCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSpinCtrl
//----------------------------------------------------------------------------
Object_wx_SpinCtrl::~Object_wx_SpinCtrl()
{
}

Object *Object_wx_SpinCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_SpinCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.SpinCtrl:");
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
Gura_DeclareMethod(wx_SpinCtrl, wxSpinCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrl, wxSpinCtrl)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxSpinCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrl, wxSpinCtrl_1)
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
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, wxSpinCtrl_1)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
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
	//int name = arg.GetNumber(9)
	//pThis->GetEntity()->wxSpinCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrl, Create)
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
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, Create)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
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
	//int name = arg.GetNumber(9)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrl, GetBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrl, GetBase)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrl, GetMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrl, GetMax)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMax();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrl, GetMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrl, GetMin)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrl, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrl, GetValue)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrl, SetBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, SetBase)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//pThis->GetEntity()->SetBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrl, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minVal", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxVal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, SetRange)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int minVal = arg.GetNumber(0)
	//int maxVal = arg.GetNumber(1)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrl, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, SetSelection)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrl, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, SetValue)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrl, SetValue_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, SetValue_1)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSpinCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SpinCtrl)
{
	Gura_AssignMethod(wx_SpinCtrl, wxSpinCtrl);
	Gura_AssignMethod(wx_SpinCtrl, wxSpinCtrl_1);
	Gura_AssignMethod(wx_SpinCtrl, Create);
	Gura_AssignMethod(wx_SpinCtrl, GetBase);
	Gura_AssignMethod(wx_SpinCtrl, GetMax);
	Gura_AssignMethod(wx_SpinCtrl, GetMin);
	Gura_AssignMethod(wx_SpinCtrl, GetValue);
	Gura_AssignMethod(wx_SpinCtrl, SetBase);
	Gura_AssignMethod(wx_SpinCtrl, SetRange);
	Gura_AssignMethod(wx_SpinCtrl, SetSelection);
	Gura_AssignMethod(wx_SpinCtrl, SetValue);
	Gura_AssignMethod(wx_SpinCtrl, SetValue_1);
}

Gura_ImplementDescendantCreator(wx_SpinCtrl)
{
	return new Object_wx_SpinCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
