//----------------------------------------------------------------------------
// wxTranslationsLoader
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTranslationsLoader
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTranslationsLoader
//----------------------------------------------------------------------------
Object_wx_TranslationsLoader::~Object_wx_TranslationsLoader()
{
}

Object *Object_wx_TranslationsLoader::Clone() const
{
	return nullptr;
}

String Object_wx_TranslationsLoader::ToString(bool exprFlag)
{
	String rtn("<wx.TranslationsLoader:");
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
Gura_DeclareMethodAlias(wx_TranslationsLoader, __wxTranslationsLoader, "wxTranslationsLoader")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TranslationsLoader, __wxTranslationsLoader)
{
	Object_wx_TranslationsLoader *pThis = Object_wx_TranslationsLoader::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxTranslationsLoader();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TranslationsLoader, __LoadCatalog, "LoadCatalog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TranslationsLoader, __LoadCatalog)
{
	Object_wx_TranslationsLoader *pThis = Object_wx_TranslationsLoader::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//int lang = arg.GetNumber(1)
	//pThis->GetEntity()->LoadCatalog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TranslationsLoader, __GetAvailableTranslations, "GetAvailableTranslations")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TranslationsLoader, __GetAvailableTranslations)
{
	Object_wx_TranslationsLoader *pThis = Object_wx_TranslationsLoader::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//pThis->GetEntity()->GetAvailableTranslations();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTranslationsLoader
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TranslationsLoader)
{
	Gura_AssignMethod(wx_TranslationsLoader, __wxTranslationsLoader);
	Gura_AssignMethod(wx_TranslationsLoader, __LoadCatalog);
	Gura_AssignMethod(wx_TranslationsLoader, __GetAvailableTranslations);
}

Gura_ImplementDescendantCreator(wx_TranslationsLoader)
{
	return new Object_wx_TranslationsLoader((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
