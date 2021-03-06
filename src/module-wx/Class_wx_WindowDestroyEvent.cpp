//----------------------------------------------------------------------------
// wxWindowDestroyEvent
// extracted from destroyevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_WindowDestroyEvent: public wxWindowDestroyEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_WindowDestroyEvent *_pObj;
public:
	inline wx_WindowDestroyEvent(wxWindow* win) : wxWindowDestroyEvent(win), _pObj(nullptr) {}
	~wx_WindowDestroyEvent();
	inline void AssocWithGura(Object_wx_WindowDestroyEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_WindowDestroyEvent::~wx_WindowDestroyEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_WindowDestroyEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowDestroyEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(WindowDestroyEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_WindowDestroyEvent));
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WindowDestroyEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *win = (wxWindow *)(nullptr);
	if (arg.IsValid(0)) win = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wx_WindowDestroyEvent *pEntity = new wx_WindowDestroyEvent(win);
	Object_wx_WindowDestroyEvent *pObj = Object_wx_WindowDestroyEvent::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_WindowDestroyEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxWindowDestroyEvent
//----------------------------------------------------------------------------
Object_wx_WindowDestroyEvent::~Object_wx_WindowDestroyEvent()
{
}

Object *Object_wx_WindowDestroyEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WindowDestroyEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WindowDestroyEvent:");
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
// Class implementation for wxWindowDestroyEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowDestroyEvent)
{
	Gura_AssignFunction(WindowDestroyEvent);
}

Gura_ImplementDescendantCreator(wx_WindowDestroyEvent)
{
	return new Object_wx_WindowDestroyEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
