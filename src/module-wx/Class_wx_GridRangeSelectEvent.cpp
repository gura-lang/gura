//----------------------------------------------------------------------------
// wxGridRangeSelectEvent
// extracted from gridevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridRangeSelectEvent: public wxGridRangeSelectEvent, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_GridRangeSelectEvent *_pObj;
public:
	inline wx_GridRangeSelectEvent() : wxGridRangeSelectEvent(), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_GridRangeSelectEvent(int id, wxEventType type, wxObject* obj, const wxGridCellCoords& topLeft, const wxGridCellCoords& bottomRight, bool sel, bool control, bool shift, bool alt, bool meta) : wxGridRangeSelectEvent(id, type, obj, topLeft, bottomRight, sel, control, shift, alt, meta), _pSig(nullptr), _pObj(nullptr) {}
	~wx_GridRangeSelectEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridRangeSelectEvent *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridRangeSelectEvent::~wx_GridRangeSelectEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridRangeSelectEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridRangeSelectEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridRangeSelectEventEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridRangeSelectEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridRangeSelectEventEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GridRangeSelectEvent *pEntity = new wx_GridRangeSelectEvent();
	Object_wx_GridRangeSelectEvent *pObj = Object_wx_GridRangeSelectEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridRangeSelectEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(GridRangeSelectEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Object_wx_GridRangeSelectEvent *pObj = Object_wx_GridRangeSelectEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridRangeSelectEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, AltDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, AltDown)
{
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->AltDown();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, ControlDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, ControlDown)
{
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->ControlDown();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, GetBottomRightCoords)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, GetBottomRightCoords)
{
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellCoords rtn = pThis->GetEntity()->GetBottomRightCoords();
	return ReturnValue(env, args, Value(new Object_wx_GridCellCoords(new wxGridCellCoords(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, GetBottomRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, GetBottomRow)
{
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetBottomRow();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, GetLeftCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, GetLeftCol)
{
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetLeftCol();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, GetRightCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, GetRightCol)
{
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetRightCol();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, GetTopLeftCoords)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, GetTopLeftCoords)
{
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellCoords rtn = pThis->GetEntity()->GetTopLeftCoords();
	return ReturnValue(env, args, Value(new Object_wx_GridCellCoords(new wxGridCellCoords(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, GetTopRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, GetTopRow)
{
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetTopRow();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, MetaDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, MetaDown)
{
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->MetaDown();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, Selecting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, Selecting)
{
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Selecting();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, ShiftDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, ShiftDown)
{
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->ShiftDown();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxGridRangeSelectEvent
//----------------------------------------------------------------------------
Object_wx_GridRangeSelectEvent::~Object_wx_GridRangeSelectEvent()
{
}

Object *Object_wx_GridRangeSelectEvent::Clone() const
{
	return nullptr;
}

String Object_wx_GridRangeSelectEvent::ToString(bool exprFlag)
{
	String rtn("<wx.GridRangeSelectEvent:");
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
// Class implementation for wxGridRangeSelectEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridRangeSelectEvent)
{
	Gura_AssignFunction(GridRangeSelectEventEmpty);
	Gura_AssignFunction(GridRangeSelectEvent);
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
	return new Object_wx_GridRangeSelectEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
