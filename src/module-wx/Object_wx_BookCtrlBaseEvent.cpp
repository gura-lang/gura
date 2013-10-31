//----------------------------------------------------------------------------
// wxBookCtrlBaseEvent
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_BookCtrlBaseEvent: public wxBookCtrlBaseEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_BookCtrlBaseEvent *_pObj;
public:
	~wx_BookCtrlBaseEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_BookCtrlBaseEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BookCtrlBaseEvent::~wx_BookCtrlBaseEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_BookCtrlBaseEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBookCtrlBaseEvent
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_BookCtrlBaseEvent, GetOldSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBaseEvent, GetOldSelection)
{
	Object_wx_BookCtrlBaseEvent *pThis = Object_wx_BookCtrlBaseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetOldSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_BookCtrlBaseEvent, GetSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBaseEvent, GetSelection)
{
	Object_wx_BookCtrlBaseEvent *pThis = Object_wx_BookCtrlBaseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_BookCtrlBaseEvent, SetOldSelection)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BookCtrlBaseEvent, SetOldSelection)
{
	Object_wx_BookCtrlBaseEvent *pThis = Object_wx_BookCtrlBaseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int page = args.GetInt(0);
	pThis->GetEntity()->SetOldSelection(page);
	return Value::Null;
}

Gura_DeclareMethod(wx_BookCtrlBaseEvent, SetSelection)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BookCtrlBaseEvent, SetSelection)
{
	Object_wx_BookCtrlBaseEvent *pThis = Object_wx_BookCtrlBaseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int page = args.GetInt(0);
	pThis->GetEntity()->SetSelection(page);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxBookCtrlBaseEvent
//----------------------------------------------------------------------------
Object_wx_BookCtrlBaseEvent::~Object_wx_BookCtrlBaseEvent()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_BookCtrlBaseEvent::Clone() const
{
	return NULL;
}

String Object_wx_BookCtrlBaseEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.BookCtrlBaseEvent:");
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
// Class implementation for wxBookCtrlBaseEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BookCtrlBaseEvent)
{
	Gura_AssignMethod(wx_BookCtrlBaseEvent, GetOldSelection);
	Gura_AssignMethod(wx_BookCtrlBaseEvent, GetSelection);
	Gura_AssignMethod(wx_BookCtrlBaseEvent, SetOldSelection);
	Gura_AssignMethod(wx_BookCtrlBaseEvent, SetSelection);
}

Gura_ImplementDescendantCreator(wx_BookCtrlBaseEvent)
{
	return new Object_wx_BookCtrlBaseEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
