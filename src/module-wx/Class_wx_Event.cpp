//----------------------------------------------------------------------------
// wxEvent
// extracted from event.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(Clone);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Event: public wxEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Event *_pObj;
public:
	//inline wx_Event(int id, wxEventType eventType) : wxEvent(id, eventType), _pObj(nullptr) {}
	//virtual wxEvent* Clone();
	~wx_Event();
	inline void AssocWithGura(Object_wx_Event *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Event::~wx_Event()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Event::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(Event)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_Event));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "eventType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(Event)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	int id = 0;
	if (args.IsValid(0)) id = args.GetInt(0);
	wxEventType eventType = wxEVT_NULL;
	if (args.IsValid(1)) eventType = static_cast<wxEventType>(args.GetInt(1));
	wx_Event *pEntity = new wx_Event(id, eventType);
	Object_wx_Event *pObj = Object_wx_Event::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Event(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxEvent *rtn = (wxEvent *)pThis->GetEntity()->Clone();
	return ReturnValue(env, args, Value(new Object_wx_Event(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Event, GetEventObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, GetEventObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxObject *rtn = (wxObject *)pThis->GetEntity()->GetEventObject();
	return ReturnValue(env, args, Value(new Object_wx_Object(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Event, GetEventType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, GetEventType)
{
	Signal &sig = env.GetSignal();
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxEventType rtn = pThis->GetEntity()->GetEventType();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Event, GetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, GetId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetId();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Event, GetSkipped)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, GetSkipped)
{
	Signal &sig = env.GetSignal();
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetSkipped();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Event, GetTimestamp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, GetTimestamp)
{
	Signal &sig = env.GetSignal();
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetTimestamp();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Event, IsCommandEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, IsCommandEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsCommandEvent();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Event, ResumePropagation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "propagationLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, ResumePropagation)
{
	Signal &sig = env.GetSignal();
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int propagationLevel = args.GetInt(0);
	pThis->GetEntity()->ResumePropagation(propagationLevel);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, SetEventObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "object", VTYPE_wx_Object, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, SetEventObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxObject *object = Object_wx_Object::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetEventObject(object);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, SetEventType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, SetEventType)
{
	Signal &sig = env.GetSignal();
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxEventType type = static_cast<wxEventType>(args.GetInt(0));
	pThis->GetEntity()->SetEventType(type);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, SetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, SetId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = args.GetInt(0);
	pThis->GetEntity()->SetId(id);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, SetTimestamp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "timeStamp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, SetTimestamp)
{
	Signal &sig = env.GetSignal();
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long timeStamp = args.GetLong(0);
	pThis->GetEntity()->SetTimestamp(timeStamp);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, ShouldPropagate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, ShouldPropagate)
{
	Signal &sig = env.GetSignal();
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->ShouldPropagate();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Event, Skip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "skip", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, Skip)
{
	Signal &sig = env.GetSignal();
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool skip = true;
	if (args.IsValid(0)) skip = args.GetBoolean(0);
	pThis->GetEntity()->Skip(skip);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, StopPropagation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Event, StopPropagation)
{
	Signal &sig = env.GetSignal();
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->StopPropagation();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxEvent
//----------------------------------------------------------------------------
Object_wx_Event::~Object_wx_Event()
{
}

Object *Object_wx_Event::Clone() const
{
	return nullptr;
}

String Object_wx_Event::ToString(bool exprFlag)
{
	String rtn("<wx.Event:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Event)
{
	Gura_RealizeUserSymbol(Clone);
	Gura_AssignFunction(Event);
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
	return new Object_wx_Event((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
