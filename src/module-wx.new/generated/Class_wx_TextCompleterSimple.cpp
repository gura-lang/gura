//----------------------------------------------------------------------------
// wxTextCompleterSimple
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextCompleterSimple
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextCompleterSimple
//----------------------------------------------------------------------------
Object_wx_TextCompleterSimple::~Object_wx_TextCompleterSimple()
{
}

Object *Object_wx_TextCompleterSimple::Clone() const
{
	return nullptr;
}

String Object_wx_TextCompleterSimple::ToString(bool exprFlag)
{
	String rtn("<wx.TextCompleterSimple:");
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
// Class implementation for wxTextCompleterSimple
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextCompleterSimple)
{
}

Gura_ImplementDescendantCreator(wx_TextCompleterSimple)
{
	return new Object_wx_TextCompleterSimple((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
