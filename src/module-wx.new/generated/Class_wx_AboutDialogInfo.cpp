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
// Method implementation
//----------------------------------------------------------------------------

Gura_DeclareMethod(wx_AboutDialogInfo, wxAboutDialogInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, wxAboutDialogInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAboutDialogInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, AddArtist)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, AddArtist)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->AddArtist();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, AddDeveloper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, AddDeveloper)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->AddDeveloper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, AddDocWriter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, AddDocWriter)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->AddDocWriter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, AddTranslator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, AddTranslator)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->AddTranslator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, HasDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, HasDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->HasDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, GetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, GetDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, HasCopyright)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, HasCopyright)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->HasCopyright();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, GetCopyright)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, GetCopyright)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetCopyright();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetArtists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetArtists)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetArtists();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetCopyright)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetCopyright)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetCopyright();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetDevelopers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetDevelopers)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetDevelopers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetDocWriters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetDocWriters)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetDocWriters();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetLicence)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetLicence)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetLicence();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetLicense)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetLicense)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetLicense();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetTranslators)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetTranslators)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetTranslators();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetVersion)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AboutDialogInfo, SetWebSite)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AboutDialogInfo, SetWebSite)
{
	Signal &sig = env.GetSignal();
	Object_wx_AboutDialogInfo *pThis = Object_wx_AboutDialogInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetWebSite();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAboutDialogInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AboutDialogInfo)
{
}

Gura_ImplementDescendantCreator(wx_AboutDialogInfo)
{
	return new Object_wx_AboutDialogInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
