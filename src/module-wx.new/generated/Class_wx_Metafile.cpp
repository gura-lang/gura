//----------------------------------------------------------------------------
// wxMetafile
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMetafile
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMetafile
//----------------------------------------------------------------------------
Object_wx_Metafile::~Object_wx_Metafile()
{
}

Object *Object_wx_Metafile::Clone() const
{
	return nullptr;
}

String Object_wx_Metafile::ToString(bool exprFlag)
{
	String rtn("<wx.Metafile:");
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
// Class implementation for wxMetafile
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Metafile)
{
}

Gura_ImplementDescendantCreator(wx_Metafile)
{
	return new Object_wx_Metafile((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
