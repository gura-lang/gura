//----------------------------------------------------------------------------
// wxEventBlocker
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxEventBlocker
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxEventBlocker
//----------------------------------------------------------------------------
Object_wx_EventBlocker::~Object_wx_EventBlocker()
{
}

Object *Object_wx_EventBlocker::Clone() const
{
	return nullptr;
}

String Object_wx_EventBlocker::ToString(bool exprFlag)
{
	String rtn("<wx.EventBlocker:");
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
Gura_DeclareFunctionAlias(__EventBlocker, "EventBlocker")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_EventBlocker));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__EventBlocker)
{
	//wxWindow* win = arg.GetNumber(0)
	//wxEventType type = arg.GetNumber(1)
	//wxEventBlocker();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_EventBlocker, __Block, "Block")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EventBlocker, __Block)
{
	Object_wx_EventBlocker *pThis = Object_wx_EventBlocker::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxEventType eventType = arg.GetNumber(0)
	//pThis->GetEntity()->Block();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxEventBlocker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EventBlocker)
{
	// Constructor assignment
	Gura_AssignFunction(__EventBlocker);
	// Method assignment
	Gura_AssignMethod(wx_EventBlocker, __Block);
}

Gura_ImplementDescendantCreator(wx_EventBlocker)
{
	return new Object_wx_EventBlocker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
