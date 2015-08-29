//----------------------------------------------------------------------------
// wxMouseCaptureLostEvent
// extracted from mcaptevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MouseCaptureLostEvent: public wxMouseCaptureLostEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MouseCaptureLostEvent *_pObj;
public:
	inline wx_MouseCaptureLostEvent(wxWindowID windowId) : wxMouseCaptureLostEvent(windowId), _pObj(nullptr) {}
	~wx_MouseCaptureLostEvent();
	inline void AssocWithGura(Object_wx_MouseCaptureLostEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MouseCaptureLostEvent::~wx_MouseCaptureLostEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MouseCaptureLostEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMouseCaptureLostEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(MouseCaptureLostEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MouseCaptureLostEvent));
	DeclareArg(env, "windowId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MouseCaptureLostEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindowID windowId = 0;
	if (arg.IsValid(0)) windowId = static_cast<wxWindowID>(arg.GetInt(0));
	wx_MouseCaptureLostEvent *pEntity = new wx_MouseCaptureLostEvent(windowId);
	Object_wx_MouseCaptureLostEvent *pObj = Object_wx_MouseCaptureLostEvent::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_MouseCaptureLostEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxMouseCaptureLostEvent
//----------------------------------------------------------------------------
Object_wx_MouseCaptureLostEvent::~Object_wx_MouseCaptureLostEvent()
{
}

Object *Object_wx_MouseCaptureLostEvent::Clone() const
{
	return nullptr;
}

String Object_wx_MouseCaptureLostEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MouseCaptureLostEvent:");
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
// Class implementation for wxMouseCaptureLostEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseCaptureLostEvent)
{
	Gura_AssignFunction(MouseCaptureLostEvent);
}

Gura_ImplementDescendantCreator(wx_MouseCaptureLostEvent)
{
	return new Object_wx_MouseCaptureLostEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
