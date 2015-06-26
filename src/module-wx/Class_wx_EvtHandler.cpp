//----------------------------------------------------------------------------
// wxEvtHandler
// extracted from evthand.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(ProcessEvent);
Gura_DeclarePrivUserSymbol(SearchEventTable);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_EvtHandler: public wxEvtHandler, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_EvtHandler *_pObj;
public:
	inline wx_EvtHandler() : wxEvtHandler(), _sig(nullptr), _pObj(nullptr) {}
	//virtual bool ProcessEvent(wxEvent& event);
	//virtual bool SearchEventTable(wxEventTable& table, wxEvent& event);
	~wx_EvtHandler();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_EvtHandler *pObj) {
		_sig = sig, _pObj = pObj;
	}
	void ObjectEventFunction(wxEvent &event);
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_EvtHandler::~wx_EvtHandler()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_EvtHandler::GuraObjectDeleted()
{
	_pObj = nullptr;
}

void wx_EvtHandler::ObjectEventFunction(wxEvent &event)
{
	if (!IsWxReady()) return;
	EventHandlerPack *pEventHandlerPack =
					wxDynamicCast(event.m_callbackUserData, EventHandlerPack);
	Signal &sig = pEventHandlerPack->GetSignal();
	pEventHandlerPack->Eval(event);
	if (sig.IsSignalled()) {
		SetLogError(sig);
		wxWindow *window = wxDynamicCast(wxApp::GetInstance(), wxApp)->GetTopWindow();
		if (window != nullptr) window->Close(true);
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
	}
}

//----------------------------------------------------------------------------
// Gura interfaces for wxEvtHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(EvtHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_EvtHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(EvtHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_EvtHandler *pEntity = new wx_EvtHandler();
	Object_wx_EvtHandler *pObj = Object_wx_EvtHandler::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_EvtHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_EvtHandler, AddPendingEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_Event, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, AddPendingEvent)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEvent *event = Object_wx_Event::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AddPendingEvent(*event);
	return Value::Null;
}

// wx.EvtHandler#Bind(eventType:wx.EventType, id?:number, lastId?:number):void {block:func_scope}
Gura_DeclareMethod(wx_EvtHandler, Bind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "eventType", VTYPE_wx_EventFactory);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "lastId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_Once, nullptr, Function::BLKSCOPE_SameAsFunc);
}

Gura_ImplementMethod(wx_EvtHandler, Bind)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	Object_wx_EventFactory *pObjEventFactory =
							Object_wx_EventFactory::GetObject(args, 0);
	int id = args.IsValid(1)? args.GetInt(1) : wxID_ANY;
	int lastId = args.IsValid(2)? args.GetInt(2) : wxID_ANY;
	wxEvtHandler *pEvtHandler = wxDynamicCast(pThis->GetEntity(), wxEvtHandler);
	const Function *pFunc = args.GetBlockFunc(env, sig, GetSymbolForBlock());
	Object_function *pObjFunc = new Object_function(env, Function::Reference(pFunc));
	pObjEventFactory->Connect(env, sig, pEvtHandler, id, lastId,
			wxEventHandler(wx_EvtHandler::ObjectEventFunction), pObjFunc, nullptr);
	return Value::Null;
}

// wx.EvtHandler#Connect(eventType:wx.EventType, func:function, id?:number, lastId?:number):void:map
Gura_DeclareMethod(wx_EvtHandler, Connect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "eventType", VTYPE_wx_EventFactory);
	DeclareArg(env, "func", VTYPE_function);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "lastId", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EvtHandler, Connect)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	Object_wx_EventFactory *pObjEventFactory =
							Object_wx_EventFactory::GetObject(args, 0);
	Object_function *pObjFunc = Object_function::GetObject(args, 1);
	int id = args.IsValid(2)? args.GetInt(1) : wxID_ANY;
	int lastId = args.IsValid(3)? args.GetInt(2) : wxID_ANY;
	wxEvtHandler *pEvtHandler = wxDynamicCast(pThis->GetEntity(), wxEvtHandler);
	pObjEventFactory->Connect(env, sig, pEvtHandler, id, lastId,
			wxEventHandler(wx_EvtHandler::ObjectEventFunction), pObjFunc, nullptr);
	return Value::Null;
}

Gura_DeclareMethod(wx_EvtHandler, Disconnect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "eventType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "function", VTYPE_wx_ObjectEventFunction, OCCUR_ZeroOrOnce);
	DeclareArg(env, "userData", VTYPE_wx_Object, OCCUR_ZeroOrOnce);
	DeclareArg(env, "eventSink", VTYPE_wx_EvtHandler, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EvtHandler, Disconnect)
{
#if 0
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEventType eventType = wxEVT_NULL;
	if (args.IsValid(0)) eventType = static_cast<wxEventType>(args.GetInt(0));
	wxObjectEventFunction *function = (wxObjectEventFunction *)(&nullptr);
	if (args.IsValid(1)) function = Object_wx_ObjectEventFunction::GetObject(args, 1)->GetEntity();
	wxObject *userData = (wxObject *)(nullptr);
	if (args.IsValid(2)) userData = Object_wx_Object::GetObject(args, 2)->GetEntity();
	wxEvtHandler *eventSink = (wxEvtHandler *)(nullptr);
	if (args.IsValid(3)) eventSink = Object_wx_EvtHandler::GetObject(args, 3)->GetEntity();
	bool rtn = pThis->GetEntity()->Disconnect(eventType, *function, userData, eventSink);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_EvtHandler, Disconnect_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "eventType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "function", VTYPE_wx_ObjectEventFunction, OCCUR_ZeroOrOnce);
	DeclareArg(env, "userData", VTYPE_wx_Object, OCCUR_ZeroOrOnce);
	DeclareArg(env, "eventSink", VTYPE_wx_EvtHandler, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EvtHandler, Disconnect_1)
{
#if 0
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = wxID_ANY;
	if (args.IsValid(0)) id = args.GetInt(0);
	wxEventType eventType = wxEVT_NULL;
	if (args.IsValid(1)) eventType = static_cast<wxEventType>(args.GetInt(1));
	wxObjectEventFunction *function = (wxObjectEventFunction *)(&nullptr);
	if (args.IsValid(2)) function = Object_wx_ObjectEventFunction::GetObject(args, 2)->GetEntity();
	wxObject *userData = (wxObject *)(nullptr);
	if (args.IsValid(3)) userData = Object_wx_Object::GetObject(args, 3)->GetEntity();
	wxEvtHandler *eventSink = (wxEvtHandler *)(nullptr);
	if (args.IsValid(4)) eventSink = Object_wx_EvtHandler::GetObject(args, 4)->GetEntity();
	bool rtn = pThis->GetEntity()->Disconnect(id, eventType, *function, userData, eventSink);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_EvtHandler, Disconnect_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "lastId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "eventType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "function", VTYPE_wx_ObjectEventFunction, OCCUR_ZeroOrOnce);
	DeclareArg(env, "userData", VTYPE_wx_Object, OCCUR_ZeroOrOnce);
	DeclareArg(env, "eventSink", VTYPE_wx_EvtHandler, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EvtHandler, Disconnect_2)
{
#if 0
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	int lastId = wxID_ANY;
	if (args.IsValid(1)) lastId = args.GetInt(1);
	wxEventType eventType = wxEVT_NULL;
	if (args.IsValid(2)) eventType = static_cast<wxEventType>(args.GetInt(2));
	wxObjectEventFunction *function = (wxObjectEventFunction *)(&nullptr);
	if (args.IsValid(3)) function = Object_wx_ObjectEventFunction::GetObject(args, 3)->GetEntity();
	wxObject *userData = (wxObject *)(nullptr);
	if (args.IsValid(4)) userData = Object_wx_Object::GetObject(args, 4)->GetEntity();
	wxEvtHandler *eventSink = (wxEvtHandler *)(nullptr);
	if (args.IsValid(5)) eventSink = Object_wx_EvtHandler::GetObject(args, 5)->GetEntity();
	bool rtn = pThis->GetEntity()->Disconnect(id, lastId, eventType, *function, userData, eventSink);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_EvtHandler, GetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, GetClientData)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->GetClientData();
	return Value::Null;
}

Gura_DeclareMethod(wx_EvtHandler, GetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EvtHandler, GetClientObject)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wx_ClientData *rtn = dynamic_cast<wx_ClientData *>(pThis->GetEntity()->GetClientObject());
	if (rtn == nullptr) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_wx_ClientData(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_EvtHandler, GetEvtHandlerEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EvtHandler, GetEvtHandlerEnabled)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetEvtHandlerEnabled();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_EvtHandler, GetNextHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EvtHandler, GetNextHandler)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEvtHandler *rtn = (wxEvtHandler *)pThis->GetEntity()->GetNextHandler();
	return ReturnValue(env, sig, args, Value(new Object_wx_EvtHandler(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_EvtHandler, GetPreviousHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EvtHandler, GetPreviousHandler)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEvtHandler *rtn = (wxEvtHandler *)pThis->GetEntity()->GetPreviousHandler();
	return ReturnValue(env, sig, args, Value(new Object_wx_EvtHandler(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_EvtHandler, ProcessEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_Event, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EvtHandler, ProcessEvent)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEvent *event = Object_wx_Event::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->ProcessEvent(*event);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_EvtHandler, SearchEventTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "table", VTYPE_wx_EventTable, OCCUR_Once);
	DeclareArg(env, "event", VTYPE_wx_Event, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EvtHandler, SearchEventTable)
{
#if 0
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEventTable *table = Object_wx_EventTable::GetObject(args, 0)->GetEntity();
	wxEvent *event = Object_wx_Event::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->SearchEventTable(*table, *event);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_EvtHandler, SetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_EvtHandler, SetClientData)
{
#if 0
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int data = args.GetInt(0);
	pThis->GetEntity()->SetClientData(data);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_EvtHandler, SetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "data", VTYPE_wx_ClientData, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, SetClientObject)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxClientData *data = Object_wx_ClientData::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetClientObject(data);
	return Value::Null;
}

Gura_DeclareMethod(wx_EvtHandler, SetEvtHandlerEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enabled", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, SetEvtHandlerEnabled)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool enabled = args.GetBoolean(0);
	pThis->GetEntity()->SetEvtHandlerEnabled(enabled);
	return Value::Null;
}

Gura_DeclareMethod(wx_EvtHandler, SetNextHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_EvtHandler, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, SetNextHandler)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEvtHandler *handler = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetNextHandler(handler);
	return Value::Null;
}

Gura_DeclareMethod(wx_EvtHandler, SetPreviousHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_EvtHandler, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, SetPreviousHandler)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEvtHandler *handler = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPreviousHandler(handler);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxEvtHandler
//----------------------------------------------------------------------------
Object_wx_EvtHandler::~Object_wx_EvtHandler()
{
}

Object *Object_wx_EvtHandler::Clone() const
{
	return nullptr;
}

String Object_wx_EvtHandler::ToString(bool exprFlag)
{
	String rtn("<wx.EvtHandler:");
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
// Class implementation for wxEvtHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EvtHandler)
{
	Gura_RealizeUserSymbol(ProcessEvent);
	Gura_RealizeUserSymbol(SearchEventTable);
	Gura_AssignFunction(EvtHandler);
	Gura_AssignMethod(wx_EvtHandler, AddPendingEvent);
	Gura_AssignMethod(wx_EvtHandler, Bind);
	Gura_AssignMethod(wx_EvtHandler, Connect);
	Gura_AssignMethod(wx_EvtHandler, Disconnect);
	Gura_AssignMethod(wx_EvtHandler, Disconnect_1);
	Gura_AssignMethod(wx_EvtHandler, Disconnect_2);
	Gura_AssignMethod(wx_EvtHandler, GetClientData);
	Gura_AssignMethod(wx_EvtHandler, GetClientObject);
	Gura_AssignMethod(wx_EvtHandler, GetEvtHandlerEnabled);
	Gura_AssignMethod(wx_EvtHandler, GetNextHandler);
	Gura_AssignMethod(wx_EvtHandler, GetPreviousHandler);
	Gura_AssignMethod(wx_EvtHandler, ProcessEvent);
	Gura_AssignMethod(wx_EvtHandler, SearchEventTable);
	Gura_AssignMethod(wx_EvtHandler, SetClientData);
	Gura_AssignMethod(wx_EvtHandler, SetClientObject);
	Gura_AssignMethod(wx_EvtHandler, SetEvtHandlerEnabled);
	Gura_AssignMethod(wx_EvtHandler, SetNextHandler);
	Gura_AssignMethod(wx_EvtHandler, SetPreviousHandler);
}

Gura_ImplementDescendantCreator(wx_EvtHandler)
{
	return new Object_wx_EvtHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
