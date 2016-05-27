//----------------------------------------------------------------------------
// wxGraphicsContext
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsContext
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsContext
//----------------------------------------------------------------------------
Object_wx_GraphicsContext::~Object_wx_GraphicsContext()
{
}

Object *Object_wx_GraphicsContext::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsContext::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsContext:");
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
// Class implementation for wxGraphicsContext
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsContext)
{
}

Gura_ImplementDescendantCreator(wx_GraphicsContext)
{
	return new Object_wx_GraphicsContext((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
