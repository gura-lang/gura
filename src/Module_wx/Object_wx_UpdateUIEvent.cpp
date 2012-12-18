//----------------------------------------------------------------------------
// wxUpdateUIEvent
// extracted from upduievt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_UpdateUIEvent: public wxUpdateUIEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_UpdateUIEvent *_pObj;
public:
	inline wx_UpdateUIEvent(wxWindowID commandId) : wxUpdateUIEvent(commandId), _sig(NULL), _pObj(NULL) {}
	~wx_UpdateUIEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_UpdateUIEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_UpdateUIEvent::~wx_UpdateUIEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_UpdateUIEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxUpdateUIEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(UpdateUIEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_UpdateUIEvent));
	DeclareArg(env, "commandId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(UpdateUIEvent)
{
	wxWindowID commandId = 0;
	if (args.IsValid(0)) commandId = static_cast<wxWindowID>(args.GetInt(0));
	wx_UpdateUIEvent *pEntity = new wx_UpdateUIEvent(commandId);
	Object_wx_UpdateUIEvent *pObj = Object_wx_UpdateUIEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_UpdateUIEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareClassMethod(wx_UpdateUIEvent, CanUpdate)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_UpdateUIEvent, CanUpdate)
{
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	bool rtn = wxUpdateUIEvent::CanUpdate(window);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_UpdateUIEvent, Check)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "check", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, Check)
{
	Object_wx_UpdateUIEvent *pSelf = Object_wx_UpdateUIEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool check = args.GetBoolean(0);
	pSelf->GetEntity()->Check(check);
	return Value::Null;
}

Gura_DeclareMethod(wx_UpdateUIEvent, Enable)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, Enable)
{
	Object_wx_UpdateUIEvent *pSelf = Object_wx_UpdateUIEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool enable = args.GetBoolean(0);
	pSelf->GetEntity()->Enable(enable);
	return Value::Null;
}

Gura_DeclareMethod(wx_UpdateUIEvent, Show)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, Show)
{
	Object_wx_UpdateUIEvent *pSelf = Object_wx_UpdateUIEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool show = args.GetBoolean(0);
	pSelf->GetEntity()->Show(show);
	return Value::Null;
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetChecked)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetChecked)
{
	Object_wx_UpdateUIEvent *pSelf = Object_wx_UpdateUIEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->GetChecked();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetEnabled)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetEnabled)
{
	Object_wx_UpdateUIEvent *pSelf = Object_wx_UpdateUIEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->GetEnabled();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetShown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetShown)
{
	Object_wx_UpdateUIEvent *pSelf = Object_wx_UpdateUIEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->GetShown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetSetChecked)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetSetChecked)
{
	Object_wx_UpdateUIEvent *pSelf = Object_wx_UpdateUIEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->GetSetChecked();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetSetEnabled)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetSetEnabled)
{
	Object_wx_UpdateUIEvent *pSelf = Object_wx_UpdateUIEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->GetSetEnabled();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetSetShown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetSetShown)
{
	Object_wx_UpdateUIEvent *pSelf = Object_wx_UpdateUIEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->GetSetShown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetSetText)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetSetText)
{
	Object_wx_UpdateUIEvent *pSelf = Object_wx_UpdateUIEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->GetSetText();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetText)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetText)
{
	Object_wx_UpdateUIEvent *pSelf = Object_wx_UpdateUIEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetText();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_UpdateUIEvent, GetMode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_UpdateUIEvent, GetMode)
{
	wxUpdateUIMode rtn = wxUpdateUIEvent::GetMode();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_UpdateUIEvent, GetUpdateInterval)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_UpdateUIEvent, GetUpdateInterval)
{
	long rtn = wxUpdateUIEvent::GetUpdateInterval();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_UpdateUIEvent, ResetUpdateTime)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_UpdateUIEvent, ResetUpdateTime)
{
	wxUpdateUIEvent::ResetUpdateTime();
	return Value::Null;
}

Gura_DeclareClassMethod(wx_UpdateUIEvent, SetMode_)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_UpdateUIEvent, SetMode_)
{
	wxUpdateUIMode mode = static_cast<wxUpdateUIMode>(args.GetInt(0));
	wxUpdateUIEvent::SetMode(mode);
	return Value::Null;
}

Gura_DeclareMethod(wx_UpdateUIEvent, SetText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, SetText)
{
	Object_wx_UpdateUIEvent *pSelf = Object_wx_UpdateUIEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetText(text);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_UpdateUIEvent, SetUpdateInterval)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "updateInterval", VTYPE_number, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_UpdateUIEvent, SetUpdateInterval)
{
	long updateInterval = args.GetLong(0);
	wxUpdateUIEvent::SetUpdateInterval(updateInterval);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxUpdateUIEvent
//----------------------------------------------------------------------------
Object_wx_UpdateUIEvent::~Object_wx_UpdateUIEvent()
{
}

Object *Object_wx_UpdateUIEvent::Clone() const
{
	return NULL;
}

String Object_wx_UpdateUIEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.UpdateUIEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_UpdateUIEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(UpdateUIEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxUpdateUIEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_UpdateUIEvent)
{
	Gura_AssignMethod(wx_UpdateUIEvent, CanUpdate);
	Gura_AssignMethod(wx_UpdateUIEvent, Check);
	Gura_AssignMethod(wx_UpdateUIEvent, Enable);
	Gura_AssignMethod(wx_UpdateUIEvent, Show);
	Gura_AssignMethod(wx_UpdateUIEvent, GetChecked);
	Gura_AssignMethod(wx_UpdateUIEvent, GetEnabled);
	Gura_AssignMethod(wx_UpdateUIEvent, GetShown);
	Gura_AssignMethod(wx_UpdateUIEvent, GetSetChecked);
	Gura_AssignMethod(wx_UpdateUIEvent, GetSetEnabled);
	Gura_AssignMethod(wx_UpdateUIEvent, GetSetShown);
	Gura_AssignMethod(wx_UpdateUIEvent, GetSetText);
	Gura_AssignMethod(wx_UpdateUIEvent, GetText);
	Gura_AssignMethod(wx_UpdateUIEvent, GetMode);
	Gura_AssignMethod(wx_UpdateUIEvent, GetUpdateInterval);
	Gura_AssignMethod(wx_UpdateUIEvent, ResetUpdateTime);
	Gura_AssignMethodEx(wx_UpdateUIEvent, SetMode_, "SetMode");
	Gura_AssignMethod(wx_UpdateUIEvent, SetText);
	Gura_AssignMethod(wx_UpdateUIEvent, SetUpdateInterval);
}

Gura_ImplementDescendantCreator(wx_UpdateUIEvent)
{
	return new Object_wx_UpdateUIEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
