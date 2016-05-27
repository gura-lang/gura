//----------------------------------------------------------------------------
// wxColourData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxColourData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxColourData
//----------------------------------------------------------------------------
Object_wx_ColourData::~Object_wx_ColourData()
{
}

Object *Object_wx_ColourData::Clone() const
{
	return nullptr;
}

String Object_wx_ColourData::ToString(bool exprFlag)
{
	String rtn("<wx.ColourData:");
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
// Class implementation for wxColourData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ColourData)
{
}

Gura_ImplementDescendantCreator(wx_ColourData)
{
	return new Object_wx_ColourData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
