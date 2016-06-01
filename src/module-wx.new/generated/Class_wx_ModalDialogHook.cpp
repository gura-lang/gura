//----------------------------------------------------------------------------
// wxModalDialogHook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxModalDialogHook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxModalDialogHook
//----------------------------------------------------------------------------
Object_wx_ModalDialogHook::~Object_wx_ModalDialogHook()
{
}

Object *Object_wx_ModalDialogHook::Clone() const
{
	return nullptr;
}

String Object_wx_ModalDialogHook::ToString(bool exprFlag)
{
	String rtn("<wx.ModalDialogHook:");
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
Gura_DeclareMethod(wx_ModalDialogHook, wxModalDialogHook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ModalDialogHook, wxModalDialogHook)
{
	Signal &sig = env.GetSignal();
	Object_wx_ModalDialogHook *pThis = Object_wx_ModalDialogHook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxModalDialogHook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ModalDialogHook, ~wxModalDialogHook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ModalDialogHook, ~wxModalDialogHook)
{
	Signal &sig = env.GetSignal();
	Object_wx_ModalDialogHook *pThis = Object_wx_ModalDialogHook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxModalDialogHook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ModalDialogHook, Register)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ModalDialogHook, Register)
{
	Signal &sig = env.GetSignal();
	Object_wx_ModalDialogHook *pThis = Object_wx_ModalDialogHook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Register();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ModalDialogHook, Unregister)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ModalDialogHook, Unregister)
{
	Signal &sig = env.GetSignal();
	Object_wx_ModalDialogHook *pThis = Object_wx_ModalDialogHook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Unregister();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ModalDialogHook, Enter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ModalDialogHook, Enter)
{
	Signal &sig = env.GetSignal();
	Object_wx_ModalDialogHook *pThis = Object_wx_ModalDialogHook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dialog = arg.GetNumber(0)
	//pThis->GetEntity()->Enter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ModalDialogHook, Exit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ModalDialogHook, Exit)
{
	Signal &sig = env.GetSignal();
	Object_wx_ModalDialogHook *pThis = Object_wx_ModalDialogHook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dialog = arg.GetNumber(0)
	//pThis->GetEntity()->Exit();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxModalDialogHook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ModalDialogHook)
{
	Gura_AssignMethod(wx_ModalDialogHook, wxModalDialogHook);
	Gura_AssignMethod(wx_ModalDialogHook, ~wxModalDialogHook);
	Gura_AssignMethod(wx_ModalDialogHook, Register);
	Gura_AssignMethod(wx_ModalDialogHook, Unregister);
	Gura_AssignMethod(wx_ModalDialogHook, Enter);
	Gura_AssignMethod(wx_ModalDialogHook, Exit);
}

Gura_ImplementDescendantCreator(wx_ModalDialogHook)
{
	return new Object_wx_ModalDialogHook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
