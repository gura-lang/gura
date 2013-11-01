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
	Gura::Signal _sig;
	Object_wx_CalculateLayoutEvent *_pObj;
public:
	inline wx_CalculateLayoutEvent(wxWindowID id) : wxCalculateLayoutEvent(id), _sig(NULL), _pObj(NULL) {}
	~wx_CalculateLayoutEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_CalculateLayoutEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CalculateLayoutEvent::~wx_CalculateLayoutEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_CalculateLayoutEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCalculateLayoutEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(CalculateLayoutEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (pObj == NULL) {
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
	SetMode(RSLTMODE_Normal, FLAG_None);
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
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalculateLayoutEvent, GetRect)
{
	Object_wx_CalculateLayoutEvent *pThis = Object_wx_CalculateLayoutEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect rtn = pThis->GetEntity()->GetRect();
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalculateLayoutEvent, SetFlags)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
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
	SetMode(RSLTMODE_Void, FLAG_Map);
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
	return NULL;
}

String Object_wx_CalculateLayoutEvent::ToString(bool exprFlag)
{
	String rtn("<wx.CalculateLayoutEvent:");
	if (GetEntity() == NULL) {
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
	return new Object_wx_CalculateLayoutEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
