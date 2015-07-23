//----------------------------------------------------------------------------
// wxWindowDisabler
// extracted from wnddisbl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_WindowDisabler: public wxWindowDisabler, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_WindowDisabler *_pObj;
public:
	inline wx_WindowDisabler(wxWindow * winToSkip) : wxWindowDisabler(winToSkip), _pObj(nullptr) {}
	~wx_WindowDisabler();
	inline void AssocWithGura(Object_wx_WindowDisabler *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_WindowDisabler::~wx_WindowDisabler()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_WindowDisabler::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowDisabler
//----------------------------------------------------------------------------
Gura_DeclareFunction(WindowDisabler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_WindowDisabler));
	DeclareArg(env, "winToSkip", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementFunction(WindowDisabler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *winToSkip = (wxWindow *)(nullptr);
	if (args.IsValid(0)) winToSkip = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wx_WindowDisabler windowDisabler(winToSkip);
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	SeqPostHandler *pSeqPostHandler = nullptr;
	Value rtn = pExprBlock->Exec2(env, sig, pSeqPostHandler);
	return rtn;
}

//----------------------------------------------------------------------------
// Object implementation for wxWindowDisabler
//----------------------------------------------------------------------------
Object_wx_WindowDisabler::~Object_wx_WindowDisabler()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_WindowDisabler::Clone() const
{
	return nullptr;
}

String Object_wx_WindowDisabler::ToString(bool exprFlag)
{
	String rtn("<wx.WindowDisabler:");
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
// Class implementation for wxWindowDisabler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowDisabler)
{
	Gura_AssignFunction(WindowDisabler);
}

Gura_ImplementDescendantCreator(wx_WindowDisabler)
{
	return new Object_wx_WindowDisabler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
