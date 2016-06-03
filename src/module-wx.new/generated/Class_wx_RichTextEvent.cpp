//----------------------------------------------------------------------------
// wxRichTextEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextEvent
//----------------------------------------------------------------------------
Object_wx_RichTextEvent::~Object_wx_RichTextEvent()
{
}

Object *Object_wx_RichTextEvent::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextEvent::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextEvent:");
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
Gura_DeclareMethodAlias(wx_RichTextEvent, __wxRichTextEvent, "wxRichTextEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, __wxRichTextEvent)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int commandType = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//pThis->GetEntity()->wxRichTextEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextEvent, __wxRichTextEvent_1, "wxRichTextEvent_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, __wxRichTextEvent_1)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextEvent, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextEvent, __GetPosition)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextEvent, __SetPosition, "SetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, __SetPosition)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextEvent, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextEvent, __GetFlags)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextEvent, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, __SetFlags)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextEvent, __GetOldStyleSheet, "GetOldStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextEvent, __GetOldStyleSheet)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOldStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextEvent, __SetOldStyleSheet, "SetOldStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, __SetOldStyleSheet)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sheet = arg.GetNumber(0)
	//pThis->GetEntity()->SetOldStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextEvent, __GetNewStyleSheet, "GetNewStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextEvent, __GetNewStyleSheet)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNewStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextEvent, __SetNewStyleSheet, "SetNewStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, __SetNewStyleSheet)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sheet = arg.GetNumber(0)
	//pThis->GetEntity()->SetNewStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextEvent, __GetRange, "GetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextEvent, __GetRange)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextEvent, __SetRange, "SetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, __SetRange)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextEvent, __GetCharacter, "GetCharacter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextEvent, __GetCharacter)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCharacter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextEvent, __SetCharacter, "SetCharacter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, __SetCharacter)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//pThis->GetEntity()->SetCharacter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextEvent, __GetContainer, "GetContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextEvent, __GetContainer)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContainer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextEvent, __SetContainer, "SetContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, __SetContainer)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//pThis->GetEntity()->SetContainer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextEvent, __GetOldContainer, "GetOldContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextEvent, __GetOldContainer)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOldContainer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextEvent, __SetOldContainer, "SetOldContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, __SetOldContainer)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//pThis->GetEntity()->SetOldContainer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextEvent, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextEvent, __Clone)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextEvent)
{
	Gura_AssignMethod(wx_RichTextEvent, __wxRichTextEvent);
	Gura_AssignMethod(wx_RichTextEvent, __wxRichTextEvent_1);
	Gura_AssignMethod(wx_RichTextEvent, __GetPosition);
	Gura_AssignMethod(wx_RichTextEvent, __SetPosition);
	Gura_AssignMethod(wx_RichTextEvent, __GetFlags);
	Gura_AssignMethod(wx_RichTextEvent, __SetFlags);
	Gura_AssignMethod(wx_RichTextEvent, __GetOldStyleSheet);
	Gura_AssignMethod(wx_RichTextEvent, __SetOldStyleSheet);
	Gura_AssignMethod(wx_RichTextEvent, __GetNewStyleSheet);
	Gura_AssignMethod(wx_RichTextEvent, __SetNewStyleSheet);
	Gura_AssignMethod(wx_RichTextEvent, __GetRange);
	Gura_AssignMethod(wx_RichTextEvent, __SetRange);
	Gura_AssignMethod(wx_RichTextEvent, __GetCharacter);
	Gura_AssignMethod(wx_RichTextEvent, __SetCharacter);
	Gura_AssignMethod(wx_RichTextEvent, __GetContainer);
	Gura_AssignMethod(wx_RichTextEvent, __SetContainer);
	Gura_AssignMethod(wx_RichTextEvent, __GetOldContainer);
	Gura_AssignMethod(wx_RichTextEvent, __SetOldContainer);
	Gura_AssignMethod(wx_RichTextEvent, __Clone);
}

Gura_ImplementDescendantCreator(wx_RichTextEvent)
{
	return new Object_wx_RichTextEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
