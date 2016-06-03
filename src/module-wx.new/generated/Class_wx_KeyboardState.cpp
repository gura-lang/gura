//----------------------------------------------------------------------------
// wxKeyboardState
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxKeyboardState
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxKeyboardState
//----------------------------------------------------------------------------
Object_wx_KeyboardState::~Object_wx_KeyboardState()
{
}

Object *Object_wx_KeyboardState::Clone() const
{
	return nullptr;
}

String Object_wx_KeyboardState::ToString(bool exprFlag)
{
	String rtn("<wx.KeyboardState:");
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
Gura_DeclareFunctionAlias(__KeyboardState, "KeyboardState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "controlDown", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shiftDown", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "altDown", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "metaDown", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_KeyboardState));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__KeyboardState)
{
	//int controlDown = arg.GetNumber(0)
	//int shiftDown = arg.GetNumber(1)
	//int altDown = arg.GetNumber(2)
	//int metaDown = arg.GetNumber(3)
	//wxKeyboardState();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_KeyboardState, __GetModifiers, "GetModifiers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyboardState, __GetModifiers)
{
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetModifiers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyboardState, __HasAnyModifiers, "HasAnyModifiers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyboardState, __HasAnyModifiers)
{
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasAnyModifiers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyboardState, __HasModifiers, "HasModifiers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyboardState, __HasModifiers)
{
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasModifiers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyboardState, __ControlDown, "ControlDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyboardState, __ControlDown)
{
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ControlDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyboardState, __RawControlDown, "RawControlDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyboardState, __RawControlDown)
{
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RawControlDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyboardState, __ShiftDown, "ShiftDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyboardState, __ShiftDown)
{
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShiftDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyboardState, __MetaDown, "MetaDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyboardState, __MetaDown)
{
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MetaDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyboardState, __AltDown, "AltDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyboardState, __AltDown)
{
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AltDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyboardState, __CmdDown, "CmdDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyboardState, __CmdDown)
{
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CmdDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyboardState, __SetControlDown, "SetControlDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_KeyboardState, __SetControlDown)
{
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int down = arg.GetNumber(0)
	//pThis->GetEntity()->SetControlDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyboardState, __SetRawControlDown, "SetRawControlDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_KeyboardState, __SetRawControlDown)
{
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int down = arg.GetNumber(0)
	//pThis->GetEntity()->SetRawControlDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyboardState, __SetShiftDown, "SetShiftDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_KeyboardState, __SetShiftDown)
{
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int down = arg.GetNumber(0)
	//pThis->GetEntity()->SetShiftDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyboardState, __SetAltDown, "SetAltDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_KeyboardState, __SetAltDown)
{
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int down = arg.GetNumber(0)
	//pThis->GetEntity()->SetAltDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_KeyboardState, __SetMetaDown, "SetMetaDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_KeyboardState, __SetMetaDown)
{
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int down = arg.GetNumber(0)
	//pThis->GetEntity()->SetMetaDown();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxKeyboardState
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_KeyboardState)
{
	// Constructor assignment
	Gura_AssignFunction(__KeyboardState);
	// Method assignment
	Gura_AssignMethod(wx_KeyboardState, __GetModifiers);
	Gura_AssignMethod(wx_KeyboardState, __HasAnyModifiers);
	Gura_AssignMethod(wx_KeyboardState, __HasModifiers);
	Gura_AssignMethod(wx_KeyboardState, __ControlDown);
	Gura_AssignMethod(wx_KeyboardState, __RawControlDown);
	Gura_AssignMethod(wx_KeyboardState, __ShiftDown);
	Gura_AssignMethod(wx_KeyboardState, __MetaDown);
	Gura_AssignMethod(wx_KeyboardState, __AltDown);
	Gura_AssignMethod(wx_KeyboardState, __CmdDown);
	Gura_AssignMethod(wx_KeyboardState, __SetControlDown);
	Gura_AssignMethod(wx_KeyboardState, __SetRawControlDown);
	Gura_AssignMethod(wx_KeyboardState, __SetShiftDown);
	Gura_AssignMethod(wx_KeyboardState, __SetAltDown);
	Gura_AssignMethod(wx_KeyboardState, __SetMetaDown);
}

Gura_ImplementDescendantCreator(wx_KeyboardState)
{
	return new Object_wx_KeyboardState((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
