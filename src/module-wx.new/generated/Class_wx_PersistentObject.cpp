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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__PersistentObject, "PersistentObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PersistentObject));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PersistentObject)
{
	//void* obj = arg.GetNumber(0)
	//wxPersistentObject(obj);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentObject, __Restore)
{
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Restore();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistentObject, __GetKind, "GetKind")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentObject, __GetKind)
{
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetKind();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistentObject, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentObject, __GetName)
{
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistentObject, __GetObject, "GetObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentObject, __GetObject)
{
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* _rtn = pThis->GetEntity()->GetObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistentObject, __SaveValue, "SaveValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistentObject, __SaveValue)
{
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//T value = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SaveValue(name, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistentObject, __RestoreValue, "RestoreValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistentObject, __RestoreValue)
{
	Object_wx_PersistentObject *pThis = Object_wx_PersistentObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//T* value = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->RestoreValue(name, value);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPersistentObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PersistentObject)
{
	// Constructor assignment
	Gura_AssignFunction(__PersistentObject);
	// Method assignment
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
