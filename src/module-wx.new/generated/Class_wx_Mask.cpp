//----------------------------------------------------------------------------
// wxMask
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMask
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMask
//----------------------------------------------------------------------------
Object_wx_Mask::~Object_wx_Mask()
{
}

Object *Object_wx_Mask::Clone() const
{
	return nullptr;
}

String Object_wx_Mask::ToString(bool exprFlag)
{
	String rtn("<wx.Mask:");
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
Gura_DeclareMethod(wx_Mask, wxMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Mask, wxMask)
{
	Object_wx_Mask *pThis = Object_wx_Mask::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxMask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Mask, wxMask_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Mask, wxMask_1)
{
	Object_wx_Mask *pThis = Object_wx_Mask::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//pThis->GetEntity()->wxMask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Mask, wxMask_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Mask, wxMask_2)
{
	Object_wx_Mask *pThis = Object_wx_Mask::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->wxMask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Mask, wxMask_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Mask, wxMask_3)
{
	Object_wx_Mask *pThis = Object_wx_Mask::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int colour = arg.GetNumber(1)
	//pThis->GetEntity()->wxMask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Mask, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Mask, Create)
{
	Object_wx_Mask *pThis = Object_wx_Mask::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Mask, Create_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Mask, Create_1)
{
	Object_wx_Mask *pThis = Object_wx_Mask::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Mask, Create_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Mask, Create_2)
{
	Object_wx_Mask *pThis = Object_wx_Mask::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int colour = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Mask, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Mask, GetBitmap)
{
	Object_wx_Mask *pThis = Object_wx_Mask::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMask
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Mask)
{
	Gura_AssignMethod(wx_Mask, wxMask);
	Gura_AssignMethod(wx_Mask, wxMask_1);
	Gura_AssignMethod(wx_Mask, wxMask_2);
	Gura_AssignMethod(wx_Mask, wxMask_3);
	Gura_AssignMethod(wx_Mask, Create);
	Gura_AssignMethod(wx_Mask, Create_1);
	Gura_AssignMethod(wx_Mask, Create_2);
	Gura_AssignMethod(wx_Mask, GetBitmap);
}

Gura_ImplementDescendantCreator(wx_Mask)
{
	return new Object_wx_Mask((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
