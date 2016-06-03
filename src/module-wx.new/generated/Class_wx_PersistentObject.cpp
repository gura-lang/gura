//----------------------------------------------------------------------------
// wxPersistentObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPersistentObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPersistentObject
//----------------------------------------------------------------------------
Object_wx_PersistentObject::~Object_wx_PersistentObject()
{
}

Object *Object_wx_PersistentObject::Clone() const
{
	return nullptr;
}

String Object_wx_PersistentObject::ToString(bool exprFlag)
{
	String rtn("<wx.PersistentObject:");
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
Gura_DeclareMethodAlias(wx_PersistentObject, __wxPersistentObject, "wxPersistentObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistentObject, __wxPersistentObject)
{
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->wxPersistentObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistentObject, __Save, "Save")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentObject, __Save)
{
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Save();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistentObject, __Restore, "Restore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentObject, __Restore)
{
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Restore();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistentObject, __GetKind, "GetKind")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentObject, __GetKind)
{
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetKind();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistentObject, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentObject, __GetName)
{
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistentObject, __GetObject, "GetObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentObject, __GetObject)
{
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistentObject, __SaveValue, "SaveValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistentObject, __SaveValue)
{
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->SaveValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistentObject, __RestoreValue, "RestoreValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistentObject, __RestoreValue)
{
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->RestoreValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPersistentObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PersistentObject)
{
	Gura_AssignMethod(wx_PersistentObject, __wxPersistentObject);
	Gura_AssignMethod(wx_PersistentObject, __Save);
	Gura_AssignMethod(wx_PersistentObject, __Restore);
	Gura_AssignMethod(wx_PersistentObject, __GetKind);
	Gura_AssignMethod(wx_PersistentObject, __GetName);
	Gura_AssignMethod(wx_PersistentObject, __GetObject);
	Gura_AssignMethod(wx_PersistentObject, __SaveValue);
	Gura_AssignMethod(wx_PersistentObject, __RestoreValue);
}

Gura_ImplementDescendantCreator(wx_PersistentObject)
{
	return new Object_wx_PersistentObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
