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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Size, wxSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Size, wxSize)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, wxSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, wxSize_1)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//pThis->GetEntity()->wxSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, DecBy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, DecBy)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->DecBy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, DecBy_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, DecBy_1)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->DecBy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, DecBy_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, DecBy_2)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->DecBy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, DecBy_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, DecBy_3)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int d = arg.GetNumber(0)
	//pThis->GetEntity()->DecBy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, DecTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, DecTo)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->DecTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, DecToIfSpecified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, DecToIfSpecified)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->DecToIfSpecified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, GetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Size, GetHeight)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Size, GetWidth)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, IncBy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, IncBy)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->IncBy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, IncBy_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, IncBy_1)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->IncBy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, IncBy_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, IncBy_2)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->IncBy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, IncBy_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, IncBy_3)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int d = arg.GetNumber(0)
	//pThis->GetEntity()->IncBy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, IncTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, IncTo)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->IncTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, IsFullySpecified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Size, IsFullySpecified)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFullySpecified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, Scale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xscale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yscale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, Scale)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int xscale = arg.GetNumber(0)
	//int yscale = arg.GetNumber(1)
	//pThis->GetEntity()->Scale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, Set)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, SetDefaults)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizeDefault", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, SetDefaults)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sizeDefault = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaults();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, SetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, SetHeight)
{
	Object_wx_Size *pThis = Object_wx_Size::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int height = arg.GetNumber(0)
	//pThis->GetEntity()->SetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Size, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, SetWidth)
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
	Gura_AssignMethod(wx_Size, wxSize);
	Gura_AssignMethod(wx_Size, wxSize_1);
	Gura_AssignMethod(wx_Size, DecBy);
	Gura_AssignMethod(wx_Size, DecBy_1);
	Gura_AssignMethod(wx_Size, DecBy_2);
	Gura_AssignMethod(wx_Size, DecBy_3);
	Gura_AssignMethod(wx_Size, DecTo);
	Gura_AssignMethod(wx_Size, DecToIfSpecified);
	Gura_AssignMethod(wx_Size, GetHeight);
	Gura_AssignMethod(wx_Size, GetWidth);
	Gura_AssignMethod(wx_Size, IncBy);
	Gura_AssignMethod(wx_Size, IncBy_1);
	Gura_AssignMethod(wx_Size, IncBy_2);
	Gura_AssignMethod(wx_Size, IncBy_3);
	Gura_AssignMethod(wx_Size, IncTo);
	Gura_AssignMethod(wx_Size, IsFullySpecified);
	Gura_AssignMethod(wx_Size, Scale);
	Gura_AssignMethod(wx_Size, Set);
	Gura_AssignMethod(wx_Size, SetDefaults);
	Gura_AssignMethod(wx_Size, SetHeight);
	Gura_AssignMethod(wx_Size, SetWidth);
}

Gura_ImplementDescendantCreator(wx_Size)
{
	return new Object_wx_Size((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
