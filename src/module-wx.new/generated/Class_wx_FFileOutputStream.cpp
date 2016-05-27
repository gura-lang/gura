//----------------------------------------------------------------------------
// wxFFileOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFFileOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFFileOutputStream
//----------------------------------------------------------------------------
Object_wx_FFileOutputStream::~Object_wx_FFileOutputStream()
{
}

Object *Object_wx_FFileOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_FFileOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.FFileOutputStream:");
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
// Class implementation for wxFFileOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FFileOutputStream)
{
}

Gura_ImplementDescendantCreator(wx_FFileOutputStream)
{
	return new Object_wx_FFileOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
