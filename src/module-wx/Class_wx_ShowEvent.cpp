//----------------------------------------------------------------------------
// wxShowEvent
// extracted from sizeevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ShowEvent: public wxShowEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ShowEvent *_pObj;
public:
	inline wx_ShowEvent(int winid, bool show) : wxShowEvent(winid, show), _sig(NULL), _pObj(NULL) {}
	~wx_ShowEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ShowEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ShowEvent::~wx_ShowEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ShowEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxShowEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(ShowEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ShowEvent));
	DeclareArg(env, "winid", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ShowEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int winid = 0;
	if (args.IsValid(0)) winid = args.GetInt(0);
	bool show = false;
	if (args.IsValid(1)) show = args.GetBoolean(1);
	wx_ShowEvent *pEntity = new wx_ShowEvent(winid, show);
	Object_wx_ShowEvent *pObj = Object_wx_ShowEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ShowEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_ShowEvent, SetShow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ShowEvent, SetShow)
{
	Object_wx_ShowEvent *pThis = Object_wx_ShowEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool show = args.GetBoolean(0);
	pThis->GetEntity()->SetShow(show);
	return Value::Null;
}

Gura_DeclareMethod(wx_ShowEvent, IsShown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ShowEvent, IsShown)
{
	Object_wx_ShowEvent *pThis = Object_wx_ShowEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsShown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ShowEvent, GetShow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ShowEvent, GetShow)
{
	Object_wx_ShowEvent *pThis = Object_wx_ShowEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetShow();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxShowEvent
//----------------------------------------------------------------------------
Object_wx_ShowEvent::~Object_wx_ShowEvent()
{
}

Object *Object_wx_ShowEvent::Clone() const
{
	return NULL;
}

String Object_wx_ShowEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ShowEvent:");
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
// Class implementation for wxShowEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ShowEvent)
{
	Gura_AssignFunction(ShowEvent);
	Gura_AssignMethod(wx_ShowEvent, SetShow);
	Gura_AssignMethod(wx_ShowEvent, IsShown);
	Gura_AssignMethod(wx_ShowEvent, GetShow);
}

Gura_ImplementDescendantCreator(wx_ShowEvent)
{
	return new Object_wx_ShowEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
