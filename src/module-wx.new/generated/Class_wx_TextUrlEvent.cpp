//----------------------------------------------------------------------------
// wxTextUrlEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextUrlEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextUrlEvent
//----------------------------------------------------------------------------
Object_wx_TextUrlEvent::~Object_wx_TextUrlEvent()
{
}

Object *Object_wx_TextUrlEvent::Clone() const
{
	return nullptr;
}

String Object_wx_TextUrlEvent::ToString(bool exprFlag)
{
	String rtn("<wx.TextUrlEvent:");
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
Gura_DeclareFunctionAlias(__TextUrlEvent, "TextUrlEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "evtMouse", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TextUrlEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TextUrlEvent)
{
	//int winid = arg.GetNumber(0)
	//const wxMouseEvent& evtMouse = arg.GetNumber(1)
	//long start = arg.GetNumber(2)
	//long end = arg.GetNumber(3)
	//wxTextUrlEvent();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__TextUrlEvent_1, "TextUrlEvent_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TextUrlEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TextUrlEvent_1)
{
	//const wxTextUrlEvent& event = arg.GetNumber(0)
	//wxTextUrlEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TextUrlEvent, __GetMouseEvent, "GetMouseEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextUrlEvent, __GetMouseEvent)
{
	Object_wx_TextUrlEvent *pThis = Object_wx_TextUrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMouseEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextUrlEvent, __GetURLStart, "GetURLStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextUrlEvent, __GetURLStart)
{
	Object_wx_TextUrlEvent *pThis = Object_wx_TextUrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetURLStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextUrlEvent, __GetURLEnd, "GetURLEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextUrlEvent, __GetURLEnd)
{
	Object_wx_TextUrlEvent *pThis = Object_wx_TextUrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetURLEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextUrlEvent, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextUrlEvent, __Clone)
{
	Object_wx_TextUrlEvent *pThis = Object_wx_TextUrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextUrlEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextUrlEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__TextUrlEvent);
	Gura_AssignFunction(__TextUrlEvent_1);
	// Method assignment
	Gura_AssignMethod(wx_TextUrlEvent, __GetMouseEvent);
	Gura_AssignMethod(wx_TextUrlEvent, __GetURLStart);
	Gura_AssignMethod(wx_TextUrlEvent, __GetURLEnd);
	Gura_AssignMethod(wx_TextUrlEvent, __Clone);
}

Gura_ImplementDescendantCreator(wx_TextUrlEvent)
{
	return new Object_wx_TextUrlEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
