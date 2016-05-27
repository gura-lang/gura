//----------------------------------------------------------------------------
// wxColourDatabase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxColourDatabase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxColourDatabase
//----------------------------------------------------------------------------
Object_wx_ColourDatabase::~Object_wx_ColourDatabase()
{
}

Object *Object_wx_ColourDatabase::Clone() const
{
	return nullptr;
}

String Object_wx_ColourDatabase::ToString(bool exprFlag)
{
	String rtn("<wx.ColourDatabase:");
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
// Class implementation for wxColourDatabase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ColourDatabase)
{
}

Gura_ImplementDescendantCreator(wx_ColourDatabase)
{
	return new Object_wx_ColourDatabase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
