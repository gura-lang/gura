//----------------------------------------------------------------------------
// wxGridEditorCreatedEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridEditorCreatedEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridEditorCreatedEvent
//----------------------------------------------------------------------------
Object_wx_GridEditorCreatedEvent::~Object_wx_GridEditorCreatedEvent()
{
}

Object *Object_wx_GridEditorCreatedEvent::Clone() const
{
	return nullptr;
}

String Object_wx_GridEditorCreatedEvent::ToString(bool exprFlag)
{
	String rtn("<wx.GridEditorCreatedEvent:");
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
Gura_DeclareMethod(wx_GridEditorCreatedEvent, wxGridEditorCreatedEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, wxGridEditorCreatedEvent)
{
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxGridEditorCreatedEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridEditorCreatedEvent, wxGridEditorCreatedEvent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, wxGridEditorCreatedEvent_1)
{
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//int obj = arg.GetNumber(2)
	//int row = arg.GetNumber(3)
	//int col = arg.GetNumber(4)
	//int ctrl = arg.GetNumber(5)
	//pThis->GetEntity()->wxGridEditorCreatedEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridEditorCreatedEvent, GetCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, GetCol)
{
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridEditorCreatedEvent, GetControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, GetControl)
{
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridEditorCreatedEvent, GetRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, GetRow)
{
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridEditorCreatedEvent, SetCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, SetCol)
{
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetCol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridEditorCreatedEvent, SetControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, SetControl)
{
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ctrl = arg.GetNumber(0)
	//pThis->GetEntity()->SetControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridEditorCreatedEvent, SetRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, SetRow)
{
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->SetRow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridEditorCreatedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridEditorCreatedEvent)
{
	Gura_AssignMethod(wx_GridEditorCreatedEvent, wxGridEditorCreatedEvent);
	Gura_AssignMethod(wx_GridEditorCreatedEvent, wxGridEditorCreatedEvent_1);
	Gura_AssignMethod(wx_GridEditorCreatedEvent, GetCol);
	Gura_AssignMethod(wx_GridEditorCreatedEvent, GetControl);
	Gura_AssignMethod(wx_GridEditorCreatedEvent, GetRow);
	Gura_AssignMethod(wx_GridEditorCreatedEvent, SetCol);
	Gura_AssignMethod(wx_GridEditorCreatedEvent, SetControl);
	Gura_AssignMethod(wx_GridEditorCreatedEvent, SetRow);
}

Gura_ImplementDescendantCreator(wx_GridEditorCreatedEvent)
{
	return new Object_wx_GridEditorCreatedEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
