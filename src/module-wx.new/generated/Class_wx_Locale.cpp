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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Locale, wxLocale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, wxLocale)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxLocale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, wxLocale_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "language", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, wxLocale_1)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int language = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->wxLocale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, wxLocale_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "locale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bLoadDefault", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, wxLocale_2)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int shortName = arg.GetNumber(1)
	//int locale = arg.GetNumber(2)
	//int bLoadDefault = arg.GetNumber(3)
	//pThis->GetEntity()->wxLocale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, AddCatalog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, AddCatalog)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//pThis->GetEntity()->AddCatalog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, AddCatalog_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdLanguage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, AddCatalog_1)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//int msgIdLanguage = arg.GetNumber(1)
	//pThis->GetEntity()->AddCatalog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, AddCatalog_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdLanguage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdCharset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, AddCatalog_2)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//int msgIdLanguage = arg.GetNumber(1)
	//int msgIdCharset = arg.GetNumber(2)
	//pThis->GetEntity()->AddCatalog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, AddCatalogLookupPathPrefix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prefix", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, AddCatalogLookupPathPrefix)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int prefix = arg.GetNumber(0)
	//pThis->GetEntity()->AddCatalogLookupPathPrefix();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, AddLanguage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, AddLanguage)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int info = arg.GetNumber(0)
	//pThis->GetEntity()->AddLanguage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, FindLanguageInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "locale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, FindLanguageInfo)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int locale = arg.GetNumber(0)
	//pThis->GetEntity()->FindLanguageInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, GetCanonicalName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, GetCanonicalName)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCanonicalName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, GetHeaderValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "header", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, GetHeaderValue)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int header = arg.GetNumber(0)
	//int domain = arg.GetNumber(1)
	//pThis->GetEntity()->GetHeaderValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, GetLanguage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, GetLanguage)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLanguage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, GetLanguageInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, GetLanguageInfo)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lang = arg.GetNumber(0)
	//pThis->GetEntity()->GetLanguageInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, GetLanguageName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, GetLanguageName)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lang = arg.GetNumber(0)
	//pThis->GetEntity()->GetLanguageName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, GetLanguageCanonicalName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, GetLanguageCanonicalName)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lang = arg.GetNumber(0)
	//pThis->GetEntity()->GetLanguageCanonicalName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, GetLocale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, GetLocale)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLocale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, GetName)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "origString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, GetString)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int origString = arg.GetNumber(0)
	//int domain = arg.GetNumber(1)
	//pThis->GetEntity()->GetString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, GetString_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "origString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "origString2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, GetString_1)
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

Gura_DeclareMethod(wx_Locale, GetSysName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, GetSysName)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSysName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, GetSystemEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, GetSystemEncoding)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSystemEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, GetSystemEncodingName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, GetSystemEncodingName)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSystemEncodingName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, GetSystemLanguage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, GetSystemLanguage)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSystemLanguage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, GetInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, GetInfo)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int cat = arg.GetNumber(1)
	//pThis->GetEntity()->GetInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, GetOSInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, GetOSInfo)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int cat = arg.GetNumber(1)
	//pThis->GetEntity()->GetOSInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "language", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, Init)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int language = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, Init_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "locale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bLoadDefault", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, Init_1)
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

Gura_DeclareMethod(wx_Locale, IsAvailable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, IsAvailable)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lang = arg.GetNumber(0)
	//pThis->GetEntity()->IsAvailable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, IsLoaded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Locale, IsLoaded)
{
	Object_wx_Locale *pThis = Object_wx_Locale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//pThis->GetEntity()->IsLoaded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Locale, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Locale, IsOk)
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
	Gura_AssignMethod(wx_Locale, wxLocale);
	Gura_AssignMethod(wx_Locale, wxLocale_1);
	Gura_AssignMethod(wx_Locale, wxLocale_2);
	Gura_AssignMethod(wx_Locale, AddCatalog);
	Gura_AssignMethod(wx_Locale, AddCatalog_1);
	Gura_AssignMethod(wx_Locale, AddCatalog_2);
	Gura_AssignMethod(wx_Locale, AddCatalogLookupPathPrefix);
	Gura_AssignMethod(wx_Locale, AddLanguage);
	Gura_AssignMethod(wx_Locale, FindLanguageInfo);
	Gura_AssignMethod(wx_Locale, GetCanonicalName);
	Gura_AssignMethod(wx_Locale, GetHeaderValue);
	Gura_AssignMethod(wx_Locale, GetLanguage);
	Gura_AssignMethod(wx_Locale, GetLanguageInfo);
	Gura_AssignMethod(wx_Locale, GetLanguageName);
	Gura_AssignMethod(wx_Locale, GetLanguageCanonicalName);
	Gura_AssignMethod(wx_Locale, GetLocale);
	Gura_AssignMethod(wx_Locale, GetName);
	Gura_AssignMethod(wx_Locale, GetString);
	Gura_AssignMethod(wx_Locale, GetString_1);
	Gura_AssignMethod(wx_Locale, GetSysName);
	Gura_AssignMethod(wx_Locale, GetSystemEncoding);
	Gura_AssignMethod(wx_Locale, GetSystemEncodingName);
	Gura_AssignMethod(wx_Locale, GetSystemLanguage);
	Gura_AssignMethod(wx_Locale, GetInfo);
	Gura_AssignMethod(wx_Locale, GetOSInfo);
	Gura_AssignMethod(wx_Locale, Init);
	Gura_AssignMethod(wx_Locale, Init_1);
	Gura_AssignMethod(wx_Locale, IsAvailable);
	Gura_AssignMethod(wx_Locale, IsLoaded);
	Gura_AssignMethod(wx_Locale, IsOk);
}

Gura_ImplementDescendantCreator(wx_Locale)
{
	return new Object_wx_Locale((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
