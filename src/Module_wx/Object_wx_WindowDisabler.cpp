//----------------------------------------------------------------------------
// wxWindowDisabler
// extracted from wnddisbl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_WindowDisabler: public wxWindowDisabler, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_WindowDisabler *_pObj;
public:
	inline wx_WindowDisabler(wxWindow * winToSkip) : wxWindowDisabler(winToSkip), _sig(NULL), _pObj(NULL) {}
	~wx_WindowDisabler();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_WindowDisabler *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_WindowDisabler::~wx_WindowDisabler()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_WindowDisabler::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowDisabler
//----------------------------------------------------------------------------
Gura_DeclareFunction(WindowDisabler)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_WindowDisabler));
	DeclareArg(env, "winToSkip", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WindowDisabler)
{
	wxWindow *winToSkip = (wxWindow *)(NULL);
	if (args.IsValid(0)) winToSkip = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wx_WindowDisabler *pEntity = new wx_WindowDisabler(winToSkip);
	Object_wx_WindowDisabler *pObj = Object_wx_WindowDisabler::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_WindowDisabler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

//----------------------------------------------------------------------------
// Object implementation for wxWindowDisabler
//----------------------------------------------------------------------------
Object_wx_WindowDisabler::~Object_wx_WindowDisabler()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_WindowDisabler::Clone() const
{
	return NULL;
}

String Object_wx_WindowDisabler::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.WindowDisabler:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_WindowDisabler::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(WindowDisabler);
}

//----------------------------------------------------------------------------
// Class implementation for wxWindowDisabler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowDisabler)
{
}

Gura_ImplementDescendantCreator(wx_WindowDisabler)
{
	return new Object_wx_WindowDisabler((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
