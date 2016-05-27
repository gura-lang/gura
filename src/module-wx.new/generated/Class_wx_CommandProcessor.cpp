//----------------------------------------------------------------------------
// wxCommandProcessor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCommandProcessor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCommandProcessor
//----------------------------------------------------------------------------
Object_wx_CommandProcessor::~Object_wx_CommandProcessor()
{
}

Object *Object_wx_CommandProcessor::Clone() const
{
	return nullptr;
}

String Object_wx_CommandProcessor::ToString(bool exprFlag)
{
	String rtn("<wx.CommandProcessor:");
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
// Class implementation for wxCommandProcessor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CommandProcessor)
{
}

Gura_ImplementDescendantCreator(wx_CommandProcessor)
{
	return new Object_wx_CommandProcessor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
