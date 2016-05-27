//----------------------------------------------------------------------------
// wxFilterOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFilterOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFilterOutputStream
//----------------------------------------------------------------------------
Object_wx_FilterOutputStream::~Object_wx_FilterOutputStream()
{
}

Object *Object_wx_FilterOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_FilterOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.FilterOutputStream:");
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
// Class implementation for wxFilterOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FilterOutputStream)
{
}

Gura_ImplementDescendantCreator(wx_FilterOutputStream)
{
	return new Object_wx_FilterOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
