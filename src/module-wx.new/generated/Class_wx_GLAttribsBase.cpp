//----------------------------------------------------------------------------
// wxGLAttribsBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGLAttribsBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGLAttribsBase
//----------------------------------------------------------------------------
Object_wx_GLAttribsBase::~Object_wx_GLAttribsBase()
{
}

Object *Object_wx_GLAttribsBase::Clone() const
{
	return nullptr;
}

String Object_wx_GLAttribsBase::ToString(bool exprFlag)
{
	String rtn("<wx.GLAttribsBase:");
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
// Class implementation for wxGLAttribsBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GLAttribsBase)
{
}

Gura_ImplementDescendantCreator(wx_GLAttribsBase)
{
	return new Object_wx_GLAttribsBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
