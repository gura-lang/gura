//----------------------------------------------------------------------------
// wxMessageOutput
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMessageOutput
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMessageOutput
//----------------------------------------------------------------------------
Object_wx_MessageOutput::~Object_wx_MessageOutput()
{
}

Object *Object_wx_MessageOutput::Clone() const
{
	return nullptr;
}

String Object_wx_MessageOutput::ToString(bool exprFlag)
{
	String rtn("<wx.MessageOutput:");
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
// Class implementation for wxMessageOutput
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MessageOutput)
{
}

Gura_ImplementDescendantCreator(wx_MessageOutput)
{
	return new Object_wx_MessageOutput((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
