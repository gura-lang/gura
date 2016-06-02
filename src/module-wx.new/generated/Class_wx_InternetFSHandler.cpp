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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_InternetFSHandler, wxInternetFSHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InternetFSHandler, wxInternetFSHandler)
{
	Object_wx_InternetFSHandler *pThis = Object_wx_InternetFSHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxInternetFSHandler();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxInternetFSHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_InternetFSHandler)
{
	Gura_AssignMethod(wx_InternetFSHandler, wxInternetFSHandler);
}

Gura_ImplementDescendantCreator(wx_InternetFSHandler)
{
	return new Object_wx_InternetFSHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
