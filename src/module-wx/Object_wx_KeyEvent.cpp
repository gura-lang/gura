//----------------------------------------------------------------------------
// wxKeyEvent
// extracted from keyevent.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_KeyEvent: public wxKeyEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_KeyEvent *_pObj;
public:
	inline wx_KeyEvent(WXTYPE keyEventType) : wxKeyEvent(keyEventType), _sig(NULL), _pObj(NULL) {}
	~wx_KeyEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_KeyEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_KeyEvent::~wx_KeyEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_KeyEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxKeyEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(KeyEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_KeyEvent));
	DeclareArg(env, "keyEventType", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(KeyEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	WXTYPE keyEventType = static_cast<WXTYPE>(args.GetInt(0));
	wx_KeyEvent *pEntity = new wx_KeyEvent(keyEventType);
	Object_wx_KeyEvent *pObj = Object_wx_KeyEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_KeyEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_KeyEvent, AltDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, AltDown)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->AltDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, CmdDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, CmdDown)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CmdDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, ControlDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, ControlDown)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->ControlDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, GetKeyCode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, GetKeyCode)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetKeyCode();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, GetModifiers)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, GetModifiers)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetModifiers();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, GetPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, GetPosition)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_KeyEvent, GetPosition_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_KeyEvent, GetPosition_1)
{
#if 0
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long x = args.GetLong(0);
	long y = args.GetLong(1);
	pThis->GetEntity()->GetPosition(x, y);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_KeyEvent, GetRawKeyCode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, GetRawKeyCode)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUint32 rtn = pThis->GetEntity()->GetRawKeyCode();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, GetRawKeyFlags)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, GetRawKeyFlags)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUint32 rtn = pThis->GetEntity()->GetRawKeyFlags();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, GetUnicodeKey)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, GetUnicodeKey)
{
#if 0
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxChar rtn = pThis->GetEntity()->GetUnicodeKey();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_KeyEvent, GetX)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, GetX)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetX();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, GetY)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, GetY)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetY();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, HasModifiers)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, HasModifiers)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasModifiers();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, MetaDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, MetaDown)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->MetaDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, ShiftDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, ShiftDown)
{
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->ShiftDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxKeyEvent
//----------------------------------------------------------------------------
Object_wx_KeyEvent::~Object_wx_KeyEvent()
{
}

Object *Object_wx_KeyEvent::Clone() const
{
	return NULL;
}

String Object_wx_KeyEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.KeyEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxKeyEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_KeyEvent)
{
	Gura_AssignFunction(KeyEvent);
	Gura_AssignMethod(wx_KeyEvent, AltDown);
	Gura_AssignMethod(wx_KeyEvent, CmdDown);
	Gura_AssignMethod(wx_KeyEvent, ControlDown);
	Gura_AssignMethod(wx_KeyEvent, GetKeyCode);
	Gura_AssignMethod(wx_KeyEvent, GetModifiers);
	Gura_AssignMethod(wx_KeyEvent, GetPosition);
	Gura_AssignMethod(wx_KeyEvent, GetPosition_1);
	Gura_AssignMethod(wx_KeyEvent, GetRawKeyCode);
	Gura_AssignMethod(wx_KeyEvent, GetRawKeyFlags);
	Gura_AssignMethod(wx_KeyEvent, GetUnicodeKey);
	Gura_AssignMethod(wx_KeyEvent, GetX);
	Gura_AssignMethod(wx_KeyEvent, GetY);
	Gura_AssignMethod(wx_KeyEvent, HasModifiers);
	Gura_AssignMethod(wx_KeyEvent, MetaDown);
	Gura_AssignMethod(wx_KeyEvent, ShiftDown);
}

Gura_ImplementDescendantCreator(wx_KeyEvent)
{
	return new Object_wx_KeyEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
