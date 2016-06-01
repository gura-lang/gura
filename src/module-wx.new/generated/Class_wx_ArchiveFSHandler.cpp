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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ArchiveFSHandler, wxArchiveFSHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveFSHandler, wxArchiveFSHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveFSHandler *pThis = Object_wx_ArchiveFSHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxArchiveFSHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveFSHandler, ~wxArchiveFSHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveFSHandler, ~wxArchiveFSHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveFSHandler *pThis = Object_wx_ArchiveFSHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxArchiveFSHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveFSHandler, Cleanup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveFSHandler, Cleanup)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveFSHandler *pThis = Object_wx_ArchiveFSHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Cleanup();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxArchiveFSHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveFSHandler)
{
	Gura_AssignMethod(wx_ArchiveFSHandler, wxArchiveFSHandler);
	Gura_AssignMethod(wx_ArchiveFSHandler, ~wxArchiveFSHandler);
	Gura_AssignMethod(wx_ArchiveFSHandler, Cleanup);
}

Gura_ImplementDescendantCreator(wx_ArchiveFSHandler)
{
	return new Object_wx_ArchiveFSHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
