//----------------------------------------------------------------------------
// wxSpinEvent
// extracted from spinevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SpinEvent: public wxSpinEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_SpinEvent *_pObj;
public:
	inline wx_SpinEvent(wxEventType commandType, int id) : wxSpinEvent(commandType, id), _sig(NULL), _pObj(NULL) {}
	~wx_SpinEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SpinEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SpinEvent::~wx_SpinEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_SpinEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSpinEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(SpinEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SpinEvent));
	DeclareArg(env, "commandType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SpinEvent)
{
	wxEventType commandType = wxEVT_NULL;
	if (args.IsValid(0)) commandType = static_cast<wxEventType>(args.GetInt(0));
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_SpinEvent *pEntity = new wx_SpinEvent(commandType, id);
	Object_wx_SpinEvent *pObj = Object_wx_SpinEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_SpinEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_SpinEvent, GetPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SpinEvent, GetPosition)
{
	Object_wx_SpinEvent *pSelf = Object_wx_SpinEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SpinEvent, SetPosition)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinEvent, SetPosition)
{
	Object_wx_SpinEvent *pSelf = Object_wx_SpinEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int pos = args.GetInt(0);
	pSelf->GetEntity()->SetPosition(pos);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxSpinEvent
//----------------------------------------------------------------------------
Object_wx_SpinEvent::~Object_wx_SpinEvent()
{
}

Object *Object_wx_SpinEvent::Clone() const
{
	return NULL;
}

String Object_wx_SpinEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.SpinEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_SpinEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(SpinEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxSpinEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SpinEvent)
{
	Gura_AssignMethod(wx_SpinEvent, GetPosition);
	Gura_AssignMethod(wx_SpinEvent, SetPosition);
}

Gura_ImplementDescendantCreator(wx_SpinEvent)
{
	return new Object_wx_SpinEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
