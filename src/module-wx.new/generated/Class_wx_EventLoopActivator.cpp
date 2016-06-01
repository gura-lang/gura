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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_EventLoopActivator, wxEventLoopActivator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "loop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EventLoopActivator, wxEventLoopActivator)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopActivator *pThis = Object_wx_EventLoopActivator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int loop = arg.GetNumber(0)
	//pThis->GetEntity()->wxEventLoopActivator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopActivator, ~wxEventLoopActivator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopActivator, ~wxEventLoopActivator)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopActivator *pThis = Object_wx_EventLoopActivator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxEventLoopActivator();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxEventLoopActivator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EventLoopActivator)
{
	Gura_AssignMethod(wx_EventLoopActivator, wxEventLoopActivator);
	Gura_AssignMethod(wx_EventLoopActivator, ~wxEventLoopActivator);
}

Gura_ImplementDescendantCreator(wx_EventLoopActivator)
{
	return new Object_wx_EventLoopActivator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
