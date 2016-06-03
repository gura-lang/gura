//----------------------------------------------------------------------------
// wxDCTextColourChanger
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDCTextColourChanger
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDCTextColourChanger
//----------------------------------------------------------------------------
Object_wx_DCTextColourChanger::~Object_wx_DCTextColourChanger()
{
}

Object *Object_wx_DCTextColourChanger::Clone() const
{
	return nullptr;
}

String Object_wx_DCTextColourChanger::ToString(bool exprFlag)
{
	String rtn("<wx.DCTextColourChanger:");
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
Gura_DeclareFunctionAlias(__wxDCTextColourChanger, "wxDCTextColourChanger")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxDCTextColourChanger)
{
	//int dc = arg.GetNumber(0)
	//wxDCTextColourChanger();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxDCTextColourChanger_1, "wxDCTextColourChanger_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxDCTextColourChanger_1)
{
	//int dc = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//wxDCTextColourChanger();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DCTextColourChanger, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DCTextColourChanger, __Set)
{
	Object_wx_DCTextColourChanger *pThis = Object_wx_DCTextColourChanger::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDCTextColourChanger
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DCTextColourChanger)
{
	// Constructor assignment
	Gura_AssignFunction(__wxDCTextColourChanger);
	Gura_AssignFunction(__wxDCTextColourChanger_1);
	// Method assignment
	Gura_AssignMethod(wx_DCTextColourChanger, __Set);
}

Gura_ImplementDescendantCreator(wx_DCTextColourChanger)
{
	return new Object_wx_DCTextColourChanger((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
