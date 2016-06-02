//----------------------------------------------------------------------------
// wxMediaCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMediaCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMediaCtrl
//----------------------------------------------------------------------------
Object_wx_MediaCtrl::~Object_wx_MediaCtrl()
{
}

Object *Object_wx_MediaCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_MediaCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.MediaCtrl:");
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
Gura_DeclareMethod(wx_MediaCtrl, wxMediaCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, wxMediaCtrl)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxMediaCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, wxMediaCtrl_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "szBackend", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, wxMediaCtrl_1)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int fileName = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int szBackend = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->wxMediaCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "szBackend", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, Create)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int fileName = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int szBackend = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, GetBestSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, GetBestSize)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBestSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, GetPlaybackRate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, GetPlaybackRate)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPlaybackRate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, GetState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, GetState)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, GetVolume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, GetVolume)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVolume();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, Length)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, Length)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Length();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, Load)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, Load)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fileName = arg.GetNumber(0)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, Load_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "uri", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, Load_1)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int uri = arg.GetNumber(0)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, Load_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "uri", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proxy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, Load_2)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int uri = arg.GetNumber(0)
	//int proxy = arg.GetNumber(1)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, LoadURI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, LoadURI)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fileName = arg.GetNumber(0)
	//pThis->GetEntity()->LoadURI();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, LoadURIWithProxy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proxy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, LoadURIWithProxy)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fileName = arg.GetNumber(0)
	//int proxy = arg.GetNumber(1)
	//pThis->GetEntity()->LoadURIWithProxy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, Pause)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, Pause)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Pause();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, Play)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, Play)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Play();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, Seek)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "where", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, Seek)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int where = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->Seek();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, SetPlaybackRate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dRate", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, SetPlaybackRate)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dRate = arg.GetNumber(0)
	//pThis->GetEntity()->SetPlaybackRate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, SetVolume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dVolume", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, SetVolume)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dVolume = arg.GetNumber(0)
	//pThis->GetEntity()->SetVolume();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, ShowPlayerControls)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, ShowPlayerControls)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->ShowPlayerControls();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, Stop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, Stop)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Stop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MediaCtrl, Tell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, Tell)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Tell();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMediaCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MediaCtrl)
{
	Gura_AssignMethod(wx_MediaCtrl, wxMediaCtrl);
	Gura_AssignMethod(wx_MediaCtrl, wxMediaCtrl_1);
	Gura_AssignMethod(wx_MediaCtrl, Create);
	Gura_AssignMethod(wx_MediaCtrl, GetBestSize);
	Gura_AssignMethod(wx_MediaCtrl, GetPlaybackRate);
	Gura_AssignMethod(wx_MediaCtrl, GetState);
	Gura_AssignMethod(wx_MediaCtrl, GetVolume);
	Gura_AssignMethod(wx_MediaCtrl, Length);
	Gura_AssignMethod(wx_MediaCtrl, Load);
	Gura_AssignMethod(wx_MediaCtrl, Load_1);
	Gura_AssignMethod(wx_MediaCtrl, Load_2);
	Gura_AssignMethod(wx_MediaCtrl, LoadURI);
	Gura_AssignMethod(wx_MediaCtrl, LoadURIWithProxy);
	Gura_AssignMethod(wx_MediaCtrl, Pause);
	Gura_AssignMethod(wx_MediaCtrl, Play);
	Gura_AssignMethod(wx_MediaCtrl, Seek);
	Gura_AssignMethod(wx_MediaCtrl, SetPlaybackRate);
	Gura_AssignMethod(wx_MediaCtrl, SetVolume);
	Gura_AssignMethod(wx_MediaCtrl, ShowPlayerControls);
	Gura_AssignMethod(wx_MediaCtrl, Stop);
	Gura_AssignMethod(wx_MediaCtrl, Tell);
}

Gura_ImplementDescendantCreator(wx_MediaCtrl)
{
	return new Object_wx_MediaCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
