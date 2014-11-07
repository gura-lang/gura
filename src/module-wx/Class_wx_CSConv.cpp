//----------------------------------------------------------------------------
// wxCSConv
// extracted from csconv.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CSConv: public wxCSConv, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_CSConv *_pObj;
public:
	inline wx_CSConv(const wxChar* charset) : wxCSConv(charset), _sig(NULL), _pObj(NULL) {}
	inline wx_CSConv(wxFontEncoding encoding) : wxCSConv(encoding), _sig(NULL), _pObj(NULL) {}
	~wx_CSConv();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_CSConv *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CSConv::~wx_CSConv()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_CSConv::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCSConv
//----------------------------------------------------------------------------
Gura_DeclareFunction(CSConv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_CSConv));
	DeclareArg(env, "charset", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CSConv)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString charset = wxString::FromUTF8(args.GetString(0));
	wx_CSConv *pEntity = new wx_CSConv(charset);
	Object_wx_CSConv *pObj = Object_wx_CSConv::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CSConv(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(CSConv_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_CSConv));
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CSConv_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxFontEncoding encoding = static_cast<wxFontEncoding>(args.GetInt(0));
	wx_CSConv *pEntity = new wx_CSConv(encoding);
	Object_wx_CSConv *pObj = Object_wx_CSConv::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CSConv(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_CSConv, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CSConv, IsOk)
{
	Object_wx_CSConv *pThis = Object_wx_CSConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CSConv, MB2WC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CSConv, MB2WC)
{
#if 0
	Object_wx_CSConv *pThis = Object_wx_CSConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wchar_t buf = static_cast<wchar_t>(args.GetUShort(0));
	char psz = args.GetChar(1);
	size_t n = args.GetSizeT(2);
	size_t rtn = pThis->GetEntity()->MB2WC(buf, psz, n);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CSConv, WC2MB)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CSConv, WC2MB)
{
#if 0
	Object_wx_CSConv *pThis = Object_wx_CSConv::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char buf = args.GetChar(0);
	wchar_t psz = static_cast<wchar_t>(args.GetUShort(1));
	size_t n = args.GetSizeT(2);
	size_t rtn = pThis->GetEntity()->WC2MB(buf, psz, n);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxCSConv
//----------------------------------------------------------------------------
Object_wx_CSConv::~Object_wx_CSConv()
{
}

Object *Object_wx_CSConv::Clone() const
{
	return NULL;
}

String Object_wx_CSConv::ToString(bool exprFlag)
{
	String rtn("<wx.CSConv:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxCSConv
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CSConv)
{
	Gura_AssignFunction(CSConv);
	Gura_AssignFunction(CSConv_1);
	Gura_AssignMethod(wx_CSConv, IsOk);
	Gura_AssignMethod(wx_CSConv, MB2WC);
	Gura_AssignMethod(wx_CSConv, WC2MB);
}

Gura_ImplementDescendantCreator(wx_CSConv)
{
	return new Object_wx_CSConv((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
