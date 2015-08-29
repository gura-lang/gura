//----------------------------------------------------------------------------
// wxUpdateUIEvent
// extracted from upduievt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_UpdateUIEvent: public wxUpdateUIEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_UpdateUIEvent *_pObj;
public:
	inline wx_UpdateUIEvent(wxWindowID commandId) : wxUpdateUIEvent(commandId), _pObj(nullptr) {}
	~wx_UpdateUIEvent();
	inline void AssocWithGura(Object_wx_UpdateUIEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_UpdateUIEvent::~wx_UpdateUIEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_UpdateUIEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxUpdateUIEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(UpdateUIEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_UpdateUIEvent));
	DeclareArg(env, "commandId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(UpdateUIEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindowID commandId = 0;
	if (arg.IsValid(0)) commandId = static_cast<wxWindowID>(arg.GetInt(0));
	wx_UpdateUIEvent *pEntity = new wx_UpdateUIEvent(commandId);
	Object_wx_UpdateUIEvent *pObj = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_UpdateUIEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareClassMethod(wx_UpdateUIEvent, CanUpdate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_UpdateUIEvent, CanUpdate)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	bool rtn = wxUpdateUIEvent::CanUpdate(window);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_UpdateUIEvent, Check)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "check", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, Check)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool check = arg.GetBoolean(0);
	pThis->GetEntity()->Check(check);
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, Enable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, Enable)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool enable = arg.GetBoolean(0);
	pThis->GetEntity()->Enable(enable);
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool show = arg.GetBoolean(0);
	pThis->GetEntity()->Show(show);
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetChecked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetChecked)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetChecked();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetEnabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetEnabled();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetShown)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetShown();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetSetChecked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetSetChecked)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetSetChecked();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetSetEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetSetEnabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetSetEnabled();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetSetShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetSetShown)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetSetShown();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetSetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetSetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetSetText();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetText();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_UpdateUIEvent, GetMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_UpdateUIEvent, GetMode)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxUpdateUIMode rtn = wxUpdateUIEvent::GetMode();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareClassMethod(wx_UpdateUIEvent, GetUpdateInterval)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_UpdateUIEvent, GetUpdateInterval)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	long rtn = wxUpdateUIEvent::GetUpdateInterval();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareClassMethod(wx_UpdateUIEvent, ResetUpdateTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_UpdateUIEvent, ResetUpdateTime)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxUpdateUIEvent::ResetUpdateTime();
	return Value::Nil;
}

Gura_DeclareClassMethodAlias(wx_UpdateUIEvent, SetMode_, "SetMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_UpdateUIEvent, SetMode_)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxUpdateUIMode mode = static_cast<wxUpdateUIMode>(arg.GetInt(0));
	wxUpdateUIEvent::SetMode(mode);
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, SetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, SetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetText(text);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_UpdateUIEvent, SetUpdateInterval)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "updateInterval", VTYPE_number, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_UpdateUIEvent, SetUpdateInterval)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	long updateInterval = arg.GetLong(0);
	wxUpdateUIEvent::SetUpdateInterval(updateInterval);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxUpdateUIEvent
//----------------------------------------------------------------------------
Object_wx_UpdateUIEvent::~Object_wx_UpdateUIEvent()
{
}

Object *Object_wx_UpdateUIEvent::Clone() const
{
	return nullptr;
}

String Object_wx_UpdateUIEvent::ToString(bool exprFlag)
{
	String rtn("<wx.UpdateUIEvent:");
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
// Class implementation for wxUpdateUIEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_UpdateUIEvent)
{
	Gura_AssignFunction(UpdateUIEvent);
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
	Gura_AssignMethod(wx_UpdateUIEvent, SetMode_);
	Gura_AssignMethod(wx_UpdateUIEvent, SetText);
	Gura_AssignMethod(wx_UpdateUIEvent, SetUpdateInterval);
}

Gura_ImplementDescendantCreator(wx_UpdateUIEvent)
{
	return new Object_wx_UpdateUIEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
