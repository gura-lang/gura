//----------------------------------------------------------------------------
// wxFileStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileStream
//----------------------------------------------------------------------------
Object_wx_FileStream::~Object_wx_FileStream()
{
}

Object *Object_wx_FileStream::Clone() const
{
	return nullptr;
}

String Object_wx_FileStream::ToString(bool exprFlag)
{
	String rtn("<wx.FileStream:");
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
// Class implementation for wxFileStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileStream)
{
}

Gura_ImplementDescendantCreator(wx_FileStream)
{
	return new Object_wx_FileStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
