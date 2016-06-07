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
Gura_DeclareFunctionAlias(__MBConv, "MBConv")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MBConv));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MBConv)
{
	//wxMBConv();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MBConv, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MBConv, __Clone)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMBConv* _rtn = pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __GetMBNulLen, "GetMBNulLen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MBConv, __GetMBNulLen)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetMBNulLen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __GetMaxMBNulLen, "GetMaxMBNulLen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MBConv, __GetMaxMBNulLen)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetMaxMBNulLen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __ToWChar, "ToWChar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dst", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dstLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "srcLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __ToWChar)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wchar_t* dst = arg.GetNumber(0)
	//size_t dstLen = arg.GetNumber(1)
	//const char* src = arg.GetNumber(2)
	//size_t srcLen = arg.GetNumber(3)
	//size_t _rtn = pThis->GetEntity()->ToWChar(dst, dstLen, src, srcLen);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __FromWChar, "FromWChar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dst", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dstLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "srcLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __FromWChar)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//char* dst = arg.GetNumber(0)
	//size_t dstLen = arg.GetNumber(1)
	//const wchar_t* src = arg.GetNumber(2)
	//size_t srcLen = arg.GetNumber(3)
	//size_t _rtn = pThis->GetEntity()->FromWChar(dst, dstLen, src, srcLen);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cMB2WC, "cMB2WC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "in", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "outLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cMB2WC)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* in = arg.GetNumber(0)
	//size_t inLen = arg.GetNumber(1)
	//size_t* outLen = arg.GetNumber(2)
	//const wxWCharBuffer _rtn = pThis->GetEntity()->cMB2WC(in, inLen, outLen);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cMB2WC_1, "cMB2WC_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cMB2WC_1)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxCharBuffer& buf = arg.GetNumber(0)
	//const wxWCharBuffer _rtn = pThis->GetEntity()->cMB2WC(buf);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cMB2WX, "cMB2WX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cMB2WX)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* psz = arg.GetNumber(0)
	//const char* _rtn = pThis->GetEntity()->cMB2WX(psz);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cMB2WX_1, "cMB2WX_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cMB2WX_1)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* psz = arg.GetNumber(0)
	//const wxWCharBuffer _rtn = pThis->GetEntity()->cMB2WX(psz);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cWC2MB, "cWC2MB")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "in", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "outLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cWC2MB)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* in = arg.GetNumber(0)
	//size_t inLen = arg.GetNumber(1)
	//size_t* outLen = arg.GetNumber(2)
	//const wxCharBuffer _rtn = pThis->GetEntity()->cWC2MB(in, inLen, outLen);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cWC2MB_1, "cWC2MB_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cWC2MB_1)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxWCharBuffer& buf = arg.GetNumber(0)
	//const wxCharBuffer _rtn = pThis->GetEntity()->cWC2MB(buf);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cWC2WX, "cWC2WX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cWC2WX)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* psz = arg.GetNumber(0)
	//const wchar_t* _rtn = pThis->GetEntity()->cWC2WX(psz);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cWC2WX_1, "cWC2WX_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cWC2WX_1)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* psz = arg.GetNumber(0)
	//const wxCharBuffer _rtn = pThis->GetEntity()->cWC2WX(psz);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cWX2MB, "cWX2MB")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cWX2MB)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxChar* psz = arg.GetNumber(0)
	//const char* _rtn = pThis->GetEntity()->cWX2MB(psz);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cWX2MB_1, "cWX2MB_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cWX2MB_1)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxChar* psz = arg.GetNumber(0)
	//const wxCharBuffer _rtn = pThis->GetEntity()->cWX2MB(psz);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cWX2WC, "cWX2WC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cWX2WC)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxChar* psz = arg.GetNumber(0)
	//const wchar_t* _rtn = pThis->GetEntity()->cWX2WC(psz);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __cWX2WC_1, "cWX2WC_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __cWX2WC_1)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxChar* psz = arg.GetNumber(0)
	//const wxWCharBuffer _rtn = pThis->GetEntity()->cWX2WC(psz);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __MB2WC, "MB2WC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "out", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "in", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "outLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __MB2WC)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wchar_t* out = arg.GetNumber(0)
	//const char* in = arg.GetNumber(1)
	//size_t outLen = arg.GetNumber(2)
	//size_t _rtn = pThis->GetEntity()->MB2WC(out, in, outLen);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MBConv, __WC2MB, "WC2MB")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MBConv, __WC2MB)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//char* buf = arg.GetNumber(0)
	//const wchar_t* psz = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//size_t _rtn = pThis->GetEntity()->WC2MB(buf, psz, n);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMBConv
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MBConv)
{
	// Constructor assignment
	Gura_AssignFunction(__MBConv);
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
