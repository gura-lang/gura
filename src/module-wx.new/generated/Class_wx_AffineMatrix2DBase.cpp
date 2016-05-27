//----------------------------------------------------------------------------
// wxAffineMatrix2DBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAffineMatrix2DBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAffineMatrix2DBase
//----------------------------------------------------------------------------
Object_wx_AffineMatrix2DBase::~Object_wx_AffineMatrix2DBase()
{
}

Object *Object_wx_AffineMatrix2DBase::Clone() const
{
	return nullptr;
}

String Object_wx_AffineMatrix2DBase::ToString(bool exprFlag)
{
	String rtn("<wx.AffineMatrix2DBase:");
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
// Class implementation for wxAffineMatrix2DBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AffineMatrix2DBase)
{
}

Gura_ImplementDescendantCreator(wx_AffineMatrix2DBase)
{
	return new Object_wx_AffineMatrix2DBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
