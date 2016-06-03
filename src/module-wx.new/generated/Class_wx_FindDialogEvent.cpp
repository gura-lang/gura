//----------------------------------------------------------------------------
// wxFindDialogEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFindDialogEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFindDialogEvent
//----------------------------------------------------------------------------
Object_wx_FindDialogEvent::~Object_wx_FindDialogEvent()
{
}

Object *Object_wx_FindDialogEvent::Clone() const
{
	return nullptr;
}

String Object_wx_FindDialogEvent::ToString(bool exprFlag)
{
	String rtn("<wx.FindDialogEvent:");
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
Gura_DeclareMethodAlias(wx_FindDialogEvent, __wxFindDialogEvent, "wxFindDialogEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FindDialogEvent, __wxFindDialogEvent)
{
	Object_wx_FindDialogEvent *pThis = Object_wx_FindDialogEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int commandType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->wxFindDialogEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FindDialogEvent, __GetDialog, "GetDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FindDialogEvent, __GetDialog)
{
	Object_wx_FindDialogEvent *pThis = Object_wx_FindDialogEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDialog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FindDialogEvent, __GetFindString, "GetFindString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FindDialogEvent, __GetFindString)
{
	Object_wx_FindDialogEvent *pThis = Object_wx_FindDialogEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFindString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FindDialogEvent, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FindDialogEvent, __GetFlags)
{
	Object_wx_FindDialogEvent *pThis = Object_wx_FindDialogEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FindDialogEvent, __GetReplaceString, "GetReplaceString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FindDialogEvent, __GetReplaceString)
{
	Object_wx_FindDialogEvent *pThis = Object_wx_FindDialogEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetReplaceString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFindDialogEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FindDialogEvent)
{
	Gura_AssignMethod(wx_FindDialogEvent, __wxFindDialogEvent);
	Gura_AssignMethod(wx_FindDialogEvent, __GetDialog);
	Gura_AssignMethod(wx_FindDialogEvent, __GetFindString);
	Gura_AssignMethod(wx_FindDialogEvent, __GetFlags);
	Gura_AssignMethod(wx_FindDialogEvent, __GetReplaceString);
}

Gura_ImplementDescendantCreator(wx_FindDialogEvent)
{
	return new Object_wx_FindDialogEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
