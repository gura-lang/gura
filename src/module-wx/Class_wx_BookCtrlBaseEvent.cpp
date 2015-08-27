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
	//Gura::Signal *_pSig;
	Object_wx_BookCtrlBaseEvent *_pObj;
public:
	~wx_BookCtrlBaseEvent();
	inline void AssocWithGura(Object_wx_BookCtrlBaseEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BookCtrlBaseEvent::~wx_BookCtrlBaseEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_BookCtrlBaseEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBookCtrlBaseEvent
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_BookCtrlBaseEvent, GetOldSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBaseEvent, GetOldSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_BookCtrlBaseEvent *pThis = Object_wx_BookCtrlBaseEvent::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetOldSelection();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_BookCtrlBaseEvent, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBaseEvent, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_BookCtrlBaseEvent *pThis = Object_wx_BookCtrlBaseEvent::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_BookCtrlBaseEvent, SetOldSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BookCtrlBaseEvent, SetOldSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_BookCtrlBaseEvent *pThis = Object_wx_BookCtrlBaseEvent::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int page = args.GetInt(0);
	pThis->GetEntity()->SetOldSelection(page);
	return Value::Nil;
}

Gura_DeclareMethod(wx_BookCtrlBaseEvent, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BookCtrlBaseEvent, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_BookCtrlBaseEvent *pThis = Object_wx_BookCtrlBaseEvent::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int page = args.GetInt(0);
	pThis->GetEntity()->SetSelection(page);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxBookCtrlBaseEvent
//----------------------------------------------------------------------------
Object_wx_BookCtrlBaseEvent::~Object_wx_BookCtrlBaseEvent()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_BookCtrlBaseEvent::Clone() const
{
	return nullptr;
}

String Object_wx_BookCtrlBaseEvent::ToString(bool exprFlag)
{
	String rtn("<wx.BookCtrlBaseEvent:");
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
	return new Object_wx_BookCtrlBaseEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
