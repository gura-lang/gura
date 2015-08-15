//----------------------------------------------------------------------------
// wxJPEGHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_JPEGHandler: public wxJPEGHandler, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_JPEGHandler *_pObj;
public:
	~wx_JPEGHandler();
	inline void AssocWithGura(Object_wx_JPEGHandler *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_JPEGHandler::~wx_JPEGHandler()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_JPEGHandler::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxJPEGHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(JPEGHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_JPEGHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(JPEGHandler)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_JPEGHandler *pEntity = new wx_JPEGHandler();
	Object_wx_JPEGHandler *pObj = Object_wx_JPEGHandler::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_JPEGHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxJPEGHandler
//----------------------------------------------------------------------------
Object_wx_JPEGHandler::~Object_wx_JPEGHandler()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_JPEGHandler::Clone() const
{
	return nullptr;
}

String Object_wx_JPEGHandler::ToString(bool exprFlag)
{
	String rtn("<wx.JPEGHandler:");
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
// Class implementation for wxJPEGHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_JPEGHandler)
{
	Gura_AssignFunction(JPEGHandler);
}

Gura_ImplementDescendantCreator(wx_JPEGHandler)
{
	return new Object_wx_JPEGHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
