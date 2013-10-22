//----------------------------------------------------------------------------
// wxCollapsiblePaneEvent
// extracted from collpane.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CollapsiblePaneEvent: public wxCollapsiblePaneEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_CollapsiblePaneEvent *_pObj;
public:
	inline wx_CollapsiblePaneEvent(wxObject * generator, int id, bool collapsed) : wxCollapsiblePaneEvent(generator, id, collapsed), _sig(NULL), _pObj(NULL) {}
	~wx_CollapsiblePaneEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_CollapsiblePaneEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CollapsiblePaneEvent::~wx_CollapsiblePaneEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_CollapsiblePaneEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCollapsiblePaneEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(CollapsiblePaneEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_CollapsiblePaneEvent));
	DeclareArg(env, "generator", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "collapsed", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CollapsiblePaneEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxObject *generator = Object_wx_Object::GetObject(args, 0)->GetEntity();
	int id = args.GetInt(1);
	bool collapsed = args.GetBoolean(2);
	wx_CollapsiblePaneEvent *pEntity = new wx_CollapsiblePaneEvent(generator, id, collapsed);
	Object_wx_CollapsiblePaneEvent *pObj = Object_wx_CollapsiblePaneEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CollapsiblePaneEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_CollapsiblePaneEvent, GetCollapsed)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CollapsiblePaneEvent, GetCollapsed)
{
	Object_wx_CollapsiblePaneEvent *pThis = Object_wx_CollapsiblePaneEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetCollapsed();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CollapsiblePaneEvent, SetCollapsed)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "collapsed", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_CollapsiblePaneEvent, SetCollapsed)
{
	Object_wx_CollapsiblePaneEvent *pThis = Object_wx_CollapsiblePaneEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool collapsed = args.GetBoolean(0);
	pThis->GetEntity()->SetCollapsed(collapsed);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxCollapsiblePaneEvent
//----------------------------------------------------------------------------
Object_wx_CollapsiblePaneEvent::~Object_wx_CollapsiblePaneEvent()
{
}

Object *Object_wx_CollapsiblePaneEvent::Clone() const
{
	return NULL;
}

String Object_wx_CollapsiblePaneEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.CollapsiblePaneEvent:");
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
// Class implementation for wxCollapsiblePaneEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CollapsiblePaneEvent)
{
	Gura_AssignFunction(CollapsiblePaneEvent);
	Gura_AssignMethod(wx_CollapsiblePaneEvent, GetCollapsed);
	Gura_AssignMethod(wx_CollapsiblePaneEvent, SetCollapsed);
}

Gura_ImplementDescendantCreator(wx_CollapsiblePaneEvent)
{
	return new Object_wx_CollapsiblePaneEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
