//----------------------------------------------------------------------------
// wxTextDataObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextDataObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextDataObject
//----------------------------------------------------------------------------
Object_wx_TextDataObject::~Object_wx_TextDataObject()
{
}

Object *Object_wx_TextDataObject::Clone() const
{
	return nullptr;
}

String Object_wx_TextDataObject::ToString(bool exprFlag)
{
	String rtn("<wx.TextDataObject:");
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
// Class implementation for wxTextDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextDataObject)
{
}

Gura_ImplementDescendantCreator(wx_TextDataObject)
{
	return new Object_wx_TextDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
