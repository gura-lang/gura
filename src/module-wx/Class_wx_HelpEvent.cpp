//----------------------------------------------------------------------------
// wxHelpEvent
// extracted from helpevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HelpEvent: public wxHelpEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_HelpEvent *_pObj;
public:
	inline wx_HelpEvent(WXTYPE eventType, wxWindowID id, const wxPoint& point) : wxHelpEvent(eventType, id, point), _pObj(nullptr) {}
	~wx_HelpEvent();
	inline void AssocWithGura(Object_wx_HelpEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HelpEvent::~wx_HelpEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HelpEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHelpEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(HelpEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HelpEvent));
	DeclareArg(env, "eventType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "point", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HelpEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	WXTYPE eventType = 0;
	if (args.IsValid(0)) eventType = static_cast<WXTYPE>(args.GetInt(0));
	wxWindowID id = 0;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint point;
	if (args.IsValid(2)) point = *Object_wx_Point::GetObject(args, 2)->GetEntity();
	wx_HelpEvent *pEntity = new wx_HelpEvent(eventType, id, point);
	Object_wx_HelpEvent *pObj = Object_wx_HelpEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HelpEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_HelpEvent, GetOrigin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpEvent, GetOrigin)
{
	Signal &sig = env.GetSignal();
	Object_wx_HelpEvent *pThis = Object_wx_HelpEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HelpEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpEvent, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_HelpEvent *pThis = Object_wx_HelpEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxPoint &rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, args, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_HelpEvent, SetOrigin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "origin", VTYPE_wx_HelpEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HelpEvent, SetOrigin)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HelpEvent *pThis = Object_wx_HelpEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxHelpEvent *origin = Object_wx_HelpEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetOrigin(*origin);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HelpEvent, SetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpEvent, SetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_HelpEvent *pThis = Object_wx_HelpEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPosition(*pt);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHelpEvent
//----------------------------------------------------------------------------
Object_wx_HelpEvent::~Object_wx_HelpEvent()
{
}

Object *Object_wx_HelpEvent::Clone() const
{
	return nullptr;
}

String Object_wx_HelpEvent::ToString(bool exprFlag)
{
	String rtn("<wx.HelpEvent:");
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
// Class implementation for wxHelpEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HelpEvent)
{
	Gura_AssignFunction(HelpEvent);
	Gura_AssignMethod(wx_HelpEvent, GetOrigin);
	Gura_AssignMethod(wx_HelpEvent, GetPosition);
	Gura_AssignMethod(wx_HelpEvent, SetOrigin);
	Gura_AssignMethod(wx_HelpEvent, SetPosition);
}

Gura_ImplementDescendantCreator(wx_HelpEvent)
{
	return new Object_wx_HelpEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
