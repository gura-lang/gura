//----------------------------------------------------------------------------
// wxFTP
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFTP
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFTP
//----------------------------------------------------------------------------
Object_wx_FTP::~Object_wx_FTP()
{
}

Object *Object_wx_FTP::Clone() const
{
	return nullptr;
}

String Object_wx_FTP::ToString(bool exprFlag)
{
	String rtn("<wx.FTP:");
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
// Class implementation for wxFTP
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FTP)
{
	// Class assignment
	Gura_AssignValueEx("FTP", Reference());
}

Gura_ImplementDescendantCreator(wx_FTP)
{
	return new Object_wx_FTP((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
