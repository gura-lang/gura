//----------------------------------------------------------------------------
// wxDelegateRendererNative
// extracted from delgrend.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DelegateRendererNative: public wxDelegateRendererNative, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DelegateRendererNative *_pObj;
public:
	inline wx_DelegateRendererNative() : wxDelegateRendererNative(), _sig(NULL), _pObj(NULL) {}
	inline wx_DelegateRendererNative(wxRendererNative& rendererNative) : wxDelegateRendererNative(rendererNative), _sig(NULL), _pObj(NULL) {}
	~wx_DelegateRendererNative();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DelegateRendererNative *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DelegateRendererNative::~wx_DelegateRendererNative()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DelegateRendererNative::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDelegateRendererNative
//----------------------------------------------------------------------------
Gura_DeclareFunction(DelegateRendererNativeEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DelegateRendererNative));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DelegateRendererNativeEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_DelegateRendererNative *pEntity = new wx_DelegateRendererNative();
	Object_wx_DelegateRendererNative *pObj = Object_wx_DelegateRendererNative::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DelegateRendererNative(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(DelegateRendererNative)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DelegateRendererNative));
	DeclareArg(env, "rendererNative", VTYPE_wx_RendererNative, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DelegateRendererNative)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxRendererNative *rendererNative = Object_wx_RendererNative::GetObject(args, 0)->GetEntity();
	wx_DelegateRendererNative *pEntity = new wx_DelegateRendererNative(*rendererNative);
	Object_wx_DelegateRendererNative *pObj = Object_wx_DelegateRendererNative::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DelegateRendererNative(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_DelegateRendererNative, DrawXXX)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
#endif
}

Gura_ImplementMethod(wx_DelegateRendererNative, DrawXXX)
{
#if 0
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->DrawXXX();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDelegateRendererNative
//----------------------------------------------------------------------------
Object_wx_DelegateRendererNative::~Object_wx_DelegateRendererNative()
{
}

Object *Object_wx_DelegateRendererNative::Clone() const
{
	return NULL;
}

String Object_wx_DelegateRendererNative::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DelegateRendererNative:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DelegateRendererNative::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(DelegateRendererNativeEmpty);
	Gura_AssignFunction(DelegateRendererNative);
}

//----------------------------------------------------------------------------
// Class implementation for wxDelegateRendererNative
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DelegateRendererNative)
{
	Gura_AssignMethod(wx_DelegateRendererNative, DrawXXX);
}

Gura_ImplementDescendantCreator(wx_DelegateRendererNative)
{
	return new Object_wx_DelegateRendererNative((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
