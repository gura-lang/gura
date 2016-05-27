//----------------------------------------------------------------------------
// wxLogBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogBuffer
//----------------------------------------------------------------------------
Object_wx_LogBuffer::~Object_wx_LogBuffer()
{
}

Object *Object_wx_LogBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_LogBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.LogBuffer:");
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
// Class implementation for wxLogBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogBuffer)
{
}

Gura_ImplementDescendantCreator(wx_LogBuffer)
{
	return new Object_wx_LogBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
