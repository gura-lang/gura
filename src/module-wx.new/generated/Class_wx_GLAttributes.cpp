//----------------------------------------------------------------------------
// wxGLAttributes
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGLAttributes
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGLAttributes
//----------------------------------------------------------------------------
Object_wx_GLAttributes::~Object_wx_GLAttributes()
{
}

Object *Object_wx_GLAttributes::Clone() const
{
	return nullptr;
}

String Object_wx_GLAttributes::ToString(bool exprFlag)
{
	String rtn("<wx.GLAttributes:");
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
// Class implementation for wxGLAttributes
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GLAttributes)
{
}

Gura_ImplementDescendantCreator(wx_GLAttributes)
{
	return new Object_wx_GLAttributes((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
