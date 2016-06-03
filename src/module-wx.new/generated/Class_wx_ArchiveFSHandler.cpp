//----------------------------------------------------------------------------
// wxArchiveFSHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveFSHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArchiveFSHandler
//----------------------------------------------------------------------------
Object_wx_ArchiveFSHandler::~Object_wx_ArchiveFSHandler()
{
}

Object *Object_wx_ArchiveFSHandler::Clone() const
{
	return nullptr;
}

String Object_wx_ArchiveFSHandler::ToString(bool exprFlag)
{
	String rtn("<wx.ArchiveFSHandler:");
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
Gura_DeclareFunctionAlias(__wxArchiveFSHandler, "wxArchiveFSHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ArchiveFSHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxArchiveFSHandler)
{
	//wxArchiveFSHandler();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ArchiveFSHandler, __Cleanup, "Cleanup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveFSHandler, __Cleanup)
{
	Object_wx_ArchiveFSHandler *pThis = Object_wx_ArchiveFSHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Cleanup();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxArchiveFSHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveFSHandler)
{
	// Constructor assignment
	Gura_AssignFunction(__wxArchiveFSHandler);
	// Method assignment
	Gura_AssignMethod(wx_ArchiveFSHandler, __Cleanup);
}

Gura_ImplementDescendantCreator(wx_ArchiveFSHandler)
{
	return new Object_wx_ArchiveFSHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
