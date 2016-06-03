//----------------------------------------------------------------------------
// wxScopedPtr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScopedPtr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScopedPtr
//----------------------------------------------------------------------------
Object_wx_ScopedPtr::~Object_wx_ScopedPtr()
{
}

Object *Object_wx_ScopedPtr::Clone() const
{
	return nullptr;
}

String Object_wx_ScopedPtr::ToString(bool exprFlag)
{
	String rtn("<wx.ScopedPtr:");
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
Gura_DeclareFunctionAlias(__ScopedPtr, "ScopedPtr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "T", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ScopedPtr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ScopedPtr)
{
	//int T = arg.GetNumber(0)
	//wxScopedPtr();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ScopedPtr, __get, "get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedPtr, __get)
{
	Object_wx_ScopedPtr *pThis = Object_wx_ScopedPtr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->get();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScopedPtr, __release, "release")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedPtr, __release)
{
	Object_wx_ScopedPtr *pThis = Object_wx_ScopedPtr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->release();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScopedPtr, __reset, "reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedPtr, __reset)
{
	Object_wx_ScopedPtr *pThis = Object_wx_ScopedPtr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScopedPtr, __swap, "swap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedPtr, __swap)
{
	Object_wx_ScopedPtr *pThis = Object_wx_ScopedPtr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int other = arg.GetNumber(0)
	//pThis->GetEntity()->swap();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxScopedPtr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScopedPtr)
{
	// Constructor assignment
	Gura_AssignFunction(__ScopedPtr);
	// Method assignment
	Gura_AssignMethod(wx_ScopedPtr, __get);
	Gura_AssignMethod(wx_ScopedPtr, __release);
	Gura_AssignMethod(wx_ScopedPtr, __reset);
	Gura_AssignMethod(wx_ScopedPtr, __swap);
}

Gura_ImplementDescendantCreator(wx_ScopedPtr)
{
	return new Object_wx_ScopedPtr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
