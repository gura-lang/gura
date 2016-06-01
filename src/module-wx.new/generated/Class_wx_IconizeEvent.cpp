//----------------------------------------------------------------------------
// wxIconizeEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxIconizeEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxIconizeEvent
//----------------------------------------------------------------------------
Object_wx_IconizeEvent::~Object_wx_IconizeEvent()
{
}

Object *Object_wx_IconizeEvent::Clone() const
{
	return nullptr;
}

String Object_wx_IconizeEvent::ToString(bool exprFlag)
{
	String rtn("<wx.IconizeEvent:");
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
Gura_DeclareMethod(wx_IconizeEvent, wxIconizeEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconized", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IconizeEvent, wxIconizeEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_IconizeEvent *pThis = Object_wx_IconizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int iconized = arg.GetNumber(1)
	//pThis->GetEntity()->wxIconizeEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IconizeEvent, IsIconized)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IconizeEvent, IsIconized)
{
	Signal &sig = env.GetSignal();
	Object_wx_IconizeEvent *pThis = Object_wx_IconizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsIconized();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IconizeEvent, Iconized)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IconizeEvent, Iconized)
{
	Signal &sig = env.GetSignal();
	Object_wx_IconizeEvent *pThis = Object_wx_IconizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Iconized();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxIconizeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IconizeEvent)
{
	Gura_AssignMethod(wx_IconizeEvent, wxIconizeEvent);
	Gura_AssignMethod(wx_IconizeEvent, IsIconized);
	Gura_AssignMethod(wx_IconizeEvent, Iconized);
}

Gura_ImplementDescendantCreator(wx_IconizeEvent)
{
	return new Object_wx_IconizeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
