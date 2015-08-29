//----------------------------------------------------------------------------
// wxGridEvent
// extracted from gridevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridEvent: public wxGridEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_GridEvent *_pObj;
public:
	inline wx_GridEvent() : wxGridEvent(), _pObj(nullptr) {}
	inline wx_GridEvent(int id, wxEventType type, wxObject* obj, int row, int col, int x, int y, bool sel, bool control, bool shift, bool alt, bool meta) : wxGridEvent(id, type, obj, row, col, x, y, sel, control, shift, alt, meta), _pObj(nullptr) {}
	~wx_GridEvent();
	inline void AssocWithGura(Object_wx_GridEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridEvent::~wx_GridEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridEventEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridEventEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_GridEvent *pEntity = new wx_GridEvent();
	Object_wx_GridEvent *pObj = Object_wx_GridEvent::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(GridEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GridEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "obj", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "col", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "sel", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "control", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "shift", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "alt", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "meta", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxEventType type = static_cast<wxEventType>(arg.GetInt(1));
	wxObject *obj = Object_wx_Object::GetObject(arg, 2)->GetEntity();
	int row = -1;
	if (arg.IsValid(3)) row = arg.GetInt(3);
	int col = -1;
	if (arg.IsValid(4)) col = arg.GetInt(4);
	int x = -1;
	if (arg.IsValid(5)) x = arg.GetInt(5);
	int y = -1;
	if (arg.IsValid(6)) y = arg.GetInt(6);
	bool sel = true;
	if (arg.IsValid(7)) sel = arg.GetBoolean(7);
	bool control = false;
	if (arg.IsValid(8)) control = arg.GetBoolean(8);
	bool shift = false;
	if (arg.IsValid(9)) shift = arg.GetBoolean(9);
	bool alt = false;
	if (arg.IsValid(10)) alt = arg.GetBoolean(10);
	bool meta = false;
	if (arg.IsValid(11)) meta = arg.GetBoolean(11);
	wx_GridEvent *pEntity = new wx_GridEvent(id, type, obj, row, col, x, y, sel, control, shift, alt, meta);
	Object_wx_GridEvent *pObj = Object_wx_GridEvent::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_GridEvent, AltDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEvent, AltDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->AltDown();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridEvent, ControlDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEvent, ControlDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->ControlDown();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridEvent, GetCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEvent, GetCol)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetCol();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEvent, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, arg, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridEvent, GetRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEvent, GetRow)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetRow();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridEvent, MetaDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEvent, MetaDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->MetaDown();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridEvent, Selecting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEvent, Selecting)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Selecting();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridEvent, ShiftDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEvent, ShiftDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->ShiftDown();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxGridEvent
//----------------------------------------------------------------------------
Object_wx_GridEvent::~Object_wx_GridEvent()
{
}

Object *Object_wx_GridEvent::Clone() const
{
	return nullptr;
}

String Object_wx_GridEvent::ToString(bool exprFlag)
{
	String rtn("<wx.GridEvent:");
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
// Class implementation for wxGridEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridEvent)
{
	Gura_AssignFunction(GridEventEmpty);
	Gura_AssignFunction(GridEvent);
	Gura_AssignMethod(wx_GridEvent, AltDown);
	Gura_AssignMethod(wx_GridEvent, ControlDown);
	Gura_AssignMethod(wx_GridEvent, GetCol);
	Gura_AssignMethod(wx_GridEvent, GetPosition);
	Gura_AssignMethod(wx_GridEvent, GetRow);
	Gura_AssignMethod(wx_GridEvent, MetaDown);
	Gura_AssignMethod(wx_GridEvent, Selecting);
	Gura_AssignMethod(wx_GridEvent, ShiftDown);
}

Gura_ImplementDescendantCreator(wx_GridEvent)
{
	return new Object_wx_GridEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
