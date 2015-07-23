//----------------------------------------------------------------------------
// wxRichTextEvent
// extracted from richtextevent.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextEvent: public wxRichTextEvent, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_RichTextEvent *_pObj;
public:
	inline wx_RichTextEvent(const wxRichTextEvent& event) : wxRichTextEvent(event), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_RichTextEvent(wxEventType commandType, int winid) : wxRichTextEvent(commandType, winid), _pSig(nullptr), _pObj(nullptr) {}
	~wx_RichTextEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextEvent *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextEvent::~wx_RichTextEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RichTextEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(RichTextEvent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_RichTextEvent, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextEvent, Clone)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEvent *rtn = (wxEvent *)pThis->GetEntity()->Clone();
	return ReturnValue(env, args, Value(new Object_wx_Event(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextEvent, GetCharacter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextEvent, GetCharacter)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxChar rtn = pThis->GetEntity()->GetCharacter();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextEvent, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextEvent, GetFlags)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetFlags();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextEvent, GetNewStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextEvent, GetNewStyleSheet)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *rtn = (wxRichTextStyleSheet *)pThis->GetEntity()->GetNewStyleSheet();
	return ReturnValue(env, args, Value(new Object_wx_RichTextStyleSheet(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextEvent, GetOldStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextEvent, GetOldStyleSheet)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *rtn = (wxRichTextStyleSheet *)pThis->GetEntity()->GetOldStyleSheet();
	return ReturnValue(env, args, Value(new Object_wx_RichTextStyleSheet(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextEvent, GetPosition)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextEvent, GetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextEvent, GetRange)
{
	Object_wx_RichTextEvent *pThis = Object_wx_RichTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextRange rtn = pThis->GetEntity()->GetRange();
	return ReturnValue(env, args, Value(new Object_wx_RichTextRange(new wxRichTextRange(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextEvent, SetCharacter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	return nullptr;
}

String Object_wx_RichTextEvent::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextEvent:");
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
// Class implementation for wxRichTextEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextEvent)
{
	Gura_AssignFunction(RichTextEvent);
	Gura_AssignFunction(RichTextEvent_1);
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
	return new Object_wx_RichTextEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
