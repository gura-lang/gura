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
// Class implementation for wxDCBrushChanger
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DCBrushChanger)
{
}

Gura_ImplementDescendantCreator(wx_DCBrushChanger)
{
	return new Object_wx_DCBrushChanger((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
