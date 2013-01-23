//----------------------------------------------------------------------------
// wxPaintEvent
// extracted from paintevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PaintEvent: public wxPaintEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PaintEvent *_pObj;
public:
	inline wx_PaintEvent(int id) : wxPaintEvent(id), _sig(NULL), _pObj(NULL) {}
	~wx_PaintEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PaintEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PaintEvent::~wx_PaintEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PaintEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPaintEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(PaintEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PaintEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PaintEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int id = 0;
	if (args.IsValid(0)) id = args.GetInt(0);
	wx_PaintEvent *pEntity = new wx_PaintEvent(id);
	Object_wx_PaintEvent *pObj = Object_wx_PaintEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PaintEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

//----------------------------------------------------------------------------
// Object implementation for wxPaintEvent
//----------------------------------------------------------------------------
Object_wx_PaintEvent::~Object_wx_PaintEvent()
{
}

Object *Object_wx_PaintEvent::Clone() const
{
	return NULL;
}

String Object_wx_PaintEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PaintEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_PaintEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(PaintEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxPaintEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PaintEvent)
{
}

Gura_ImplementDescendantCreator(wx_PaintEvent)
{
	return new Object_wx_PaintEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
