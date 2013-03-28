//----------------------------------------------------------------------------
// wxPopupTransientWindow
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(Popup);
Gura_DeclarePrivUserSymbol(Dismiss);
Gura_DeclarePrivUserSymbol(CanDismiss);
Gura_DeclarePrivUserSymbol(ProcessLeftDown);
Gura_DeclarePrivUserSymbol(Show);
Gura_DeclarePrivUserSymbol(OnDismiss);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PopupTransientWindow: public wxPopupTransientWindow, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	AutoPtr<Object_wx_PopupTransientWindow> _pObj;
public:
	inline wx_PopupTransientWindow(wxWindow* parent, long style) : wxPopupTransientWindow(parent, style), _sig(NULL), _pObj(NULL) {}
	~wx_PopupTransientWindow();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PopupTransientWindow *pObj) {
		_sig = sig, _pObj.reset(Object_wx_PopupTransientWindow::Reference(pObj));
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
	// virtual functions
	virtual void Popup(wxWindow *focus);
	virtual void Dismiss();
	virtual bool CanDismiss();
	virtual bool ProcessLeftDown(wxMouseEvent& event);
	virtual bool Show(bool show);
	virtual void OnDismiss();
public:
	// reveal private or protected member functions to public
	inline void _OnDismiss() {
		wxPopupTransientWindow::OnDismiss();
	}
};

wx_PopupTransientWindow::~wx_PopupTransientWindow()
{
}

void wx_PopupTransientWindow::GuraObjectDeleted()
{
}

void wx_PopupTransientWindow::Popup(wxWindow *focus)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, Popup);
	if (pFunc == NULL) {
		wxPopupTransientWindow::Popup(focus);
		return;
	}
	ValueList valList;
	valList.reserve(1);
	valList.push_back(Value(new Object_wx_Window(focus, NULL, OwnerFalse)));
	_pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	CheckMethodResult(_sig);
}

void wx_PopupTransientWindow::Dismiss()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, Dismiss);
	if (pFunc == NULL) {
		wxPopupTransientWindow::Dismiss();
		return;
	}
	_pObj->EvalMethod(*_pObj, _sig, pFunc, ValueList::Null);
	CheckMethodResult(_sig);
}

bool wx_PopupTransientWindow::CanDismiss()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, CanDismiss);
	if (pFunc == NULL) return wxPopupTransientWindow::CanDismiss();
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, ValueList::Null);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_PopupTransientWindow::ProcessLeftDown(wxMouseEvent& event)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, ProcessLeftDown);
	if (pFunc == NULL) return wxPopupTransientWindow::ProcessLeftDown(event);
	ValueList valList;
	valList.reserve(1);
	valList.push_back(Value(new Object_wx_MouseEvent(new wxMouseEvent(event), NULL, OwnerTrue)));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_PopupTransientWindow::Show(bool show)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, Show);
	if (pFunc == NULL) return wxPopupTransientWindow::Show(show);
	ValueList valList;
	valList.reserve(1);
	valList.push_back(Value(show));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

void wx_PopupTransientWindow::OnDismiss()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnDismiss);
	if (pFunc == NULL) {
		wxPopupTransientWindow::OnDismiss();
		return;
	}
	_pObj->EvalMethod(*_pObj, _sig, pFunc, ValueList::Null);
	CheckMethodResult(_sig);
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPopupTransientWindow
//----------------------------------------------------------------------------
Gura_DeclareFunction(PopupTransientWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PopupTransientWindow));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PopupTransientWindow)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	long style = wxBORDER_NONE;
	if (args.IsValid(1)) style = args.GetLong(1);
	wx_PopupTransientWindow *pEntity = new wx_PopupTransientWindow(parent, style);
	Object_wx_PopupTransientWindow *pObj = Object_wx_PopupTransientWindow::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PopupTransientWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_PopupTransientWindow, Popup)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "focus", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_PopupTransientWindow, Popup)
{
	Object_wx_PopupTransientWindow *pThis = Object_wx_PopupTransientWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *focus = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->wxPopupTransientWindow::Popup(focus);
	return Value::Null;
}

Gura_DeclareMethod(wx_PopupTransientWindow, Dismiss)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PopupTransientWindow, Dismiss)
{
	Object_wx_PopupTransientWindow *pThis = Object_wx_PopupTransientWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->wxPopupTransientWindow::Dismiss();
	return Value::Null;
}

Gura_DeclareMethod(wx_PopupTransientWindow, CanDismiss)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PopupTransientWindow, CanDismiss)
{
	Object_wx_PopupTransientWindow *pThis = Object_wx_PopupTransientWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->wxPopupTransientWindow::CanDismiss();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PopupTransientWindow, ProcessLeftDown)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_MouseEvent, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PopupTransientWindow, ProcessLeftDown)
{
	Object_wx_PopupTransientWindow *pThis = Object_wx_PopupTransientWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMouseEvent *event = Object_wx_MouseEvent::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->wxPopupTransientWindow::ProcessLeftDown(*event);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PopupTransientWindow, Show)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PopupTransientWindow, Show)
{
	Object_wx_PopupTransientWindow *pThis = Object_wx_PopupTransientWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool show = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->wxPopupTransientWindow::Show(show);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PopupTransientWindow, OnDismiss)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PopupTransientWindow, OnDismiss)
{
	Object_wx_PopupTransientWindow *pThis = Object_wx_PopupTransientWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	dynamic_cast<wx_PopupTransientWindow *>(pThis->GetEntity())->_OnDismiss();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxPopupTransientWindow
//----------------------------------------------------------------------------
Object_wx_PopupTransientWindow::~Object_wx_PopupTransientWindow()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_PopupTransientWindow::Clone() const
{
	return NULL;
}

String Object_wx_PopupTransientWindow::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PopupTransientWindow:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_PopupTransientWindow::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(Popup);
	Gura_RealizeUserSymbol(Dismiss);
	Gura_RealizeUserSymbol(CanDismiss);
	Gura_RealizeUserSymbol(ProcessLeftDown);
	Gura_RealizeUserSymbol(Show);
	Gura_RealizeUserSymbol(OnDismiss);
	Gura_AssignFunction(PopupTransientWindow);
}

//----------------------------------------------------------------------------
// Class implementation for wxPopupTransientWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PopupTransientWindow)
{
	Gura_AssignMethod(wx_PopupTransientWindow, Popup);
	Gura_AssignMethod(wx_PopupTransientWindow, Dismiss);
	Gura_AssignMethod(wx_PopupTransientWindow, CanDismiss);
	Gura_AssignMethod(wx_PopupTransientWindow, ProcessLeftDown);
	Gura_AssignMethod(wx_PopupTransientWindow, Show);
	Gura_AssignMethod(wx_PopupTransientWindow, OnDismiss);
}

Gura_ImplementDescendantCreator(wx_PopupTransientWindow)
{
	return new Object_wx_PopupTransientWindow((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
