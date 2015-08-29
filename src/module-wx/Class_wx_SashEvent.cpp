//----------------------------------------------------------------------------
// wxSashEvent
// extracted from sashevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SashEvent: public wxSashEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SashEvent *_pObj;
public:
	inline wx_SashEvent(int id, wxSashEdgePosition edge) : wxSashEvent(id, edge), _pObj(nullptr) {}
	~wx_SashEvent();
	inline void AssocWithGura(Object_wx_SashEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SashEvent::~wx_SashEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SashEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSashEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(SashEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SashEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "edge", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SashEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int id = 0;
	if (arg.IsValid(0)) id = arg.GetInt(0);
	wxSashEdgePosition edge = wxSASH_NONE;
	if (arg.IsValid(1)) edge = static_cast<wxSashEdgePosition>(arg.GetInt(1));
	wx_SashEvent *pEntity = new wx_SashEvent(id, edge);
	Object_wx_SashEvent *pObj = Object_wx_SashEvent::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_SashEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_SashEvent, GetEdge)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashEvent, GetEdge)
{
	Signal &sig = env.GetSignal();
	Object_wx_SashEvent *pThis = Object_wx_SashEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSashEdgePosition rtn = pThis->GetEntity()->GetEdge();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SashEvent, GetDragRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashEvent, GetDragRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_SashEvent *pThis = Object_wx_SashEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect rtn = pThis->GetEntity()->GetDragRect();
	return ReturnValue(env, arg, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_SashEvent, GetDragStatus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashEvent, GetDragStatus)
{
	Signal &sig = env.GetSignal();
	Object_wx_SashEvent *pThis = Object_wx_SashEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSashDragStatus rtn = pThis->GetEntity()->GetDragStatus();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxSashEvent
//----------------------------------------------------------------------------
Object_wx_SashEvent::~Object_wx_SashEvent()
{
}

Object *Object_wx_SashEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SashEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SashEvent:");
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
// Class implementation for wxSashEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SashEvent)
{
	Gura_AssignFunction(SashEvent);
	Gura_AssignMethod(wx_SashEvent, GetEdge);
	Gura_AssignMethod(wx_SashEvent, GetDragRect);
	Gura_AssignMethod(wx_SashEvent, GetDragStatus);
}

Gura_ImplementDescendantCreator(wx_SashEvent)
{
	return new Object_wx_SashEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
