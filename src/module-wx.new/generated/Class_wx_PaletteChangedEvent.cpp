//----------------------------------------------------------------------------
// wxPaletteChangedEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPaletteChangedEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPaletteChangedEvent
//----------------------------------------------------------------------------
Object_wx_PaletteChangedEvent::~Object_wx_PaletteChangedEvent()
{
}

Object *Object_wx_PaletteChangedEvent::Clone() const
{
	return nullptr;
}

String Object_wx_PaletteChangedEvent::ToString(bool exprFlag)
{
	String rtn("<wx.PaletteChangedEvent:");
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
Gura_DeclareMethod(wx_PaletteChangedEvent, wxPaletteChangedEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PaletteChangedEvent, wxPaletteChangedEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_PaletteChangedEvent *pThis = Object_wx_PaletteChangedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int winid = arg.GetNumber(0)
	//pThis->GetEntity()->wxPaletteChangedEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PaletteChangedEvent, SetChangedWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PaletteChangedEvent, SetChangedWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_PaletteChangedEvent *pThis = Object_wx_PaletteChangedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->SetChangedWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PaletteChangedEvent, GetChangedWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PaletteChangedEvent, GetChangedWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_PaletteChangedEvent *pThis = Object_wx_PaletteChangedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetChangedWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPaletteChangedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PaletteChangedEvent)
{
	Gura_AssignMethod(wx_PaletteChangedEvent, wxPaletteChangedEvent);
	Gura_AssignMethod(wx_PaletteChangedEvent, SetChangedWindow);
	Gura_AssignMethod(wx_PaletteChangedEvent, GetChangedWindow);
}

Gura_ImplementDescendantCreator(wx_PaletteChangedEvent)
{
	return new Object_wx_PaletteChangedEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
