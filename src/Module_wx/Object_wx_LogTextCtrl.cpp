//----------------------------------------------------------------------------
// wxLogTextCtrl
// extracted from log.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_LogTextCtrl: public wxLogTextCtrl, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_LogTextCtrl *_pObj;
public:
	inline wx_LogTextCtrl(wxTextCtrl *textctrl) : wxLogTextCtrl(textctrl), _sig(NULL), _pObj(NULL) {}
	~wx_LogTextCtrl();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_LogTextCtrl *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LogTextCtrl::~wx_LogTextCtrl()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_LogTextCtrl::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLogTextCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(LogTextCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_LogTextCtrl));
	DeclareArg(env, "textctrl", VTYPE_wx_TextCtrl, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LogTextCtrl)
{
	wxTextCtrl *textctrl = Object_wx_TextCtrl::GetObject(args, 0)->GetEntity();
	wx_LogTextCtrl *pEntity = new wx_LogTextCtrl(textctrl);
	Object_wx_LogTextCtrl *pObj = Object_wx_LogTextCtrl::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_LogTextCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

//----------------------------------------------------------------------------
// Object implementation for wxLogTextCtrl
//----------------------------------------------------------------------------
Object_wx_LogTextCtrl::~Object_wx_LogTextCtrl()
{
}

Object *Object_wx_LogTextCtrl::Clone() const
{
	return NULL;
}

String Object_wx_LogTextCtrl::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.LogTextCtrl:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_LogTextCtrl::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(LogTextCtrl);
}

//----------------------------------------------------------------------------
// Class implementation for wxLogTextCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogTextCtrl)
{
}

Gura_ImplementDescendantCreator(wx_LogTextCtrl)
{
	return new Object_wx_LogTextCtrl((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
