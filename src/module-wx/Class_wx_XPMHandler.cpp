//----------------------------------------------------------------------------
// wxXPMHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_XPMHandler: public wxXPMHandler, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_XPMHandler *_pObj;
public:
	~wx_XPMHandler();
	inline void AssocWithGura(Object_wx_XPMHandler *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_XPMHandler::~wx_XPMHandler()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_XPMHandler::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxXPMHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(XPMHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_XPMHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(XPMHandler)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_XPMHandler *pEntity = new wx_XPMHandler();
	Object_wx_XPMHandler *pObj = Object_wx_XPMHandler::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_XPMHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxXPMHandler
//----------------------------------------------------------------------------
Object_wx_XPMHandler::~Object_wx_XPMHandler()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_XPMHandler::Clone() const
{
	return nullptr;
}

String Object_wx_XPMHandler::ToString(bool exprFlag)
{
	String rtn("<wx.XPMHandler:");
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
// Class implementation for wxXPMHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XPMHandler)
{
	Gura_AssignFunction(XPMHandler);
}

Gura_ImplementDescendantCreator(wx_XPMHandler)
{
	return new Object_wx_XPMHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
