//----------------------------------------------------------------------------
// wxTextInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextInputStream
//----------------------------------------------------------------------------
Object_wx_TextInputStream::~Object_wx_TextInputStream()
{
}

Object *Object_wx_TextInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_TextInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.TextInputStream:");
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
// Class implementation for wxTextInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextInputStream)
{
}

Gura_ImplementDescendantCreator(wx_TextInputStream)
{
	return new Object_wx_TextInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
