//----------------------------------------------------------------------------
// wxMouseEvent
// extracted from mouseevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MouseEvent: public wxMouseEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MouseEvent *_pObj;
public:
	inline wx_MouseEvent(WXTYPE mouseEventType) : wxMouseEvent(mouseEventType), _sig(NULL), _pObj(NULL) {}
	~wx_MouseEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MouseEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MouseEvent::~wx_MouseEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MouseEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMouseEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(MouseEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MouseEvent));
	DeclareArg(env, "mouseEventType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MouseEvent)
{
	WXTYPE mouseEventType = 0;
	if (args.IsValid(0)) mouseEventType = static_cast<WXTYPE>(args.GetInt(0));
	wx_MouseEvent *pEntity = new wx_MouseEvent(mouseEventType);
	Object_wx_MouseEvent *pObj = Object_wx_MouseEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MouseEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_MouseEvent, AltDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, AltDown)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->AltDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, Button)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, Button)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int button = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->Button(button);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, ButtonDClick)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "but", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, ButtonDClick)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int but = wxMOUSE_BTN_ANY;
	if (args.IsValid(0)) but = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->ButtonDClick(but);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, ButtonDown)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "but", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, ButtonDown)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int but = -1;
	if (args.IsValid(0)) but = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->ButtonDown(but);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, ButtonUp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "but", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, ButtonUp)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int but = -1;
	if (args.IsValid(0)) but = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->ButtonUp(but);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, CmdDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, CmdDown)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->CmdDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, ControlDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, ControlDown)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->ControlDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, Dragging)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, Dragging)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->Dragging();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, Entering)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, Entering)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->Entering();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, GetButton)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, GetButton)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetButton();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, GetPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, GetPosition)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pSelf->GetEntity()->GetPosition();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_MouseEvent, GetPosition_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_MouseEvent, GetPosition_1)
{
#if 0
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	pSelf->GetEntity()->GetPosition(x, y);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_MouseEvent, GetPosition_2)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_MouseEvent, GetPosition_2)
{
#if 0
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long x = args.GetLong(0);
	long y = args.GetLong(1);
	pSelf->GetEntity()->GetPosition(x, y);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_MouseEvent, GetLogicalPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, GetLogicalPosition)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxPoint rtn = pSelf->GetEntity()->GetLogicalPosition(*dc);
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_MouseEvent, GetLinesPerAction)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, GetLinesPerAction)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetLinesPerAction();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, GetWheelRotation)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, GetWheelRotation)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetWheelRotation();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, GetWheelDelta)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, GetWheelDelta)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetWheelDelta();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, GetX)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, GetX)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetX();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, GetY)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, GetY)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetY();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, IsButton)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, IsButton)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsButton();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, IsPageScroll)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, IsPageScroll)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsPageScroll();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, Leaving)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, Leaving)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->Leaving();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, LeftDClick)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, LeftDClick)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->LeftDClick();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, LeftDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, LeftDown)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->LeftDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, LeftIsDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, LeftIsDown)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->LeftIsDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, LeftUp)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, LeftUp)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->LeftUp();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, MetaDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, MetaDown)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->MetaDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, MiddleDClick)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, MiddleDClick)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->MiddleDClick();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, MiddleDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, MiddleDown)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->MiddleDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, MiddleIsDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, MiddleIsDown)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->MiddleIsDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, MiddleUp)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, MiddleUp)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->MiddleUp();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, Moving)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, Moving)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->Moving();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, RightDClick)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, RightDClick)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->RightDClick();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, RightDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, RightDown)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->RightDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, RightIsDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, RightIsDown)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->RightIsDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, RightUp)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, RightUp)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->RightUp();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, ShiftDown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, ShiftDown)
{
	Object_wx_MouseEvent *pSelf = Object_wx_MouseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->ShiftDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxMouseEvent
//----------------------------------------------------------------------------
Object_wx_MouseEvent::~Object_wx_MouseEvent()
{
}

Object *Object_wx_MouseEvent::Clone() const
{
	return NULL;
}

String Object_wx_MouseEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.MouseEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_MouseEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(MouseEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxMouseEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseEvent)
{
	Gura_AssignMethod(wx_MouseEvent, AltDown);
	Gura_AssignMethod(wx_MouseEvent, Button);
	Gura_AssignMethod(wx_MouseEvent, ButtonDClick);
	Gura_AssignMethod(wx_MouseEvent, ButtonDown);
	Gura_AssignMethod(wx_MouseEvent, ButtonUp);
	Gura_AssignMethod(wx_MouseEvent, CmdDown);
	Gura_AssignMethod(wx_MouseEvent, ControlDown);
	Gura_AssignMethod(wx_MouseEvent, Dragging);
	Gura_AssignMethod(wx_MouseEvent, Entering);
	Gura_AssignMethod(wx_MouseEvent, GetButton);
	Gura_AssignMethod(wx_MouseEvent, GetPosition);
	Gura_AssignMethod(wx_MouseEvent, GetPosition_1);
	Gura_AssignMethod(wx_MouseEvent, GetPosition_2);
	Gura_AssignMethod(wx_MouseEvent, GetLogicalPosition);
	Gura_AssignMethod(wx_MouseEvent, GetLinesPerAction);
	Gura_AssignMethod(wx_MouseEvent, GetWheelRotation);
	Gura_AssignMethod(wx_MouseEvent, GetWheelDelta);
	Gura_AssignMethod(wx_MouseEvent, GetX);
	Gura_AssignMethod(wx_MouseEvent, GetY);
	Gura_AssignMethod(wx_MouseEvent, IsButton);
	Gura_AssignMethod(wx_MouseEvent, IsPageScroll);
	Gura_AssignMethod(wx_MouseEvent, Leaving);
	Gura_AssignMethod(wx_MouseEvent, LeftDClick);
	Gura_AssignMethod(wx_MouseEvent, LeftDown);
	Gura_AssignMethod(wx_MouseEvent, LeftIsDown);
	Gura_AssignMethod(wx_MouseEvent, LeftUp);
	Gura_AssignMethod(wx_MouseEvent, MetaDown);
	Gura_AssignMethod(wx_MouseEvent, MiddleDClick);
	Gura_AssignMethod(wx_MouseEvent, MiddleDown);
	Gura_AssignMethod(wx_MouseEvent, MiddleIsDown);
	Gura_AssignMethod(wx_MouseEvent, MiddleUp);
	Gura_AssignMethod(wx_MouseEvent, Moving);
	Gura_AssignMethod(wx_MouseEvent, RightDClick);
	Gura_AssignMethod(wx_MouseEvent, RightDown);
	Gura_AssignMethod(wx_MouseEvent, RightIsDown);
	Gura_AssignMethod(wx_MouseEvent, RightUp);
	Gura_AssignMethod(wx_MouseEvent, ShiftDown);
}

Gura_ImplementDescendantCreator(wx_MouseEvent)
{
	return new Object_wx_MouseEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
