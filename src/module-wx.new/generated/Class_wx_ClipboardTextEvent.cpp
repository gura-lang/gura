//----------------------------------------------------------------------------
// wxClipboardTextEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxClipboardTextEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxClipboardTextEvent
//----------------------------------------------------------------------------
Object_wx_ClipboardTextEvent::~Object_wx_ClipboardTextEvent()
{
}

Object *Object_wx_ClipboardTextEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ClipboardTextEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ClipboardTextEvent:");
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
Gura_DeclareMethod(wx_ClipboardTextEvent, wxClipboardTextEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ClipboardTextEvent, wxClipboardTextEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_ClipboardTextEvent *pThis = Object_wx_ClipboardTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int commandType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->wxClipboardTextEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxClipboardTextEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClipboardTextEvent)
{
	Gura_AssignMethod(wx_ClipboardTextEvent, wxClipboardTextEvent);
}

Gura_ImplementDescendantCreator(wx_ClipboardTextEvent)
{
	return new Object_wx_ClipboardTextEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
