//----------------------------------------------------------------------------
// wxGLContextAttrs
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGLContextAttrs
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGLContextAttrs
//----------------------------------------------------------------------------
Object_wx_GLContextAttrs::~Object_wx_GLContextAttrs()
{
}

Object *Object_wx_GLContextAttrs::Clone() const
{
	return nullptr;
}

String Object_wx_GLContextAttrs::ToString(bool exprFlag)
{
	String rtn("<wx.GLContextAttrs:");
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
// Class implementation for wxGLContextAttrs
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GLContextAttrs)
{
}

Gura_ImplementDescendantCreator(wx_GLContextAttrs)
{
	return new Object_wx_GLContextAttrs((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
