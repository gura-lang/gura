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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__PersistenceManager, "PersistenceManager")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PersistenceManager));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PersistenceManager)
{
	//wxPersistenceManager();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PersistenceManager, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "manager", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, __Set)
{
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPersistenceManager& manager = arg.GetNumber(0)
	//pThis->GetEntity()->Set(manager);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistenceManager, __Get, "Get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistenceManager, __Get)
{
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistenceManager, __DisableSaving, "DisableSaving")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistenceManager, __DisableSaving)
{
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DisableSaving();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistenceManager, __DisableRestoring, "DisableRestoring")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistenceManager, __DisableRestoring)
{
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DisableRestoring();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistenceManager, __Register, "Register")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, __Register)
{
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T* obj = arg.GetNumber(0)
	//pThis->GetEntity()->Register(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistenceManager, __Register_1, "Register_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "po", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, __Register_1)
{
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* obj = arg.GetNumber(0)
	//wxPersistentObject* po = arg.GetNumber(1)
	//pThis->GetEntity()->Register(obj, po);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistenceManager, __Find, "Find")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, __Find)
{
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* obj = arg.GetNumber(0)
	//pThis->GetEntity()->Find(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistenceManager, __Unregister, "Unregister")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, __Unregister)
{
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* obj = arg.GetNumber(0)
	//pThis->GetEntity()->Unregister(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistenceManager, __Save, "Save")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, __Save)
{
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* obj = arg.GetNumber(0)
	//pThis->GetEntity()->Save(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistenceManager, __Restore, "Restore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, __Restore)
{
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* obj = arg.GetNumber(0)
	//pThis->GetEntity()->Restore(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistenceManager, __SaveAndUnregister, "SaveAndUnregister")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, __SaveAndUnregister)
{
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* obj = arg.GetNumber(0)
	//pThis->GetEntity()->SaveAndUnregister(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistenceManager, __RegisterAndRestore, "RegisterAndRestore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, __RegisterAndRestore)
{
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T* obj = arg.GetNumber(0)
	//pThis->GetEntity()->RegisterAndRestore(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistenceManager, __RegisterAndRestore_1, "RegisterAndRestore_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "po", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, __RegisterAndRestore_1)
{
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* obj = arg.GetNumber(0)
	//wxPersistentObject* po = arg.GetNumber(1)
	//pThis->GetEntity()->RegisterAndRestore(obj, po);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistenceManager, __GetConfig, "GetConfig")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistenceManager, __GetConfig)
{
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetConfig();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistenceManager, __GetKey, "GetKey")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "who", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistenceManager, __GetKey)
{
	Object_wx_PersistenceManager *pThis = Object_wx_PersistenceManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPersistentObject& who = arg.GetNumber(0)
	//const wxString& name = arg.GetNumber(1)
	//pThis->GetEntity()->GetKey(who, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPersistenceManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PersistenceManager)
{
	// Constructor assignment
	Gura_AssignFunction(__PersistenceManager);
	// Method assignment
	Gura_AssignMethod(wx_PersistenceManager, __Set);
	Gura_AssignMethod(wx_PersistenceManager, __Get);
	Gura_AssignMethod(wx_PersistenceManager, __DisableSaving);
	Gura_AssignMethod(wx_PersistenceManager, __DisableRestoring);
	Gura_AssignMethod(wx_PersistenceManager, __Register);
	Gura_AssignMethod(wx_PersistenceManager, __Register_1);
	Gura_AssignMethod(wx_PersistenceManager, __Find);
	Gura_AssignMethod(wx_PersistenceManager, __Unregister);
	Gura_AssignMethod(wx_PersistenceManager, __Save);
	Gura_AssignMethod(wx_PersistenceManager, __Restore);
	Gura_AssignMethod(wx_PersistenceManager, __SaveAndUnregister);
	Gura_AssignMethod(wx_PersistenceManager, __RegisterAndRestore);
	Gura_AssignMethod(wx_PersistenceManager, __RegisterAndRestore_1);
	Gura_AssignMethod(wx_PersistenceManager, __GetConfig);
	Gura_AssignMethod(wx_PersistenceManager, __GetKey);
}

Gura_ImplementDescendantCreator(wx_PersistenceManager)
{
	return new Object_wx_PersistenceManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
