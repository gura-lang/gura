//----------------------------------------------------------------------------
// wxStdOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStdOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStdOutputStream
//----------------------------------------------------------------------------
Object_wx_StdOutputStream::~Object_wx_StdOutputStream()
{
}

Object *Object_wx_StdOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_StdOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.StdOutputStream:");
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
// Class implementation for wxStdOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StdOutputStream)
{
}

Gura_ImplementDescendantCreator(wx_StdOutputStream)
{
	return new Object_wx_StdOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
