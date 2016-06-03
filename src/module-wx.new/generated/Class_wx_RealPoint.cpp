//----------------------------------------------------------------------------
// wxRealPoint
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRealPoint
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRealPoint
//----------------------------------------------------------------------------
Object_wx_RealPoint::~Object_wx_RealPoint()
{
}

Object *Object_wx_RealPoint::Clone() const
{
	return nullptr;
}

String Object_wx_RealPoint::ToString(bool exprFlag)
{
	String rtn("<wx.RealPoint:");
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
Gura_DeclareMethodAlias(wx_RealPoint, __wxRealPoint, "wxRealPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RealPoint, __wxRealPoint)
{
	Object_wx_RealPoint *pThis = Object_wx_RealPoint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRealPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RealPoint, __wxRealPoint_1, "wxRealPoint_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RealPoint, __wxRealPoint_1)
{
	Object_wx_RealPoint *pThis = Object_wx_RealPoint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->wxRealPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RealPoint, __wxRealPoint_2, "wxRealPoint_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RealPoint, __wxRealPoint_2)
{
	Object_wx_RealPoint *pThis = Object_wx_RealPoint::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->wxRealPoint();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRealPoint
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RealPoint)
{
	Gura_AssignMethod(wx_RealPoint, __wxRealPoint);
	Gura_AssignMethod(wx_RealPoint, __wxRealPoint_1);
	Gura_AssignMethod(wx_RealPoint, __wxRealPoint_2);
}

Gura_ImplementDescendantCreator(wx_RealPoint)
{
	return new Object_wx_RealPoint((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
