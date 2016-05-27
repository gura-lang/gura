//----------------------------------------------------------------------------
// wxAppProgressIndicator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAppProgressIndicator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAppProgressIndicator
//----------------------------------------------------------------------------
Object_wx_AppProgressIndicator::~Object_wx_AppProgressIndicator()
{
}

Object *Object_wx_AppProgressIndicator::Clone() const
{
	return nullptr;
}

String Object_wx_AppProgressIndicator::ToString(bool exprFlag)
{
	String rtn("<wx.AppProgressIndicator:");
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
// Class implementation for wxAppProgressIndicator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AppProgressIndicator)
{
}

Gura_ImplementDescendantCreator(wx_AppProgressIndicator)
{
	return new Object_wx_AppProgressIndicator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
