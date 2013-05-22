//----------------------------------------------------------------------------
// wxMouseCaptureLostEvent
// extracted from mcaptevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MouseCaptureLostEvent: public wxMouseCaptureLostEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MouseCaptureLostEvent *_pObj;
public:
	inline wx_MouseCaptureLostEvent(wxWindowID windowId) : wxMouseCaptureLostEvent(windowId), _sig(NULL), _pObj(NULL) {}
	~wx_MouseCaptureLostEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MouseCaptureLostEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MouseCaptureLostEvent::~wx_MouseCaptureLostEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MouseCaptureLostEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMouseCaptureLostEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(MouseCaptureLostEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MouseCaptureLostEvent));
	DeclareArg(env, "windowId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MouseCaptureLostEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindowID windowId = 0;
	if (args.IsValid(0)) windowId = static_cast<wxWindowID>(args.GetInt(0));
	wx_MouseCaptureLostEvent *pEntity = new wx_MouseCaptureLostEvent(windowId);
	Object_wx_MouseCaptureLostEvent *pObj = Object_wx_MouseCaptureLostEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MouseCaptureLostEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxMouseCaptureLostEvent
//----------------------------------------------------------------------------
Object_wx_MouseCaptureLostEvent::~Object_wx_MouseCaptureLostEvent()
{
}

Object *Object_wx_MouseCaptureLostEvent::Clone() const
{
	return NULL;
}

String Object_wx_MouseCaptureLostEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.MouseCaptureLostEvent:");
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
// Class implementation for wxMouseCaptureLostEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseCaptureLostEvent)
{
	Gura_AssignFunction(MouseCaptureLostEvent);
}

Gura_ImplementDescendantCreator(wx_MouseCaptureLostEvent)
{
	return new Object_wx_MouseCaptureLostEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
