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
	//Gura::Signal *_pSig;
	Object_wx_CSConv *_pObj;
public:
	inline wx_CSConv(const wxChar* charset) : wxCSConv(charset), _pObj(nullptr) {}
	inline wx_CSConv(wxFontEncoding encoding) : wxCSConv(encoding), _pObj(nullptr) {}
	~wx_CSConv();
	inline void AssocWithGura(Object_wx_CSConv *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CSConv::~wx_CSConv()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_CSConv::GuraObjectDeleted()
{
	_pObj = nullptr;
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString charset = wxString::FromUTF8(arg.GetString(0));
	wx_CSConv *pEntity = new wx_CSConv(charset);
	Object_wx_CSConv *pObj = Object_wx_CSConv::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_CSConv(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxFontEncoding encoding = static_cast<wxFontEncoding>(arg.GetInt(0));
	wx_CSConv *pEntity = new wx_CSConv(encoding);
	Object_wx_CSConv *pObj = Object_wx_CSConv::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_CSConv(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_CSConv, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CSConv, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_CSConv *pThis = Object_wx_CSConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, arg, Value(rtn));
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CSConv *pThis = Object_wx_CSConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wchar_t buf = static_cast<wchar_t>(arg.GetUShort(0));
	char psz = arg.GetChar(1);
	size_t n = arg.GetSizeT(2);
	size_t rtn = pThis->GetEntity()->MB2WC(buf, psz, n);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CSConv *pThis = Object_wx_CSConv::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	char buf = arg.GetChar(0);
	wchar_t psz = static_cast<wchar_t>(arg.GetUShort(1));
	size_t n = arg.GetSizeT(2);
	size_t rtn = pThis->GetEntity()->WC2MB(buf, psz, n);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxCSConv
//----------------------------------------------------------------------------
Object_wx_CSConv::~Object_wx_CSConv()
{
}

Object *Object_wx_CSConv::Clone() const
{
	return nullptr;
}

String Object_wx_CSConv::ToString(bool exprFlag)
{
	String rtn("<wx.CSConv:");
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
	return new Object_wx_CSConv((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
