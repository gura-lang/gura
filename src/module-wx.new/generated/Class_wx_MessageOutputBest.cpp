//----------------------------------------------------------------------------
// wxMessageOutputBest
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMessageOutputBest
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMessageOutputBest
//----------------------------------------------------------------------------
Object_wx_MessageOutputBest::~Object_wx_MessageOutputBest()
{
}

Object *Object_wx_MessageOutputBest::Clone() const
{
	return nullptr;
}

String Object_wx_MessageOutputBest::ToString(bool exprFlag)
{
	String rtn("<wx.MessageOutputBest:");
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
// Class implementation for wxMessageOutputBest
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MessageOutputBest)
{
}

Gura_ImplementDescendantCreator(wx_MessageOutputBest)
{
	return new Object_wx_MessageOutputBest((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
