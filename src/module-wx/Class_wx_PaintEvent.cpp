//----------------------------------------------------------------------------
// wxPaintEvent
// extracted from paintevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PaintEvent: public wxPaintEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_PaintEvent *_pObj;
public:
	inline wx_PaintEvent(int id) : wxPaintEvent(id), _pObj(nullptr) {}
	~wx_PaintEvent();
	inline void AssocWithGura(Object_wx_PaintEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PaintEvent::~wx_PaintEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PaintEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPaintEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(PaintEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PaintEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PaintEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int id = 0;
	if (args.IsValid(0)) id = args.GetInt(0);
	wx_PaintEvent *pEntity = new wx_PaintEvent(id);
	Object_wx_PaintEvent *pObj = Object_wx_PaintEvent::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PaintEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxPaintEvent
//----------------------------------------------------------------------------
Object_wx_PaintEvent::~Object_wx_PaintEvent()
{
}

Object *Object_wx_PaintEvent::Clone() const
{
	return nullptr;
}

String Object_wx_PaintEvent::ToString(bool exprFlag)
{
	String rtn("<wx.PaintEvent:");
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
// Class implementation for wxPaintEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PaintEvent)
{
	Gura_AssignFunction(PaintEvent);
}

Gura_ImplementDescendantCreator(wx_PaintEvent)
{
	return new Object_wx_PaintEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
