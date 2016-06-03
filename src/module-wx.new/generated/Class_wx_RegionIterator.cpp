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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RegionIterator, "RegionIterator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RegionIterator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RegionIterator)
{
	//wxRegionIterator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RegionIterator_1, "RegionIterator_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RegionIterator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RegionIterator_1)
{
	//const wxRegion& region = arg.GetNumber(0)
	//wxRegionIterator();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RegionIterator, __GetH, "GetH")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, __GetH)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetH();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegionIterator, __GetHeight, "GetHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, __GetHeight)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegionIterator, __GetRect, "GetRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, __GetRect)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegionIterator, __GetW, "GetW")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, __GetW)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetW();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegionIterator, __GetWidth, "GetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, __GetWidth)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegionIterator, __GetX, "GetX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, __GetX)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegionIterator, __GetY, "GetY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, __GetY)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegionIterator, __HaveRects, "HaveRects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, __HaveRects)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HaveRects();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegionIterator, __Reset, "Reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, __Reset)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegionIterator, __Reset_1, "Reset_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegionIterator, __Reset_1)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRegion& region = arg.GetNumber(0)
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegionIterator, __bool, "bool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, __bool)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->bool();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRegionIterator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RegionIterator)
{
	// Constructor assignment
	Gura_AssignFunction(__RegionIterator);
	Gura_AssignFunction(__RegionIterator_1);
	// Method assignment
	Gura_AssignMethod(wx_RegionIterator, __GetH);
	Gura_AssignMethod(wx_RegionIterator, __GetHeight);
	Gura_AssignMethod(wx_RegionIterator, __GetRect);
	Gura_AssignMethod(wx_RegionIterator, __GetW);
	Gura_AssignMethod(wx_RegionIterator, __GetWidth);
	Gura_AssignMethod(wx_RegionIterator, __GetX);
	Gura_AssignMethod(wx_RegionIterator, __GetY);
	Gura_AssignMethod(wx_RegionIterator, __HaveRects);
	Gura_AssignMethod(wx_RegionIterator, __Reset);
	Gura_AssignMethod(wx_RegionIterator, __Reset_1);
	Gura_AssignMethod(wx_RegionIterator, __bool);
}

Gura_ImplementDescendantCreator(wx_RegionIterator)
{
	return new Object_wx_RegionIterator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
