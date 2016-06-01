//----------------------------------------------------------------------------
// wxLayoutConstraints
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLayoutConstraints
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLayoutConstraints
//----------------------------------------------------------------------------
Object_wx_LayoutConstraints::~Object_wx_LayoutConstraints()
{
}

Object *Object_wx_LayoutConstraints::Clone() const
{
	return nullptr;
}

String Object_wx_LayoutConstraints::ToString(bool exprFlag)
{
	String rtn("<wx.LayoutConstraints:");
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
Gura_DeclareMethod(wx_LayoutConstraints, wxLayoutConstraints)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LayoutConstraints, wxLayoutConstraints)
{
	Signal &sig = env.GetSignal();
	Object_wx_LayoutConstraints *pThis = Object_wx_LayoutConstraints::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxLayoutConstraints();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LayoutConstraints, ~wxLayoutConstraints)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LayoutConstraints, ~wxLayoutConstraints)
{
	Signal &sig = env.GetSignal();
	Object_wx_LayoutConstraints *pThis = Object_wx_LayoutConstraints::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxLayoutConstraints();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LayoutConstraints, SatisfyConstraints)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noChanges", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LayoutConstraints, SatisfyConstraints)
{
	Signal &sig = env.GetSignal();
	Object_wx_LayoutConstraints *pThis = Object_wx_LayoutConstraints::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int noChanges = arg.GetNumber(1)
	//pThis->GetEntity()->SatisfyConstraints();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LayoutConstraints, AreSatisfied)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LayoutConstraints, AreSatisfied)
{
	Signal &sig = env.GetSignal();
	Object_wx_LayoutConstraints *pThis = Object_wx_LayoutConstraints::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AreSatisfied();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLayoutConstraints
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LayoutConstraints)
{
	Gura_AssignMethod(wx_LayoutConstraints, wxLayoutConstraints);
	Gura_AssignMethod(wx_LayoutConstraints, ~wxLayoutConstraints);
	Gura_AssignMethod(wx_LayoutConstraints, SatisfyConstraints);
	Gura_AssignMethod(wx_LayoutConstraints, AreSatisfied);
}

Gura_ImplementDescendantCreator(wx_LayoutConstraints)
{
	return new Object_wx_LayoutConstraints((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
