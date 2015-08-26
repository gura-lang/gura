//----------------------------------------------------------------------------
// wxTipProvider
// extracted from tipprov.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(PreProcessTip);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TipProvider: public wxTipProvider, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_TipProvider *_pObj;
public:
	//inline wx_TipProvider(size_t currentTip) : wxTipProvider(currentTip), _pObj(nullptr) {}
	//virtual wxString PreProcessTip(const wxString& tip);
	~wx_TipProvider();
	inline void AssocWithGura(Object_wx_TipProvider *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TipProvider::~wx_TipProvider()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TipProvider::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTipProvider
//----------------------------------------------------------------------------
Gura_DeclareFunction(TipProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_TipProvider));
	DeclareArg(env, "currentTip", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(TipProvider)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	size_t currentTip = args.GetSizeT(0);
	wx_TipProvider *pEntity = new wx_TipProvider(currentTip);
	Object_wx_TipProvider *pObj = Object_wx_TipProvider::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TipProvider(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_TipProvider, GetTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TipProvider, GetTip)
{
	Signal &sig = env.GetSignal();
	Object_wx_TipProvider *pThis = Object_wx_TipProvider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetTip();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TipProvider, PreProcessTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "tip", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TipProvider, PreProcessTip)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TipProvider *pThis = Object_wx_TipProvider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString tip = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->PreProcessTip(tip);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TipProvider, GetCurrentTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TipProvider, GetCurrentTip)
{
	Signal &sig = env.GetSignal();
	Object_wx_TipProvider *pThis = Object_wx_TipProvider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetCurrentTip();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTipProvider
//----------------------------------------------------------------------------
Object_wx_TipProvider::~Object_wx_TipProvider()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_TipProvider::Clone() const
{
	return nullptr;
}

String Object_wx_TipProvider::ToString(bool exprFlag)
{
	String rtn("<wx.TipProvider:");
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
// Class implementation for wxTipProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TipProvider)
{
	Gura_RealizeUserSymbol(PreProcessTip);
	Gura_AssignFunction(TipProvider);
	Gura_AssignMethod(wx_TipProvider, GetTip);
	Gura_AssignMethod(wx_TipProvider, PreProcessTip);
	Gura_AssignMethod(wx_TipProvider, GetCurrentTip);
}

Gura_ImplementDescendantCreator(wx_TipProvider)
{
	return new Object_wx_TipProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
