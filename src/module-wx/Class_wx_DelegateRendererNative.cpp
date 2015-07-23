//----------------------------------------------------------------------------
// wxDelegateRendererNative
// extracted from delgrend.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DelegateRendererNative: public wxDelegateRendererNative, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DelegateRendererNative *_pObj;
public:
	inline wx_DelegateRendererNative() : wxDelegateRendererNative(), _pObj(nullptr) {}
	inline wx_DelegateRendererNative(wxRendererNative& rendererNative) : wxDelegateRendererNative(rendererNative), _pObj(nullptr) {}
	~wx_DelegateRendererNative();
	inline void AssocWithGura(Object_wx_DelegateRendererNative *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DelegateRendererNative::~wx_DelegateRendererNative()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DelegateRendererNative::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDelegateRendererNative
//----------------------------------------------------------------------------
Gura_DeclareFunction(DelegateRendererNativeEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DelegateRendererNative));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DelegateRendererNativeEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_DelegateRendererNative *pEntity = new wx_DelegateRendererNative();
	Object_wx_DelegateRendererNative *pObj = Object_wx_DelegateRendererNative::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DelegateRendererNative(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(DelegateRendererNative)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	if (pObj == nullptr) {
		pObj = new Object_wx_DelegateRendererNative(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_DelegateRendererNative, DrawXXX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	return nullptr;
}

String Object_wx_DelegateRendererNative::ToString(bool exprFlag)
{
	String rtn("<wx.DelegateRendererNative:");
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
// Class implementation for wxDelegateRendererNative
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DelegateRendererNative)
{
	Gura_AssignFunction(DelegateRendererNativeEmpty);
	Gura_AssignFunction(DelegateRendererNative);
	Gura_AssignMethod(wx_DelegateRendererNative, DrawXXX);
}

Gura_ImplementDescendantCreator(wx_DelegateRendererNative)
{
	return new Object_wx_DelegateRendererNative((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
