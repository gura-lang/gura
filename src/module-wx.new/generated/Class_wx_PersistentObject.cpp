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
Gura_DeclareMethod(wx_PersistentObject, wxPersistentObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistentObject, wxPersistentObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->wxPersistentObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistentObject, ~wxPersistentObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentObject, ~wxPersistentObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxPersistentObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistentObject, Save)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentObject, Save)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Save();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistentObject, Restore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentObject, Restore)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Restore();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistentObject, GetKind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentObject, GetKind)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetKind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistentObject, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentObject, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistentObject, GetObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentObject, GetObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistentObject, SaveValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistentObject, SaveValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->SaveValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistentObject, RestoreValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistentObject, RestoreValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_PersistentObject, wxPersistentObject);
	Gura_AssignMethod(wx_PersistentObject, ~wxPersistentObject);
	Gura_AssignMethod(wx_PersistentObject, Save);
	Gura_AssignMethod(wx_PersistentObject, Restore);
	Gura_AssignMethod(wx_PersistentObject, GetKind);
	Gura_AssignMethod(wx_PersistentObject, GetName);
	Gura_AssignMethod(wx_PersistentObject, GetObject);
	Gura_AssignMethod(wx_PersistentObject, SaveValue);
	Gura_AssignMethod(wx_PersistentObject, RestoreValue);
}

Gura_ImplementDescendantCreator(wx_PersistentObject)
{
	return new Object_wx_PersistentObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
