//----------------------------------------------------------------------------
// wxDCPenChanger
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDCPenChanger
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDCPenChanger
//----------------------------------------------------------------------------
Object_wx_DCPenChanger::~Object_wx_DCPenChanger()
{
}

Object *Object_wx_DCPenChanger::Clone() const
{
	return nullptr;
}

String Object_wx_DCPenChanger::ToString(bool exprFlag)
{
	String rtn("<wx.DCPenChanger:");
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
Gura_DeclareFunctionAlias(__DCPenChanger, "DCPenChanger")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pen", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DCPenChanger));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DCPenChanger)
{
	//wxDC& dc = arg.GetNumber(0)
	//const wxPen& pen = arg.GetNumber(1)
	//wxDCPenChanger(dc, pen);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDCPenChanger
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DCPenChanger)
{
	// Constructor assignment
	Gura_AssignFunction(__DCPenChanger);
}

Gura_ImplementDescendantCreator(wx_DCPenChanger)
{
	return new Object_wx_DCPenChanger((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
