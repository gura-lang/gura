//----------------------------------------------------------------------------
// wxThreadHelper
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxThreadHelper
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxThreadHelper
//----------------------------------------------------------------------------
Object_wx_ThreadHelper::~Object_wx_ThreadHelper()
{
}

Object *Object_wx_ThreadHelper::Clone() const
{
	return nullptr;
}

String Object_wx_ThreadHelper::ToString(bool exprFlag)
{
	String rtn("<wx.ThreadHelper:");
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
// Class implementation for wxThreadHelper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ThreadHelper)
{
}

Gura_ImplementDescendantCreator(wx_ThreadHelper)
{
	return new Object_wx_ThreadHelper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
