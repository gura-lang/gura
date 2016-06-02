//----------------------------------------------------------------------------
// wxResourceTranslationsLoader
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxResourceTranslationsLoader
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxResourceTranslationsLoader
//----------------------------------------------------------------------------
Object_wx_ResourceTranslationsLoader::~Object_wx_ResourceTranslationsLoader()
{
}

Object *Object_wx_ResourceTranslationsLoader::Clone() const
{
	return nullptr;
}

String Object_wx_ResourceTranslationsLoader::ToString(bool exprFlag)
{
	String rtn("<wx.ResourceTranslationsLoader:");
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
Gura_DeclareMethod(wx_ResourceTranslationsLoader, GetResourceType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ResourceTranslationsLoader, GetResourceType)
{
	Object_wx_ResourceTranslationsLoader *pThis = Object_wx_ResourceTranslationsLoader::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetResourceType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ResourceTranslationsLoader, GetModule)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ResourceTranslationsLoader, GetModule)
{
	Object_wx_ResourceTranslationsLoader *pThis = Object_wx_ResourceTranslationsLoader::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetModule();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxResourceTranslationsLoader
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ResourceTranslationsLoader)
{
	Gura_AssignMethod(wx_ResourceTranslationsLoader, GetResourceType);
	Gura_AssignMethod(wx_ResourceTranslationsLoader, GetModule);
}

Gura_ImplementDescendantCreator(wx_ResourceTranslationsLoader)
{
	return new Object_wx_ResourceTranslationsLoader((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
