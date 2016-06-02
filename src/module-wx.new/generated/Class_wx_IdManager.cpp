//----------------------------------------------------------------------------
// wxIdManager
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxIdManager
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxIdManager
//----------------------------------------------------------------------------
Object_wx_IdManager::~Object_wx_IdManager()
{
}

Object *Object_wx_IdManager::Clone() const
{
	return nullptr;
}

String Object_wx_IdManager::ToString(bool exprFlag)
{
	String rtn("<wx.IdManager:");
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
Gura_DeclareMethod(wx_IdManager, ReserveId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IdManager, ReserveId)
{
	Object_wx_IdManager *pThis = Object_wx_IdManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int count = arg.GetNumber(0)
	//pThis->GetEntity()->ReserveId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IdManager, UnreserveId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IdManager, UnreserveId)
{
	Object_wx_IdManager *pThis = Object_wx_IdManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int count = arg.GetNumber(1)
	//pThis->GetEntity()->UnreserveId();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxIdManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IdManager)
{
	Gura_AssignMethod(wx_IdManager, ReserveId);
	Gura_AssignMethod(wx_IdManager, UnreserveId);
}

Gura_ImplementDescendantCreator(wx_IdManager)
{
	return new Object_wx_IdManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
