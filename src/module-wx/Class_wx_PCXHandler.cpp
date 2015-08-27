//----------------------------------------------------------------------------
// wxPCXHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PCXHandler: public wxPCXHandler, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_PCXHandler *_pObj;
public:
	~wx_PCXHandler();
	inline void AssocWithGura(Object_wx_PCXHandler *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PCXHandler::~wx_PCXHandler()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PCXHandler::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPCXHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(PCXHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PCXHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PCXHandler)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_PCXHandler *pEntity = new wx_PCXHandler();
	Object_wx_PCXHandler *pObj = Object_wx_PCXHandler::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PCXHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxPCXHandler
//----------------------------------------------------------------------------
Object_wx_PCXHandler::~Object_wx_PCXHandler()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_PCXHandler::Clone() const
{
	return nullptr;
}

String Object_wx_PCXHandler::ToString(bool exprFlag)
{
	String rtn("<wx.PCXHandler:");
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
// Class implementation for wxPCXHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PCXHandler)
{
	Gura_AssignFunction(PCXHandler);
}

Gura_ImplementDescendantCreator(wx_PCXHandler)
{
	return new Object_wx_PCXHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
