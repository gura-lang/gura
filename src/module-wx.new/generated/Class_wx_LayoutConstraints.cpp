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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__LayoutConstraints, "LayoutConstraints")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_LayoutConstraints));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__LayoutConstraints)
{
	//wxLayoutConstraints();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_LayoutConstraints, __SatisfyConstraints, "SatisfyConstraints")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noChanges", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LayoutConstraints, __SatisfyConstraints)
{
	Object_wx_LayoutConstraints *pThis = Object_wx_LayoutConstraints::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//int* noChanges = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SatisfyConstraints(win, noChanges);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LayoutConstraints, __AreSatisfied, "AreSatisfied")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_LayoutConstraints, __AreSatisfied)
{
	Object_wx_LayoutConstraints *pThis = Object_wx_LayoutConstraints::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->AreSatisfied();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLayoutConstraints
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LayoutConstraints)
{
	// Constructor assignment
	Gura_AssignFunction(__LayoutConstraints);
	// Method assignment
	Gura_AssignMethod(wx_LayoutConstraints, __SatisfyConstraints);
	Gura_AssignMethod(wx_LayoutConstraints, __AreSatisfied);
}

Gura_ImplementDescendantCreator(wx_LayoutConstraints)
{
	return new Object_wx_LayoutConstraints((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
