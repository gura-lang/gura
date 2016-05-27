//----------------------------------------------------------------------------
// wxBufferedOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBufferedOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBufferedOutputStream
//----------------------------------------------------------------------------
Object_wx_BufferedOutputStream::~Object_wx_BufferedOutputStream()
{
}

Object *Object_wx_BufferedOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_BufferedOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.BufferedOutputStream:");
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
// Class implementation for wxBufferedOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedOutputStream)
{
}

Gura_ImplementDescendantCreator(wx_BufferedOutputStream)
{
	return new Object_wx_BufferedOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
