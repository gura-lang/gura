//----------------------------------------------------------------------------
// wxMouseCaptureChangedEvent
// extracted from mcaptevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MouseCaptureChangedEvent: public wxMouseCaptureChangedEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MouseCaptureChangedEvent *_pObj;
public:
	inline wx_MouseCaptureChangedEvent(wxWindowID windowId, wxWindow* gainedCapture) : wxMouseCaptureChangedEvent(windowId, gainedCapture), _sig(NULL), _pObj(NULL) {}
	~wx_MouseCaptureChangedEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MouseCaptureChangedEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MouseCaptureChangedEvent::~wx_MouseCaptureChangedEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MouseCaptureChangedEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(MouseCaptureChangedEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MouseCaptureChangedEvent));
	DeclareArg(env, "windowId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "gainedCapture", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MouseCaptureChangedEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindowID windowId = 0;
	if (args.IsValid(0)) windowId = static_cast<wxWindowID>(args.GetInt(0));
	wxWindow *gainedCapture = (wxWindow *)(NULL);
	if (args.IsValid(1)) gainedCapture = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wx_MouseCaptureChangedEvent *pEntity = new wx_MouseCaptureChangedEvent(windowId, gainedCapture);
	Object_wx_MouseCaptureChangedEvent *pObj = Object_wx_MouseCaptureChangedEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MouseCaptureChangedEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_MouseCaptureChangedEvent, GetCapturedWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseCaptureChangedEvent, GetCapturedWindow)
{
	Object_wx_MouseCaptureChangedEvent *pThis = Object_wx_MouseCaptureChangedEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetCapturedWindow();
	return ReturnValue(env, sig, args, Value(new Object_wx_Window(rtn, NULL, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------
Object_wx_MouseCaptureChangedEvent::~Object_wx_MouseCaptureChangedEvent()
{
}

Object *Object_wx_MouseCaptureChangedEvent::Clone() const
{
	return NULL;
}

String Object_wx_MouseCaptureChangedEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.MouseCaptureChangedEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseCaptureChangedEvent)
{
	Gura_AssignFunction(MouseCaptureChangedEvent);
	Gura_AssignMethod(wx_MouseCaptureChangedEvent, GetCapturedWindow);
}

Gura_ImplementDescendantCreator(wx_MouseCaptureChangedEvent)
{
	return new Object_wx_MouseCaptureChangedEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
