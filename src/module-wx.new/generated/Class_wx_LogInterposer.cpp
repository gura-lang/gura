//----------------------------------------------------------------------------
// wxLogInterposer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogInterposer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogInterposer
//----------------------------------------------------------------------------
Object_wx_LogInterposer::~Object_wx_LogInterposer()
{
}

Object *Object_wx_LogInterposer::Clone() const
{
	return nullptr;
}

String Object_wx_LogInterposer::ToString(bool exprFlag)
{
	String rtn("<wx.LogInterposer:");
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
Gura_DeclareFunctionAlias(__wxLogInterposer, "wxLogInterposer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_LogInterposer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxLogInterposer)
{
	//wxLogInterposer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLogInterposer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogInterposer)
{
	// Constructor assignment
	Gura_AssignFunction(__wxLogInterposer);
}

Gura_ImplementDescendantCreator(wx_LogInterposer)
{
	return new Object_wx_LogInterposer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
