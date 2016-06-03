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
Gura_DeclareFunctionAlias(__wxDCBrushChanger, "wxDCBrushChanger")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "brush", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxDCBrushChanger)
{
	//int dc = arg.GetNumber(0)
	//int brush = arg.GetNumber(1)
	//wxDCBrushChanger();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDCBrushChanger
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DCBrushChanger)
{
	// Constructor assignment
	Gura_AssignFunction(__wxDCBrushChanger);
}

Gura_ImplementDescendantCreator(wx_DCBrushChanger)
{
	return new Object_wx_DCBrushChanger((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
