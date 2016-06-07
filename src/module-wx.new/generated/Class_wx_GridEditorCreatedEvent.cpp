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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__GridEditorCreatedEvent, "GridEditorCreatedEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridEditorCreatedEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridEditorCreatedEvent)
{
	//wxGridEditorCreatedEvent();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GridEditorCreatedEvent_1, "GridEditorCreatedEvent_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GridEditorCreatedEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridEditorCreatedEvent_1)
{
	//int id = arg.GetNumber(0)
	//wxEventType type = arg.GetNumber(1)
	//wxObject* obj = arg.GetNumber(2)
	//int row = arg.GetNumber(3)
	//int col = arg.GetNumber(4)
	//wxControl* ctrl = arg.GetNumber(5)
	//wxGridEditorCreatedEvent(id, type, obj, row, col, ctrl);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GridEditorCreatedEvent, __GetCol, "GetCol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, __GetCol)
{
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetCol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridEditorCreatedEvent, __GetControl, "GetControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, __GetControl)
{
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxControl* _rtn = pThis->GetEntity()->GetControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridEditorCreatedEvent, __GetRow, "GetRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, __GetRow)
{
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetRow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridEditorCreatedEvent, __SetCol, "SetCol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, __SetCol)
{
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetCol(col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridEditorCreatedEvent, __SetControl, "SetControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, __SetControl)
{
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxControl* ctrl = arg.GetNumber(0)
	//pThis->GetEntity()->SetControl(ctrl);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridEditorCreatedEvent, __SetRow, "SetRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, __SetRow)
{
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->SetRow(row);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridEditorCreatedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridEditorCreatedEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__GridEditorCreatedEvent);
	Gura_AssignFunction(__GridEditorCreatedEvent_1);
	// Method assignment
	Gura_AssignMethod(wx_GridEditorCreatedEvent, __GetCol);
	Gura_AssignMethod(wx_GridEditorCreatedEvent, __GetControl);
	Gura_AssignMethod(wx_GridEditorCreatedEvent, __GetRow);
	Gura_AssignMethod(wx_GridEditorCreatedEvent, __SetCol);
	Gura_AssignMethod(wx_GridEditorCreatedEvent, __SetControl);
	Gura_AssignMethod(wx_GridEditorCreatedEvent, __SetRow);
}

Gura_ImplementDescendantCreator(wx_GridEditorCreatedEvent)
{
	return new Object_wx_GridEditorCreatedEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
