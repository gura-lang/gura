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
	//Gura::Signal *_pSig;
	Object_wx_MouseState *_pObj;
public:
	inline wx_MouseState() : wxMouseState(), _pObj(nullptr) {}
	~wx_MouseState();
	inline void AssocWithGura(Object_wx_MouseState *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MouseState::~wx_MouseState()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MouseState::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMouseState
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_MouseState, GetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, GetX)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord rtn = pThis->GetEntity()->GetX();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, GetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, GetY)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord rtn = pThis->GetEntity()->GetY();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, LeftIsDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, LeftIsDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->LeftIsDown();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, MiddleIsDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, MiddleIsDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->MiddleIsDown();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, RightIsDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, RightIsDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->RightIsDown();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, ControlDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, ControlDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->ControlDown();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, ShiftDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, ShiftDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->ShiftDown();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, AltDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, AltDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->AltDown();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, MetaDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, MetaDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->MetaDown();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, CmdDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseState, CmdDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CmdDown();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_MouseState, SetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetX)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = arg.GetInt(0);
	pThis->GetEntity()->SetX(x);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, SetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetY)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord y = arg.GetInt(0);
	pThis->GetEntity()->SetY(y);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, SetLeftDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "down", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetLeftDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool down = arg.GetBoolean(0);
	pThis->GetEntity()->SetLeftDown(down);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, SetMiddleDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "down", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetMiddleDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool down = arg.GetBoolean(0);
	pThis->GetEntity()->SetMiddleDown(down);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, SetRightDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "down", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetRightDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool down = arg.GetBoolean(0);
	pThis->GetEntity()->SetRightDown(down);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, SetControlDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "down", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetControlDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool down = arg.GetBoolean(0);
	pThis->GetEntity()->SetControlDown(down);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, SetShiftDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "down", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetShiftDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool down = arg.GetBoolean(0);
	pThis->GetEntity()->SetShiftDown(down);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, SetAltDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "down", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetAltDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool down = arg.GetBoolean(0);
	pThis->GetEntity()->SetAltDown(down);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, SetMetaDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "down", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetMetaDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool down = arg.GetBoolean(0);
	pThis->GetEntity()->SetMetaDown(down);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxMouseState
//----------------------------------------------------------------------------
Object_wx_MouseState::~Object_wx_MouseState()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_MouseState::Clone() const
{
	return nullptr;
}

String Object_wx_MouseState::ToString(bool exprFlag)
{
	String rtn("<wx.MouseState:");
	if (GetEntity() == nullptr) {
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
	Gura_AssignMethod(wx_MouseState, LeftIsDown);
	Gura_AssignMethod(wx_MouseState, MiddleIsDown);
	Gura_AssignMethod(wx_MouseState, RightIsDown);
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
	return new Object_wx_MouseState((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
