//----------------------------------------------------------------------------
// wxWizardEvent
// extracted from wizevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_WizardEvent: public wxWizardEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_WizardEvent *_pObj;
public:
	inline wx_WizardEvent(wxEventType type, int id, bool direction) : wxWizardEvent(type, id, direction), _pObj(nullptr) {}
	~wx_WizardEvent();
	inline void AssocWithGura(Object_wx_WizardEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_WizardEvent::~wx_WizardEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_WizardEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxWizardEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(WizardEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_WizardEvent));
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "direction", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WizardEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxEventType type = wxEVT_NULL;
	if (args.IsValid(0)) type = static_cast<wxEventType>(args.GetInt(0));
	int id = -1;
	if (args.IsValid(1)) id = args.GetInt(1);
	bool direction = true;
	if (args.IsValid(2)) direction = args.GetBoolean(2);
	wx_WizardEvent *pEntity = new wx_WizardEvent(type, id, direction);
	Object_wx_WizardEvent *pObj = Object_wx_WizardEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_WizardEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_WizardEvent, GetDirection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_WizardEvent, GetDirection)
{
	Signal &sig = env.GetSignal();
	Object_wx_WizardEvent *pThis = Object_wx_WizardEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetDirection();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_WizardEvent, GetPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_WizardEvent, GetPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_WizardEvent *pThis = Object_wx_WizardEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWizardPage *rtn = (wxWizardPage *)pThis->GetEntity()->GetPage();
	return ReturnValue(env, args, Value(new Object_wx_WizardPage(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxWizardEvent
//----------------------------------------------------------------------------
Object_wx_WizardEvent::~Object_wx_WizardEvent()
{
}

Object *Object_wx_WizardEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WizardEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WizardEvent:");
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
// Class implementation for wxWizardEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WizardEvent)
{
	Gura_AssignFunction(WizardEvent);
	Gura_AssignMethod(wx_WizardEvent, GetDirection);
	Gura_AssignMethod(wx_WizardEvent, GetPage);
}

Gura_ImplementDescendantCreator(wx_WizardEvent)
{
	return new Object_wx_WizardEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
