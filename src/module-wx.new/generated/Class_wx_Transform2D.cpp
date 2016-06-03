//----------------------------------------------------------------------------
// wxTransform2D
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTransform2D
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTransform2D
//----------------------------------------------------------------------------
Object_wx_Transform2D::~Object_wx_Transform2D()
{
}

Object *Object_wx_Transform2D::Clone() const
{
	return nullptr;
}

String Object_wx_Transform2D::ToString(bool exprFlag)
{
	String rtn("<wx.Transform2D:");
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
Gura_DeclareMethodAlias(wx_Transform2D, __Transform, "Transform")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Transform2D, __Transform)
{
	Object_wx_Transform2D *pThis = Object_wx_Transform2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Transform();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Transform2D, __Transform_1, "Transform_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Transform2D, __Transform_1)
{
	Object_wx_Transform2D *pThis = Object_wx_Transform2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int r = arg.GetNumber(0)
	//pThis->GetEntity()->Transform();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Transform2D, __Transform_2, "Transform_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Transform2D, __Transform_2)
{
	Object_wx_Transform2D *pThis = Object_wx_Transform2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Transform();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Transform2D, __Transform_3, "Transform_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Transform2D, __Transform_3)
{
	Object_wx_Transform2D *pThis = Object_wx_Transform2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int r = arg.GetNumber(0)
	//pThis->GetEntity()->Transform();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Transform2D, __InverseTransform, "InverseTransform")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Transform2D, __InverseTransform)
{
	Object_wx_Transform2D *pThis = Object_wx_Transform2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->InverseTransform();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Transform2D, __InverseTransform_1, "InverseTransform_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Transform2D, __InverseTransform_1)
{
	Object_wx_Transform2D *pThis = Object_wx_Transform2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int r = arg.GetNumber(0)
	//pThis->GetEntity()->InverseTransform();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Transform2D, __InverseTransform_2, "InverseTransform_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Transform2D, __InverseTransform_2)
{
	Object_wx_Transform2D *pThis = Object_wx_Transform2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->InverseTransform();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Transform2D, __InverseTransform_3, "InverseTransform_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Transform2D, __InverseTransform_3)
{
	Object_wx_Transform2D *pThis = Object_wx_Transform2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int r = arg.GetNumber(0)
	//pThis->GetEntity()->InverseTransform();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTransform2D
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Transform2D)
{
	// Class assignment
	Gura_AssignValueEx("Transform2D", Reference());
	// Method assignment
	Gura_AssignMethod(wx_Transform2D, __Transform);
	Gura_AssignMethod(wx_Transform2D, __Transform_1);
	Gura_AssignMethod(wx_Transform2D, __Transform_2);
	Gura_AssignMethod(wx_Transform2D, __Transform_3);
	Gura_AssignMethod(wx_Transform2D, __InverseTransform);
	Gura_AssignMethod(wx_Transform2D, __InverseTransform_1);
	Gura_AssignMethod(wx_Transform2D, __InverseTransform_2);
	Gura_AssignMethod(wx_Transform2D, __InverseTransform_3);
}

Gura_ImplementDescendantCreator(wx_Transform2D)
{
	return new Object_wx_Transform2D((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
