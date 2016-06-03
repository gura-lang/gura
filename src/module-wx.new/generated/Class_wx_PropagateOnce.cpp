//----------------------------------------------------------------------------
// wxPropagateOnce
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropagateOnce
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropagateOnce
//----------------------------------------------------------------------------
Object_wx_PropagateOnce::~Object_wx_PropagateOnce()
{
}

Object *Object_wx_PropagateOnce::Clone() const
{
	return nullptr;
}

String Object_wx_PropagateOnce::ToString(bool exprFlag)
{
	String rtn("<wx.PropagateOnce:");
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
Gura_DeclareMethodAlias(wx_PropagateOnce, __wxPropagateOnce, "wxPropagateOnce")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropagateOnce, __wxPropagateOnce)
{
	Object_wx_PropagateOnce *pThis = Object_wx_PropagateOnce::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->wxPropagateOnce();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPropagateOnce
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropagateOnce)
{
	Gura_AssignMethod(wx_PropagateOnce, __wxPropagateOnce);
}

Gura_ImplementDescendantCreator(wx_PropagateOnce)
{
	return new Object_wx_PropagateOnce((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
