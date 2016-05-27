//----------------------------------------------------------------------------
// wxScopedCharTypeBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScopedCharTypeBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScopedCharTypeBuffer
//----------------------------------------------------------------------------
Object_wx_ScopedCharTypeBuffer::~Object_wx_ScopedCharTypeBuffer()
{
}

Object *Object_wx_ScopedCharTypeBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_ScopedCharTypeBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.ScopedCharTypeBuffer:");
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
// Class implementation for wxScopedCharTypeBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScopedCharTypeBuffer)
{
}

Gura_ImplementDescendantCreator(wx_ScopedCharTypeBuffer)
{
	return new Object_wx_ScopedCharTypeBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
