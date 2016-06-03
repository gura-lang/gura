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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__SpinCtrl, "SpinCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SpinCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SpinCtrl)
{
	//wxSpinCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__SpinCtrl_1, "SpinCtrl_1")
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
	SetClassToConstruct(Gura_UserClass(wx_SpinCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SpinCtrl_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& value = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//int min = arg.GetNumber(6)
	//int max = arg.GetNumber(7)
	//int initial = arg.GetNumber(8)
	//const wxString& name = arg.GetNumber(9)
	//wxSpinCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SpinCtrl, __Create, "Create")
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

Gura_ImplementMethod(wx_SpinCtrl, __Create)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& value = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//int min = arg.GetNumber(6)
	//int max = arg.GetNumber(7)
	//int initial = arg.GetNumber(8)
	//const wxString& name = arg.GetNumber(9)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinCtrl, __GetBase, "GetBase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrl, __GetBase)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinCtrl, __GetMax, "GetMax")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrl, __GetMax)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMax();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinCtrl, __GetMin, "GetMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrl, __GetMin)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinCtrl, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinCtrl, __GetValue)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinCtrl, __SetBase, "SetBase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, __SetBase)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//pThis->GetEntity()->SetBase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinCtrl, __SetRange, "SetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minVal", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxVal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, __SetRange)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int minVal = arg.GetNumber(0)
	//int maxVal = arg.GetNumber(1)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinCtrl, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, __SetSelection)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long from = arg.GetNumber(0)
	//long to = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinCtrl, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, __SetValue)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinCtrl, __SetValue_1, "SetValue_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, __SetValue_1)
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
	// Constructor assignment
	Gura_AssignFunction(__SpinCtrl);
	Gura_AssignFunction(__SpinCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_SpinCtrl, __Create);
	Gura_AssignMethod(wx_SpinCtrl, __GetBase);
	Gura_AssignMethod(wx_SpinCtrl, __GetMax);
	Gura_AssignMethod(wx_SpinCtrl, __GetMin);
	Gura_AssignMethod(wx_SpinCtrl, __GetValue);
	Gura_AssignMethod(wx_SpinCtrl, __SetBase);
	Gura_AssignMethod(wx_SpinCtrl, __SetRange);
	Gura_AssignMethod(wx_SpinCtrl, __SetSelection);
	Gura_AssignMethod(wx_SpinCtrl, __SetValue);
	Gura_AssignMethod(wx_SpinCtrl, __SetValue_1);
}

Gura_ImplementDescendantCreator(wx_SpinCtrl)
{
	return new Object_wx_SpinCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
