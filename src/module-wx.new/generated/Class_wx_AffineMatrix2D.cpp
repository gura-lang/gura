//----------------------------------------------------------------------------
// wxAffineMatrix2D
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAffineMatrix2D
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAffineMatrix2D
//----------------------------------------------------------------------------
Object_wx_AffineMatrix2D::~Object_wx_AffineMatrix2D()
{
}

Object *Object_wx_AffineMatrix2D::Clone() const
{
	return nullptr;
}

String Object_wx_AffineMatrix2D::ToString(bool exprFlag)
{
	String rtn("<wx.AffineMatrix2D:");
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
Gura_DeclareMethod(wx_AffineMatrix2D, wxAffineMatrix2D)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AffineMatrix2D, wxAffineMatrix2D)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxAffineMatrix2D();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mat2D", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, Get)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mat2D = arg.GetNumber(0)
	//int tr = arg.GetNumber(1)
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mat2D", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, Set)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mat2D = arg.GetNumber(0)
	//int tr = arg.GetNumber(1)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, Concat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, Concat)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int t = arg.GetNumber(0)
	//pThis->GetEntity()->Concat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, Invert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AffineMatrix2D, Invert)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Invert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, IsIdentity)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AffineMatrix2D, IsIdentity)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsIdentity();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, IsEqual)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, IsEqual)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int t = arg.GetNumber(0)
	//pThis->GetEntity()->IsEqual();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, Translate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, Translate)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->Translate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, Scale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xScale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, Scale)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int xScale = arg.GetNumber(0)
	//int yScale = arg.GetNumber(1)
	//pThis->GetEntity()->Scale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, Mirror)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, Mirror)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->Mirror();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, Rotate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cRadians", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, Rotate)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cRadians = arg.GetNumber(0)
	//pThis->GetEntity()->Rotate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, TransformPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, TransformPoint)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->TransformPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, TransformPoint_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, TransformPoint_1)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->TransformPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, TransformDistance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, TransformDistance)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->TransformDistance();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, TransformDistance_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, TransformDistance_1)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->TransformDistance();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAffineMatrix2D
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AffineMatrix2D)
{
	Gura_AssignMethod(wx_AffineMatrix2D, wxAffineMatrix2D);
	Gura_AssignMethod(wx_AffineMatrix2D, Get);
	Gura_AssignMethod(wx_AffineMatrix2D, Set);
	Gura_AssignMethod(wx_AffineMatrix2D, Concat);
	Gura_AssignMethod(wx_AffineMatrix2D, Invert);
	Gura_AssignMethod(wx_AffineMatrix2D, IsIdentity);
	Gura_AssignMethod(wx_AffineMatrix2D, IsEqual);
	Gura_AssignMethod(wx_AffineMatrix2D, Translate);
	Gura_AssignMethod(wx_AffineMatrix2D, Scale);
	Gura_AssignMethod(wx_AffineMatrix2D, Mirror);
	Gura_AssignMethod(wx_AffineMatrix2D, Rotate);
	Gura_AssignMethod(wx_AffineMatrix2D, TransformPoint);
	Gura_AssignMethod(wx_AffineMatrix2D, TransformPoint_1);
	Gura_AssignMethod(wx_AffineMatrix2D, TransformDistance);
	Gura_AssignMethod(wx_AffineMatrix2D, TransformDistance_1);
}

Gura_ImplementDescendantCreator(wx_AffineMatrix2D)
{
	return new Object_wx_AffineMatrix2D((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
