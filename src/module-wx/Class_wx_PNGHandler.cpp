//----------------------------------------------------------------------------
// wxPNGHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PNGHandler: public wxPNGHandler, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_PNGHandler *_pObj;
public:
	~wx_PNGHandler();
	inline void AssocWithGura(Object_wx_PNGHandler *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PNGHandler::~wx_PNGHandler()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PNGHandler::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPNGHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(PNGHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PNGHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PNGHandler)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_PNGHandler *pEntity = new wx_PNGHandler();
	Object_wx_PNGHandler *pObj = Object_wx_PNGHandler::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PNGHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxPNGHandler
//----------------------------------------------------------------------------
Object_wx_PNGHandler::~Object_wx_PNGHandler()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_PNGHandler::Clone() const
{
	return nullptr;
}

String Object_wx_PNGHandler::ToString(bool exprFlag)
{
	String rtn("<wx.PNGHandler:");
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
// Class implementation for wxPNGHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PNGHandler)
{
	Gura_AssignFunction(PNGHandler);
}

Gura_ImplementDescendantCreator(wx_PNGHandler)
{
	return new Object_wx_PNGHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
