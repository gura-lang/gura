//----------------------------------------------------------------------------
// wxMouseEvent
// extracted from mouseevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MouseEvent: public wxMouseEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MouseEvent *_pObj;
public:
	inline wx_MouseEvent(WXTYPE mouseEventType) : wxMouseEvent(mouseEventType), _sig(nullptr), _pObj(nullptr) {}
	~wx_MouseEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MouseEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MouseEvent::~wx_MouseEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MouseEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMouseEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(MouseEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MouseEvent));
	DeclareArg(env, "mouseEventType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MouseEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	WXTYPE mouseEventType = 0;
	if (args.IsValid(0)) mouseEventType = static_cast<WXTYPE>(args.GetInt(0));
	wx_MouseEvent *pEntity = new wx_MouseEvent(mouseEventType);
	Object_wx_MouseEvent *pObj = Object_wx_MouseEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_MouseEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_MouseEvent, AltDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, AltDown)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->AltDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, Button)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, Button)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int button = args.GetInt(0);
	bool rtn = pThis->GetEntity()->Button(button);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, ButtonDClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "but", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, ButtonDClick)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int but = wxMOUSE_BTN_ANY;
	if (args.IsValid(0)) but = args.GetInt(0);
	bool rtn = pThis->GetEntity()->ButtonDClick(but);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, ButtonDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "but", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, ButtonDown)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int but = -1;
	if (args.IsValid(0)) but = args.GetInt(0);
	bool rtn = pThis->GetEntity()->ButtonDown(but);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, ButtonUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "but", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, ButtonUp)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int but = -1;
	if (args.IsValid(0)) but = args.GetInt(0);
	bool rtn = pThis->GetEntity()->ButtonUp(but);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, CmdDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, CmdDown)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CmdDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, ControlDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, ControlDown)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->ControlDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, Dragging)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, Dragging)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Dragging();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, Entering)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, Entering)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Entering();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, GetButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, GetButton)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetButton();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, GetPosition)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_MouseEvent, GetPosition_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_MouseEvent, GetPosition_1)
{
#if 0
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	pThis->GetEntity()->GetPosition(x, y);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_MouseEvent, GetPosition_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_MouseEvent, GetPosition_2)
{
#if 0
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long x = args.GetLong(0);
	long y = args.GetLong(1);
	pThis->GetEntity()->GetPosition(x, y);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_MouseEvent, GetLogicalPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, GetLogicalPosition)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxPoint rtn = pThis->GetEntity()->GetLogicalPosition(*dc);
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_MouseEvent, GetLinesPerAction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, GetLinesPerAction)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetLinesPerAction();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, GetWheelRotation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, GetWheelRotation)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetWheelRotation();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, GetWheelDelta)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, GetWheelDelta)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetWheelDelta();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, GetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, GetX)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetX();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, GetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, GetY)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetY();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, IsButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, IsButton)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsButton();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, IsPageScroll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, IsPageScroll)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsPageScroll();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, Leaving)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, Leaving)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Leaving();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, LeftDClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, LeftDClick)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->LeftDClick();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, LeftDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, LeftDown)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->LeftDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, LeftIsDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, LeftIsDown)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->LeftIsDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, LeftUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, LeftUp)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->LeftUp();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, MetaDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, MetaDown)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->MetaDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, MiddleDClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, MiddleDClick)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->MiddleDClick();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, MiddleDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, MiddleDown)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->MiddleDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, MiddleIsDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, MiddleIsDown)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->MiddleIsDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, MiddleUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, MiddleUp)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->MiddleUp();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, Moving)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, Moving)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Moving();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, RightDClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, RightDClick)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->RightDClick();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, RightDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, RightDown)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->RightDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, RightIsDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, RightIsDown)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->RightIsDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, RightUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, RightUp)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->RightUp();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MouseEvent, ShiftDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MouseEvent, ShiftDown)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->ShiftDown();
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
	return nullptr;
}

String Object_wx_MouseEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MouseEvent:");
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
// Class implementation for wxMouseEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseEvent)
{
	Gura_AssignFunction(MouseEvent);
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
	return new Object_wx_MouseEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
