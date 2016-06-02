//----------------------------------------------------------------------------
// wxListEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxListEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxListEvent
//----------------------------------------------------------------------------
Object_wx_ListEvent::~Object_wx_ListEvent()
{
}

Object *Object_wx_ListEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ListEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ListEvent:");
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
Gura_DeclareMethod(wx_ListEvent, wxListEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListEvent, wxListEvent)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int commandType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->wxListEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListEvent, GetCacheFrom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListEvent, GetCacheFrom)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCacheFrom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListEvent, GetCacheTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListEvent, GetCacheTo)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCacheTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListEvent, GetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListEvent, GetColumn)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListEvent, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListEvent, GetData)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListEvent, GetImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListEvent, GetImage)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListEvent, GetIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListEvent, GetIndex)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListEvent, GetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListEvent, GetItem)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListEvent, GetKeyCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListEvent, GetKeyCode)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetKeyCode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListEvent, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListEvent, GetLabel)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListEvent, GetMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListEvent, GetMask)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListEvent, GetPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListEvent, GetPoint)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListEvent, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListEvent, GetText)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListEvent, IsEditCancelled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListEvent, IsEditCancelled)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEditCancelled();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxListEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListEvent)
{
	Gura_AssignMethod(wx_ListEvent, wxListEvent);
	Gura_AssignMethod(wx_ListEvent, GetCacheFrom);
	Gura_AssignMethod(wx_ListEvent, GetCacheTo);
	Gura_AssignMethod(wx_ListEvent, GetColumn);
	Gura_AssignMethod(wx_ListEvent, GetData);
	Gura_AssignMethod(wx_ListEvent, GetImage);
	Gura_AssignMethod(wx_ListEvent, GetIndex);
	Gura_AssignMethod(wx_ListEvent, GetItem);
	Gura_AssignMethod(wx_ListEvent, GetKeyCode);
	Gura_AssignMethod(wx_ListEvent, GetLabel);
	Gura_AssignMethod(wx_ListEvent, GetMask);
	Gura_AssignMethod(wx_ListEvent, GetPoint);
	Gura_AssignMethod(wx_ListEvent, GetText);
	Gura_AssignMethod(wx_ListEvent, IsEditCancelled);
}

Gura_ImplementDescendantCreator(wx_ListEvent)
{
	return new Object_wx_ListEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
