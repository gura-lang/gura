//----------------------------------------------------------------------------
// wxTIFFHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TIFFHandler: public wxTIFFHandler, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TIFFHandler *_pObj;
public:
	~wx_TIFFHandler();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TIFFHandler *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TIFFHandler::~wx_TIFFHandler()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TIFFHandler::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTIFFHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(TIFFHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TIFFHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TIFFHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_TIFFHandler *pEntity = new wx_TIFFHandler();
	Object_wx_TIFFHandler *pObj = Object_wx_TIFFHandler::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TIFFHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxTIFFHandler
//----------------------------------------------------------------------------
Object_wx_TIFFHandler::~Object_wx_TIFFHandler()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_TIFFHandler::Clone() const
{
	return NULL;
}

String Object_wx_TIFFHandler::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TIFFHandler:");
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
// Class implementation for wxTIFFHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TIFFHandler)
{
	Gura_AssignFunction(TIFFHandler);
}

Gura_ImplementDescendantCreator(wx_TIFFHandler)
{
	return new Object_wx_TIFFHandler((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
