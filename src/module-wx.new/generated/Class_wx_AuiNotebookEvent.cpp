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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__AuiNotebookEvent, "AuiNotebookEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "command_type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win_id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_AuiNotebookEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AuiNotebookEvent)
{
	//wxEventType command_type = arg.GetNumber(0)
	//int win_id = arg.GetNumber(1)
	//wxAuiNotebookEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AuiNotebookEvent, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebookEvent, __Clone)
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
	// Constructor assignment
	Gura_AssignFunction(__AuiNotebookEvent);
	// Method assignment
	Gura_AssignMethod(wx_AuiNotebookEvent, __Clone);
}

Gura_ImplementDescendantCreator(wx_AuiNotebookEvent)
{
	return new Object_wx_AuiNotebookEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
