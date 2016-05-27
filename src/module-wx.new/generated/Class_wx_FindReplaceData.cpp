//----------------------------------------------------------------------------
// wxFindReplaceData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFindReplaceData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFindReplaceData
//----------------------------------------------------------------------------
Object_wx_FindReplaceData::~Object_wx_FindReplaceData()
{
}

Object *Object_wx_FindReplaceData::Clone() const
{
	return nullptr;
}

String Object_wx_FindReplaceData::ToString(bool exprFlag)
{
	String rtn("<wx.FindReplaceData:");
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
// Class implementation for wxFindReplaceData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FindReplaceData)
{
}

Gura_ImplementDescendantCreator(wx_FindReplaceData)
{
	return new Object_wx_FindReplaceData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
