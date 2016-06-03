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
Gura_DeclareFunctionAlias(__wxLocale, "wxLocale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Locale));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxLocale)
{
	//wxLocale();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxLocale_1, "wxLocale_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "language", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Locale));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxLocale_1)
{
	//int language = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//wxLocale();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxLocale_2, "wxLocale_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "locale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bLoadDefault", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Locale));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxLocale_2)
{
	//int name = arg.GetNumber(0)
	//int shortName = arg.GetNumber(1)
	//int locale = arg.GetNumber(2)
	//int bLoadDefault = arg.GetNumber(3)
	//wxLocale();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Locale, __AddCatalog, "AddCatalog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __AddCatalog)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//pThis->GetEntity()->AddCatalog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __AddCatalog_1, "AddCatalog_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdLanguage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __AddCatalog_1)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//int msgIdLanguage = arg.GetNumber(1)
	//pThis->GetEntity()->AddCatalog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __AddCatalog_2, "AddCatalog_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdLanguage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdCharset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __AddCatalog_2)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//int msgIdLanguage = arg.GetNumber(1)
	//int msgIdCharset = arg.GetNumber(2)
	//pThis->GetEntity()->AddCatalog();
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
	//int prefix = arg.GetNumber(0)
	//pThis->GetEntity()->AddCatalogLookupPathPrefix();
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
	//int info = arg.GetNumber(0)
	//pThis->GetEntity()->AddLanguage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __FindLanguageInfo, "FindLanguageInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "locale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __FindLanguageInfo)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int locale = arg.GetNumber(0)
	//pThis->GetEntity()->FindLanguageInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetCanonicalName, "GetCanonicalName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, __GetCanonicalName)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCanonicalName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetHeaderValue, "GetHeaderValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "header", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __GetHeaderValue)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int header = arg.GetNumber(0)
	//int domain = arg.GetNumber(1)
	//pThis->GetEntity()->GetHeaderValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetLanguage, "GetLanguage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, __GetLanguage)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLanguage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetLanguageInfo, "GetLanguageInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __GetLanguageInfo)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lang = arg.GetNumber(0)
	//pThis->GetEntity()->GetLanguageInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetLanguageName, "GetLanguageName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __GetLanguageName)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lang = arg.GetNumber(0)
	//pThis->GetEntity()->GetLanguageName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetLanguageCanonicalName, "GetLanguageCanonicalName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __GetLanguageCanonicalName)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lang = arg.GetNumber(0)
	//pThis->GetEntity()->GetLanguageCanonicalName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetLocale, "GetLocale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, __GetLocale)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLocale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, __GetName)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetString, "GetString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "origString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __GetString)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int origString = arg.GetNumber(0)
	//int domain = arg.GetNumber(1)
	//pThis->GetEntity()->GetString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetString_1, "GetString_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "origString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "origString2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __GetString_1)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int origString = arg.GetNumber(0)
	//int origString2 = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//int domain = arg.GetNumber(3)
	//pThis->GetEntity()->GetString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetSysName, "GetSysName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, __GetSysName)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSysName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetSystemEncoding, "GetSystemEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, __GetSystemEncoding)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSystemEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetSystemEncodingName, "GetSystemEncodingName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, __GetSystemEncodingName)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSystemEncodingName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetSystemLanguage, "GetSystemLanguage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, __GetSystemLanguage)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSystemLanguage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetInfo, "GetInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __GetInfo)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int cat = arg.GetNumber(1)
	//pThis->GetEntity()->GetInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __GetOSInfo, "GetOSInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __GetOSInfo)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int cat = arg.GetNumber(1)
	//pThis->GetEntity()->GetOSInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "language", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __Init)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int language = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __Init_1, "Init_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "locale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bLoadDefault", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __Init_1)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int shortName = arg.GetNumber(1)
	//int locale = arg.GetNumber(2)
	//int bLoadDefault = arg.GetNumber(3)
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __IsAvailable, "IsAvailable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __IsAvailable)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lang = arg.GetNumber(0)
	//pThis->GetEntity()->IsAvailable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __IsLoaded, "IsLoaded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, __IsLoaded)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//pThis->GetEntity()->IsLoaded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Locale, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, __IsOk)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLocale
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Locale)
{
	// Constructor assignment
	Gura_AssignFunction(__wxLocale);
	Gura_AssignFunction(__wxLocale_1);
	Gura_AssignFunction(__wxLocale_2);
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
