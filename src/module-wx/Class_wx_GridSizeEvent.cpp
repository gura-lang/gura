//----------------------------------------------------------------------------
// wxGridSizeEvent
// extracted from gridevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridSizeEvent: public wxGridSizeEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_GridSizeEvent *_pObj;
public:
	inline wx_GridSizeEvent() : wxGridSizeEvent(), _pObj(nullptr) {}
	inline wx_GridSizeEvent(int id, wxEventType type, wxObject* obj, int rowOrCol, int x, int y, bool control, bool shift, bool alt, bool meta) : wxGridSizeEvent(id, type, obj, rowOrCol, x, y, control, shift, alt, meta), _pObj(nullptr) {}
	~wx_GridSizeEvent();
	inline void AssocWithGura(Object_wx_GridSizeEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridSizeEvent::~wx_GridSizeEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridSizeEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridSizeEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridSizeEventEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridSizeEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridSizeEventEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_GridSizeEvent *pEntity = new wx_GridSizeEvent();
	Object_wx_GridSizeEvent *pObj = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridSizeEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(GridSizeEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxEventType type = static_cast<wxEventType>(arg.GetInt(1));
	wxObject *obj = Object_wx_Object::GetObject(arg, 2)->GetEntity();
	int rowOrCol = -1;
	if (arg.IsValid(3)) rowOrCol = arg.GetInt(3);
	int x = -1;
	if (arg.IsValid(4)) x = arg.GetInt(4);
	int y = -1;
	if (arg.IsValid(5)) y = arg.GetInt(5);
	bool control = false;
	if (arg.IsValid(6)) control = arg.GetBoolean(6);
	bool shift = false;
	if (arg.IsValid(7)) shift = arg.GetBoolean(7);
	bool alt = false;
	if (arg.IsValid(8)) alt = arg.GetBoolean(8);
	bool meta = false;
	if (arg.IsValid(9)) meta = arg.GetBoolean(9);
	wx_GridSizeEvent *pEntity = new wx_GridSizeEvent(id, type, obj, rowOrCol, x, y, control, shift, alt, meta);
	Object_wx_GridSizeEvent *pObj = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridSizeEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_GridSizeEvent, AltDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizeEvent, AltDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->AltDown();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridSizeEvent, ControlDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizeEvent, ControlDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->ControlDown();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridSizeEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizeEvent, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, arg, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridSizeEvent, GetRowOrCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizeEvent, GetRowOrCol)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetRowOrCol();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridSizeEvent, MetaDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizeEvent, MetaDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->MetaDown();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridSizeEvent, ShiftDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizeEvent, ShiftDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->ShiftDown();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxGridSizeEvent
//----------------------------------------------------------------------------
Object_wx_GridSizeEvent::~Object_wx_GridSizeEvent()
{
}

Object *Object_wx_GridSizeEvent::Clone() const
{
	return nullptr;
}

String Object_wx_GridSizeEvent::ToString(bool exprFlag)
{
	String rtn("<wx.GridSizeEvent:");
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
// Class implementation for wxGridSizeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridSizeEvent)
{
	Gura_AssignFunction(GridSizeEventEmpty);
	Gura_AssignFunction(GridSizeEvent);
	Gura_AssignMethod(wx_GridSizeEvent, AltDown);
	Gura_AssignMethod(wx_GridSizeEvent, ControlDown);
	Gura_AssignMethod(wx_GridSizeEvent, GetPosition);
	Gura_AssignMethod(wx_GridSizeEvent, GetRowOrCol);
	Gura_AssignMethod(wx_GridSizeEvent, MetaDown);
	Gura_AssignMethod(wx_GridSizeEvent, ShiftDown);
}

Gura_ImplementDescendantCreator(wx_GridSizeEvent)
{
	return new Object_wx_GridSizeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
