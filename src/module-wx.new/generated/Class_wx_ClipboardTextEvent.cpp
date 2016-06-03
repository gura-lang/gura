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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__ClipboardTextEvent, "ClipboardTextEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ClipboardTextEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ClipboardTextEvent)
{
	//int commandType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//wxClipboardTextEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxClipboardTextEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClipboardTextEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__ClipboardTextEvent);
}

Gura_ImplementDescendantCreator(wx_ClipboardTextEvent)
{
	return new Object_wx_ClipboardTextEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
