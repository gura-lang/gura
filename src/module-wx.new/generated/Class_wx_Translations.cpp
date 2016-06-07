//----------------------------------------------------------------------------
// wxTranslations
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTranslations
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTranslations
//----------------------------------------------------------------------------
Object_wx_Translations::~Object_wx_Translations()
{
}

Object *Object_wx_Translations::Clone() const
{
	return nullptr;
}

String Object_wx_Translations::ToString(bool exprFlag)
{
	String rtn("<wx.Translations:");
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
Gura_DeclareFunctionAlias(__Translations, "Translations")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Translations));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Translations)
{
	//wxTranslations();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Translations, __Get, "Get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Translations, __Get)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTranslations* _rtn = pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __Set)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTranslations* t = arg.GetNumber(0)
	//pThis->GetEntity()->Set(t);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __SetLoader, "SetLoader")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "loader", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __SetLoader)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTranslationsLoader* loader = arg.GetNumber(0)
	//pThis->GetEntity()->SetLoader(loader);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __SetLanguage, "SetLanguage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __SetLanguage)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxLanguage lang = arg.GetNumber(0)
	//pThis->GetEntity()->SetLanguage(lang);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __SetLanguage_1, "SetLanguage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __SetLanguage_1)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& lang = arg.GetNumber(0)
	//pThis->GetEntity()->SetLanguage(lang);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __GetAvailableTranslations, "GetAvailableTranslations")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __GetAvailableTranslations)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& domain = arg.GetNumber(0)
	//wxArrayString _rtn = pThis->GetEntity()->GetAvailableTranslations(domain);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __GetBestTranslation, "GetBestTranslation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdLanguage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __GetBestTranslation)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& domain = arg.GetNumber(0)
	//wxLanguage msgIdLanguage = arg.GetNumber(1)
	//wxString _rtn = pThis->GetEntity()->GetBestTranslation(domain, msgIdLanguage);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __GetBestTranslation_1, "GetBestTranslation_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdLanguage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __GetBestTranslation_1)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& domain = arg.GetNumber(0)
	//const wxString& msgIdLanguage = arg.GetNumber(1)
	//wxString _rtn = pThis->GetEntity()->GetBestTranslation(domain, msgIdLanguage);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __AddStdCatalog, "AddStdCatalog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Translations, __AddStdCatalog)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->AddStdCatalog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __AddCatalog, "AddCatalog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __AddCatalog)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& domain = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->AddCatalog(domain);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __AddCatalog_1, "AddCatalog_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdLanguage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __AddCatalog_1)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& domain = arg.GetNumber(0)
	//wxLanguage msgIdLanguage = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->AddCatalog(domain, msgIdLanguage);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __AddCatalog_2, "AddCatalog_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdLanguage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdCharset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __AddCatalog_2)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& domain = arg.GetNumber(0)
	//wxLanguage msgIdLanguage = arg.GetNumber(1)
	//const wxString& msgIdCharset = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->AddCatalog(domain, msgIdLanguage, msgIdCharset);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __IsLoaded, "IsLoaded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __IsLoaded)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& domain = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsLoaded(domain);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __GetTranslatedString, "GetTranslatedString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "origString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __GetTranslatedString)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& origString = arg.GetNumber(0)
	//const wxString& domain = arg.GetNumber(1)
	//const wxString* _rtn = pThis->GetEntity()->GetTranslatedString(origString, domain);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __GetTranslatedString_1, "GetTranslatedString_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "origString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __GetTranslatedString_1)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& origString = arg.GetNumber(0)
	//unsigned n = arg.GetNumber(1)
	//const wxString& domain = arg.GetNumber(2)
	//const wxString* _rtn = pThis->GetEntity()->GetTranslatedString(origString, n, domain);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __GetHeaderValue, "GetHeaderValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "header", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __GetHeaderValue)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& header = arg.GetNumber(0)
	//const wxString& domain = arg.GetNumber(1)
	//wxString _rtn = pThis->GetEntity()->GetHeaderValue(header, domain);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTranslations
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Translations)
{
	// Constructor assignment
	Gura_AssignFunction(__Translations);
	// Method assignment
	Gura_AssignMethod(wx_Translations, __Get);
	Gura_AssignMethod(wx_Translations, __Set);
	Gura_AssignMethod(wx_Translations, __SetLoader);
	Gura_AssignMethod(wx_Translations, __SetLanguage);
	Gura_AssignMethod(wx_Translations, __SetLanguage_1);
	Gura_AssignMethod(wx_Translations, __GetAvailableTranslations);
	Gura_AssignMethod(wx_Translations, __GetBestTranslation);
	Gura_AssignMethod(wx_Translations, __GetBestTranslation_1);
	Gura_AssignMethod(wx_Translations, __AddStdCatalog);
	Gura_AssignMethod(wx_Translations, __AddCatalog);
	Gura_AssignMethod(wx_Translations, __AddCatalog_1);
	Gura_AssignMethod(wx_Translations, __AddCatalog_2);
	Gura_AssignMethod(wx_Translations, __IsLoaded);
	Gura_AssignMethod(wx_Translations, __GetTranslatedString);
	Gura_AssignMethod(wx_Translations, __GetTranslatedString_1);
	Gura_AssignMethod(wx_Translations, __GetHeaderValue);
}

Gura_ImplementDescendantCreator(wx_Translations)
{
	return new Object_wx_Translations((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
