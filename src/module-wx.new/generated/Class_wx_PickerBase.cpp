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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxPickerBase, "wxPickerBase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PickerBase));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxPickerBase)
{
	//wxPickerBase();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PickerBase, __CreateBase, "CreateBase")
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

Gura_ImplementMethod(wx_PickerBase, __CreateBase)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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

Gura_DeclareMethodAlias(wx_PickerBase, __GetInternalMargin, "GetInternalMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, __GetInternalMargin)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInternalMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __GetPickerCtrlProportion, "GetPickerCtrlProportion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, __GetPickerCtrlProportion)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPickerCtrlProportion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __GetTextCtrl, "GetTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, __GetTextCtrl)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __GetPickerCtrl, "GetPickerCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, __GetPickerCtrl)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPickerCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __GetTextCtrlProportion, "GetTextCtrlProportion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, __GetTextCtrlProportion)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextCtrlProportion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __HasTextCtrl, "HasTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, __HasTextCtrl)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __IsPickerCtrlGrowable, "IsPickerCtrlGrowable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, __IsPickerCtrlGrowable)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsPickerCtrlGrowable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __IsTextCtrlGrowable, "IsTextCtrlGrowable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, __IsTextCtrlGrowable)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsTextCtrlGrowable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __SetInternalMargin, "SetInternalMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, __SetInternalMargin)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//pThis->GetEntity()->SetInternalMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __SetPickerCtrlGrowable, "SetPickerCtrlGrowable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, __SetPickerCtrlGrowable)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int grow = arg.GetNumber(0)
	//pThis->GetEntity()->SetPickerCtrlGrowable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __SetPickerCtrlProportion, "SetPickerCtrlProportion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, __SetPickerCtrlProportion)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int prop = arg.GetNumber(0)
	//pThis->GetEntity()->SetPickerCtrlProportion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __SetTextCtrlGrowable, "SetTextCtrlGrowable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, __SetTextCtrlGrowable)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int grow = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextCtrlGrowable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __SetTextCtrlProportion, "SetTextCtrlProportion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, __SetTextCtrlProportion)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int prop = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextCtrlProportion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __SetTextCtrl, "SetTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, __SetTextCtrl)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __SetPickerCtrl, "SetPickerCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "picker", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, __SetPickerCtrl)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int picker = arg.GetNumber(0)
	//pThis->GetEntity()->SetPickerCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __UpdatePickerFromTextCtrl, "UpdatePickerFromTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, __UpdatePickerFromTextCtrl)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UpdatePickerFromTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __UpdateTextCtrlFromPicker, "UpdateTextCtrlFromPicker")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, __UpdateTextCtrlFromPicker)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UpdateTextCtrlFromPicker();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __GetTextCtrlStyle, "GetTextCtrlStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, __GetTextCtrlStyle)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->GetTextCtrlStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __GetPickerStyle, "GetPickerStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, __GetPickerStyle)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->GetPickerStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PickerBase, __PostCreation, "PostCreation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PickerBase, __PostCreation)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PostCreation();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPickerBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PickerBase)
{
	// Constructor assignment
	Gura_AssignFunction(__wxPickerBase);
	// Method assignment
	Gura_AssignMethod(wx_PickerBase, __CreateBase);
	Gura_AssignMethod(wx_PickerBase, __GetInternalMargin);
	Gura_AssignMethod(wx_PickerBase, __GetPickerCtrlProportion);
	Gura_AssignMethod(wx_PickerBase, __GetTextCtrl);
	Gura_AssignMethod(wx_PickerBase, __GetPickerCtrl);
	Gura_AssignMethod(wx_PickerBase, __GetTextCtrlProportion);
	Gura_AssignMethod(wx_PickerBase, __HasTextCtrl);
	Gura_AssignMethod(wx_PickerBase, __IsPickerCtrlGrowable);
	Gura_AssignMethod(wx_PickerBase, __IsTextCtrlGrowable);
	Gura_AssignMethod(wx_PickerBase, __SetInternalMargin);
	Gura_AssignMethod(wx_PickerBase, __SetPickerCtrlGrowable);
	Gura_AssignMethod(wx_PickerBase, __SetPickerCtrlProportion);
	Gura_AssignMethod(wx_PickerBase, __SetTextCtrlGrowable);
	Gura_AssignMethod(wx_PickerBase, __SetTextCtrlProportion);
	Gura_AssignMethod(wx_PickerBase, __SetTextCtrl);
	Gura_AssignMethod(wx_PickerBase, __SetPickerCtrl);
	Gura_AssignMethod(wx_PickerBase, __UpdatePickerFromTextCtrl);
	Gura_AssignMethod(wx_PickerBase, __UpdateTextCtrlFromPicker);
	Gura_AssignMethod(wx_PickerBase, __GetTextCtrlStyle);
	Gura_AssignMethod(wx_PickerBase, __GetPickerStyle);
	Gura_AssignMethod(wx_PickerBase, __PostCreation);
}

Gura_ImplementDescendantCreator(wx_PickerBase)
{
	return new Object_wx_PickerBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
