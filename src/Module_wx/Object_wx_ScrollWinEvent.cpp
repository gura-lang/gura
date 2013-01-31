//----------------------------------------------------------------------------
// wxScrollWinEvent
// extracted from scrlwevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ScrollWinEvent: public wxScrollWinEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ScrollWinEvent *_pObj;
public:
	inline wx_ScrollWinEvent(WXTYPE commandType, int pos, int orientation) : wxScrollWinEvent(commandType, pos, orientation), _sig(NULL), _pObj(NULL) {}
	~wx_ScrollWinEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ScrollWinEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ScrollWinEvent::~wx_ScrollWinEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ScrollWinEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxScrollWinEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(ScrollWinEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ScrollWinEvent));
	DeclareArg(env, "commandType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ScrollWinEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	WXTYPE commandType = 0;
	if (args.IsValid(0)) commandType = static_cast<WXTYPE>(args.GetInt(0));
	int pos = 0;
	if (args.IsValid(1)) pos = args.GetInt(1);
	int orientation = 0;
	if (args.IsValid(2)) orientation = args.GetInt(2);
	wx_ScrollWinEvent *pEntity = new wx_ScrollWinEvent(commandType, pos, orientation);
	Object_wx_ScrollWinEvent *pObj = Object_wx_ScrollWinEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ScrollWinEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_ScrollWinEvent, GetOrientation)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrollWinEvent, GetOrientation)
{
	Object_wx_ScrollWinEvent *pThis = Object_wx_ScrollWinEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetOrientation();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ScrollWinEvent, GetPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrollWinEvent, GetPosition)
{
	Object_wx_ScrollWinEvent *pThis = Object_wx_ScrollWinEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxScrollWinEvent
//----------------------------------------------------------------------------
Object_wx_ScrollWinEvent::~Object_wx_ScrollWinEvent()
{
}

Object *Object_wx_ScrollWinEvent::Clone() const
{
	return NULL;
}

String Object_wx_ScrollWinEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ScrollWinEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ScrollWinEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(ScrollWinEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxScrollWinEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScrollWinEvent)
{
	Gura_AssignMethod(wx_ScrollWinEvent, GetOrientation);
	Gura_AssignMethod(wx_ScrollWinEvent, GetPosition);
}

Gura_ImplementDescendantCreator(wx_ScrollWinEvent)
{
	return new Object_wx_ScrollWinEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
