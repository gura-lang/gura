//----------------------------------------------------------------------------
// wxPaintDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPaintDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPaintDC
//----------------------------------------------------------------------------
Object_wx_PaintDC::~Object_wx_PaintDC()
{
}

Object *Object_wx_PaintDC::Clone() const
{
	return nullptr;
}

String Object_wx_PaintDC::ToString(bool exprFlag)
{
	String rtn("<wx.PaintDC:");
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
// Class implementation for wxPaintDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PaintDC)
{
}

Gura_ImplementDescendantCreator(wx_PaintDC)
{
	return new Object_wx_PaintDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
