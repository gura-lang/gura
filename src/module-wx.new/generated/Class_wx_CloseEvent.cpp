//----------------------------------------------------------------------------
// wxCloseEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCloseEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCloseEvent
//----------------------------------------------------------------------------
Object_wx_CloseEvent::~Object_wx_CloseEvent()
{
}

Object *Object_wx_CloseEvent::Clone() const
{
	return nullptr;
}

String Object_wx_CloseEvent::ToString(bool exprFlag)
{
	String rtn("<wx.CloseEvent:");
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
Gura_DeclareFunctionAlias(__CloseEvent, "CloseEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "commandEventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CloseEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CloseEvent)
{
	//wxEventType commandEventType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//wxCloseEvent(commandEventType, id);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CloseEvent, __CanVeto, "CanVeto")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CloseEvent, __CanVeto)
{
	Object_wx_CloseEvent *pThis = Object_wx_CloseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->CanVeto();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CloseEvent, __GetLoggingOff, "GetLoggingOff")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CloseEvent, __GetLoggingOff)
{
	Object_wx_CloseEvent *pThis = Object_wx_CloseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetLoggingOff();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CloseEvent, __SetCanVeto, "SetCanVeto")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "canVeto", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CloseEvent, __SetCanVeto)
{
	Object_wx_CloseEvent *pThis = Object_wx_CloseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool canVeto = arg.GetNumber(0)
	//pThis->GetEntity()->SetCanVeto(canVeto);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CloseEvent, __SetLoggingOff, "SetLoggingOff")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "loggingOff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CloseEvent, __SetLoggingOff)
{
	Object_wx_CloseEvent *pThis = Object_wx_CloseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool loggingOff = arg.GetNumber(0)
	//pThis->GetEntity()->SetLoggingOff(loggingOff);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CloseEvent, __Veto, "Veto")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "veto", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CloseEvent, __Veto)
{
	Object_wx_CloseEvent *pThis = Object_wx_CloseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool veto = arg.GetNumber(0)
	//pThis->GetEntity()->Veto(veto);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CloseEvent, __GetVeto, "GetVeto")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CloseEvent, __GetVeto)
{
	Object_wx_CloseEvent *pThis = Object_wx_CloseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetVeto();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCloseEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CloseEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__CloseEvent);
	// Method assignment
	Gura_AssignMethod(wx_CloseEvent, __CanVeto);
	Gura_AssignMethod(wx_CloseEvent, __GetLoggingOff);
	Gura_AssignMethod(wx_CloseEvent, __SetCanVeto);
	Gura_AssignMethod(wx_CloseEvent, __SetLoggingOff);
	Gura_AssignMethod(wx_CloseEvent, __Veto);
	Gura_AssignMethod(wx_CloseEvent, __GetVeto);
}

Gura_ImplementDescendantCreator(wx_CloseEvent)
{
	return new Object_wx_CloseEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
