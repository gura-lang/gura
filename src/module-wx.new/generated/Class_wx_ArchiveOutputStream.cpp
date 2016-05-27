//----------------------------------------------------------------------------
// wxArchiveOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArchiveOutputStream
//----------------------------------------------------------------------------
Object_wx_ArchiveOutputStream::~Object_wx_ArchiveOutputStream()
{
}

Object *Object_wx_ArchiveOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_ArchiveOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.ArchiveOutputStream:");
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
// Class implementation for wxArchiveOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveOutputStream)
{
}

Gura_ImplementDescendantCreator(wx_ArchiveOutputStream)
{
	return new Object_wx_ArchiveOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
