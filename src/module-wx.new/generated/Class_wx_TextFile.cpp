//----------------------------------------------------------------------------
// wxTextFile
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextFile
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextFile
//----------------------------------------------------------------------------
Object_wx_TextFile::~Object_wx_TextFile()
{
}

Object *Object_wx_TextFile::Clone() const
{
	return nullptr;
}

String Object_wx_TextFile::ToString(bool exprFlag)
{
	String rtn("<wx.TextFile:");
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

//----------------------------------------------------------------------------
// Class implementation for wxTextFile
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextFile)
{
}

Gura_ImplementDescendantCreator(wx_TextFile)
{
	return new Object_wx_TextFile((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
