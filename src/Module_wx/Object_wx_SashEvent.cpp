//----------------------------------------------------------------------------
// wxSashEvent
// extracted from sashevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SashEvent: public wxSashEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_SashEvent *_pObj;
public:
	inline wx_SashEvent(int id, wxSashEdgePosition edge) : wxSashEvent(id, edge), _sig(NULL), _pObj(NULL) {}
	~wx_SashEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SashEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SashEvent::~wx_SashEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_SashEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSashEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(SashEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SashEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "edge", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SashEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int id = 0;
	if (args.IsValid(0)) id = args.GetInt(0);
	wxSashEdgePosition edge = wxSASH_NONE;
	if (args.IsValid(1)) edge = static_cast<wxSashEdgePosition>(args.GetInt(1));
	wx_SashEvent *pEntity = new wx_SashEvent(id, edge);
	Object_wx_SashEvent *pObj = Object_wx_SashEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_SashEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_SashEvent, GetEdge)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashEvent, GetEdge)
{
	Object_wx_SashEvent *pSelf = Object_wx_SashEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSashEdgePosition rtn = pSelf->GetEntity()->GetEdge();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SashEvent, GetDragRect)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashEvent, GetDragRect)
{
	Object_wx_SashEvent *pSelf = Object_wx_SashEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRect rtn = pSelf->GetEntity()->GetDragRect();
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_SashEvent, GetDragStatus)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashEvent, GetDragStatus)
{
	Object_wx_SashEvent *pSelf = Object_wx_SashEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSashDragStatus rtn = pSelf->GetEntity()->GetDragStatus();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxSashEvent
//----------------------------------------------------------------------------
Object_wx_SashEvent::~Object_wx_SashEvent()
{
}

Object *Object_wx_SashEvent::Clone() const
{
	return NULL;
}

String Object_wx_SashEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.SashEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_SashEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(SashEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxSashEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SashEvent)
{
	Gura_AssignMethod(wx_SashEvent, GetEdge);
	Gura_AssignMethod(wx_SashEvent, GetDragRect);
	Gura_AssignMethod(wx_SashEvent, GetDragStatus);
}

Gura_ImplementDescendantCreator(wx_SashEvent)
{
	return new Object_wx_SashEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
