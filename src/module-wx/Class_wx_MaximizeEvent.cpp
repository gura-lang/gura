//----------------------------------------------------------------------------
// wxMaximizeEvent
// extracted from maxzevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MaximizeEvent: public wxMaximizeEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MaximizeEvent *_pObj;
public:
	inline wx_MaximizeEvent(int id) : wxMaximizeEvent(id), _pObj(nullptr) {}
	~wx_MaximizeEvent();
	inline void AssocWithGura(Object_wx_MaximizeEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MaximizeEvent::~wx_MaximizeEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MaximizeEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMaximizeEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(MaximizeEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MaximizeEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MaximizeEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int id = 0;
	if (args.IsValid(0)) id = args.GetInt(0);
	wx_MaximizeEvent *pEntity = new wx_MaximizeEvent(id);
	Object_wx_MaximizeEvent *pObj = Object_wx_MaximizeEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_MaximizeEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxMaximizeEvent
//----------------------------------------------------------------------------
Object_wx_MaximizeEvent::~Object_wx_MaximizeEvent()
{
}

Object *Object_wx_MaximizeEvent::Clone() const
{
	return nullptr;
}

String Object_wx_MaximizeEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MaximizeEvent:");
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
// Class implementation for wxMaximizeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MaximizeEvent)
{
	Gura_AssignFunction(MaximizeEvent);
}

Gura_ImplementDescendantCreator(wx_MaximizeEvent)
{
	return new Object_wx_MaximizeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
