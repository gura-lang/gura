//----------------------------------------------------------------------------
// wxBMPHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_BMPHandler: public wxBMPHandler, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_BMPHandler *_pObj;
public:
	~wx_BMPHandler();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_BMPHandler *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BMPHandler::~wx_BMPHandler()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_BMPHandler::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBMPHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(BMPHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_BMPHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BMPHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_BMPHandler *pEntity = new wx_BMPHandler();
	Object_wx_BMPHandler *pObj = Object_wx_BMPHandler::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_BMPHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxBMPHandler
//----------------------------------------------------------------------------
Object_wx_BMPHandler::~Object_wx_BMPHandler()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_BMPHandler::Clone() const
{
	return NULL;
}

String Object_wx_BMPHandler::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.BMPHandler:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxBMPHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BMPHandler)
{
	Gura_AssignFunction(BMPHandler);
}

Gura_ImplementDescendantCreator(wx_BMPHandler)
{
	return new Object_wx_BMPHandler((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
