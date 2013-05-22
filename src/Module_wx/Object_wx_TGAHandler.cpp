//----------------------------------------------------------------------------
// wxTGAHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TGAHandler: public wxTGAHandler, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TGAHandler *_pObj;
public:
	~wx_TGAHandler();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TGAHandler *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TGAHandler::~wx_TGAHandler()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TGAHandler::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTGAHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(TGAHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TGAHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TGAHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_TGAHandler *pEntity = new wx_TGAHandler();
	Object_wx_TGAHandler *pObj = Object_wx_TGAHandler::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TGAHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxTGAHandler
//----------------------------------------------------------------------------
Object_wx_TGAHandler::~Object_wx_TGAHandler()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_TGAHandler::Clone() const
{
	return NULL;
}

String Object_wx_TGAHandler::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TGAHandler:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_TGAHandler::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(TGAHandler);
}

//----------------------------------------------------------------------------
// Class implementation for wxTGAHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TGAHandler)
{
}

Gura_ImplementDescendantCreator(wx_TGAHandler)
{
	return new Object_wx_TGAHandler((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
