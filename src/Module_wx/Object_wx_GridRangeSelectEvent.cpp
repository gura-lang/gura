//----------------------------------------------------------------------------
// wxGridRangeSelectEvent
// extracted from gridevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridRangeSelectEvent: public wxGridRangeSelectEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GridRangeSelectEvent *_pObj;
public:
	inline wx_GridRangeSelectEvent() : wxGridRangeSelectEvent(), _sig(NULL), _pObj(NULL) {}
	inline wx_GridRangeSelectEvent(int id, wxEventType type, wxObject* obj, const wxGridCellCoords& topLeft, const wxGridCellCoords& bottomRight, bool sel, bool control, bool shift, bool alt, bool meta) : wxGridRangeSelectEvent(id, type, obj, topLeft, bottomRight, sel, control, shift, alt, meta), _sig(NULL), _pObj(NULL) {}
	~wx_GridRangeSelectEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridRangeSelectEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridRangeSelectEvent::~wx_GridRangeSelectEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GridRangeSelectEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridRangeSelectEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridRangeSelectEventEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridRangeSelectEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridRangeSelectEventEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GridRangeSelectEvent *pEntity = new wx_GridRangeSelectEvent();
	Object_wx_GridRangeSelectEvent *pObj = Object_wx_GridRangeSelectEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridRangeSelectEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(GridRangeSelectEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GridRangeSelectEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "obj", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "topLeft", VTYPE_wx_GridCellCoords, OCCUR_Once);
	DeclareArg(env, "bottomRight", VTYPE_wx_GridCellCoords, OCCUR_Once);
	DeclareArg(env, "sel", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "control", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "shift", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "alt", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "meta", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridRangeSelectEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxEventType type = static_cast<wxEventType>(args.GetInt(1));
	wxObject *obj = Object_wx_Object::GetObject(args, 2)->GetEntity();
	wxGridCellCoords *topLeft = Object_wx_GridCellCoords::GetObject(args, 3)->GetEntity();
	wxGridCellCoords *bottomRight = Object_wx_GridCellCoords::GetObject(args, 4)->GetEntity();
	bool sel = true;
	if (args.IsValid(5)) sel = args.GetBoolean(5);
	bool control = false;
	if (args.IsValid(6)) control = args.GetBoolean(6);
	bool shift = false;
	if (args.IsValid(7)) shift = args.GetBoolean(7);
	bool alt = false;
	if (args.IsValid(8)) alt = args.GetBoolean(8);
	bool meta = false;
	if (args.IsValid(9)) meta = args.GetBoolean(9);
	wx_GridRangeSelectEvent *pEntity = new wx_GridRangeSelectEvent(id, type, obj, *topLeft, *bottomRight, sel, control, shift, alt, meta);
	Object_wx_GridRangeSelectEvent *pObj = Object_wx_GridRangeSelectEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridRangeSelectEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, AltDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, AltDown)
{
	Object_wx_GridRangeSelectEvent *pSelf = Object_wx_GridRangeSelectEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->AltDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, ControlDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, ControlDown)
{
	Object_wx_GridRangeSelectEvent *pSelf = Object_wx_GridRangeSelectEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->ControlDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, GetBottomRightCoords)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, GetBottomRightCoords)
{
	Object_wx_GridRangeSelectEvent *pSelf = Object_wx_GridRangeSelectEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxGridCellCoords rtn = pSelf->GetEntity()->GetBottomRightCoords();
	return ReturnValue(env, sig, args, Value(new Object_wx_GridCellCoords(new wxGridCellCoords(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, GetBottomRow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, GetBottomRow)
{
	Object_wx_GridRangeSelectEvent *pSelf = Object_wx_GridRangeSelectEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetBottomRow();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, GetLeftCol)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, GetLeftCol)
{
	Object_wx_GridRangeSelectEvent *pSelf = Object_wx_GridRangeSelectEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetLeftCol();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, GetRightCol)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, GetRightCol)
{
	Object_wx_GridRangeSelectEvent *pSelf = Object_wx_GridRangeSelectEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetRightCol();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, GetTopLeftCoords)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, GetTopLeftCoords)
{
	Object_wx_GridRangeSelectEvent *pSelf = Object_wx_GridRangeSelectEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxGridCellCoords rtn = pSelf->GetEntity()->GetTopLeftCoords();
	return ReturnValue(env, sig, args, Value(new Object_wx_GridCellCoords(new wxGridCellCoords(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, GetTopRow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, GetTopRow)
{
	Object_wx_GridRangeSelectEvent *pSelf = Object_wx_GridRangeSelectEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetTopRow();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, MetaDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, MetaDown)
{
	Object_wx_GridRangeSelectEvent *pSelf = Object_wx_GridRangeSelectEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->MetaDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, Selecting)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, Selecting)
{
	Object_wx_GridRangeSelectEvent *pSelf = Object_wx_GridRangeSelectEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->Selecting();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, ShiftDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, ShiftDown)
{
	Object_wx_GridRangeSelectEvent *pSelf = Object_wx_GridRangeSelectEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->ShiftDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxGridRangeSelectEvent
//----------------------------------------------------------------------------
Object_wx_GridRangeSelectEvent::~Object_wx_GridRangeSelectEvent()
{
}

Object *Object_wx_GridRangeSelectEvent::Clone() const
{
	return NULL;
}

String Object_wx_GridRangeSelectEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GridRangeSelectEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_GridRangeSelectEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(GridRangeSelectEventEmpty);
	Gura_AssignFunction(GridRangeSelectEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxGridRangeSelectEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridRangeSelectEvent)
{
	Gura_AssignMethod(wx_GridRangeSelectEvent, AltDown);
	Gura_AssignMethod(wx_GridRangeSelectEvent, ControlDown);
	Gura_AssignMethod(wx_GridRangeSelectEvent, GetBottomRightCoords);
	Gura_AssignMethod(wx_GridRangeSelectEvent, GetBottomRow);
	Gura_AssignMethod(wx_GridRangeSelectEvent, GetLeftCol);
	Gura_AssignMethod(wx_GridRangeSelectEvent, GetRightCol);
	Gura_AssignMethod(wx_GridRangeSelectEvent, GetTopLeftCoords);
	Gura_AssignMethod(wx_GridRangeSelectEvent, GetTopRow);
	Gura_AssignMethod(wx_GridRangeSelectEvent, MetaDown);
	Gura_AssignMethod(wx_GridRangeSelectEvent, Selecting);
	Gura_AssignMethod(wx_GridRangeSelectEvent, ShiftDown);
}

Gura_ImplementDescendantCreator(wx_GridRangeSelectEvent)
{
	return new Object_wx_GridRangeSelectEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
