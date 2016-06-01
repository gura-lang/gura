//----------------------------------------------------------------------------
// wxAnimation
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAnimation
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAnimation
//----------------------------------------------------------------------------
Object_wx_Animation::~Object_wx_Animation()
{
}

Object *Object_wx_Animation::Clone() const
{
	return nullptr;
}

String Object_wx_Animation::ToString(bool exprFlag)
{
	String rtn("<wx.Animation:");
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

Gura_DeclareMethod(wx_Animation, wxAnimation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, wxAnimation)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAnimation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, wxAnimation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, wxAnimation)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAnimation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, wxAnimation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, wxAnimation)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAnimation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, ~wxAnimation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, ~wxAnimation)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->~wxAnimation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, GetDelay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, GetDelay)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetDelay();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, GetFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, GetFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, GetFrameCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, GetFrameCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetFrameCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, Load)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, Load)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, LoadFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAnimation
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Animation)
{
}

Gura_ImplementDescendantCreator(wx_Animation)
{
	return new Object_wx_Animation((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
