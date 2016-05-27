//----------------------------------------------------------------------------
// wxBufferedDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBufferedDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBufferedDC
//----------------------------------------------------------------------------
Object_wx_BufferedDC::~Object_wx_BufferedDC()
{
}

Object *Object_wx_BufferedDC::Clone() const
{
	return nullptr;
}

String Object_wx_BufferedDC::ToString(bool exprFlag)
{
	String rtn("<wx.BufferedDC:");
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
// Class implementation for wxBufferedDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedDC)
{
}

Gura_ImplementDescendantCreator(wx_BufferedDC)
{
	return new Object_wx_BufferedDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
