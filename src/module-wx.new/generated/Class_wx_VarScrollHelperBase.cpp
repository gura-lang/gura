//----------------------------------------------------------------------------
// wxVarScrollHelperBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVarScrollHelperBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVarScrollHelperBase
//----------------------------------------------------------------------------
Object_wx_VarScrollHelperBase::~Object_wx_VarScrollHelperBase()
{
}

Object *Object_wx_VarScrollHelperBase::Clone() const
{
	return nullptr;
}

String Object_wx_VarScrollHelperBase::ToString(bool exprFlag)
{
	String rtn("<wx.VarScrollHelperBase:");
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
Gura_DeclareMethod(wx_VarScrollHelperBase, wxVarScrollHelperBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "winToScroll", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, wxVarScrollHelperBase)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int winToScroll = arg.GetNumber(0)
	//pThis->GetEntity()->wxVarScrollHelperBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarScrollHelperBase, ~wxVarScrollHelperBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, ~wxVarScrollHelperBase)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxVarScrollHelperBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarScrollHelperBase, CalcScrolledPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "coord", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, CalcScrolledPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int coord = arg.GetNumber(0)
	//pThis->GetEntity()->CalcScrolledPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarScrollHelperBase, CalcUnscrolledPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "coord", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, CalcUnscrolledPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int coord = arg.GetNumber(0)
	//pThis->GetEntity()->CalcUnscrolledPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarScrollHelperBase, EnablePhysicalScrolling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "scrolling", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, EnablePhysicalScrolling)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int scrolling = arg.GetNumber(0)
	//pThis->GetEntity()->EnablePhysicalScrolling();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarScrollHelperBase, GetNonOrientationTargetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, GetNonOrientationTargetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNonOrientationTargetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarScrollHelperBase, GetOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, GetOrientation)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOrientation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarScrollHelperBase, GetOrientationTargetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, GetOrientationTargetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOrientationTargetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarScrollHelperBase, GetTargetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, GetTargetWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTargetWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarScrollHelperBase, GetVisibleBegin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, GetVisibleBegin)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVisibleBegin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarScrollHelperBase, GetVisibleEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, GetVisibleEnd)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVisibleEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarScrollHelperBase, IsVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "unit", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, IsVisible)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int unit = arg.GetNumber(0)
	//pThis->GetEntity()->IsVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarScrollHelperBase, RefreshAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, RefreshAll)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RefreshAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarScrollHelperBase, SetTargetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "target", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, SetTargetWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int target = arg.GetNumber(0)
	//pThis->GetEntity()->SetTargetWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarScrollHelperBase, UpdateScrollbar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, UpdateScrollbar)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UpdateScrollbar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarScrollHelperBase, VirtualHitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "coord", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, VirtualHitTest)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int coord = arg.GetNumber(0)
	//pThis->GetEntity()->VirtualHitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarScrollHelperBase, OnGetUnitsSizeHint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "unitMin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "unitMax", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, OnGetUnitsSizeHint)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int unitMin = arg.GetNumber(0)
	//int unitMax = arg.GetNumber(1)
	//pThis->GetEntity()->OnGetUnitsSizeHint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarScrollHelperBase, EstimateTotalSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, EstimateTotalSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EstimateTotalSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarScrollHelperBase, OnGetUnitSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "unit", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, OnGetUnitSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int unit = arg.GetNumber(0)
	//pThis->GetEntity()->OnGetUnitSize();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVarScrollHelperBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VarScrollHelperBase)
{
	Gura_AssignMethod(wx_VarScrollHelperBase, wxVarScrollHelperBase);
	Gura_AssignMethod(wx_VarScrollHelperBase, ~wxVarScrollHelperBase);
	Gura_AssignMethod(wx_VarScrollHelperBase, CalcScrolledPosition);
	Gura_AssignMethod(wx_VarScrollHelperBase, CalcUnscrolledPosition);
	Gura_AssignMethod(wx_VarScrollHelperBase, EnablePhysicalScrolling);
	Gura_AssignMethod(wx_VarScrollHelperBase, GetNonOrientationTargetSize);
	Gura_AssignMethod(wx_VarScrollHelperBase, GetOrientation);
	Gura_AssignMethod(wx_VarScrollHelperBase, GetOrientationTargetSize);
	Gura_AssignMethod(wx_VarScrollHelperBase, GetTargetWindow);
	Gura_AssignMethod(wx_VarScrollHelperBase, GetVisibleBegin);
	Gura_AssignMethod(wx_VarScrollHelperBase, GetVisibleEnd);
	Gura_AssignMethod(wx_VarScrollHelperBase, IsVisible);
	Gura_AssignMethod(wx_VarScrollHelperBase, RefreshAll);
	Gura_AssignMethod(wx_VarScrollHelperBase, SetTargetWindow);
	Gura_AssignMethod(wx_VarScrollHelperBase, UpdateScrollbar);
	Gura_AssignMethod(wx_VarScrollHelperBase, VirtualHitTest);
	Gura_AssignMethod(wx_VarScrollHelperBase, OnGetUnitsSizeHint);
	Gura_AssignMethod(wx_VarScrollHelperBase, EstimateTotalSize);
	Gura_AssignMethod(wx_VarScrollHelperBase, OnGetUnitSize);
}

Gura_ImplementDescendantCreator(wx_VarScrollHelperBase)
{
	return new Object_wx_VarScrollHelperBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
