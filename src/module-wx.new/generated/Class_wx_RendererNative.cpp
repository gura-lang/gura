//----------------------------------------------------------------------------
// wxRendererNative
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRendererNative
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRendererNative
//----------------------------------------------------------------------------
Object_wx_RendererNative::~Object_wx_RendererNative()
{
}

Object *Object_wx_RendererNative::Clone() const
{
	return nullptr;
}

String Object_wx_RendererNative::ToString(bool exprFlag)
{
	String rtn("<wx.RendererNative:");
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
// Class implementation for wxRendererNative
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RendererNative)
{
}

Gura_ImplementDescendantCreator(wx_RendererNative)
{
	return new Object_wx_RendererNative((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
