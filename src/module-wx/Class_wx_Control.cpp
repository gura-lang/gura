//----------------------------------------------------------------------------
// wxControl
// extracted from control.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Control: public wxControl, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Control *_pObj;
public:
	~wx_Control();
	inline void AssocWithGura(Object_wx_Control *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Control::~wx_Control()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Control::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxControl
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Control, Command)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_Control, Command)
{
	Signal &sig = env.GetSignal();
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Command(*event);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Control, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Control, GetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetLabel();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Control, GetLabelText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Control, GetLabelText)
{
	Signal &sig = env.GetSignal();
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetLabelText();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_Control, GetLabelText_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Control, GetLabelText_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString label = wxString::FromUTF8(args.GetString(0));
	wxString rtn = wxControl::GetLabelText(label);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Control, SetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Control, SetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString label = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetLabel(label);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxControl
//----------------------------------------------------------------------------
Object_wx_Control::~Object_wx_Control()
{
}

Object *Object_wx_Control::Clone() const
{
	return nullptr;
}

String Object_wx_Control::ToString(bool exprFlag)
{
	String rtn("<wx.Control:");
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
	return new Object_wx_Control((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
