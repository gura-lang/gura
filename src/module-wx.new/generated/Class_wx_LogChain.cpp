//----------------------------------------------------------------------------
// wxLogChain
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogChain
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogChain
//----------------------------------------------------------------------------
Object_wx_LogChain::~Object_wx_LogChain()
{
}

Object *Object_wx_LogChain::Clone() const
{
	return nullptr;
}

String Object_wx_LogChain::ToString(bool exprFlag)
{
	String rtn("<wx.LogChain:");
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
Gura_DeclareMethod(wx_LogChain, wxLogChain)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "logger", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogChain, wxLogChain)
{
	Signal &sig = env.GetSignal();
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int logger = arg.GetNumber(0)
	//pThis->GetEntity()->wxLogChain();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogChain, ~wxLogChain)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogChain, ~wxLogChain)
{
	Signal &sig = env.GetSignal();
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxLogChain();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogChain, DetachOldLog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogChain, DetachOldLog)
{
	Signal &sig = env.GetSignal();
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DetachOldLog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogChain, GetOldLog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogChain, GetOldLog)
{
	Signal &sig = env.GetSignal();
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOldLog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogChain, IsPassingMessages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogChain, IsPassingMessages)
{
	Signal &sig = env.GetSignal();
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsPassingMessages();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogChain, PassMessages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "passMessages", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogChain, PassMessages)
{
	Signal &sig = env.GetSignal();
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int passMessages = arg.GetNumber(0)
	//pThis->GetEntity()->PassMessages();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogChain, SetLog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "logger", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogChain, SetLog)
{
	Signal &sig = env.GetSignal();
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int logger = arg.GetNumber(0)
	//pThis->GetEntity()->SetLog();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLogChain
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogChain)
{
	Gura_AssignMethod(wx_LogChain, wxLogChain);
	Gura_AssignMethod(wx_LogChain, ~wxLogChain);
	Gura_AssignMethod(wx_LogChain, DetachOldLog);
	Gura_AssignMethod(wx_LogChain, GetOldLog);
	Gura_AssignMethod(wx_LogChain, IsPassingMessages);
	Gura_AssignMethod(wx_LogChain, PassMessages);
	Gura_AssignMethod(wx_LogChain, SetLog);
}

Gura_ImplementDescendantCreator(wx_LogChain)
{
	return new Object_wx_LogChain((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
