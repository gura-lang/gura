//----------------------------------------------------------------------------
// wxAuiNotebookEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiNotebookEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiNotebookEvent
//----------------------------------------------------------------------------
Object_wx_AuiNotebookEvent::~Object_wx_AuiNotebookEvent()
{
}

Object *Object_wx_AuiNotebookEvent::Clone() const
{
	return nullptr;
}

String Object_wx_AuiNotebookEvent::ToString(bool exprFlag)
{
	String rtn("<wx.AuiNotebookEvent:");
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
// Class implementation for wxAuiNotebookEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiNotebookEvent)
{
}

Gura_ImplementDescendantCreator(wx_AuiNotebookEvent)
{
	return new Object_wx_AuiNotebookEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
