//----------------------------------------------------------------------------
// wxJPEGHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_JPEGHandler: public wxJPEGHandler, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_JPEGHandler *_pObj;
public:
	~wx_JPEGHandler();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_JPEGHandler *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_JPEGHandler::~wx_JPEGHandler()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_JPEGHandler::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxJPEGHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(JPEGHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_JPEGHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(JPEGHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_JPEGHandler *pEntity = new wx_JPEGHandler();
	Object_wx_JPEGHandler *pObj = Object_wx_JPEGHandler::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_JPEGHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxJPEGHandler
//----------------------------------------------------------------------------
Object_wx_JPEGHandler::~Object_wx_JPEGHandler()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_JPEGHandler::Clone() const
{
	return NULL;
}

String Object_wx_JPEGHandler::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.JPEGHandler:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_JPEGHandler::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(JPEGHandler);
}

//----------------------------------------------------------------------------
// Class implementation for wxJPEGHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_JPEGHandler)
{
}

Gura_ImplementDescendantCreator(wx_JPEGHandler)
{
	return new Object_wx_JPEGHandler((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
