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
	Gura::Signal *_pSig;
	Object_wx_CommandEvent *_pObj;
public:
	inline wx_CommandEvent(WXTYPE commandEventType, int id) : wxCommandEvent(commandEventType, id), _pSig(nullptr), _pObj(nullptr) {}
	~wx_CommandEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_CommandEvent *pObj) {
		_pSig = &sig, _pObj = pObj;
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
	if (!CheckWxReady(sig)) return Value::Null;
	WXTYPE commandEventType = 0;
	if (args.IsValid(0)) commandEventType = static_cast<WXTYPE>(args.GetInt(0));
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_CommandEvent *pEntity = new wx_CommandEvent(commandEventType, id);
	Object_wx_CommandEvent *pObj = Object_wx_CommandEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_CommandEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_CommandEvent, Checked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CommandEvent, Checked)
{
#if 0
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Checked();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CommandEvent, GetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CommandEvent, GetClientObject)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wx_ClientData *rtn = dynamic_cast<wx_ClientData *>(pThis->GetEntity()->GetClientObject());
	if (rtn == nullptr) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_wx_ClientData(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_CommandEvent, GetExtraLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CommandEvent, GetExtraLong)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetExtraLong();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CommandEvent, GetInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CommandEvent, GetInt)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetInt();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CommandEvent, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CommandEvent, GetSelection)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CommandEvent, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CommandEvent, GetString)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetString();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_CommandEvent, IsChecked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CommandEvent, IsChecked)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsChecked();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CommandEvent, IsSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CommandEvent, IsSelection)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsSelection();
	return ReturnValue(env, sig, args, Value(rtn));
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
#if 0
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int clientData = args.GetInt(0);
	pThis->GetEntity()->SetClientData(clientData);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CommandEvent, SetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "clientObject", VTYPE_wx_ClientData, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, SetClientObject)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxClientData *clientObject = Object_wx_ClientData::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetClientObject(clientObject);
	return Value::Null;
}

Gura_DeclareMethod(wx_CommandEvent, SetExtraLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "extraLong", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, SetExtraLong)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long extraLong = args.GetLong(0);
	pThis->GetEntity()->SetExtraLong(extraLong);
	return Value::Null;
}

Gura_DeclareMethod(wx_CommandEvent, SetInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "intCommand", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, SetInt)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int intCommand = args.GetInt(0);
	pThis->GetEntity()->SetInt(intCommand);
	return Value::Null;
}

Gura_DeclareMethod(wx_CommandEvent, SetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, SetString)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString string = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetString(string);
	return Value::Null;
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
