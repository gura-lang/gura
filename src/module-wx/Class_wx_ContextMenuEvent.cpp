//----------------------------------------------------------------------------
// wxContextMenuEvent
// extracted from cntxtevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ContextMenuEvent: public wxContextMenuEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ContextMenuEvent *_pObj;
public:
	inline wx_ContextMenuEvent(WXTYPE type, int id, const wxPoint& pos) : wxContextMenuEvent(type, id, pos), _pObj(nullptr) {}
	~wx_ContextMenuEvent();
	inline void AssocWithGura(Object_wx_ContextMenuEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ContextMenuEvent::~wx_ContextMenuEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ContextMenuEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxContextMenuEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(ContextMenuEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ContextMenuEvent));
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ContextMenuEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	WXTYPE type = 0;
	if (args.IsValid(0)) type = static_cast<WXTYPE>(args.GetInt(0));
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wx_ContextMenuEvent *pEntity = new wx_ContextMenuEvent(type, id, *pos);
	Object_wx_ContextMenuEvent *pObj = Object_wx_ContextMenuEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ContextMenuEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_ContextMenuEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ContextMenuEvent, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ContextMenuEvent *pThis = Object_wx_ContextMenuEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, args, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ContextMenuEvent, SetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "point", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_ContextMenuEvent, SetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ContextMenuEvent *pThis = Object_wx_ContextMenuEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *point = Object_wx_Point::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPosition(*point);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxContextMenuEvent
//----------------------------------------------------------------------------
Object_wx_ContextMenuEvent::~Object_wx_ContextMenuEvent()
{
}

Object *Object_wx_ContextMenuEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ContextMenuEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ContextMenuEvent:");
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
// Class implementation for wxContextMenuEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ContextMenuEvent)
{
	Gura_AssignFunction(ContextMenuEvent);
	Gura_AssignMethod(wx_ContextMenuEvent, GetPosition);
	Gura_AssignMethod(wx_ContextMenuEvent, SetPosition);
}

Gura_ImplementDescendantCreator(wx_ContextMenuEvent)
{
	return new Object_wx_ContextMenuEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
