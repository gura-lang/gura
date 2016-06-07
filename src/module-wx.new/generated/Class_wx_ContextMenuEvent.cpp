//----------------------------------------------------------------------------
// wxContextMenuEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxContextMenuEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxContextMenuEvent
//----------------------------------------------------------------------------
Object_wx_ContextMenuEvent::~Object_wx_ContextMenuEvent()
{
}

Object *Object_wx_ContextMenuEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ContextMenuEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ContextMenuEvent:");
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
Gura_DeclareFunctionAlias(__ContextMenuEvent, "ContextMenuEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ContextMenuEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ContextMenuEvent)
{
	//wxEventType type = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//wxContextMenuEvent(type, id, pos);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ContextMenuEvent, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ContextMenuEvent, __GetPosition)
{
	Object_wx_ContextMenuEvent *pThis = Object_wx_ContextMenuEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& _rtn = pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ContextMenuEvent, __SetPosition, "SetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ContextMenuEvent, __SetPosition)
{
	Object_wx_ContextMenuEvent *pThis = Object_wx_ContextMenuEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& point = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition(point);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxContextMenuEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ContextMenuEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__ContextMenuEvent);
	// Method assignment
	Gura_AssignMethod(wx_ContextMenuEvent, __GetPosition);
	Gura_AssignMethod(wx_ContextMenuEvent, __SetPosition);
}

Gura_ImplementDescendantCreator(wx_ContextMenuEvent)
{
	return new Object_wx_ContextMenuEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
