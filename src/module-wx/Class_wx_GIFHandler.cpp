//----------------------------------------------------------------------------
// wxGIFHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GIFHandler: public wxGIFHandler, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GIFHandler *_pObj;
public:
	~wx_GIFHandler();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GIFHandler *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GIFHandler::~wx_GIFHandler()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GIFHandler::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGIFHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(GIFHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GIFHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GIFHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GIFHandler *pEntity = new wx_GIFHandler();
	Object_wx_GIFHandler *pObj = Object_wx_GIFHandler::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GIFHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxGIFHandler
//----------------------------------------------------------------------------
Object_wx_GIFHandler::~Object_wx_GIFHandler()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_GIFHandler::Clone() const
{
	return NULL;
}

String Object_wx_GIFHandler::ToString(bool exprFlag)
{
	String rtn("<wx.GIFHandler:");
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
// Class implementation for wxGIFHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GIFHandler)
{
	Gura_AssignFunction(GIFHandler);
}

Gura_ImplementDescendantCreator(wx_GIFHandler)
{
	return new Object_wx_GIFHandler((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
