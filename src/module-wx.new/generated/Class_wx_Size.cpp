//----------------------------------------------------------------------------
// wxSize
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSize
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSize
//----------------------------------------------------------------------------
Object_wx_Size::~Object_wx_Size()
{
}

Object *Object_wx_Size::Clone() const
{
	return nullptr;
}

String Object_wx_Size::ToString(bool exprFlag)
{
	String rtn("<wx.Size:");
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
Gura_DeclareFunctionAlias(__wxSize, "wxSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxSize)
{
	//wxSize();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxSize_1, "wxSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxSize_1)
{
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//wxSize();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Size, __DecBy, "DecBy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, __DecBy)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->DecBy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Size, __DecBy_1, "DecBy_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, __DecBy_1)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->DecBy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Size, __DecBy_2, "DecBy_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, __DecBy_2)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->DecBy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Size, __DecBy_3, "DecBy_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, __DecBy_3)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int d = arg.GetNumber(0)
	//pThis->GetEntity()->DecBy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Size, __DecTo, "DecTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, __DecTo)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->DecTo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Size, __DecToIfSpecified, "DecToIfSpecified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, __DecToIfSpecified)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->DecToIfSpecified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Size, __GetHeight, "GetHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Size, __GetHeight)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Size, __GetWidth, "GetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Size, __GetWidth)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Size, __IncBy, "IncBy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, __IncBy)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->IncBy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Size, __IncBy_1, "IncBy_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, __IncBy_1)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->IncBy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Size, __IncBy_2, "IncBy_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, __IncBy_2)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->IncBy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Size, __IncBy_3, "IncBy_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, __IncBy_3)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int d = arg.GetNumber(0)
	//pThis->GetEntity()->IncBy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Size, __IncTo, "IncTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, __IncTo)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->IncTo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Size, __IsFullySpecified, "IsFullySpecified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Size, __IsFullySpecified)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFullySpecified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Size, __Scale, "Scale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xscale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yscale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, __Scale)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int xscale = arg.GetNumber(0)
	//int yscale = arg.GetNumber(1)
	//pThis->GetEntity()->Scale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Size, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, __Set)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Size, __SetDefaults, "SetDefaults")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizeDefault", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, __SetDefaults)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sizeDefault = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaults();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Size, __SetHeight, "SetHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, __SetHeight)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int height = arg.GetNumber(0)
	//pThis->GetEntity()->SetHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Size, __SetWidth, "SetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, __SetWidth)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSize
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Size)
{
	// Constructor assignment
	Gura_AssignFunction(__wxSize);
	Gura_AssignFunction(__wxSize_1);
	// Method assignment
	Gura_AssignMethod(wx_Size, __DecBy);
	Gura_AssignMethod(wx_Size, __DecBy_1);
	Gura_AssignMethod(wx_Size, __DecBy_2);
	Gura_AssignMethod(wx_Size, __DecBy_3);
	Gura_AssignMethod(wx_Size, __DecTo);
	Gura_AssignMethod(wx_Size, __DecToIfSpecified);
	Gura_AssignMethod(wx_Size, __GetHeight);
	Gura_AssignMethod(wx_Size, __GetWidth);
	Gura_AssignMethod(wx_Size, __IncBy);
	Gura_AssignMethod(wx_Size, __IncBy_1);
	Gura_AssignMethod(wx_Size, __IncBy_2);
	Gura_AssignMethod(wx_Size, __IncBy_3);
	Gura_AssignMethod(wx_Size, __IncTo);
	Gura_AssignMethod(wx_Size, __IsFullySpecified);
	Gura_AssignMethod(wx_Size, __Scale);
	Gura_AssignMethod(wx_Size, __Set);
	Gura_AssignMethod(wx_Size, __SetDefaults);
	Gura_AssignMethod(wx_Size, __SetHeight);
	Gura_AssignMethod(wx_Size, __SetWidth);
}

Gura_ImplementDescendantCreator(wx_Size)
{
	return new Object_wx_Size((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
