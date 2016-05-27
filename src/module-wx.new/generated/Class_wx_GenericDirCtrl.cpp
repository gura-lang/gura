//----------------------------------------------------------------------------
// wxGenericDirCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGenericDirCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGenericDirCtrl
//----------------------------------------------------------------------------
Object_wx_GenericDirCtrl::~Object_wx_GenericDirCtrl()
{
}

Object *Object_wx_GenericDirCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_GenericDirCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.GenericDirCtrl:");
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
// Class implementation for wxGenericDirCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GenericDirCtrl)
{
}

Gura_ImplementDescendantCreator(wx_GenericDirCtrl)
{
	return new Object_wx_GenericDirCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
