//----------------------------------------------------------------------------
// wxCountingOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCountingOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCountingOutputStream
//----------------------------------------------------------------------------
Object_wx_CountingOutputStream::~Object_wx_CountingOutputStream()
{
}

Object *Object_wx_CountingOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_CountingOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.CountingOutputStream:");
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
// Class implementation for wxCountingOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CountingOutputStream)
{
}

Gura_ImplementDescendantCreator(wx_CountingOutputStream)
{
	return new Object_wx_CountingOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
