//----------------------------------------------------------------------------
// wxBitmap
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBitmap
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBitmap
//----------------------------------------------------------------------------
Object_wx_Bitmap::~Object_wx_Bitmap()
{
}

Object *Object_wx_Bitmap::Clone() const
{
	return nullptr;
}

String Object_wx_Bitmap::ToString(bool exprFlag)
{
	String rtn("<wx.Bitmap:");
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
// Class implementation for wxBitmap
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Bitmap)
{
}

Gura_ImplementDescendantCreator(wx_Bitmap)
{
	return new Object_wx_Bitmap((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
