//----------------------------------------------------------------------------
// wxRibbonBarEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonBarEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonBarEvent
//----------------------------------------------------------------------------
Object_wx_RibbonBarEvent::~Object_wx_RibbonBarEvent()
{
}

Object *Object_wx_RibbonBarEvent::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonBarEvent::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonBarEvent:");
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
Gura_DeclareMethod(wx_RibbonBarEvent, wxRibbonBarEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "command_type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBarEvent, wxRibbonBarEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonBarEvent *pThis = Object_wx_RibbonBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int command_type = arg.GetNumber(0)
	//int win_id = arg.GetNumber(1)
	//int page = arg.GetNumber(2)
	//pThis->GetEntity()->wxRibbonBarEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBarEvent, GetPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBarEvent, GetPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonBarEvent *pThis = Object_wx_RibbonBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBarEvent, SetPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBarEvent, SetPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonBarEvent *pThis = Object_wx_RibbonBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetPage();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonBarEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonBarEvent)
{
	Gura_AssignMethod(wx_RibbonBarEvent, wxRibbonBarEvent);
	Gura_AssignMethod(wx_RibbonBarEvent, GetPage);
	Gura_AssignMethod(wx_RibbonBarEvent, SetPage);
}

Gura_ImplementDescendantCreator(wx_RibbonBarEvent)
{
	return new Object_wx_RibbonBarEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
