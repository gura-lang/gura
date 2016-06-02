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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_AnyButton, wxAnyButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnyButton, wxAnyButton)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxAnyButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnyButton, GetBitmap)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, GetBitmapCurrent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnyButton, GetBitmapCurrent)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapCurrent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, GetBitmapDisabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnyButton, GetBitmapDisabled)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapDisabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, GetBitmapFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnyButton, GetBitmapFocus)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, GetBitmapLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnyButton, GetBitmapLabel)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, GetBitmapPressed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnyButton, GetBitmapPressed)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapPressed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, SetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, SetBitmap)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int dir = arg.GetNumber(1)
	//pThis->GetEntity()->SetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, SetBitmapCurrent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, SetBitmapCurrent)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmapCurrent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, SetBitmapDisabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, SetBitmapDisabled)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmapDisabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, SetBitmapFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, SetBitmapFocus)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmapFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, SetBitmapLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, SetBitmapLabel)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmapLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, SetBitmapPressed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, SetBitmapPressed)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmapPressed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, GetBitmapMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnyButton, GetBitmapMargins)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, SetBitmapMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, SetBitmapMargins)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->SetBitmapMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, SetBitmapMargins_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, SetBitmapMargins_1)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmapMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, SetBitmapPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, SetBitmapPosition)
{
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmapPosition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAnyButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AnyButton)
{
	Gura_AssignMethod(wx_AnyButton, wxAnyButton);
	Gura_AssignMethod(wx_AnyButton, GetBitmap);
	Gura_AssignMethod(wx_AnyButton, GetBitmapCurrent);
	Gura_AssignMethod(wx_AnyButton, GetBitmapDisabled);
	Gura_AssignMethod(wx_AnyButton, GetBitmapFocus);
	Gura_AssignMethod(wx_AnyButton, GetBitmapLabel);
	Gura_AssignMethod(wx_AnyButton, GetBitmapPressed);
	Gura_AssignMethod(wx_AnyButton, SetBitmap);
	Gura_AssignMethod(wx_AnyButton, SetBitmapCurrent);
	Gura_AssignMethod(wx_AnyButton, SetBitmapDisabled);
	Gura_AssignMethod(wx_AnyButton, SetBitmapFocus);
	Gura_AssignMethod(wx_AnyButton, SetBitmapLabel);
	Gura_AssignMethod(wx_AnyButton, SetBitmapPressed);
	Gura_AssignMethod(wx_AnyButton, GetBitmapMargins);
	Gura_AssignMethod(wx_AnyButton, SetBitmapMargins);
	Gura_AssignMethod(wx_AnyButton, SetBitmapMargins_1);
	Gura_AssignMethod(wx_AnyButton, SetBitmapPosition);
}

Gura_ImplementDescendantCreator(wx_AnyButton)
{
	return new Object_wx_AnyButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
