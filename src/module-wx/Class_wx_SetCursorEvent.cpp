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
	Gura::Signal _sig;
	Object_wx_SetCursorEvent *_pObj;
public:
	inline wx_SetCursorEvent(wxCoord x, wxCoord y) : wxSetCursorEvent(x, y), _sig(NULL), _pObj(NULL) {}
	~wx_SetCursorEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SetCursorEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SetCursorEvent::~wx_SetCursorEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_SetCursorEvent::GuraObjectDeleted()
{
	_pObj = NULL;
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxCoord x = 0;
	if (args.IsValid(0)) x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = 0;
	if (args.IsValid(1)) y = static_cast<wxCoord>(args.GetInt(1));
	wx_SetCursorEvent *pEntity = new wx_SetCursorEvent(x, y);
	Object_wx_SetCursorEvent *pObj = Object_wx_SetCursorEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_SetCursorEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_SetCursorEvent, GetCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SetCursorEvent, GetCursor)
{
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxCursor &rtn = pThis->GetEntity()->GetCursor();
	return ReturnValue(env, sig, args, Value(new Object_wx_Cursor(new wxCursor(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_SetCursorEvent, GetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SetCursorEvent, GetX)
{
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pThis->GetEntity()->GetX();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SetCursorEvent, GetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SetCursorEvent, GetY)
{
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pThis->GetEntity()->GetY();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SetCursorEvent, HasCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SetCursorEvent, HasCursor)
{
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasCursor();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SetCursorEvent, SetCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cursor", VTYPE_wx_Cursor, OCCUR_Once);
}

Gura_ImplementMethod(wx_SetCursorEvent, SetCursor)
{
	Object_wx_SetCursorEvent *pThis = Object_wx_SetCursorEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCursor *cursor = Object_wx_Cursor::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetCursor(*cursor);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxSetCursorEvent
//----------------------------------------------------------------------------
Object_wx_SetCursorEvent::~Object_wx_SetCursorEvent()
{
}

Object *Object_wx_SetCursorEvent::Clone() const
{
	return NULL;
}

String Object_wx_SetCursorEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SetCursorEvent:");
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
	return new Object_wx_SetCursorEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
