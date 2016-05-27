//----------------------------------------------------------------------------
// wxAutoBufferedPaintDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAutoBufferedPaintDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAutoBufferedPaintDC
//----------------------------------------------------------------------------
Object_wx_AutoBufferedPaintDC::~Object_wx_AutoBufferedPaintDC()
{
}

Object *Object_wx_AutoBufferedPaintDC::Clone() const
{
	return nullptr;
}

String Object_wx_AutoBufferedPaintDC::ToString(bool exprFlag)
{
	String rtn("<wx.AutoBufferedPaintDC:");
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
// Class implementation for wxAutoBufferedPaintDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AutoBufferedPaintDC)
{
}

Gura_ImplementDescendantCreator(wx_AutoBufferedPaintDC)
{
	return new Object_wx_AutoBufferedPaintDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
