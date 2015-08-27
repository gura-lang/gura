//----------------------------------------------------------------------------
// wxInitDialogEvent
// extracted from indlgevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_InitDialogEvent: public wxInitDialogEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_InitDialogEvent *_pObj;
public:
	inline wx_InitDialogEvent(int id) : wxInitDialogEvent(id), _pObj(nullptr) {}
	~wx_InitDialogEvent();
	inline void AssocWithGura(Object_wx_InitDialogEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_InitDialogEvent::~wx_InitDialogEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_InitDialogEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxInitDialogEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(InitDialogEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_InitDialogEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(InitDialogEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int id = 0;
	if (args.IsValid(0)) id = args.GetInt(0);
	wx_InitDialogEvent *pEntity = new wx_InitDialogEvent(id);
	Object_wx_InitDialogEvent *pObj = Object_wx_InitDialogEvent::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_InitDialogEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxInitDialogEvent
//----------------------------------------------------------------------------
Object_wx_InitDialogEvent::~Object_wx_InitDialogEvent()
{
}

Object *Object_wx_InitDialogEvent::Clone() const
{
	return nullptr;
}

String Object_wx_InitDialogEvent::ToString(bool exprFlag)
{
	String rtn("<wx.InitDialogEvent:");
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
// Class implementation for wxInitDialogEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_InitDialogEvent)
{
	Gura_AssignFunction(InitDialogEvent);
}

Gura_ImplementDescendantCreator(wx_InitDialogEvent)
{
	return new Object_wx_InitDialogEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
