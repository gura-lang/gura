//----------------------------------------------------------------------------
// wxGBSpan
// extracted from gbspan.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GBSpan: public wxGBSpan, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GBSpan *_pObj;
public:
	inline wx_GBSpan() : wxGBSpan(), _sig(NULL), _pObj(NULL) {}
	inline wx_GBSpan(int rowspan, int colspan) : wxGBSpan(rowspan, colspan), _sig(NULL), _pObj(NULL) {}
	~wx_GBSpan();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GBSpan *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GBSpan::~wx_GBSpan()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GBSpan::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGBSpan
//----------------------------------------------------------------------------
Gura_DeclareFunction(GBSpanEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GBSpan));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GBSpanEmpty)
{
	wx_GBSpan *pEntity = new wx_GBSpan();
	Object_wx_GBSpan *pObj = Object_wx_GBSpan::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GBSpan(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(GBSpan)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GBSpan));
	DeclareArg(env, "rowspan", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "colspan", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GBSpan)
{
	int rowspan = args.GetInt(0);
	int colspan = args.GetInt(1);
	wx_GBSpan *pEntity = new wx_GBSpan(rowspan, colspan);
	Object_wx_GBSpan *pObj = Object_wx_GBSpan::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GBSpan(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_GBSpan, GetColspan)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBSpan, GetColspan)
{
	Object_wx_GBSpan *pSelf = Object_wx_GBSpan::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetColspan();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GBSpan, GetRowspan)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBSpan, GetRowspan)
{
	Object_wx_GBSpan *pSelf = Object_wx_GBSpan::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetRowspan();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GBSpan, SetColspan)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colspan", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSpan, SetColspan)
{
	Object_wx_GBSpan *pSelf = Object_wx_GBSpan::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int colspan = args.GetInt(0);
	pSelf->GetEntity()->SetColspan(colspan);
	return Value::Null;
}

Gura_DeclareMethod(wx_GBSpan, SetRowspan)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rowspan", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSpan, SetRowspan)
{
	Object_wx_GBSpan *pSelf = Object_wx_GBSpan::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rowspan = args.GetInt(0);
	pSelf->GetEntity()->SetRowspan(rowspan);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxGBSpan
//----------------------------------------------------------------------------
Object_wx_GBSpan::~Object_wx_GBSpan()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_GBSpan::Clone() const
{
	return NULL;
}

String Object_wx_GBSpan::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GBSpan:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_GBSpan::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(GBSpanEmpty);
	Gura_AssignFunction(GBSpan);
}

//----------------------------------------------------------------------------
// Class implementation for wxGBSpan
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GBSpan)
{
	Gura_AssignMethod(wx_GBSpan, GetColspan);
	Gura_AssignMethod(wx_GBSpan, GetRowspan);
	Gura_AssignMethod(wx_GBSpan, SetColspan);
	Gura_AssignMethod(wx_GBSpan, SetRowspan);
}

Gura_ImplementDescendantCreator(wx_GBSpan)
{
	return new Object_wx_GBSpan((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
