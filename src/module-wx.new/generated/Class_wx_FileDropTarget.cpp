//----------------------------------------------------------------------------
// wxFileDropTarget
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileDropTarget
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileDropTarget
//----------------------------------------------------------------------------
Object_wx_FileDropTarget::~Object_wx_FileDropTarget()
{
}

Object *Object_wx_FileDropTarget::Clone() const
{
	return nullptr;
}

String Object_wx_FileDropTarget::ToString(bool exprFlag)
{
	String rtn("<wx.FileDropTarget:");
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
// Class implementation for wxFileDropTarget
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileDropTarget)
{
}

Gura_ImplementDescendantCreator(wx_FileDropTarget)
{
	return new Object_wx_FileDropTarget((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
