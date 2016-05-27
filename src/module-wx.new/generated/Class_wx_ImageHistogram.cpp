//----------------------------------------------------------------------------
// wxImageHistogram
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxImageHistogram
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxImageHistogram
//----------------------------------------------------------------------------
Object_wx_ImageHistogram::~Object_wx_ImageHistogram()
{
}

Object *Object_wx_ImageHistogram::Clone() const
{
	return nullptr;
}

String Object_wx_ImageHistogram::ToString(bool exprFlag)
{
	String rtn("<wx.ImageHistogram:");
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
// Class implementation for wxImageHistogram
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ImageHistogram)
{
}

Gura_ImplementDescendantCreator(wx_ImageHistogram)
{
	return new Object_wx_ImageHistogram((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
