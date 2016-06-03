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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__LogChain, "LogChain")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "logger", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_LogChain));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__LogChain)
{
	//int logger = arg.GetNumber(0)
	//wxLogChain();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_LogChain, __DetachOldLog, "DetachOldLog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogChain, __DetachOldLog)
{
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DetachOldLog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LogChain, __GetOldLog, "GetOldLog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogChain, __GetOldLog)
{
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOldLog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LogChain, __IsPassingMessages, "IsPassingMessages")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogChain, __IsPassingMessages)
{
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsPassingMessages();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LogChain, __PassMessages, "PassMessages")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "passMessages", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogChain, __PassMessages)
{
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int passMessages = arg.GetNumber(0)
	//pThis->GetEntity()->PassMessages();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LogChain, __SetLog, "SetLog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "logger", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogChain, __SetLog)
{
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int logger = arg.GetNumber(0)
	//pThis->GetEntity()->SetLog();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLogChain
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogChain)
{
	// Constructor assignment
	Gura_AssignFunction(__LogChain);
	// Method assignment
	Gura_AssignMethod(wx_LogChain, __DetachOldLog);
	Gura_AssignMethod(wx_LogChain, __GetOldLog);
	Gura_AssignMethod(wx_LogChain, __IsPassingMessages);
	Gura_AssignMethod(wx_LogChain, __PassMessages);
	Gura_AssignMethod(wx_LogChain, __SetLog);
}

Gura_ImplementDescendantCreator(wx_LogChain)
{
	return new Object_wx_LogChain((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
