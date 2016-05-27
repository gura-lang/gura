//----------------------------------------------------------------------------
// wxFileType
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileType
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileType
//----------------------------------------------------------------------------
Object_wx_FileType::~Object_wx_FileType()
{
}

Object *Object_wx_FileType::Clone() const
{
	return nullptr;
}

String Object_wx_FileType::ToString(bool exprFlag)
{
	String rtn("<wx.FileType:");
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
// Class implementation for wxFileType
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileType)
{
}

Gura_ImplementDescendantCreator(wx_FileType)
{
	return new Object_wx_FileType((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
