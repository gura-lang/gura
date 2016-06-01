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
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, wxAffineMatrix2D)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAffineMatrix2D();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, Get)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, Concat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, Concat)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Concat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, Invert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, Invert)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Invert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, IsIdentity)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, IsIdentity)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->IsIdentity();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, IsEqual)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, IsEqual)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->IsEqual();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, Translate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, Translate)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Translate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, Scale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, Scale)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Scale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, Mirror)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, Mirror)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Mirror();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, Rotate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, Rotate)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Rotate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, TransformPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, TransformPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->TransformPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, TransformPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, TransformPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->TransformPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, TransformDistance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, TransformDistance)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->TransformDistance();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2D, TransformDistance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2D, TransformDistance)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2D *pThis = Object_wx_AffineMatrix2D::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->TransformDistance();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAffineMatrix2D
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AffineMatrix2D)
{
}

Gura_ImplementDescendantCreator(wx_AffineMatrix2D)
{
	return new Object_wx_AffineMatrix2D((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
