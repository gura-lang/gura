//----------------------------------------------------------------------------
// wxPCXHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PCXHandler: public wxPCXHandler, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PCXHandler *_pObj;
public:
	~wx_PCXHandler();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PCXHandler *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PCXHandler::~wx_PCXHandler()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PCXHandler::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPCXHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(PCXHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PCXHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PCXHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_PCXHandler *pEntity = new wx_PCXHandler();
	Object_wx_PCXHandler *pObj = Object_wx_PCXHandler::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PCXHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxPCXHandler
//----------------------------------------------------------------------------
Object_wx_PCXHandler::~Object_wx_PCXHandler()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_PCXHandler::Clone() const
{
	return NULL;
}

String Object_wx_PCXHandler::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PCXHandler:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_PCXHandler::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(PCXHandler);
}

//----------------------------------------------------------------------------
// Class implementation for wxPCXHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PCXHandler)
{
}

Gura_ImplementDescendantCreator(wx_PCXHandler)
{
	return new Object_wx_PCXHandler((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
