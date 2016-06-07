//----------------------------------------------------------------------------
// wxAboutDialogInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAboutDialogInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAboutDialogInfo
//----------------------------------------------------------------------------
Object_wx_AboutDialogInfo::~Object_wx_AboutDialogInfo()
{
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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__AboutDialogInfo, "AboutDialogInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AboutDialogInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AboutDialogInfo)
{
	//wxAboutDialogInfo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AboutDialogInfo, __AddArtist, "AddArtist")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "artist", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __AddArtist)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& artist = arg.GetNumber(0)
	//pThis->GetEntity()->AddArtist(artist);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __AddDeveloper, "AddDeveloper")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __AddDeveloper)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& developer = arg.GetNumber(0)
	//pThis->GetEntity()->AddDeveloper(developer);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __AddDocWriter, "AddDocWriter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "docwriter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __AddDocWriter)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& docwriter = arg.GetNumber(0)
	//pThis->GetEntity()->AddDocWriter(docwriter);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __AddTranslator, "AddTranslator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "translator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __AddTranslator)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& translator = arg.GetNumber(0)
	//pThis->GetEntity()->AddTranslator(translator);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __GetName)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __HasDescription, "HasDescription")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __HasDescription)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasDescription();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __GetDescription, "GetDescription")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __GetDescription)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDescription();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __HasCopyright, "HasCopyright")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __HasCopyright)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasCopyright();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __GetCopyright, "GetCopyright")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __GetCopyright)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCopyright();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __SetArtists, "SetArtists")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "artists", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __SetArtists)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayString& artists = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtists(artists);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __SetCopyright, "SetCopyright")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "copyright", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __SetCopyright)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& copyright = arg.GetNumber(0)
	//pThis->GetEntity()->SetCopyright(copyright);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __SetDescription, "SetDescription")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __SetDescription)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& desc = arg.GetNumber(0)
	//pThis->GetEntity()->SetDescription(desc);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __SetDevelopers, "SetDevelopers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developers", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __SetDevelopers)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayString& developers = arg.GetNumber(0)
	//pThis->GetEntity()->SetDevelopers(developers);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __SetDocWriters, "SetDocWriters")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "docwriters", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __SetDocWriters)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayString& docwriters = arg.GetNumber(0)
	//pThis->GetEntity()->SetDocWriters(docwriters);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __SetIcon, "SetIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __SetIcon)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxIcon& icon = arg.GetNumber(0)
	//pThis->GetEntity()->SetIcon(icon);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __SetLicence, "SetLicence")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "licence", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __SetLicence)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& licence = arg.GetNumber(0)
	//pThis->GetEntity()->SetLicence(licence);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __SetLicense, "SetLicense")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "licence", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __SetLicense)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& licence = arg.GetNumber(0)
	//pThis->GetEntity()->SetLicense(licence);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __SetName, "SetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __SetName)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __SetTranslators, "SetTranslators")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "translators", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __SetTranslators)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayString& translators = arg.GetNumber(0)
	//pThis->GetEntity()->SetTranslators(translators);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __SetVersion, "SetVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "version", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "longVersion", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __SetVersion)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& version = arg.GetNumber(0)
	//const wxString& longVersion = arg.GetNumber(1)
	//pThis->GetEntity()->SetVersion(version, longVersion);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AboutDialogInfo, __SetWebSite, "SetWebSite")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, __SetWebSite)
{
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& url = arg.GetNumber(0)
	//const wxString& desc = arg.GetNumber(1)
	//pThis->GetEntity()->SetWebSite(url, desc);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAboutDialogInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AboutDialogInfo)
{
	// Constructor assignment
	Gura_AssignFunction(__AboutDialogInfo);
	// Method assignment
	Gura_AssignMethod(wx_AboutDialogInfo, __AddArtist);
	Gura_AssignMethod(wx_AboutDialogInfo, __AddDeveloper);
	Gura_AssignMethod(wx_AboutDialogInfo, __AddDocWriter);
	Gura_AssignMethod(wx_AboutDialogInfo, __AddTranslator);
	Gura_AssignMethod(wx_AboutDialogInfo, __GetName);
	Gura_AssignMethod(wx_AboutDialogInfo, __HasDescription);
	Gura_AssignMethod(wx_AboutDialogInfo, __GetDescription);
	Gura_AssignMethod(wx_AboutDialogInfo, __HasCopyright);
	Gura_AssignMethod(wx_AboutDialogInfo, __GetCopyright);
	Gura_AssignMethod(wx_AboutDialogInfo, __SetArtists);
	Gura_AssignMethod(wx_AboutDialogInfo, __SetCopyright);
	Gura_AssignMethod(wx_AboutDialogInfo, __SetDescription);
	Gura_AssignMethod(wx_AboutDialogInfo, __SetDevelopers);
	Gura_AssignMethod(wx_AboutDialogInfo, __SetDocWriters);
	Gura_AssignMethod(wx_AboutDialogInfo, __SetIcon);
	Gura_AssignMethod(wx_AboutDialogInfo, __SetLicence);
	Gura_AssignMethod(wx_AboutDialogInfo, __SetLicense);
	Gura_AssignMethod(wx_AboutDialogInfo, __SetName);
	Gura_AssignMethod(wx_AboutDialogInfo, __SetTranslators);
	Gura_AssignMethod(wx_AboutDialogInfo, __SetVersion);
	Gura_AssignMethod(wx_AboutDialogInfo, __SetWebSite);
}

Gura_ImplementDescendantCreator(wx_AboutDialogInfo)
{
	return new Object_wx_AboutDialogInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
