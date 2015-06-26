//----------------------------------------------------------------------------
// wxDateEvent
// extracted from dateevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DateEvent: public wxDateEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DateEvent *_pObj;
public:
	~wx_DateEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DateEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DateEvent::~wx_DateEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DateEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDateEvent
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DateEvent, GetDate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateEvent, GetDate)
{
	Object_wx_DateEvent *pThis = Object_wx_DateEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxDateTime &rtn = pThis->GetEntity()->GetDate();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateEvent, SetDate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "date", VTYPE_wx_DateTime, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateEvent, SetDate)
{
	Object_wx_DateEvent *pThis = Object_wx_DateEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime *date = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDate(*date);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDateEvent
//----------------------------------------------------------------------------
Object_wx_DateEvent::~Object_wx_DateEvent()
{
}

Object *Object_wx_DateEvent::Clone() const
{
	return nullptr;
}

String Object_wx_DateEvent::ToString(bool exprFlag)
{
	String rtn("<wx.DateEvent:");
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
// Class implementation for wxDateEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DateEvent)
{
	Gura_AssignMethod(wx_DateEvent, GetDate);
	Gura_AssignMethod(wx_DateEvent, SetDate);
}

Gura_ImplementDescendantCreator(wx_DateEvent)
{
	return new Object_wx_DateEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
