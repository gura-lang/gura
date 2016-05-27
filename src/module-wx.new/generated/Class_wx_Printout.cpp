//----------------------------------------------------------------------------
// wxPrintout
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintout
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPrintout
//----------------------------------------------------------------------------
Object_wx_Printout::~Object_wx_Printout()
{
}

Object *Object_wx_Printout::Clone() const
{
	return nullptr;
}

String Object_wx_Printout::ToString(bool exprFlag)
{
	String rtn("<wx.Printout:");
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
// Class implementation for wxPrintout
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Printout)
{
}

Gura_ImplementDescendantCreator(wx_Printout)
{
	return new Object_wx_Printout((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
