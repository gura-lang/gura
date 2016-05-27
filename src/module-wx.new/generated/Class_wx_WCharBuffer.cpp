//----------------------------------------------------------------------------
// wxWCharBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWCharBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWCharBuffer
//----------------------------------------------------------------------------
Object_wx_WCharBuffer::~Object_wx_WCharBuffer()
{
}

Object *Object_wx_WCharBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_WCharBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.WCharBuffer:");
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
// Class implementation for wxWCharBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WCharBuffer)
{
}

Gura_ImplementDescendantCreator(wx_WCharBuffer)
{
	return new Object_wx_WCharBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
