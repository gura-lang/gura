//----------------------------------------------------------------------------
// wxAboutDialogInfo
// extracted from aboutdlginfo.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AboutDialogInfo: public wxAboutDialogInfo, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_AboutDialogInfo *_pObj;
public:
	inline wx_AboutDialogInfo() : wxAboutDialogInfo(), _sig(NULL), _pObj(NULL) {}
	~wx_AboutDialogInfo();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_AboutDialogInfo *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AboutDialogInfo::~wx_AboutDialogInfo()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_AboutDialogInfo::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAboutDialogInfo
//----------------------------------------------------------------------------
Gura_DeclareFunction(AboutDialogInfoEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AboutDialogInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AboutDialogInfoEmpty)
{
	wx_AboutDialogInfo *pEntity = new wx_AboutDialogInfo();
	Object_wx_AboutDialogInfo *pObj = Object_wx_AboutDialogInfo::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_AboutDialogInfo(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_AboutDialogInfo, AddArtist)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "artist", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, AddArtist)
{
	Object_wx_AboutDialogInfo *pSelf = Object_wx_AboutDialogInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString artist = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->AddArtist(artist);
	return Value::Null;
}

Gura_DeclareMethod(wx_AboutDialogInfo, AddDeveloper)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, AddDeveloper)
{
	Object_wx_AboutDialogInfo *pSelf = Object_wx_AboutDialogInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString developer = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->AddDeveloper(developer);
	return Value::Null;
}

Gura_DeclareMethod(wx_AboutDialogInfo, AddDocWriter)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "docwriter", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, AddDocWriter)
{
	Object_wx_AboutDialogInfo *pSelf = Object_wx_AboutDialogInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString docwriter = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->AddDocWriter(docwriter);
	return Value::Null;
}

Gura_DeclareMethod(wx_AboutDialogInfo, AddTranslator)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "translator", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, AddTranslator)
{
	Object_wx_AboutDialogInfo *pSelf = Object_wx_AboutDialogInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString translator = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->AddTranslator(translator);
	return Value::Null;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetArtists)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "artists", VTYPE_string, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetArtists)
{
	Object_wx_AboutDialogInfo *pSelf = Object_wx_AboutDialogInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	std::auto_ptr<wxArrayString> artists(CreateArrayString(args.GetList(0)));
	pSelf->GetEntity()->SetArtists(*artists);
	return Value::Null;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetCopyright)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "copyright", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetCopyright)
{
	Object_wx_AboutDialogInfo *pSelf = Object_wx_AboutDialogInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString copyright = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetCopyright(copyright);
	return Value::Null;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetDescription)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "desc", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetDescription)
{
	Object_wx_AboutDialogInfo *pSelf = Object_wx_AboutDialogInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString desc = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetDescription(desc);
	return Value::Null;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetDevelopers)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "developers", VTYPE_string, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetDevelopers)
{
	Object_wx_AboutDialogInfo *pSelf = Object_wx_AboutDialogInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	std::auto_ptr<wxArrayString> developers(CreateArrayString(args.GetList(0)));
	pSelf->GetEntity()->SetDevelopers(*developers);
	return Value::Null;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetDocWriters)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "docwriters", VTYPE_string, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetDocWriters)
{
	Object_wx_AboutDialogInfo *pSelf = Object_wx_AboutDialogInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	std::auto_ptr<wxArrayString> docwriters(CreateArrayString(args.GetList(0)));
	pSelf->GetEntity()->SetDocWriters(*docwriters);
	return Value::Null;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetIcon)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetIcon)
{
	Object_wx_AboutDialogInfo *pSelf = Object_wx_AboutDialogInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxIcon *icon = Object_wx_Icon::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetIcon(*icon);
	return Value::Null;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetLicence)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "licence", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetLicence)
{
	Object_wx_AboutDialogInfo *pSelf = Object_wx_AboutDialogInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString licence = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetLicence(licence);
	return Value::Null;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetLicense)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "licence", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetLicense)
{
	Object_wx_AboutDialogInfo *pSelf = Object_wx_AboutDialogInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString licence = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetLicense(licence);
	return Value::Null;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetName)
{
	Object_wx_AboutDialogInfo *pSelf = Object_wx_AboutDialogInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetTranslators)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "translators", VTYPE_string, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetTranslators)
{
	Object_wx_AboutDialogInfo *pSelf = Object_wx_AboutDialogInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	std::auto_ptr<wxArrayString> translators(CreateArrayString(args.GetList(0)));
	pSelf->GetEntity()->SetTranslators(*translators);
	return Value::Null;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetVersion)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "version", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetVersion)
{
	Object_wx_AboutDialogInfo *pSelf = Object_wx_AboutDialogInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString version = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetVersion(version);
	return Value::Null;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetWebSite)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "desc", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetWebSite)
{
	Object_wx_AboutDialogInfo *pSelf = Object_wx_AboutDialogInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString url = wxString::FromUTF8(args.GetString(0));
	wxString desc = wxEmptyString;
	if (args.IsValid(1)) desc = wxString::FromUTF8(args.GetString(1));
	pSelf->GetEntity()->SetWebSite(url, desc);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxAboutDialogInfo
//----------------------------------------------------------------------------
Object_wx_AboutDialogInfo::~Object_wx_AboutDialogInfo()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_AboutDialogInfo::Clone() const
{
	return NULL;
}

String Object_wx_AboutDialogInfo::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.AboutDialogInfo:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_AboutDialogInfo::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(AboutDialogInfoEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxAboutDialogInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AboutDialogInfo)
{
	Gura_AssignMethod(wx_AboutDialogInfo, AddArtist);
	Gura_AssignMethod(wx_AboutDialogInfo, AddDeveloper);
	Gura_AssignMethod(wx_AboutDialogInfo, AddDocWriter);
	Gura_AssignMethod(wx_AboutDialogInfo, AddTranslator);
	Gura_AssignMethod(wx_AboutDialogInfo, SetArtists);
	Gura_AssignMethod(wx_AboutDialogInfo, SetCopyright);
	Gura_AssignMethod(wx_AboutDialogInfo, SetDescription);
	Gura_AssignMethod(wx_AboutDialogInfo, SetDevelopers);
	Gura_AssignMethod(wx_AboutDialogInfo, SetDocWriters);
	Gura_AssignMethod(wx_AboutDialogInfo, SetIcon);
	Gura_AssignMethod(wx_AboutDialogInfo, SetLicence);
	Gura_AssignMethod(wx_AboutDialogInfo, SetLicense);
	Gura_AssignMethod(wx_AboutDialogInfo, SetName);
	Gura_AssignMethod(wx_AboutDialogInfo, SetTranslators);
	Gura_AssignMethod(wx_AboutDialogInfo, SetVersion);
	Gura_AssignMethod(wx_AboutDialogInfo, SetWebSite);
}

Gura_ImplementDescendantCreator(wx_AboutDialogInfo)
{
	return new Object_wx_AboutDialogInfo((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
