//----------------------------------------------------------------------------
// wxTextDropTarget
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextDropTarget
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextDropTarget
//----------------------------------------------------------------------------
Object_wx_TextDropTarget::~Object_wx_TextDropTarget()
{
}

Object *Object_wx_TextDropTarget::Clone() const
{
	return nullptr;
}

String Object_wx_TextDropTarget::ToString(bool exprFlag)
{
	String rtn("<wx.TextDropTarget:");
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
// Class implementation for wxTextDropTarget
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextDropTarget)
{
}

Gura_ImplementDescendantCreator(wx_TextDropTarget)
{
	return new Object_wx_TextDropTarget((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
