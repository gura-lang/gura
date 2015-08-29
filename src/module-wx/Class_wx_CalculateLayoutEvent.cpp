//----------------------------------------------------------------------------
// wxCalculateLayoutEvent
// extracted from calclevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CalculateLayoutEvent: public wxCalculateLayoutEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_CalculateLayoutEvent *_pObj;
public:
	inline wx_CalculateLayoutEvent(wxWindowID id) : wxCalculateLayoutEvent(id), _pObj(nullptr) {}
	~wx_CalculateLayoutEvent();
	inline void AssocWithGura(Object_wx_CalculateLayoutEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CalculateLayoutEvent::~wx_CalculateLayoutEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_CalculateLayoutEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCalculateLayoutEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(CalculateLayoutEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_CalculateLayoutEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CalculateLayoutEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindowID id = 0;
	if (arg.IsValid(0)) id = static_cast<wxWindowID>(arg.GetInt(0));
	wx_CalculateLayoutEvent *pEntity = new wx_CalculateLayoutEvent(id);
	Object_wx_CalculateLayoutEvent *pObj = Object_wx_CalculateLayoutEvent::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_CalculateLayoutEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_CalculateLayoutEvent, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalculateLayoutEvent, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalculateLayoutEvent *pThis = Object_wx_CalculateLayoutEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetFlags();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_CalculateLayoutEvent, GetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalculateLayoutEvent, GetRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalculateLayoutEvent *pThis = Object_wx_CalculateLayoutEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect rtn = pThis->GetEntity()->GetRect();
	return ReturnValue(env, arg, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalculateLayoutEvent, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalculateLayoutEvent, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalculateLayoutEvent *pThis = Object_wx_CalculateLayoutEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int flags = arg.GetInt(0);
	pThis->GetEntity()->SetFlags(flags);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalculateLayoutEvent, SetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalculateLayoutEvent, SetRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalculateLayoutEvent *pThis = Object_wx_CalculateLayoutEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetRect(*rect);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxCalculateLayoutEvent
//----------------------------------------------------------------------------
Object_wx_CalculateLayoutEvent::~Object_wx_CalculateLayoutEvent()
{
}

Object *Object_wx_CalculateLayoutEvent::Clone() const
{
	return nullptr;
}

String Object_wx_CalculateLayoutEvent::ToString(bool exprFlag)
{
	String rtn("<wx.CalculateLayoutEvent:");
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
// Class implementation for wxCalculateLayoutEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CalculateLayoutEvent)
{
	Gura_AssignFunction(CalculateLayoutEvent);
	Gura_AssignMethod(wx_CalculateLayoutEvent, GetFlags);
	Gura_AssignMethod(wx_CalculateLayoutEvent, GetRect);
	Gura_AssignMethod(wx_CalculateLayoutEvent, SetFlags);
	Gura_AssignMethod(wx_CalculateLayoutEvent, SetRect);
}

Gura_ImplementDescendantCreator(wx_CalculateLayoutEvent)
{
	return new Object_wx_CalculateLayoutEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
