//----------------------------------------------------------------------------
// wxArchiveIterator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveIterator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArchiveIterator
//----------------------------------------------------------------------------
Object_wx_ArchiveIterator::~Object_wx_ArchiveIterator()
{
}

Object *Object_wx_ArchiveIterator::Clone() const
{
	return nullptr;
}

String Object_wx_ArchiveIterator::ToString(bool exprFlag)
{
	String rtn("<wx.ArchiveIterator:");
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
// Class implementation for wxArchiveIterator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveIterator)
{
}

Gura_ImplementDescendantCreator(wx_ArchiveIterator)
{
	return new Object_wx_ArchiveIterator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
