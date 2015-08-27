//----------------------------------------------------------------------------
// wxBMPHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_BMPHandler: public wxBMPHandler, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_BMPHandler *_pObj;
public:
	~wx_BMPHandler();
	inline void AssocWithGura(Object_wx_BMPHandler *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BMPHandler::~wx_BMPHandler()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_BMPHandler::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBMPHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(BMPHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_BMPHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BMPHandler)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_BMPHandler *pEntity = new wx_BMPHandler();
	Object_wx_BMPHandler *pObj = Object_wx_BMPHandler::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_BMPHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxBMPHandler
//----------------------------------------------------------------------------
Object_wx_BMPHandler::~Object_wx_BMPHandler()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_BMPHandler::Clone() const
{
	return nullptr;
}

String Object_wx_BMPHandler::ToString(bool exprFlag)
{
	String rtn("<wx.BMPHandler:");
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
// Class implementation for wxBMPHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BMPHandler)
{
	Gura_AssignFunction(BMPHandler);
}

Gura_ImplementDescendantCreator(wx_BMPHandler)
{
	return new Object_wx_BMPHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
