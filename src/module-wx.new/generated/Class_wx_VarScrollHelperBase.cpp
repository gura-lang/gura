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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxVarScrollHelperBase, "wxVarScrollHelperBase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "winToScroll", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_VarScrollHelperBase));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxVarScrollHelperBase)
{
	//int winToScroll = arg.GetNumber(0)
	//wxVarScrollHelperBase();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_VarScrollHelperBase, __CalcScrolledPosition, "CalcScrolledPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "coord", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, __CalcScrolledPosition)
{
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int coord = arg.GetNumber(0)
	//pThis->GetEntity()->CalcScrolledPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarScrollHelperBase, __CalcUnscrolledPosition, "CalcUnscrolledPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "coord", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, __CalcUnscrolledPosition)
{
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int coord = arg.GetNumber(0)
	//pThis->GetEntity()->CalcUnscrolledPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarScrollHelperBase, __EnablePhysicalScrolling, "EnablePhysicalScrolling")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "scrolling", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, __EnablePhysicalScrolling)
{
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int scrolling = arg.GetNumber(0)
	//pThis->GetEntity()->EnablePhysicalScrolling();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarScrollHelperBase, __GetNonOrientationTargetSize, "GetNonOrientationTargetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, __GetNonOrientationTargetSize)
{
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNonOrientationTargetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarScrollHelperBase, __GetOrientation, "GetOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, __GetOrientation)
{
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOrientation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarScrollHelperBase, __GetOrientationTargetSize, "GetOrientationTargetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, __GetOrientationTargetSize)
{
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOrientationTargetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarScrollHelperBase, __GetTargetWindow, "GetTargetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, __GetTargetWindow)
{
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTargetWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarScrollHelperBase, __GetVisibleBegin, "GetVisibleBegin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, __GetVisibleBegin)
{
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVisibleBegin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarScrollHelperBase, __GetVisibleEnd, "GetVisibleEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, __GetVisibleEnd)
{
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVisibleEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarScrollHelperBase, __IsVisible, "IsVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "unit", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, __IsVisible)
{
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int unit = arg.GetNumber(0)
	//pThis->GetEntity()->IsVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarScrollHelperBase, __RefreshAll, "RefreshAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, __RefreshAll)
{
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RefreshAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarScrollHelperBase, __SetTargetWindow, "SetTargetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "target", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, __SetTargetWindow)
{
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int target = arg.GetNumber(0)
	//pThis->GetEntity()->SetTargetWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarScrollHelperBase, __UpdateScrollbar, "UpdateScrollbar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, __UpdateScrollbar)
{
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UpdateScrollbar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarScrollHelperBase, __VirtualHitTest, "VirtualHitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "coord", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, __VirtualHitTest)
{
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int coord = arg.GetNumber(0)
	//pThis->GetEntity()->VirtualHitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarScrollHelperBase, __OnGetUnitsSizeHint, "OnGetUnitsSizeHint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "unitMin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "unitMax", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, __OnGetUnitsSizeHint)
{
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int unitMin = arg.GetNumber(0)
	//int unitMax = arg.GetNumber(1)
	//pThis->GetEntity()->OnGetUnitsSizeHint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarScrollHelperBase, __EstimateTotalSize, "EstimateTotalSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, __EstimateTotalSize)
{
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EstimateTotalSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarScrollHelperBase, __OnGetUnitSize, "OnGetUnitSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "unit", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarScrollHelperBase, __OnGetUnitSize)
{
	Object_wx_VarScrollHelperBase *pThis = Object_wx_VarScrollHelperBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int unit = arg.GetNumber(0)
	//pThis->GetEntity()->OnGetUnitSize();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVarScrollHelperBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VarScrollHelperBase)
{
	// Constructor assignment
	Gura_AssignFunction(__wxVarScrollHelperBase);
	// Method assignment
	Gura_AssignMethod(wx_VarScrollHelperBase, __CalcScrolledPosition);
	Gura_AssignMethod(wx_VarScrollHelperBase, __CalcUnscrolledPosition);
	Gura_AssignMethod(wx_VarScrollHelperBase, __EnablePhysicalScrolling);
	Gura_AssignMethod(wx_VarScrollHelperBase, __GetNonOrientationTargetSize);
	Gura_AssignMethod(wx_VarScrollHelperBase, __GetOrientation);
	Gura_AssignMethod(wx_VarScrollHelperBase, __GetOrientationTargetSize);
	Gura_AssignMethod(wx_VarScrollHelperBase, __GetTargetWindow);
	Gura_AssignMethod(wx_VarScrollHelperBase, __GetVisibleBegin);
	Gura_AssignMethod(wx_VarScrollHelperBase, __GetVisibleEnd);
	Gura_AssignMethod(wx_VarScrollHelperBase, __IsVisible);
	Gura_AssignMethod(wx_VarScrollHelperBase, __RefreshAll);
	Gura_AssignMethod(wx_VarScrollHelperBase, __SetTargetWindow);
	Gura_AssignMethod(wx_VarScrollHelperBase, __UpdateScrollbar);
	Gura_AssignMethod(wx_VarScrollHelperBase, __VirtualHitTest);
	Gura_AssignMethod(wx_VarScrollHelperBase, __OnGetUnitsSizeHint);
	Gura_AssignMethod(wx_VarScrollHelperBase, __EstimateTotalSize);
	Gura_AssignMethod(wx_VarScrollHelperBase, __OnGetUnitSize);
}

Gura_ImplementDescendantCreator(wx_VarScrollHelperBase)
{
	return new Object_wx_VarScrollHelperBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
