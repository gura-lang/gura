//----------------------------------------------------------------------------
// wxLongLong
// extracted from longlong.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_LongLong: public wxLongLong, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_LongLong *_pObj;
public:
	//inline wx_LongLong() : wxLongLong(), _sig(NULL), _pObj(NULL) {}
	//inline wx_LongLong(wxLongLong_t ll) : wxLongLong(ll), _sig(NULL), _pObj(NULL) {}
	//inline wx_LongLong(long hi, unsigned long lo) : wxLongLong(hi, lo), _sig(NULL), _pObj(NULL) {}
	~wx_LongLong();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_LongLong *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LongLong::~wx_LongLong()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_LongLong::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLongLong
//----------------------------------------------------------------------------
Gura_DeclareFunction(LongLongEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_LongLong));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(LongLongEmpty)
{
#if 0
	wx_LongLong *pEntity = new wx_LongLong();
	Object_wx_LongLong *pObj = Object_wx_LongLong::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_LongLong(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(LongLong)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_LongLong));
	DeclareArg(env, "ll", VTYPE_wx_LongLong_t, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(LongLong)
{
#if 0
	wxLongLong_t *ll = Object_wx_LongLong_t::GetObject(args, 0)->GetEntity();
	wx_LongLong *pEntity = new wx_LongLong(*ll);
	Object_wx_LongLong *pObj = Object_wx_LongLong::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_LongLong(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(LongLong_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_LongLong));
	DeclareArg(env, "hi", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "lo", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(LongLong_1)
{
#if 0
	long hi = args.GetLong(0);
	unsigned lo = args.GetInt(1);
	wx_LongLong *pEntity = new wx_LongLong(hi, lo);
	Object_wx_LongLong *pObj = Object_wx_LongLong::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_LongLong(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_LongLong, Abs)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LongLong, Abs)
{
#if 0
	Object_wx_LongLong *pSelf = Object_wx_LongLong::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxLongLong rtn = pSelf->GetEntity()->Abs();
	return ReturnValue(env, sig, args, Value(new Object_wx_LongLong(new wxLongLong(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_LongLong, Abs_1)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LongLong, Abs_1)
{
	Object_wx_LongLong *pSelf = Object_wx_LongLong::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxLongLong &rtn = pSelf->GetEntity()->Abs();
	return ReturnValue(env, sig, args, Value(new Object_wx_LongLong(new wxLongLong(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_LongLong, Assign)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LongLong, Assign)
{
#if 0
	Object_wx_LongLong *pSelf = Object_wx_LongLong::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	double d = args.GetDouble(0);
	wxLongLong &rtn = pSelf->GetEntity()->Assign(d);
	return ReturnValue(env, sig, args, Value(new Object_wx_LongLong(new wxLongLong(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_LongLong, GetHi)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LongLong, GetHi)
{
	Object_wx_LongLong *pSelf = Object_wx_LongLong::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetHi();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_LongLong, GetLo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LongLong, GetLo)
{
	Object_wx_LongLong *pSelf = Object_wx_LongLong::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pSelf->GetEntity()->GetLo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_LongLong, GetValue)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LongLong, GetValue)
{
#if 0
	Object_wx_LongLong *pSelf = Object_wx_LongLong::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxLongLong_t rtn = pSelf->GetEntity()->GetValue();
	return ReturnValue(env, sig, args, Value(new Object_wx_LongLong_t(new wxLongLong_t(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_LongLong, ToDouble)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LongLong, ToDouble)
{
	Object_wx_LongLong *pSelf = Object_wx_LongLong::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	double rtn = pSelf->GetEntity()->ToDouble();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_LongLong, ToLong)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LongLong, ToLong)
{
	Object_wx_LongLong *pSelf = Object_wx_LongLong::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->ToLong();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_LongLong, ToString)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LongLong, ToString)
{
	Object_wx_LongLong *pSelf = Object_wx_LongLong::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->ToString();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxLongLong
//----------------------------------------------------------------------------
Object_wx_LongLong::~Object_wx_LongLong()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_LongLong::Clone() const
{
	return NULL;
}

String Object_wx_LongLong::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.LongLong:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_LongLong::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(LongLongEmpty);
	Gura_AssignFunction(LongLong);
	Gura_AssignFunction(LongLong_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxLongLong
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LongLong)
{
	Gura_AssignMethod(wx_LongLong, Abs);
	Gura_AssignMethod(wx_LongLong, Abs_1);
	Gura_AssignMethod(wx_LongLong, Assign);
	Gura_AssignMethod(wx_LongLong, GetHi);
	Gura_AssignMethod(wx_LongLong, GetLo);
	Gura_AssignMethod(wx_LongLong, GetValue);
	Gura_AssignMethod(wx_LongLong, ToDouble);
	Gura_AssignMethod(wx_LongLong, ToLong);
	Gura_AssignMethod(wx_LongLong, ToString);
}

Gura_ImplementDescendantCreator(wx_LongLong)
{
	return new Object_wx_LongLong((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
