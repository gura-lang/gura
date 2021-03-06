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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__ComboPopup, "ComboPopup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ComboPopup));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ComboPopup)
{
	//wxComboPopup();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ComboPopup, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboPopup, __Create)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Create(parent);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboPopup, __DestroyPopup, "DestroyPopup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, __DestroyPopup)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DestroyPopup();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboPopup, __Dismiss, "Dismiss")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, __Dismiss)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Dismiss();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboPopup, __FindItem, "FindItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "trueItem", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboPopup, __FindItem)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//wxString* trueItem = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->FindItem(item, trueItem);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboPopup, __GetAdjustedSize, "GetAdjustedSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "minWidth", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "prefHeight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxHeight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboPopup, __GetAdjustedSize)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int minWidth = arg.GetNumber(0)
	//int prefHeight = arg.GetNumber(1)
	//int maxHeight = arg.GetNumber(2)
	//wxSize _rtn = pThis->GetEntity()->GetAdjustedSize(minWidth, prefHeight, maxHeight);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboPopup, __GetComboCtrl, "GetComboCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, __GetComboCtrl)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxComboCtrl* _rtn = pThis->GetEntity()->GetComboCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboPopup, __GetControl, "GetControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, __GetControl)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* _rtn = pThis->GetEntity()->GetControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboPopup, __GetStringValue, "GetStringValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, __GetStringValue)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetStringValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboPopup, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, __Init)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboPopup, __IsCreated, "IsCreated")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, __IsCreated)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsCreated();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboPopup, __LazyCreate, "LazyCreate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, __LazyCreate)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->LazyCreate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboPopup, __OnComboDoubleClick, "OnComboDoubleClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, __OnComboDoubleClick)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnComboDoubleClick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboPopup, __OnComboKeyEvent, "OnComboKeyEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboPopup, __OnComboKeyEvent)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxKeyEvent& event = arg.GetNumber(0)
	//pThis->GetEntity()->OnComboKeyEvent(event);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboPopup, __OnDismiss, "OnDismiss")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, __OnDismiss)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnDismiss();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboPopup, __OnPopup, "OnPopup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, __OnPopup)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnPopup();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboPopup, __PaintComboControl, "PaintComboControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboPopup, __PaintComboControl)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//const wxRect& rect = arg.GetNumber(1)
	//pThis->GetEntity()->PaintComboControl(dc, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboPopup, __SetStringValue, "SetStringValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboPopup, __SetStringValue)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& value = arg.GetNumber(0)
	//pThis->GetEntity()->SetStringValue(value);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxComboPopup
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ComboPopup)
{
	// Constructor assignment
	Gura_AssignFunction(__ComboPopup);
	// Method assignment
	Gura_AssignMethod(wx_ComboPopup, __Create);
	Gura_AssignMethod(wx_ComboPopup, __DestroyPopup);
	Gura_AssignMethod(wx_ComboPopup, __Dismiss);
	Gura_AssignMethod(wx_ComboPopup, __FindItem);
	Gura_AssignMethod(wx_ComboPopup, __GetAdjustedSize);
	Gura_AssignMethod(wx_ComboPopup, __GetComboCtrl);
	Gura_AssignMethod(wx_ComboPopup, __GetControl);
	Gura_AssignMethod(wx_ComboPopup, __GetStringValue);
	Gura_AssignMethod(wx_ComboPopup, __Init);
	Gura_AssignMethod(wx_ComboPopup, __IsCreated);
	Gura_AssignMethod(wx_ComboPopup, __LazyCreate);
	Gura_AssignMethod(wx_ComboPopup, __OnComboDoubleClick);
	Gura_AssignMethod(wx_ComboPopup, __OnComboKeyEvent);
	Gura_AssignMethod(wx_ComboPopup, __OnDismiss);
	Gura_AssignMethod(wx_ComboPopup, __OnPopup);
	Gura_AssignMethod(wx_ComboPopup, __PaintComboControl);
	Gura_AssignMethod(wx_ComboPopup, __SetStringValue);
}

Gura_ImplementDescendantCreator(wx_ComboPopup)
{
	return new Object_wx_ComboPopup((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
