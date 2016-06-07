//----------------------------------------------------------------------------
// wxWindowDestroyEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowDestroyEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWindowDestroyEvent
//----------------------------------------------------------------------------
Object_wx_WindowDestroyEvent::~Object_wx_WindowDestroyEvent()
{
}

Object *Object_wx_WindowDestroyEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WindowDestroyEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WindowDestroyEvent:");
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
Gura_DeclareFunctionAlias(__WindowDestroyEvent, "WindowDestroyEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WindowDestroyEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WindowDestroyEvent)
{
	//wxWindow* win = arg.GetNumber(0)
	//wxWindowDestroyEvent(win);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_WindowDestroyEvent, __GetWindow, "GetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WindowDestroyEvent, __GetWindow)
{
	Object_wx_WindowDestroyEvent *pThis = Object_wx_WindowDestroyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWindowDestroyEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowDestroyEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__WindowDestroyEvent);
	// Method assignment
	Gura_AssignMethod(wx_WindowDestroyEvent, __GetWindow);
}

Gura_ImplementDescendantCreator(wx_WindowDestroyEvent)
{
	return new Object_wx_WindowDestroyEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
