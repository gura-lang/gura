//----------------------------------------------------------------------------
// wxTextOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextOutputStream
//----------------------------------------------------------------------------
Object_wx_TextOutputStream::~Object_wx_TextOutputStream()
{
}

Object *Object_wx_TextOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_TextOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.TextOutputStream:");
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
// Class implementation for wxTextOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextOutputStream)
{
}

Gura_ImplementDescendantCreator(wx_TextOutputStream)
{
	return new Object_wx_TextOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
