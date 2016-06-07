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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__IndividualLayoutConstraint, "IndividualLayoutConstraint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_IndividualLayoutConstraint));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__IndividualLayoutConstraint)
{
	//wxIndividualLayoutConstraint();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rel", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "otherW", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "otherE", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __Set)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRelationship rel = arg.GetNumber(0)
	//wxWindow* otherW = arg.GetNumber(1)
	//wxEdge otherE = arg.GetNumber(2)
	//int val = arg.GetNumber(3)
	//int margin = arg.GetNumber(4)
	//pThis->GetEntity()->Set(rel, otherW, otherE, val, margin);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __LeftOf, "LeftOf")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sibling", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __LeftOf)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* sibling = arg.GetNumber(0)
	//int margin = arg.GetNumber(1)
	//pThis->GetEntity()->LeftOf(sibling, margin);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __RightOf, "RightOf")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sibling", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __RightOf)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* sibling = arg.GetNumber(0)
	//int margin = arg.GetNumber(1)
	//pThis->GetEntity()->RightOf(sibling, margin);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __Above, "Above")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sibling", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __Above)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* sibling = arg.GetNumber(0)
	//int margin = arg.GetNumber(1)
	//pThis->GetEntity()->Above(sibling, margin);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __Below, "Below")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sibling", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __Below)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* sibling = arg.GetNumber(0)
	//int margin = arg.GetNumber(1)
	//pThis->GetEntity()->Below(sibling, margin);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __SameAs, "SameAs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "otherW", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __SameAs)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* otherW = arg.GetNumber(0)
	//wxEdge edge = arg.GetNumber(1)
	//int margin = arg.GetNumber(2)
	//pThis->GetEntity()->SameAs(otherW, edge, margin);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __PercentOf, "PercentOf")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "otherW", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wh", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "per", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __PercentOf)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* otherW = arg.GetNumber(0)
	//wxEdge wh = arg.GetNumber(1)
	//int per = arg.GetNumber(2)
	//pThis->GetEntity()->PercentOf(otherW, wh, per);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __Absolute, "Absolute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __Absolute)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->Absolute(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __Unconstrained, "Unconstrained")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __Unconstrained)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Unconstrained();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __AsIs, "AsIs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __AsIs)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AsIs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __GetOtherWindow, "GetOtherWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __GetOtherWindow)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* _rtn = pThis->GetEntity()->GetOtherWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __GetMyEdge, "GetMyEdge")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __GetMyEdge)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxEdge _rtn = pThis->GetEntity()->GetMyEdge();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __SetEdge, "SetEdge")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __SetEdge)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxEdge which = arg.GetNumber(0)
	//pThis->GetEntity()->SetEdge(which);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __SetValue)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int v = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue(v);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __GetMargin, "GetMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __GetMargin)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __SetMargin, "SetMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "m", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __SetMargin)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int m = arg.GetNumber(0)
	//pThis->GetEntity()->SetMargin(m);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __GetValue)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __GetPercent, "GetPercent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __GetPercent)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetPercent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __GetOtherEdge, "GetOtherEdge")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __GetOtherEdge)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetOtherEdge();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __GetDone, "GetDone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __GetDone)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetDone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __SetDone, "SetDone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __SetDone)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool d = arg.GetNumber(0)
	//pThis->GetEntity()->SetDone(d);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __GetRelationship, "GetRelationship")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __GetRelationship)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRelationship _rtn = pThis->GetEntity()->GetRelationship();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __SetRelationship, "SetRelationship")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __SetRelationship)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRelationship r = arg.GetNumber(0)
	//pThis->GetEntity()->SetRelationship(r);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __ResetIfWin, "ResetIfWin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "otherW", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __ResetIfWin)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* otherW = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->ResetIfWin(otherW);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __SatisfyConstraint, "SatisfyConstraint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "constraints", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __SatisfyConstraint)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxLayoutConstraints* constraints = arg.GetNumber(0)
	//wxWindow* win = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SatisfyConstraint(constraints, win);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IndividualLayoutConstraint, __GetEdge, "GetEdge")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "thisWin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, __GetEdge)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxEdge which = arg.GetNumber(0)
	//wxWindow* thisWin = arg.GetNumber(1)
	//wxWindow* other = arg.GetNumber(2)
	//int _rtn = pThis->GetEntity()->GetEdge(which, thisWin, other);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxIndividualLayoutConstraint
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IndividualLayoutConstraint)
{
	// Constructor assignment
	Gura_AssignFunction(__IndividualLayoutConstraint);
	// Method assignment
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __Set);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __LeftOf);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __RightOf);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __Above);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __Below);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __SameAs);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __PercentOf);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __Absolute);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __Unconstrained);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __AsIs);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __GetOtherWindow);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __GetMyEdge);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __SetEdge);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __SetValue);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __GetMargin);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __SetMargin);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __GetValue);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __GetPercent);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __GetOtherEdge);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __GetDone);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __SetDone);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __GetRelationship);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __SetRelationship);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __ResetIfWin);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __SatisfyConstraint);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, __GetEdge);
}

Gura_ImplementDescendantCreator(wx_IndividualLayoutConstraint)
{
	return new Object_wx_IndividualLayoutConstraint((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
