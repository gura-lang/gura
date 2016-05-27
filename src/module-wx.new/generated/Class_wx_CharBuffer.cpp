//----------------------------------------------------------------------------
// wxCharBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCharBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCharBuffer
//----------------------------------------------------------------------------
Object_wx_CharBuffer::~Object_wx_CharBuffer()
{
}

Object *Object_wx_CharBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_CharBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.CharBuffer:");
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
// Class implementation for wxCharBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CharBuffer)
{
}

Gura_ImplementDescendantCreator(wx_CharBuffer)
{
	return new Object_wx_CharBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
