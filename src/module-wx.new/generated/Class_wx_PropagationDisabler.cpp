//----------------------------------------------------------------------------
// wxPropagationDisabler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropagationDisabler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropagationDisabler
//----------------------------------------------------------------------------
Object_wx_PropagationDisabler::~Object_wx_PropagationDisabler()
{
}

Object *Object_wx_PropagationDisabler::Clone() const
{
	return nullptr;
}

String Object_wx_PropagationDisabler::ToString(bool exprFlag)
{
	String rtn("<wx.PropagationDisabler:");
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
Gura_DeclareMethod(wx_PropagationDisabler, wxPropagationDisabler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropagationDisabler, wxPropagationDisabler)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropagationDisabler *pThis = Object_wx_PropagationDisabler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->wxPropagationDisabler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropagationDisabler, ~wxPropagationDisabler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropagationDisabler, ~wxPropagationDisabler)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropagationDisabler *pThis = Object_wx_PropagationDisabler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxPropagationDisabler();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPropagationDisabler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropagationDisabler)
{
	Gura_AssignMethod(wx_PropagationDisabler, wxPropagationDisabler);
	Gura_AssignMethod(wx_PropagationDisabler, ~wxPropagationDisabler);
}

Gura_ImplementDescendantCreator(wx_PropagationDisabler)
{
	return new Object_wx_PropagationDisabler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
