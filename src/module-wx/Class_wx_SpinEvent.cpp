//----------------------------------------------------------------------------
// wxSpinEvent
// extracted from spinevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SpinEvent: public wxSpinEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SpinEvent *_pObj;
public:
	inline wx_SpinEvent(wxEventType commandType, int id) : wxSpinEvent(commandType, id), _pObj(nullptr) {}
	~wx_SpinEvent();
	inline void AssocWithGura(Object_wx_SpinEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SpinEvent::~wx_SpinEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SpinEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSpinEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(SpinEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SpinEvent));
	DeclareArg(env, "commandType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SpinEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxEventType commandType = wxEVT_NULL;
	if (arg.IsValid(0)) commandType = static_cast<wxEventType>(arg.GetInt(0));
	int id = 0;
	if (arg.IsValid(1)) id = arg.GetInt(1);
	wx_SpinEvent *pEntity = new wx_SpinEvent(commandType, id);
	Object_wx_SpinEvent *pObj = Object_wx_SpinEvent::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_SpinEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_SpinEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SpinEvent, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinEvent *pThis = Object_wx_SpinEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SpinEvent, SetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinEvent, SetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinEvent *pThis = Object_wx_SpinEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int pos = arg.GetInt(0);
	pThis->GetEntity()->SetPosition(pos);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxSpinEvent
//----------------------------------------------------------------------------
Object_wx_SpinEvent::~Object_wx_SpinEvent()
{
}

Object *Object_wx_SpinEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SpinEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SpinEvent:");
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
// Class implementation for wxSpinEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SpinEvent)
{
	Gura_AssignFunction(SpinEvent);
	Gura_AssignMethod(wx_SpinEvent, GetPosition);
	Gura_AssignMethod(wx_SpinEvent, SetPosition);
}

Gura_ImplementDescendantCreator(wx_SpinEvent)
{
	return new Object_wx_SpinEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
