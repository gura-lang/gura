//----------------------------------------------------------------------------
// wxWindowDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWindowDC
//----------------------------------------------------------------------------
Object_wx_WindowDC::~Object_wx_WindowDC()
{
}

Object *Object_wx_WindowDC::Clone() const
{
	return nullptr;
}

String Object_wx_WindowDC::ToString(bool exprFlag)
{
	String rtn("<wx.WindowDC:");
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
Gura_DeclareFunctionAlias(__wxWindowDC, "wxWindowDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WindowDC));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxWindowDC)
{
	//int window = arg.GetNumber(0)
	//wxWindowDC();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWindowDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowDC)
{
	// Constructor assignment
	Gura_AssignFunction(__wxWindowDC);
}

Gura_ImplementDescendantCreator(wx_WindowDC)
{
	return new Object_wx_WindowDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
