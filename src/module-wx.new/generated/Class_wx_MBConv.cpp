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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxMBConv, "wxMBConv")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MBConv));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxMBConv)
{
	//wxMBConv();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MBConv, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MBConv, __Clone)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __GetMBNulLen, "GetMBNulLen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MBConv, __GetMBNulLen)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMBNulLen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __GetMaxMBNulLen, "GetMaxMBNulLen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MBConv, __GetMaxMBNulLen)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaxMBNulLen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __ToWChar, "ToWChar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dst", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dstLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "srcLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __ToWChar)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dst = arg.GetNumber(0)
	//int dstLen = arg.GetNumber(1)
	//int src = arg.GetNumber(2)
	//int srcLen = arg.GetNumber(3)
	//pThis->GetEntity()->ToWChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __FromWChar, "FromWChar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dst", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dstLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "srcLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __FromWChar)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dst = arg.GetNumber(0)
	//int dstLen = arg.GetNumber(1)
	//int src = arg.GetNumber(2)
	//int srcLen = arg.GetNumber(3)
	//pThis->GetEntity()->FromWChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cMB2WC, "cMB2WC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "in", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "outLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cMB2WC)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int in = arg.GetNumber(0)
	//int inLen = arg.GetNumber(1)
	//int outLen = arg.GetNumber(2)
	//pThis->GetEntity()->cMB2WC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cMB2WC_1, "cMB2WC_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cMB2WC_1)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->cMB2WC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cMB2WX, "cMB2WX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cMB2WX)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//pThis->GetEntity()->cMB2WX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cMB2WX_1, "cMB2WX_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cMB2WX_1)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//pThis->GetEntity()->cMB2WX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cWC2MB, "cWC2MB")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "in", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "outLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cWC2MB)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int in = arg.GetNumber(0)
	//int inLen = arg.GetNumber(1)
	//int outLen = arg.GetNumber(2)
	//pThis->GetEntity()->cWC2MB();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cWC2MB_1, "cWC2MB_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cWC2MB_1)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->cWC2MB();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cWC2WX, "cWC2WX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cWC2WX)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//pThis->GetEntity()->cWC2WX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cWC2WX_1, "cWC2WX_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cWC2WX_1)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//pThis->GetEntity()->cWC2WX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cWX2MB, "cWX2MB")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cWX2MB)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//pThis->GetEntity()->cWX2MB();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cWX2MB_1, "cWX2MB_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cWX2MB_1)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//pThis->GetEntity()->cWX2MB();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cWX2WC, "cWX2WC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cWX2WC)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//pThis->GetEntity()->cWX2WC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cWX2WC_1, "cWX2WC_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cWX2WC_1)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//pThis->GetEntity()->cWX2WC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __MB2WC, "MB2WC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "out", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "in", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "outLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __MB2WC)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int out = arg.GetNumber(0)
	//int in = arg.GetNumber(1)
	//int outLen = arg.GetNumber(2)
	//pThis->GetEntity()->MB2WC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __WC2MB, "WC2MB")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __WC2MB)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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
	// Constructor assignment
	Gura_AssignFunction(__wxMBConv);
	// Method assignment
	Gura_AssignMethod(wx_MBConv, __Clone);
	Gura_AssignMethod(wx_MBConv, __GetMBNulLen);
	Gura_AssignMethod(wx_MBConv, __GetMaxMBNulLen);
	Gura_AssignMethod(wx_MBConv, __ToWChar);
	Gura_AssignMethod(wx_MBConv, __FromWChar);
	Gura_AssignMethod(wx_MBConv, __cMB2WC);
	Gura_AssignMethod(wx_MBConv, __cMB2WC_1);
	Gura_AssignMethod(wx_MBConv, __cMB2WX);
	Gura_AssignMethod(wx_MBConv, __cMB2WX_1);
	Gura_AssignMethod(wx_MBConv, __cWC2MB);
	Gura_AssignMethod(wx_MBConv, __cWC2MB_1);
	Gura_AssignMethod(wx_MBConv, __cWC2WX);
	Gura_AssignMethod(wx_MBConv, __cWC2WX_1);
	Gura_AssignMethod(wx_MBConv, __cWX2MB);
	Gura_AssignMethod(wx_MBConv, __cWX2MB_1);
	Gura_AssignMethod(wx_MBConv, __cWX2WC);
	Gura_AssignMethod(wx_MBConv, __cWX2WC_1);
	Gura_AssignMethod(wx_MBConv, __MB2WC);
	Gura_AssignMethod(wx_MBConv, __WC2MB);
}

Gura_ImplementDescendantCreator(wx_MBConv)
{
	return new Object_wx_MBConv((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
