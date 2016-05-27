//----------------------------------------------------------------------------
// wxGauge
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGauge
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGauge
//----------------------------------------------------------------------------
Object_wx_Gauge::~Object_wx_Gauge()
{
}

Object *Object_wx_Gauge::Clone() const
{
	return nullptr;
}

String Object_wx_Gauge::ToString(bool exprFlag)
{
	String rtn("<wx.Gauge:");
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
// Class implementation for wxGauge
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Gauge)
{
}

Gura_ImplementDescendantCreator(wx_Gauge)
{
	return new Object_wx_Gauge((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
