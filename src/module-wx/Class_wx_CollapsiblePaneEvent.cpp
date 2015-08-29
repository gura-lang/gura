//----------------------------------------------------------------------------
// wxCollapsiblePaneEvent
// extracted from collpane.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CollapsiblePaneEvent: public wxCollapsiblePaneEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_CollapsiblePaneEvent *_pObj;
public:
	inline wx_CollapsiblePaneEvent(wxObject * generator, int id, bool collapsed) : wxCollapsiblePaneEvent(generator, id, collapsed), _pObj(nullptr) {}
	~wx_CollapsiblePaneEvent();
	inline void AssocWithGura(Object_wx_CollapsiblePaneEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CollapsiblePaneEvent::~wx_CollapsiblePaneEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_CollapsiblePaneEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCollapsiblePaneEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(CollapsiblePaneEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_CollapsiblePaneEvent));
	DeclareArg(env, "generator", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "collapsed", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CollapsiblePaneEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxObject *generator = Object_wx_Object::GetObject(arg, 0)->GetEntity();
	int id = arg.GetInt(1);
	bool collapsed = arg.GetBoolean(2);
	wx_CollapsiblePaneEvent *pEntity = new wx_CollapsiblePaneEvent(generator, id, collapsed);
	Object_wx_CollapsiblePaneEvent *pObj = Object_wx_CollapsiblePaneEvent::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_CollapsiblePaneEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_CollapsiblePaneEvent, GetCollapsed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CollapsiblePaneEvent, GetCollapsed)
{
	Signal &sig = env.GetSignal();
	Object_wx_CollapsiblePaneEvent *pThis = Object_wx_CollapsiblePaneEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetCollapsed();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_CollapsiblePaneEvent, SetCollapsed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "collapsed", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_CollapsiblePaneEvent, SetCollapsed)
{
	Signal &sig = env.GetSignal();
	Object_wx_CollapsiblePaneEvent *pThis = Object_wx_CollapsiblePaneEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool collapsed = arg.GetBoolean(0);
	pThis->GetEntity()->SetCollapsed(collapsed);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxCollapsiblePaneEvent
//----------------------------------------------------------------------------
Object_wx_CollapsiblePaneEvent::~Object_wx_CollapsiblePaneEvent()
{
}

Object *Object_wx_CollapsiblePaneEvent::Clone() const
{
	return nullptr;
}

String Object_wx_CollapsiblePaneEvent::ToString(bool exprFlag)
{
	String rtn("<wx.CollapsiblePaneEvent:");
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
	return new Object_wx_CollapsiblePaneEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
