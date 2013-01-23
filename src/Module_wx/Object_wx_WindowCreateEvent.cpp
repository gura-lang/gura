//----------------------------------------------------------------------------
// wxWindowCreateEvent
// extracted from createevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_WindowCreateEvent: public wxWindowCreateEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_WindowCreateEvent *_pObj;
public:
	inline wx_WindowCreateEvent(wxWindow* win) : wxWindowCreateEvent(win), _sig(NULL), _pObj(NULL) {}
	~wx_WindowCreateEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_WindowCreateEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_WindowCreateEvent::~wx_WindowCreateEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_WindowCreateEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowCreateEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(WindowCreateEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_WindowCreateEvent));
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WindowCreateEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *win = (wxWindow *)(NULL);
	if (args.IsValid(0)) win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wx_WindowCreateEvent *pEntity = new wx_WindowCreateEvent(win);
	Object_wx_WindowCreateEvent *pObj = Object_wx_WindowCreateEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_WindowCreateEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

//----------------------------------------------------------------------------
// Object implementation for wxWindowCreateEvent
//----------------------------------------------------------------------------
Object_wx_WindowCreateEvent::~Object_wx_WindowCreateEvent()
{
}

Object *Object_wx_WindowCreateEvent::Clone() const
{
	return NULL;
}

String Object_wx_WindowCreateEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.WindowCreateEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_WindowCreateEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(WindowCreateEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxWindowCreateEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowCreateEvent)
{
}

Gura_ImplementDescendantCreator(wx_WindowCreateEvent)
{
	return new Object_wx_WindowCreateEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
