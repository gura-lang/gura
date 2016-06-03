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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxRealPoint, "wxRealPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RealPoint));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRealPoint)
{
	//wxRealPoint();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRealPoint_1, "wxRealPoint_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RealPoint));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRealPoint_1)
{
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//wxRealPoint();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRealPoint_2, "wxRealPoint_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RealPoint));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRealPoint_2)
{
	//int pt = arg.GetNumber(0)
	//wxRealPoint();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRealPoint
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RealPoint)
{
	// Constructor assignment
	Gura_AssignFunction(__wxRealPoint);
	Gura_AssignFunction(__wxRealPoint_1);
	Gura_AssignFunction(__wxRealPoint_2);
}

Gura_ImplementDescendantCreator(wx_RealPoint)
{
	return new Object_wx_RealPoint((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
