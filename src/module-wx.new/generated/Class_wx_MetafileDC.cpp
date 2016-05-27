//----------------------------------------------------------------------------
// wxMetafileDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMetafileDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMetafileDC
//----------------------------------------------------------------------------
Object_wx_MetafileDC::~Object_wx_MetafileDC()
{
}

Object *Object_wx_MetafileDC::Clone() const
{
	return nullptr;
}

String Object_wx_MetafileDC::ToString(bool exprFlag)
{
	String rtn("<wx.MetafileDC:");
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
// Class implementation for wxMetafileDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MetafileDC)
{
}

Gura_ImplementDescendantCreator(wx_MetafileDC)
{
	return new Object_wx_MetafileDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
