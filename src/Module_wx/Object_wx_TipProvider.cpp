//----------------------------------------------------------------------------
// wxTipProvider
// extracted from tipprov.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(PreProcessTip);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TipProvider: public wxTipProvider, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TipProvider *_pObj;
public:
	//inline wx_TipProvider(size_t currentTip) : wxTipProvider(currentTip), _sig(NULL), _pObj(NULL) {}
	//virtual wxString PreProcessTip(const wxString& tip);
	~wx_TipProvider();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TipProvider *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TipProvider::~wx_TipProvider()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TipProvider::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTipProvider
//----------------------------------------------------------------------------
Gura_DeclareFunction(TipProvider)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_TipProvider));
	DeclareArg(env, "currentTip", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(TipProvider)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	size_t currentTip = args.GetSizeT(0);
	wx_TipProvider *pEntity = new wx_TipProvider(currentTip);
	Object_wx_TipProvider *pObj = Object_wx_TipProvider::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TipProvider(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_TipProvider, GetTip)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TipProvider, GetTip)
{
	Object_wx_TipProvider *pThis = Object_wx_TipProvider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetTip();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TipProvider, PreProcessTip)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "tip", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TipProvider, PreProcessTip)
{
#if 0
	Object_wx_TipProvider *pThis = Object_wx_TipProvider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString tip = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->PreProcessTip(tip);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TipProvider, GetCurrentTip)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TipProvider, GetCurrentTip)
{
	Object_wx_TipProvider *pThis = Object_wx_TipProvider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetCurrentTip();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTipProvider
//----------------------------------------------------------------------------
Object_wx_TipProvider::~Object_wx_TipProvider()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_TipProvider::Clone() const
{
	return NULL;
}

String Object_wx_TipProvider::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TipProvider:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_TipProvider::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(PreProcessTip);
	Gura_AssignFunction(TipProvider);
}

//----------------------------------------------------------------------------
// Class implementation for wxTipProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TipProvider)
{
	Gura_AssignMethod(wx_TipProvider, GetTip);
	Gura_AssignMethod(wx_TipProvider, PreProcessTip);
	Gura_AssignMethod(wx_TipProvider, GetCurrentTip);
}

Gura_ImplementDescendantCreator(wx_TipProvider)
{
	return new Object_wx_TipProvider((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
