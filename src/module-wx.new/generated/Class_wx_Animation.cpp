//----------------------------------------------------------------------------
// wxAnimation
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAnimation
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAnimation
//----------------------------------------------------------------------------
Object_wx_Animation::~Object_wx_Animation()
{
}

Object *Object_wx_Animation::Clone() const
{
	return nullptr;
}

String Object_wx_Animation::ToString(bool exprFlag)
{
	String rtn("<wx.Animation:");
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
// Class implementation for wxAnimation
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Animation)
{
}

Gura_ImplementDescendantCreator(wx_Animation)
{
	return new Object_wx_Animation((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
