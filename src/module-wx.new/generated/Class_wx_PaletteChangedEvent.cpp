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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__PaletteChangedEvent, "PaletteChangedEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PaletteChangedEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PaletteChangedEvent)
{
	//wxWindowID winid = arg.GetNumber(0)
	//wxPaletteChangedEvent(winid);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PaletteChangedEvent, __SetChangedWindow, "SetChangedWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PaletteChangedEvent, __SetChangedWindow)
{
	Object_wx_PaletteChangedEvent *pThis = Object_wx_PaletteChangedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//pThis->GetEntity()->SetChangedWindow(win);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PaletteChangedEvent, __GetChangedWindow, "GetChangedWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PaletteChangedEvent, __GetChangedWindow)
{
	Object_wx_PaletteChangedEvent *pThis = Object_wx_PaletteChangedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* _rtn = pThis->GetEntity()->GetChangedWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPaletteChangedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PaletteChangedEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__PaletteChangedEvent);
	// Method assignment
	Gura_AssignMethod(wx_PaletteChangedEvent, __SetChangedWindow);
	Gura_AssignMethod(wx_PaletteChangedEvent, __GetChangedWindow);
}

Gura_ImplementDescendantCreator(wx_PaletteChangedEvent)
{
	return new Object_wx_PaletteChangedEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
