//----------------------------------------------------------------------------
// wxBookCtrlEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBookCtrlEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBookCtrlEvent
//----------------------------------------------------------------------------
Object_wx_BookCtrlEvent::~Object_wx_BookCtrlEvent()
{
}

Object *Object_wx_BookCtrlEvent::Clone() const
{
	return nullptr;
}

String Object_wx_BookCtrlEvent::ToString(bool exprFlag)
{
	String rtn("<wx.BookCtrlEvent:");
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
Gura_DeclareFunctionAlias(__BookCtrlEvent, "BookCtrlEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sel", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "oldSel", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BookCtrlEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BookCtrlEvent)
{
	//wxEventType eventType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int sel = arg.GetNumber(2)
	//int oldSel = arg.GetNumber(3)
	//wxBookCtrlEvent(eventType, id, sel, oldSel);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_BookCtrlEvent, __GetOldSelection, "GetOldSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_BookCtrlEvent, __GetOldSelection)
{
	Object_wx_BookCtrlEvent *pThis = Object_wx_BookCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetOldSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BookCtrlEvent, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_BookCtrlEvent, __GetSelection)
{
	Object_wx_BookCtrlEvent *pThis = Object_wx_BookCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BookCtrlEvent, __SetOldSelection, "SetOldSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BookCtrlEvent, __SetOldSelection)
{
	Object_wx_BookCtrlEvent *pThis = Object_wx_BookCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetOldSelection(page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BookCtrlEvent, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BookCtrlEvent, __SetSelection)
{
	Object_wx_BookCtrlEvent *pThis = Object_wx_BookCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection(page);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBookCtrlEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BookCtrlEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__BookCtrlEvent);
	// Method assignment
	Gura_AssignMethod(wx_BookCtrlEvent, __GetOldSelection);
	Gura_AssignMethod(wx_BookCtrlEvent, __GetSelection);
	Gura_AssignMethod(wx_BookCtrlEvent, __SetOldSelection);
	Gura_AssignMethod(wx_BookCtrlEvent, __SetSelection);
}

Gura_ImplementDescendantCreator(wx_BookCtrlEvent)
{
	return new Object_wx_BookCtrlEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
