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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_WindowModalDialogEvent, wxWindowModalDialogEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WindowModalDialogEvent, wxWindowModalDialogEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_WindowModalDialogEvent *pThis = Object_wx_WindowModalDialogEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int commandType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->wxWindowModalDialogEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WindowModalDialogEvent, GetDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WindowModalDialogEvent, GetDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_WindowModalDialogEvent *pThis = Object_wx_WindowModalDialogEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WindowModalDialogEvent, GetReturnCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WindowModalDialogEvent, GetReturnCode)
{
	Signal &sig = env.GetSignal();
	Object_wx_WindowModalDialogEvent *pThis = Object_wx_WindowModalDialogEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetReturnCode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WindowModalDialogEvent, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WindowModalDialogEvent, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_WindowModalDialogEvent *pThis = Object_wx_WindowModalDialogEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWindowModalDialogEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowModalDialogEvent)
{
	Gura_AssignMethod(wx_WindowModalDialogEvent, wxWindowModalDialogEvent);
	Gura_AssignMethod(wx_WindowModalDialogEvent, GetDialog);
	Gura_AssignMethod(wx_WindowModalDialogEvent, GetReturnCode);
	Gura_AssignMethod(wx_WindowModalDialogEvent, Clone);
}

Gura_ImplementDescendantCreator(wx_WindowModalDialogEvent)
{
	return new Object_wx_WindowModalDialogEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
