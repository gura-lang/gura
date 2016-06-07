//----------------------------------------------------------------------------
// wxDCBrushChanger
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDCBrushChanger
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDCBrushChanger
//----------------------------------------------------------------------------
Object_wx_DCBrushChanger::~Object_wx_DCBrushChanger()
{
}

Object *Object_wx_DCBrushChanger::Clone() const
{
	return nullptr;
}

String Object_wx_DCBrushChanger::ToString(bool exprFlag)
{
	String rtn("<wx.DCBrushChanger:");
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
Gura_DeclareFunctionAlias(__DCBrushChanger, "DCBrushChanger")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "brush", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DCBrushChanger));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DCBrushChanger)
{
	//wxDC& dc = arg.GetNumber(0)
	//const wxBrush& brush = arg.GetNumber(1)
	//wxDCBrushChanger(dc, brush);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDCBrushChanger
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DCBrushChanger)
{
	// Constructor assignment
	Gura_AssignFunction(__DCBrushChanger);
}

Gura_ImplementDescendantCreator(wx_DCBrushChanger)
{
	return new Object_wx_DCBrushChanger((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
