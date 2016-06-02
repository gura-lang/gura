//----------------------------------------------------------------------------
// wxQueryLayoutInfoEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxQueryLayoutInfoEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxQueryLayoutInfoEvent
//----------------------------------------------------------------------------
Object_wx_QueryLayoutInfoEvent::~Object_wx_QueryLayoutInfoEvent()
{
}

Object *Object_wx_QueryLayoutInfoEvent::Clone() const
{
	return nullptr;
}

String Object_wx_QueryLayoutInfoEvent::ToString(bool exprFlag)
{
	String rtn("<wx.QueryLayoutInfoEvent:");
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
Gura_DeclareMethod(wx_QueryLayoutInfoEvent, wxQueryLayoutInfoEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, wxQueryLayoutInfoEvent)
{
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->wxQueryLayoutInfoEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, GetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, GetAlignment)
{
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, GetFlags)
{
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, GetOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, GetOrientation)
{
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOrientation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, GetRequestedLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, GetRequestedLength)
{
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRequestedLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, GetSize)
{
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, SetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, SetAlignment)
{
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alignment = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, SetFlags)
{
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, SetOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, SetOrientation)
{
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//pThis->GetEntity()->SetOrientation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, SetRequestedLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, SetRequestedLength)
{
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int length = arg.GetNumber(0)
	//pThis->GetEntity()->SetRequestedLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, SetSize)
{
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetSize();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxQueryLayoutInfoEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_QueryLayoutInfoEvent)
{
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, wxQueryLayoutInfoEvent);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, GetAlignment);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, GetFlags);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, GetOrientation);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, GetRequestedLength);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, GetSize);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, SetAlignment);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, SetFlags);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, SetOrientation);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, SetRequestedLength);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, SetSize);
}

Gura_ImplementDescendantCreator(wx_QueryLayoutInfoEvent)
{
	return new Object_wx_QueryLayoutInfoEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
