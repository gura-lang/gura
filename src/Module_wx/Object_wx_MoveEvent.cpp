//----------------------------------------------------------------------------
// wxMoveEvent
// extracted from moveevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MoveEvent: public wxMoveEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MoveEvent *_pObj;
public:
	inline wx_MoveEvent(const wxPoint& pt, int id) : wxMoveEvent(pt, id), _sig(NULL), _pObj(NULL) {}
	~wx_MoveEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MoveEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MoveEvent::~wx_MoveEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MoveEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMoveEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(MoveEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MoveEvent));
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MoveEvent)
{
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_MoveEvent *pEntity = new wx_MoveEvent(*pt, id);
	Object_wx_MoveEvent *pObj = Object_wx_MoveEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MoveEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_MoveEvent, GetPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MoveEvent, GetPosition)
{
	Object_wx_MoveEvent *pSelf = Object_wx_MoveEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pSelf->GetEntity()->GetPosition();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxMoveEvent
//----------------------------------------------------------------------------
Object_wx_MoveEvent::~Object_wx_MoveEvent()
{
}

Object *Object_wx_MoveEvent::Clone() const
{
	return NULL;
}

String Object_wx_MoveEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.MoveEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_MoveEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(MoveEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxMoveEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MoveEvent)
{
	Gura_AssignMethod(wx_MoveEvent, GetPosition);
}

Gura_ImplementDescendantCreator(wx_MoveEvent)
{
	return new Object_wx_MoveEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
