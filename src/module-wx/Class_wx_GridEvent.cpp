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
	Gura::Signal _sig;
	Object_wx_GridEvent *_pObj;
public:
	inline wx_GridEvent() : wxGridEvent(), _sig(NULL), _pObj(NULL) {}
	inline wx_GridEvent(int id, wxEventType type, wxObject* obj, int row, int col, int x, int y, bool sel, bool control, bool shift, bool alt, bool meta) : wxGridEvent(id, type, obj, row, col, x, y, sel, control, shift, alt, meta), _sig(NULL), _pObj(NULL) {}
	~wx_GridEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridEvent::~wx_GridEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GridEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridEventEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridEventEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GridEvent *pEntity = new wx_GridEvent();
	Object_wx_GridEvent *pObj = Object_wx_GridEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(GridEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxEventType type = static_cast<wxEventType>(args.GetInt(1));
	wxObject *obj = Object_wx_Object::GetObject(args, 2)->GetEntity();
	int row = -1;
	if (args.IsValid(3)) row = args.GetInt(3);
	int col = -1;
	if (args.IsValid(4)) col = args.GetInt(4);
	int x = -1;
	if (args.IsValid(5)) x = args.GetInt(5);
	int y = -1;
	if (args.IsValid(6)) y = args.GetInt(6);
	bool sel = true;
	if (args.IsValid(7)) sel = args.GetBoolean(7);
	bool control = false;
	if (args.IsValid(8)) control = args.GetBoolean(8);
	bool shift = false;
	if (args.IsValid(9)) shift = args.GetBoolean(9);
	bool alt = false;
	if (args.IsValid(10)) alt = args.GetBoolean(10);
	bool meta = false;
	if (args.IsValid(11)) meta = args.GetBoolean(11);
	wx_GridEvent *pEntity = new wx_GridEvent(id, type, obj, row, col, x, y, sel, control, shift, alt, meta);
	Object_wx_GridEvent *pObj = Object_wx_GridEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_GridEvent, AltDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEvent, AltDown)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->AltDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridEvent, ControlDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEvent, ControlDown)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->ControlDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridEvent, GetCol)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEvent, GetCol)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetCol();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridEvent, GetPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEvent, GetPosition)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridEvent, GetRow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEvent, GetRow)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetRow();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridEvent, MetaDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEvent, MetaDown)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->MetaDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridEvent, Selecting)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEvent, Selecting)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Selecting();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridEvent, ShiftDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEvent, ShiftDown)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->ShiftDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxGridEvent
//----------------------------------------------------------------------------
Object_wx_GridEvent::~Object_wx_GridEvent()
{
}

Object *Object_wx_GridEvent::Clone() const
{
	return NULL;
}

String Object_wx_GridEvent::ToString(bool exprFlag)
{
	String rtn("<wx.GridEvent:");
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
	return new Object_wx_GridEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
