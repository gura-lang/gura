//----------------------------------------------------------------------------
// wxSound
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSound
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSound
//----------------------------------------------------------------------------
Object_wx_Sound::~Object_wx_Sound()
{
}

Object *Object_wx_Sound::Clone() const
{
	return nullptr;
}

String Object_wx_Sound::ToString(bool exprFlag)
{
	String rtn("<wx.Sound:");
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
Gura_DeclareMethod(wx_Sound, wxSound)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sound, wxSound)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sound *pThis = Object_wx_Sound::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxSound();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sound, wxSound_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "isResource", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sound, wxSound_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sound *pThis = Object_wx_Sound::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fileName = arg.GetNumber(0)
	//int isResource = arg.GetNumber(1)
	//pThis->GetEntity()->wxSound();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sound, wxSound_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sound, wxSound_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sound *pThis = Object_wx_Sound::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->wxSound();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sound, ~wxSound)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sound, ~wxSound)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sound *pThis = Object_wx_Sound::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxSound();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sound, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "isResource", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sound, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sound *pThis = Object_wx_Sound::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fileName = arg.GetNumber(0)
	//int isResource = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sound, Create_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sound, Create_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sound *pThis = Object_wx_Sound::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sound, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sound, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sound *pThis = Object_wx_Sound::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sound, IsPlaying)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sound, IsPlaying)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sound *pThis = Object_wx_Sound::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsPlaying();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sound, Play)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sound, Play)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sound *pThis = Object_wx_Sound::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->Play();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sound, Play_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sound, Play_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sound *pThis = Object_wx_Sound::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Play();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sound, Stop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sound, Stop)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sound *pThis = Object_wx_Sound::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Stop();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSound
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Sound)
{
	Gura_AssignMethod(wx_Sound, wxSound);
	Gura_AssignMethod(wx_Sound, wxSound_1);
	Gura_AssignMethod(wx_Sound, wxSound_2);
	Gura_AssignMethod(wx_Sound, ~wxSound);
	Gura_AssignMethod(wx_Sound, Create);
	Gura_AssignMethod(wx_Sound, Create_1);
	Gura_AssignMethod(wx_Sound, IsOk);
	Gura_AssignMethod(wx_Sound, IsPlaying);
	Gura_AssignMethod(wx_Sound, Play);
	Gura_AssignMethod(wx_Sound, Play_1);
	Gura_AssignMethod(wx_Sound, Stop);
}

Gura_ImplementDescendantCreator(wx_Sound)
{
	return new Object_wx_Sound((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
