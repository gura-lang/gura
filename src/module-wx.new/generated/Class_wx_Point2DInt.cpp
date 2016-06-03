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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Point2DInt, "Point2DInt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Point2DInt));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Point2DInt)
{
	//wxPoint2DInt();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Point2DInt_1, "Point2DInt_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Point2DInt));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Point2DInt_1)
{
	//wxInt32 x = arg.GetNumber(0)
	//wxInt32 y = arg.GetNumber(1)
	//wxPoint2DInt();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Point2DInt_2, "Point2DInt_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Point2DInt));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Point2DInt_2)
{
	//const wxPoint2DInt& pt = arg.GetNumber(0)
	//wxPoint2DInt();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Point2DInt_3, "Point2DInt_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Point2DInt));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Point2DInt_3)
{
	//const wxPoint& pt = arg.GetNumber(0)
	//wxPoint2DInt();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Point2DInt, __GetFloor, "GetFloor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, __GetFloor)
{
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32* x = arg.GetNumber(0)
	//wxInt32* y = arg.GetNumber(1)
	//pThis->GetEntity()->GetFloor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DInt, __GetRounded, "GetRounded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, __GetRounded)
{
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32* x = arg.GetNumber(0)
	//wxInt32* y = arg.GetNumber(1)
	//pThis->GetEntity()->GetRounded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DInt, __GetVectorLength, "GetVectorLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Point2DInt, __GetVectorLength)
{
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVectorLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DInt, __GetVectorAngle, "GetVectorAngle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Point2DInt, __GetVectorAngle)
{
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVectorAngle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DInt, __SetVectorLength, "SetVectorLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, __SetVectorLength)
{
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble length = arg.GetNumber(0)
	//pThis->GetEntity()->SetVectorLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DInt, __SetVectorAngle, "SetVectorAngle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "degrees", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, __SetVectorAngle)
{
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble degrees = arg.GetNumber(0)
	//pThis->GetEntity()->SetVectorAngle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DInt, __Normalize, "Normalize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Point2DInt, __Normalize)
{
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Normalize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DInt, __GetDistance, "GetDistance")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, __GetDistance)
{
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetDistance();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DInt, __GetDistanceSquare, "GetDistanceSquare")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, __GetDistanceSquare)
{
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetDistanceSquare();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DInt, __GetDotProduct, "GetDotProduct")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "vec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, __GetDotProduct)
{
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& vec = arg.GetNumber(0)
	//pThis->GetEntity()->GetDotProduct();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DInt, __GetCrossProduct, "GetCrossProduct")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "vec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point2DInt, __GetCrossProduct)
{
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& vec = arg.GetNumber(0)
	//pThis->GetEntity()->GetCrossProduct();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point2DInt, __wxPoint, "wxPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Point2DInt, __wxPoint)
{
	Object_wx_Point2DInt *pThis = Object_wx_Point2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxPoint();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPoint2DInt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Point2DInt)
{
	// Constructor assignment
	Gura_AssignFunction(__Point2DInt);
	Gura_AssignFunction(__Point2DInt_1);
	Gura_AssignFunction(__Point2DInt_2);
	Gura_AssignFunction(__Point2DInt_3);
	// Method assignment
	Gura_AssignMethod(wx_Point2DInt, __GetFloor);
	Gura_AssignMethod(wx_Point2DInt, __GetRounded);
	Gura_AssignMethod(wx_Point2DInt, __GetVectorLength);
	Gura_AssignMethod(wx_Point2DInt, __GetVectorAngle);
	Gura_AssignMethod(wx_Point2DInt, __SetVectorLength);
	Gura_AssignMethod(wx_Point2DInt, __SetVectorAngle);
	Gura_AssignMethod(wx_Point2DInt, __Normalize);
	Gura_AssignMethod(wx_Point2DInt, __GetDistance);
	Gura_AssignMethod(wx_Point2DInt, __GetDistanceSquare);
	Gura_AssignMethod(wx_Point2DInt, __GetDotProduct);
	Gura_AssignMethod(wx_Point2DInt, __GetCrossProduct);
	Gura_AssignMethod(wx_Point2DInt, __wxPoint);
}

Gura_ImplementDescendantCreator(wx_Point2DInt)
{
	return new Object_wx_Point2DInt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
