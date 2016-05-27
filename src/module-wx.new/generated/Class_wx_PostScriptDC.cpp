//----------------------------------------------------------------------------
// wxPostScriptDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPostScriptDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPostScriptDC
//----------------------------------------------------------------------------
Object_wx_PostScriptDC::~Object_wx_PostScriptDC()
{
}

Object *Object_wx_PostScriptDC::Clone() const
{
	return nullptr;
}

String Object_wx_PostScriptDC::ToString(bool exprFlag)
{
	String rtn("<wx.PostScriptDC:");
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
// Class implementation for wxPostScriptDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PostScriptDC)
{
}

Gura_ImplementDescendantCreator(wx_PostScriptDC)
{
	return new Object_wx_PostScriptDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
