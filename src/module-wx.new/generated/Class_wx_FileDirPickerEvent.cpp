//----------------------------------------------------------------------------
// wxFileDirPickerEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileDirPickerEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileDirPickerEvent
//----------------------------------------------------------------------------
Object_wx_FileDirPickerEvent::~Object_wx_FileDirPickerEvent()
{
}

Object *Object_wx_FileDirPickerEvent::Clone() const
{
	return nullptr;
}

String Object_wx_FileDirPickerEvent::ToString(bool exprFlag)
{
	String rtn("<wx.FileDirPickerEvent:");
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
// Class implementation for wxFileDirPickerEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileDirPickerEvent)
{
}

Gura_ImplementDescendantCreator(wx_FileDirPickerEvent)
{
	return new Object_wx_FileDirPickerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
