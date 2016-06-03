//----------------------------------------------------------------------------
// wxPowerEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPowerEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPowerEvent
//----------------------------------------------------------------------------
Object_wx_PowerEvent::~Object_wx_PowerEvent()
{
}

Object *Object_wx_PowerEvent::Clone() const
{
	return nullptr;
}

String Object_wx_PowerEvent::ToString(bool exprFlag)
{
	String rtn("<wx.PowerEvent:");
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
Gura_DeclareFunctionAlias(__wxPowerEvent, "wxPowerEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PowerEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxPowerEvent)
{
	//wxPowerEvent();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxPowerEvent_1, "wxPowerEvent_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "evtType", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PowerEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxPowerEvent_1)
{
	//int evtType = arg.GetNumber(0)
	//wxPowerEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PowerEvent, __Veto, "Veto")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PowerEvent, __Veto)
{
	Object_wx_PowerEvent *pThis = Object_wx_PowerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Veto();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PowerEvent, __IsVetoed, "IsVetoed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PowerEvent, __IsVetoed)
{
	Object_wx_PowerEvent *pThis = Object_wx_PowerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsVetoed();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPowerEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PowerEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__wxPowerEvent);
	Gura_AssignFunction(__wxPowerEvent_1);
	// Method assignment
	Gura_AssignMethod(wx_PowerEvent, __Veto);
	Gura_AssignMethod(wx_PowerEvent, __IsVetoed);
}

Gura_ImplementDescendantCreator(wx_PowerEvent)
{
	return new Object_wx_PowerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
