//----------------------------------------------------------------------------
// wxQuantize
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxQuantize
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxQuantize
//----------------------------------------------------------------------------
Object_wx_Quantize::~Object_wx_Quantize()
{
}

Object *Object_wx_Quantize::Clone() const
{
	return nullptr;
}

String Object_wx_Quantize::ToString(bool exprFlag)
{
	String rtn("<wx.Quantize:");
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
// Class implementation for wxQuantize
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Quantize)
{
}

Gura_ImplementDescendantCreator(wx_Quantize)
{
	return new Object_wx_Quantize((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
