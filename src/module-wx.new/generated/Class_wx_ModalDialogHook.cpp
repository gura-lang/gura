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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__ModalDialogHook, "ModalDialogHook")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ModalDialogHook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ModalDialogHook)
{
	//wxModalDialogHook();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ModalDialogHook, __Register, "Register")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ModalDialogHook, __Register)
{
	Object_wx_ModalDialogHook *pThis = Object_wx_ModalDialogHook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Register();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ModalDialogHook, __Unregister, "Unregister")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ModalDialogHook, __Unregister)
{
	Object_wx_ModalDialogHook *pThis = Object_wx_ModalDialogHook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Unregister();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ModalDialogHook, __Enter, "Enter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ModalDialogHook, __Enter)
{
	Object_wx_ModalDialogHook *pThis = Object_wx_ModalDialogHook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDialog* dialog = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->Enter(dialog);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ModalDialogHook, __Exit, "Exit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ModalDialogHook, __Exit)
{
	Object_wx_ModalDialogHook *pThis = Object_wx_ModalDialogHook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDialog* dialog = arg.GetNumber(0)
	//pThis->GetEntity()->Exit(dialog);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxModalDialogHook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ModalDialogHook)
{
	// Constructor assignment
	Gura_AssignFunction(__ModalDialogHook);
	// Method assignment
	Gura_AssignMethod(wx_ModalDialogHook, __Register);
	Gura_AssignMethod(wx_ModalDialogHook, __Unregister);
	Gura_AssignMethod(wx_ModalDialogHook, __Enter);
	Gura_AssignMethod(wx_ModalDialogHook, __Exit);
}

Gura_ImplementDescendantCreator(wx_ModalDialogHook)
{
	return new Object_wx_ModalDialogHook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
