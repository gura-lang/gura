//----------------------------------------------------------------------------
// wxContextMenuEvent
// extracted from cntxtevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ContextMenuEvent: public wxContextMenuEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ContextMenuEvent *_pObj;
public:
	inline wx_ContextMenuEvent(WXTYPE type, int id, const wxPoint& pos) : wxContextMenuEvent(type, id, pos), _sig(NULL), _pObj(NULL) {}
	~wx_ContextMenuEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ContextMenuEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ContextMenuEvent::~wx_ContextMenuEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ContextMenuEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxContextMenuEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(ContextMenuEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ContextMenuEvent));
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ContextMenuEvent)
{
	WXTYPE type = 0;
	if (args.IsValid(0)) type = static_cast<WXTYPE>(args.GetInt(0));
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wx_ContextMenuEvent *pEntity = new wx_ContextMenuEvent(type, id, *pos);
	Object_wx_ContextMenuEvent *pObj = Object_wx_ContextMenuEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ContextMenuEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_ContextMenuEvent, GetPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ContextMenuEvent, GetPosition)
{
	Object_wx_ContextMenuEvent *pSelf = Object_wx_ContextMenuEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pSelf->GetEntity()->GetPosition();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ContextMenuEvent, SetPosition)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "point", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_ContextMenuEvent, SetPosition)
{
	Object_wx_ContextMenuEvent *pSelf = Object_wx_ContextMenuEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint *point = Object_wx_Point::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetPosition(*point);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxContextMenuEvent
//----------------------------------------------------------------------------
Object_wx_ContextMenuEvent::~Object_wx_ContextMenuEvent()
{
}

Object *Object_wx_ContextMenuEvent::Clone() const
{
	return NULL;
}

String Object_wx_ContextMenuEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ContextMenuEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ContextMenuEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(ContextMenuEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxContextMenuEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ContextMenuEvent)
{
	Gura_AssignMethod(wx_ContextMenuEvent, GetPosition);
	Gura_AssignMethod(wx_ContextMenuEvent, SetPosition);
}

Gura_ImplementDescendantCreator(wx_ContextMenuEvent)
{
	return new Object_wx_ContextMenuEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
