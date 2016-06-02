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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_AuiNotebookEvent, wxAuiNotebookEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "command_type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebookEvent, wxAuiNotebookEvent)
{
	Object_wx_AuiNotebookEvent *pThis = Object_wx_AuiNotebookEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int command_type = arg.GetNumber(0)
	//int win_id = arg.GetNumber(1)
	//pThis->GetEntity()->wxAuiNotebookEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebookEvent, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebookEvent, Clone)
{
	Object_wx_AuiNotebookEvent *pThis = Object_wx_AuiNotebookEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiNotebookEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiNotebookEvent)
{
	Gura_AssignMethod(wx_AuiNotebookEvent, wxAuiNotebookEvent);
	Gura_AssignMethod(wx_AuiNotebookEvent, Clone);
}

Gura_ImplementDescendantCreator(wx_AuiNotebookEvent)
{
	return new Object_wx_AuiNotebookEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
