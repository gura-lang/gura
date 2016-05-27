//----------------------------------------------------------------------------
// wxZipInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxZipInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxZipInputStream
//----------------------------------------------------------------------------
Object_wx_ZipInputStream::~Object_wx_ZipInputStream()
{
}

Object *Object_wx_ZipInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_ZipInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.ZipInputStream:");
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
// Class implementation for wxZipInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZipInputStream)
{
}

Gura_ImplementDescendantCreator(wx_ZipInputStream)
{
	return new Object_wx_ZipInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
