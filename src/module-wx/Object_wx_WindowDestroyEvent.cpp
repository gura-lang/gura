//----------------------------------------------------------------------------
// wxWindowDestroyEvent
// extracted from destroyevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_WindowDestroyEvent: public wxWindowDestroyEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_WindowDestroyEvent *_pObj;
public:
	inline wx_WindowDestroyEvent(wxWindow* win) : wxWindowDestroyEvent(win), _sig(NULL), _pObj(NULL) {}
	~wx_WindowDestroyEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_WindowDestroyEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_WindowDestroyEvent::~wx_WindowDestroyEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_WindowDestroyEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowDestroyEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(WindowDestroyEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_WindowDestroyEvent));
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WindowDestroyEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *win = (wxWindow *)(NULL);
	if (args.IsValid(0)) win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wx_WindowDestroyEvent *pEntity = new wx_WindowDestroyEvent(win);
	Object_wx_WindowDestroyEvent *pObj = Object_wx_WindowDestroyEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_WindowDestroyEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxWindowDestroyEvent
//----------------------------------------------------------------------------
Object_wx_WindowDestroyEvent::~Object_wx_WindowDestroyEvent()
{
}

Object *Object_wx_WindowDestroyEvent::Clone() const
{
	return NULL;
}

String Object_wx_WindowDestroyEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.WindowDestroyEvent:");
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
// Class implementation for wxWindowDestroyEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowDestroyEvent)
{
	Gura_AssignFunction(WindowDestroyEvent);
}

Gura_ImplementDescendantCreator(wx_WindowDestroyEvent)
{
	return new Object_wx_WindowDestroyEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
