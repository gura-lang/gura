//----------------------------------------------------------------------------
// wxZipOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxZipOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxZipOutputStream
//----------------------------------------------------------------------------
Object_wx_ZipOutputStream::~Object_wx_ZipOutputStream()
{
}

Object *Object_wx_ZipOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_ZipOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.ZipOutputStream:");
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
// Class implementation for wxZipOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZipOutputStream)
{
}

Gura_ImplementDescendantCreator(wx_ZipOutputStream)
{
	return new Object_wx_ZipOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
