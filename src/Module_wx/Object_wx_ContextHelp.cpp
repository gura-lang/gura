//----------------------------------------------------------------------------
// wxContextHelp
// extracted from cshelp.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ContextHelp: public wxContextHelp, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ContextHelp *_pObj;
public:
	inline wx_ContextHelp(wxWindow* window, bool doNow) : wxContextHelp(window, doNow), _sig(NULL), _pObj(NULL) {}
	~wx_ContextHelp();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ContextHelp *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ContextHelp::~wx_ContextHelp()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ContextHelp::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxContextHelp
//----------------------------------------------------------------------------
Gura_DeclareFunction(ContextHelp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ContextHelp));
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "doNow", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ContextHelp)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *window = (wxWindow *)(NULL);
	if (args.IsValid(0)) window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	bool doNow = true;
	if (args.IsValid(1)) doNow = args.GetBoolean(1);
	wx_ContextHelp *pEntity = new wx_ContextHelp(window, doNow);
	Object_wx_ContextHelp *pObj = Object_wx_ContextHelp::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ContextHelp(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_ContextHelp, BeginContextHelp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ContextHelp, BeginContextHelp)
{
	Object_wx_ContextHelp *pSelf = Object_wx_ContextHelp::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *window = (wxWindow *)(NULL);
	if (args.IsValid(0)) window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->BeginContextHelp(window);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ContextHelp, EndContextHelp)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ContextHelp, EndContextHelp)
{
	Object_wx_ContextHelp *pSelf = Object_wx_ContextHelp::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndContextHelp();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxContextHelp
//----------------------------------------------------------------------------
Object_wx_ContextHelp::~Object_wx_ContextHelp()
{
}

Object *Object_wx_ContextHelp::Clone() const
{
	return NULL;
}

String Object_wx_ContextHelp::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ContextHelp:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ContextHelp::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(ContextHelp);
}

//----------------------------------------------------------------------------
// Class implementation for wxContextHelp
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ContextHelp)
{
	Gura_AssignMethod(wx_ContextHelp, BeginContextHelp);
	Gura_AssignMethod(wx_ContextHelp, EndContextHelp);
}

Gura_ImplementDescendantCreator(wx_ContextHelp)
{
	return new Object_wx_ContextHelp((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
