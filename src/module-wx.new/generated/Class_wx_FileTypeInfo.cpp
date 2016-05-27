//----------------------------------------------------------------------------
// wxFileTypeInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileTypeInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileTypeInfo
//----------------------------------------------------------------------------
Object_wx_FileTypeInfo::~Object_wx_FileTypeInfo()
{
}

Object *Object_wx_FileTypeInfo::Clone() const
{
	return nullptr;
}

String Object_wx_FileTypeInfo::ToString(bool exprFlag)
{
	String rtn("<wx.FileTypeInfo:");
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
// Class implementation for wxFileTypeInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileTypeInfo)
{
}

Gura_ImplementDescendantCreator(wx_FileTypeInfo)
{
	return new Object_wx_FileTypeInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
