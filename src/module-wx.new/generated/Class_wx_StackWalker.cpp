//----------------------------------------------------------------------------
// wxStackWalker
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStackWalker
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStackWalker
//----------------------------------------------------------------------------
Object_wx_StackWalker::~Object_wx_StackWalker()
{
}

Object *Object_wx_StackWalker::Clone() const
{
	return nullptr;
}

String Object_wx_StackWalker::ToString(bool exprFlag)
{
	String rtn("<wx.StackWalker:");
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
Gura_DeclareMethod(wx_StackWalker, wxStackWalker)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "argv0", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StackWalker, wxStackWalker)
{
	Signal &sig = env.GetSignal();
	Object_wx_StackWalker *pThis = Object_wx_StackWalker::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int argv0 = arg.GetNumber(0)
	//pThis->GetEntity()->wxStackWalker();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StackWalker, ~wxStackWalker)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackWalker, ~wxStackWalker)
{
	Signal &sig = env.GetSignal();
	Object_wx_StackWalker *pThis = Object_wx_StackWalker::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxStackWalker();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StackWalker, Walk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "skip", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxDepth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StackWalker, Walk)
{
	Signal &sig = env.GetSignal();
	Object_wx_StackWalker *pThis = Object_wx_StackWalker::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int skip = arg.GetNumber(0)
	//int maxDepth = arg.GetNumber(1)
	//pThis->GetEntity()->Walk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StackWalker, WalkFromException)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "maxDepth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StackWalker, WalkFromException)
{
	Signal &sig = env.GetSignal();
	Object_wx_StackWalker *pThis = Object_wx_StackWalker::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int maxDepth = arg.GetNumber(0)
	//pThis->GetEntity()->WalkFromException();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StackWalker, OnStackFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "frame", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StackWalker, OnStackFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_StackWalker *pThis = Object_wx_StackWalker::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int frame = arg.GetNumber(0)
	//pThis->GetEntity()->OnStackFrame();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStackWalker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StackWalker)
{
	Gura_AssignMethod(wx_StackWalker, wxStackWalker);
	Gura_AssignMethod(wx_StackWalker, ~wxStackWalker);
	Gura_AssignMethod(wx_StackWalker, Walk);
	Gura_AssignMethod(wx_StackWalker, WalkFromException);
	Gura_AssignMethod(wx_StackWalker, OnStackFrame);
}

Gura_ImplementDescendantCreator(wx_StackWalker)
{
	return new Object_wx_StackWalker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
