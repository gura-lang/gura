//----------------------------------------------------------------------------
// wxGridSizeEvent
// extracted from gridevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridSizeEvent: public wxGridSizeEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GridSizeEvent *_pObj;
public:
	inline wx_GridSizeEvent() : wxGridSizeEvent(), _sig(NULL), _pObj(NULL) {}
	inline wx_GridSizeEvent(int id, wxEventType type, wxObject* obj, int rowOrCol, int x, int y, bool control, bool shift, bool alt, bool meta) : wxGridSizeEvent(id, type, obj, rowOrCol, x, y, control, shift, alt, meta), _sig(NULL), _pObj(NULL) {}
	~wx_GridSizeEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridSizeEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridSizeEvent::~wx_GridSizeEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GridSizeEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridSizeEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridSizeEventEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridSizeEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridSizeEventEmpty)
{
	wx_GridSizeEvent *pEntity = new wx_GridSizeEvent();
	Object_wx_GridSizeEvent *pObj = Object_wx_GridSizeEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridSizeEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(GridSizeEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GridSizeEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "obj", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "rowOrCol", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "control", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "shift", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "alt", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "meta", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridSizeEvent)
{
	int id = args.GetInt(0);
	wxEventType type = static_cast<wxEventType>(args.GetInt(1));
	wxObject *obj = Object_wx_Object::GetObject(args, 2)->GetEntity();
	int rowOrCol = -1;
	if (args.IsValid(3)) rowOrCol = args.GetInt(3);
	int x = -1;
	if (args.IsValid(4)) x = args.GetInt(4);
	int y = -1;
	if (args.IsValid(5)) y = args.GetInt(5);
	bool control = false;
	if (args.IsValid(6)) control = args.GetBoolean(6);
	bool shift = false;
	if (args.IsValid(7)) shift = args.GetBoolean(7);
	bool alt = false;
	if (args.IsValid(8)) alt = args.GetBoolean(8);
	bool meta = false;
	if (args.IsValid(9)) meta = args.GetBoolean(9);
	wx_GridSizeEvent *pEntity = new wx_GridSizeEvent(id, type, obj, rowOrCol, x, y, control, shift, alt, meta);
	Object_wx_GridSizeEvent *pObj = Object_wx_GridSizeEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridSizeEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_GridSizeEvent, AltDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizeEvent, AltDown)
{
	Object_wx_GridSizeEvent *pSelf = Object_wx_GridSizeEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->AltDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridSizeEvent, ControlDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizeEvent, ControlDown)
{
	Object_wx_GridSizeEvent *pSelf = Object_wx_GridSizeEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->ControlDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridSizeEvent, GetPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizeEvent, GetPosition)
{
	Object_wx_GridSizeEvent *pSelf = Object_wx_GridSizeEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pSelf->GetEntity()->GetPosition();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridSizeEvent, GetRowOrCol)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizeEvent, GetRowOrCol)
{
	Object_wx_GridSizeEvent *pSelf = Object_wx_GridSizeEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetRowOrCol();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridSizeEvent, MetaDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizeEvent, MetaDown)
{
	Object_wx_GridSizeEvent *pSelf = Object_wx_GridSizeEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->MetaDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridSizeEvent, ShiftDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizeEvent, ShiftDown)
{
	Object_wx_GridSizeEvent *pSelf = Object_wx_GridSizeEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->ShiftDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxGridSizeEvent
//----------------------------------------------------------------------------
Object_wx_GridSizeEvent::~Object_wx_GridSizeEvent()
{
}

Object *Object_wx_GridSizeEvent::Clone() const
{
	return NULL;
}

String Object_wx_GridSizeEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GridSizeEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_GridSizeEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(GridSizeEventEmpty);
	Gura_AssignFunction(GridSizeEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxGridSizeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridSizeEvent)
{
	Gura_AssignMethod(wx_GridSizeEvent, AltDown);
	Gura_AssignMethod(wx_GridSizeEvent, ControlDown);
	Gura_AssignMethod(wx_GridSizeEvent, GetPosition);
	Gura_AssignMethod(wx_GridSizeEvent, GetRowOrCol);
	Gura_AssignMethod(wx_GridSizeEvent, MetaDown);
	Gura_AssignMethod(wx_GridSizeEvent, ShiftDown);
}

Gura_ImplementDescendantCreator(wx_GridSizeEvent)
{
	return new Object_wx_GridSizeEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
