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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Point2DDouble, "Point2DDouble")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Point2DDouble));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Point2DDouble)
{
	//wxPoint2DDouble();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Point2DDouble_1, "Point2DDouble_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Point2DDouble));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Point2DDouble_1)
{
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//wxPoint2DDouble();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Point2DDouble_2, "Point2DDouble_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Point2DDouble));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Point2DDouble_2)
{
	//int pt = arg.GetNumber(0)
	//wxPoint2DDouble();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Point2DDouble_3, "Point2DDouble_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Point2DDouble));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Point2DDouble_3)
{
	//int pt = arg.GetNumber(0)
	//wxPoint2DDouble();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Point2DDouble_4, "Point2DDouble_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Point2DDouble));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Point2DDouble_4)
{
	//int pt = arg.GetNumber(0)
	//wxPoint2DDouble();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Point2DDouble, __GetFloor, "GetFloor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, __GetFloor)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->GetFloor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DDouble, __GetRounded, "GetRounded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, __GetRounded)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->GetRounded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DDouble, __GetVectorLength, "GetVectorLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Point2DDouble, __GetVectorLength)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVectorLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DDouble, __GetVectorAngle, "GetVectorAngle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Point2DDouble, __GetVectorAngle)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVectorAngle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DDouble, __SetVectorLength, "SetVectorLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, __SetVectorLength)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int length = arg.GetNumber(0)
	//pThis->GetEntity()->SetVectorLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DDouble, __SetVectorAngle, "SetVectorAngle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "degrees", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, __SetVectorAngle)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int degrees = arg.GetNumber(0)
	//pThis->GetEntity()->SetVectorAngle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DDouble, __Normalize, "Normalize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Point2DDouble, __Normalize)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Normalize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DDouble, __GetDistance, "GetDistance")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, __GetDistance)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetDistance();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DDouble, __GetDistanceSquare, "GetDistanceSquare")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, __GetDistanceSquare)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetDistanceSquare();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DDouble, __GetDotProduct, "GetDotProduct")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "vec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, __GetDotProduct)
{
	Object_wx_Point2DDouble *pThis = Object_wx_Point2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int vec = arg.GetNumber(0)
	//pThis->GetEntity()->GetDotProduct();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DDouble, __GetCrossProduct, "GetCrossProduct")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "vec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DDouble, __GetCrossProduct)
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
	// Constructor assignment
	Gura_AssignFunction(__Point2DDouble);
	Gura_AssignFunction(__Point2DDouble_1);
	Gura_AssignFunction(__Point2DDouble_2);
	Gura_AssignFunction(__Point2DDouble_3);
	Gura_AssignFunction(__Point2DDouble_4);
	// Method assignment
	Gura_AssignMethod(wx_Point2DDouble, __GetFloor);
	Gura_AssignMethod(wx_Point2DDouble, __GetRounded);
	Gura_AssignMethod(wx_Point2DDouble, __GetVectorLength);
	Gura_AssignMethod(wx_Point2DDouble, __GetVectorAngle);
	Gura_AssignMethod(wx_Point2DDouble, __SetVectorLength);
	Gura_AssignMethod(wx_Point2DDouble, __SetVectorAngle);
	Gura_AssignMethod(wx_Point2DDouble, __Normalize);
	Gura_AssignMethod(wx_Point2DDouble, __GetDistance);
	Gura_AssignMethod(wx_Point2DDouble, __GetDistanceSquare);
	Gura_AssignMethod(wx_Point2DDouble, __GetDotProduct);
	Gura_AssignMethod(wx_Point2DDouble, __GetCrossProduct);
}

Gura_ImplementDescendantCreator(wx_Point2DDouble)
{
	return new Object_wx_Point2DDouble((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
