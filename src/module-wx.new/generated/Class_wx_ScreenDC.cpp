//----------------------------------------------------------------------------
// wxScreenDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScreenDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScreenDC
//----------------------------------------------------------------------------
Object_wx_ScreenDC::~Object_wx_ScreenDC()
{
}

Object *Object_wx_ScreenDC::Clone() const
{
	return nullptr;
}

String Object_wx_ScreenDC::ToString(bool exprFlag)
{
	String rtn("<wx.ScreenDC:");
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
// Method implementation
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Class implementation for wxScreenDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScreenDC)
{
}

Gura_ImplementDescendantCreator(wx_ScreenDC)
{
	return new Object_wx_ScreenDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
