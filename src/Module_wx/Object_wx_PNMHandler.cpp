//----------------------------------------------------------------------------
// wxPNMHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PNMHandler: public wxPNMHandler, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PNMHandler *_pObj;
public:
	~wx_PNMHandler();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PNMHandler *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PNMHandler::~wx_PNMHandler()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PNMHandler::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPNMHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(PNMHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PNMHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PNMHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_PNMHandler *pEntity = new wx_PNMHandler();
	Object_wx_PNMHandler *pObj = Object_wx_PNMHandler::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PNMHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

//----------------------------------------------------------------------------
// Object implementation for wxPNMHandler
//----------------------------------------------------------------------------
Object_wx_PNMHandler::~Object_wx_PNMHandler()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_PNMHandler::Clone() const
{
	return NULL;
}

String Object_wx_PNMHandler::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PNMHandler:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_PNMHandler::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(PNMHandler);
}

//----------------------------------------------------------------------------
// Class implementation for wxPNMHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PNMHandler)
{
}

Gura_ImplementDescendantCreator(wx_PNMHandler)
{
	return new Object_wx_PNMHandler((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
