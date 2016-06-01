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
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, wxAnyButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAnyButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, ~wxAnyButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, ~wxAnyButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->~wxAnyButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, GetBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, GetBitmapCurrent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, GetBitmapCurrent)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetBitmapCurrent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, GetBitmapDisabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, GetBitmapDisabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetBitmapDisabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, GetBitmapFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, GetBitmapFocus)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetBitmapFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, GetBitmapLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, GetBitmapLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetBitmapLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, GetBitmapPressed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, GetBitmapPressed)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetBitmapPressed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, SetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, SetBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, SetBitmapCurrent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, SetBitmapCurrent)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetBitmapCurrent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, SetBitmapDisabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, SetBitmapDisabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetBitmapDisabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, SetBitmapFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, SetBitmapFocus)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetBitmapFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, SetBitmapLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, SetBitmapLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetBitmapLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, SetBitmapPressed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, SetBitmapPressed)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetBitmapPressed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, GetBitmapMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, GetBitmapMargins)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetBitmapMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, SetBitmapMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, SetBitmapMargins)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetBitmapMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, SetBitmapMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, SetBitmapMargins)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetBitmapMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyButton, SetBitmapPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyButton, SetBitmapPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyButton *pThis = Object_wx_AnyButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetBitmapPosition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAnyButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AnyButton)
{
}

Gura_ImplementDescendantCreator(wx_AnyButton)
{
	return new Object_wx_AnyButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
