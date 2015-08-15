//----------------------------------------------------------------------------
// wxContextHelp
// extracted from cshelp.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ContextHelp: public wxContextHelp, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ContextHelp *_pObj;
public:
	inline wx_ContextHelp(wxWindow* window, bool doNow) : wxContextHelp(window, doNow), _pObj(nullptr) {}
	~wx_ContextHelp();
	inline void AssocWithGura(Object_wx_ContextHelp *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ContextHelp::~wx_ContextHelp()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ContextHelp::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxContextHelp
//----------------------------------------------------------------------------
Gura_DeclareFunction(ContextHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ContextHelp));
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "doNow", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ContextHelp)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *window = (wxWindow *)(nullptr);
	if (args.IsValid(0)) window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	bool doNow = true;
	if (args.IsValid(1)) doNow = args.GetBoolean(1);
	wx_ContextHelp *pEntity = new wx_ContextHelp(window, doNow);
	Object_wx_ContextHelp *pObj = Object_wx_ContextHelp::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ContextHelp(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_ContextHelp, BeginContextHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ContextHelp, BeginContextHelp)
{
	Signal &sig = env.GetSignal();
	Object_wx_ContextHelp *pThis = Object_wx_ContextHelp::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window = (wxWindow *)(nullptr);
	if (args.IsValid(0)) window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->BeginContextHelp(window);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ContextHelp, EndContextHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ContextHelp, EndContextHelp)
{
	Signal &sig = env.GetSignal();
	Object_wx_ContextHelp *pThis = Object_wx_ContextHelp::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->EndContextHelp();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxContextHelp
//----------------------------------------------------------------------------
Object_wx_ContextHelp::~Object_wx_ContextHelp()
{
}

Object *Object_wx_ContextHelp::Clone() const
{
	return nullptr;
}

String Object_wx_ContextHelp::ToString(bool exprFlag)
{
	String rtn("<wx.ContextHelp:");
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
// Class implementation for wxContextHelp
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ContextHelp)
{
	Gura_AssignFunction(ContextHelp);
	Gura_AssignMethod(wx_ContextHelp, BeginContextHelp);
	Gura_AssignMethod(wx_ContextHelp, EndContextHelp);
}

Gura_ImplementDescendantCreator(wx_ContextHelp)
{
	return new Object_wx_ContextHelp((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
