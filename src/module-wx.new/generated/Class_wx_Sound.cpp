//----------------------------------------------------------------------------
// wxSound
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSound
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSound
//----------------------------------------------------------------------------
Object_wx_Sound::~Object_wx_Sound()
{
}

Object *Object_wx_Sound::Clone() const
{
	return nullptr;
}

String Object_wx_Sound::ToString(bool exprFlag)
{
	String rtn("<wx.Sound:");
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
// Class implementation for wxSound
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Sound)
{
}

Gura_ImplementDescendantCreator(wx_Sound)
{
	return new Object_wx_Sound((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
