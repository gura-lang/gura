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
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, wxAffineMatrix2DBase)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAffineMatrix2DBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, ~wxAffineMatrix2DBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, ~wxAffineMatrix2DBase)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->~wxAffineMatrix2DBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, Get)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, Concat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, Concat)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Concat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, Invert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, Invert)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Invert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, IsIdentity)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, IsIdentity)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->IsIdentity();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, IsEqual)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, IsEqual)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->IsEqual();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, Translate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, Translate)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Translate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, Scale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, Scale)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Scale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, Rotate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, Rotate)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Rotate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, Mirror)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, Mirror)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Mirror();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, TransformPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, TransformPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->TransformPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, TransformPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, TransformPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->TransformPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, TransformDistance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, TransformDistance)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->TransformDistance();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AffineMatrix2DBase, TransformDistance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AffineMatrix2DBase, TransformDistance)
{
	Signal &sig = env.GetSignal();
	Object_wx_AffineMatrix2DBase *pThis = Object_wx_AffineMatrix2DBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->TransformDistance();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAffineMatrix2DBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AffineMatrix2DBase)
{
}

Gura_ImplementDescendantCreator(wx_AffineMatrix2DBase)
{
	return new Object_wx_AffineMatrix2DBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
