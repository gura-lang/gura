//----------------------------------------------------------------------------
// wxStaticBitmap
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStaticBitmap
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStaticBitmap
//----------------------------------------------------------------------------
Object_wx_StaticBitmap::~Object_wx_StaticBitmap()
{
}

Object *Object_wx_StaticBitmap::Clone() const
{
	return nullptr;
}

String Object_wx_StaticBitmap::ToString(bool exprFlag)
{
	String rtn("<wx.StaticBitmap:");
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
// Class implementation for wxStaticBitmap
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StaticBitmap)
{
}

Gura_ImplementDescendantCreator(wx_StaticBitmap)
{
	return new Object_wx_StaticBitmap((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
