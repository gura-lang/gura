//----------------------------------------------------------------------------
// wxAnyButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAnyButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAnyButton
//----------------------------------------------------------------------------
Object_wx_AnyButton::~Object_wx_AnyButton()
{
}

Object *Object_wx_AnyButton::Clone() const
{
	return nullptr;
}

String Object_wx_AnyButton::ToString(bool exprFlag)
{
	String rtn("<wx.AnyButton:");
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
Gura_DeclareFunctionAlias(__AnyButton, "AnyButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AnyButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AnyButton)
{
	//wxAnyButton();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AnyButton, __GetBitmap, "GetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnyButton, __GetBitmap)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyButton, __GetBitmapCurrent, "GetBitmapCurrent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnyButton, __GetBitmapCurrent)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapCurrent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyButton, __GetBitmapDisabled, "GetBitmapDisabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnyButton, __GetBitmapDisabled)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapDisabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyButton, __GetBitmapFocus, "GetBitmapFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnyButton, __GetBitmapFocus)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyButton, __GetBitmapLabel, "GetBitmapLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnyButton, __GetBitmapLabel)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyButton, __GetBitmapPressed, "GetBitmapPressed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnyButton, __GetBitmapPressed)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapPressed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyButton, __SetBitmap, "SetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, __SetBitmap)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//wxDirection dir = arg.GetNumber(1)
	//pThis->GetEntity()->SetBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyButton, __SetBitmapCurrent, "SetBitmapCurrent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, __SetBitmapCurrent)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmapCurrent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyButton, __SetBitmapDisabled, "SetBitmapDisabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, __SetBitmapDisabled)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmapDisabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyButton, __SetBitmapFocus, "SetBitmapFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, __SetBitmapFocus)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmapFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyButton, __SetBitmapLabel, "SetBitmapLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, __SetBitmapLabel)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmapLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyButton, __SetBitmapPressed, "SetBitmapPressed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, __SetBitmapPressed)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmapPressed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyButton, __GetBitmapMargins, "GetBitmapMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnyButton, __GetBitmapMargins)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyButton, __SetBitmapMargins, "SetBitmapMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, __SetBitmapMargins)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//pThis->GetEntity()->SetBitmapMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyButton, __SetBitmapMargins_1, "SetBitmapMargins_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, __SetBitmapMargins_1)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmapMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyButton, __SetBitmapPosition, "SetBitmapPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, __SetBitmapPosition)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDirection dir = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmapPosition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAnyButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AnyButton)
{
	// Constructor assignment
	Gura_AssignFunction(__AnyButton);
	// Method assignment
	Gura_AssignMethod(wx_AnyButton, __GetBitmap);
	Gura_AssignMethod(wx_AnyButton, __GetBitmapCurrent);
	Gura_AssignMethod(wx_AnyButton, __GetBitmapDisabled);
	Gura_AssignMethod(wx_AnyButton, __GetBitmapFocus);
	Gura_AssignMethod(wx_AnyButton, __GetBitmapLabel);
	Gura_AssignMethod(wx_AnyButton, __GetBitmapPressed);
	Gura_AssignMethod(wx_AnyButton, __SetBitmap);
	Gura_AssignMethod(wx_AnyButton, __SetBitmapCurrent);
	Gura_AssignMethod(wx_AnyButton, __SetBitmapDisabled);
	Gura_AssignMethod(wx_AnyButton, __SetBitmapFocus);
	Gura_AssignMethod(wx_AnyButton, __SetBitmapLabel);
	Gura_AssignMethod(wx_AnyButton, __SetBitmapPressed);
	Gura_AssignMethod(wx_AnyButton, __GetBitmapMargins);
	Gura_AssignMethod(wx_AnyButton, __SetBitmapMargins);
	Gura_AssignMethod(wx_AnyButton, __SetBitmapMargins_1);
	Gura_AssignMethod(wx_AnyButton, __SetBitmapPosition);
}

Gura_ImplementDescendantCreator(wx_AnyButton)
{
	return new Object_wx_AnyButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
