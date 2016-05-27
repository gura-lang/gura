//----------------------------------------------------------------------------
// wxFileHistory
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileHistory
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileHistory
//----------------------------------------------------------------------------
Object_wx_FileHistory::~Object_wx_FileHistory()
{
}

Object *Object_wx_FileHistory::Clone() const
{
	return nullptr;
}

String Object_wx_FileHistory::ToString(bool exprFlag)
{
	String rtn("<wx.FileHistory:");
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
// Class implementation for wxFileHistory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileHistory)
{
}

Gura_ImplementDescendantCreator(wx_FileHistory)
{
	return new Object_wx_FileHistory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
