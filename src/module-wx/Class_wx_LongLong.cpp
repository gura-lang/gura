//----------------------------------------------------------------------------
// wxLongLong
// extracted from longlong.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_LongLong: public wxLongLong, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_LongLong *_pObj;
public:
	//inline wx_LongLong() : wxLongLong(), _pObj(nullptr) {}
	//inline wx_LongLong(wxLongLong_t ll) : wxLongLong(ll), _pObj(nullptr) {}
	//inline wx_LongLong(long hi, unsigned long lo) : wxLongLong(hi, lo), _pObj(nullptr) {}
	~wx_LongLong();
	inline void AssocWithGura(Object_wx_LongLong *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LongLong::~wx_LongLong()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_LongLong::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLongLong
//----------------------------------------------------------------------------
Gura_DeclareFunction(LongLongEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_LongLong));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(LongLongEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_LongLong *pEntity = new wx_LongLong();
	Object_wx_LongLong *pObj = Object_wx_LongLong::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_LongLong(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(LongLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_LongLong));
	DeclareArg(env, "ll", VTYPE_wx_LongLong_t, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(LongLong)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxLongLong_t *ll = Object_wx_LongLong_t::GetObject(args, 0)->GetEntity();
	wx_LongLong *pEntity = new wx_LongLong(*ll);
	Object_wx_LongLong *pObj = Object_wx_LongLong::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_LongLong(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(LongLong_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_LongLong));
	DeclareArg(env, "hi", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "lo", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(LongLong_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	long hi = args.GetLong(0);
	unsigned lo = args.GetInt(1);
	wx_LongLong *pEntity = new wx_LongLong(hi, lo);
	Object_wx_LongLong *pObj = Object_wx_LongLong::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_LongLong(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_LongLong, Abs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LongLong, Abs)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLongLong rtn = pThis->GetEntity()->Abs();
	return ReturnValue(env, args, Value(new Object_wx_LongLong(new wxLongLong(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_LongLong, Abs_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LongLong, Abs_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLongLong &rtn = pThis->GetEntity()->Abs();
	return ReturnValue(env, args, Value(new Object_wx_LongLong(new wxLongLong(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_LongLong, Assign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LongLong, Assign)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	double d = args.GetDouble(0);
	wxLongLong &rtn = pThis->GetEntity()->Assign(d);
	return ReturnValue(env, args, Value(new Object_wx_LongLong(new wxLongLong(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_LongLong, GetHi)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LongLong, GetHi)
{
	Signal &sig = env.GetSignal();
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetHi();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_LongLong, GetLo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LongLong, GetLo)
{
	Signal &sig = env.GetSignal();
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned rtn = pThis->GetEntity()->GetLo();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_LongLong, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LongLong, GetValue)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLongLong_t rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, args, Value(new Object_wx_LongLong_t(new wxLongLong_t(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_LongLong, ToDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LongLong, ToDouble)
{
	Signal &sig = env.GetSignal();
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	double rtn = pThis->GetEntity()->ToDouble();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_LongLong, ToLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LongLong, ToLong)
{
	Signal &sig = env.GetSignal();
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->ToLong();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_LongLong, ToString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LongLong, ToString)
{
	Signal &sig = env.GetSignal();
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->ToString();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxLongLong
//----------------------------------------------------------------------------
Object_wx_LongLong::~Object_wx_LongLong()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_LongLong::Clone() const
{
	return nullptr;
}

String Object_wx_LongLong::ToString(bool exprFlag)
{
	String rtn("<wx.LongLong:");
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
// Class implementation for wxLongLong
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LongLong)
{
	Gura_AssignFunction(LongLongEmpty);
	Gura_AssignFunction(LongLong);
	Gura_AssignFunction(LongLong_1);
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
	return new Object_wx_LongLong((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
