//----------------------------------------------------------------------------
// wxPoint
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPoint
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPoint
//----------------------------------------------------------------------------
Object_wx_Point::~Object_wx_Point()
{
}

Object *Object_wx_Point::Clone() const
{
	return nullptr;
}

String Object_wx_Point::ToString(bool exprFlag)
{
	String rtn("<wx.Point:");
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
Gura_DeclareMethod(wx_Point, wxPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Point, wxPoint)
{
	Object_wx_Point *pThis = Object_wx_Point::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point, wxPoint_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point, wxPoint_1)
{
	Object_wx_Point *pThis = Object_wx_Point::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->wxPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point, wxPoint_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point, wxPoint_2)
{
	Object_wx_Point *pThis = Object_wx_Point::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->wxPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point, IsFullySpecified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Point, IsFullySpecified)
{
	Object_wx_Point *pThis = Object_wx_Point::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFullySpecified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Point, SetDefaults)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point, SetDefaults)
{
	Object_wx_Point *pThis = Object_wx_Point::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaults();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPoint
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Point)
{
	Gura_AssignMethod(wx_Point, wxPoint);
	Gura_AssignMethod(wx_Point, wxPoint_1);
	Gura_AssignMethod(wx_Point, wxPoint_2);
	Gura_AssignMethod(wx_Point, IsFullySpecified);
	Gura_AssignMethod(wx_Point, SetDefaults);
}

Gura_ImplementDescendantCreator(wx_Point)
{
	return new Object_wx_Point((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
