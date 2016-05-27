//----------------------------------------------------------------------------
// wxAffineMatrix2D
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAffineMatrix2D
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAffineMatrix2D
//----------------------------------------------------------------------------
Object_wx_AffineMatrix2D::~Object_wx_AffineMatrix2D()
{
}

Object *Object_wx_AffineMatrix2D::Clone() const
{
	return nullptr;
}

String Object_wx_AffineMatrix2D::ToString(bool exprFlag)
{
	String rtn("<wx.AffineMatrix2D:");
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
// Class implementation for wxAffineMatrix2D
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AffineMatrix2D)
{
}

Gura_ImplementDescendantCreator(wx_AffineMatrix2D)
{
	return new Object_wx_AffineMatrix2D((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
