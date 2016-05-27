//----------------------------------------------------------------------------
// wxFFileStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFFileStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFFileStream
//----------------------------------------------------------------------------
Object_wx_FFileStream::~Object_wx_FFileStream()
{
}

Object *Object_wx_FFileStream::Clone() const
{
	return nullptr;
}

String Object_wx_FFileStream::ToString(bool exprFlag)
{
	String rtn("<wx.FFileStream:");
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
// Class implementation for wxFFileStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FFileStream)
{
}

Gura_ImplementDescendantCreator(wx_FFileStream)
{
	return new Object_wx_FFileStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
