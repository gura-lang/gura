//----------------------------------------------------------------------------
// wxPersistenceManager
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPersistenceManager
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPersistenceManager
//----------------------------------------------------------------------------
Object_wx_PersistenceManager::~Object_wx_PersistenceManager()
{
}

Object *Object_wx_PersistenceManager::Clone() const
{
	return nullptr;
}

String Object_wx_PersistenceManager::ToString(bool exprFlag)
{
	String rtn("<wx.PersistenceManager:");
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
Gura_DeclareMethod(wx_PersistenceManager, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "manager", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int manager = arg.GetNumber(0)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistenceManager, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistenceManager, Get)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistenceManager, DisableSaving)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistenceManager, DisableSaving)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DisableSaving();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistenceManager, DisableRestoring)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistenceManager, DisableRestoring)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DisableRestoring();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistenceManager, Register)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, Register)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Register();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistenceManager, Register_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "po", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, Register_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int po = arg.GetNumber(1)
	//pThis->GetEntity()->Register();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistenceManager, Find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, Find)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Find();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistenceManager, Unregister)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, Unregister)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Unregister();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistenceManager, Save)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, Save)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Save();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistenceManager, Restore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, Restore)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Restore();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistenceManager, SaveAndUnregister)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, SaveAndUnregister)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->SaveAndUnregister();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistenceManager, RegisterAndRestore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, RegisterAndRestore)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->RegisterAndRestore();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistenceManager, RegisterAndRestore_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "po", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, RegisterAndRestore_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int po = arg.GetNumber(1)
	//pThis->GetEntity()->RegisterAndRestore();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistenceManager, wxPersistenceManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistenceManager, wxPersistenceManager)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxPersistenceManager();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistenceManager, GetConfig)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistenceManager, GetConfig)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetConfig();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistenceManager, GetKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "who", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, GetKey)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int who = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->GetKey();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPersistenceManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PersistenceManager)
{
	Gura_AssignMethod(wx_PersistenceManager, Set);
	Gura_AssignMethod(wx_PersistenceManager, Get);
	Gura_AssignMethod(wx_PersistenceManager, DisableSaving);
	Gura_AssignMethod(wx_PersistenceManager, DisableRestoring);
	Gura_AssignMethod(wx_PersistenceManager, Register);
	Gura_AssignMethod(wx_PersistenceManager, Register_1);
	Gura_AssignMethod(wx_PersistenceManager, Find);
	Gura_AssignMethod(wx_PersistenceManager, Unregister);
	Gura_AssignMethod(wx_PersistenceManager, Save);
	Gura_AssignMethod(wx_PersistenceManager, Restore);
	Gura_AssignMethod(wx_PersistenceManager, SaveAndUnregister);
	Gura_AssignMethod(wx_PersistenceManager, RegisterAndRestore);
	Gura_AssignMethod(wx_PersistenceManager, RegisterAndRestore_1);
	Gura_AssignMethod(wx_PersistenceManager, wxPersistenceManager);
	Gura_AssignMethod(wx_PersistenceManager, GetConfig);
	Gura_AssignMethod(wx_PersistenceManager, GetKey);
}

Gura_ImplementDescendantCreator(wx_PersistenceManager)
{
	return new Object_wx_PersistenceManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
