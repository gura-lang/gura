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
	//Gura::Signal *_pSig;
	Object_wx_MouseCaptureChangedEvent *_pObj;
public:
	inline wx_MouseCaptureChangedEvent(wxWindowID windowId, wxWindow* gainedCapture) : wxMouseCaptureChangedEvent(windowId, gainedCapture), _pObj(nullptr) {}
	~wx_MouseCaptureChangedEvent();
	inline void AssocWithGura(Object_wx_MouseCaptureChangedEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MouseCaptureChangedEvent::~wx_MouseCaptureChangedEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MouseCaptureChangedEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(MouseCaptureChangedEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MouseCaptureChangedEvent));
	DeclareArg(env, "windowId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "gainedCapture", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MouseCaptureChangedEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindowID windowId = 0;
	if (args.IsValid(0)) windowId = static_cast<wxWindowID>(args.GetInt(0));
	wxWindow *gainedCapture = (wxWindow *)(nullptr);
	if (args.IsValid(1)) gainedCapture = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wx_MouseCaptureChangedEvent *pEntity = new wx_MouseCaptureChangedEvent(windowId, gainedCapture);
	Object_wx_MouseCaptureChangedEvent *pObj = Object_wx_MouseCaptureChangedEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_MouseCaptureChangedEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_MouseCaptureChangedEvent, GetCapturedWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseCaptureChangedEvent, GetCapturedWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseCaptureChangedEvent *pThis = Object_wx_MouseCaptureChangedEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetCapturedWindow();
	return ReturnValue(env, args, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------
Object_wx_MouseCaptureChangedEvent::~Object_wx_MouseCaptureChangedEvent()
{
}

Object *Object_wx_MouseCaptureChangedEvent::Clone() const
{
	return nullptr;
}

String Object_wx_MouseCaptureChangedEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MouseCaptureChangedEvent:");
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
// Class implementation for wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseCaptureChangedEvent)
{
	Gura_AssignFunction(MouseCaptureChangedEvent);
	Gura_AssignMethod(wx_MouseCaptureChangedEvent, GetCapturedWindow);
}

Gura_ImplementDescendantCreator(wx_MouseCaptureChangedEvent)
{
	return new Object_wx_MouseCaptureChangedEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
