//----------------------------------------------------------------------------
// wxBufferedPaintDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBufferedPaintDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBufferedPaintDC
//----------------------------------------------------------------------------
Object_wx_BufferedPaintDC::~Object_wx_BufferedPaintDC()
{
}

Object *Object_wx_BufferedPaintDC::Clone() const
{
	return nullptr;
}

String Object_wx_BufferedPaintDC::ToString(bool exprFlag)
{
	String rtn("<wx.BufferedPaintDC:");
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
// Class implementation for wxBufferedPaintDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedPaintDC)
{
}

Gura_ImplementDescendantCreator(wx_BufferedPaintDC)
{
	return new Object_wx_BufferedPaintDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
