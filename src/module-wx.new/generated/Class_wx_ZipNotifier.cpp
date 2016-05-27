//----------------------------------------------------------------------------
// wxZipNotifier
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxZipNotifier
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxZipNotifier
//----------------------------------------------------------------------------
Object_wx_ZipNotifier::~Object_wx_ZipNotifier()
{
}

Object *Object_wx_ZipNotifier::Clone() const
{
	return nullptr;
}

String Object_wx_ZipNotifier::ToString(bool exprFlag)
{
	String rtn("<wx.ZipNotifier:");
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
// Class implementation for wxZipNotifier
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZipNotifier)
{
}

Gura_ImplementDescendantCreator(wx_ZipNotifier)
{
	return new Object_wx_ZipNotifier((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
