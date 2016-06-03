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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxAffineMatrix2D, "wxAffineMatrix2D")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxAffineMatrix2D)
{
	//wxAffineMatrix2D();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AffineMatrix2D, __Get, "Get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mat2D", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, __Get)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mat2D = arg.GetNumber(0)
	//int tr = arg.GetNumber(1)
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2D, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mat2D", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, __Set)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mat2D = arg.GetNumber(0)
	//int tr = arg.GetNumber(1)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2D, __Concat, "Concat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, __Concat)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int t = arg.GetNumber(0)
	//pThis->GetEntity()->Concat();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2D, __Invert, "Invert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AffineMatrix2D, __Invert)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Invert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2D, __IsIdentity, "IsIdentity")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AffineMatrix2D, __IsIdentity)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsIdentity();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2D, __IsEqual, "IsEqual")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, __IsEqual)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int t = arg.GetNumber(0)
	//pThis->GetEntity()->IsEqual();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2D, __Translate, "Translate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, __Translate)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->Translate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2D, __Scale, "Scale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xScale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, __Scale)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int xScale = arg.GetNumber(0)
	//int yScale = arg.GetNumber(1)
	//pThis->GetEntity()->Scale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2D, __Mirror, "Mirror")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, __Mirror)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->Mirror();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2D, __Rotate, "Rotate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cRadians", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, __Rotate)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cRadians = arg.GetNumber(0)
	//pThis->GetEntity()->Rotate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2D, __TransformPoint, "TransformPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, __TransformPoint)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->TransformPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2D, __TransformPoint_1, "TransformPoint_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, __TransformPoint_1)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->TransformPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2D, __TransformDistance, "TransformDistance")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, __TransformDistance)
{
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->TransformDistance();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2D, __TransformDistance_1, "TransformDistance_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, __TransformDistance_1)
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
	// Constructor assignment
	Gura_AssignFunction(__wxAffineMatrix2D);
	// Method assignment
	Gura_AssignMethod(wx_AffineMatrix2D, __Get);
	Gura_AssignMethod(wx_AffineMatrix2D, __Set);
	Gura_AssignMethod(wx_AffineMatrix2D, __Concat);
	Gura_AssignMethod(wx_AffineMatrix2D, __Invert);
	Gura_AssignMethod(wx_AffineMatrix2D, __IsIdentity);
	Gura_AssignMethod(wx_AffineMatrix2D, __IsEqual);
	Gura_AssignMethod(wx_AffineMatrix2D, __Translate);
	Gura_AssignMethod(wx_AffineMatrix2D, __Scale);
	Gura_AssignMethod(wx_AffineMatrix2D, __Mirror);
	Gura_AssignMethod(wx_AffineMatrix2D, __Rotate);
	Gura_AssignMethod(wx_AffineMatrix2D, __TransformPoint);
	Gura_AssignMethod(wx_AffineMatrix2D, __TransformPoint_1);
	Gura_AssignMethod(wx_AffineMatrix2D, __TransformDistance);
	Gura_AssignMethod(wx_AffineMatrix2D, __TransformDistance_1);
}

Gura_ImplementDescendantCreator(wx_AffineMatrix2D)
{
	return new Object_wx_AffineMatrix2D((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
