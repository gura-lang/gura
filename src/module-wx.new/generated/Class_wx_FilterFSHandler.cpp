//----------------------------------------------------------------------------
// wxFilterFSHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFilterFSHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFilterFSHandler
//----------------------------------------------------------------------------
Object_wx_FilterFSHandler::~Object_wx_FilterFSHandler()
{
}

Object *Object_wx_FilterFSHandler::Clone() const
{
	return nullptr;
}

String Object_wx_FilterFSHandler::ToString(bool exprFlag)
{
	String rtn("<wx.FilterFSHandler:");
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
Gura_DeclareFunctionAlias(__FilterFSHandler, "FilterFSHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FilterFSHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FilterFSHandler)
{
	//wxFilterFSHandler();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFilterFSHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FilterFSHandler)
{
	// Constructor assignment
	Gura_AssignFunction(__FilterFSHandler);
}

Gura_ImplementDescendantCreator(wx_FilterFSHandler)
{
	return new Object_wx_FilterFSHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
