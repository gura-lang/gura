//----------------------------------------------------------------------------
// wxComboPopup
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxComboPopup
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxComboPopup
//----------------------------------------------------------------------------
Object_wx_ComboPopup::~Object_wx_ComboPopup()
{
}

Object *Object_wx_ComboPopup::Clone() const
{
	return nullptr;
}

String Object_wx_ComboPopup::ToString(bool exprFlag)
{
	String rtn("<wx.ComboPopup:");
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
Gura_DeclareMethod(wx_ComboPopup, wxComboPopup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, wxComboPopup)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxComboPopup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboPopup, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, DestroyPopup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, DestroyPopup)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DestroyPopup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, Dismiss)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, Dismiss)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Dismiss();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, FindItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "trueItem", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboPopup, FindItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int trueItem = arg.GetNumber(1)
	//pThis->GetEntity()->FindItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, GetAdjustedSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minWidth", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "prefHeight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxHeight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboPopup, GetAdjustedSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int minWidth = arg.GetNumber(0)
	//int prefHeight = arg.GetNumber(1)
	//int maxHeight = arg.GetNumber(2)
	//pThis->GetEntity()->GetAdjustedSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, GetComboCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, GetComboCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetComboCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, GetControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, GetControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, GetStringValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, GetStringValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStringValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, Init)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, IsCreated)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, IsCreated)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsCreated();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, LazyCreate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, LazyCreate)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LazyCreate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, OnComboDoubleClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, OnComboDoubleClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnComboDoubleClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, OnComboKeyEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboPopup, OnComboKeyEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnComboKeyEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, OnDismiss)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, OnDismiss)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnDismiss();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, OnPopup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, OnPopup)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnPopup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, PaintComboControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboPopup, PaintComboControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//pThis->GetEntity()->PaintComboControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, SetStringValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboPopup, SetStringValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetStringValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxComboPopup
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ComboPopup)
{
	Gura_AssignMethod(wx_ComboPopup, wxComboPopup);
	Gura_AssignMethod(wx_ComboPopup, Create);
	Gura_AssignMethod(wx_ComboPopup, DestroyPopup);
	Gura_AssignMethod(wx_ComboPopup, Dismiss);
	Gura_AssignMethod(wx_ComboPopup, FindItem);
	Gura_AssignMethod(wx_ComboPopup, GetAdjustedSize);
	Gura_AssignMethod(wx_ComboPopup, GetComboCtrl);
	Gura_AssignMethod(wx_ComboPopup, GetControl);
	Gura_AssignMethod(wx_ComboPopup, GetStringValue);
	Gura_AssignMethod(wx_ComboPopup, Init);
	Gura_AssignMethod(wx_ComboPopup, IsCreated);
	Gura_AssignMethod(wx_ComboPopup, LazyCreate);
	Gura_AssignMethod(wx_ComboPopup, OnComboDoubleClick);
	Gura_AssignMethod(wx_ComboPopup, OnComboKeyEvent);
	Gura_AssignMethod(wx_ComboPopup, OnDismiss);
	Gura_AssignMethod(wx_ComboPopup, OnPopup);
	Gura_AssignMethod(wx_ComboPopup, PaintComboControl);
	Gura_AssignMethod(wx_ComboPopup, SetStringValue);
}

Gura_ImplementDescendantCreator(wx_ComboPopup)
{
	return new Object_wx_ComboPopup((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
