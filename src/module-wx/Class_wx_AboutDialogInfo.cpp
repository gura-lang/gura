//----------------------------------------------------------------------------
// wxAboutDialogInfo
// extracted from aboutdlginfo.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AboutDialogInfo: public wxAboutDialogInfo, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_AboutDialogInfo *_pObj;
public:
	inline wx_AboutDialogInfo() : wxAboutDialogInfo(), _pObj(nullptr) {}
	~wx_AboutDialogInfo();
	inline void AssocWithGura(Object_wx_AboutDialogInfo *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AboutDialogInfo::~wx_AboutDialogInfo()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_AboutDialogInfo::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAboutDialogInfo
//----------------------------------------------------------------------------
Gura_DeclareFunction(AboutDialogInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AboutDialogInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AboutDialogInfo)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_AboutDialogInfo *pEntity = new wx_AboutDialogInfo();
	Object_wx_AboutDialogInfo *pObj = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_AboutDialogInfo(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_AboutDialogInfo, AddArtist)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "artist", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, AddArtist)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString artist = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->AddArtist(artist);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, AddDeveloper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, AddDeveloper)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->AddDeveloper(developer);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, AddDocWriter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "docwriter", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, AddDocWriter)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString docwriter = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->AddDocWriter(docwriter);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, AddTranslator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "translator", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, AddTranslator)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString translator = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->AddTranslator(translator);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetArtists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "artists", VTYPE_string, OCCUR_Once, FLAG_ListVar);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetArtists)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	std::unique_ptr<wxArrayString> artists(CreateArrayString(arg.GetList(0)));
	pThis->GetEntity()->SetArtists(*artists);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetCopyright)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "copyright", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetCopyright)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString copyright = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetCopyright(copyright);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "desc", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString desc = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetDescription(desc);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetDevelopers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "developers", VTYPE_string, OCCUR_Once, FLAG_ListVar);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetDevelopers)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	std::unique_ptr<wxArrayString> developers(CreateArrayString(arg.GetList(0)));
	pThis->GetEntity()->SetDevelopers(*developers);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetDocWriters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "docwriters", VTYPE_string, OCCUR_Once, FLAG_ListVar);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetDocWriters)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	std::unique_ptr<wxArrayString> docwriters(CreateArrayString(arg.GetList(0)));
	pThis->GetEntity()->SetDocWriters(*docwriters);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxIcon *icon = Object_wx_Icon::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetIcon(*icon);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetLicence)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "licence", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetLicence)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString licence = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetLicence(licence);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetLicense)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "licence", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetLicense)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString licence = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetLicense(licence);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetName(name);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetTranslators)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "translators", VTYPE_string, OCCUR_Once, FLAG_ListVar);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetTranslators)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	std::unique_ptr<wxArrayString> translators(CreateArrayString(arg.GetList(0)));
	pThis->GetEntity()->SetTranslators(*translators);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "version", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetVersion)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString version = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetVersion(version);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetWebSite)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "desc", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetWebSite)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString url = wxString::FromUTF8(arg.GetString(0));
	wxString desc = wxEmptyString;
	if (arg.IsValid(1)) desc = wxString::FromUTF8(arg.GetString(1));
	pThis->GetEntity()->SetWebSite(url, desc);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxAboutDialogInfo
//----------------------------------------------------------------------------
Object_wx_AboutDialogInfo::~Object_wx_AboutDialogInfo()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_AboutDialogInfo::Clone() const
{
	return nullptr;
}

String Object_wx_AboutDialogInfo::ToString(bool exprFlag)
{
	String rtn("<wx.AboutDialogInfo:");
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
// Class implementation for wxAboutDialogInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AboutDialogInfo)
{
	Gura_AssignFunction(AboutDialogInfo);
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
	return new Object_wx_AboutDialogInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
