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
Gura_DeclareFunctionAlias(__DCTextColourChanger, "DCTextColourChanger")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DCTextColourChanger));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DCTextColourChanger)
{
	//wxDC& dc = arg.GetNumber(0)
	//wxDCTextColourChanger(dc);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DCTextColourChanger_1, "DCTextColourChanger_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DCTextColourChanger));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DCTextColourChanger_1)
{
	//wxDC& dc = arg.GetNumber(0)
	//const wxColour& col = arg.GetNumber(1)
	//wxDCTextColourChanger(dc, col);
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
	//const wxColour& col = arg.GetNumber(0)
	//pThis->GetEntity()->Set(col);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDCTextColourChanger
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DCTextColourChanger)
{
	// Constructor assignment
	Gura_AssignFunction(__DCTextColourChanger);
	Gura_AssignFunction(__DCTextColourChanger_1);
	// Method assignment
	Gura_AssignMethod(wx_DCTextColourChanger, __Set);
}

Gura_ImplementDescendantCreator(wx_DCTextColourChanger)
{
	return new Object_wx_DCTextColourChanger((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
