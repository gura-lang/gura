//----------------------------------------------------------------------------
// wxStandardPaths
// extracted from stdpaths.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StandardPaths: public wxStandardPaths, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_StandardPaths *_pObj;
public:
	~wx_StandardPaths();
	inline void AssocWithGura(Object_wx_StandardPaths *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StandardPaths::~wx_StandardPaths()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_StandardPaths::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStandardPaths
//----------------------------------------------------------------------------
Gura_DeclareClassMethod(wx_StandardPaths, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_StandardPaths, Get)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxStandardPathsBase &rtn = wxStandardPaths::Get();
	return ReturnValue(env, arg, Value(new Object_wx_StandardPathsBase(new wxStandardPathsBase(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_StandardPaths, GetConfigDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetConfigDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_StandardPaths *pThis = Object_wx_StandardPaths::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetConfigDir();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetDataDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetDataDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_StandardPaths *pThis = Object_wx_StandardPaths::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetDataDir();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetDocumentsDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetDocumentsDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_StandardPaths *pThis = Object_wx_StandardPaths::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetDocumentsDir();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetExecutablePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetExecutablePath)
{
	Signal &sig = env.GetSignal();
	Object_wx_StandardPaths *pThis = Object_wx_StandardPaths::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetExecutablePath();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetInstallPrefix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetInstallPrefix)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_StandardPaths *pThis = Object_wx_StandardPaths::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetInstallPrefix();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_StandardPaths, GetLocalDataDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetLocalDataDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_StandardPaths *pThis = Object_wx_StandardPaths::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetLocalDataDir();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetLocalizedResourcesDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "lang", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetLocalizedResourcesDir)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_StandardPaths *pThis = Object_wx_StandardPaths::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString lang = wxString::FromUTF8(arg.GetString(0));
	wxString rtn = pThis->GetEntity()->GetLocalizedResourcesDir(lang, );
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_StandardPaths, GetPluginsDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetPluginsDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_StandardPaths *pThis = Object_wx_StandardPaths::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetPluginsDir();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetResourcesDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetResourcesDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_StandardPaths *pThis = Object_wx_StandardPaths::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetResourcesDir();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetTempDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetTempDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_StandardPaths *pThis = Object_wx_StandardPaths::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetTempDir();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetUserConfigDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetUserConfigDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_StandardPaths *pThis = Object_wx_StandardPaths::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetUserConfigDir();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetUserDataDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetUserDataDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_StandardPaths *pThis = Object_wx_StandardPaths::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetUserDataDir();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetUserLocalDataDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetUserLocalDataDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_StandardPaths *pThis = Object_wx_StandardPaths::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetUserLocalDataDir();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, SetInstallPrefix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "prefix", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_StandardPaths, SetInstallPrefix)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_StandardPaths *pThis = Object_wx_StandardPaths::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString prefix = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetInstallPrefix(prefix);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxStandardPaths
//----------------------------------------------------------------------------
Object_wx_StandardPaths::~Object_wx_StandardPaths()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_StandardPaths::Clone() const
{
	return nullptr;
}

String Object_wx_StandardPaths::ToString(bool exprFlag)
{
	String rtn("<wx.StandardPaths:");
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
// Class implementation for wxStandardPaths
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StandardPaths)
{
	Gura_AssignMethod(wx_StandardPaths, Get);
	Gura_AssignMethod(wx_StandardPaths, GetConfigDir);
	Gura_AssignMethod(wx_StandardPaths, GetDataDir);
	Gura_AssignMethod(wx_StandardPaths, GetDocumentsDir);
	Gura_AssignMethod(wx_StandardPaths, GetExecutablePath);
	Gura_AssignMethod(wx_StandardPaths, GetInstallPrefix);
	Gura_AssignMethod(wx_StandardPaths, GetLocalDataDir);
	Gura_AssignMethod(wx_StandardPaths, GetLocalizedResourcesDir);
	Gura_AssignMethod(wx_StandardPaths, GetPluginsDir);
	Gura_AssignMethod(wx_StandardPaths, GetResourcesDir);
	Gura_AssignMethod(wx_StandardPaths, GetTempDir);
	Gura_AssignMethod(wx_StandardPaths, GetUserConfigDir);
	Gura_AssignMethod(wx_StandardPaths, GetUserDataDir);
	Gura_AssignMethod(wx_StandardPaths, GetUserLocalDataDir);
	Gura_AssignMethod(wx_StandardPaths, SetInstallPrefix);
}

Gura_ImplementDescendantCreator(wx_StandardPaths)
{
	return new Object_wx_StandardPaths((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
