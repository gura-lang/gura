//----------------------------------------------------------------------------
// wxScopedTiedPtr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScopedTiedPtr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScopedTiedPtr
//----------------------------------------------------------------------------
Object_wx_ScopedTiedPtr::~Object_wx_ScopedTiedPtr()
{
}

Object *Object_wx_ScopedTiedPtr::Clone() const
{
	return nullptr;
}

String Object_wx_ScopedTiedPtr::ToString(bool exprFlag)
{
	String rtn("<wx.ScopedTiedPtr:");
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
Gura_DeclareMethodAlias(wx_ScopedTiedPtr, __wxScopedTiedPtr, "wxScopedTiedPtr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ppTie", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedTiedPtr, __wxScopedTiedPtr)
{
	Object_wx_ScopedTiedPtr *pThis = Object_wx_ScopedTiedPtr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ppTie = arg.GetNumber(0)
	//int ptr = arg.GetNumber(1)
	//pThis->GetEntity()->wxScopedTiedPtr();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxScopedTiedPtr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScopedTiedPtr)
{
	Gura_AssignMethod(wx_ScopedTiedPtr, __wxScopedTiedPtr);
}

Gura_ImplementDescendantCreator(wx_ScopedTiedPtr)
{
	return new Object_wx_ScopedTiedPtr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
