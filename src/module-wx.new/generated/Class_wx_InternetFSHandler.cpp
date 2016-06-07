//----------------------------------------------------------------------------
// wxInternetFSHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxInternetFSHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxInternetFSHandler
//----------------------------------------------------------------------------
Object_wx_InternetFSHandler::~Object_wx_InternetFSHandler()
{
}

Object *Object_wx_InternetFSHandler::Clone() const
{
	return nullptr;
}

String Object_wx_InternetFSHandler::ToString(bool exprFlag)
{
	String rtn("<wx.InternetFSHandler:");
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
Gura_DeclareFunctionAlias(__InternetFSHandler, "InternetFSHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_InternetFSHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__InternetFSHandler)
{
	//wxInternetFSHandler();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxInternetFSHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_InternetFSHandler)
{
	// Constructor assignment
	Gura_AssignFunction(__InternetFSHandler);
}

Gura_ImplementDescendantCreator(wx_InternetFSHandler)
{
	return new Object_wx_InternetFSHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
