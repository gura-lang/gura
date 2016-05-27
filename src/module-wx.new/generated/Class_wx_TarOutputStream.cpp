//----------------------------------------------------------------------------
// wxTarOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTarOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTarOutputStream
//----------------------------------------------------------------------------
Object_wx_TarOutputStream::~Object_wx_TarOutputStream()
{
}

Object *Object_wx_TarOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_TarOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.TarOutputStream:");
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
// Class implementation for wxTarOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TarOutputStream)
{
}

Gura_ImplementDescendantCreator(wx_TarOutputStream)
{
	return new Object_wx_TarOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
