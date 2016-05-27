//----------------------------------------------------------------------------
// wxHeaderCtrlSimple
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHeaderCtrlSimple
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHeaderCtrlSimple
//----------------------------------------------------------------------------
Object_wx_HeaderCtrlSimple::~Object_wx_HeaderCtrlSimple()
{
}

Object *Object_wx_HeaderCtrlSimple::Clone() const
{
	return nullptr;
}

String Object_wx_HeaderCtrlSimple::ToString(bool exprFlag)
{
	String rtn("<wx.HeaderCtrlSimple:");
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
// Class implementation for wxHeaderCtrlSimple
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HeaderCtrlSimple)
{
}

Gura_ImplementDescendantCreator(wx_HeaderCtrlSimple)
{
	return new Object_wx_HeaderCtrlSimple((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
