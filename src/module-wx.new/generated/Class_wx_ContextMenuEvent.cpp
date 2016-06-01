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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ContextMenuEvent, wxContextMenuEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ContextMenuEvent, wxContextMenuEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_ContextMenuEvent *pThis = Object_wx_ContextMenuEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//pThis->GetEntity()->wxContextMenuEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ContextMenuEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ContextMenuEvent, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ContextMenuEvent *pThis = Object_wx_ContextMenuEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ContextMenuEvent, SetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ContextMenuEvent, SetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ContextMenuEvent *pThis = Object_wx_ContextMenuEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int point = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxContextMenuEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ContextMenuEvent)
{
	Gura_AssignMethod(wx_ContextMenuEvent, wxContextMenuEvent);
	Gura_AssignMethod(wx_ContextMenuEvent, GetPosition);
	Gura_AssignMethod(wx_ContextMenuEvent, SetPosition);
}

Gura_ImplementDescendantCreator(wx_ContextMenuEvent)
{
	return new Object_wx_ContextMenuEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
