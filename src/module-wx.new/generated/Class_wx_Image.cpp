//----------------------------------------------------------------------------
// wxImage
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxImage
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxImage
//----------------------------------------------------------------------------
Object_wx_Image::~Object_wx_Image()
{
}

Object *Object_wx_Image::Clone() const
{
	return nullptr;
}

String Object_wx_Image::ToString(bool exprFlag)
{
	String rtn("<wx.Image:");
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
// Class implementation for wxImage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Image)
{
}

Gura_ImplementDescendantCreator(wx_Image)
{
	return new Object_wx_Image((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
