//----------------------------------------------------------------------------
// wxGLContext
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGLContext
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGLContext
//----------------------------------------------------------------------------
Object_wx_GLContext::~Object_wx_GLContext()
{
}

Object *Object_wx_GLContext::Clone() const
{
	return nullptr;
}

String Object_wx_GLContext::ToString(bool exprFlag)
{
	String rtn("<wx.GLContext:");
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
Gura_DeclareMethodAlias(wx_GLContext, __wxGLContext, "wxGLContext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctxAttrs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLContext, __wxGLContext)
{
	Object_wx_GLContext *pThis = Object_wx_GLContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int other = arg.GetNumber(1)
	//int ctxAttrs = arg.GetNumber(2)
	//pThis->GetEntity()->wxGLContext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLContext, __IsOK, "IsOK")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContext, __IsOK)
{
	Object_wx_GLContext *pThis = Object_wx_GLContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOK();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLContext, __SetCurrent, "SetCurrent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLContext, __SetCurrent)
{
	Object_wx_GLContext *pThis = Object_wx_GLContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->SetCurrent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGLContext
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GLContext)
{
	Gura_AssignMethod(wx_GLContext, __wxGLContext);
	Gura_AssignMethod(wx_GLContext, __IsOK);
	Gura_AssignMethod(wx_GLContext, __SetCurrent);
}

Gura_ImplementDescendantCreator(wx_GLContext)
{
	return new Object_wx_GLContext((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
