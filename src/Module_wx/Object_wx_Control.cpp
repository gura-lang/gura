//----------------------------------------------------------------------------
// wxControl
// extracted from control.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Control: public wxControl, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Control *_pObj;
public:
	~wx_Control();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Control *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Control::~wx_Control()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Control::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxControl
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Control, Command)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_Control, Command)
{
	Object_wx_Control *pSelf = Object_wx_Control::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->Command(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_Control, GetLabel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Control, GetLabel)
{
	Object_wx_Control *pSelf = Object_wx_Control::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetLabel();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Control, GetLabelText)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Control, GetLabelText)
{
	Object_wx_Control *pSelf = Object_wx_Control::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetLabelText();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_Control, GetLabelText_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Control, GetLabelText_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString label = wxString::FromUTF8(args.GetString(0));
	wxString rtn = wxControl::GetLabelText(label);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Control, SetLabel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Control, SetLabel)
{
	Object_wx_Control *pSelf = Object_wx_Control::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString label = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetLabel(label);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxControl
//----------------------------------------------------------------------------
Object_wx_Control::~Object_wx_Control()
{
}

Object *Object_wx_Control::Clone() const
{
	return NULL;
}

String Object_wx_Control::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Control:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Control::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxControl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Control)
{
	Gura_AssignMethod(wx_Control, Command);
	Gura_AssignMethod(wx_Control, GetLabel);
	Gura_AssignMethod(wx_Control, GetLabelText);
	Gura_AssignMethod(wx_Control, GetLabelText_1);
	Gura_AssignMethod(wx_Control, SetLabel);
}

Gura_ImplementDescendantCreator(wx_Control)
{
	return new Object_wx_Control((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
