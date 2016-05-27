//----------------------------------------------------------------------------
// wxTempFileOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTempFileOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTempFileOutputStream
//----------------------------------------------------------------------------
Object_wx_TempFileOutputStream::~Object_wx_TempFileOutputStream()
{
}

Object *Object_wx_TempFileOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_TempFileOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.TempFileOutputStream:");
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
// Class implementation for wxTempFileOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TempFileOutputStream)
{
}

Gura_ImplementDescendantCreator(wx_TempFileOutputStream)
{
	return new Object_wx_TempFileOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
