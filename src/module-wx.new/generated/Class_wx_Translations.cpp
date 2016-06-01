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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Translations, wxTranslations)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Translations, wxTranslations)
{
	Signal &sig = env.GetSignal();
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxTranslations();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Translations, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Translations, Get)
{
	Signal &sig = env.GetSignal();
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Translations, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int t = arg.GetNumber(0)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Translations, SetLoader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "loader", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, SetLoader)
{
	Signal &sig = env.GetSignal();
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int loader = arg.GetNumber(0)
	//pThis->GetEntity()->SetLoader();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Translations, SetLanguage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, SetLanguage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int lang = arg.GetNumber(0)
	//pThis->GetEntity()->SetLanguage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Translations, SetLanguage_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, SetLanguage_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int lang = arg.GetNumber(0)
	//pThis->GetEntity()->SetLanguage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Translations, GetAvailableTranslations)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, GetAvailableTranslations)
{
	Signal &sig = env.GetSignal();
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//pThis->GetEntity()->GetAvailableTranslations();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Translations, GetBestTranslation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdLanguage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, GetBestTranslation)
{
	Signal &sig = env.GetSignal();
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//int msgIdLanguage = arg.GetNumber(1)
	//pThis->GetEntity()->GetBestTranslation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Translations, GetBestTranslation_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdLanguage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, GetBestTranslation_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//int msgIdLanguage = arg.GetNumber(1)
	//pThis->GetEntity()->GetBestTranslation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Translations, AddStdCatalog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Translations, AddStdCatalog)
{
	Signal &sig = env.GetSignal();
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AddStdCatalog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Translations, AddCatalog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, AddCatalog)
{
	Signal &sig = env.GetSignal();
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//pThis->GetEntity()->AddCatalog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Translations, AddCatalog_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdLanguage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, AddCatalog_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//int msgIdLanguage = arg.GetNumber(1)
	//pThis->GetEntity()->AddCatalog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Translations, AddCatalog_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdLanguage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdCharset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, AddCatalog_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//int msgIdLanguage = arg.GetNumber(1)
	//int msgIdCharset = arg.GetNumber(2)
	//pThis->GetEntity()->AddCatalog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Translations, IsLoaded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, IsLoaded)
{
	Signal &sig = env.GetSignal();
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//pThis->GetEntity()->IsLoaded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Translations, GetTranslatedString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "origString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, GetTranslatedString)
{
	Signal &sig = env.GetSignal();
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int origString = arg.GetNumber(0)
	//int domain = arg.GetNumber(1)
	//pThis->GetEntity()->GetTranslatedString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Translations, GetTranslatedString_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "origString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, GetTranslatedString_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int origString = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//int domain = arg.GetNumber(2)
	//pThis->GetEntity()->GetTranslatedString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Translations, GetHeaderValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "header", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, GetHeaderValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int header = arg.GetNumber(0)
	//int domain = arg.GetNumber(1)
	//pThis->GetEntity()->GetHeaderValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTranslations
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Translations)
{
	Gura_AssignMethod(wx_Translations, wxTranslations);
	Gura_AssignMethod(wx_Translations, Get);
	Gura_AssignMethod(wx_Translations, Set);
	Gura_AssignMethod(wx_Translations, SetLoader);
	Gura_AssignMethod(wx_Translations, SetLanguage);
	Gura_AssignMethod(wx_Translations, SetLanguage_1);
	Gura_AssignMethod(wx_Translations, GetAvailableTranslations);
	Gura_AssignMethod(wx_Translations, GetBestTranslation);
	Gura_AssignMethod(wx_Translations, GetBestTranslation_1);
	Gura_AssignMethod(wx_Translations, AddStdCatalog);
	Gura_AssignMethod(wx_Translations, AddCatalog);
	Gura_AssignMethod(wx_Translations, AddCatalog_1);
	Gura_AssignMethod(wx_Translations, AddCatalog_2);
	Gura_AssignMethod(wx_Translations, IsLoaded);
	Gura_AssignMethod(wx_Translations, GetTranslatedString);
	Gura_AssignMethod(wx_Translations, GetTranslatedString_1);
	Gura_AssignMethod(wx_Translations, GetHeaderValue);
}

Gura_ImplementDescendantCreator(wx_Translations)
{
	return new Object_wx_Translations((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
