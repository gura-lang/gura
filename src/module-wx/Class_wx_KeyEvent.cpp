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
	//Gura::Signal *_pSig;
	Object_wx_KeyEvent *_pObj;
public:
	inline wx_KeyEvent(WXTYPE keyEventType) : wxKeyEvent(keyEventType), _pObj(nullptr) {}
	~wx_KeyEvent();
	inline void AssocWithGura(Object_wx_KeyEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_KeyEvent::~wx_KeyEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_KeyEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxKeyEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(KeyEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_KeyEvent));
	DeclareArg(env, "keyEventType", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(KeyEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	WXTYPE keyEventType = static_cast<WXTYPE>(args.GetInt(0));
	wx_KeyEvent *pEntity = new wx_KeyEvent(keyEventType);
	Object_wx_KeyEvent *pObj = Object_wx_KeyEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_KeyEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_KeyEvent, AltDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, AltDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->AltDown();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, CmdDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, CmdDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CmdDown();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, ControlDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, ControlDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->ControlDown();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, GetKeyCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, GetKeyCode)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetKeyCode();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, GetModifiers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, GetModifiers)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetModifiers();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, args, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_KeyEvent, GetPosition_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_KeyEvent, GetPosition_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long x = args.GetLong(0);
	long y = args.GetLong(1);
	pThis->GetEntity()->GetPosition(x, y);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_KeyEvent, GetRawKeyCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, GetRawKeyCode)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxUint32 rtn = pThis->GetEntity()->GetRawKeyCode();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, GetRawKeyFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, GetRawKeyFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxUint32 rtn = pThis->GetEntity()->GetRawKeyFlags();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, GetUnicodeKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, GetUnicodeKey)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar rtn = pThis->GetEntity()->GetUnicodeKey();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_KeyEvent, GetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, GetX)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetX();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, GetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, GetY)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetY();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, HasModifiers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, HasModifiers)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasModifiers();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, MetaDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, MetaDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->MetaDown();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_KeyEvent, ShiftDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_KeyEvent, ShiftDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyEvent *pThis = Object_wx_KeyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->ShiftDown();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxKeyEvent
//----------------------------------------------------------------------------
Object_wx_KeyEvent::~Object_wx_KeyEvent()
{
}

Object *Object_wx_KeyEvent::Clone() const
{
	return nullptr;
}

String Object_wx_KeyEvent::ToString(bool exprFlag)
{
	String rtn("<wx.KeyEvent:");
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
	return new Object_wx_KeyEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
