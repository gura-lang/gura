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
Gura_DeclareMethodAlias(wx_StackWalker, __wxStackWalker, "wxStackWalker")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "argv0", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StackWalker, __wxStackWalker)
{
	Object_wx_StackWalker *pThis = Object_wx_StackWalker::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int argv0 = arg.GetNumber(0)
	//pThis->GetEntity()->wxStackWalker();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StackWalker, __Walk, "Walk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "skip", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxDepth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StackWalker, __Walk)
{
	Object_wx_StackWalker *pThis = Object_wx_StackWalker::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int skip = arg.GetNumber(0)
	//int maxDepth = arg.GetNumber(1)
	//pThis->GetEntity()->Walk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StackWalker, __WalkFromException, "WalkFromException")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "maxDepth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StackWalker, __WalkFromException)
{
	Object_wx_StackWalker *pThis = Object_wx_StackWalker::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int maxDepth = arg.GetNumber(0)
	//pThis->GetEntity()->WalkFromException();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StackWalker, __OnStackFrame, "OnStackFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "frame", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StackWalker, __OnStackFrame)
{
	Object_wx_StackWalker *pThis = Object_wx_StackWalker::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int frame = arg.GetNumber(0)
	//pThis->GetEntity()->OnStackFrame();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStackWalker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StackWalker)
{
	Gura_AssignMethod(wx_StackWalker, __wxStackWalker);
	Gura_AssignMethod(wx_StackWalker, __Walk);
	Gura_AssignMethod(wx_StackWalker, __WalkFromException);
	Gura_AssignMethod(wx_StackWalker, __OnStackFrame);
}

Gura_ImplementDescendantCreator(wx_StackWalker)
{
	return new Object_wx_StackWalker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
