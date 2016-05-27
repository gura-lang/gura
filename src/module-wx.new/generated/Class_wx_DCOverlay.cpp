//----------------------------------------------------------------------------
// wxDCOverlay
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDCOverlay
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDCOverlay
//----------------------------------------------------------------------------
Object_wx_DCOverlay::~Object_wx_DCOverlay()
{
}

Object *Object_wx_DCOverlay::Clone() const
{
	return nullptr;
}

String Object_wx_DCOverlay::ToString(bool exprFlag)
{
	String rtn("<wx.DCOverlay:");
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
// Class implementation for wxDCOverlay
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DCOverlay)
{
}

Gura_ImplementDescendantCreator(wx_DCOverlay)
{
	return new Object_wx_DCOverlay((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
