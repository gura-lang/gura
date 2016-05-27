//----------------------------------------------------------------------------
// wxGridTableMessage
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridTableMessage
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridTableMessage
//----------------------------------------------------------------------------
Object_wx_GridTableMessage::~Object_wx_GridTableMessage()
{
}

Object *Object_wx_GridTableMessage::Clone() const
{
	return nullptr;
}

String Object_wx_GridTableMessage::ToString(bool exprFlag)
{
	String rtn("<wx.GridTableMessage:");
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
// Class implementation for wxGridTableMessage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridTableMessage)
{
}

Gura_ImplementDescendantCreator(wx_GridTableMessage)
{
	return new Object_wx_GridTableMessage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
