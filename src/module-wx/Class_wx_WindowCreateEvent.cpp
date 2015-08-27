//----------------------------------------------------------------------------
// wxWindowCreateEvent
// extracted from createevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_WindowCreateEvent: public wxWindowCreateEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_WindowCreateEvent *_pObj;
public:
	inline wx_WindowCreateEvent(wxWindow* win) : wxWindowCreateEvent(win), _pObj(nullptr) {}
	~wx_WindowCreateEvent();
	inline void AssocWithGura(Object_wx_WindowCreateEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_WindowCreateEvent::~wx_WindowCreateEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_WindowCreateEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowCreateEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(WindowCreateEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_WindowCreateEvent));
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WindowCreateEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *win = (wxWindow *)(nullptr);
	if (args.IsValid(0)) win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wx_WindowCreateEvent *pEntity = new wx_WindowCreateEvent(win);
	Object_wx_WindowCreateEvent *pObj = Object_wx_WindowCreateEvent::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_WindowCreateEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxWindowCreateEvent
//----------------------------------------------------------------------------
Object_wx_WindowCreateEvent::~Object_wx_WindowCreateEvent()
{
}

Object *Object_wx_WindowCreateEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WindowCreateEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WindowCreateEvent:");
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
// Class implementation for wxWindowCreateEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowCreateEvent)
{
	Gura_AssignFunction(WindowCreateEvent);
}

Gura_ImplementDescendantCreator(wx_WindowCreateEvent)
{
	return new Object_wx_WindowCreateEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
