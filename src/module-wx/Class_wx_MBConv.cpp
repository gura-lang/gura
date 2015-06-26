//----------------------------------------------------------------------------
// wxMBConv
// extracted from mbconv.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(MB2WC);
Gura_DeclarePrivUserSymbol(WC2MB);
Gura_DeclarePrivUserSymbol(FromWChar);
Gura_DeclarePrivUserSymbol(ToWChar);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MBConv: public wxMBConv, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MBConv *_pObj;
public:
	//inline wx_MBConv() : wxMBConv(), _sig(nullptr), _pObj(nullptr) {}
	//virtual size_t MB2WC(wchar_t * out, const char * in, size_t outLen);
	//virtual size_t WC2MB(char* buf, const wchar_t* psz, size_t n);
	//virtual size_t FromWChar(char_t * dst, size_t dstLen, const wchar_t * src, size_t srcLen);
	//virtual size_t ToWChar(wchar_t * dst, size_t dstLen, const char_t * src, size_t srcLen);
	~wx_MBConv();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MBConv *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MBConv::~wx_MBConv()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MBConv::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMBConv
//----------------------------------------------------------------------------
#if 0
Gura_DeclareFunction(MBConvEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_MBConv));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(MBConvEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_MBConv *pEntity = new wx_MBConv();
	Object_wx_MBConv *pObj = Object_wx_MBConv::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_MBConv(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_MBConv, MB2WC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "out", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "in", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "outLen", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConv, MB2WC)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wchar_t out = static_cast<wchar_t>(args.GetUShort(0));
	char in = args.GetChar(1);
	size_t outLen = args.GetSizeT(2);
	size_t rtn = pThis->GetEntity()->MB2WC(out, in, outLen);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MBConv, WC2MB)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConv, WC2MB)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char buf = args.GetChar(0);
	wchar_t psz = static_cast<wchar_t>(args.GetUShort(1));
	size_t n = args.GetSizeT(2);
	size_t rtn = pThis->GetEntity()->WC2MB(buf, psz, n);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MBConv, cMB2WC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "in", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConv, cMB2WC)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char in = args.GetChar(0);
	wxWCharBuffer rtn = pThis->GetEntity()->cMB2WC(in);
	return ReturnValue(env, sig, args, Value(new Object_wx_WCharBuffer(new wxWCharBuffer(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_MBConv, cMB2WC_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "in", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "inLen", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*outLen", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConv, cMB2WC_1)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char in = args.GetChar(0);
	size_t inLen = args.GetSizeT(1);
	size_t *outLen = args.GetSizeT(2);
	wxWCharBuffer rtn = pThis->GetEntity()->cMB2WC(in, inLen, *outLen);
	return ReturnValue(env, sig, args, Value(new Object_wx_WCharBuffer(new wxWCharBuffer(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_MBConv, cWC2MB)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "in", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConv, cWC2MB)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wchar_t in = static_cast<wchar_t>(args.GetUShort(0));
	wxCharBuffer rtn = pThis->GetEntity()->cWC2MB(in);
	return ReturnValue(env, sig, args, Value(new Object_wx_CharBuffer(new wxCharBuffer(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_MBConv, cWC2MB_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "in", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "inLen", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*outLen", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConv, cWC2MB_1)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wchar_t in = static_cast<wchar_t>(args.GetUShort(0));
	size_t inLen = args.GetSizeT(1);
	size_t *outLen = args.GetSizeT(2);
	wxCharBuffer rtn = pThis->GetEntity()->cWC2MB(in, inLen, *outLen);
	return ReturnValue(env, sig, args, Value(new Object_wx_CharBuffer(new wxCharBuffer(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_MBConv, cMB2WX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConv, cMB2WX)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char psz = args.GetChar(0);
	char rtn = pThis->GetEntity()->cMB2WX(psz);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MBConv, cMB2WX_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConv, cMB2WX_1)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char psz = args.GetChar(0);
	wxWCharBuffer rtn = pThis->GetEntity()->cMB2WX(psz);
	return ReturnValue(env, sig, args, Value(new Object_wx_WCharBuffer(new wxWCharBuffer(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_MBConv, cWX2MB)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "psz", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConv, cWX2MB)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString psz = wxString::FromUTF8(args.GetString(0));
	char rtn = pThis->GetEntity()->cWX2MB(psz);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MBConv, cWX2MB_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "psz", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConv, cWX2MB_1)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString psz = wxString::FromUTF8(args.GetString(0));
	wxCharBuffer rtn = pThis->GetEntity()->cWX2MB(psz);
	return ReturnValue(env, sig, args, Value(new Object_wx_CharBuffer(new wxCharBuffer(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_MBConv, cWC2WX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConv, cWC2WX)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wchar_t psz = static_cast<wchar_t>(args.GetUShort(0));
	wchar_t rtn = pThis->GetEntity()->cWC2WX(psz);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MBConv, cWC2WX_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConv, cWC2WX_1)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wchar_t psz = static_cast<wchar_t>(args.GetUShort(0));
	wxCharBuffer rtn = pThis->GetEntity()->cWC2WX(psz);
	return ReturnValue(env, sig, args, Value(new Object_wx_CharBuffer(new wxCharBuffer(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_MBConv, cWX2WC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "psz", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConv, cWX2WC)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString psz = wxString::FromUTF8(args.GetString(0));
	wchar_t rtn = pThis->GetEntity()->cWX2WC(psz);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MBConv, cWX2WC_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "psz", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConv, cWX2WC_1)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString psz = wxString::FromUTF8(args.GetString(0));
	wxWCharBuffer rtn = pThis->GetEntity()->cWX2WC(psz);
	return ReturnValue(env, sig, args, Value(new Object_wx_WCharBuffer(new wxWCharBuffer(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_MBConv, FromWChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dstLen", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "srcLen", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConv, FromWChar)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t dstLen = args.GetSizeT(1);
	wchar_t src = static_cast<wchar_t>(args.GetUShort(2));
	size_t srcLen = wxNO_LEN;
	if (args.IsValid(3)) srcLen = args.GetSizeT(3);
	size_t rtn = pThis->GetEntity()->FromWChar(, dstLen, src, srcLen);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MBConv, GetMaxMBNulLen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConv, GetMaxMBNulLen)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetMaxMBNulLen();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MBConv, GetMBNulLen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConv, GetMBNulLen)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetMBNulLen();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MBConv, ToWChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dst", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "dstLen", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "srcLen", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MBConv, ToWChar)
{
	Object_wx_MBConv *pThis = Object_wx_MBConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wchar_t dst = static_cast<wchar_t>(args.GetUShort(0));
	size_t dstLen = args.GetSizeT(1);
	size_t srcLen = wxNO_LEN;
	if (args.IsValid(3)) srcLen = args.GetSizeT(3);
	size_t rtn = pThis->GetEntity()->ToWChar(dst, dstLen, , srcLen);
	return ReturnValue(env, sig, args, Value(rtn));
}
#endif

//----------------------------------------------------------------------------
// Object implementation for wxMBConv
//----------------------------------------------------------------------------
Object_wx_MBConv::~Object_wx_MBConv()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
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
// Class implementation for wxMBConv
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MBConv)
{
	Gura_RealizeUserSymbol(MB2WC);
	Gura_RealizeUserSymbol(WC2MB);
	Gura_RealizeUserSymbol(FromWChar);
	Gura_RealizeUserSymbol(ToWChar);
	//Gura_AssignFunction(MBConvEmpty);
#if 0
	Gura_AssignMethod(wx_MBConv, MB2WC);
	Gura_AssignMethod(wx_MBConv, WC2MB);
	Gura_AssignMethod(wx_MBConv, cMB2WC);
	Gura_AssignMethod(wx_MBConv, cMB2WC_1);
	Gura_AssignMethod(wx_MBConv, cWC2MB);
	Gura_AssignMethod(wx_MBConv, cWC2MB_1);
	Gura_AssignMethod(wx_MBConv, cMB2WX);
	Gura_AssignMethod(wx_MBConv, cMB2WX_1);
	Gura_AssignMethod(wx_MBConv, cWX2MB);
	Gura_AssignMethod(wx_MBConv, cWX2MB_1);
	Gura_AssignMethod(wx_MBConv, cWC2WX);
	Gura_AssignMethod(wx_MBConv, cWC2WX_1);
	Gura_AssignMethod(wx_MBConv, cWX2WC);
	Gura_AssignMethod(wx_MBConv, cWX2WC_1);
	Gura_AssignMethod(wx_MBConv, FromWChar);
	Gura_AssignMethod(wx_MBConv, GetMaxMBNulLen);
	Gura_AssignMethod(wx_MBConv, GetMBNulLen);
	Gura_AssignMethod(wx_MBConv, ToWChar);
#endif
}

Gura_ImplementDescendantCreator(wx_MBConv)
{
	return new Object_wx_MBConv((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
