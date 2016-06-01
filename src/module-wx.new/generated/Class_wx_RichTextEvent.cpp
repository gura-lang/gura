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
Gura_DeclareMethod(wx_RichTextEvent, wxRichTextEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, wxRichTextEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int commandType = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//pThis->GetEntity()->wxRichTextEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextEvent, wxRichTextEvent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, wxRichTextEvent_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextEvent, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextEvent, SetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, SetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextEvent, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextEvent, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextEvent, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextEvent, GetOldStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextEvent, GetOldStyleSheet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOldStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextEvent, SetOldStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, SetOldStyleSheet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sheet = arg.GetNumber(0)
	//pThis->GetEntity()->SetOldStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextEvent, GetNewStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextEvent, GetNewStyleSheet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNewStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextEvent, SetNewStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, SetNewStyleSheet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sheet = arg.GetNumber(0)
	//pThis->GetEntity()->SetNewStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextEvent, GetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextEvent, GetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextEvent, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, SetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextEvent, GetCharacter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextEvent, GetCharacter)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCharacter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextEvent, SetCharacter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, SetCharacter)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//pThis->GetEntity()->SetCharacter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextEvent, GetContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextEvent, GetContainer)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextEvent, SetContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, SetContainer)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//pThis->GetEntity()->SetContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextEvent, GetOldContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextEvent, GetOldContainer)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOldContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextEvent, SetOldContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, SetOldContainer)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//pThis->GetEntity()->SetOldContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextEvent, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextEvent, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextEvent)
{
	Gura_AssignMethod(wx_RichTextEvent, wxRichTextEvent);
	Gura_AssignMethod(wx_RichTextEvent, wxRichTextEvent_1);
	Gura_AssignMethod(wx_RichTextEvent, GetPosition);
	Gura_AssignMethod(wx_RichTextEvent, SetPosition);
	Gura_AssignMethod(wx_RichTextEvent, GetFlags);
	Gura_AssignMethod(wx_RichTextEvent, SetFlags);
	Gura_AssignMethod(wx_RichTextEvent, GetOldStyleSheet);
	Gura_AssignMethod(wx_RichTextEvent, SetOldStyleSheet);
	Gura_AssignMethod(wx_RichTextEvent, GetNewStyleSheet);
	Gura_AssignMethod(wx_RichTextEvent, SetNewStyleSheet);
	Gura_AssignMethod(wx_RichTextEvent, GetRange);
	Gura_AssignMethod(wx_RichTextEvent, SetRange);
	Gura_AssignMethod(wx_RichTextEvent, GetCharacter);
	Gura_AssignMethod(wx_RichTextEvent, SetCharacter);
	Gura_AssignMethod(wx_RichTextEvent, GetContainer);
	Gura_AssignMethod(wx_RichTextEvent, SetContainer);
	Gura_AssignMethod(wx_RichTextEvent, GetOldContainer);
	Gura_AssignMethod(wx_RichTextEvent, SetOldContainer);
	Gura_AssignMethod(wx_RichTextEvent, Clone);
}

Gura_ImplementDescendantCreator(wx_RichTextEvent)
{
	return new Object_wx_RichTextEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
