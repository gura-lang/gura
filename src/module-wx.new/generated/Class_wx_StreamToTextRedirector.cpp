//----------------------------------------------------------------------------
// wxStreamToTextRedirector
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStreamToTextRedirector
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStreamToTextRedirector
//----------------------------------------------------------------------------
Object_wx_StreamToTextRedirector::~Object_wx_StreamToTextRedirector()
{
}

Object *Object_wx_StreamToTextRedirector::Clone() const
{
	return nullptr;
}

String Object_wx_StreamToTextRedirector::ToString(bool exprFlag)
{
	String rtn("<wx.StreamToTextRedirector:");
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
// Class implementation for wxStreamToTextRedirector
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StreamToTextRedirector)
{
}

Gura_ImplementDescendantCreator(wx_StreamToTextRedirector)
{
	return new Object_wx_StreamToTextRedirector((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
