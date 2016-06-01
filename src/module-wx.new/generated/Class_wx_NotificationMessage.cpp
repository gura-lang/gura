//----------------------------------------------------------------------------
// wxNotificationMessage
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxNotificationMessage
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNotificationMessage
//----------------------------------------------------------------------------
Object_wx_NotificationMessage::~Object_wx_NotificationMessage()
{
}

Object *Object_wx_NotificationMessage::Clone() const
{
	return nullptr;
}

String Object_wx_NotificationMessage::ToString(bool exprFlag)
{
	String rtn("<wx.NotificationMessage:");
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
// Class implementation for wxNotificationMessage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NotificationMessage)
{
	
}

Gura_ImplementDescendantCreator(wx_NotificationMessage)
{
	return new Object_wx_NotificationMessage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
