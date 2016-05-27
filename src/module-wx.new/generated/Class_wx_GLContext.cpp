//----------------------------------------------------------------------------
// wxGLContext
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGLContext
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGLContext
//----------------------------------------------------------------------------
Object_wx_GLContext::~Object_wx_GLContext()
{
}

Object *Object_wx_GLContext::Clone() const
{
	return nullptr;
}

String Object_wx_GLContext::ToString(bool exprFlag)
{
	String rtn("<wx.GLContext:");
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
// Class implementation for wxGLContext
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GLContext)
{
}

Gura_ImplementDescendantCreator(wx_GLContext)
{
	return new Object_wx_GLContext((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
