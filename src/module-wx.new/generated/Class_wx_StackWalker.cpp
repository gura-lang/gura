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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__StackWalker, "StackWalker")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "argv0", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_StackWalker));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StackWalker)
{
	//const char* argv0 = arg.GetNumber(0)
	//wxStackWalker(argv0);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
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
	//size_t skip = arg.GetNumber(0)
	//size_t maxDepth = arg.GetNumber(1)
	//pThis->GetEntity()->Walk(skip, maxDepth);
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
	//size_t maxDepth = arg.GetNumber(0)
	//pThis->GetEntity()->WalkFromException(maxDepth);
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
	//const wxStackFrame& frame = arg.GetNumber(0)
	//pThis->GetEntity()->OnStackFrame(frame);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStackWalker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StackWalker)
{
	// Constructor assignment
	Gura_AssignFunction(__StackWalker);
	// Method assignment
	Gura_AssignMethod(wx_StackWalker, __Walk);
	Gura_AssignMethod(wx_StackWalker, __WalkFromException);
	Gura_AssignMethod(wx_StackWalker, __OnStackFrame);
}

Gura_ImplementDescendantCreator(wx_StackWalker)
{
	return new Object_wx_StackWalker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
