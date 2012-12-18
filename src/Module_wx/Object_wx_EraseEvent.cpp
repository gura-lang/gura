//----------------------------------------------------------------------------
// wxEraseEvent
// extracted from eraseevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_EraseEvent: public wxEraseEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_EraseEvent *_pObj;
public:
	inline wx_EraseEvent(int id, wxDC* dc) : wxEraseEvent(id, dc), _sig(NULL), _pObj(NULL) {}
	~wx_EraseEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_EraseEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_EraseEvent::~wx_EraseEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_EraseEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxEraseEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(EraseEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_EraseEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(EraseEvent)
{
	int id = 0;
	if (args.IsValid(0)) id = args.GetInt(0);
	wxDC *dc = (wxDC *)(NULL);
	if (args.IsValid(1)) dc = Object_wx_DC::GetObject(args, 1)->GetEntity();
	wx_EraseEvent *pEntity = new wx_EraseEvent(id, dc);
	Object_wx_EraseEvent *pObj = Object_wx_EraseEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_EraseEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_EraseEvent, GetDC)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EraseEvent, GetDC)
{
	Object_wx_EraseEvent *pSelf = Object_wx_EraseEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *rtn = (wxDC *)pSelf->GetEntity()->GetDC();
	return ReturnValue(env, sig, args, Value(new Object_wx_DC(rtn, NULL, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxEraseEvent
//----------------------------------------------------------------------------
Object_wx_EraseEvent::~Object_wx_EraseEvent()
{
}

Object *Object_wx_EraseEvent::Clone() const
{
	return NULL;
}

String Object_wx_EraseEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.EraseEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_EraseEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(EraseEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxEraseEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EraseEvent)
{
	Gura_AssignMethod(wx_EraseEvent, GetDC);
}

Gura_ImplementDescendantCreator(wx_EraseEvent)
{
	return new Object_wx_EraseEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
