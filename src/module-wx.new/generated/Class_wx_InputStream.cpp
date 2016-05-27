//----------------------------------------------------------------------------
// wxInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxInputStream
//----------------------------------------------------------------------------
Object_wx_InputStream::~Object_wx_InputStream()
{
}

Object *Object_wx_InputStream::Clone() const
{
	return nullptr;
}

String Object_wx_InputStream::ToString(bool exprFlag)
{
	String rtn("<wx.InputStream:");
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
// Class implementation for wxInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_InputStream)
{
}

Gura_ImplementDescendantCreator(wx_InputStream)
{
	return new Object_wx_InputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
