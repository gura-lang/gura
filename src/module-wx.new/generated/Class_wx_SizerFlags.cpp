//----------------------------------------------------------------------------
// wxSizerFlags
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSizerFlags
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSizerFlags
//----------------------------------------------------------------------------
Object_wx_SizerFlags::~Object_wx_SizerFlags()
{
}

Object *Object_wx_SizerFlags::Clone() const
{
	return nullptr;
}

String Object_wx_SizerFlags::ToString(bool exprFlag)
{
	String rtn("<wx.SizerFlags:");
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
// Class implementation for wxSizerFlags
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SizerFlags)
{
}

Gura_ImplementDescendantCreator(wx_SizerFlags)
{
	return new Object_wx_SizerFlags((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
