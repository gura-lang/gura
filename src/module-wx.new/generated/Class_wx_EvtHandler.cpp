//----------------------------------------------------------------------------
// wxEvtHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxEvtHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxEvtHandler
//----------------------------------------------------------------------------
Object_wx_EvtHandler::~Object_wx_EvtHandler()
{
}

Object *Object_wx_EvtHandler::Clone() const
{
	return nullptr;
}

String Object_wx_EvtHandler::ToString(bool exprFlag)
{
	String rtn("<wx.EvtHandler:");
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
// Class implementation for wxEvtHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EvtHandler)
{
}

Gura_ImplementDescendantCreator(wx_EvtHandler)
{
	return new Object_wx_EvtHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
