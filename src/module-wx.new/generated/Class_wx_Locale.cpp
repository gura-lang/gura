//----------------------------------------------------------------------------
// wxLocale
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLocale
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLocale
//----------------------------------------------------------------------------
Object_wx_Locale::~Object_wx_Locale()
{
}

Object *Object_wx_Locale::Clone() const
{
	return nullptr;
}

String Object_wx_Locale::ToString(bool exprFlag)
{
	String rtn("<wx.Locale:");
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
Gura_DeclareFunctionAlias(__Locale, "Locale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Locale));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Locale)
{
	//wxLocale();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Locale_1, "Locale_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "language", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Locale));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Locale_1)
{
	//int language = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//wxLocale(language, flags);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Locale_2, "Locale_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "locale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bLoadDefault", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Locale));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Locale_2)
{
	//const wxString& name = arg.GetNumber(0)
	//const wxString& shortName = arg.GetNumber(1)
	//const wxString& locale = arg.GetNumber(2)
	//bool bLoadDefault = arg.GetNumber(3)
	//wxLocale(name, shortName, locale, bLoadDefault);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Locale, __AddCatalog, "AddCatalog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __AddCatalog)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& domain = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->AddCatalog(domain);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __AddCatalog_1, "AddCatalog_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdLanguage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __AddCatalog_1)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& domain = arg.GetNumber(0)
	//wxLanguage msgIdLanguage = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->AddCatalog(domain, msgIdLanguage);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __AddCatalog_2, "AddCatalog_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdLanguage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdCharset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __AddCatalog_2)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& domain = arg.GetNumber(0)
	//wxLanguage msgIdLanguage = arg.GetNumber(1)
	//const wxString& msgIdCharset = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->AddCatalog(domain, msgIdLanguage, msgIdCharset);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __AddCatalogLookupPathPrefix, "AddCatalogLookupPathPrefix")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prefix", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __AddCatalogLookupPathPrefix)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& prefix = arg.GetNumber(0)
	//pThis->GetEntity()->AddCatalogLookupPathPrefix(prefix);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __AddLanguage, "AddLanguage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __AddLanguage)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxLanguageInfo& info = arg.GetNumber(0)
	//pThis->GetEntity()->AddLanguage(info);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __FindLanguageInfo, "FindLanguageInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "locale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __FindLanguageInfo)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& locale = arg.GetNumber(0)
	//const wxLanguageInfo* _rtn = pThis->GetEntity()->FindLanguageInfo(locale);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetCanonicalName, "GetCanonicalName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, __GetCanonicalName)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetCanonicalName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetHeaderValue, "GetHeaderValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "header", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __GetHeaderValue)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& header = arg.GetNumber(0)
	//const wxString& domain = arg.GetNumber(1)
	//wxString _rtn = pThis->GetEntity()->GetHeaderValue(header, domain);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetLanguage, "GetLanguage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, __GetLanguage)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetLanguage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetLanguageInfo, "GetLanguageInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __GetLanguageInfo)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lang = arg.GetNumber(0)
	//const wxLanguageInfo* _rtn = pThis->GetEntity()->GetLanguageInfo(lang);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetLanguageName, "GetLanguageName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __GetLanguageName)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lang = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetLanguageName(lang);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetLanguageCanonicalName, "GetLanguageCanonicalName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __GetLanguageCanonicalName)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lang = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetLanguageCanonicalName(lang);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetLocale, "GetLocale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, __GetLocale)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetLocale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, __GetName)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetString, "GetString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "origString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __GetString)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& origString = arg.GetNumber(0)
	//const wxString& domain = arg.GetNumber(1)
	//const wxString& _rtn = pThis->GetEntity()->GetString(origString, domain);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetString_1, "GetString_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "origString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "origString2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __GetString_1)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& origString = arg.GetNumber(0)
	//const wxString& origString2 = arg.GetNumber(1)
	//unsigned n = arg.GetNumber(2)
	//const wxString& domain = arg.GetNumber(3)
	//const wxString& _rtn = pThis->GetEntity()->GetString(origString, origString2, n, domain);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetSysName, "GetSysName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, __GetSysName)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetSysName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetSystemEncoding, "GetSystemEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, __GetSystemEncoding)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding _rtn = pThis->GetEntity()->GetSystemEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetSystemEncodingName, "GetSystemEncodingName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, __GetSystemEncodingName)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetSystemEncodingName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetSystemLanguage, "GetSystemLanguage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, __GetSystemLanguage)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetSystemLanguage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetInfo, "GetInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __GetInfo)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxLocaleInfo index = arg.GetNumber(0)
	//wxLocaleCategory cat = arg.GetNumber(1)
	//wxString _rtn = pThis->GetEntity()->GetInfo(index, cat);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetOSInfo, "GetOSInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __GetOSInfo)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxLocaleInfo index = arg.GetNumber(0)
	//wxLocaleCategory cat = arg.GetNumber(1)
	//wxString _rtn = pThis->GetEntity()->GetOSInfo(index, cat);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "language", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __Init)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int language = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Init(language, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __Init_1, "Init_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "locale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bLoadDefault", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __Init_1)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//const wxString& shortName = arg.GetNumber(1)
	//const wxString& locale = arg.GetNumber(2)
	//bool bLoadDefault = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->Init(name, shortName, locale, bLoadDefault);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __IsAvailable, "IsAvailable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __IsAvailable)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lang = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsAvailable(lang);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __IsLoaded, "IsLoaded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __IsLoaded)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& domain = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsLoaded(domain);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, __IsOk)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLocale
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Locale)
{
	// Constructor assignment
	Gura_AssignFunction(__Locale);
	Gura_AssignFunction(__Locale_1);
	Gura_AssignFunction(__Locale_2);
	// Method assignment
	Gura_AssignMethod(wx_Locale, __AddCatalog);
	Gura_AssignMethod(wx_Locale, __AddCatalog_1);
	Gura_AssignMethod(wx_Locale, __AddCatalog_2);
	Gura_AssignMethod(wx_Locale, __AddCatalogLookupPathPrefix);
	Gura_AssignMethod(wx_Locale, __AddLanguage);
	Gura_AssignMethod(wx_Locale, __FindLanguageInfo);
	Gura_AssignMethod(wx_Locale, __GetCanonicalName);
	Gura_AssignMethod(wx_Locale, __GetHeaderValue);
	Gura_AssignMethod(wx_Locale, __GetLanguage);
	Gura_AssignMethod(wx_Locale, __GetLanguageInfo);
	Gura_AssignMethod(wx_Locale, __GetLanguageName);
	Gura_AssignMethod(wx_Locale, __GetLanguageCanonicalName);
	Gura_AssignMethod(wx_Locale, __GetLocale);
	Gura_AssignMethod(wx_Locale, __GetName);
	Gura_AssignMethod(wx_Locale, __GetString);
	Gura_AssignMethod(wx_Locale, __GetString_1);
	Gura_AssignMethod(wx_Locale, __GetSysName);
	Gura_AssignMethod(wx_Locale, __GetSystemEncoding);
	Gura_AssignMethod(wx_Locale, __GetSystemEncodingName);
	Gura_AssignMethod(wx_Locale, __GetSystemLanguage);
	Gura_AssignMethod(wx_Locale, __GetInfo);
	Gura_AssignMethod(wx_Locale, __GetOSInfo);
	Gura_AssignMethod(wx_Locale, __Init);
	Gura_AssignMethod(wx_Locale, __Init_1);
	Gura_AssignMethod(wx_Locale, __IsAvailable);
	Gura_AssignMethod(wx_Locale, __IsLoaded);
	Gura_AssignMethod(wx_Locale, __IsOk);
}

Gura_ImplementDescendantCreator(wx_Locale)
{
	return new Object_wx_Locale((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
