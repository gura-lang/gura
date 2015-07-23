//----------------------------------------------------------------------------
// wxFocusEvent
// extracted from focusevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FocusEvent: public wxFocusEvent, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_FocusEvent *_pObj;
public:
	inline wx_FocusEvent(WXTYPE eventType, int id) : wxFocusEvent(eventType, id), _pSig(nullptr), _pObj(nullptr) {}
	~wx_FocusEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FocusEvent *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FocusEvent::~wx_FocusEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FocusEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFocusEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(FocusEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FocusEvent));
	DeclareArg(env, "eventType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FocusEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	WXTYPE eventType = 0;
	if (args.IsValid(0)) eventType = static_cast<WXTYPE>(args.GetInt(0));
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_FocusEvent *pEntity = new wx_FocusEvent(eventType, id);
	Object_wx_FocusEvent *pObj = Object_wx_FocusEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_FocusEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_FocusEvent, GetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
}

Gura_ImplementMethod(wx_FocusEvent, GetWindow)
{
	Object_wx_FocusEvent *pThis = Object_wx_FocusEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = pThis->GetEntity()->GetWindow();
	return Value(new Object_wx_Window(rtn, nullptr, false));
}

//----------------------------------------------------------------------------
// Object implementation for wxFocusEvent
//----------------------------------------------------------------------------
Object_wx_FocusEvent::~Object_wx_FocusEvent()
{
}

Object *Object_wx_FocusEvent::Clone() const
{
	return nullptr;
}

String Object_wx_FocusEvent::ToString(bool exprFlag)
{
	String rtn("<wx.FocusEvent:");
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
// Class implementation for wxFocusEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FocusEvent)
{
	Gura_AssignFunction(FocusEvent);
	Gura_AssignMethod(wx_FocusEvent, GetWindow);
}

Gura_ImplementDescendantCreator(wx_FocusEvent)
{
	return new Object_wx_FocusEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
