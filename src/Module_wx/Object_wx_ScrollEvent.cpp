//----------------------------------------------------------------------------
// wxScrollEvent
// extracted from scrolevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ScrollEvent: public wxScrollEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ScrollEvent *_pObj;
public:
	inline wx_ScrollEvent(WXTYPE commandType, int id, int pos, int orientation) : wxScrollEvent(commandType, id, pos, orientation), _sig(NULL), _pObj(NULL) {}
	~wx_ScrollEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ScrollEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ScrollEvent::~wx_ScrollEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ScrollEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxScrollEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(ScrollEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ScrollEvent));
	DeclareArg(env, "commandType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ScrollEvent)
{
	WXTYPE commandType = 0;
	if (args.IsValid(0)) commandType = static_cast<WXTYPE>(args.GetInt(0));
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	int pos = 0;
	if (args.IsValid(2)) pos = args.GetInt(2);
	int orientation = 0;
	if (args.IsValid(3)) orientation = args.GetInt(3);
	wx_ScrollEvent *pEntity = new wx_ScrollEvent(commandType, id, pos, orientation);
	Object_wx_ScrollEvent *pObj = Object_wx_ScrollEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ScrollEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_ScrollEvent, GetOrientation)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrollEvent, GetOrientation)
{
	Object_wx_ScrollEvent *pSelf = Object_wx_ScrollEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetOrientation();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ScrollEvent, GetPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrollEvent, GetPosition)
{
	Object_wx_ScrollEvent *pSelf = Object_wx_ScrollEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxScrollEvent
//----------------------------------------------------------------------------
Object_wx_ScrollEvent::~Object_wx_ScrollEvent()
{
}

Object *Object_wx_ScrollEvent::Clone() const
{
	return NULL;
}

String Object_wx_ScrollEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ScrollEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ScrollEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(ScrollEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxScrollEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScrollEvent)
{
	Gura_AssignMethod(wx_ScrollEvent, GetOrientation);
	Gura_AssignMethod(wx_ScrollEvent, GetPosition);
}

Gura_ImplementDescendantCreator(wx_ScrollEvent)
{
	return new Object_wx_ScrollEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
