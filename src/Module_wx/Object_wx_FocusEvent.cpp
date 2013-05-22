//----------------------------------------------------------------------------
// wxFocusEvent
// extracted from focusevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FocusEvent: public wxFocusEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FocusEvent *_pObj;
public:
	inline wx_FocusEvent(WXTYPE eventType, int id) : wxFocusEvent(eventType, id), _sig(NULL), _pObj(NULL) {}
	~wx_FocusEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FocusEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FocusEvent::~wx_FocusEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FocusEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFocusEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(FocusEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FocusEvent));
	DeclareArg(env, "eventType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FocusEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	WXTYPE eventType = 0;
	if (args.IsValid(0)) eventType = static_cast<WXTYPE>(args.GetInt(0));
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_FocusEvent *pEntity = new wx_FocusEvent(eventType, id);
	Object_wx_FocusEvent *pObj = Object_wx_FocusEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FocusEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_FocusEvent, GetWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
}

Gura_ImplementMethod(wx_FocusEvent, GetWindow)
{
	Object_wx_FocusEvent *pThis = Object_wx_FocusEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = pThis->GetEntity()->GetWindow();
	return Value(new Object_wx_Window(rtn, NULL, false));
}

//----------------------------------------------------------------------------
// Object implementation for wxFocusEvent
//----------------------------------------------------------------------------
Object_wx_FocusEvent::~Object_wx_FocusEvent()
{
}

Object *Object_wx_FocusEvent::Clone() const
{
	return NULL;
}

String Object_wx_FocusEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FocusEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_FocusEvent::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(FocusEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxFocusEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FocusEvent)
{
	Gura_AssignMethod(wx_FocusEvent, GetWindow);
}

Gura_ImplementDescendantCreator(wx_FocusEvent)
{
	return new Object_wx_FocusEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
