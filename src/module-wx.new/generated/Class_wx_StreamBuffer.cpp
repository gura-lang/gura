//----------------------------------------------------------------------------
// wxStreamBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStreamBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStreamBuffer
//----------------------------------------------------------------------------
Object_wx_StreamBuffer::~Object_wx_StreamBuffer()
{
}

Object *Object_wx_StreamBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_StreamBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.StreamBuffer:");
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
// Class implementation for wxStreamBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StreamBuffer)
{
}

Gura_ImplementDescendantCreator(wx_StreamBuffer)
{
	return new Object_wx_StreamBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
