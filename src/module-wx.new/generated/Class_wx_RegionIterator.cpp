//----------------------------------------------------------------------------
// wxRegionIterator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRegionIterator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRegionIterator
//----------------------------------------------------------------------------
Object_wx_RegionIterator::~Object_wx_RegionIterator()
{
}

Object *Object_wx_RegionIterator::Clone() const
{
	return nullptr;
}

String Object_wx_RegionIterator::ToString(bool exprFlag)
{
	String rtn("<wx.RegionIterator:");
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
Gura_DeclareMethod(wx_RegionIterator, wxRegionIterator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, wxRegionIterator)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRegionIterator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegionIterator, wxRegionIterator_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegionIterator, wxRegionIterator_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int region = arg.GetNumber(0)
	//pThis->GetEntity()->wxRegionIterator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegionIterator, GetH)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, GetH)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetH();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegionIterator, GetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, GetHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegionIterator, GetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, GetRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegionIterator, GetW)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, GetW)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetW();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegionIterator, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, GetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegionIterator, GetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, GetX)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegionIterator, GetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, GetY)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegionIterator, HaveRects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, HaveRects)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HaveRects();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegionIterator, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, Reset)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegionIterator, Reset_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegionIterator, Reset_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int region = arg.GetNumber(0)
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegionIterator, bool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, bool)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->bool();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRegionIterator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RegionIterator)
{
	Gura_AssignMethod(wx_RegionIterator, wxRegionIterator);
	Gura_AssignMethod(wx_RegionIterator, wxRegionIterator_1);
	Gura_AssignMethod(wx_RegionIterator, GetH);
	Gura_AssignMethod(wx_RegionIterator, GetHeight);
	Gura_AssignMethod(wx_RegionIterator, GetRect);
	Gura_AssignMethod(wx_RegionIterator, GetW);
	Gura_AssignMethod(wx_RegionIterator, GetWidth);
	Gura_AssignMethod(wx_RegionIterator, GetX);
	Gura_AssignMethod(wx_RegionIterator, GetY);
	Gura_AssignMethod(wx_RegionIterator, HaveRects);
	Gura_AssignMethod(wx_RegionIterator, Reset);
	Gura_AssignMethod(wx_RegionIterator, Reset_1);
	Gura_AssignMethod(wx_RegionIterator, bool);
}

Gura_ImplementDescendantCreator(wx_RegionIterator)
{
	return new Object_wx_RegionIterator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
