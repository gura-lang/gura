//----------------------------------------------------------------------------
// wxEventLoopActivator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxEventLoopActivator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxEventLoopActivator
//----------------------------------------------------------------------------
Object_wx_EventLoopActivator::~Object_wx_EventLoopActivator()
{
}

Object *Object_wx_EventLoopActivator::Clone() const
{
	return nullptr;
}

String Object_wx_EventLoopActivator::ToString(bool exprFlag)
{
	String rtn("<wx.EventLoopActivator:");
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
Gura_DeclareFunctionAlias(__EventLoopActivator, "EventLoopActivator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "loop", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_EventLoopActivator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__EventLoopActivator)
{
	//wxEventLoopBase* loop = arg.GetNumber(0)
	//wxEventLoopActivator(loop);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxEventLoopActivator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EventLoopActivator)
{
	// Constructor assignment
	Gura_AssignFunction(__EventLoopActivator);
}

Gura_ImplementDescendantCreator(wx_EventLoopActivator)
{
	return new Object_wx_EventLoopActivator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
