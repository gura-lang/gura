//----------------------------------------------------------------------------
// wxStandardPaths
// extracted from stdpaths.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StandardPaths: public wxStandardPaths, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_StandardPaths *_pObj;
public:
	~wx_StandardPaths();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_StandardPaths *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StandardPaths::~wx_StandardPaths()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_StandardPaths::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStandardPaths
//----------------------------------------------------------------------------
Gura_DeclareClassMethod(wx_StandardPaths, Get)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_StandardPaths, Get)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxStandardPathsBase &rtn = wxStandardPaths::Get();
	return ReturnValue(env, sig, args, Value(new Object_wx_StandardPathsBase(new wxStandardPathsBase(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_StandardPaths, GetConfigDir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetConfigDir)
{
	Object_wx_StandardPaths *pSelf = Object_wx_StandardPaths::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetConfigDir();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetDataDir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetDataDir)
{
	Object_wx_StandardPaths *pSelf = Object_wx_StandardPaths::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetDataDir();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetDocumentsDir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetDocumentsDir)
{
	Object_wx_StandardPaths *pSelf = Object_wx_StandardPaths::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetDocumentsDir();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetExecutablePath)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetExecutablePath)
{
	Object_wx_StandardPaths *pSelf = Object_wx_StandardPaths::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetExecutablePath();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetInstallPrefix)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetInstallPrefix)
{
#if 0
	Object_wx_StandardPaths *pSelf = Object_wx_StandardPaths::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetInstallPrefix();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_StandardPaths, GetLocalDataDir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetLocalDataDir)
{
	Object_wx_StandardPaths *pSelf = Object_wx_StandardPaths::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetLocalDataDir();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetLocalizedResourcesDir)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "lang", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetLocalizedResourcesDir)
{
#if 0
	Object_wx_StandardPaths *pSelf = Object_wx_StandardPaths::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString lang = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pSelf->GetEntity()->GetLocalizedResourcesDir(lang, );
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_StandardPaths, GetPluginsDir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetPluginsDir)
{
	Object_wx_StandardPaths *pSelf = Object_wx_StandardPaths::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetPluginsDir();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetResourcesDir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetResourcesDir)
{
	Object_wx_StandardPaths *pSelf = Object_wx_StandardPaths::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetResourcesDir();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetTempDir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetTempDir)
{
	Object_wx_StandardPaths *pSelf = Object_wx_StandardPaths::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetTempDir();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetUserConfigDir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetUserConfigDir)
{
	Object_wx_StandardPaths *pSelf = Object_wx_StandardPaths::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetUserConfigDir();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetUserDataDir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetUserDataDir)
{
	Object_wx_StandardPaths *pSelf = Object_wx_StandardPaths::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetUserDataDir();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, GetUserLocalDataDir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StandardPaths, GetUserLocalDataDir)
{
	Object_wx_StandardPaths *pSelf = Object_wx_StandardPaths::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetUserLocalDataDir();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StandardPaths, SetInstallPrefix)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "prefix", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_StandardPaths, SetInstallPrefix)
{
#if 0
	Object_wx_StandardPaths *pSelf = Object_wx_StandardPaths::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString prefix = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetInstallPrefix(prefix);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxStandardPaths
//----------------------------------------------------------------------------
Object_wx_StandardPaths::~Object_wx_StandardPaths()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_StandardPaths::Clone() const
{
	return NULL;
}

String Object_wx_StandardPaths::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.StandardPaths:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_StandardPaths::OnModuleEntry(Environment &env, Signal sig)
{
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
	return new Object_wx_StandardPaths((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
