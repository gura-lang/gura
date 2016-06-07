//----------------------------------------------------------------------------
// wxWindowModalDialogEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowModalDialogEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWindowModalDialogEvent
//----------------------------------------------------------------------------
Object_wx_WindowModalDialogEvent::~Object_wx_WindowModalDialogEvent()
{
}

Object *Object_wx_WindowModalDialogEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WindowModalDialogEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WindowModalDialogEvent:");
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
Gura_DeclareFunctionAlias(__WindowModalDialogEvent, "WindowModalDialogEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WindowModalDialogEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WindowModalDialogEvent)
{
	//wxEventType commandType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//wxWindowModalDialogEvent(commandType, id);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_WindowModalDialogEvent, __GetDialog, "GetDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WindowModalDialogEvent, __GetDialog)
{
	Object_wx_WindowModalDialogEvent *pThis = Object_wx_WindowModalDialogEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDialog* _rtn = pThis->GetEntity()->GetDialog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WindowModalDialogEvent, __GetReturnCode, "GetReturnCode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WindowModalDialogEvent, __GetReturnCode)
{
	Object_wx_WindowModalDialogEvent *pThis = Object_wx_WindowModalDialogEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetReturnCode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WindowModalDialogEvent, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WindowModalDialogEvent, __Clone)
{
	Object_wx_WindowModalDialogEvent *pThis = Object_wx_WindowModalDialogEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxEvent* _rtn = pThis->GetEntity()->Clone();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWindowModalDialogEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowModalDialogEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__WindowModalDialogEvent);
	// Method assignment
	Gura_AssignMethod(wx_WindowModalDialogEvent, __GetDialog);
	Gura_AssignMethod(wx_WindowModalDialogEvent, __GetReturnCode);
	Gura_AssignMethod(wx_WindowModalDialogEvent, __Clone);
}

Gura_ImplementDescendantCreator(wx_WindowModalDialogEvent)
{
	return new Object_wx_WindowModalDialogEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
