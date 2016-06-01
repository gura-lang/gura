//----------------------------------------------------------------------------
// wxAnimationCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAnimationCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAnimationCtrl
//----------------------------------------------------------------------------
Object_wx_AnimationCtrl::~Object_wx_AnimationCtrl()
{
}

Object *Object_wx_AnimationCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_AnimationCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.AnimationCtrl:");
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

Gura_DeclareMethod(wx_AnimationCtrl, wxAnimationCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, wxAnimationCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAnimationCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, GetAnimation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, GetAnimation)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetAnimation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, GetInactiveBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, GetInactiveBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetInactiveBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, IsPlaying)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, IsPlaying)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->IsPlaying();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, LoadFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, Load)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, Load)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, Play)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, Play)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Play();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, SetAnimation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, SetAnimation)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetAnimation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, SetInactiveBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, SetInactiveBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetInactiveBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, Stop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, Stop)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Stop();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAnimationCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AnimationCtrl)
{
}

Gura_ImplementDescendantCreator(wx_AnimationCtrl)
{
	return new Object_wx_AnimationCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
