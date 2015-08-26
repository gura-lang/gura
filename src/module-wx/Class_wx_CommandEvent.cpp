//----------------------------------------------------------------------------
// wxCommandEvent
// extracted from cmdevent.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CommandEvent: public wxCommandEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_CommandEvent *_pObj;
public:
	inline wx_CommandEvent(WXTYPE commandEventType, int id) : wxCommandEvent(commandEventType, id), _pObj(nullptr) {}
	~wx_CommandEvent();
	inline void AssocWithGura(Object_wx_CommandEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CommandEvent::~wx_CommandEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_CommandEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCommandEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(CommandEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_CommandEvent));
	DeclareArg(env, "commandEventType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CommandEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	WXTYPE commandEventType = 0;
	if (args.IsValid(0)) commandEventType = static_cast<WXTYPE>(args.GetInt(0));
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_CommandEvent *pEntity = new wx_CommandEvent(commandEventType, id);
	Object_wx_CommandEvent *pObj = Object_wx_CommandEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_CommandEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_CommandEvent, Checked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CommandEvent, Checked)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Checked();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandEvent, GetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CommandEvent, GetClientObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wx_ClientData *rtn = dynamic_cast<wx_ClientData *>(pThis->GetEntity()->GetClientObject());
	if (rtn == nullptr) return Value::Nil;
	return ReturnValue(env, args, Value(new Object_wx_ClientData(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_CommandEvent, GetExtraLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CommandEvent, GetExtraLong)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetExtraLong();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_CommandEvent, GetInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CommandEvent, GetInt)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetInt();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_CommandEvent, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CommandEvent, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_CommandEvent, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CommandEvent, GetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetString();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_CommandEvent, IsChecked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CommandEvent, IsChecked)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsChecked();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_CommandEvent, IsSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CommandEvent, IsSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsSelection();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_CommandEvent, SetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_CommandEvent, SetClientData)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int clientData = args.GetInt(0);
	pThis->GetEntity()->SetClientData(clientData);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandEvent, SetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "clientObject", VTYPE_wx_ClientData, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, SetClientObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxClientData *clientObject = Object_wx_ClientData::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetClientObject(clientObject);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandEvent, SetExtraLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "extraLong", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, SetExtraLong)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long extraLong = args.GetLong(0);
	pThis->GetEntity()->SetExtraLong(extraLong);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandEvent, SetInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "intCommand", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, SetInt)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int intCommand = args.GetInt(0);
	pThis->GetEntity()->SetInt(intCommand);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandEvent, SetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, SetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString string = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetString(string);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxCommandEvent
//----------------------------------------------------------------------------
Object_wx_CommandEvent::~Object_wx_CommandEvent()
{
}

Object *Object_wx_CommandEvent::Clone() const
{
	return nullptr;
}

String Object_wx_CommandEvent::ToString(bool exprFlag)
{
	String rtn("<wx.CommandEvent:");
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
// Class implementation for wxCommandEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CommandEvent)
{
	Gura_AssignFunction(CommandEvent);
	Gura_AssignMethod(wx_CommandEvent, Checked);
	Gura_AssignMethod(wx_CommandEvent, GetClientObject);
	Gura_AssignMethod(wx_CommandEvent, GetExtraLong);
	Gura_AssignMethod(wx_CommandEvent, GetInt);
	Gura_AssignMethod(wx_CommandEvent, GetSelection);
	Gura_AssignMethod(wx_CommandEvent, GetString);
	Gura_AssignMethod(wx_CommandEvent, IsChecked);
	Gura_AssignMethod(wx_CommandEvent, IsSelection);
	Gura_AssignMethod(wx_CommandEvent, SetClientData);
	Gura_AssignMethod(wx_CommandEvent, SetClientObject);
	Gura_AssignMethod(wx_CommandEvent, SetExtraLong);
	Gura_AssignMethod(wx_CommandEvent, SetInt);
	Gura_AssignMethod(wx_CommandEvent, SetString);
}

Gura_ImplementDescendantCreator(wx_CommandEvent)
{
	return new Object_wx_CommandEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
