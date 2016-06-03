//----------------------------------------------------------------------------
// wxDCClipper
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDCClipper
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDCClipper
//----------------------------------------------------------------------------
Object_wx_DCClipper::~Object_wx_DCClipper()
{
}

Object *Object_wx_DCClipper::Clone() const
{
	return nullptr;
}

String Object_wx_DCClipper::ToString(bool exprFlag)
{
	String rtn("<wx.DCClipper:");
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
Gura_DeclareFunctionAlias(__DCClipper, "DCClipper")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DCClipper));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DCClipper)
{
	//int dc = arg.GetNumber(0)
	//int region = arg.GetNumber(1)
	//wxDCClipper();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DCClipper_1, "DCClipper_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DCClipper));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DCClipper_1)
{
	//int dc = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//wxDCClipper();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DCClipper_2, "DCClipper_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DCClipper));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DCClipper_2)
{
	//int dc = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//int w = arg.GetNumber(3)
	//int h = arg.GetNumber(4)
	//wxDCClipper();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDCClipper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DCClipper)
{
	// Constructor assignment
	Gura_AssignFunction(__DCClipper);
	Gura_AssignFunction(__DCClipper_1);
	Gura_AssignFunction(__DCClipper_2);
}

Gura_ImplementDescendantCreator(wx_DCClipper)
{
	return new Object_wx_DCClipper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
