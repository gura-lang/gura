//----------------------------------------------------------------------------
// wxPickerBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPickerBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPickerBase
//----------------------------------------------------------------------------
Object_wx_PickerBase::~Object_wx_PickerBase()
{
}

Object *Object_wx_PickerBase::Clone() const
{
	return nullptr;
}

String Object_wx_PickerBase::ToString(bool exprFlag)
{
	String rtn("<wx.PickerBase:");
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
Gura_DeclareMethod(wx_PickerBase, wxPickerBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, wxPickerBase)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxPickerBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, ~wxPickerBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, ~wxPickerBase)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxPickerBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, CreateBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, CreateBase)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->CreateBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, GetInternalMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, GetInternalMargin)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetInternalMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, GetPickerCtrlProportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, GetPickerCtrlProportion)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPickerCtrlProportion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, GetTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, GetTextCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, GetPickerCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, GetPickerCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPickerCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, GetTextCtrlProportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, GetTextCtrlProportion)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTextCtrlProportion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, HasTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, HasTextCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, IsPickerCtrlGrowable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, IsPickerCtrlGrowable)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsPickerCtrlGrowable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, IsTextCtrlGrowable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, IsTextCtrlGrowable)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsTextCtrlGrowable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, SetInternalMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, SetInternalMargin)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//pThis->GetEntity()->SetInternalMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, SetPickerCtrlGrowable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, SetPickerCtrlGrowable)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int grow = arg.GetNumber(0)
	//pThis->GetEntity()->SetPickerCtrlGrowable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, SetPickerCtrlProportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, SetPickerCtrlProportion)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int prop = arg.GetNumber(0)
	//pThis->GetEntity()->SetPickerCtrlProportion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, SetTextCtrlGrowable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, SetTextCtrlGrowable)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int grow = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextCtrlGrowable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, SetTextCtrlProportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, SetTextCtrlProportion)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int prop = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextCtrlProportion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, SetTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, SetTextCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, SetPickerCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "picker", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, SetPickerCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int picker = arg.GetNumber(0)
	//pThis->GetEntity()->SetPickerCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, UpdatePickerFromTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, UpdatePickerFromTextCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UpdatePickerFromTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, UpdateTextCtrlFromPicker)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, UpdateTextCtrlFromPicker)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UpdateTextCtrlFromPicker();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, GetTextCtrlStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, GetTextCtrlStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->GetTextCtrlStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, GetPickerStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, GetPickerStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->GetPickerStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PickerBase, PostCreation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, PostCreation)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->PostCreation();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPickerBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PickerBase)
{
	Gura_AssignMethod(wx_PickerBase, wxPickerBase);
	Gura_AssignMethod(wx_PickerBase, ~wxPickerBase);
	Gura_AssignMethod(wx_PickerBase, CreateBase);
	Gura_AssignMethod(wx_PickerBase, GetInternalMargin);
	Gura_AssignMethod(wx_PickerBase, GetPickerCtrlProportion);
	Gura_AssignMethod(wx_PickerBase, GetTextCtrl);
	Gura_AssignMethod(wx_PickerBase, GetPickerCtrl);
	Gura_AssignMethod(wx_PickerBase, GetTextCtrlProportion);
	Gura_AssignMethod(wx_PickerBase, HasTextCtrl);
	Gura_AssignMethod(wx_PickerBase, IsPickerCtrlGrowable);
	Gura_AssignMethod(wx_PickerBase, IsTextCtrlGrowable);
	Gura_AssignMethod(wx_PickerBase, SetInternalMargin);
	Gura_AssignMethod(wx_PickerBase, SetPickerCtrlGrowable);
	Gura_AssignMethod(wx_PickerBase, SetPickerCtrlProportion);
	Gura_AssignMethod(wx_PickerBase, SetTextCtrlGrowable);
	Gura_AssignMethod(wx_PickerBase, SetTextCtrlProportion);
	Gura_AssignMethod(wx_PickerBase, SetTextCtrl);
	Gura_AssignMethod(wx_PickerBase, SetPickerCtrl);
	Gura_AssignMethod(wx_PickerBase, UpdatePickerFromTextCtrl);
	Gura_AssignMethod(wx_PickerBase, UpdateTextCtrlFromPicker);
	Gura_AssignMethod(wx_PickerBase, GetTextCtrlStyle);
	Gura_AssignMethod(wx_PickerBase, GetPickerStyle);
	Gura_AssignMethod(wx_PickerBase, PostCreation);
}

Gura_ImplementDescendantCreator(wx_PickerBase)
{
	return new Object_wx_PickerBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
