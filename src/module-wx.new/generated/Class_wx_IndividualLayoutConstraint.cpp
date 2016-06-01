//----------------------------------------------------------------------------
// wxIndividualLayoutConstraint
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxIndividualLayoutConstraint
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxIndividualLayoutConstraint
//----------------------------------------------------------------------------
Object_wx_IndividualLayoutConstraint::~Object_wx_IndividualLayoutConstraint()
{
}

Object *Object_wx_IndividualLayoutConstraint::Clone() const
{
	return nullptr;
}

String Object_wx_IndividualLayoutConstraint::ToString(bool exprFlag)
{
	String rtn("<wx.IndividualLayoutConstraint:");
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
Gura_DeclareMethod(wx_IndividualLayoutConstraint, wxIndividualLayoutConstraint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, wxIndividualLayoutConstraint)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxIndividualLayoutConstraint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, ~wxIndividualLayoutConstraint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, ~wxIndividualLayoutConstraint)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxIndividualLayoutConstraint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rel", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "otherW", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "otherE", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rel = arg.GetNumber(0)
	//int otherW = arg.GetNumber(1)
	//int otherE = arg.GetNumber(2)
	//int val = arg.GetNumber(3)
	//int margin = arg.GetNumber(4)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, LeftOf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sibling", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, LeftOf)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sibling = arg.GetNumber(0)
	//int margin = arg.GetNumber(1)
	//pThis->GetEntity()->LeftOf();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, RightOf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sibling", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, RightOf)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sibling = arg.GetNumber(0)
	//int margin = arg.GetNumber(1)
	//pThis->GetEntity()->RightOf();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, Above)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sibling", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, Above)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sibling = arg.GetNumber(0)
	//int margin = arg.GetNumber(1)
	//pThis->GetEntity()->Above();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, Below)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sibling", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, Below)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sibling = arg.GetNumber(0)
	//int margin = arg.GetNumber(1)
	//pThis->GetEntity()->Below();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, SameAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "otherW", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, SameAs)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int otherW = arg.GetNumber(0)
	//int edge = arg.GetNumber(1)
	//int margin = arg.GetNumber(2)
	//pThis->GetEntity()->SameAs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, PercentOf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "otherW", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wh", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "per", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, PercentOf)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int otherW = arg.GetNumber(0)
	//int wh = arg.GetNumber(1)
	//int per = arg.GetNumber(2)
	//pThis->GetEntity()->PercentOf();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, Absolute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, Absolute)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->Absolute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, Unconstrained)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, Unconstrained)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Unconstrained();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, AsIs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, AsIs)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AsIs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, GetOtherWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, GetOtherWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOtherWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, GetMyEdge)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, GetMyEdge)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMyEdge();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, SetEdge)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, SetEdge)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int which = arg.GetNumber(0)
	//pThis->GetEntity()->SetEdge();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int v = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, GetMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, GetMargin)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, SetMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "m", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, SetMargin)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int m = arg.GetNumber(0)
	//pThis->GetEntity()->SetMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, GetPercent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, GetPercent)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPercent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, GetOtherEdge)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, GetOtherEdge)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOtherEdge();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, GetDone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, GetDone)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, SetDone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, SetDone)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int d = arg.GetNumber(0)
	//pThis->GetEntity()->SetDone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, GetRelationship)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, GetRelationship)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRelationship();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, SetRelationship)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, SetRelationship)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int r = arg.GetNumber(0)
	//pThis->GetEntity()->SetRelationship();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, ResetIfWin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "otherW", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, ResetIfWin)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int otherW = arg.GetNumber(0)
	//pThis->GetEntity()->ResetIfWin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, SatisfyConstraint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "constraints", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, SatisfyConstraint)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int constraints = arg.GetNumber(0)
	//int win = arg.GetNumber(1)
	//pThis->GetEntity()->SatisfyConstraint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, GetEdge)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "thisWin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, GetEdge)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int which = arg.GetNumber(0)
	//int thisWin = arg.GetNumber(1)
	//int other = arg.GetNumber(2)
	//pThis->GetEntity()->GetEdge();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxIndividualLayoutConstraint
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IndividualLayoutConstraint)
{
	Gura_AssignMethod(wx_IndividualLayoutConstraint, wxIndividualLayoutConstraint);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, ~wxIndividualLayoutConstraint);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, Set);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, LeftOf);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, RightOf);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, Above);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, Below);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, SameAs);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, PercentOf);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, Absolute);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, Unconstrained);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, AsIs);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, GetOtherWindow);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, GetMyEdge);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, SetEdge);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, SetValue);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, GetMargin);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, SetMargin);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, GetValue);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, GetPercent);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, GetOtherEdge);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, GetDone);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, SetDone);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, GetRelationship);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, SetRelationship);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, ResetIfWin);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, SatisfyConstraint);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, GetEdge);
}

Gura_ImplementDescendantCreator(wx_IndividualLayoutConstraint)
{
	return new Object_wx_IndividualLayoutConstraint((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
