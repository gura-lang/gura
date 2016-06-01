//----------------------------------------------------------------------------
// wxMBConv
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMBConv
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMBConv
//----------------------------------------------------------------------------
Object_wx_MBConv::~Object_wx_MBConv()
{
}

Object *Object_wx_MBConv::Clone() const
{
	return nullptr;
}

String Object_wx_MBConv::ToString(bool exprFlag)
{
	String rtn("<wx.MBConv:");
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
Gura_DeclareMethod(wx_MBConv, wxMBConv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MBConv, wxMBConv)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxMBConv();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MBConv, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, GetMBNulLen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MBConv, GetMBNulLen)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMBNulLen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, GetMaxMBNulLen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MBConv, GetMaxMBNulLen)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMaxMBNulLen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, ToWChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dst", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dstLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "srcLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, ToWChar)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dst = arg.GetNumber(0)
	//int dstLen = arg.GetNumber(1)
	//int src = arg.GetNumber(2)
	//int srcLen = arg.GetNumber(3)
	//pThis->GetEntity()->ToWChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, FromWChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dst", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dstLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "srcLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, FromWChar)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dst = arg.GetNumber(0)
	//int dstLen = arg.GetNumber(1)
	//int src = arg.GetNumber(2)
	//int srcLen = arg.GetNumber(3)
	//pThis->GetEntity()->FromWChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, cMB2WC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "in", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "outLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, cMB2WC)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int in = arg.GetNumber(0)
	//int inLen = arg.GetNumber(1)
	//int outLen = arg.GetNumber(2)
	//pThis->GetEntity()->cMB2WC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, cMB2WC_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, cMB2WC_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->cMB2WC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, cMB2WX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, cMB2WX)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//pThis->GetEntity()->cMB2WX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, cMB2WX_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, cMB2WX_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//pThis->GetEntity()->cMB2WX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, cWC2MB)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "in", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "outLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, cWC2MB)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int in = arg.GetNumber(0)
	//int inLen = arg.GetNumber(1)
	//int outLen = arg.GetNumber(2)
	//pThis->GetEntity()->cWC2MB();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, cWC2MB_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, cWC2MB_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->cWC2MB();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, cWC2WX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, cWC2WX)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//pThis->GetEntity()->cWC2WX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, cWC2WX_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, cWC2WX_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//pThis->GetEntity()->cWC2WX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, cWX2MB)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, cWX2MB)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//pThis->GetEntity()->cWX2MB();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, cWX2MB_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, cWX2MB_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//pThis->GetEntity()->cWX2MB();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, cWX2WC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, cWX2WC)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//pThis->GetEntity()->cWX2WC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, cWX2WC_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, cWX2WC_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//pThis->GetEntity()->cWX2WC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, MB2WC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "out", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "in", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "outLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, MB2WC)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int out = arg.GetNumber(0)
	//int in = arg.GetNumber(1)
	//int outLen = arg.GetNumber(2)
	//pThis->GetEntity()->MB2WC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MBConv, WC2MB)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, WC2MB)
{
	Signal &sig = env.GetSignal();
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//int psz = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->WC2MB();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMBConv
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MBConv)
{
	Gura_AssignMethod(wx_MBConv, wxMBConv);
	Gura_AssignMethod(wx_MBConv, Clone);
	Gura_AssignMethod(wx_MBConv, GetMBNulLen);
	Gura_AssignMethod(wx_MBConv, GetMaxMBNulLen);
	Gura_AssignMethod(wx_MBConv, ToWChar);
	Gura_AssignMethod(wx_MBConv, FromWChar);
	Gura_AssignMethod(wx_MBConv, cMB2WC);
	Gura_AssignMethod(wx_MBConv, cMB2WC_1);
	Gura_AssignMethod(wx_MBConv, cMB2WX);
	Gura_AssignMethod(wx_MBConv, cMB2WX_1);
	Gura_AssignMethod(wx_MBConv, cWC2MB);
	Gura_AssignMethod(wx_MBConv, cWC2MB_1);
	Gura_AssignMethod(wx_MBConv, cWC2WX);
	Gura_AssignMethod(wx_MBConv, cWC2WX_1);
	Gura_AssignMethod(wx_MBConv, cWX2MB);
	Gura_AssignMethod(wx_MBConv, cWX2MB_1);
	Gura_AssignMethod(wx_MBConv, cWX2WC);
	Gura_AssignMethod(wx_MBConv, cWX2WC_1);
	Gura_AssignMethod(wx_MBConv, MB2WC);
	Gura_AssignMethod(wx_MBConv, WC2MB);
}

Gura_ImplementDescendantCreator(wx_MBConv)
{
	return new Object_wx_MBConv((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
