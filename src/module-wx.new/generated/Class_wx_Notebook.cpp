//----------------------------------------------------------------------------
// wxNotebook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxNotebook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNotebook
//----------------------------------------------------------------------------
Object_wx_Notebook::~Object_wx_Notebook()
{
}

Object *Object_wx_Notebook::Clone() const
{
	return nullptr;
}

String Object_wx_Notebook::ToString(bool exprFlag)
{
	String rtn("<wx.Notebook:");
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
// Class implementation for wxNotebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Notebook)
{
}

Gura_ImplementDescendantCreator(wx_Notebook)
{
	return new Object_wx_Notebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
