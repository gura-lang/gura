//----------------------------------------------------------------------------
// wxSetCursorEvent
// extracted from setcursorevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SetCursorEvent: public wxSetCursorEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SetCursorEvent *_pObj;
public:
	inline wx_SetCursorEvent(wxCoord x, wxCoord y) : wxSetCursorEvent(x, y), _pObj(nullptr) {}
	~wx_SetCursorEvent();
	inline void AssocWithGura(Object_wx_SetCursorEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SetCursorEvent::~wx_SetCursorEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SetCursorEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSetCursorEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(SetCursorEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SetCursorEvent));
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SetCursorEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxCoord x = 0;
	if (args.IsValid(0)) x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = 0;
	if (args.IsValid(1)) y = static_cast<wxCoord>(args.GetInt(1));
	wx_SetCursorEvent *pEntity = new wx_SetCursorEvent(x, y);
	Object_wx_SetCursorEvent *pObj = Object_wx_SetCursorEvent::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SetCursorEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_SetCursorEvent, GetCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SetCursorEvent, GetCursor)
{
	Signal &sig = env.GetSignal();
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxCursor &rtn = pThis->GetEntity()->GetCursor();
	return ReturnValue(env, args, Value(new Object_wx_Cursor(new wxCursor(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_SetCursorEvent, GetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SetCursorEvent, GetX)
{
	Signal &sig = env.GetSignal();
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord rtn = pThis->GetEntity()->GetX();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SetCursorEvent, GetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SetCursorEvent, GetY)
{
	Signal &sig = env.GetSignal();
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord rtn = pThis->GetEntity()->GetY();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SetCursorEvent, HasCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SetCursorEvent, HasCursor)
{
	Signal &sig = env.GetSignal();
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasCursor();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SetCursorEvent, SetCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cursor", VTYPE_wx_Cursor, OCCUR_Once);
}

Gura_ImplementMethod(wx_SetCursorEvent, SetCursor)
{
	Signal &sig = env.GetSignal();
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCursor *cursor = Object_wx_Cursor::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetCursor(*cursor);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxSetCursorEvent
//----------------------------------------------------------------------------
Object_wx_SetCursorEvent::~Object_wx_SetCursorEvent()
{
}

Object *Object_wx_SetCursorEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SetCursorEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SetCursorEvent:");
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
// Class implementation for wxSetCursorEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SetCursorEvent)
{
	Gura_AssignFunction(SetCursorEvent);
	Gura_AssignMethod(wx_SetCursorEvent, GetCursor);
	Gura_AssignMethod(wx_SetCursorEvent, GetX);
	Gura_AssignMethod(wx_SetCursorEvent, GetY);
	Gura_AssignMethod(wx_SetCursorEvent, HasCursor);
	Gura_AssignMethod(wx_SetCursorEvent, SetCursor);
}

Gura_ImplementDescendantCreator(wx_SetCursorEvent)
{
	return new Object_wx_SetCursorEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
