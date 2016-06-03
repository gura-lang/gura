//----------------------------------------------------------------------------
// wxClientData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxClientData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxClientData
//----------------------------------------------------------------------------
Object_wx_ClientData::~Object_wx_ClientData()
{
}

Object *Object_wx_ClientData::Clone() const
{
	return nullptr;
}

String Object_wx_ClientData::ToString(bool exprFlag)
{
	String rtn("<wx.ClientData:");
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
Gura_DeclareFunctionAlias(__wxClientData, "wxClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ClientData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxClientData)
{
	//wxClientData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxClientData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClientData)
{
	// Constructor assignment
	Gura_AssignFunction(__wxClientData);
}

Gura_ImplementDescendantCreator(wx_ClientData)
{
	return new Object_wx_ClientData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
