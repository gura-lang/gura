//----------------------------------------------------------------------------
// wxQueryLayoutInfoEvent
// extracted from qylayevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_QueryLayoutInfoEvent: public wxQueryLayoutInfoEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_QueryLayoutInfoEvent *_pObj;
public:
	inline wx_QueryLayoutInfoEvent(wxWindowID id) : wxQueryLayoutInfoEvent(id), _pObj(nullptr) {}
	~wx_QueryLayoutInfoEvent();
	inline void AssocWithGura(Object_wx_QueryLayoutInfoEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_QueryLayoutInfoEvent::~wx_QueryLayoutInfoEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_QueryLayoutInfoEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxQueryLayoutInfoEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(QueryLayoutInfoEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_QueryLayoutInfoEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(QueryLayoutInfoEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindowID id = 0;
	if (arg.IsValid(0)) id = static_cast<wxWindowID>(arg.GetInt(0));
	wx_QueryLayoutInfoEvent *pEntity = new wx_QueryLayoutInfoEvent(id);
	Object_wx_QueryLayoutInfoEvent *pObj = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_QueryLayoutInfoEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, GetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, GetAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->GetAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetFlags();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, GetOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, GetOrientation)
{
	Signal &sig = env.GetSignal();
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLayoutOrientation rtn = pThis->GetEntity()->GetOrientation();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, GetRequestedLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, GetRequestedLength)
{
	Signal &sig = env.GetSignal();
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetRequestedLength();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, SetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, SetAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLayoutAlignment alignment = static_cast<wxLayoutAlignment>(arg.GetInt(0));
	pThis->GetEntity()->SetAlignment(alignment);
	return Value::Nil;
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int flags = arg.GetInt(0);
	pThis->GetEntity()->SetFlags(flags);
	return Value::Nil;
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, SetOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, SetOrientation)
{
	Signal &sig = env.GetSignal();
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLayoutOrientation orientation = static_cast<wxLayoutOrientation>(arg.GetInt(0));
	pThis->GetEntity()->SetOrientation(orientation);
	return Value::Nil;
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, SetRequestedLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, SetRequestedLength)
{
	Signal &sig = env.GetSignal();
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int length = arg.GetInt(0);
	pThis->GetEntity()->SetRequestedLength(length);
	return Value::Nil;
}

Gura_DeclareMethod(wx_QueryLayoutInfoEvent, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_QueryLayoutInfoEvent, SetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_QueryLayoutInfoEvent *pThis = Object_wx_QueryLayoutInfoEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetSize(*size);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxQueryLayoutInfoEvent
//----------------------------------------------------------------------------
Object_wx_QueryLayoutInfoEvent::~Object_wx_QueryLayoutInfoEvent()
{
}

Object *Object_wx_QueryLayoutInfoEvent::Clone() const
{
	return nullptr;
}

String Object_wx_QueryLayoutInfoEvent::ToString(bool exprFlag)
{
	String rtn("<wx.QueryLayoutInfoEvent:");
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
// Class implementation for wxQueryLayoutInfoEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_QueryLayoutInfoEvent)
{
	Gura_AssignFunction(QueryLayoutInfoEvent);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, GetAlignment);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, GetFlags);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, GetOrientation);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, GetRequestedLength);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, GetSize);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, SetAlignment);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, SetFlags);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, SetOrientation);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, SetRequestedLength);
	Gura_AssignMethod(wx_QueryLayoutInfoEvent, SetSize);
}

Gura_ImplementDescendantCreator(wx_QueryLayoutInfoEvent)
{
	return new Object_wx_QueryLayoutInfoEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
