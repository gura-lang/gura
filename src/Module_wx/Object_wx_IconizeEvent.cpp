//----------------------------------------------------------------------------
// wxIconizeEvent
// extracted from iconevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_IconizeEvent: public wxIconizeEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_IconizeEvent *_pObj;
public:
	inline wx_IconizeEvent(int id, bool iconized) : wxIconizeEvent(id, iconized), _sig(NULL), _pObj(NULL) {}
	~wx_IconizeEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_IconizeEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_IconizeEvent::~wx_IconizeEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_IconizeEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxIconizeEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(IconizeEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_IconizeEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "iconized", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IconizeEvent)
{
	int id = 0;
	if (args.IsValid(0)) id = args.GetInt(0);
	bool iconized = true;
	if (args.IsValid(1)) iconized = args.GetBoolean(1);
	wx_IconizeEvent *pEntity = new wx_IconizeEvent(id, iconized);
	Object_wx_IconizeEvent *pObj = Object_wx_IconizeEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_IconizeEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_IconizeEvent, Iconized)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IconizeEvent, Iconized)
{
	Object_wx_IconizeEvent *pSelf = Object_wx_IconizeEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->Iconized();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxIconizeEvent
//----------------------------------------------------------------------------
Object_wx_IconizeEvent::~Object_wx_IconizeEvent()
{
}

Object *Object_wx_IconizeEvent::Clone() const
{
	return NULL;
}

String Object_wx_IconizeEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.IconizeEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_IconizeEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(IconizeEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxIconizeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IconizeEvent)
{
	Gura_AssignMethod(wx_IconizeEvent, Iconized);
}

Gura_ImplementDescendantCreator(wx_IconizeEvent)
{
	return new Object_wx_IconizeEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
