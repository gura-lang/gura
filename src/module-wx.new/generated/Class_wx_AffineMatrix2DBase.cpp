//----------------------------------------------------------------------------
// wxAffineMatrix2DBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAffineMatrix2DBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAffineMatrix2DBase
//----------------------------------------------------------------------------
Object_wx_AffineMatrix2DBase::~Object_wx_AffineMatrix2DBase()
{
}

Object *Object_wx_AffineMatrix2DBase::Clone() const
{
	return nullptr;
}

String Object_wx_AffineMatrix2DBase::ToString(bool exprFlag)
{
	String rtn("<wx.AffineMatrix2DBase:");
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
Gura_DeclareMethod(wx_AffineMatrix2DBase, wxAffineMatrix2DBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, wxAffineMatrix2DBase)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxAffineMatrix2DBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, ~wxAffineMatrix2DBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, ~wxAffineMatrix2DBase)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxAffineMatrix2DBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mat2D", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mat2D = arg.GetNumber(0)
	//int tr = arg.GetNumber(1)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mat2D", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, Get)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mat2D = arg.GetNumber(0)
	//int tr = arg.GetNumber(1)
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, Concat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, Concat)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int t = arg.GetNumber(0)
	//pThis->GetEntity()->Concat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, Invert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, Invert)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Invert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, IsIdentity)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, IsIdentity)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsIdentity();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, IsEqual)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, IsEqual)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int t = arg.GetNumber(0)
	//pThis->GetEntity()->IsEqual();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, Translate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, Translate)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->Translate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, Scale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xScale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, Scale)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int xScale = arg.GetNumber(0)
	//int yScale = arg.GetNumber(1)
	//pThis->GetEntity()->Scale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, Rotate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cRadians", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, Rotate)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cRadians = arg.GetNumber(0)
	//pThis->GetEntity()->Rotate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, Mirror)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, Mirror)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->Mirror();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, TransformPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, TransformPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->TransformPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, TransformPoint_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, TransformPoint_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->TransformPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, TransformDistance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, TransformDistance)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->TransformDistance();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, TransformDistance_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, TransformDistance_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->TransformDistance();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAffineMatrix2DBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AffineMatrix2DBase)
{
	Gura_AssignMethod(wx_AffineMatrix2DBase, wxAffineMatrix2DBase);
	Gura_AssignMethod(wx_AffineMatrix2DBase, ~wxAffineMatrix2DBase);
	Gura_AssignMethod(wx_AffineMatrix2DBase, Set);
	Gura_AssignMethod(wx_AffineMatrix2DBase, Get);
	Gura_AssignMethod(wx_AffineMatrix2DBase, Concat);
	Gura_AssignMethod(wx_AffineMatrix2DBase, Invert);
	Gura_AssignMethod(wx_AffineMatrix2DBase, IsIdentity);
	Gura_AssignMethod(wx_AffineMatrix2DBase, IsEqual);
	Gura_AssignMethod(wx_AffineMatrix2DBase, Translate);
	Gura_AssignMethod(wx_AffineMatrix2DBase, Scale);
	Gura_AssignMethod(wx_AffineMatrix2DBase, Rotate);
	Gura_AssignMethod(wx_AffineMatrix2DBase, Mirror);
	Gura_AssignMethod(wx_AffineMatrix2DBase, TransformPoint);
	Gura_AssignMethod(wx_AffineMatrix2DBase, TransformPoint_1);
	Gura_AssignMethod(wx_AffineMatrix2DBase, TransformDistance);
	Gura_AssignMethod(wx_AffineMatrix2DBase, TransformDistance_1);
}

Gura_ImplementDescendantCreator(wx_AffineMatrix2DBase)
{
	return new Object_wx_AffineMatrix2DBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
