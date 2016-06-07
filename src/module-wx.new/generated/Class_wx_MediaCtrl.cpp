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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__MediaCtrl, "MediaCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MediaCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MediaCtrl)
{
	//wxMediaCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__MediaCtrl_1, "MediaCtrl_1")
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
	SetClassToConstruct(Gura_UserClass(wx_MediaCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MediaCtrl_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& fileName = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& szBackend = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//wxMediaCtrl(parent, id, fileName, pos, size, style, szBackend, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MediaCtrl, __Create, "Create")
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

Gura_ImplementMethod(wx_MediaCtrl, __Create)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& fileName = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& szBackend = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//pThis->GetEntity()->Create(parent, id, fileName, pos, size, style, szBackend, validator, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MediaCtrl, __GetBestSize, "GetBestSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, __GetBestSize)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBestSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MediaCtrl, __GetPlaybackRate, "GetPlaybackRate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, __GetPlaybackRate)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPlaybackRate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MediaCtrl, __GetState, "GetState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, __GetState)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MediaCtrl, __GetVolume, "GetVolume")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, __GetVolume)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVolume();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MediaCtrl, __Length, "Length")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, __Length)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Length();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MediaCtrl, __Load, "Load")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, __Load)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& fileName = arg.GetNumber(0)
	//pThis->GetEntity()->Load(fileName);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MediaCtrl, __Load_1, "Load_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "uri", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, __Load_1)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxURI& uri = arg.GetNumber(0)
	//pThis->GetEntity()->Load(uri);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MediaCtrl, __Load_2, "Load_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "uri", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proxy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, __Load_2)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxURI& uri = arg.GetNumber(0)
	//const wxURI& proxy = arg.GetNumber(1)
	//pThis->GetEntity()->Load(uri, proxy);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MediaCtrl, __LoadURI, "LoadURI")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, __LoadURI)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& fileName = arg.GetNumber(0)
	//pThis->GetEntity()->LoadURI(fileName);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MediaCtrl, __LoadURIWithProxy, "LoadURIWithProxy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proxy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, __LoadURIWithProxy)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& fileName = arg.GetNumber(0)
	//const wxString& proxy = arg.GetNumber(1)
	//pThis->GetEntity()->LoadURIWithProxy(fileName, proxy);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MediaCtrl, __Pause, "Pause")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, __Pause)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Pause();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MediaCtrl, __Play, "Play")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, __Play)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Play();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MediaCtrl, __Seek, "Seek")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "where", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, __Seek)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFileOffset where = arg.GetNumber(0)
	//wxSeekMode mode = arg.GetNumber(1)
	//pThis->GetEntity()->Seek(where, mode);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MediaCtrl, __SetPlaybackRate, "SetPlaybackRate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dRate", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, __SetPlaybackRate)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double dRate = arg.GetNumber(0)
	//pThis->GetEntity()->SetPlaybackRate(dRate);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MediaCtrl, __SetVolume, "SetVolume")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dVolume", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, __SetVolume)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double dVolume = arg.GetNumber(0)
	//pThis->GetEntity()->SetVolume(dVolume);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MediaCtrl, __ShowPlayerControls, "ShowPlayerControls")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MediaCtrl, __ShowPlayerControls)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMediaCtrlPlayerControls flags = arg.GetNumber(0)
	//pThis->GetEntity()->ShowPlayerControls(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MediaCtrl, __Stop, "Stop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, __Stop)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Stop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MediaCtrl, __Tell, "Tell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MediaCtrl, __Tell)
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
	// Constructor assignment
	Gura_AssignFunction(__MediaCtrl);
	Gura_AssignFunction(__MediaCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_MediaCtrl, __Create);
	Gura_AssignMethod(wx_MediaCtrl, __GetBestSize);
	Gura_AssignMethod(wx_MediaCtrl, __GetPlaybackRate);
	Gura_AssignMethod(wx_MediaCtrl, __GetState);
	Gura_AssignMethod(wx_MediaCtrl, __GetVolume);
	Gura_AssignMethod(wx_MediaCtrl, __Length);
	Gura_AssignMethod(wx_MediaCtrl, __Load);
	Gura_AssignMethod(wx_MediaCtrl, __Load_1);
	Gura_AssignMethod(wx_MediaCtrl, __Load_2);
	Gura_AssignMethod(wx_MediaCtrl, __LoadURI);
	Gura_AssignMethod(wx_MediaCtrl, __LoadURIWithProxy);
	Gura_AssignMethod(wx_MediaCtrl, __Pause);
	Gura_AssignMethod(wx_MediaCtrl, __Play);
	Gura_AssignMethod(wx_MediaCtrl, __Seek);
	Gura_AssignMethod(wx_MediaCtrl, __SetPlaybackRate);
	Gura_AssignMethod(wx_MediaCtrl, __SetVolume);
	Gura_AssignMethod(wx_MediaCtrl, __ShowPlayerControls);
	Gura_AssignMethod(wx_MediaCtrl, __Stop);
	Gura_AssignMethod(wx_MediaCtrl, __Tell);
}

Gura_ImplementDescendantCreator(wx_MediaCtrl)
{
	return new Object_wx_MediaCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
