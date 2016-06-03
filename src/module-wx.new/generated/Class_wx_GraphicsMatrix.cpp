//----------------------------------------------------------------------------
// wxGraphicsMatrix
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsMatrix
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsMatrix
//----------------------------------------------------------------------------
Object_wx_GraphicsMatrix::~Object_wx_GraphicsMatrix()
{
}

Object *Object_wx_GraphicsMatrix::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsMatrix::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsMatrix:");
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
Gura_DeclareMethodAlias(wx_GraphicsMatrix, __Concat, "Concat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, __Concat)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGraphicsMatrix* t = arg.GetNumber(0)
	//pThis->GetEntity()->Concat();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsMatrix, __Concat_1, "Concat_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, __Concat_1)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGraphicsMatrix& t = arg.GetNumber(0)
	//pThis->GetEntity()->Concat();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsMatrix, __Get, "Get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "a", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ty", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, __Get)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble* a = arg.GetNumber(0)
	//wxDouble* b = arg.GetNumber(1)
	//wxDouble* c = arg.GetNumber(2)
	//wxDouble* d = arg.GetNumber(3)
	//wxDouble* tx = arg.GetNumber(4)
	//wxDouble* ty = arg.GetNumber(5)
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsMatrix, __GetNativeMatrix, "GetNativeMatrix")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsMatrix, __GetNativeMatrix)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNativeMatrix();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsMatrix, __Invert, "Invert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsMatrix, __Invert)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Invert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsMatrix, __IsEqual, "IsEqual")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, __IsEqual)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGraphicsMatrix* t = arg.GetNumber(0)
	//pThis->GetEntity()->IsEqual();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsMatrix, __IsEqual_1, "IsEqual_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, __IsEqual_1)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGraphicsMatrix& t = arg.GetNumber(0)
	//pThis->GetEntity()->IsEqual();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsMatrix, __IsIdentity, "IsIdentity")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsMatrix, __IsIdentity)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsIdentity();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsMatrix, __Rotate, "Rotate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, __Rotate)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble angle = arg.GetNumber(0)
	//pThis->GetEntity()->Rotate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsMatrix, __Scale, "Scale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xScale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, __Scale)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble xScale = arg.GetNumber(0)
	//wxDouble yScale = arg.GetNumber(1)
	//pThis->GetEntity()->Scale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsMatrix, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "a", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ty", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, __Set)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble a = arg.GetNumber(0)
	//wxDouble b = arg.GetNumber(1)
	//wxDouble c = arg.GetNumber(2)
	//wxDouble d = arg.GetNumber(3)
	//wxDouble tx = arg.GetNumber(4)
	//wxDouble ty = arg.GetNumber(5)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsMatrix, __TransformDistance, "TransformDistance")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, __TransformDistance)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble* dx = arg.GetNumber(0)
	//wxDouble* dy = arg.GetNumber(1)
	//pThis->GetEntity()->TransformDistance();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsMatrix, __TransformPoint, "TransformPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, __TransformPoint)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble* x = arg.GetNumber(0)
	//wxDouble* y = arg.GetNumber(1)
	//pThis->GetEntity()->TransformPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsMatrix, __Translate, "Translate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, __Translate)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble dx = arg.GetNumber(0)
	//wxDouble dy = arg.GetNumber(1)
	//pThis->GetEntity()->Translate();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGraphicsMatrix
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsMatrix)
{
	// Class assignment
	Gura_AssignValueEx("GraphicsMatrix", Reference());
	// Method assignment
	Gura_AssignMethod(wx_GraphicsMatrix, __Concat);
	Gura_AssignMethod(wx_GraphicsMatrix, __Concat_1);
	Gura_AssignMethod(wx_GraphicsMatrix, __Get);
	Gura_AssignMethod(wx_GraphicsMatrix, __GetNativeMatrix);
	Gura_AssignMethod(wx_GraphicsMatrix, __Invert);
	Gura_AssignMethod(wx_GraphicsMatrix, __IsEqual);
	Gura_AssignMethod(wx_GraphicsMatrix, __IsEqual_1);
	Gura_AssignMethod(wx_GraphicsMatrix, __IsIdentity);
	Gura_AssignMethod(wx_GraphicsMatrix, __Rotate);
	Gura_AssignMethod(wx_GraphicsMatrix, __Scale);
	Gura_AssignMethod(wx_GraphicsMatrix, __Set);
	Gura_AssignMethod(wx_GraphicsMatrix, __TransformDistance);
	Gura_AssignMethod(wx_GraphicsMatrix, __TransformPoint);
	Gura_AssignMethod(wx_GraphicsMatrix, __Translate);
}

Gura_ImplementDescendantCreator(wx_GraphicsMatrix)
{
	return new Object_wx_GraphicsMatrix((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
