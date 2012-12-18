//----------------------------------------------------------------------------
// wxEvent
// extracted from event.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(Clone);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Event: public wxEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Event *_pObj;
public:
	//inline wx_Event(int id, wxEventType eventType) : wxEvent(id, eventType), _sig(NULL), _pObj(NULL) {}
	//virtual wxEvent* Clone();
	~wx_Event();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Event *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Event::~wx_Event()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Event::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(Event)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_Event));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "eventType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(Event)
{
#if 0
	int id = 0;
	if (args.IsValid(0)) id = args.GetInt(0);
	wxEventType eventType = wxEVT_NULL;
	if (args.IsValid(1)) eventType = static_cast<wxEventType>(args.GetInt(1));
	wx_Event *pEntity = new wx_Event(id, eventType);
	Object_wx_Event *pObj = Object_wx_Event::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Event(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Event, Clone)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, Clone)
{
	Object_wx_Event *pSelf = Object_wx_Event::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxEvent *rtn = (wxEvent *)pSelf->GetEntity()->Clone();
	return ReturnValue(env, sig, args, Value(new Object_wx_Event(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Event, GetEventObject)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, GetEventObject)
{
	Object_wx_Event *pSelf = Object_wx_Event::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxObject *rtn = (wxObject *)pSelf->GetEntity()->GetEventObject();
	return ReturnValue(env, sig, args, Value(new Object_wx_Object(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Event, GetEventType)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, GetEventType)
{
	Object_wx_Event *pSelf = Object_wx_Event::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxEventType rtn = pSelf->GetEntity()->GetEventType();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Event, GetId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, GetId)
{
	Object_wx_Event *pSelf = Object_wx_Event::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Event, GetSkipped)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, GetSkipped)
{
	Object_wx_Event *pSelf = Object_wx_Event::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->GetSkipped();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Event, GetTimestamp)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, GetTimestamp)
{
	Object_wx_Event *pSelf = Object_wx_Event::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetTimestamp();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Event, IsCommandEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, IsCommandEvent)
{
	Object_wx_Event *pSelf = Object_wx_Event::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsCommandEvent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Event, ResumePropagation)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "propagationLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, ResumePropagation)
{
	Object_wx_Event *pSelf = Object_wx_Event::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int propagationLevel = args.GetInt(0);
	pSelf->GetEntity()->ResumePropagation(propagationLevel);
	return Value::Null;
}

Gura_DeclareMethod(wx_Event, SetEventObject)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "object", VTYPE_wx_Object, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, SetEventObject)
{
	Object_wx_Event *pSelf = Object_wx_Event::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxObject *object = Object_wx_Object::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetEventObject(object);
	return Value::Null;
}

Gura_DeclareMethod(wx_Event, SetEventType)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, SetEventType)
{
	Object_wx_Event *pSelf = Object_wx_Event::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxEventType type = static_cast<wxEventType>(args.GetInt(0));
	pSelf->GetEntity()->SetEventType(type);
	return Value::Null;
}

Gura_DeclareMethod(wx_Event, SetId)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, SetId)
{
	Object_wx_Event *pSelf = Object_wx_Event::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	pSelf->GetEntity()->SetId(id);
	return Value::Null;
}

Gura_DeclareMethod(wx_Event, SetTimestamp)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "timeStamp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, SetTimestamp)
{
	Object_wx_Event *pSelf = Object_wx_Event::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long timeStamp = args.GetLong(0);
	pSelf->GetEntity()->SetTimestamp(timeStamp);
	return Value::Null;
}

Gura_DeclareMethod(wx_Event, ShouldPropagate)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, ShouldPropagate)
{
	Object_wx_Event *pSelf = Object_wx_Event::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->ShouldPropagate();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Event, Skip)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "skip", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, Skip)
{
	Object_wx_Event *pSelf = Object_wx_Event::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool skip = true;
	if (args.IsValid(0)) skip = args.GetBoolean(0);
	pSelf->GetEntity()->Skip(skip);
	return Value::Null;
}

Gura_DeclareMethod(wx_Event, StopPropagation)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, StopPropagation)
{
	Object_wx_Event *pSelf = Object_wx_Event::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->StopPropagation();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxEvent
//----------------------------------------------------------------------------
Object_wx_Event::~Object_wx_Event()
{
}

Object *Object_wx_Event::Clone() const
{
	return NULL;
}

String Object_wx_Event::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Event:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Event::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(Clone);
	Gura_AssignFunction(Event);
}

//----------------------------------------------------------------------------
// Class implementation for wxEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Event)
{
	Gura_AssignMethod(wx_Event, Clone);
	Gura_AssignMethod(wx_Event, GetEventObject);
	Gura_AssignMethod(wx_Event, GetEventType);
	Gura_AssignMethod(wx_Event, GetId);
	Gura_AssignMethod(wx_Event, GetSkipped);
	Gura_AssignMethod(wx_Event, GetTimestamp);
	Gura_AssignMethod(wx_Event, IsCommandEvent);
	Gura_AssignMethod(wx_Event, ResumePropagation);
	Gura_AssignMethod(wx_Event, SetEventObject);
	Gura_AssignMethod(wx_Event, SetEventType);
	Gura_AssignMethod(wx_Event, SetId);
	Gura_AssignMethod(wx_Event, SetTimestamp);
	Gura_AssignMethod(wx_Event, ShouldPropagate);
	Gura_AssignMethod(wx_Event, Skip);
	Gura_AssignMethod(wx_Event, StopPropagation);
}

Gura_ImplementDescendantCreator(wx_Event)
{
	return new Object_wx_Event((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
