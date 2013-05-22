//----------------------------------------------------------------------------
// wxPNGHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PNGHandler: public wxPNGHandler, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PNGHandler *_pObj;
public:
	~wx_PNGHandler();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PNGHandler *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PNGHandler::~wx_PNGHandler()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PNGHandler::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPNGHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(PNGHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PNGHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PNGHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_PNGHandler *pEntity = new wx_PNGHandler();
	Object_wx_PNGHandler *pObj = Object_wx_PNGHandler::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PNGHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxPNGHandler
//----------------------------------------------------------------------------
Object_wx_PNGHandler::~Object_wx_PNGHandler()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_PNGHandler::Clone() const
{
	return NULL;
}

String Object_wx_PNGHandler::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PNGHandler:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_PNGHandler::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(PNGHandler);
}

//----------------------------------------------------------------------------
// Class implementation for wxPNGHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PNGHandler)
{
}

Gura_ImplementDescendantCreator(wx_PNGHandler)
{
	return new Object_wx_PNGHandler((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
