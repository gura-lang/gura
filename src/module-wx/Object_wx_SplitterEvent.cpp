//----------------------------------------------------------------------------
// wxSplitterEvent
// extracted from splitevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SplitterEvent: public wxSplitterEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_SplitterEvent *_pObj;
public:
	inline wx_SplitterEvent(wxEventType eventType, wxSplitterWindow * splitter) : wxSplitterEvent(eventType, splitter), _sig(NULL), _pObj(NULL) {}
	~wx_SplitterEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SplitterEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SplitterEvent::~wx_SplitterEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_SplitterEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSplitterEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(SplitterEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SplitterEvent));
	DeclareArg(env, "eventType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "splitter", VTYPE_wx_SplitterWindow, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SplitterEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxEventType eventType = wxEVT_NULL;
	if (args.IsValid(0)) eventType = static_cast<wxEventType>(args.GetInt(0));
	wxSplitterWindow *splitter = (wxSplitterWindow *)(NULL);
	if (args.IsValid(1)) splitter = Object_wx_SplitterWindow::GetObject(args, 1)->GetEntity();
	wx_SplitterEvent *pEntity = new wx_SplitterEvent(eventType, splitter);
	Object_wx_SplitterEvent *pObj = Object_wx_SplitterEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_SplitterEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_SplitterEvent, GetSashPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplitterEvent, GetSashPosition)
{
	Object_wx_SplitterEvent *pThis = Object_wx_SplitterEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetSashPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SplitterEvent, GetX)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplitterEvent, GetX)
{
	Object_wx_SplitterEvent *pThis = Object_wx_SplitterEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetX();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SplitterEvent, GetY)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplitterEvent, GetY)
{
	Object_wx_SplitterEvent *pThis = Object_wx_SplitterEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetY();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SplitterEvent, GetWindowBeingRemoved)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplitterEvent, GetWindowBeingRemoved)
{
	Object_wx_SplitterEvent *pThis = Object_wx_SplitterEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetWindowBeingRemoved();
	return ReturnValue(env, sig, args, Value(new Object_wx_Window(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_SplitterEvent, SetSashPosition)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterEvent, SetSashPosition)
{
	Object_wx_SplitterEvent *pThis = Object_wx_SplitterEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pos = args.GetInt(0);
	pThis->GetEntity()->SetSashPosition(pos);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxSplitterEvent
//----------------------------------------------------------------------------
Object_wx_SplitterEvent::~Object_wx_SplitterEvent()
{
}

Object *Object_wx_SplitterEvent::Clone() const
{
	return NULL;
}

String Object_wx_SplitterEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SplitterEvent:");
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
// Class implementation for wxSplitterEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SplitterEvent)
{
	Gura_AssignFunction(SplitterEvent);
	Gura_AssignMethod(wx_SplitterEvent, GetSashPosition);
	Gura_AssignMethod(wx_SplitterEvent, GetX);
	Gura_AssignMethod(wx_SplitterEvent, GetY);
	Gura_AssignMethod(wx_SplitterEvent, GetWindowBeingRemoved);
	Gura_AssignMethod(wx_SplitterEvent, SetSashPosition);
}

Gura_ImplementDescendantCreator(wx_SplitterEvent)
{
	return new Object_wx_SplitterEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
