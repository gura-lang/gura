//----------------------------------------------------------------------------
// wxZlibInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxZlibInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxZlibInputStream
//----------------------------------------------------------------------------
Object_wx_ZlibInputStream::~Object_wx_ZlibInputStream()
{
}

Object *Object_wx_ZlibInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_ZlibInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.ZlibInputStream:");
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
// Class implementation for wxZlibInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZlibInputStream)
{
}

Gura_ImplementDescendantCreator(wx_ZlibInputStream)
{
	return new Object_wx_ZlibInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
