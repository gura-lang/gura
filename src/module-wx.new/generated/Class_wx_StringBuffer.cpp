//----------------------------------------------------------------------------
// wxStringBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStringBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStringBuffer
//----------------------------------------------------------------------------
Object_wx_StringBuffer::~Object_wx_StringBuffer()
{
}

Object *Object_wx_StringBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_StringBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.StringBuffer:");
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
// Class implementation for wxStringBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringBuffer)
{
}

Gura_ImplementDescendantCreator(wx_StringBuffer)
{
	return new Object_wx_StringBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
