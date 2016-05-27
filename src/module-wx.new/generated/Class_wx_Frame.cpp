//----------------------------------------------------------------------------
// wxFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFrame
//----------------------------------------------------------------------------
Object_wx_Frame::~Object_wx_Frame()
{
}

Object *Object_wx_Frame::Clone() const
{
	return nullptr;
}

String Object_wx_Frame::ToString(bool exprFlag)
{
	String rtn("<wx.Frame:");
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
// Class implementation for wxFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Frame)
{
}

Gura_ImplementDescendantCreator(wx_Frame)
{
	return new Object_wx_Frame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
