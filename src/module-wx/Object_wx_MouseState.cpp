//----------------------------------------------------------------------------
// wxMouseState
// (handcoded)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(Language);
Gura_DeclarePrivUserSymbol(CanonicalName);
Gura_DeclarePrivUserSymbol(WinLang);
Gura_DeclarePrivUserSymbol(WinSublang);
Gura_DeclarePrivUserSymbol(Description);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MouseState: public wxMouseState, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MouseState *_pObj;
public:
	inline wx_MouseState() : wxMouseState(), _sig(NULL), _pObj(NULL) {}
	~wx_MouseState();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MouseState *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MouseState::~wx_MouseState()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MouseState::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMouseState
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_MouseState, GetX)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, GetX)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pThis->GetEntity()->GetX();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, GetY)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, GetY)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pThis->GetEntity()->GetY();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, LeftDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, LeftDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->LeftDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, MiddleDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, MiddleDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->MiddleDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, RightDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, RightDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->RightDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, ControlDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, ControlDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->ControlDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, ShiftDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, ShiftDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->ShiftDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, AltDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, AltDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->AltDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, MetaDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, MetaDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->MetaDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, CmdDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, CmdDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CmdDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, SetX)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetX)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = args.GetInt(0);
	pThis->GetEntity()->SetX(x);
	return Value::Null;
}

Gura_DeclareMethod(wx_MouseState, SetY)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetY)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord y = args.GetInt(0);
	pThis->GetEntity()->SetY(y);
	return Value::Null;
}

Gura_DeclareMethod(wx_MouseState, SetLeftDown)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "down", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetLeftDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool down = args.GetBoolean(0);
	pThis->GetEntity()->SetLeftDown(down);
	return Value::Null;
}

Gura_DeclareMethod(wx_MouseState, SetMiddleDown)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "down", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetMiddleDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool down = args.GetBoolean(0);
	pThis->GetEntity()->SetMiddleDown(down);
	return Value::Null;
}

Gura_DeclareMethod(wx_MouseState, SetRightDown)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "down", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetRightDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool down = args.GetBoolean(0);
	pThis->GetEntity()->SetRightDown(down);
	return Value::Null;
}

Gura_DeclareMethod(wx_MouseState, SetControlDown)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "down", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetControlDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool down = args.GetBoolean(0);
	pThis->GetEntity()->SetControlDown(down);
	return Value::Null;
}

Gura_DeclareMethod(wx_MouseState, SetShiftDown)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "down", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetShiftDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool down = args.GetBoolean(0);
	pThis->GetEntity()->SetShiftDown(down);
	return Value::Null;
}

Gura_DeclareMethod(wx_MouseState, SetAltDown)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "down", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetAltDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool down = args.GetBoolean(0);
	pThis->GetEntity()->SetAltDown(down);
	return Value::Null;
}

Gura_DeclareMethod(wx_MouseState, SetMetaDown)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "down", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetMetaDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool down = args.GetBoolean(0);
	pThis->GetEntity()->SetMetaDown(down);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxMouseState
//----------------------------------------------------------------------------
Object_wx_MouseState::~Object_wx_MouseState()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_MouseState::Clone() const
{
	return NULL;
}

String Object_wx_MouseState::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.MouseState:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p", GetEntity());
		rtn += buff;
		rtn += ">";
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxMouseState
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseState)
{
	Gura_AssignMethod(wx_MouseState, GetX);
	Gura_AssignMethod(wx_MouseState, GetY);
	Gura_AssignMethod(wx_MouseState, LeftDown);
	Gura_AssignMethod(wx_MouseState, MiddleDown);
	Gura_AssignMethod(wx_MouseState, RightDown);
	Gura_AssignMethod(wx_MouseState, ControlDown);
	Gura_AssignMethod(wx_MouseState, ShiftDown);
	Gura_AssignMethod(wx_MouseState, AltDown);
	Gura_AssignMethod(wx_MouseState, MetaDown);
	Gura_AssignMethod(wx_MouseState, CmdDown);
	Gura_AssignMethod(wx_MouseState, SetX);
	Gura_AssignMethod(wx_MouseState, SetY);
	Gura_AssignMethod(wx_MouseState, SetLeftDown);
	Gura_AssignMethod(wx_MouseState, SetMiddleDown);
	Gura_AssignMethod(wx_MouseState, SetRightDown);
	Gura_AssignMethod(wx_MouseState, SetControlDown);
	Gura_AssignMethod(wx_MouseState, SetShiftDown);
	Gura_AssignMethod(wx_MouseState, SetAltDown);
	Gura_AssignMethod(wx_MouseState, SetMetaDown);
}

Gura_ImplementDescendantCreator(wx_MouseState)
{
	return new Object_wx_MouseState((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
