//----------------------------------------------------------------------------
// wxStdInputStreamBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStdInputStreamBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStdInputStreamBuffer
//----------------------------------------------------------------------------
Object_wx_StdInputStreamBuffer::~Object_wx_StdInputStreamBuffer()
{
}

Object *Object_wx_StdInputStreamBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_StdInputStreamBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.StdInputStreamBuffer:");
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
// Class implementation for wxStdInputStreamBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StdInputStreamBuffer)
{
}

Gura_ImplementDescendantCreator(wx_StdInputStreamBuffer)
{
	return new Object_wx_StdInputStreamBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
