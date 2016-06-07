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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Point, "Point")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Point));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Point)
{
	//wxPoint();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Point_1, "Point_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Point));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Point_1)
{
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//wxPoint(x, y);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Point_2, "Point_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Point));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Point_2)
{
	//const wxRealPoint& pt = arg.GetNumber(0)
	//wxPoint(pt);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Point, __IsFullySpecified, "IsFullySpecified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Point, __IsFullySpecified)
{
	Object_wx_Point *pThis = Object_wx_Point::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsFullySpecified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Point, __SetDefaults, "SetDefaults")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Point, __SetDefaults)
{
	Object_wx_Point *pThis = Object_wx_Point::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaults(pt);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPoint
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Point)
{
	// Constructor assignment
	Gura_AssignFunction(__Point);
	Gura_AssignFunction(__Point_1);
	Gura_AssignFunction(__Point_2);
	// Method assignment
	Gura_AssignMethod(wx_Point, __IsFullySpecified);
	Gura_AssignMethod(wx_Point, __SetDefaults);
}

Gura_ImplementDescendantCreator(wx_Point)
{
	return new Object_wx_Point((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
