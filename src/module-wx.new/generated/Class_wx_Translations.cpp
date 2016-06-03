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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Translations, __Get)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Get();
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
	//int t = arg.GetNumber(0)
	//pThis->GetEntity()->Set();
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
	//int loader = arg.GetNumber(0)
	//pThis->GetEntity()->SetLoader();
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
	//int lang = arg.GetNumber(0)
	//pThis->GetEntity()->SetLanguage();
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
	//int lang = arg.GetNumber(0)
	//pThis->GetEntity()->SetLanguage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __GetAvailableTranslations, "GetAvailableTranslations")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __GetAvailableTranslations)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//pThis->GetEntity()->GetAvailableTranslations();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __GetBestTranslation, "GetBestTranslation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdLanguage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __GetBestTranslation)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//int msgIdLanguage = arg.GetNumber(1)
	//pThis->GetEntity()->GetBestTranslation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __GetBestTranslation_1, "GetBestTranslation_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdLanguage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __GetBestTranslation_1)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//int msgIdLanguage = arg.GetNumber(1)
	//pThis->GetEntity()->GetBestTranslation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __AddStdCatalog, "AddStdCatalog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Translations, __AddStdCatalog)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AddStdCatalog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __AddCatalog, "AddCatalog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __AddCatalog)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//pThis->GetEntity()->AddCatalog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __AddCatalog_1, "AddCatalog_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdLanguage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __AddCatalog_1)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//int msgIdLanguage = arg.GetNumber(1)
	//pThis->GetEntity()->AddCatalog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __AddCatalog_2, "AddCatalog_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdLanguage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msgIdCharset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __AddCatalog_2)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//int msgIdLanguage = arg.GetNumber(1)
	//int msgIdCharset = arg.GetNumber(2)
	//pThis->GetEntity()->AddCatalog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __IsLoaded, "IsLoaded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __IsLoaded)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//pThis->GetEntity()->IsLoaded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __GetTranslatedString, "GetTranslatedString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "origString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __GetTranslatedString)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int origString = arg.GetNumber(0)
	//int domain = arg.GetNumber(1)
	//pThis->GetEntity()->GetTranslatedString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __GetTranslatedString_1, "GetTranslatedString_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "origString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __GetTranslatedString_1)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int origString = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//int domain = arg.GetNumber(2)
	//pThis->GetEntity()->GetTranslatedString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Translations, __GetHeaderValue, "GetHeaderValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "header", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Translations, __GetHeaderValue)
{
	Object_wx_Translations *pThis = Object_wx_Translations::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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
