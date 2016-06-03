//----------------------------------------------------------------------------
// wxScopeGuard
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScopeGuard
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScopeGuard
//----------------------------------------------------------------------------
Object_wx_ScopeGuard::~Object_wx_ScopeGuard()
{
}

Object *Object_wx_ScopeGuard::Clone() const
{
	return nullptr;
}

String Object_wx_ScopeGuard::ToString(bool exprFlag)
{
	String rtn("<wx.ScopeGuard:");
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
Gura_DeclareMethodAlias(wx_ScopeGuard, __Dismiss, "Dismiss")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopeGuard, __Dismiss)
{
	Object_wx_ScopeGuard *pThis = Object_wx_ScopeGuard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Dismiss();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxScopeGuard
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScopeGuard)
{
	// Method assignment
	Gura_AssignMethod(wx_ScopeGuard, __Dismiss);
}

Gura_ImplementDescendantCreator(wx_ScopeGuard)
{
	return new Object_wx_ScopeGuard((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
