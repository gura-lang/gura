//----------------------------------------------------------------------------
// wxPoint2DInt
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPoint2DInt
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPoint2DInt
//----------------------------------------------------------------------------
Object_wx_Point2DInt::~Object_wx_Point2DInt()
{
}

Object *Object_wx_Point2DInt::Clone() const
{
	return nullptr;
}

String Object_wx_Point2DInt::ToString(bool exprFlag)
{
	String rtn("<wx.Point2DInt:");
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
Gura_DeclareMethod(wx_Point2DInt, wxPoint2DInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Point2DInt, wxPoint2DInt)
{
	Signal &sig = env.GetSignal();
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxPoint2DInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DInt, wxPoint2DInt_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, wxPoint2DInt_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->wxPoint2DInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DInt, wxPoint2DInt_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, wxPoint2DInt_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->wxPoint2DInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DInt, wxPoint2DInt_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, wxPoint2DInt_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->wxPoint2DInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DInt, GetFloor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, GetFloor)
{
	Signal &sig = env.GetSignal();
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->GetFloor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DInt, GetRounded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, GetRounded)
{
	Signal &sig = env.GetSignal();
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->GetRounded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DInt, GetVectorLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Point2DInt, GetVectorLength)
{
	Signal &sig = env.GetSignal();
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVectorLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DInt, GetVectorAngle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Point2DInt, GetVectorAngle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVectorAngle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DInt, SetVectorLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, SetVectorLength)
{
	Signal &sig = env.GetSignal();
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int length = arg.GetNumber(0)
	//pThis->GetEntity()->SetVectorLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DInt, SetVectorAngle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "degrees", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, SetVectorAngle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int degrees = arg.GetNumber(0)
	//pThis->GetEntity()->SetVectorAngle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DInt, Normalize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Point2DInt, Normalize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Normalize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DInt, GetDistance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, GetDistance)
{
	Signal &sig = env.GetSignal();
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetDistance();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DInt, GetDistanceSquare)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, GetDistanceSquare)
{
	Signal &sig = env.GetSignal();
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetDistanceSquare();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DInt, GetDotProduct)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "vec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, GetDotProduct)
{
	Signal &sig = env.GetSignal();
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int vec = arg.GetNumber(0)
	//pThis->GetEntity()->GetDotProduct();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DInt, GetCrossProduct)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "vec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, GetCrossProduct)
{
	Signal &sig = env.GetSignal();
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int vec = arg.GetNumber(0)
	//pThis->GetEntity()->GetCrossProduct();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point2DInt, wxPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Point2DInt, wxPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxPoint();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPoint2DInt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Point2DInt)
{
	Gura_AssignMethod(wx_Point2DInt, wxPoint2DInt);
	Gura_AssignMethod(wx_Point2DInt, wxPoint2DInt_1);
	Gura_AssignMethod(wx_Point2DInt, wxPoint2DInt_2);
	Gura_AssignMethod(wx_Point2DInt, wxPoint2DInt_3);
	Gura_AssignMethod(wx_Point2DInt, GetFloor);
	Gura_AssignMethod(wx_Point2DInt, GetRounded);
	Gura_AssignMethod(wx_Point2DInt, GetVectorLength);
	Gura_AssignMethod(wx_Point2DInt, GetVectorAngle);
	Gura_AssignMethod(wx_Point2DInt, SetVectorLength);
	Gura_AssignMethod(wx_Point2DInt, SetVectorAngle);
	Gura_AssignMethod(wx_Point2DInt, Normalize);
	Gura_AssignMethod(wx_Point2DInt, GetDistance);
	Gura_AssignMethod(wx_Point2DInt, GetDistanceSquare);
	Gura_AssignMethod(wx_Point2DInt, GetDotProduct);
	Gura_AssignMethod(wx_Point2DInt, GetCrossProduct);
	Gura_AssignMethod(wx_Point2DInt, wxPoint);
}

Gura_ImplementDescendantCreator(wx_Point2DInt)
{
	return new Object_wx_Point2DInt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
