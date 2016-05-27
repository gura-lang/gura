//----------------------------------------------------------------------------
// wxPixelData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPixelData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPixelData
//----------------------------------------------------------------------------
Object_wx_PixelData::~Object_wx_PixelData()
{
}

Object *Object_wx_PixelData::Clone() const
{
	return nullptr;
}

String Object_wx_PixelData::ToString(bool exprFlag)
{
	String rtn("<wx.PixelData:");
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
// Class implementation for wxPixelData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PixelData)
{
}

Gura_ImplementDescendantCreator(wx_PixelData)
{
	return new Object_wx_PixelData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
