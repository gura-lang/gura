//----------------------------------------------------------------------------
// wxEraseEvent
// extracted from eraseevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_EraseEvent: public wxEraseEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_EraseEvent *_pObj;
public:
	inline wx_EraseEvent(int id, wxDC* dc) : wxEraseEvent(id, dc), _pObj(nullptr) {}
	~wx_EraseEvent();
	inline void AssocWithGura(Object_wx_EraseEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_EraseEvent::~wx_EraseEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_EraseEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxEraseEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(EraseEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_EraseEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(EraseEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int id = 0;
	if (args.IsValid(0)) id = args.GetInt(0);
	wxDC *dc = (wxDC *)(nullptr);
	if (args.IsValid(1)) dc = Object_wx_DC::GetObject(args, 1)->GetEntity();
	wx_EraseEvent *pEntity = new wx_EraseEvent(id, dc);
	Object_wx_EraseEvent *pObj = Object_wx_EraseEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_EraseEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_EraseEvent, GetDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EraseEvent, GetDC)
{
	Signal &sig = env.GetSignal();
	Object_wx_EraseEvent *pThis = Object_wx_EraseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *rtn = (wxDC *)pThis->GetEntity()->GetDC();
	return ReturnValue(env, args, Value(new Object_wx_DC(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxEraseEvent
//----------------------------------------------------------------------------
Object_wx_EraseEvent::~Object_wx_EraseEvent()
{
}

Object *Object_wx_EraseEvent::Clone() const
{
	return nullptr;
}

String Object_wx_EraseEvent::ToString(bool exprFlag)
{
	String rtn("<wx.EraseEvent:");
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
// Class implementation for wxEraseEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EraseEvent)
{
	Gura_AssignFunction(EraseEvent);
	Gura_AssignMethod(wx_EraseEvent, GetDC);
}

Gura_ImplementDescendantCreator(wx_EraseEvent)
{
	return new Object_wx_EraseEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
