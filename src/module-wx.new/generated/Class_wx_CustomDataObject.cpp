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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__CustomDataObject, "CustomDataObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CustomDataObject));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CustomDataObject)
{
	//const wxDataFormat& format = arg.GetNumber(0)
	//wxCustomDataObject();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CustomDataObject, __Alloc, "Alloc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CustomDataObject, __Alloc)
{
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t size = arg.GetNumber(0)
	//pThis->GetEntity()->Alloc();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CustomDataObject, __Free, "Free")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CustomDataObject, __Free)
{
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Free();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CustomDataObject, __GetData, "GetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CustomDataObject, __GetData)
{
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CustomDataObject, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CustomDataObject, __GetSize)
{
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CustomDataObject, __SetData, "SetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CustomDataObject, __SetData)
{
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t size = arg.GetNumber(0)
	//const void* data = arg.GetNumber(1)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CustomDataObject, __TakeData, "TakeData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CustomDataObject, __TakeData)
{
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t size = arg.GetNumber(0)
	//void* data = arg.GetNumber(1)
	//pThis->GetEntity()->TakeData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCustomDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CustomDataObject)
{
	// Constructor assignment
	Gura_AssignFunction(__CustomDataObject);
	// Method assignment
	Gura_AssignMethod(wx_CustomDataObject, __Alloc);
	Gura_AssignMethod(wx_CustomDataObject, __Free);
	Gura_AssignMethod(wx_CustomDataObject, __GetData);
	Gura_AssignMethod(wx_CustomDataObject, __GetSize);
	Gura_AssignMethod(wx_CustomDataObject, __SetData);
	Gura_AssignMethod(wx_CustomDataObject, __TakeData);
}

Gura_ImplementDescendantCreator(wx_CustomDataObject)
{
	return new Object_wx_CustomDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
