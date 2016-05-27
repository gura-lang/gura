//----------------------------------------------------------------------------
// wxSizeEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSizeEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSizeEvent
//----------------------------------------------------------------------------
Object_wx_SizeEvent::~Object_wx_SizeEvent()
{
}

Object *Object_wx_SizeEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SizeEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SizeEvent:");
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
// Class implementation for wxSizeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SizeEvent)
{
}

Gura_ImplementDescendantCreator(wx_SizeEvent)
{
	return new Object_wx_SizeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
