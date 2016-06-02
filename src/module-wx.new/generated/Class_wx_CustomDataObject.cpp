//----------------------------------------------------------------------------
// wxCustomDataObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCustomDataObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCustomDataObject
//----------------------------------------------------------------------------
Object_wx_CustomDataObject::~Object_wx_CustomDataObject()
{
}

Object *Object_wx_CustomDataObject::Clone() const
{
	return nullptr;
}

String Object_wx_CustomDataObject::ToString(bool exprFlag)
{
	String rtn("<wx.CustomDataObject:");
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
Gura_DeclareMethod(wx_CustomDataObject, wxCustomDataObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CustomDataObject, wxCustomDataObject)
{
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->wxCustomDataObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CustomDataObject, Alloc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CustomDataObject, Alloc)
{
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->Alloc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CustomDataObject, Free)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CustomDataObject, Free)
{
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Free();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CustomDataObject, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CustomDataObject, GetData)
{
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CustomDataObject, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CustomDataObject, GetSize)
{
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CustomDataObject, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CustomDataObject, SetData)
{
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CustomDataObject, TakeData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CustomDataObject, TakeData)
{
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->TakeData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCustomDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CustomDataObject)
{
	Gura_AssignMethod(wx_CustomDataObject, wxCustomDataObject);
	Gura_AssignMethod(wx_CustomDataObject, Alloc);
	Gura_AssignMethod(wx_CustomDataObject, Free);
	Gura_AssignMethod(wx_CustomDataObject, GetData);
	Gura_AssignMethod(wx_CustomDataObject, GetSize);
	Gura_AssignMethod(wx_CustomDataObject, SetData);
	Gura_AssignMethod(wx_CustomDataObject, TakeData);
}

Gura_ImplementDescendantCreator(wx_CustomDataObject)
{
	return new Object_wx_CustomDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
