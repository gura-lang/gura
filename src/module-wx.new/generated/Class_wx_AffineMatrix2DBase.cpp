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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__AffineMatrix2DBase, "AffineMatrix2DBase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AffineMatrix2DBase));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AffineMatrix2DBase)
{
	//wxAffineMatrix2DBase();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AffineMatrix2DBase, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mat2D", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, __Set)
{
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxMatrix2D& mat2D = arg.GetNumber(0)
	//const wxPoint2DDouble& tr = arg.GetNumber(1)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2DBase, __Get, "Get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mat2D", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, __Get)
{
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMatrix2D* mat2D = arg.GetNumber(0)
	//wxPoint2DDouble* tr = arg.GetNumber(1)
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2DBase, __Concat, "Concat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, __Concat)
{
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxAffineMatrix2DBase& t = arg.GetNumber(0)
	//pThis->GetEntity()->Concat();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2DBase, __Invert, "Invert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, __Invert)
{
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Invert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2DBase, __IsIdentity, "IsIdentity")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, __IsIdentity)
{
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsIdentity();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2DBase, __IsEqual, "IsEqual")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, __IsEqual)
{
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxAffineMatrix2DBase& t = arg.GetNumber(0)
	//pThis->GetEntity()->IsEqual();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2DBase, __Translate, "Translate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, __Translate)
{
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble dx = arg.GetNumber(0)
	//wxDouble dy = arg.GetNumber(1)
	//pThis->GetEntity()->Translate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2DBase, __Scale, "Scale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xScale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, __Scale)
{
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble xScale = arg.GetNumber(0)
	//wxDouble yScale = arg.GetNumber(1)
	//pThis->GetEntity()->Scale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2DBase, __Rotate, "Rotate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cRadians", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, __Rotate)
{
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble cRadians = arg.GetNumber(0)
	//pThis->GetEntity()->Rotate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2DBase, __Mirror, "Mirror")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, __Mirror)
{
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->Mirror();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2DBase, __TransformPoint, "TransformPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, __TransformPoint)
{
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DDouble& p = arg.GetNumber(0)
	//pThis->GetEntity()->TransformPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2DBase, __TransformPoint_1, "TransformPoint_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, __TransformPoint_1)
{
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble* x = arg.GetNumber(0)
	//wxDouble* y = arg.GetNumber(1)
	//pThis->GetEntity()->TransformPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2DBase, __TransformDistance, "TransformDistance")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, __TransformDistance)
{
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DDouble& p = arg.GetNumber(0)
	//pThis->GetEntity()->TransformDistance();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AffineMatrix2DBase, __TransformDistance_1, "TransformDistance_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, __TransformDistance_1)
{
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble* dx = arg.GetNumber(0)
	//wxDouble* dy = arg.GetNumber(1)
	//pThis->GetEntity()->TransformDistance();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAffineMatrix2DBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AffineMatrix2DBase)
{
	// Constructor assignment
	Gura_AssignFunction(__AffineMatrix2DBase);
	// Method assignment
	Gura_AssignMethod(wx_AffineMatrix2DBase, __Set);
	Gura_AssignMethod(wx_AffineMatrix2DBase, __Get);
	Gura_AssignMethod(wx_AffineMatrix2DBase, __Concat);
	Gura_AssignMethod(wx_AffineMatrix2DBase, __Invert);
	Gura_AssignMethod(wx_AffineMatrix2DBase, __IsIdentity);
	Gura_AssignMethod(wx_AffineMatrix2DBase, __IsEqual);
	Gura_AssignMethod(wx_AffineMatrix2DBase, __Translate);
	Gura_AssignMethod(wx_AffineMatrix2DBase, __Scale);
	Gura_AssignMethod(wx_AffineMatrix2DBase, __Rotate);
	Gura_AssignMethod(wx_AffineMatrix2DBase, __Mirror);
	Gura_AssignMethod(wx_AffineMatrix2DBase, __TransformPoint);
	Gura_AssignMethod(wx_AffineMatrix2DBase, __TransformPoint_1);
	Gura_AssignMethod(wx_AffineMatrix2DBase, __TransformDistance);
	Gura_AssignMethod(wx_AffineMatrix2DBase, __TransformDistance_1);
}

Gura_ImplementDescendantCreator(wx_AffineMatrix2DBase)
{
	return new Object_wx_AffineMatrix2DBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
