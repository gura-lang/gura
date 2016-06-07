//----------------------------------------------------------------------------
// wxWindowUpdateLocker
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowUpdateLocker
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWindowUpdateLocker
//----------------------------------------------------------------------------
Object_wx_WindowUpdateLocker::~Object_wx_WindowUpdateLocker()
{
}

Object *Object_wx_WindowUpdateLocker::Clone() const
{
	return nullptr;
}

String Object_wx_WindowUpdateLocker::ToString(bool exprFlag)
{
	String rtn("<wx.WindowUpdateLocker:");
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
Gura_DeclareFunctionAlias(__WindowUpdateLocker, "WindowUpdateLocker")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WindowUpdateLocker));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WindowUpdateLocker)
{
	//wxWindow* win = arg.GetNumber(0)
	//wxWindowUpdateLocker(win);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWindowUpdateLocker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowUpdateLocker)
{
	// Constructor assignment
	Gura_AssignFunction(__WindowUpdateLocker);
}

Gura_ImplementDescendantCreator(wx_WindowUpdateLocker)
{
	return new Object_wx_WindowUpdateLocker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
