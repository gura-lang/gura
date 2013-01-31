//----------------------------------------------------------------------------
// wxRichTextEvent
// extracted from richtextevent.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextEvent: public wxRichTextEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RichTextEvent *_pObj;
public:
	inline wx_RichTextEvent(const wxRichTextEvent& event) : wxRichTextEvent(event), _sig(NULL), _pObj(NULL) {}
	inline wx_RichTextEvent(wxEventType commandType, int winid) : wxRichTextEvent(commandType, winid), _sig(NULL), _pObj(NULL) {}
	~wx_RichTextEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextEvent::~wx_RichTextEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RichTextEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextEvent));
	DeclareArg(env, "event", VTYPE_wx_RichTextEvent, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxRichTextEvent *event = Object_wx_RichTextEvent::GetObject(args, 0)->GetEntity();
	wx_RichTextEvent *pEntity = new wx_RichTextEvent(*event);
	Object_wx_RichTextEvent *pObj = Object_wx_RichTextEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(RichTextEvent_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextEvent));
	DeclareArg(env, "commandType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "winid", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextEvent_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxEventType commandType = wxEVT_NULL;
	if (args.IsValid(0)) commandType = static_cast<wxEventType>(args.GetInt(0));
	int winid = 0;
	if (args.IsValid(1)) winid = args.GetInt(1);
	wx_RichTextEvent *pEntity = new wx_RichTextEvent(commandType, winid);
	Object_wx_RichTextEvent *pObj = Object_wx_RichTextEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_RichTextEvent, Clone)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextEvent, Clone)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEvent *rtn = (wxEvent *)pThis->GetEntity()->Clone();
	return ReturnValue(env, sig, args, Value(new Object_wx_Event(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextEvent, GetCharacter)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextEvent, GetCharacter)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxChar rtn = pThis->GetEntity()->GetCharacter();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextEvent, GetFlags)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextEvent, GetFlags)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetFlags();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextEvent, GetNewStyleSheet)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextEvent, GetNewStyleSheet)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *rtn = (wxRichTextStyleSheet *)pThis->GetEntity()->GetNewStyleSheet();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextStyleSheet(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextEvent, GetOldStyleSheet)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextEvent, GetOldStyleSheet)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *rtn = (wxRichTextStyleSheet *)pThis->GetEntity()->GetOldStyleSheet();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextStyleSheet(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextEvent, GetPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextEvent, GetPosition)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextEvent, GetRange)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextEvent, GetRange)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextRange rtn = pThis->GetEntity()->GetRange();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextRange(new wxRichTextRange(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextEvent, SetCharacter)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, SetCharacter)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	pThis->GetEntity()->SetCharacter(ch);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextEvent, SetFlags)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, SetFlags)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int flags = args.GetInt(0);
	pThis->GetEntity()->SetFlags(flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextEvent, SetNewStyleSheet)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sheet", VTYPE_wx_RichTextStyleSheet, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, SetNewStyleSheet)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *sheet = Object_wx_RichTextStyleSheet::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetNewStyleSheet(sheet);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextEvent, SetOldStyleSheet)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sheet", VTYPE_wx_RichTextStyleSheet, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, SetOldStyleSheet)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *sheet = Object_wx_RichTextStyleSheet::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetOldStyleSheet(sheet);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextEvent, SetPosition)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, SetPosition)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long pos = args.GetLong(0);
	pThis->GetEntity()->SetPosition(pos);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextEvent, SetRange)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextEvent, SetRange)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetRange(*range);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextEvent
//----------------------------------------------------------------------------
Object_wx_RichTextEvent::~Object_wx_RichTextEvent()
{
}

Object *Object_wx_RichTextEvent::Clone() const
{
	return NULL;
}

String Object_wx_RichTextEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.RichTextEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_RichTextEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(RichTextEvent);
	Gura_AssignFunction(RichTextEvent_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextEvent)
{
	Gura_AssignMethod(wx_RichTextEvent, Clone);
	Gura_AssignMethod(wx_RichTextEvent, GetCharacter);
	Gura_AssignMethod(wx_RichTextEvent, GetFlags);
	Gura_AssignMethod(wx_RichTextEvent, GetNewStyleSheet);
	Gura_AssignMethod(wx_RichTextEvent, GetOldStyleSheet);
	Gura_AssignMethod(wx_RichTextEvent, GetPosition);
	Gura_AssignMethod(wx_RichTextEvent, GetRange);
	Gura_AssignMethod(wx_RichTextEvent, SetCharacter);
	Gura_AssignMethod(wx_RichTextEvent, SetFlags);
	Gura_AssignMethod(wx_RichTextEvent, SetNewStyleSheet);
	Gura_AssignMethod(wx_RichTextEvent, SetOldStyleSheet);
	Gura_AssignMethod(wx_RichTextEvent, SetPosition);
	Gura_AssignMethod(wx_RichTextEvent, SetRange);
}

Gura_ImplementDescendantCreator(wx_RichTextEvent)
{
	return new Object_wx_RichTextEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
