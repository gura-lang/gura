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
Gura_DeclareMethod(wx_GraphicsMatrix, Concat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, Concat)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int t = arg.GetNumber(0)
	//pThis->GetEntity()->Concat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsMatrix, Concat_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, Concat_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int t = arg.GetNumber(0)
	//pThis->GetEntity()->Concat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsMatrix, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "a", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ty", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, Get)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int a = arg.GetNumber(0)
	//int b = arg.GetNumber(1)
	//int c = arg.GetNumber(2)
	//int d = arg.GetNumber(3)
	//int tx = arg.GetNumber(4)
	//int ty = arg.GetNumber(5)
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsMatrix, GetNativeMatrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsMatrix, GetNativeMatrix)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNativeMatrix();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsMatrix, Invert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsMatrix, Invert)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Invert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsMatrix, IsEqual)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, IsEqual)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int t = arg.GetNumber(0)
	//pThis->GetEntity()->IsEqual();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsMatrix, IsEqual_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, IsEqual_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int t = arg.GetNumber(0)
	//pThis->GetEntity()->IsEqual();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsMatrix, IsIdentity)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsMatrix, IsIdentity)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsIdentity();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsMatrix, Rotate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, Rotate)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int angle = arg.GetNumber(0)
	//pThis->GetEntity()->Rotate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsMatrix, Scale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xScale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, Scale)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int xScale = arg.GetNumber(0)
	//int yScale = arg.GetNumber(1)
	//pThis->GetEntity()->Scale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsMatrix, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "a", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ty", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int a = arg.GetNumber(0)
	//int b = arg.GetNumber(1)
	//int c = arg.GetNumber(2)
	//int d = arg.GetNumber(3)
	//int tx = arg.GetNumber(4)
	//int ty = arg.GetNumber(5)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsMatrix, TransformDistance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, TransformDistance)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->TransformDistance();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsMatrix, TransformPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, TransformPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->TransformPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsMatrix, Translate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, Translate)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->Translate();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGraphicsMatrix
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsMatrix)
{
	Gura_AssignMethod(wx_GraphicsMatrix, Concat);
	Gura_AssignMethod(wx_GraphicsMatrix, Concat_1);
	Gura_AssignMethod(wx_GraphicsMatrix, Get);
	Gura_AssignMethod(wx_GraphicsMatrix, GetNativeMatrix);
	Gura_AssignMethod(wx_GraphicsMatrix, Invert);
	Gura_AssignMethod(wx_GraphicsMatrix, IsEqual);
	Gura_AssignMethod(wx_GraphicsMatrix, IsEqual_1);
	Gura_AssignMethod(wx_GraphicsMatrix, IsIdentity);
	Gura_AssignMethod(wx_GraphicsMatrix, Rotate);
	Gura_AssignMethod(wx_GraphicsMatrix, Scale);
	Gura_AssignMethod(wx_GraphicsMatrix, Set);
	Gura_AssignMethod(wx_GraphicsMatrix, TransformDistance);
	Gura_AssignMethod(wx_GraphicsMatrix, TransformPoint);
	Gura_AssignMethod(wx_GraphicsMatrix, Translate);
}

Gura_ImplementDescendantCreator(wx_GraphicsMatrix)
{
	return new Object_wx_GraphicsMatrix((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
