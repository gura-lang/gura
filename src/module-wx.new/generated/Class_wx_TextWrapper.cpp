//----------------------------------------------------------------------------
// wxTextWrapper
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextWrapper
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextWrapper
//----------------------------------------------------------------------------
Object_wx_TextWrapper::~Object_wx_TextWrapper()
{
}

Object *Object_wx_TextWrapper::Clone() const
{
	return nullptr;
}

String Object_wx_TextWrapper::ToString(bool exprFlag)
{
	String rtn("<wx.TextWrapper:");
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
// Class implementation for wxTextWrapper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextWrapper)
{
}

Gura_ImplementDescendantCreator(wx_TextWrapper)
{
	return new Object_wx_TextWrapper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
