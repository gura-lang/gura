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
// Class implementation for wxFileTranslationsLoader
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileTranslationsLoader)
{
}

Gura_ImplementDescendantCreator(wx_FileTranslationsLoader)
{
	return new Object_wx_FileTranslationsLoader((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
