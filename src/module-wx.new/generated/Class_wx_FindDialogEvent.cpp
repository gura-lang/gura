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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__FindDialogEvent, "FindDialogEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FindDialogEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FindDialogEvent)
{
	//wxEventType commandType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//wxFindDialogEvent(commandType, id);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FindDialogEvent, __GetDialog, "GetDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FindDialogEvent, __GetDialog)
{
	Object_wx_FindDialogEvent *pThis = Object_wx_FindDialogEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFindReplaceDialog* _rtn = pThis->GetEntity()->GetDialog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FindDialogEvent, __GetFindString, "GetFindString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FindDialogEvent, __GetFindString)
{
	Object_wx_FindDialogEvent *pThis = Object_wx_FindDialogEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetFindString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FindDialogEvent, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FindDialogEvent, __GetFlags)
{
	Object_wx_FindDialogEvent *pThis = Object_wx_FindDialogEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FindDialogEvent, __GetReplaceString, "GetReplaceString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FindDialogEvent, __GetReplaceString)
{
	Object_wx_FindDialogEvent *pThis = Object_wx_FindDialogEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetReplaceString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFindDialogEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FindDialogEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__FindDialogEvent);
	// Method assignment
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
