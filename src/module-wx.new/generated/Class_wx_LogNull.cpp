//----------------------------------------------------------------------------
// wxLogNull
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogNull
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogNull
//----------------------------------------------------------------------------
Object_wx_LogNull::~Object_wx_LogNull()
{
}

Object *Object_wx_LogNull::Clone() const
{
	return nullptr;
}

String Object_wx_LogNull::ToString(bool exprFlag)
{
	String rtn("<wx.LogNull:");
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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxLogNull, "wxLogNull")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_LogNull));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxLogNull)
{
	//wxLogNull();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLogNull
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogNull)
{
	// Constructor assignment
	Gura_AssignFunction(__wxLogNull);
}

Gura_ImplementDescendantCreator(wx_LogNull)
{
	return new Object_wx_LogNull((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
