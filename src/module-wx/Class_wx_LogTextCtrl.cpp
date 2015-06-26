//----------------------------------------------------------------------------
// wxLogTextCtrl
// extracted from log.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_LogTextCtrl: public wxLogTextCtrl, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_LogTextCtrl *_pObj;
public:
	inline wx_LogTextCtrl(wxTextCtrl *textctrl) : wxLogTextCtrl(textctrl), _sig(nullptr), _pObj(nullptr) {}
	~wx_LogTextCtrl();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_LogTextCtrl *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LogTextCtrl::~wx_LogTextCtrl()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_LogTextCtrl::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLogTextCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(LogTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_LogTextCtrl));
	DeclareArg(env, "textctrl", VTYPE_wx_TextCtrl, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LogTextCtrl)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxTextCtrl *textctrl = Object_wx_TextCtrl::GetObject(args, 0)->GetEntity();
	wx_LogTextCtrl *pEntity = new wx_LogTextCtrl(textctrl);
	Object_wx_LogTextCtrl *pObj = Object_wx_LogTextCtrl::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_LogTextCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxLogTextCtrl
//----------------------------------------------------------------------------
Object_wx_LogTextCtrl::~Object_wx_LogTextCtrl()
{
}

Object *Object_wx_LogTextCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_LogTextCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.LogTextCtrl:");
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
// Class implementation for wxLogTextCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogTextCtrl)
{
	Gura_AssignFunction(LogTextCtrl);
}

Gura_ImplementDescendantCreator(wx_LogTextCtrl)
{
	return new Object_wx_LogTextCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
