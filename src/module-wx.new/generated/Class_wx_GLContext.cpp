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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__GLContext, "GLContext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctxAttrs", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GLContext));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GLContext)
{
	//wxGLCanvas* win = arg.GetNumber(0)
	//const wxGLContext* other = arg.GetNumber(1)
	//const wxGLContextAttrs* ctxAttrs = arg.GetNumber(2)
	//wxGLContext(win, other, ctxAttrs);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
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
	//const wxGLCanvas& win = arg.GetNumber(0)
	//pThis->GetEntity()->SetCurrent(win);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGLContext
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GLContext)
{
	// Constructor assignment
	Gura_AssignFunction(__GLContext);
	// Method assignment
	Gura_AssignMethod(wx_GLContext, __IsOK);
	Gura_AssignMethod(wx_GLContext, __SetCurrent);
}

Gura_ImplementDescendantCreator(wx_GLContext)
{
	return new Object_wx_GLContext((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
