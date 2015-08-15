//----------------------------------------------------------------------------
// wxChildFocusEvent
// extracted from chfocevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ChildFocusEvent: public wxChildFocusEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ChildFocusEvent *_pObj;
public:
	inline wx_ChildFocusEvent(wxWindow * win) : wxChildFocusEvent(win), _pObj(nullptr) {}
	~wx_ChildFocusEvent();
	inline void AssocWithGura(Object_wx_ChildFocusEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ChildFocusEvent::~wx_ChildFocusEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ChildFocusEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxChildFocusEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(ChildFocusEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ChildFocusEvent));
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ChildFocusEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *win = (wxWindow *)(nullptr);
	if (args.IsValid(0)) win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wx_ChildFocusEvent *pEntity = new wx_ChildFocusEvent(win);
	Object_wx_ChildFocusEvent *pObj = Object_wx_ChildFocusEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ChildFocusEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxChildFocusEvent
//----------------------------------------------------------------------------
Object_wx_ChildFocusEvent::~Object_wx_ChildFocusEvent()
{
}

Object *Object_wx_ChildFocusEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ChildFocusEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ChildFocusEvent:");
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
// Class implementation for wxChildFocusEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ChildFocusEvent)
{
	Gura_AssignFunction(ChildFocusEvent);
}

Gura_ImplementDescendantCreator(wx_ChildFocusEvent)
{
	return new Object_wx_ChildFocusEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
