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
	Gura::Signal *_pSig;
	Object_wx_CalculateLayoutEvent *_pObj;
public:
	inline wx_CalculateLayoutEvent(wxWindowID id) : wxCalculateLayoutEvent(id), _pSig(nullptr), _pObj(nullptr) {}
	~wx_CalculateLayoutEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_CalculateLayoutEvent *pObj) {
		_pSig = &sig, _pObj = pObj;
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindowID id = 0;
	if (args.IsValid(0)) id = static_cast<wxWindowID>(args.GetInt(0));
	wx_CalculateLayoutEvent *pEntity = new wx_CalculateLayoutEvent(id);
	Object_wx_CalculateLayoutEvent *pObj = Object_wx_CalculateLayoutEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_CalculateLayoutEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_CalculateLayoutEvent, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalculateLayoutEvent, GetFlags)
{
	Object_wx_CalculateLayoutEvent *pThis = Object_wx_CalculateLayoutEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetFlags();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CalculateLayoutEvent, GetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalculateLayoutEvent, GetRect)
{
	Object_wx_CalculateLayoutEvent *pThis = Object_wx_CalculateLayoutEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect rtn = pThis->GetEntity()->GetRect();
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalculateLayoutEvent, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalculateLayoutEvent, SetFlags)
{
	Object_wx_CalculateLayoutEvent *pThis = Object_wx_CalculateLayoutEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int flags = args.GetInt(0);
	pThis->GetEntity()->SetFlags(flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_CalculateLayoutEvent, SetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalculateLayoutEvent, SetRect)
{
	Object_wx_CalculateLayoutEvent *pThis = Object_wx_CalculateLayoutEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetRect(*rect);
	return Value::Null;
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
