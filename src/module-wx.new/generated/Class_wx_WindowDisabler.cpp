//----------------------------------------------------------------------------
// wxWindowDisabler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowDisabler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWindowDisabler
//----------------------------------------------------------------------------
Object_wx_WindowDisabler::~Object_wx_WindowDisabler()
{
}

Object *Object_wx_WindowDisabler::Clone() const
{
	return nullptr;
}

String Object_wx_WindowDisabler::ToString(bool exprFlag)
{
	String rtn("<wx.WindowDisabler:");
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
Gura_DeclareFunctionAlias(__WindowDisabler, "WindowDisabler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "disable", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WindowDisabler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WindowDisabler)
{
	//bool disable = arg.GetNumber(0)
	//wxWindowDisabler(disable);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__WindowDisabler_1, "WindowDisabler_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "winToSkip", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WindowDisabler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WindowDisabler_1)
{
	//wxWindow* winToSkip = arg.GetNumber(0)
	//wxWindowDisabler(winToSkip);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWindowDisabler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowDisabler)
{
	// Constructor assignment
	Gura_AssignFunction(__WindowDisabler);
	Gura_AssignFunction(__WindowDisabler_1);
}

Gura_ImplementDescendantCreator(wx_WindowDisabler)
{
	return new Object_wx_WindowDisabler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
