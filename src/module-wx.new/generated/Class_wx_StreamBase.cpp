//----------------------------------------------------------------------------
// wxStreamBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStreamBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStreamBase
//----------------------------------------------------------------------------
Object_wx_StreamBase::~Object_wx_StreamBase()
{
}

Object *Object_wx_StreamBase::Clone() const
{
	return nullptr;
}

String Object_wx_StreamBase::ToString(bool exprFlag)
{
	String rtn("<wx.StreamBase:");
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
// Class implementation for wxStreamBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StreamBase)
{
}

Gura_ImplementDescendantCreator(wx_StreamBase)
{
	return new Object_wx_StreamBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
