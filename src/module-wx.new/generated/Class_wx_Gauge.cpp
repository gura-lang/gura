//----------------------------------------------------------------------------
// wxGauge
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGauge
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGauge
//----------------------------------------------------------------------------
Object_wx_Gauge::~Object_wx_Gauge()
{
}

Object *Object_wx_Gauge::Clone() const
{
	return nullptr;
}

String Object_wx_Gauge::ToString(bool exprFlag)
{
	String rtn("<wx.Gauge:");
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
Gura_DeclareFunctionAlias(__Gauge, "Gauge")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Gauge));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Gauge)
{
	//wxGauge();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Gauge_1, "Gauge_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Gauge));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Gauge_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//int range = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxGauge();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Gauge, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Gauge, __Create)
{
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//int range = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Gauge, __GetRange, "GetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Gauge, __GetRange)
{
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Gauge, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Gauge, __GetValue)
{
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Gauge, __IsVertical, "IsVertical")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Gauge, __IsVertical)
{
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsVertical();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Gauge, __Pulse, "Pulse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Gauge, __Pulse)
{
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Pulse();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Gauge, __SetRange, "SetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Gauge, __SetRange)
{
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Gauge, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Gauge, __SetValue)
{
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGauge
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Gauge)
{
	// Constructor assignment
	Gura_AssignFunction(__Gauge);
	Gura_AssignFunction(__Gauge_1);
	// Method assignment
	Gura_AssignMethod(wx_Gauge, __Create);
	Gura_AssignMethod(wx_Gauge, __GetRange);
	Gura_AssignMethod(wx_Gauge, __GetValue);
	Gura_AssignMethod(wx_Gauge, __IsVertical);
	Gura_AssignMethod(wx_Gauge, __Pulse);
	Gura_AssignMethod(wx_Gauge, __SetRange);
	Gura_AssignMethod(wx_Gauge, __SetValue);
}

Gura_ImplementDescendantCreator(wx_Gauge)
{
	return new Object_wx_Gauge((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
