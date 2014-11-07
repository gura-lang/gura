//----------------------------------------------------------------------------
// wxSysColourChangedEvent
// extracted from sysclevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SysColourChangedEvent: public wxSysColourChangedEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_SysColourChangedEvent *_pObj;
public:
	inline wx_SysColourChangedEvent() : wxSysColourChangedEvent(), _sig(NULL), _pObj(NULL) {}
	~wx_SysColourChangedEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SysColourChangedEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SysColourChangedEvent::~wx_SysColourChangedEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_SysColourChangedEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSysColourChangedEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(SysColourChangedEventEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SysColourChangedEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SysColourChangedEventEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_SysColourChangedEvent *pEntity = new wx_SysColourChangedEvent();
	Object_wx_SysColourChangedEvent *pObj = Object_wx_SysColourChangedEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_SysColourChangedEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxSysColourChangedEvent
//----------------------------------------------------------------------------
Object_wx_SysColourChangedEvent::~Object_wx_SysColourChangedEvent()
{
}

Object *Object_wx_SysColourChangedEvent::Clone() const
{
	return NULL;
}

String Object_wx_SysColourChangedEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SysColourChangedEvent:");
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
// Class implementation for wxSysColourChangedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SysColourChangedEvent)
{
	Gura_AssignFunction(SysColourChangedEventEmpty);
}

Gura_ImplementDescendantCreator(wx_SysColourChangedEvent)
{
	return new Object_wx_SysColourChangedEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
