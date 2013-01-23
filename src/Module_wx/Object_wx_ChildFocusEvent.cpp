//----------------------------------------------------------------------------
// wxChildFocusEvent
// extracted from chfocevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ChildFocusEvent: public wxChildFocusEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ChildFocusEvent *_pObj;
public:
	inline wx_ChildFocusEvent(wxWindow * win) : wxChildFocusEvent(win), _sig(NULL), _pObj(NULL) {}
	~wx_ChildFocusEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ChildFocusEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ChildFocusEvent::~wx_ChildFocusEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ChildFocusEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxChildFocusEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(ChildFocusEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ChildFocusEvent));
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ChildFocusEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *win = (wxWindow *)(NULL);
	if (args.IsValid(0)) win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wx_ChildFocusEvent *pEntity = new wx_ChildFocusEvent(win);
	Object_wx_ChildFocusEvent *pObj = Object_wx_ChildFocusEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ChildFocusEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

//----------------------------------------------------------------------------
// Object implementation for wxChildFocusEvent
//----------------------------------------------------------------------------
Object_wx_ChildFocusEvent::~Object_wx_ChildFocusEvent()
{
}

Object *Object_wx_ChildFocusEvent::Clone() const
{
	return NULL;
}

String Object_wx_ChildFocusEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ChildFocusEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ChildFocusEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(ChildFocusEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxChildFocusEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ChildFocusEvent)
{
}

Gura_ImplementDescendantCreator(wx_ChildFocusEvent)
{
	return new Object_wx_ChildFocusEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
