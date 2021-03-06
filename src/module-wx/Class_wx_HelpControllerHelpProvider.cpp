//----------------------------------------------------------------------------
// wxHelpControllerHelpProvider
// extracted from hprovcnt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HelpControllerHelpProvider: public wxHelpControllerHelpProvider, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_HelpControllerHelpProvider *_pObj;
public:
	inline wx_HelpControllerHelpProvider(wxHelpControllerBase* hc) : wxHelpControllerHelpProvider(hc), _pObj(nullptr) {}
	~wx_HelpControllerHelpProvider();
	inline void AssocWithGura(Object_wx_HelpControllerHelpProvider *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HelpControllerHelpProvider::~wx_HelpControllerHelpProvider()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HelpControllerHelpProvider::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHelpControllerHelpProvider
//----------------------------------------------------------------------------
Gura_DeclareFunction(HelpControllerHelpProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HelpControllerHelpProvider));
	DeclareArg(env, "hc", VTYPE_wx_HelpControllerBase, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HelpControllerHelpProvider)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxHelpControllerBase *hc = (wxHelpControllerBase *)(nullptr);
	if (arg.IsValid(0)) hc = Object_wx_HelpControllerBase::GetObject(arg, 0)->GetEntity();
	wx_HelpControllerHelpProvider *pEntity = new wx_HelpControllerHelpProvider(hc);
	Object_wx_HelpControllerHelpProvider *pObj = Object_wx_HelpControllerHelpProvider::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_HelpControllerHelpProvider(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_HelpControllerHelpProvider, SetHelpController)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "hc", VTYPE_wx_HelpControllerBase, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpControllerHelpProvider, SetHelpController)
{
	Signal &sig = env.GetSignal();
	Object_wx_HelpControllerHelpProvider *pThis = Object_wx_HelpControllerHelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHelpControllerBase *hc = Object_wx_HelpControllerBase::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetHelpController(hc);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerHelpProvider, GetHelpController)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpControllerHelpProvider, GetHelpController)
{
	Signal &sig = env.GetSignal();
	Object_wx_HelpControllerHelpProvider *pThis = Object_wx_HelpControllerHelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHelpControllerBase *rtn = (wxHelpControllerBase *)pThis->GetEntity()->GetHelpController();
	return ReturnValue(env, arg, Value(new Object_wx_HelpControllerBase(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxHelpControllerHelpProvider
//----------------------------------------------------------------------------
Object_wx_HelpControllerHelpProvider::~Object_wx_HelpControllerHelpProvider()
{
}

Object *Object_wx_HelpControllerHelpProvider::Clone() const
{
	return nullptr;
}

String Object_wx_HelpControllerHelpProvider::ToString(bool exprFlag)
{
	String rtn("<wx.HelpControllerHelpProvider:");
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
// Class implementation for wxHelpControllerHelpProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HelpControllerHelpProvider)
{
	Gura_AssignFunction(HelpControllerHelpProvider);
	Gura_AssignMethod(wx_HelpControllerHelpProvider, SetHelpController);
	Gura_AssignMethod(wx_HelpControllerHelpProvider, GetHelpController);
}

Gura_ImplementDescendantCreator(wx_HelpControllerHelpProvider)
{
	return new Object_wx_HelpControllerHelpProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
