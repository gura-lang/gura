//----------------------------------------------------------------------------
// wxMaximizeEvent
// extracted from maxzevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MaximizeEvent: public wxMaximizeEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MaximizeEvent *_pObj;
public:
	inline wx_MaximizeEvent(int id) : wxMaximizeEvent(id), _sig(NULL), _pObj(NULL) {}
	~wx_MaximizeEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MaximizeEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MaximizeEvent::~wx_MaximizeEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MaximizeEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMaximizeEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(MaximizeEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MaximizeEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MaximizeEvent)
{
	int id = 0;
	if (args.IsValid(0)) id = args.GetInt(0);
	wx_MaximizeEvent *pEntity = new wx_MaximizeEvent(id);
	Object_wx_MaximizeEvent *pObj = Object_wx_MaximizeEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MaximizeEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

//----------------------------------------------------------------------------
// Object implementation for wxMaximizeEvent
//----------------------------------------------------------------------------
Object_wx_MaximizeEvent::~Object_wx_MaximizeEvent()
{
}

Object *Object_wx_MaximizeEvent::Clone() const
{
	return NULL;
}

String Object_wx_MaximizeEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.MaximizeEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_MaximizeEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(MaximizeEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxMaximizeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MaximizeEvent)
{
}

Gura_ImplementDescendantCreator(wx_MaximizeEvent)
{
	return new Object_wx_MaximizeEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
