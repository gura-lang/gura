//----------------------------------------------------------------------------
// wxDateEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDateEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDateEvent
//----------------------------------------------------------------------------
Object_wx_DateEvent::~Object_wx_DateEvent()
{
}

Object *Object_wx_DateEvent::Clone() const
{
	return nullptr;
}

String Object_wx_DateEvent::ToString(bool exprFlag)
{
	String rtn("<wx.DateEvent:");
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
Gura_DeclareFunctionAlias(__DateEvent, "DateEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DateEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DateEvent)
{
	//wxDateEvent();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DateEvent_1, "DateEvent_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DateEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DateEvent_1)
{
	//wxWindow* win = arg.GetNumber(0)
	//const wxDateTime& dt = arg.GetNumber(1)
	//wxEventType type = arg.GetNumber(2)
	//wxDateEvent(win, dt, type);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DateEvent, __GetDate, "GetDate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DateEvent, __GetDate)
{
	Object_wx_DateEvent *pThis = Object_wx_DateEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDateTime& _rtn = pThis->GetEntity()->GetDate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateEvent, __SetDate, "SetDate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "date", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateEvent, __SetDate)
{
	Object_wx_DateEvent *pThis = Object_wx_DateEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDateTime& date = arg.GetNumber(0)
	//pThis->GetEntity()->SetDate(date);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDateEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DateEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__DateEvent);
	Gura_AssignFunction(__DateEvent_1);
	// Method assignment
	Gura_AssignMethod(wx_DateEvent, __GetDate);
	Gura_AssignMethod(wx_DateEvent, __SetDate);
}

Gura_ImplementDescendantCreator(wx_DateEvent)
{
	return new Object_wx_DateEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
