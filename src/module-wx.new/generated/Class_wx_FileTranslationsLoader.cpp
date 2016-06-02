//----------------------------------------------------------------------------
// wxFileTranslationsLoader
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileTranslationsLoader
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileTranslationsLoader
//----------------------------------------------------------------------------
Object_wx_FileTranslationsLoader::~Object_wx_FileTranslationsLoader()
{
}

Object *Object_wx_FileTranslationsLoader::Clone() const
{
	return nullptr;
}

String Object_wx_FileTranslationsLoader::ToString(bool exprFlag)
{
	String rtn("<wx.FileTranslationsLoader:");
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
Gura_DeclareMethod(wx_FileTranslationsLoader, AddCatalogLookupPathPrefix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prefix", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileTranslationsLoader, AddCatalogLookupPathPrefix)
{
	Object_wx_FileTranslationsLoader *pThis = Object_wx_FileTranslationsLoader::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int prefix = arg.GetNumber(0)
	//pThis->GetEntity()->AddCatalogLookupPathPrefix();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileTranslationsLoader
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileTranslationsLoader)
{
	Gura_AssignMethod(wx_FileTranslationsLoader, AddCatalogLookupPathPrefix);
}

Gura_ImplementDescendantCreator(wx_FileTranslationsLoader)
{
	return new Object_wx_FileTranslationsLoader((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
