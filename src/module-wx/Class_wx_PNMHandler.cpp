//----------------------------------------------------------------------------
// wxPNMHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PNMHandler: public wxPNMHandler, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_PNMHandler *_pObj;
public:
	~wx_PNMHandler();
	inline void AssocWithGura(Object_wx_PNMHandler *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PNMHandler::~wx_PNMHandler()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PNMHandler::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPNMHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(PNMHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PNMHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PNMHandler)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wx_PNMHandler *pEntity = new wx_PNMHandler();
	Object_wx_PNMHandler *pObj = Object_wx_PNMHandler::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PNMHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxPNMHandler
//----------------------------------------------------------------------------
Object_wx_PNMHandler::~Object_wx_PNMHandler()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_PNMHandler::Clone() const
{
	return nullptr;
}

String Object_wx_PNMHandler::ToString(bool exprFlag)
{
	String rtn("<wx.PNMHandler:");
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
// Class implementation for wxPNMHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PNMHandler)
{
	Gura_AssignFunction(PNMHandler);
}

Gura_ImplementDescendantCreator(wx_PNMHandler)
{
	return new Object_wx_PNMHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
