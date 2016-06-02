//----------------------------------------------------------------------------
// wxPoint2DDouble
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPoint2DDouble
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPoint2DDouble
//----------------------------------------------------------------------------
Object_wx_Point2DDouble::~Object_wx_Point2DDouble()
{
}

Object *Object_wx_Point2DDouble::Clone() const
{
	return nullptr;
}

String Object_wx_Point2DDouble::ToString(bool exprFlag)
{
	String rtn("<wx.Point2DDouble:");
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
Gura_DeclareMethod(wx_Point2DDouble, wxPoint2DDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Point2DDouble, wxPoint2DDouble)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxPoint2DDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DDouble, wxPoint2DDouble_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, wxPoint2DDouble_1)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->wxPoint2DDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DDouble, wxPoint2DDouble_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, wxPoint2DDouble_2)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->wxPoint2DDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DDouble, wxPoint2DDouble_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, wxPoint2DDouble_3)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->wxPoint2DDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DDouble, wxPoint2DDouble_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, wxPoint2DDouble_4)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->wxPoint2DDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DDouble, GetFloor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, GetFloor)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->GetFloor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DDouble, GetRounded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, GetRounded)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->GetRounded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DDouble, GetVectorLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Point2DDouble, GetVectorLength)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVectorLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DDouble, GetVectorAngle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Point2DDouble, GetVectorAngle)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVectorAngle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DDouble, SetVectorLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, SetVectorLength)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int length = arg.GetNumber(0)
	//pThis->GetEntity()->SetVectorLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DDouble, SetVectorAngle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "degrees", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, SetVectorAngle)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int degrees = arg.GetNumber(0)
	//pThis->GetEntity()->SetVectorAngle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DDouble, Normalize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Point2DDouble, Normalize)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Normalize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DDouble, GetDistance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, GetDistance)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetDistance();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DDouble, GetDistanceSquare)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, GetDistanceSquare)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetDistanceSquare();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DDouble, GetDotProduct)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "vec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, GetDotProduct)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int vec = arg.GetNumber(0)
	//pThis->GetEntity()->GetDotProduct();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DDouble, GetCrossProduct)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "vec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, GetCrossProduct)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int vec = arg.GetNumber(0)
	//pThis->GetEntity()->GetCrossProduct();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPoint2DDouble
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Point2DDouble)
{
	Gura_AssignMethod(wx_Point2DDouble, wxPoint2DDouble);
	Gura_AssignMethod(wx_Point2DDouble, wxPoint2DDouble_1);
	Gura_AssignMethod(wx_Point2DDouble, wxPoint2DDouble_2);
	Gura_AssignMethod(wx_Point2DDouble, wxPoint2DDouble_3);
	Gura_AssignMethod(wx_Point2DDouble, wxPoint2DDouble_4);
	Gura_AssignMethod(wx_Point2DDouble, GetFloor);
	Gura_AssignMethod(wx_Point2DDouble, GetRounded);
	Gura_AssignMethod(wx_Point2DDouble, GetVectorLength);
	Gura_AssignMethod(wx_Point2DDouble, GetVectorAngle);
	Gura_AssignMethod(wx_Point2DDouble, SetVectorLength);
	Gura_AssignMethod(wx_Point2DDouble, SetVectorAngle);
	Gura_AssignMethod(wx_Point2DDouble, Normalize);
	Gura_AssignMethod(wx_Point2DDouble, GetDistance);
	Gura_AssignMethod(wx_Point2DDouble, GetDistanceSquare);
	Gura_AssignMethod(wx_Point2DDouble, GetDotProduct);
	Gura_AssignMethod(wx_Point2DDouble, GetCrossProduct);
}

Gura_ImplementDescendantCreator(wx_Point2DDouble)
{
	return new Object_wx_Point2DDouble((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
